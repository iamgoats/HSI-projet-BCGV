/**
 * \file        fsm.c
 * \author      Alexis Daley
 * \version     0.4
 * \date        08 otober 2023
 * \brief       This is a template file to create a Finite State Machine.
 * \details
 */


#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "drv_api.h"


/* States */
typedef enum {
    ST_ANY = -1,                            /* Any state */
    ST_INIT = 0,                            /* Init state */
    ST_TOUS_ETEINTS = 1,                         /*State OFF && State EVERYTHING OFF*/
    ST_EG_ACTIVE= 2,
    ST_LG_EG_ACTIVES= 3,
    ST_TIMER_ETEINT = 4,
    ST_TERM = 255                           /* Final state */
} fsm_state_t;

/* Events */
typedef enum {
    EV_ANY = -1,                            /* Any event */
    EV_NONE = 0,                            /* No event */                          
    EV_EG_0_LG_0 = 1,
    EV_LG_1 = 2,
    EV_EG_1 = 3,
    EV_LG_0 = 4,
    EV_EG_0 = 5,
    EV_T_INF_2 = 6,
    EV_T_SUP_2 = 7,
    EV_ERR = 255                            /* Error event */
} fsm_event_t;

/* Callback functions called on transitions */
static int callbackNothing(void){
    printf("Ne rien faire");
    return 0;
}
static int callbackTurnoffALL(void){
    printf("Tout éteints");
    return 0;
}
static int callbackTurnOnEG(void){
    printf("Activer essuis-glace");
    return 0;
}
static int callbackTurnOnLGEG(void) {
    printf("Activer lave glece et essuie glace");
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

/* Transition structure */
typedef struct {
    fsm_state_t state;
    fsm_event_t event;
    int (*callback)(void);
    int next_state;
} tTransition;

/* Transition table */
tTransition trans[] = {
    /* These are examples */
    { ST_INIT, EV_NONE,&callbackTurnoffALL,ST_TOUS_ETEINTS},
    { ST_TOUS_ETEINTS, EV_EG_1, &callbackTurnOnEG, ST_EG_ACTIVE},
    { ST_TOUS_ETEINTS, EV_LG_1, &callbackTurnOnLGEG, ST_LG_EG_ACTIVES},
    { ST_TOUS_ETEINTS, EV_EG_0_LG_0, &callbackNothing, ST_TOUS_ETEINTS},
    { ST_LG_EG_ACTIVES, EV_LG_1, &callbackNothing, ST_LG_EG_ACTIVES},
    { ST_LG_EG_ACTIVES, EV_LG_0, &callbackTimeout, ST_TIMER_ETEINT},
    { ST_TIMER_ETEINT, EV_T_INF_2, &callbackNothing, ST_TIMER_ETEINT},
    { ST_TIMER_ETEINT, EV_T_SUP_2, &callbackTurnoffALL, ST_TOUS_ETEINTS},
    { ST_EG_ACTIVE,EV_LG_1, &callbackTurnOnLGEG, ST_LG_EG_ACTIVES},
    { ST_EG_ACTIVE,EV_EG_1,&callbackNothing, ST_EG_ACTIVE},
    {ST_EG_ACTIVE,EV_EG_0,&callbackTurnoffALL,ST_TOUS_ETEINTS},

    { ST_ANY, EV_ERR, &FsmError, ST_TERM}
};

#define TRANS_COUNT (sizeof(trans)/sizeof(*trans))

int get_next_event(int current_state)
{
    int event = EV_NONE;           // Initialisation à aucun événement
    int sensorValue = 0;           // Simulation d'un capteur ou d'une commande
    int timerValue = 0;            // Simulation d'un timer ou compteur

    // Exemple : Gérer les événements selon l'état courant
    switch (current_state) {
        case ST_INIT:
            // Par défaut, retourner l'événement NONE ou un état initial
            event = EV_NONE;
            break;

        case ST_TOUS_ETEINTS:
            // Simuler une condition pour activer les essuie-glaces
            sensorValue = readSensor();
            if (sensorValue == 1) {
                event = EV_EG_1; // Activer les essuie-glaces
            } else if (sensorValue == 2) {
                event = EV_LG_1; // Activer lave-glace + essuie-glaces
            } else {
                event = EV_EG_0_LG_0; // Aucun capteur actif
            }
            break;

        case ST_EG_ACTIVE:
            // Simuler la gestion d'un timer
            timerValue = readTimer();
            if (timerValue > 10) {
                event = EV_T_SUP_2; // Timer > 10
            } else if (timerValue <= 2) {
                event = EV_T_INF_2; // Timer <= 2
            }
            break;

        case ST_LG_EG_ACTIVES:
            // Gérer des commandes via des entrées externes
            sensorValue = readSensor();
            if (sensorValue == 0) {
                event = EV_LG_0; // Lave-glace désactivé
            } else {
                event = EV_LG_1; // Lave-glace toujours actif
            }
            break;

        case ST_TIMER_ETEINT:
            // Vérification des états lorsque tout est éteint
            sensorValue = readSensor();
            if (sensorValue == 0) {
                event = EV_EG_0_LG_0; // Tout reste éteint
            }
            break;

        default:
            // Gestion par défaut ou erreur
            printf("État inconnu : %d\n", current_state);
            event = EV_ERR; // Retourne un événement d'erreur
            break;
    }

    return event; // Retourne l'événement déterminé
}

int main(void)
{
    int i = 0;
    int ret = 0; 
    int event = EV_NONE;
    int state = ST_INIT;
    
    /* While FSM hasn't reach end state */
    while (state != ST_TERM) {
        
        /* Get event */
        event = get_next_event(state);
        
        /* For each transitions */
        for (i = 0; i < TRANS_COUNT; i++) {
            /* If State is current state OR The transition applies to all states ...*/
            if ((state == trans[i].state) || (ST_ANY == trans[i].state)) {
                /* If event is the transition event OR the event applies to all */
                if ((event == trans[i].event) || (EV_ANY == trans[i].event)) {
                    /* Apply the new state */
                    state = trans[i].next_state;
                    if (trans[i].callback != NULL) {
                        /* Call the state function */
                        ret = (trans[i].callback)();
                    }
                    break;
                }
            }
        }
    }

    return ret;
}
