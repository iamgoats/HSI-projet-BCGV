/**
 * \file        app_data_generated.c
 * \brief       Implémentation générée automatiquement des getters, setters et fonctions UDP.
 * \author      Généré par un script Python
 */

#include "app_data.h"
#include <stdio.h>

/**
 * \brief   Récupère la valeur de voyant_feux_de_position.
 * \param   data : Pointeur vers la structure applicative.
 * \return  voyant_t : Valeur actuelle de voyant_feux_de_position.
 */
voyant_t get_voyant_feux_de_position(const app_data_t *data) {
    return data->voyant_feux_de_position;
}

/**
 * \brief   Met à jour la valeur de voyant_feux_de_position.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_feux_de_position(app_data_t *data, bool value) {
    
    data->voyant_feux_de_position.value = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de voyant_feux_de_croisement.
 * \param   data : Pointeur vers la structure applicative.
 * \return  voyant_t : Valeur actuelle de voyant_feux_de_croisement.
 */
voyant_t get_voyant_feux_de_croisement(const app_data_t *data) {
    return data->voyant_feux_de_croisement;
}

/**
 * \brief   Met à jour la valeur de voyant_feux_de_croisement.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_feux_de_croisement(app_data_t *data, bool value) {
    
    data->voyant_feux_de_croisement.value = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de voyant_feux_de_route.
 * \param   data : Pointeur vers la structure applicative.
 * \return  voyant_t : Valeur actuelle de voyant_feux_de_route.
 */
voyant_t get_voyant_feux_de_route(const app_data_t *data) {
    return data->voyant_feux_de_route;
}

/**
 * \brief   Met à jour la valeur de voyant_feux_de_route.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_feux_de_route(app_data_t *data, bool value) {
    
    data->voyant_feux_de_route.value = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de voyant_essence.
 * \param   data : Pointeur vers la structure applicative.
 * \return  voyant_t : Valeur actuelle de voyant_essence.
 */
voyant_t get_voyant_essence(const app_data_t *data) {
    return data->voyant_essence;
}

/**
 * \brief   Met à jour la valeur de voyant_essence.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_essence(app_data_t *data, bool value) {
    
    data->voyant_essence.value = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de voyant_défaut_de_moteur.
 * \param   data : Pointeur vers la structure applicative.
 * \return  voyant_t : Valeur actuelle de voyant_défaut_de_moteur.
 */
voyant_t get_voyant_défaut_de_moteur(const app_data_t *data) {
    return data->voyant_défaut_de_moteur;
}

/**
 * \brief   Met à jour la valeur de voyant_défaut_de_moteur.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_défaut_de_moteur(app_data_t *data, bool value) {
    
    data->voyant_défaut_de_moteur.value = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de voyant_pression_de_pneu.
 * \param   data : Pointeur vers la structure applicative.
 * \return  voyant_t : Valeur actuelle de voyant_pression_de_pneu.
 */
voyant_t get_voyant_pression_de_pneu(const app_data_t *data) {
    return data->voyant_pression_de_pneu;
}

/**
 * \brief   Met à jour la valeur de voyant_pression_de_pneu.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_pression_de_pneu(app_data_t *data, bool value) {
    
    data->voyant_pression_de_pneu.value = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de voyant_batterie_déchargée.
 * \param   data : Pointeur vers la structure applicative.
 * \return  voyant_t : Valeur actuelle de voyant_batterie_déchargée.
 */
voyant_t get_voyant_batterie_déchargée(const app_data_t *data) {
    return data->voyant_batterie_déchargée;
}

/**
 * \brief   Met à jour la valeur de voyant_batterie_déchargée.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_batterie_déchargée(app_data_t *data, bool value) {
    
    data->voyant_batterie_déchargée.value = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de voyant_warnings.
 * \param   data : Pointeur vers la structure applicative.
 * \return  voyant_t : Valeur actuelle de voyant_warnings.
 */
voyant_t get_voyant_warnings(const app_data_t *data) {
    return data->voyant_warnings;
}

/**
 * \brief   Met à jour la valeur de voyant_warnings.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_warnings(app_data_t *data, bool value) {
    
    data->voyant_warnings.value = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de voyant_panne_batterie.
 * \param   data : Pointeur vers la structure applicative.
 * \return  voyant_t : Valeur actuelle de voyant_panne_batterie.
 */
voyant_t get_voyant_panne_batterie(const app_data_t *data) {
    return data->voyant_panne_batterie;
}

/**
 * \brief   Met à jour la valeur de voyant_panne_batterie.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_panne_batterie(app_data_t *data, bool value) {
    
    data->voyant_panne_batterie.value = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de voyant_temp_ldr.
 * \param   data : Pointeur vers la structure applicative.
 * \return  voyant_t : Valeur actuelle de voyant_temp_ldr.
 */
voyant_t get_voyant_temp_ldr(const app_data_t *data) {
    return data->voyant_temp_ldr;
}

/**
 * \brief   Met à jour la valeur de voyant_temp_ldr.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_temp_ldr(app_data_t *data, bool value) {
    
    data->voyant_temp_ldr.value = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de voyant_pession_moteur.
 * \param   data : Pointeur vers la structure applicative.
 * \return  voyant_t : Valeur actuelle de voyant_pession_moteur.
 */
voyant_t get_voyant_pession_moteur(const app_data_t *data) {
    return data->voyant_pession_moteur;
}

/**
 * \brief   Met à jour la valeur de voyant_pession_moteur.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_pession_moteur(app_data_t *data, bool value) {
    
    data->voyant_pession_moteur.value = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de voyant_surchauffe_huile.
 * \param   data : Pointeur vers la structure applicative.
 * \return  voyant_t : Valeur actuelle de voyant_surchauffe_huile.
 */
voyant_t get_voyant_surchauffe_huile(const app_data_t *data) {
    return data->voyant_surchauffe_huile;
}

/**
 * \brief   Met à jour la valeur de voyant_surchauffe_huile.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_surchauffe_huile(app_data_t *data, bool value) {
    
    data->voyant_surchauffe_huile.value = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de voyant_défallaince_freins.
 * \param   data : Pointeur vers la structure applicative.
 * \return  voyant_t : Valeur actuelle de voyant_défallaince_freins.
 */
voyant_t get_voyant_défallaince_freins(const app_data_t *data) {
    return data->voyant_défallaince_freins;
}

/**
 * \brief   Met à jour la valeur de voyant_défallaince_freins.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_défallaince_freins(app_data_t *data, bool value) {
    
    data->voyant_défallaince_freins.value = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de activation_essuie_glaces.
 * \param   data : Pointeur vers la structure applicative.
 * \return  commande_t : Valeur actuelle de activation_essuie_glaces.
 */
commande_t get_activation_essuie_glaces(const app_data_t *data) {
    return data->activation_essuie_glaces;
}

/**
 * \brief   Met à jour la valeur de activation_essuie_glaces.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_activation_essuie_glaces(app_data_t *data, bool value) {
    
    data->activation_essuie_glaces.value = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de activation_lave_glace.
 * \param   data : Pointeur vers la structure applicative.
 * \return  commande_t : Valeur actuelle de activation_lave_glace.
 */
commande_t get_activation_lave_glace(const app_data_t *data) {
    return data->activation_lave_glace;
}

/**
 * \brief   Met à jour la valeur de activation_lave_glace.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_activation_lave_glace(app_data_t *data, bool value) {
    
    data->activation_lave_glace.value = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de affichage_kilométrage.
 * \param   data : Pointeur vers la structure applicative.
 * \return  km_t : Valeur actuelle de affichage_kilométrage.
 */
km_t get_affichage_kilométrage(const app_data_t *data) {
    return data->affichage_kilométrage;
}

/**
 * \brief   Met à jour la valeur de affichage_kilométrage.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_affichage_kilométrage(app_data_t *data, uint32_t value) {
    if (value > 4294967295) {
            printf("Erreur : Valeur hors borne pour affichage_kilométrage (%d).\n", value);
            return -1;
        }
    data->affichage_kilométrage.value = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de affichage_vitesse.
 * \param   data : Pointeur vers la structure applicative.
 * \return  vitesse_t : Valeur actuelle de affichage_vitesse.
 */
vitesse_t get_affichage_vitesse(const app_data_t *data) {
    return data->affichage_vitesse;
}

/**
 * \brief   Met à jour la valeur de affichage_vitesse.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_affichage_vitesse(app_data_t *data, uint8_t value) {
    if (value > 255) {
            printf("Erreur : Valeur hors borne pour affichage_vitesse (%d).\n", value);
            return -1;
        }
    data->affichage_vitesse.value = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de affichage_niveau_réservoir.
 * \param   data : Pointeur vers la structure applicative.
 * \return  reservoir_t : Valeur actuelle de affichage_niveau_réservoir.
 */
reservoir_t get_affichage_niveau_réservoir(const app_data_t *data) {
    return data->affichage_niveau_réservoir;
}

/**
 * \brief   Met à jour la valeur de affichage_niveau_réservoir.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_affichage_niveau_réservoir(app_data_t *data, uint8_t value) {
    if (value > 40) {
            printf("Erreur : Valeur hors borne pour affichage_niveau_réservoir (%d).\n", value);
            return -1;
        }
    data->affichage_niveau_réservoir.value = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de affichage_tours_minutes.
 * \param   data : Pointeur vers la structure applicative.
 * \return  trmin_t : Valeur actuelle de affichage_tours_minutes.
 */
trmin_t get_affichage_tours_minutes(const app_data_t *data) {
    return data->affichage_tours_minutes;
}

/**
 * \brief   Met à jour la valeur de affichage_tours_minutes.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_affichage_tours_minutes(app_data_t *data, uint8_t value) {
    if (value > 10000) {
            printf("Erreur : Valeur hors borne pour affichage_tours_minutes (%d).\n", value);
            return -1;
        }
    data->affichage_tours_minutes.value = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de cmd_warning.
 * \param   data : Pointeur vers la structure applicative.
 * \return  commande_t : Valeur actuelle de cmd_warning.
 */
commande_t get_cmd_warning(const app_data_t *data) {
    return data->cmd_warning;
}

/**
 * \brief   Met à jour la valeur de cmd_warning.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_cmd_warning(app_data_t *data, bool value) {
    
    data->cmd_warning.value = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de cmd_feux_de_poition.
 * \param   data : Pointeur vers la structure applicative.
 * \return  commande_t : Valeur actuelle de cmd_feux_de_poition.
 */
commande_t get_cmd_feux_de_poition(const app_data_t *data) {
    return data->cmd_feux_de_poition;
}

/**
 * \brief   Met à jour la valeur de cmd_feux_de_poition.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_cmd_feux_de_poition(app_data_t *data, bool value) {
    
    data->cmd_feux_de_poition.value = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de cmd_feux_de_route.
 * \param   data : Pointeur vers la structure applicative.
 * \return  commande_t : Valeur actuelle de cmd_feux_de_route.
 */
commande_t get_cmd_feux_de_route(const app_data_t *data) {
    return data->cmd_feux_de_route;
}

/**
 * \brief   Met à jour la valeur de cmd_feux_de_route.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_cmd_feux_de_route(app_data_t *data, bool value) {
    
    data->cmd_feux_de_route.value = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de cmd_clignotant_droit.
 * \param   data : Pointeur vers la structure applicative.
 * \return  commande_t : Valeur actuelle de cmd_clignotant_droit.
 */
commande_t get_cmd_clignotant_droit(const app_data_t *data) {
    return data->cmd_clignotant_droit;
}

/**
 * \brief   Met à jour la valeur de cmd_clignotant_droit.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_cmd_clignotant_droit(app_data_t *data, bool value) {
    
    data->cmd_clignotant_droit.value = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de cmd_clignotant_gauche.
 * \param   data : Pointeur vers la structure applicative.
 * \return  commande_t : Valeur actuelle de cmd_clignotant_gauche.
 */
commande_t get_cmd_clignotant_gauche(const app_data_t *data) {
    return data->cmd_clignotant_gauche;
}

/**
 * \brief   Met à jour la valeur de cmd_clignotant_gauche.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_cmd_clignotant_gauche(app_data_t *data, bool value) {
    
    data->cmd_clignotant_gauche.value = value;
    return 0;
}

/**
 * \brief   Décoder une trame UDP reçue.
 * \param   frame : Tableau d'octets représentant la trame.
 * \param   data : Structure applicative à mettre à jour.
 */
void decode_udp_frame(const uint8_t *frame, app_data_t *data) {
    data->voyant_feux_de_position.value = frame[0];
    data->voyant_feux_de_croisement.value = frame[1];
    data->voyant_feux_de_route.value = frame[2];
    data->voyant_essence.value = frame[3];
    data->voyant_défaut_de_moteur.value = frame[4];
    data->voyant_pression_de_pneu.value = frame[5];
    data->voyant_batterie_déchargée.value = frame[6];
    data->voyant_warnings.value = frame[7];
    data->voyant_panne_batterie.value = frame[8];
    data->voyant_temp_ldr.value = frame[9];
    data->voyant_pession_moteur.value = frame[10];
    data->voyant_surchauffe_huile.value = frame[11];
    data->voyant_défallaince_freins.value = frame[12];
    data->activation_essuie_glaces.value = frame[13];
    data->activation_lave_glace.value = frame[14];
    data->affichage_kilométrage.value = frame[15];
    data->affichage_vitesse.value = frame[16];
    data->affichage_niveau_réservoir.value = frame[17];
    data->affichage_tours_minutes.value = frame[18];
    data->cmd_warning.value = frame[19];
    data->cmd_feux_de_poition.value = frame[20];
    data->cmd_feux_de_route.value = frame[21];
    data->cmd_clignotant_droit.value = frame[22];
    data->cmd_clignotant_gauche.value = frame[23];
}
