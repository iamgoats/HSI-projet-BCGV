import csv

# Charger les données depuis le fichier CSV
def load_csv(file_path):
    with open(file_path, mode="r") as file:
        reader = csv.reader(file)
        section = None
        types = []
        data = []

        for row in reader:
            # Ignore les lignes vides ou les commentaires
            if not row or row[0].startswith("#"):
                continue

            # Identifier les sections (Types / Données)
            if row[0].lower() == "Nom" and "Genre" in row:
                section = "types"
                continue
            elif row[0].lower() == "Id" and "Nom" in row:
                section = "data"
                continue

            # Ajouter les lignes correspondantes à la bonne section
            if section == "types":
                types.append({
                    "Nom": row[0],
                    "Genre": row[1],
                    "Declaration": row[2],
                    "Domaine": row[3],
                    "Commentaire": row[4]
                })
            elif section == "data":
                data.append({
                    "Id": int(row[0]),
                    "Nom": row[1],
                    "Type": row[2],
                    "Dimension": int(row[3]),
                    "InitVal": row[4],
                    "Commentaire": row[5]
                })
        return data

# Génération du fichier header
def generate_header(types, data):
    with open("app_data.h", "w") as header:
        header.write("#ifndef APP_DATA_H\n#define APP_DATA_H\n\n")
        header.write("#include <stdint.h>\n#include <string.h>\n\n")

        # Définition des types
        header.write("// Types définis\n")
        for t in types:
            if t["Genre"] == "Atom":
                header.write(f"typedef {t['Declaration']} {t['Nom']}; // {t['Commentaire']}\n")
            elif t["Genre"] == "Enum":
                header.write(f"{t['Declaration']} {t['Nom']}; // {t['Commentaire']}\n")
        header.write("\n")

        # Structure des données
        header.write("// Structure des données applicatives\n")
        header.write("typedef struct {\n")
        for d in data:
            if d["Dimension"] == 1:
                header.write(f"    {d['Type']} {d['Nom']}; // {d['Commentaire']}\n")
            else:
                header.write(f"    {d['Type']} {d['Nom']}[{d['dimension']}]; // {d['Commentaire']}\n")
        header.write("} AppData;\n\n")

        # Prototypes des fonctions
        header.write("// Prototypes des fonctions\n")
        header.write("void init_app_data(AppData *data);\n")
        for d in data:
            header.write(f"{d['Type']} get_{d['Nom']}(const AppData *data);\n")
            header.write(f"int set_{d['Nom']}(AppData *data, {d['Type']} value);\n")
        header.write("\n#endif // APP_DATA_H\n")

# Generation du fichier source
def generate_source(data):
    with open("app_data.c", "w") as source:
        source.write('#include "app_data.h"\n\n')

        # Fonction d'initialisation
        source.write("// Initialisation de la structure\n")
        source.write("void init_app_data(AppData *data) {\n")
        for d in data:
            if d["Dimension"] == 1:
                source.write(f"    data->{d['Nom']} = {d['InitVal']};\n")
            else:
                source.write(f"    for (int i = 0; i < {d['dimension']}; i++) {{\n")
                source.write(f"        data->{d['Nom']}[i] = {d['InitVal']};\n")
                source.write("    }\n")
        source.write("}\n\n")

        # Getters
        source.write("// Getters\n")
        for d in data:
            if d["Dimension"] == 1:
                source.write(f"{d['Type']} get_{d['Nom']}(const AppData *data) {{\n")
                source.write(f"    return data->{d['Nom']};\n")
                source.write("}\n\n")

        # Setters avec validation
        source.write("// Setters avec validation des bornes\n")
        for d in data:
            if d["Dimension"] == 1:
                source.write(f"int set_{d['Nom']}(AppData *data, {d['Type']} value) {{\n")
                
                # Ajout de la validation des bornes
                if d["Nom"] == "kilometrage":
                    source.write("    if (value > 4294967295) return -1; // Kilométrage hors bornes\n")
                elif d["Nom"] == "vitesse":
                    source.write("    if (value > 255) return -1; // Vitesse hors bornes\n")
                elif d["Nom"] == "niveau_reservoir":
                    source.write("    if (value > 40) return -1; // Niveau réservoir hors bornes\n")
                elif d["Nom"] == "tours_minute":
                    source.write("    if (value > 10000) return -1; // Tours/minute hors bornes\n")
                
                
                # Met à jour la valeur si elle est valide
                source.write(f"    data->{d['Nom']} = value;\n")
                source.write("    return 0; // Succès\n")
                source.write("}\n\n")

# Charger les données et générer les fichiers
types = load_csv("types.csv")
data = load_csv("data.csv")

generate_header(types, data)
generate_source(data)
