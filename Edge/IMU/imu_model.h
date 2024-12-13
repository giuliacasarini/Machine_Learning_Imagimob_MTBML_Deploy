/*
* Imagimob Studio 4.8.1397+ec7f68f457701b125b40ecb6a3e43a64ab83bbf6
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 06/13/2024 12:33:04 UTC. Any changes will be lost.
* 
* Model ID  ad01ecca-1cbb-47c7-aafa-77eb28d5e7a9
* 
* Memory    Size                      Efficiency
* State     952 bytes (RAM)           100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   conv1d-medium-balanced-1
* 
* Class Index | Symbol Label
* 0           | unlabelled
* 1           | circle
* 2           | square
* 3           | sidetoside
* 
* Layer                          Shape           Type       Function
* Sliding Window (data points)   [62,3]          float      dequeue
*    window_shape = [62,3]
*    stride = 15
*    buffer_multiplier = 1
* Contextual Window (Sliding Window) [62,3]          float      dequeue
*    contextual_length_sec = 1.25
*    prediction_freq = 10
* 
* Exported functions:
* 
* int IMAI_IMU_dequeue(float *restrict data_out)
*    Description: Dequeue features. RET_SUCCESS (0) on success, RET_NODATA (-1) if no data is available, RET_NOMEM (-2) on internal memory error
*    Parameter data_out is Output of size float[62,3].
* 
* int IMAI_IMU_enqueue(const float *restrict data_in)
*    Description: Enqueue features. Returns SUCCESS (0) on success, else RET_NOMEM (-2) when low on memory.
*    Parameter data_in is Input of size float[3].
* 
* void IMAI_IMU_init(void)
*    Description: Initializes buffers to initial state. This function also works as a reset function.
* 
* 
* Disclaimer:
*   The generated code relies on the optimizations done by the C compiler.
*   For example many for-loops of length 1 must be removed by the optimizer.
*   This can only be done if the functions are inlined and simplified.
*   Check disassembly if unsure.
*   tl;dr Compile using gcc with -O3 or -Ofast
*/

#ifndef _IMAI_IMU_IMU_MODEL_H_
#define _IMAI_IMU_IMU_MODEL_H_
#ifdef _MSC_VER
#pragma once
#endif

#include <stdint.h>

typedef struct {    
    char *name;
    double TP; // True Positive or Correct Positive Prediction
    double FN; // False Negative or Incorrect Negative Prediction
    double FP; // False Positive or Incorrect Positive Prediction
    double TN; // True Negative or Correct Negative Prediction
    double TPR; // True Positive Rate or Sensitivity, Recall
    double TNR; // True Negative Rate or Specificity, Selectivity
    double PPV; // Positive Predictive Value or Precision
    double NPV; // Negative Predictive Value
    double FNR; // False Negative Rate or Miss Rate
    double FPR; // False Positive Rate or Fall-Out
    double FDR; // False Discovery Rate
    double FOR; // False Omission Rate
    double F1S; // F1 Score
} IMAI_IMU_stats;

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 91.159 %
* (F1S) F1 Score 91.553 %
* 
* Name of class                                            (unlabelled)           circle       sidetoside           square
* (TP) True Positive or Correct Positive Prediction                1909              301              165              378
* (FN) False Negative or Incorrect Negative Prediction              159               20               24               64
* (FP) False Positive or Incorrect Positive Prediction               96               19              126               26
* (TN) True Negative or Correct Negative Prediction                 856             2680             2705             2552
* (TPR) True Positive Rate or Sensitivity, Recall               92.31 %          93.77 %          87.30 %          85.52 %
* (TNR) True Negative Rate or Specificity, Selectivity          89.92 %          99.30 %          95.55 %          98.99 %
* (PPV) Positive Predictive Value or Precision                  95.21 %          94.06 %          56.70 %          93.56 %
* (NPV) Negative Predictive Value                               84.33 %          99.26 %          99.12 %          97.55 %
* (FNR) False Negative Rate or Miss Rate                         7.69 %           6.23 %          12.70 %          14.48 %
* (FPR) False Positive Rate or Fall-Out                         10.08 %           0.70 %           4.45 %           1.01 %
* (FDR) False Discovery Rate                                     4.79 %           5.94 %          43.30 %           6.44 %
* (FOR) False Omission Rate                                     15.67 %           0.74 %           0.88 %           2.45 %
* (F1S) F1 Score                                                93.74 %          93.92 %          68.75 %          89.36 %
*/


#define IMAI_IMU_TRAIN_AVG_ACC 0.91158940397351 // Accuracy
#define IMAI_IMU_TRAIN_AVG_F1S 0.9155343273592456 // F1 Score

#define IMAI_IMU_TRAIN_STATS { \
 {name: "(unlabelled)", TP: 1909, FN: 159, FP: 96, TN: 856, TPR: 0.9231141199226, TNR: 0.8991596638655, PPV: 0.9521197007481, NPV: 0.8433497536945, FNR: 0.0768858800773, FPR: 0.1008403361344, FDR: 0.0478802992518, FOR: 0.1566502463054, F1S: 0.9373925853179, }, \
 {name: "circle", TP: 301, FN: 20, FP: 19, TN: 2680, TPR: 0.9376947040498, TNR: 0.9929603556872, PPV: 0.940625, NPV: 0.9925925925925, FNR: 0.0623052959501, FPR: 0.0070396443127, FDR: 0.059375, FOR: 0.0074074074074, F1S: 0.9391575663026, }, \
 {name: "square", TP: 378, FN: 64, FP: 26, TN: 2552, TPR: 0.8552036199095, TNR: 0.9899146625290, PPV: 0.9356435643564, NPV: 0.9755351681957, FNR: 0.1447963800904, FPR: 0.0100853374709, FDR: 0.0643564356435, FOR: 0.0244648318042, F1S: 0.8936170212765, }, \
 {name: "sidetoside", TP: 165, FN: 24, FP: 126, TN: 2705, TPR: 0.8730158730158, TNR: 0.9554927587424, PPV: 0.5670103092783, NPV: 0.9912055698057, FNR: 0.1269841269841, FPR: 0.0445072412575, FDR: 0.4329896907216, FOR: 0.0087944301942, F1S: 0.6875, }, \
}

#ifdef IMAI_IMU_STATS_ENABLED
static const IMAI_IMU_stats IMAI_IMU_train_stats[] = IMAI_IMU_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 93.012 %
* (F1S) F1 Score 92.724 %
* 
* Name of class                                            (unlabelled)           circle       sidetoside           square
* (TP) True Positive or Correct Positive Prediction                 792              137               30              159
* (FN) False Negative or Incorrect Negative Prediction               35                8               34                7
* (FP) False Positive or Incorrect Positive Prediction               44               10               17               13
* (TN) True Negative or Correct Negative Prediction                 331             1047             1121             1023
* (TPR) True Positive Rate or Sensitivity, Recall               95.77 %          94.48 %          46.88 %          95.78 %
* (TNR) True Negative Rate or Specificity, Selectivity          88.27 %          99.05 %          98.51 %          98.75 %
* (PPV) Positive Predictive Value or Precision                  94.74 %          93.20 %          63.83 %          92.44 %
* (NPV) Negative Predictive Value                               90.44 %          99.24 %          97.06 %          99.32 %
* (FNR) False Negative Rate or Miss Rate                         4.23 %           5.52 %          53.12 %           4.22 %
* (FPR) False Positive Rate or Fall-Out                         11.73 %           0.95 %           1.49 %           1.25 %
* (FDR) False Discovery Rate                                     5.26 %           6.80 %          36.17 %           7.56 %
* (FOR) False Omission Rate                                      9.56 %           0.76 %           2.94 %           0.68 %
* (F1S) F1 Score                                                95.25 %          93.84 %          54.05 %          94.08 %
*/


#define IMAI_IMU_VALIDATION_AVG_ACC 0.930116472545757 // Accuracy
#define IMAI_IMU_VALIDATION_AVG_F1S 0.9272441959382351 // F1 Score

#define IMAI_IMU_VALIDATION_STATS { \
 {name: "(unlabelled)", TP: 792, FN: 35, FP: 44, TN: 331, TPR: 0.9576783555018, TNR: 0.8826666666666, PPV: 0.9473684210526, NPV: 0.9043715846994, FNR: 0.0423216444981, FPR: 0.1173333333333, FDR: 0.0526315789473, FOR: 0.0956284153005, F1S: 0.9524954900781, }, \
 {name: "circle", TP: 137, FN: 8, FP: 10, TN: 1047, TPR: 0.9448275862068, TNR: 0.9905392620624, PPV: 0.9319727891156, NPV: 0.9924170616113, FNR: 0.0551724137931, FPR: 0.0094607379375, FDR: 0.0680272108843, FOR: 0.0075829383886, F1S: 0.9383561643835, }, \
 {name: "square", TP: 159, FN: 7, FP: 13, TN: 1023, TPR: 0.9578313253012, TNR: 0.9874517374517, PPV: 0.9244186046511, NPV: 0.9932038834951, FNR: 0.0421686746987, FPR: 0.0125482625482, FDR: 0.0755813953488, FOR: 0.0067961165048, F1S: 0.9408284023668, }, \
 {name: "sidetoside", TP: 30, FN: 34, FP: 17, TN: 1121, TPR: 0.46875, TNR: 0.9850615114235, PPV: 0.6382978723404, NPV: 0.9705627705627, FNR: 0.53125, FPR: 0.0149384885764, FDR: 0.3617021276595, FOR: 0.0294372294372, F1S: 0.5405405405405, }, \
}

#ifdef IMAI_IMU_STATS_ENABLED
static const IMAI_IMU_stats IMAI_IMU_validation_stats[] = IMAI_IMU_VALIDATION_STATS;
#endif

#define IMAI_IMU_API_QUEUE

// All symbols in order
#define IMAI_IMU_SYMBOL_MAP {"unlabelled", "circle", "square", "sidetoside"}

// Model GUID (16 bytes)
#define IMAI_IMU_MODEL_ID {0xca, 0xec, 0x01, 0xad, 0xbb, 0x1c, 0xc7, 0x47, 0xaa, 0xfa, 0x77, 0xeb, 0x28, 0xd5, 0xe7, 0xa9}

// First nibble is bit encoding, second nibble is number of bytes
#define IMAGINET_TYPES_NONE	(0x0)
#define IMAGINET_TYPES_FLOAT32	(0x14)
#define IMAGINET_TYPES_FLOAT64	(0x18)
#define IMAGINET_TYPES_INT8	(0x21)
#define IMAGINET_TYPES_INT16	(0x22)
#define IMAGINET_TYPES_INT32	(0x24)
#define IMAGINET_TYPES_INT64	(0x28)
#define IMAGINET_TYPES_QDYN8	(0x31)
#define IMAGINET_TYPES_QDYN16	(0x32)
#define IMAGINET_TYPES_QDYN32	(0x34)

// data_in [3] (12 bytes)
#define IMAI_IMU_DATA_IN_COUNT (3)
#define IMAI_IMU_DATA_IN_TYPE float
#define IMAI_IMU_DATA_IN_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_IMU_DATA_IN_SCALE (1)
#define IMAI_IMU_DATA_IN_OFFSET (0)
#define IMAI_IMU_DATA_IN_IS_QUANTIZED (0)

// data_out [62,3] (744 bytes)
#define IMAI_IMU_DATA_OUT_COUNT (186)
#define IMAI_IMU_DATA_OUT_TYPE float
#define IMAI_IMU_DATA_OUT_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_IMU_DATA_OUT_SCALE (1)
#define IMAI_IMU_DATA_OUT_OFFSET (0)
#define IMAI_IMU_DATA_OUT_IS_QUANTIZED (0)

#define IMAI_IMU_KEY_MAX (3)



// Return codes
#define IMAI_IMU_RET_SUCCESS 0
#define IMAI_IMU_RET_NODATA -1
#define IMAI_IMU_RET_NOMEM -2

// Exported methods


#ifdef __cplusplus


extern "C" {


#endif


#define restrict __restrict__

int IMAI_IMU_dequeue(float *restrict data_out);


int IMAI_IMU_enqueue(const float *restrict data_in);


void IMAI_IMU_init(void);



#ifdef __cplusplus


}


#endif

#endif /* _IMAI_IMU_IMU_MODEL_H_ */
