/******************************************************************************
* File Name:   config.h
*
* Description: This file contains the configuration for running either the IMU
* based model, or the PDM based model.
*
* Related Document: See README.md
*
*
*******************************************************************************/
#ifndef CONFIG_H
#define CONFIG_H

#include "IIS2DLPCSensor.h"
/******************************************************************************
 * Constants
 *****************************************************************************/

/* Type of inference */
#define IMU_INFERENCE    1
#define PDM_INFERENCE    2

/* Change below define to IMU_INFERENCE or PDM_INFERENCE */
#define INFERENCE_MODE_SELECT IMU_INFERENCE

/* Set IMU_SAMPLE_RATE to one of the following
 * BMI160_ACCEL_ODR_400HZ
 * BMI160_ACCEL_ODR_200HZ
 * BMI160_ACCEL_ODR_100HZ
 * BMI160_ACCEL_ODR_50HZ */
#define IMU_SAMPLE_RATE BMI160_ACCEL_ODR_50HZ

/*Set IMU_SAMPLE_RANGE to one of the following
 * BMI160_ACCEL_RANGE_2G
 * BMI160_ACCEL_RANGE_4G
 * BMI160_ACCEL_RANGE_8G
 * BMI160_ACCEL_RANGE_16G */
#define IMU_SAMPLE_RANGE BMI160_ACCEL_RANGE_8G

/* PDM sample rates */
#define SAMPLE_RATE_8_KHZ    8000u
#define SAMPLE_RATE_16_KHZ   16000u

/* Change below to SAMPLE_RATE_8_KHZ or SAMPLE_RATE_16_KHZ */
#define PDM_SAMPLE_RATE SAMPLE_RATE_16_KHZ

#endif /* CONFIG_H */

