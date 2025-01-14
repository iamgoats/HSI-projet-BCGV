#ifndef APP_DATA_H
#define APP_DATA_H

#include <stdint.h>
#include <stdbool.h>

/* Définition des types */
typedef uint32_t t_kilometrage_t;    /**< Kilométrage en kilomètres */
typedef uint8_t t_vitesse_t;        /**< Vitesse en km/h */
typedef uint8_t t_reservoir_t;      /**< Niveau de réservoir en pourcentage */
typedef uint16_t t_tours_minute_t;  /**< Tours par minute divisé par 10 */
typedef uint8_t t_command_t;        /**< Commande */
typedef bool t_acquittement_t;      /**< Acquittement */

/* Définition de la structure des données */
typedef struct {
    t_kilometrage_t kilometrage;
    t_vitesse_t vitesse;
    t_reservoir_t reservoir;
    t_tours_minute_t tours_minute;
    t_command_t command;            /**< Commande courante */
    t_acquittement_t acquittement;  /**< Indicateur d'acquittement */
} app_data_udp;



/* Taille de la trame UDP */
#define FRAME_SIZE 14

/* Prototypes des fonctions */
void init_app_data(t_app_data_t *data);
t_kilometrage_t get_kilometrage(const t_app_data_t *data);
int set_kilometrage(t_app_data_t *data, t_kilometrage_t value);

t_vitesse_t get_vitesse(const t_app_data_t *data);
int set_vitesse(t_app_data_t *data, t_vitesse_t value);

t_reservoir_t get_reservoir(const t_app_data_t *data);
int set_reservoir(t_app_data_t *data, t_reservoir_t value);

t_tours_minute_t get_tours_minute(const t_app_data_t *data);
int set_tours_minute(t_app_data_t *data, t_tours_minute_t value);

t_command_t get_command(const t_app_data_t *data);
int set_command(t_app_data_t *data, t_command_t value);

t_acquittement_t get_acquittement(const t_app_data_t *data);
int set_acquittement(t_app_data_t *data, t_acquittement_t value);

/* Fonctions pour la gestion des trames UDP */
void decode_udp_frame(const uint8_t *frame, t_app_data_t *data);
void generate_ack_frame(uint8_t *frame, const t_app_data_t *data);
bool validate_ack_frame(const uint8_t *ack_frame, const t_app_data_t *data);

#endif 
