/**
 * \file        fsm_eglg.c
 * \author      Alexis Daley
 * \brief       Machine à états pour les essuie-glaces et lave-glace.
 */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "drv_api.h"
#include "fsm_eglg.h"
#include "app_data.h"

/* Transition structure */
typedef struct {
    fsm_state_t state;
    fsm_event_t event;
    int (*callback)(void);
    fsm_state_t next_state;
} tTransition;

/* Fonctions de réponse */
static int callbackNothing(void) {
    printf("Ne rien faire\n");
    return 0;
}

static int callbackTurnoffALL(void) {
    printf("Tout éteints\n");
    return 0;
}

static int callbackTurnOnEG(void) {
    printf("Activer essuie-glace\n");
    return 0;
}

static int callbackTurnOnLGEG(void) {
    printf("Activer lave-glace et essuie-glace\n");
    return 0;
}

static int callbackTimeout(void) {
    printf("Timer EG et LG éteints\n");
    return 0;
}

static int FsmError(void) {
    printf("Erreur critique détectée.\n");
    return -1;
}

/* Tableau des transitions */
static tTransition trans[] = {
    { ST_INIT, EV_NONE, &callbackTurnoffALL, ST_TOUS_ETEINTS },
    { ST_TOUS_ETEINTS, EV_EG_1, &callbackTurnOnEG, ST_EG_ACTIVE },
    { ST_TOUS_ETEINTS, EV_LG_1, &callbackTurnOnLGEG, ST_LG_EG_ACTIVES },
    { ST_TOUS_ETEINTS, EV_EG_0_LG_0, &callbackNothing, ST_TOUS_ETEINTS },
    { ST_LG_EG_ACTIVES, EV_LG_1, &callbackNothing, ST_LG_EG_ACTIVES },
    { ST_LG_EG_ACTIVES, EV_LG_0, &callbackTimeout, ST_TIMER_ETEINT },
    { ST_TIMER_ETEINT, EV_T_INF_2, &callbackNothing, ST_TIMER_ETEINT },
    { ST_TIMER_ETEINT, EV_T_SUP_2, &callbackTurnoffALL, ST_TOUS_ETEINTS },
    { ST_EG_ACTIVE, EV_LG_1, &callbackTurnOnLGEG, ST_LG_EG_ACTIVES },
    { ST_EG_ACTIVE, EV_EG_1, &callbackNothing, ST_EG_ACTIVE },
    { ST_EG_ACTIVE, EV_EG_0, &callbackTurnoffALL, ST_TOUS_ETEINTS },

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

    data->command = frame[0];
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
        case ST_TOUS_ETEINTS:
            if (app_data.command == 0x01) {
                event = EV_EG_1;
            } else if (app_data.command == 0x02) {
                event = EV_LG_1;
            } else {
                event = EV_EG_0_LG_0;
            }
            break;

        case ST_EG_ACTIVE:
            if (app_data.acquittement) {
                event = EV_T_SUP_2;
            } else {
                event = EV_T_INF_2;
            }
            break;

        case ST_LG_EG_ACTIVES:
            if (app_data.acquittement) {
                event = EV_LG_0;
            } else {
                event = EV_LG_1;
            }
            break;

        case ST_TIMER_ETEINT:
            if (app_data.acquittement) {
                event = EV_EG_0_LG_0;
            }
            break;

        default:
            event = EV_ERR;
            break;
    }

    return event;
}

/**
 * \brief Exécute la machine à états.
 */
void fsm_eglg_run(void) {
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
        fsm_eglg_run();
        usleep(100000);
    }

    return 0;
}
