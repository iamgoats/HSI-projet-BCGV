/**
 * \file        fifo.h
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

#ifndef FIFO_H_
#define FIFO_H_

#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>

/* TODO : Can be adjusted depending on push/read frequency */
#define FIFO_MAX_ITEMS  (256)           /* Max number of elements in fifo */

/* Return codes */
#define FIFO_FAILURE    (-1)            /* Bad parameters, NULL pointers or excluded ID */
#define FIFO_DATA       (0)             /* "Normal" data item is returned or stored */
#define FIFO_EMPTY      (1)             /* (read) FIFO is empty, no data returned */
#define FIFO_OVERRUN    (2)             /* (push) FIFO is full, data item is rejected */
#define FIFO_LOST       (3)             /* (read) 'sz_or_count' set to the count of lost items */

typedef struct fifo_item_s
{
    /* TODO : fill the structure with willing elements */
} fifo_item_t;

/**
 * \brief   Internal structure of the global FIFO header, used internally by FIFO implementation
 * \details Contains read and write index, but client does not need to know its content
 *
 */
typedef struct hsi_fifo_s hsi_fifo_t;     /* forward declaration for the opaque structure */

/**
 * \brief       Init fifo buffer (Should be used by producer thread)
 * \details     Initialize the fifo struct inside of allocated memory
 * \return      hsi_fifo_t : pointer to fifo structure
 *                            NULL in case of error: the size is too small or NULL pointer given
 */
hsi_fifo_t* fifo_init(void);

/**
 * \brief       Get pointer on fifo struct (Should be used by consumer thread)
 * \details
 * \return      hsi_fifo_t : pointer to fifo structure
 */
hsi_fifo_t* fifo_get_pointer(void);

/**
 * \brief       Copy a data to fifo
 * \details
 * \param       p_fifo  : Pointer to the fifo object
 * \param       item    : Pointer on item to push
 * \return      int32_t : FIFO_DATA if everything is OK
 *                        FIFO_OVERRUN (fifo full)
 *                        FIFO_FAILURE (pointer null or reserved ID gived)
 */
int32_t fifo_push(hsi_fifo_t* p_fifo, const fifo_item_t* item);

/**
 * \brief       Read one data from the fifo (give a pointer to it)
 * \details     Give a pointer to the data which is in the write index.
 *              if there was rejected data on push, return special id (FIFO_LOST)
 * \param       p_fifo      : Pointer to the fifo object
 * \param[out]  item        : Pointer on item data to set
 * \return      int32_t : FIFO_DATA if a data is returned
 *                        FIFO_EMPTY if fifo is empty
 *                        FIFO_LOST if there was rejected data on push
 *                        FIFO_FAILURE if a given pointer is NULL
 */
int32_t fifo_read(hsi_fifo_t* p_fifo, fifo_item_t* item);

/**
 * \brief       Place the read index to the next item, and call fifo_read with this new index
 * \details
 * \param       p_fifo      : Pointer to the fifo object
 * \param[out]  item        : Pointer on item data to set
 *                            if ret value is  FIFO_LOST : number of data lost
 * \return      int32_t : FIFO_DATA if a data is returned
 *                        FIFO_EMPTY  if fifo is empty
 *                        FIFO_LOST if there was rejected data on push
 *                        FIFO_FAILURE - if a given pointer is NULL
 */
int32_t fifo_next(hsi_fifo_t* p_fifo, fifo_item_t* item);


#endif /* FIFO_H_ */
