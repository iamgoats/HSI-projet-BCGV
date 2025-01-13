#ifndef FSM_EGLG_H
#define FSM_EGLG_H

#include <stdint.h>
#include <stdbool.h>

/* FSM states */
typedef enum {
    ST_ANY = -1,         /**< Any state */
    ST_INIT = 0,         /**< Init state */
    ST_TOUS_ETEINTS = 1, /**< All off */
    ST_EG_ACTIVE = 2,    /**< Wipers active */
    ST_LG_EG_ACTIVES = 3,/**< Washer + wipers active */
    ST_TIMER_ETEINT = 4, /**< Timer finished */
    ST_TERM = 255        /**< Terminal state */
} fsm_state_t;

/* FSM events */
typedef enum {
    EV_ANY = -1,         /**< Any event */
    EV_NONE = 0,         /**< No event */
    EV_EG_0_LG_0 = 1,    /**< Wipers and washer off */
    EV_LG_1 = 2,         /**< Washer active */
    EV_EG_1 = 3,         /**< Wipers active */
    EV_LG_0 = 4,         /**< Washer off */
    EV_EG_0 = 5,         /**< Wipers off */
    EV_T_INF_2 = 6,      /**< Timer <= 2 seconds */
    EV_T_SUP_2 = 7,      /**< Timer > 2 seconds */
    EV_ERR = 255         /**< Error event */
} fsm_event_t;

/* Prototypes */
void fsm_eglg_run(void);
fsm_event_t get_next_event(fsm_state_t current_state);

#endif /* FSM_EGLG_H */
