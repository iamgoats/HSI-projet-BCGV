import csv
from typing import Dict, List

def parse_types_csv(filename: str) -> Dict[str, Dict]:
    """Parse le fichier des types et retourne un dictionnaire des définitions."""
    types = {}
    with open(filename, 'r') as f:
        reader = csv.DictReader(f)
        for row in reader:
            domain = row['Domaine'].strip('[]').split(',')[0] if row['Domaine'] else "0"
            max_val = domain.split('...')[-1].strip() if '...' in domain else domain
            
            # Gérer les types énumérés
            if row['Genre'] == 'Enum':
                try:
                    enum_values = eval(row['Déclaration'])
                    max_val = len(enum_values) - 1
                except:
                    max_val = 1  # Valeur par défaut pour les énums

            types[row['Nom']] = { 
                'genre': row['Genre'],
                'declaration': row['Declaration'] or f'uint8_t',  # Type par défaut
                'max_value': max_val if isinstance(max_val, int) else 255,
                'comment': row['Commentaire']
            }
    return types

def parse_data_csv(filename: str, type_fields) -> List[Dict]:
    """Parse le fichier de données et retourne une liste des champs."""
    fields = []
    with open(filename, 'r') as f:
        reader = csv.DictReader(f)
        for row in reader:
            
            type = type_fields[row["Type"]]["declaration"]
            if type in ("uint8_t", "uint32_t", "bool"):
                type_type = type
            else:
                type = str
            fields.append({
                'name': row['Nom'].lower().replace(' ', '_').replace('.', ''),
                'type': type_type,
                'comment': row['Commentaire'] or row['Nom']
            })
    return fields

def generate_field_definition(field: Dict, types: Dict) -> Dict:
    """Génère la définition complète d'un champ."""
    type_info = types.get(field['type'], {})
    return {
        'name': field['name'],
        'type': field['type'],
        'comment': field['comment'],
        'bounds': (0, type_info.get('max_value', 255))
    }

def generate_getter(field: Dict) -> str:
    """Génère le getter pour un champ."""
    return f"""
/**
 * \\brief   Récupère la valeur de {field['name']}.
 * \\param   data : Pointeur vers la structure applicative.
 * \\return  {field['type']} : Valeur actuelle de {field['name']}.
 */
{field['type']} get_{field['name']}(const app_data_t *data) {{
    return data->{field['name']};
}}
"""

def generate_setter(field: Dict) -> str:    
    """Génère le setter pour un champ."""
    bounds_check = f"""
    if (value > {field['bounds'][1]}) {{
        printf("Erreur : Valeur hors borne pour {field['name']} (%d).\\n", value);
        return -1;
    }}""" if field['bounds'] else ""

    return f"""
/**
 * \\brief   Met à jour la valeur de {field['name']}.
 * \\param   data : Pointeur vers la structure applicative.
 * \\param   value : Nouvelle valeur à attribuer.
 * \\return  int : 0 si succès, -1 si erreur.
 */
int set_{field['name']}(app_data_t *data, {field['type']} value) {{
    {bounds_check.strip()}
    data->{field['name']} = value;
    return 0;
}}
"""

def generate_decode(fields: List[Dict]) -> str:
    """Génère la fonction de décodage UDP."""
    lines = [f"    data->{field['name']} = frame[{i}];" for i, field in enumerate(fields)]
    return f"""
/**
 * \\brief   Décoder une trame UDP reçue.
 * \\param   frame : Tableau d'octets représentant la trame.
 * \\param   data : Structure applicative à mettre à jour.
 */
void decode_udp_frame(const uint8_t *frame, app_data_t *data) {{
{chr(10).join(lines)}
}}
"""
def generate_type_structs(types: Dict) -> str:
    """Génère les structures et les énumérations des types définis en utilisant les déclarations spécifiées."""
    structs = []
    for type_name, details in types.items():
        type_genre = details['genre']
        declaration = details['declaration']
        comment = details['comment']
        if type_genre.lower() == "enum":
            try:
                enum_values = tuple(declaration.split(', '))
                enum_body = ",\n    ".join(enum_values)
                structs.append(f"""// Definition de  {type_name}
typedef enum {{
    {enum_body}
}} {type_name};
""")
            except Exception as e:
                structs.append(f"// Error parsing enum for {type_name}: {e}")

        elif type_genre.lower() == "atom":
            # Pour les types atomiques, utiliser la déclaration directement
            structs.append(f"""// Definition of {type_name}
typedef struct {{
    {declaration} value;  // {comment}
}} {type_name};
""")


    return "\n".join(structs)




def generate_header(fields: List[Dict], types: Dict) -> str:
    """Génère le contenu du fichier header."""
    struct_fields = "\n".join([f"    {field['type']} {field['name']}; // {field['comment']}" for field in fields])
    prototypes = "\n".join([
        f"{field['type']} get_{field['name']}(const app_data_t *data);\n"
        f"int set_{field['name']}(app_data_t *data, {field['type']} value);"
        for field in fields
    ])
    
    type_structs = generate_type_structs(types)

    return f"""#ifndef APP_DATA_H
#define APP_DATA_H

#include <stdint.h>
#include <stdbool.h>

/* Définition des types */
{type_structs}

/* Définition de la structure des données */
typedef struct {{
{struct_fields}
}} app_data_t;

/* Taille de la trame UDP */
#define FRAME_SIZE {len(fields)}

/* Prototypes des fonctions */
void init_app_data(app_data_t *data);
{prototypes}
void decode_udp_frame(const uint8_t *frame, app_data_t *data);
void generate_ack_frame(uint8_t *frame, const app_data_t *data);
bool validate_ack_frame(const uint8_t *ack_frame, const app_data_t *data);

#endif /* APP_DATA_H */
"""

def main():
    """Fonction principale pour générer les fichiers C et header."""
    types = parse_types_csv('types.csv')
    data_fields = parse_data_csv('data.csv', types)
    fields = [generate_field_definition(field, types) for field in data_fields]

    try:
        with open("archive/app_data_generated.c", "w") as f:
            f.write("""/**
 * \\file        app_data_generated.c
 * \\brief       Implémentation générée automatiquement des getters, setters et fonctions UDP.
 * \\author      Généré par un script Python
 */

#include "app_data.h"
#include <stdio.h>
""")
            for field in fields:
                f.write(generate_getter(field))
                f.write(generate_setter(field))
            f.write(generate_decode(fields))

        with open("archive/app_data.h", "w") as f:
            f.write(generate_header(fields, types))

        print("Fichiers générés avec succès!")
    except IOError as e:
        print(f"Erreur lors de la génération des fichiers : {e}")

if __name__ == "__main__":
    main()
