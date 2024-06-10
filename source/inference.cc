/******************************************************************************
* File Name:   inference.c
*
* Description: This file implements the inference engine initialization.
*
* Related Document: See README.md
*
*
*******************************************************************************/
#include "cyhal.h"
#include "cybsp.h"
#include "stdio.h"
#include "stdlib.h"

#include "mtb_ml_utils.h"
#include "mtb_ml_common.h"

#include "config.h"
#include "imu_model.h"
#include "pdm_model.h"

#include "cy_retarget_io.h"

/* Include model files */
#include MTB_ML_INCLUDE_MODEL_FILE(MODEL_NAME)
/*******************************************************************************
* Macros
*******************************************************************************/
#define MIN_CONFIDENCE 0.50
/*******************************************************************************
* Global Variables
*******************************************************************************/
/* Model information */
mtb_ml_model_t *imagimob_model_obj;

/* Output/result buffers for the inference engine */
static MTB_ML_DATA_T *result_buffer;

/* Model Output Size */
static int model_output_size;
#if INFERENCE_MODE_SELECT == IMU_INFERENCE
static const char* LABELS[IMAI_IMU_DATA_OUT_COUNT] = IMAI_IMU_SYMBOL_MAP;
#else
static const char* LABELS[IMAI_PDM_DATA_OUT_COUNT] = IMAI_PDM_SYMBOL_MAP;
#endif
/*******************************************************************************
* Function Name: inference_init
********************************************************************************
* Summary:
*  Initializes the neural network based on the Imagimob model.
*
* Parameters:
*  None
*
* Returns:
*  The status of the initialization.
*
*******************************************************************************/
cy_rslt_t inference_init(void)
{
    cy_rslt_t result;

    mtb_ml_model_bin_t imagimob_model_bin = {MTB_ML_MODEL_BIN_DATA(MODEL_NAME)};

    /* Initialize the Neural Network */
    result = mtb_ml_model_init(&imagimob_model_bin, NULL, &imagimob_model_obj);
    if(CY_RSLT_SUCCESS != result)
    {
        return result;
    }

    mtb_ml_model_get_output(imagimob_model_obj, &result_buffer, &model_output_size);

        return result;
}

/*******************************************************************************
* Function Name: inference_feed
********************************************************************************
* Summary:
*  Feeds the inference engine the pre-processed data.
*
* Parameters:
*  processed_data: Data to be fed to the inference engine.
*
* Returns:
*  None
*
*******************************************************************************/
void inference_feed(float *processed_data)
{
#if !COMPONENT_ML_FLOAT32
            /* Quantize data before feeding model */
            MTB_ML_DATA_T data_feed_int[PDM_BATCH_SIZE][PDM_NUM_AXIS];
            mtb_ml_utils_model_quantize(imagimob_model_obj, &processed_data[0][0], &data_feed_int[0][0]);

            /* Feed the Model */
            MTB_ML_DATA_T *input_reference = (MTB_ML_DATA_T *) data_feed_int;
            mtb_ml_model_run(imagimob_model_obj, input_reference);
            mtb_ml_utils_model_dequantize(imagimob_model_obj, results);

#else
            MTB_ML_DATA_T *input_reference = (MTB_ML_DATA_T *) processed_data;
            mtb_ml_model_run(imagimob_model_obj, input_reference);
#endif
}

/*******************************************************************************
* Function Name: inference_output_control
********************************************************************************
* Summary:
*    A function used to print the results from the inference engine, such as the
*   the class and the confidence of each class.
*
* Parameters:
*   None
*
* Return:
*     None
*
*
*******************************************************************************/
void inference_output_control(void)
{

#if !COMPONENT_ML_FLOAT32
    /* Convert 8-bit fixed-point output to floating-point for visualization */
    float *nn_float_buffer = (float *) malloc(model_output_size * sizeof(float));
    mtb_ml_utils_model_dequantize(imagimob_model_obj, nn_float_buffer);
#else
    float *nn_float_buffer = result_buffer;
#endif

    /* Prints the classifications with the confidence */
    printf("\x1b[2J\x1b[;H");
    printf("******* Machine Learning: Imagimob MTBML Deploy *******\r\n\n");
    for (uint8_t i = 0; i < model_output_size; i++)
    {
        printf("%-8s: %f%%\r\n", LABELS[i], 100 * nn_float_buffer[i]);
    }

#if !COMPONENT_ML_FLOAT32
    free(nn_float_buffer);
#endif
}
