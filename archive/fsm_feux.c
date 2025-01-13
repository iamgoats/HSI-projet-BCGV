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
    ST_ETEINTS = 1,                         /*State OFF && State EVERYTHING OFF*/
    ST_ALLUMES = 2,
    ST_ACQUITTES = 3,
    ST_ERREUR = 4,
    ST_TERM = 255                           /* Final state */
} fsm_state_t;

/* Events */
typedef enum {
    EV_ANY = -1,                            /* Any event */
    EV_NONE = 0,                            /* No event */
    EV_CMD_0 = 1,                           
    EV_CMD_1 = 2,                           
    EV_ACQUITTEMENT_RECU = 3,
    EV_ACQUITTEMENT_NR_1 = 4,
    EV_ERR = 255                            /* Error event */
} fsm_event_t;

static int callbackNothing(void){
    printf("Ne rien faire");
    return 0;
}
static int callbackTurnOnLights(void){
    printf("Allumer la lumière");
    return 0;
}
static int callbackHandleAcknowledgment(void) {
    printf("Acquitter");
    return 0;
}

static int callbackHandleTimeout(void) {
    printf("Temps supérieur à 1 sec\n");
    return 0;
}

static int callbackTurnOffLights(void) {
    printf("Eteindre");
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
    {ST_INIT, EV_NONE, &callbackTurnOffLights, ST_ETEINTS },
    { ST_ETEINTS, EV_CMD_1, &callbackTurnOnLights, ST_ALLUMES },
    { ST_ETEINTS,EV_CMD_0,&callbackNothing, ST_ETEINTS },
    { ST_ALLUMES,EV_CMD_0,&callbackNothing,ST_ALLUMES },
    { ST_ALLUMES, EV_ACQUITTEMENT_RECU, &callbackHandleAcknowledgment, ST_ACQUITTES },
    { ST_ALLUMES, EV_ACQUITTEMENT_NR_1, &callbackHandleTimeout, ST_ERREUR },
    { ST_ACQUITTES, EV_CMD_0, &callbackTurnOffLights, ST_ETEINTS },
    { ST_ACQUITTES, EV_CMD_0, &callbackNothing, ST_ACQUITTES },
    { ST_ERREUR, EV_NONE, &FsmError, ST_TERM },
    { ST_ANY, EV_ERR, &FsmError, ST_TERM }
};


#define TRANS_COUNT (sizeof(trans)/sizeof(*trans))


 int get_next_event(int current_state) {

    int event = EV_NONE;
    int command = 0;
    bool acquittement = false;


    if (current_state == ST_ALLUMES) {
        int32_t drvFd = drv_open();
        if (drvFd < 0) {
            printf("Erreur : impossible d'ouvrir le driver.\n");
            return EV_ERR; 
        }

        for (int i = 0; i < 10; i++) {
            acquittement = getAcquittement();
            if (acquittement) {
                drv_close(drvFd);
                return EV_ACQUITTEMENT_RECU; 
            }

            
            uint8_t udpFrame[DRV_UDP_100MS_FRAME_SIZE];
            if (drv_read_udp_100ms(drvFd, udpFrame) == DRV_SUCCESS) {
                command = udpFrame[0];
                switch (command) {
                    case 0x01: 
                        drv_close(drvFd);
                        return EV_CMD_1;
                    case 0x00: 
                        drv_close(drvFd);
                        return EV_CMD_0;
                }
            }
        }

        
        drv_close(drvFd);
        return EV_ACQUITTEMENT_NR_1; 
    }
 
    command = getCommand();
    switch (command) {
        case 0x01: 
            event = EV_CMD_1;
            break;
        case 0x00: 
            event = EV_CMD_0;
            break;
        default:
            printf("Commande inconnue : %02X\n", command);
            break;
    }

    return event;
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
