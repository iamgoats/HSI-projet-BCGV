/**
 * \file        fsm_feux_cliwar.c
 * \author      Alexis Daley
 * \brief       Machine à états pour les feux clignotants et warnings.
 */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "drv_api.h"
#include "fsm_feux_cliwar.h"
#include "app_data.h"

/* Transition structure */
typedef struct {
    fsm_state_t state;
    fsm_event_t event;
    int (*callback)(void);
    fsm_state_t next_state;
} tTransition;

/* Fonctions de réponse*/
static int callbackNothing(void) {
    printf("Ne rien faire\n");
    return 0;
}

static int callbackTurnoffLights(void) {
    printf("Éteindre les lumières\n");
    return 0;
}

static int callbackTurnOnLightsAndActivate(void) {
    printf("Allumer les lumières et activer\n");
    return 0;
}

static int callbackHandleAcknowledgment(void) {
    printf("Acquitter\n");
    return 0;
}

static int callbackHandleTimeout(void) {
    printf("Temps supérieur à 1 seconde\n");
    return 0;
}

static int FsmError(void) {
    printf("Erreur critique détectée\n");
    return -1;
}

/* Tableau des transitions */
static tTransition trans[] = {
    { ST_INIT, EV_NONE, &callbackTurnoffLights, ST_ETEINTS },
    { ST_ETEINTS, EV_CMD_0, &callbackNothing, ST_ETEINTS },
    { ST_ETEINTS, EV_CMD_1, &callbackTurnOnLightsAndActivate, ST_ACTIV_ALLU },
    { ST_ACTIV_ALLU, EV_CMD_1, &callbackNothing, ST_ACTIV_ALLU },
    { ST_ACTIV_ALLU, EV_ACQUITTEMENT_RECU, &callbackHandleAcknowledgment, ST_ACQUITTES_VOYANT_ALLUME },
    { ST_ACTIV_ALLU, EV_ACQUITTEMENT_NR_1, &callbackHandleTimeout, ST_ERREUR },
    { ST_ACQUITTES_VOYANT_ALLUME, EV_CMD_1, &callbackNothing, ST_ACQUITTES_VOYANT_ALLUME },
    { ST_ACQUITTES_VOYANT_ALLUME, EV_CMD_0, &callbackTurnoffLights, ST_ETEINTS },
    { ST_ACQUITTES_VOYANT_ALLUME, EV_T_1, &callbackHandleTimeout, ST_ACT_ET },
    { ST_ACT_ET, EV_CMD_1, &callbackNothing, ST_ACT_ET },
    { ST_ACT_ET, EV_CMD_0, &callbackTurnoffLights, ST_ETEINTS },
    { ST_ACT_ET, EV_ACQUITTEMENT_RECU, &callbackHandleAcknowledgment, ST_ACQUITTES_VOYANT_ETEINT },
    { ST_ACQUITTES_VOYANT_ETEINT, EV_CMD_1, &callbackNothing, ST_ACQUITTES_VOYANT_ETEINT },
    { ST_ACQUITTES_VOYANT_ETEINT, EV_CMD_0, &callbackTurnoffLights, ST_ETEINTS },
    { ST_ACQUITTES_VOYANT_ETEINT, EV_T_1, &callbackTurnOnLightsAndActivate, ST_ACTIV_ALLU },
    { ST_ERREUR, EV_NONE, &FsmError, ST_TERM },
    { ST_ANY, EV_ERR, &FsmError, ST_TERM }
};

#define TRANS_COUNT (sizeof(trans) / sizeof(*trans))

static fsm_state_t state = ST_INIT;
static t_app_data_t app_data;

/**
 * \brief Décoder une trame UDP et mettre à jour app_data.
 * \param frame : Trame UDP reçue.
 */
void decode_udp_frame(const uint8_t *frame, t_app_data_t *data) {
    if (frame == NULL || data == NULL) {
        printf("Erreur : trame ou données nulles\n");
        return;
    }

    data->command =frame[0];
    data->acquittement = frame[1];

}

/**
 * \brief Détermine le prochain événement à partir de l'état actuel.
 * \param current_state L'état actuel de la machine à états.
 * \return L'événement détecté.
 */
fsm_event_t get_next_event(fsm_state_t current_state) {
    fsm_event_t event = EV_NONE;
    uint8_t udpFrame[DRV_UDP_100MS_FRAME_SIZE];


 
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
    switch (current_state) {
        case ST_ACTIV_ALLU:
            if (app_data.acquittement) {
                return EV_ACQUITTEMENT_RECU;
            }
            break;
        default:
            break;
    }

    if (app_data.command == 0x01) {
        event = EV_CMD_1;
    } else if (app_data.command == 0x00) {
        event = EV_CMD_0;
    }

    return event;
}

/**
 * \brief Exécute la machine à états.
 */
void fsm_feux_cliwar_run(void) {
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
    app_data.command = 0;
    app_data.acquittement = false;

    while (state != ST_TERM) {
        fsm_feux_cliwar_run();
        usleep(100000);
    }

    return 0;
}
