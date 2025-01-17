#ifndef APP_DATA_H
#define APP_DATA_H

#include <stdint.h>
#include <stdbool.h>

/* Définition des types */
// Definition of km_t
typedef struct {
    uint32_t value;  // Kilométrage total 
} km_t;

// Definition of vitesse_t
typedef struct {
    uint8_t value;  // Vitesse en km/h
} vitesse_t;

// Definition of reservoir_t
typedef struct {
    uint8_t value;  // Réservoir en L
} reservoir_t;

// Definition of commande_t
typedef struct {
    bool value;  // Commande
} commande_t;

// Definition of trmin_t
typedef struct {
    uint8_t value;  // Tour par minutes
} trmin_t;

// Definition de  defautChassis_t
typedef enum {
    Aucun,
    Pression,
    Freins
} defautChassis_t;

// Definition de  défautMoteur_t
typedef enum {
    Aucun,
    Pression,
    Température,
    Surchauffe_huile
} défautMoteur_t;

// Definition de  défautBatterie_t
typedef enum {
    Aucun,
    Déchargé,
    Panne
} défautBatterie_t;

// Definition of crc8
typedef struct {
    uint8_t value;  // Contrôle de redondance cyclique
} crc8;

// Definition of voyant_t
typedef struct {
    bool value;  // Etat des voyants
} voyant_t;

// Definition de  idFeux
typedef enum {
    position,
    croisement,
    route,
    clignotant_droit,
    clignotant_gauche
} idFeux;


/* Définition de la structure des données */
typedef struct {
    bool voyant_feux_de_position; // Voyant feux de position
    bool voyant_feux_de_croisement; // Voyant feux de croisement
    bool voyant_feux_de_route; // Voyant feux de route
    bool voyant_essence; // Voyant essence
    bool voyant_défaut_de_moteur; // Voyant défaut de moteur
    bool voyant_pression_de_pneu; // Voyant pression de pneu
    bool voyant_batterie_déchargée; // Voyant batterie déchargée
    bool voyant_warnings; // Voyant warnings
    bool voyant_panne_batterie; // Voyant panne batterie
    bool voyant_temp_ldr; // Voyant TEMP. LDR
    bool voyant_pession_moteur; // Voyant pession moteur
    bool voyant_surchauffe_huile; // Voyant surchauffe huile
    bool voyant_défallaince_freins; // Voyant défallaince freins.
    bool activation_essuie_glaces; // Activation Essuie_glaces
    bool activation_lave_glace; // Activation Lave_Glace
    uint32_t affichage_kilométrage; // Affichage kilométrage
    uint8_t affichage_vitesse; // Affichage vitesse
    uint8_t affichage_niveau_réservoir; // Affichage niveau réservoir
    uint8_t affichage_tours_minutes; // Affichage tours_minutes
    bool cmd_warning; // Cmd warning
    bool cmd_feux_de_poition; // Cmd feux de poition
    bool cmd_feux_de_route; // cmd feux de route
    bool cmd_clignotant_droit; // cmd clignotant droit
    bool cmd_clignotant_gauche; // cmd clignotant gauche
} app_data_t;

/* Taille de la trame UDP */
#define FRAME_SIZE 24

/* Prototypes des fonctions */
void init_app_data(app_data_t *data);
bool get_voyant_feux_de_position(const app_data_t *data);
int set_voyant_feux_de_position(app_data_t *data, bool value);
bool get_voyant_feux_de_croisement(const app_data_t *data);
int set_voyant_feux_de_croisement(app_data_t *data, bool value);
bool get_voyant_feux_de_route(const app_data_t *data);
int set_voyant_feux_de_route(app_data_t *data, bool value);
bool get_voyant_essence(const app_data_t *data);
int set_voyant_essence(app_data_t *data, bool value);
bool get_voyant_défaut_de_moteur(const app_data_t *data);
int set_voyant_défaut_de_moteur(app_data_t *data, bool value);
bool get_voyant_pression_de_pneu(const app_data_t *data);
int set_voyant_pression_de_pneu(app_data_t *data, bool value);
bool get_voyant_batterie_déchargée(const app_data_t *data);
int set_voyant_batterie_déchargée(app_data_t *data, bool value);
bool get_voyant_warnings(const app_data_t *data);
int set_voyant_warnings(app_data_t *data, bool value);
bool get_voyant_panne_batterie(const app_data_t *data);
int set_voyant_panne_batterie(app_data_t *data, bool value);
bool get_voyant_temp_ldr(const app_data_t *data);
int set_voyant_temp_ldr(app_data_t *data, bool value);
bool get_voyant_pession_moteur(const app_data_t *data);
int set_voyant_pession_moteur(app_data_t *data, bool value);
bool get_voyant_surchauffe_huile(const app_data_t *data);
int set_voyant_surchauffe_huile(app_data_t *data, bool value);
bool get_voyant_défallaince_freins(const app_data_t *data);
int set_voyant_défallaince_freins(app_data_t *data, bool value);
bool get_activation_essuie_glaces(const app_data_t *data);
int set_activation_essuie_glaces(app_data_t *data, bool value);
bool get_activation_lave_glace(const app_data_t *data);
int set_activation_lave_glace(app_data_t *data, bool value);
uint32_t get_affichage_kilométrage(const app_data_t *data);
int set_affichage_kilométrage(app_data_t *data, uint32_t value);
uint8_t get_affichage_vitesse(const app_data_t *data);
int set_affichage_vitesse(app_data_t *data, uint8_t value);
uint8_t get_affichage_niveau_réservoir(const app_data_t *data);
int set_affichage_niveau_réservoir(app_data_t *data, uint8_t value);
uint8_t get_affichage_tours_minutes(const app_data_t *data);
int set_affichage_tours_minutes(app_data_t *data, uint8_t value);
bool get_cmd_warning(const app_data_t *data);
int set_cmd_warning(app_data_t *data, bool value);
bool get_cmd_feux_de_poition(const app_data_t *data);
int set_cmd_feux_de_poition(app_data_t *data, bool value);
bool get_cmd_feux_de_route(const app_data_t *data);
int set_cmd_feux_de_route(app_data_t *data, bool value);
bool get_cmd_clignotant_droit(const app_data_t *data);
int set_cmd_clignotant_droit(app_data_t *data, bool value);
bool get_cmd_clignotant_gauche(const app_data_t *data);
int set_cmd_clignotant_gauche(app_data_t *data, bool value);
void decode_udp_frame(const uint8_t *frame, app_data_t *data);
void generate_ack_frame(uint8_t *frame, const app_data_t *data);
bool validate_ack_frame(const uint8_t *ack_frame, const app_data_t *data);

#endif /* APP_DATA_H */
