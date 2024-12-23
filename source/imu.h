/******************************************************************************
* File Name:   imu.h
*
* Description: This file contains the function prototypes and constants used
*   in imu.c.
*
* Related Document: See README.md
*
*
*******************************************************************************/

#ifndef IMU_H
#define IMU_H

#include "cy_result.h"
#include "stdbool.h"

/******************************************************************************
 * Global Variables
 *****************************************************************************/
extern volatile bool imu_flag;

/******************************************************************************
 * Constants
 *****************************************************************************/

/*******************************************************************************
* Function Prototypes
*******************************************************************************/
cy_rslt_t imu_init(void);


#endif /* IMU_H */
