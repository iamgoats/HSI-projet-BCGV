#ifndef FSM_FEUX_H
#define FSM_FEUX_H

#include <stdint.h>
#include <stdbool.h>

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

void fsm_feux_run(void);
fsm_event_t get_next_event(fsm_state_t current_state);


#endif /* FSM_FEUX_H */
