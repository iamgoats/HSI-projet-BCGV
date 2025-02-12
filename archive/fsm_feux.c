/**
 * \file        fsm_feux.c
 * \author      Alexis Daley
 * \brief       Implémentation d'une machine à états pour la gestion des feux.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include "drv_api.h"
#include "fsm_feux.h"
#include "app_data.h"

/* Callbacks pour les transitions */
static int callbackNothing(void) {
    printf("[FSM FEUX] Ne rien faire\n");
    return 0;
}

static int callbackTurnOnLights(void) {
    printf("[FSM FEUX] Allumer les lumières\n");
    set_voyant_feux_de_position(&app_data, (voyant_t){true});
    set_voyant_feux_de_croisement(&app_data, (voyant_t){true});
    set_voyant_feux_de_route(&app_data, (voyant_t){true});
    return 0;
}

static int callbackTurnOffLights(void) {
    printf("[FSM FEUX] Éteindre les lumières\n");
    set_voyant_feux_de_position(&app_data, (voyant_t){false});
    set_voyant_feux_de_croisement(&app_data, (voyant_t){false});
    set_voyant_feux_de_route(&app_data, (voyant_t){false});
    return 0;
}

static int callbackHandleAcknowledgment(void) {
    printf("[FSM FEUX] Acquitter\n");
    return 0;
}

static int callbackHandleTimeout(void) {
    printf("[FSM FEUX] Temps supérieur à 1 sec\n");
    return 0;
}

static int FsmError(void) {
    printf("[FSM FEUX] Erreur critique détectée.\n");
    return -1;
}

/* Structure des transitions */
typedef struct {
    fsm_state_t state;
    fsm_event_t event;
    int (*callback)(void);
    int next_state;
} tTransition;

/* Tableau des transitions */
tTransition trans[] = {
    {ST_INIT, EV_NONE, &callbackTurnOffLights, ST_ETEINTS},
    {ST_ETEINTS, EV_CMD_1, &callbackTurnOnLights, ST_ALLUMES},
    {ST_ETEINTS, EV_CMD_0, &callbackNothing, ST_ETEINTS},
    {ST_ALLUMES, EV_CMD_0, &callbackTurnOffLights, ST_ETEINTS},
    {ST_ALLUMES, EV_ACQUITTEMENT_RECU, &callbackHandleAcknowledgment, ST_ACQUITTES},
    {ST_ALLUMES, EV_ACQUITTEMENT_NR_1, &callbackHandleTimeout, ST_ERREUR},
    {ST_ACQUITTES, EV_CMD_0, &callbackTurnOffLights, ST_ETEINTS},
    {ST_ACQUITTES, EV_CMD_0, &callbackNothing, ST_ACQUITTES},
    {ST_ERREUR, EV_NONE, &FsmError, ST_TERM},
    {ST_ANY, EV_ERR, &FsmError, ST_TERM}
};

#define TRANS_COUNT (sizeof(trans) / sizeof(*trans))

static fsm_state_t state = ST_INIT;
static app_data_t app_data;

/**
 * \brief Décoder une trame UDP et mettre à jour app_data.
 * \param frame : Trame UDP reçue.
 */
void decode_udp_frame(const uint8_t *frame, app_data_t *data) {
    if (frame == NULL || data == NULL) {
        printf("Erreur : trame ou données nulles\n");
        return;
    }

    set_cmd_feux_de_poition(data, (commande_t){frame[0] & 0x01});
    set_cmd_feux_de_route(data, (commande_t){frame[0] & 0x02});
    set_cmd_clignotant_droit(data, (commande_t){frame[0] & 0x04});
    set_cmd_clignotant_gauche(data, (commande_t){frame[0] & 0x08});
    set_cmd_warning(data, (commande_t){frame[0] & 0x10});
    set_activation_essuie_glaces(data, (commande_t){frame[0] & 0x20});
    set_activation_lave_glace(data, (commande_t){frame[0] & 0x40});
}

/**
 * \brief Détermine le prochain événement à partir de l'état actuel.
 * \param current_state L'état actuel de la machine à états.
 * \return L'événement détecté.
 */
fsm_event_t get_next_event(fsm_state_t current_state) {
    fsm_event_t event = EV_NONE;
    uint8_t udpFrame[FRAME_SIZE];

    // Lire une trame UDP depuis le driver
    int32_t drvFd = drv_open();
    if (drvFd < 0) {
        printf("Erreur : impossible d'ouvrir le driver.\n");
        return EV_ERR;
    }

    if (drv_read_udp_100ms(drvFd, udpFrame) == DRV_SUCCESS) {
        decode_udp_frame(udpFrame, &app_data);
    } else {
        printf("Erreur lors de la lecture de la trame UDP.\n");
        drv_close(drvFd);
        return EV_ERR;
    }

    drv_close(drvFd);

    /* Déterminer l'événement à partir de app_data */
    if (current_state == ST_ALLUMES && get_cmd_feux_de_poition(&app_data).value) {
        return EV_CMD_1;
    }
    if (!get_cmd_feux_de_poition(&app_data).value) {
        return EV_CMD_0;
    }

    return event;
}

/**
 * \brief Exécute la machine à états.
 */
void fsm_feux_run(void) {
    fsm_event_t event = get_next_event(state);

    for (int i = 0; i < TRANS_COUNT; i++) {
        if ((state == trans[i].state || trans[i].state == ST_ANY) &&
            (event == trans[i].event || trans[i].event == EV_ANY)) {
            state = trans[i].next_state;
            if (trans[i].callback) {
                trans[i].callback();
            }
            break;
        }
    }
}

int main(void) {
    // Initialiser app_data
    init_app_data(&app_data);

    while (state != ST_TERM) {
        fsm_feux_run();
        usleep(100000);
    }

    return 0;
}
