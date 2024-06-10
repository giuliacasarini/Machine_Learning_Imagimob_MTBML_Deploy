/******************************************************************************
* File Name:   audio.h
*
* Description: This file contains the function prototypes and constants used
*   in audio.c.
*
* Related Document: See README.md
*
*
*******************************************************************************/

#ifndef SOURCE_AUDIO_H_
#define SOURCE_AUDIO_H_

#include "cy_retarget_io.h"
#include "stdbool.h"

/******************************************************************************
 * Constants
 *****************************************************************************/
#define PDM_PROCESSING_INCOMPLETE    0
#define PDM_PROCESSING_COMPLETE      1
/******************************************************************************
 * Global Variables
 *****************************************************************************/
extern volatile bool pdm_pcm_flag;

/*******************************************************************************
* Function Prototypes
*******************************************************************************/
cy_rslt_t pdm_init(void);
bool pdm_preprocessing_feed(float *preprocessed_data);


#endif /* SOURCE_AUDIO_H_ */
