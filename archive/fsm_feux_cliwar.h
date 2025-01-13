
#ifndef FSM_FEUX_CLIWAR_H
#define FSM_FEUX_CLIWAR_H

#include <stdint.h>
#include <stdbool.h>

/* FSM states */
typedef enum {
    ST_ANY = -1,        
    ST_INIT = 0,         
    ST_ETEINTS = 1,      
    ST_ALLUMES = 2,      
    ST_ACQUITTES_VOYANT_ALLUME = 3, 
    ST_ACQUITTES_VOYANT_ETEINT = 4, 
    ST_ACTIV_ALLU = 5,   
    ST_ACT_ET = 6,       
    ST_ERREUR = 7,       
    ST_TERM = 255        
} fsm_state_t;

/* FSM events */
typedef enum {
    EV_ANY = -1,         
    EV_NONE = 0,         
    EV_CMD_0 = 1,        
    EV_CMD_1 = 2,        
    EV_ACQUITTEMENT_RECU = 3, 
    EV_ACQUITTEMENT_NR_1 = 4, 
    EV_T_1 = 5,          
    EV_ERR = 255         
} fsm_event_t;


void fsm_feux_cliwar_run(void);


fsm_event_t get_next_event(fsm_state_t current_state);

#endif /* FSM_FEUX_CLIWAR_H */
