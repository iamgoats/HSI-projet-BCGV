/**
 * \file        drv_api.h
 * \author      Alexis Daley
 * \version     1.0
 * \date        27/02/2022
 * \brief       This file describe the interface with driver
 * \details     It provides following functions : 
 *              - drv_open              : Open connection between client and driver
 *              - drv_read_udp_100ms    : Read UDP 100ms frame in blocking mode(block until receiving a frame)
 *              - drv_write_udp_200ms   : Write udp 200ms frame
 *              - drv_read_ser          : Read serial messages received on all lines
 *              - drv_write_ser         : Write serial messages
 *              - drv_close             : close connexion between client and driver
 *              Must be delivered with static library (drv_api.a) and driver executable file (driver)
 */

#ifndef DRV_API_H_
#define DRV_API_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define DRV_SUCCESS         0
#define DRV_ERROR           -1
#define DRV_VER_MISMATCH    -2

#define SER_MAX_FRAME_SIZE          (2)
#define DRV_MAX_FRAMES              (16)
#define DRV_UDP_100MS_FRAME_SIZE    (15)
#define DRV_UDP_200MS_FRAME_SIZE    (10)

typedef struct {
    uint32_t serNum;                    /* Physical ser number */
    uint8_t frame[SER_MAX_FRAME_SIZE];  /* Frame received/to write */
    size_t frameSize;                   /* Size of received frame */
} serial_frame_t;

/**
 * \brief Open connection with driver, and returns file descriptor of channel
 * \param   void
 * \return int32_t : File descriptor (positive value), error otherwise :
 *                      - DRV_ERROR if an error occurs (is driver started ?)
 *                      - DRV_VER_MISMATCH if version of API is not compatible with driver
 */
int32_t drv_open(void);

/**
 * \brief   Read UDP 100ms frame (blocking call)
 * \details Wait for next UDP 100ms frame and returns it
 * \param       drvFd       : File descriptor of channel with driver (get with open)
 * \param[out]  udpFrame    : Structure to fill with udp frame
 * \return int32_t : DRV_SUCCESS, or DRV_ERROR if an error occurs
 */
int32_t drv_read_udp_100ms(int32_t drvFd, uint8_t udpFrame[DRV_UDP_100MS_FRAME_SIZE]);

/**
 * \brief   Write UDP 200ms frame
 * \param       drvFd       : File descriptor of channel with driver (get with open)
 * \param       udpFrame    : Structure to write
 * \return int32_t : DRV_SUCCESS, or DRV_ERROR if an error occurs
 */
int32_t drv_write_udp_200ms(int32_t drvFd, uint8_t udpFrame[DRV_UDP_200MS_FRAME_SIZE]);

/**
 * \brief Give all serial message received since the last call
 * \param       drvFd           : File descriptor of channel with driver (get with open)
 * \param[out]  serialData      : Structure to fill with read messages
 * \param[out]  serialDataLen   : Number of element in serialData structure
 * \return int32_t : DRV_SUCCESS, or DRV_ERROR if an error occurs
 */
int32_t drv_read_ser(int32_t drvFd, serial_frame_t serialData[DRV_MAX_FRAMES], uint32_t* serialDataLen);

/**
 * \brief Write data on serial lines
 * \param   drvFd           : File descriptor of channel with driver (get with open)
 * \param   serialData      : Pointer on structure containing messages to write on lines
 * \param   serialDataLen   : Number of element in serialData structure
 * \return int32_t : DRV_SUCCESS, or DRV_ERROR if an error occurs
 */
int32_t drv_write_ser(int32_t drvFd, serial_frame_t* serialData, uint32_t serialDataLen);

/**
 * \brief Close connection with driver
 * \param   drvFd           : File descriptor of channel with driver (get with open)
 * \return int32_t : DRV_SUCCESS, or DRV_ERROR if an error occurs
 */
int32_t drv_close(int32_t drvFd);

#endif /* DRV_API_H_ */
