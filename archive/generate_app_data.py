# Définition des champs de la structure
fields = [
    {"name": "kilometrage", "type": "t_kilometrage_t", "comment": "Kilométrage en kilomètres", "bounds": (0, 999999)},
    {"name": "vitesse", "type": "t_vitesse_t", "comment": "Vitesse en km/h", "bounds": (0, 255)},
    {"name": "reservoir", "type": "t_reservoir_t", "comment": "Niveau de réservoir en pourcentage", "bounds": (0, 100)},
    {"name": "tours_minute", "type": "t_tours_minute_t", "comment": "Tours par minute divisés par 10", "bounds": (0, 1000)},
    {"name": "command", "type": "t_command_t", "comment": "Commande courante", "bounds": (0, 255)},
    {"name": "acquittement", "type": "t_acquittement_t", "comment": "Indicateur d'acquittement", "bounds": (0, 1)},
]

# Génération du fichier C
header = """/**
 * \\file        app_data_generated.c
 * \\brief       Implémentation générée automatiquement des getters, setters et fonctions UDP.
 * \\author      Généré par un script Python
 */

#include "app_data.h"
#include <stdio.h>
"""

def generate_getter(field):
    return f"""
/**
 * \\brief   Récupère la valeur de {field['name']}.
 * \\param   data : Pointeur vers la structure applicative.
 * \\return  {field['type']} : Valeur actuelle de {field['name']}.
 */
{field['type']} get_{field['name']}(const t_app_data_t *data) {{
    return data->{field['name']};
}}
"""

def generate_setter(field):

    if field["type"] == "bool" or field["type"] == "t_acquittement_t":
        bounds_check = f"""
    if (value > {field['bounds'][1]}) {{
        printf("Erreur : Valeur hors borne pour {field['name']} (%d).\\n", value);
        return -1;
    }}"""
    else:
        bounds_check = f"""
    if (value > {field['bounds'][1]}) {{
        printf("Erreur : Valeur hors borne pour {field['name']} (%d).\\n", value);
        return -1;
    }}""" if field["bounds"] else ""

    return f"""
/**
 * \\brief   Met à jour la valeur de {field['name']}.
 * \\param   data : Pointeur vers la structure applicative.
 * \\param   value : Nouvelle valeur à attribuer.
 * \\return  int : 0 si succès, -1 si erreur.
 */
int set_{field['name']}(t_app_data_t *data, {field['type']} value) {{
    {bounds_check.strip()}
    data->{field['name']} = value;
    return 0;
}}
"""

def generate_decode():
    lines = [f"    data->{field['name']} = frame[{i}];" for i, field in enumerate(fields)]
    return f"""
/**
 * \\brief   Décoder une trame UDP reçue.
 * \\param   frame : Tableau d'octets représentant la trame.
 * \\param   data : Structure applicative à mettre à jour.
 */
void decode_udp_frame(const uint8_t *frame, t_app_data_t *data) {{
{chr(10).join(lines)}
}}
"""

def generate_ack():
    lines = [f"    frame[{i}] = data->{field['name']};" for i, field in enumerate(fields)]
    return f"""
/**
 * \\brief   Générer une trame d'acquittement.
 * \\param   frame : Tableau d'octets pour écrire la trame.
 * \\param   data : Structure applicative source.
 */
void generate_ack_frame(uint8_t *frame, const t_app_data_t *data) {{
{chr(10).join(lines)}
}}
"""

def generate_validation():
    return """
/**
 * \\brief   Valider une trame d'acquittement.
 * \\param   ack_frame : Trame d'acquittement reçue.
 * \\param   data : Structure applicative source.
 * \\return  bool : true si la trame est valide, false sinon.
 */
bool validate_ack_frame(const uint8_t *ack_frame, const t_app_data_t *data) {
    uint8_t generated_frame[FRAME_SIZE];
    generate_ack_frame(generated_frame, data);
    for (int i = 0; i < FRAME_SIZE; i++) {
        if (ack_frame[i] != generated_frame[i]) {
            return false;
        }
    }
    return true;
}
"""

# Génération du fichier
output_file = "app_data_generated.c"

try:
    with open(output_file, "w") as f:
        print(f"Écriture dans le fichier : {output_file}")
        f.write(header)
        for field in fields:
            f.write(generate_getter(field))
            f.write("\n")
            f.write(generate_setter(field))
            f.write("\n")
        f.write(generate_decode())
        f.write("\n")
        f.write(generate_ack())
        f.write("\n")
        f.write(generate_validation())
    print(f"Fichier généré avec succès : {output_file}")
except IOError as e:
    print(f"Erreur lors de la génération du fichier : {e}")
