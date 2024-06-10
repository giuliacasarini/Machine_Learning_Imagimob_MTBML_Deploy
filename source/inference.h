/******************************************************************************
* File Name:   imu.h
*
* Description: This file contains the function prototypes and constants used
*   in inference.c.
*
* Related Document: See README.md
*
*
*******************************************************************************/

#ifndef SOURCE_INFERENCE_H_
#define SOURCE_INFERENCE_H_

#include "cy_result.h"
/*******************************************************************************
* Macros
*******************************************************************************/

/*******************************************************************************
* Global Variables
*******************************************************************************/

/*******************************************************************************
* Function Prototypes
*******************************************************************************/
cy_rslt_t inference_init(void);
void inference_feed(float *processed_data);
void inference_output_control(void);

#endif /* SOURCE_INFERENCE_H_ */
