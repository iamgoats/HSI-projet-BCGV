#ifndef APP_DATA_H
#define APP_DATA_H

#include <stdint.h>
#include <stdbool.h>

/* Définition des types */
// Definition of km_t
typedef struct km_t{
    uint32_t value;  // Kilométrage total 
} km_t;

// Definition of vitesse_t
typedef struct vitesse_t{
    uint8_t value;  // Vitesse en km/h
} vitesse_t;

// Definition of reservoir_t
typedef struct reservoir_t{
    uint8_t value;  // Réservoir en L
} reservoir_t;

// Definition of commande_t
typedef struct commande_t{
    bool value;  // Commande
} commande_t;

// Definition of trmin_t
typedef struct trmin_t{
    uint8_t value;  // Tour par minutes
} trmin_t;

// Definition de  defautChassis_t
typedef enum defautChassis_t {
    Aucun,
    Pression,
    Freins
} defautChassis_t;

// Definition de  défautMoteur_t
typedef enum défautMoteur_t {
    Aucun,
    Pression,
    Température,
    Surchauffe_huile
} défautMoteur_t;

// Definition de  défautBatterie_t
typedef enum défautBatterie_t {
    Aucun,
    Déchargé,
    Panne
} défautBatterie_t;

// Definition of crc8
typedef struct crc8{
    uint8_t value;  // Contrôle de redondance cyclique
} crc8;

// Definition of voyant_t
typedef struct voyant_t{
    bool value;  // Etat des voyants
} voyant_t;

// Definition de  idFeux
typedef enum idFeux {
    position,
    croisement,
    route,
    clignotant_droit,
    clignotant_gauche
} idFeux;


/* Définition de la structure des données */
typedef struct {
    voyant_t voyant_feux_de_position; // Voyant feux de position
    voyant_t voyant_feux_de_croisement; // Voyant feux de croisement
    voyant_t voyant_feux_de_route; // Voyant feux de route
    voyant_t voyant_essence; // Voyant essence
    voyant_t voyant_défaut_de_moteur; // Voyant défaut de moteur
    voyant_t voyant_pression_de_pneu; // Voyant pression de pneu
    voyant_t voyant_batterie_déchargée; // Voyant batterie déchargée
    voyant_t voyant_warnings; // Voyant warnings
    voyant_t voyant_panne_batterie; // Voyant panne batterie
    voyant_t voyant_temp_ldr; // Voyant TEMP. LDR
    voyant_t voyant_pession_moteur; // Voyant pession moteur
    voyant_t voyant_surchauffe_huile; // Voyant surchauffe huile
    voyant_t voyant_défallaince_freins; // Voyant défallaince freins.
    commande_t activation_essuie_glaces; // Activation Essuie_glaces
    commande_t activation_lave_glace; // Activation Lave_Glace
    km_t affichage_kilométrage; // Affichage kilométrage
    vitesse_t affichage_vitesse; // Affichage vitesse
    reservoir_t affichage_niveau_réservoir; // Affichage niveau réservoir
    trmin_t affichage_tours_minutes; // Affichage tours_minutes
    commande_t cmd_warning; // Cmd warning
    commande_t cmd_feux_de_poition; // Cmd feux de poition
    commande_t cmd_feux_de_route; // cmd feux de route
    commande_t cmd_clignotant_droit; // cmd clignotant droit
    commande_t cmd_clignotant_gauche; // cmd clignotant gauche
} app_data_t;

/* Taille de la trame UDP */
#define FRAME_SIZE 24

/* Prototypes des fonctions */
void init_app_data(app_data_t *data);
voyant_t get_voyant_feux_de_position(const app_data_t *data);
int set_voyant_feux_de_position(app_data_t *data, bool value);
voyant_t get_voyant_feux_de_croisement(const app_data_t *data);
int set_voyant_feux_de_croisement(app_data_t *data, bool value);
voyant_t get_voyant_feux_de_route(const app_data_t *data);
int set_voyant_feux_de_route(app_data_t *data, bool value);
voyant_t get_voyant_essence(const app_data_t *data);
int set_voyant_essence(app_data_t *data, bool value);
voyant_t get_voyant_défaut_de_moteur(const app_data_t *data);
int set_voyant_défaut_de_moteur(app_data_t *data, bool value);
voyant_t get_voyant_pression_de_pneu(const app_data_t *data);
int set_voyant_pression_de_pneu(app_data_t *data, bool value);
voyant_t get_voyant_batterie_déchargée(const app_data_t *data);
int set_voyant_batterie_déchargée(app_data_t *data, bool value);
voyant_t get_voyant_warnings(const app_data_t *data);
int set_voyant_warnings(app_data_t *data, bool value);
voyant_t get_voyant_panne_batterie(const app_data_t *data);
int set_voyant_panne_batterie(app_data_t *data, bool value);
voyant_t get_voyant_temp_ldr(const app_data_t *data);
int set_voyant_temp_ldr(app_data_t *data, bool value);
voyant_t get_voyant_pession_moteur(const app_data_t *data);
int set_voyant_pession_moteur(app_data_t *data, bool value);
voyant_t get_voyant_surchauffe_huile(const app_data_t *data);
int set_voyant_surchauffe_huile(app_data_t *data, bool value);
voyant_t get_voyant_défallaince_freins(const app_data_t *data);
int set_voyant_défallaince_freins(app_data_t *data, bool value);
commande_t get_activation_essuie_glaces(const app_data_t *data);
int set_activation_essuie_glaces(app_data_t *data, bool value);
commande_t get_activation_lave_glace(const app_data_t *data);
int set_activation_lave_glace(app_data_t *data, bool value);
km_t get_affichage_kilométrage(const app_data_t *data);
int set_affichage_kilométrage(app_data_t *data, uint32_t value);
vitesse_t get_affichage_vitesse(const app_data_t *data);
int set_affichage_vitesse(app_data_t *data, uint8_t value);
reservoir_t get_affichage_niveau_réservoir(const app_data_t *data);
int set_affichage_niveau_réservoir(app_data_t *data, uint8_t value);
trmin_t get_affichage_tours_minutes(const app_data_t *data);
int set_affichage_tours_minutes(app_data_t *data, uint8_t value);
commande_t get_cmd_warning(const app_data_t *data);
int set_cmd_warning(app_data_t *data, bool value);
commande_t get_cmd_feux_de_poition(const app_data_t *data);
int set_cmd_feux_de_poition(app_data_t *data, bool value);
commande_t get_cmd_feux_de_route(const app_data_t *data);
int set_cmd_feux_de_route(app_data_t *data, bool value);
commande_t get_cmd_clignotant_droit(const app_data_t *data);
int set_cmd_clignotant_droit(app_data_t *data, bool value);
commande_t get_cmd_clignotant_gauche(const app_data_t *data);
int set_cmd_clignotant_gauche(app_data_t *data, bool value);
void decode_udp_frame(const uint8_t *frame, app_data_t *data);
void generate_ack_frame(uint8_t *frame, const app_data_t *data);
bool validate_ack_frame(const uint8_t *ack_frame, const app_data_t *data);

#endif /* APP_DATA_H */
