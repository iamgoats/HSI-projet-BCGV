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
 * \return  t_voyant_t : Valeur actuelle de voyant_feux_de_position.
 */
t_voyant_t get_voyant_feux_de_position(const app_data_t *data) {
    return data->voyant_feux_de_position;
}

/**
 * \brief   Met à jour la valeur de voyant_feux_de_position.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_feux_de_position(t_app_data_t *data, t_voyant_t value) {
    if (value > 255) {
        printf("Erreur : Valeur hors borne pour voyant_feux_de_position (%d).\n", value);
        return -1;
    }
    data->voyant_feux_de_position = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de voyant_feux_de_croisement.
 * \param   data : Pointeur vers la structure applicative.
 * \return  t_voyant_t : Valeur actuelle de voyant_feux_de_croisement.
 */
t_voyant_t get_voyant_feux_de_croisement(const app_data_t *data) {
    return data->voyant_feux_de_croisement;
}

/**
 * \brief   Met à jour la valeur de voyant_feux_de_croisement.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_feux_de_croisement(t_app_data_t *data, t_voyant_t value) {
    if (value > 255) {
        printf("Erreur : Valeur hors borne pour voyant_feux_de_croisement (%d).\n", value);
        return -1;
    }
    data->voyant_feux_de_croisement = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de voyant_feux_de_route.
 * \param   data : Pointeur vers la structure applicative.
 * \return  t_voyant_t : Valeur actuelle de voyant_feux_de_route.
 */
t_voyant_t get_voyant_feux_de_route(const app_data_t *data) {
    return data->voyant_feux_de_route;
}

/**
 * \brief   Met à jour la valeur de voyant_feux_de_route.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_feux_de_route(t_app_data_t *data, t_voyant_t value) {
    if (value > 255) {
        printf("Erreur : Valeur hors borne pour voyant_feux_de_route (%d).\n", value);
        return -1;
    }
    data->voyant_feux_de_route = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de voyant_essence.
 * \param   data : Pointeur vers la structure applicative.
 * \return  t_voyant_t : Valeur actuelle de voyant_essence.
 */
t_voyant_t get_voyant_essence(const app_data_t *data) {
    return data->voyant_essence;
}

/**
 * \brief   Met à jour la valeur de voyant_essence.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_essence(t_app_data_t *data, t_voyant_t value) {
    if (value > 255) {
        printf("Erreur : Valeur hors borne pour voyant_essence (%d).\n", value);
        return -1;
    }
    data->voyant_essence = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de voyant_défaut_de_moteur.
 * \param   data : Pointeur vers la structure applicative.
 * \return  t_voyant_t : Valeur actuelle de voyant_défaut_de_moteur.
 */
t_voyant_t get_voyant_défaut_de_moteur(const app_data_t *data) {
    return data->voyant_défaut_de_moteur;
}

/**
 * \brief   Met à jour la valeur de voyant_défaut_de_moteur.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_défaut_de_moteur(t_app_data_t *data, t_voyant_t value) {
    if (value > 255) {
        printf("Erreur : Valeur hors borne pour voyant_défaut_de_moteur (%d).\n", value);
        return -1;
    }
    data->voyant_défaut_de_moteur = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de voyant_pression_de_pneu.
 * \param   data : Pointeur vers la structure applicative.
 * \return  t_voyant_t : Valeur actuelle de voyant_pression_de_pneu.
 */
t_voyant_t get_voyant_pression_de_pneu(const app_data_t *data) {
    return data->voyant_pression_de_pneu;
}

/**
 * \brief   Met à jour la valeur de voyant_pression_de_pneu.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_pression_de_pneu(t_app_data_t *data, t_voyant_t value) {
    if (value > 255) {
        printf("Erreur : Valeur hors borne pour voyant_pression_de_pneu (%d).\n", value);
        return -1;
    }
    data->voyant_pression_de_pneu = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de voyant_batterie_déchargée.
 * \param   data : Pointeur vers la structure applicative.
 * \return  t_voyant_t : Valeur actuelle de voyant_batterie_déchargée.
 */
t_voyant_t get_voyant_batterie_déchargée(const app_data_t *data) {
    return data->voyant_batterie_déchargée;
}

/**
 * \brief   Met à jour la valeur de voyant_batterie_déchargée.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_batterie_déchargée(t_app_data_t *data, t_voyant_t value) {
    if (value > 255) {
        printf("Erreur : Valeur hors borne pour voyant_batterie_déchargée (%d).\n", value);
        return -1;
    }
    data->voyant_batterie_déchargée = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de voyant_warnings.
 * \param   data : Pointeur vers la structure applicative.
 * \return  t_voyant_t : Valeur actuelle de voyant_warnings.
 */
t_voyant_t get_voyant_warnings(const app_data_t *data) {
    return data->voyant_warnings;
}

/**
 * \brief   Met à jour la valeur de voyant_warnings.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_warnings(t_app_data_t *data, t_voyant_t value) {
    if (value > 255) {
        printf("Erreur : Valeur hors borne pour voyant_warnings (%d).\n", value);
        return -1;
    }
    data->voyant_warnings = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de voyant_panne_batterie.
 * \param   data : Pointeur vers la structure applicative.
 * \return  t_voyant_t : Valeur actuelle de voyant_panne_batterie.
 */
t_voyant_t get_voyant_panne_batterie(const app_data_t *data) {
    return data->voyant_panne_batterie;
}

/**
 * \brief   Met à jour la valeur de voyant_panne_batterie.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_panne_batterie(t_app_data_t *data, t_voyant_t value) {
    if (value > 255) {
        printf("Erreur : Valeur hors borne pour voyant_panne_batterie (%d).\n", value);
        return -1;
    }
    data->voyant_panne_batterie = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de voyant_temp_ldr.
 * \param   data : Pointeur vers la structure applicative.
 * \return  t_voyant_t : Valeur actuelle de voyant_temp_ldr.
 */
t_voyant_t get_voyant_temp_ldr(const app_data_t *data) {
    return data->voyant_temp_ldr;
}

/**
 * \brief   Met à jour la valeur de voyant_temp_ldr.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_temp_ldr(t_app_data_t *data, t_voyant_t value) {
    if (value > 255) {
        printf("Erreur : Valeur hors borne pour voyant_temp_ldr (%d).\n", value);
        return -1;
    }
    data->voyant_temp_ldr = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de voyant_pession_moteur.
 * \param   data : Pointeur vers la structure applicative.
 * \return  t_voyant_t : Valeur actuelle de voyant_pession_moteur.
 */
t_voyant_t get_voyant_pession_moteur(const app_data_t *data) {
    return data->voyant_pession_moteur;
}

/**
 * \brief   Met à jour la valeur de voyant_pession_moteur.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_pession_moteur(t_app_data_t *data, t_voyant_t value) {
    if (value > 255) {
        printf("Erreur : Valeur hors borne pour voyant_pession_moteur (%d).\n", value);
        return -1;
    }
    data->voyant_pession_moteur = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de voyant_surchauffe_huile.
 * \param   data : Pointeur vers la structure applicative.
 * \return  t_voyant_t : Valeur actuelle de voyant_surchauffe_huile.
 */
t_voyant_t get_voyant_surchauffe_huile(const app_data_t *data) {
    return data->voyant_surchauffe_huile;
}

/**
 * \brief   Met à jour la valeur de voyant_surchauffe_huile.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_surchauffe_huile(t_app_data_t *data, t_voyant_t value) {
    if (value > 255) {
        printf("Erreur : Valeur hors borne pour voyant_surchauffe_huile (%d).\n", value);
        return -1;
    }
    data->voyant_surchauffe_huile = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de voyant_défallaince_freins.
 * \param   data : Pointeur vers la structure applicative.
 * \return  t_voyant_t : Valeur actuelle de voyant_défallaince_freins.
 */
t_voyant_t get_voyant_défallaince_freins(const app_data_t *data) {
    return data->voyant_défallaince_freins;
}

/**
 * \brief   Met à jour la valeur de voyant_défallaince_freins.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_voyant_défallaince_freins(t_app_data_t *data, t_voyant_t value) {
    if (value > 255) {
        printf("Erreur : Valeur hors borne pour voyant_défallaince_freins (%d).\n", value);
        return -1;
    }
    data->voyant_défallaince_freins = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de activation_essuie_glaces.
 * \param   data : Pointeur vers la structure applicative.
 * \return  t_commande_t : Valeur actuelle de activation_essuie_glaces.
 */
t_commande_t get_activation_essuie_glaces(const app_data_t *data) {
    return data->activation_essuie_glaces;
}

/**
 * \brief   Met à jour la valeur de activation_essuie_glaces.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_activation_essuie_glaces(t_app_data_t *data, t_commande_t value) {
    if (value > 255) {
        printf("Erreur : Valeur hors borne pour activation_essuie_glaces (%d).\n", value);
        return -1;
    }
    data->activation_essuie_glaces = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de activation_lave_glace.
 * \param   data : Pointeur vers la structure applicative.
 * \return  t_commande_t : Valeur actuelle de activation_lave_glace.
 */
t_commande_t get_activation_lave_glace(const app_data_t *data) {
    return data->activation_lave_glace;
}

/**
 * \brief   Met à jour la valeur de activation_lave_glace.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_activation_lave_glace(t_app_data_t *data, t_commande_t value) {
    if (value > 255) {
        printf("Erreur : Valeur hors borne pour activation_lave_glace (%d).\n", value);
        return -1;
    }
    data->activation_lave_glace = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de affichage_kilométrage.
 * \param   data : Pointeur vers la structure applicative.
 * \return  t_km_t : Valeur actuelle de affichage_kilométrage.
 */
t_km_t get_affichage_kilométrage(const app_data_t *data) {
    return data->affichage_kilométrage;
}

/**
 * \brief   Met à jour la valeur de affichage_kilométrage.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_affichage_kilométrage(t_app_data_t *data, t_km_t value) {
    if (value > 255) {
        printf("Erreur : Valeur hors borne pour affichage_kilométrage (%d).\n", value);
        return -1;
    }
    data->affichage_kilométrage = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de affichage_vitesse_.
 * \param   data : Pointeur vers la structure applicative.
 * \return  t_vitesse_t : Valeur actuelle de affichage_vitesse_.
 */
t_vitesse_t get_affichage_vitesse_(const app_data_t *data) {
    return data->affichage_vitesse_;
}

/**
 * \brief   Met à jour la valeur de affichage_vitesse_.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_affichage_vitesse_(t_app_data_t *data, t_vitesse_t value) {
    if (value > 255) {
        printf("Erreur : Valeur hors borne pour affichage_vitesse_ (%d).\n", value);
        return -1;
    }
    data->affichage_vitesse_ = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de affichage_niveau_réservoir.
 * \param   data : Pointeur vers la structure applicative.
 * \return  t_reservoir_t : Valeur actuelle de affichage_niveau_réservoir.
 */
t_reservoir_t get_affichage_niveau_réservoir(const app_data_t *data) {
    return data->affichage_niveau_réservoir;
}

/**
 * \brief   Met à jour la valeur de affichage_niveau_réservoir.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_affichage_niveau_réservoir(t_app_data_t *data, t_reservoir_t value) {
    if (value > 255) {
        printf("Erreur : Valeur hors borne pour affichage_niveau_réservoir (%d).\n", value);
        return -1;
    }
    data->affichage_niveau_réservoir = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de affichage_tours_minutes.
 * \param   data : Pointeur vers la structure applicative.
 * \return  t_trmin_t : Valeur actuelle de affichage_tours_minutes.
 */
t_trmin_t get_affichage_tours_minutes(const app_data_t *data) {
    return data->affichage_tours_minutes;
}

/**
 * \brief   Met à jour la valeur de affichage_tours_minutes.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_affichage_tours_minutes(t_app_data_t *data, t_trmin_t value) {
    if (value > 255) {
        printf("Erreur : Valeur hors borne pour affichage_tours_minutes (%d).\n", value);
        return -1;
    }
    data->affichage_tours_minutes = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de cmd_warning.
 * \param   data : Pointeur vers la structure applicative.
 * \return  t_commande_t : Valeur actuelle de cmd_warning.
 */
t_commande_t get_cmd_warning(const app_data_t *data) {
    return data->cmd_warning;
}

/**
 * \brief   Met à jour la valeur de cmd_warning.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_cmd_warning(t_app_data_t *data, t_commande_t value) {
    if (value > 255) {
        printf("Erreur : Valeur hors borne pour cmd_warning (%d).\n", value);
        return -1;
    }
    data->cmd_warning = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de cmd_feux_de_poition.
 * \param   data : Pointeur vers la structure applicative.
 * \return  t_commande_t : Valeur actuelle de cmd_feux_de_poition.
 */
t_commande_t get_cmd_feux_de_poition(const app_data_t *data) {
    return data->cmd_feux_de_poition;
}

/**
 * \brief   Met à jour la valeur de cmd_feux_de_poition.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_cmd_feux_de_poition(t_app_data_t *data, t_commande_t value) {
    if (value > 255) {
        printf("Erreur : Valeur hors borne pour cmd_feux_de_poition (%d).\n", value);
        return -1;
    }
    data->cmd_feux_de_poition = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de cmd_feux_de_route.
 * \param   data : Pointeur vers la structure applicative.
 * \return  t_commande_t : Valeur actuelle de cmd_feux_de_route.
 */
t_commande_t get_cmd_feux_de_route(const app_data_t *data) {
    return data->cmd_feux_de_route;
}

/**
 * \brief   Met à jour la valeur de cmd_feux_de_route.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_cmd_feux_de_route(t_app_data_t *data, t_commande_t value) {
    if (value > 255) {
        printf("Erreur : Valeur hors borne pour cmd_feux_de_route (%d).\n", value);
        return -1;
    }
    data->cmd_feux_de_route = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de cmd_clignotant_droit.
 * \param   data : Pointeur vers la structure applicative.
 * \return  t_commande_t : Valeur actuelle de cmd_clignotant_droit.
 */
t_commande_t get_cmd_clignotant_droit(const app_data_t *data) {
    return data->cmd_clignotant_droit;
}

/**
 * \brief   Met à jour la valeur de cmd_clignotant_droit.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_cmd_clignotant_droit(t_app_data_t *data, t_commande_t value) {
    if (value > 255) {
        printf("Erreur : Valeur hors borne pour cmd_clignotant_droit (%d).\n", value);
        return -1;
    }
    data->cmd_clignotant_droit = value;
    return 0;
}

/**
 * \brief   Récupère la valeur de cmd_clignotant_gauche.
 * \param   data : Pointeur vers la structure applicative.
 * \return  t_commande_t : Valeur actuelle de cmd_clignotant_gauche.
 */
t_commande_t get_cmd_clignotant_gauche(const app_data_t *data) {
    return data->cmd_clignotant_gauche;
}

/**
 * \brief   Met à jour la valeur de cmd_clignotant_gauche.
 * \param   data : Pointeur vers la structure applicative.
 * \param   value : Nouvelle valeur à attribuer.
 * \return  int : 0 si succès, -1 si erreur.
 */
int set_cmd_clignotant_gauche(t_app_data_t *data, t_commande_t value) {
    if (value > 255) {
        printf("Erreur : Valeur hors borne pour cmd_clignotant_gauche (%d).\n", value);
        return -1;
    }
    data->cmd_clignotant_gauche = value;
    return 0;
}

/**
 * \brief   Décoder une trame UDP reçue.
 * \param   frame : Tableau d'octets représentant la trame.
 * \param   data : Structure applicative à mettre à jour.
 */
void decode_udp_frame(const uint8_t *frame, app_data_t *data) {
    data->voyant_feux_de_position = frame[0];
    data->voyant_feux_de_croisement = frame[1];
    data->voyant_feux_de_route = frame[2];
    data->voyant_essence = frame[3];
    data->voyant_défaut_de_moteur = frame[4];
    data->voyant_pression_de_pneu = frame[5];
    data->voyant_batterie_déchargée = frame[6];
    data->voyant_warnings = frame[7];
    data->voyant_panne_batterie = frame[8];
    data->voyant_temp_ldr = frame[9];
    data->voyant_pession_moteur = frame[10];
    data->voyant_surchauffe_huile = frame[11];
    data->voyant_défallaince_freins = frame[12];
    data->activation_essuie_glaces = frame[13];
    data->activation_lave_glace = frame[14];
    data->affichage_kilométrage = frame[15];
    data->affichage_vitesse_ = frame[16];
    data->affichage_niveau_réservoir = frame[17];
    data->affichage_tours_minutes = frame[18];
    data->cmd_warning = frame[19];
    data->cmd_feux_de_poition = frame[20];
    data->cmd_feux_de_route = frame[21];
    data->cmd_clignotant_droit = frame[22];
    data->cmd_clignotant_gauche = frame[23];
}
