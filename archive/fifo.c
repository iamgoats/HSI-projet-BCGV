/**
 * \file        fifo.c
 * \author      Alexis Daley
 * \version     1.1
 * \date        02 february 2021
 * \brief       This files allow a user to create and manage a fifo buffer (circular buffer).
 * \details     This file gives the interfaces to be able to create and manage the fifo buffer.
 *              Concerning threads, the fifo is designed for one producer one consumer.
 *
 *              It implements following functions :
 *                  init : to init the fifo buffer
 *                  push : insert in the buffer
 *                  read : get fist data from the buffer
 *                  next : go to the next value, and read the new value
 */

#include "fifo.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

/**
 * \brief   Struct to describe fifo object
 * \details Contains read and write index, and the buffer
 */
struct hsi_fifo_s
{
    volatile uint32_t read_index;       /*!< read index */
    volatile uint32_t write_index;      /*!< write index */
    volatile uint32_t rejected_count;   /*!< count the number of rejected values in push (if fifo is full for example) */
    fifo_item_t buff[FIFO_MAX_ITEMS];   /*!< buffer for the fifo */
};

static hsi_fifo_t fifo;

/**
 * \brief       Thread safe setting a uint32_t to a value
 * \details     do *src = var2, using only atomic functions
 *              Warning : We must to be sure that *src is not set during execution of this function
 * \param      	src     : pointer to variable to set
 * \param       value   : value to set
 * \return   	int32_t : 0 if everything is OK -errno otherwise
 */
static void set_atomic(volatile uint32_t* src, uint32_t value)
{
    uint32_t src_value = *src;
    uint32_t delta = 0;

    if (value == 0)
    {
        (*src) &= 0x00000000;
    }
    else if (src_value < value)
    {
        delta = value - src_value;
        (*src) += delta;
    }
    else if (src_value > value) {
        delta = src_value - value;
        (*src) -= delta;
    }
}

hsi_fifo_t* fifo_init(void)
{
    fifo.write_index = 0;
    fifo.read_index = 0;
    fifo.rejected_count = 0;
    memset(&fifo.buff, 0, sizeof(fifo.buff));

    return &fifo;
}

hsi_fifo_t* fifo_get_pointer(void)
{
    return &fifo;
}

int32_t fifo_push(hsi_fifo_t* p_fifo, const fifo_item_t* item)
{
    int32_t ret = FIFO_DATA;
    uint32_t new_write_index = (p_fifo->write_index + 1) % FIFO_MAX_ITEMS;

    if (p_fifo == NULL || item == NULL) {
        ret = FIFO_FAILURE;
    }
    else if (new_write_index == p_fifo->read_index) {
        ret = FIFO_OVERRUN;
    }
    else {
        memcpy(&p_fifo->buff[p_fifo->write_index], item, sizeof(*item));
        set_atomic(&p_fifo->write_index, new_write_index);
    }

    return ret;
}

int32_t fifo_read(hsi_fifo_t* p_fifo, fifo_item_t* item)
{
    int32_t ret = 0;

    if (p_fifo == NULL || item == NULL) {
        ret = FIFO_FAILURE;
    }
    else if (p_fifo->rejected_count > 0)
    {
        p_fifo->rejected_count &= 0x00000000;
        ret = FIFO_LOST;
    }
    else if (p_fifo->read_index == p_fifo->write_index) {  /* read = write -> empty fifo */
        ret = FIFO_EMPTY;
    }
    else
    {
        memcpy(item, &p_fifo->buff[p_fifo->read_index], sizeof(*item));
        ret = FIFO_DATA;
    }
    return ret;
}

int32_t fifo_next(hsi_fifo_t* p_fifo, fifo_item_t* item)
{
    int32_t ret = 0;

    if (p_fifo == NULL ) {
        ret = FIFO_FAILURE;
    }
    else if (p_fifo->read_index == p_fifo->write_index) /* read = write -> empty fifo */
    {
        ret = FIFO_EMPTY;
    }
    else {
        set_atomic(&p_fifo->read_index, (p_fifo->read_index + 1) % FIFO_MAX_ITEMS);
        ret = fifo_read(p_fifo, item);
    }
    return ret;
}
