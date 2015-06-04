/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: watering_controller_AVR.h
 *
 * Code generated for Simulink model 'watering_controller_AVR'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * C/C++ source code generated on : Sun May 24 00:52:40 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_watering_controller_AVR_h_
#define RTW_HEADER_watering_controller_AVR_h_
#include <stddef.h>
#include <string.h>
#ifndef watering_controller_AVR_COMMON_INCLUDES_
# define watering_controller_AVR_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* watering_controller_AVR_COMMON_INCLUDES_ */

#include "watering_controller_AVR_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_watering_controlle;/* '<Root>/Watering_Controller' */
  uint8_T is_c3_watering_controller_AVR;/* '<Root>/Watering_Controller' */
  uint8_T is_automatic_mode;           /* '<Root>/Watering_Controller' */
  uint8_T is_manual_mode;              /* '<Root>/Watering_Controller' */
} DW_watering_controller_AVR_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  uint16_T Dampness;                   /* '<Root>/Dampness' */
  uint16_T Manual_Automatic;           /* '<Root>/Manual_Automatic' */
  uint16_T Manual_On_Off;              /* '<Root>/Manual_On_Off' */
  uint16_T Upper_threshold;            /* '<Root>/Upper_threshold' */
  uint16_T Lower_threshold;            /* '<Root>/Lower_threshold' */
} ExtU_watering_controller_AVR_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  uint16_T ValveRelay;                 /* '<Root>/Valve-Relay' */
} ExtY_watering_controller_AVR_T;

/* Real-time Model Data Structure */
struct tag_RTM_watering_controller_A_T {
  const char_T * volatile errorStatus;
};

/* Block states (auto storage) */
extern DW_watering_controller_AVR_T watering_controller_AVR_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_watering_controller_AVR_T watering_controller_AVR_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_watering_controller_AVR_T watering_controller_AVR_Y;


/* Model entry point functions */
extern void watering_controller_AVR_initialize(void);
extern void watering_controller_AVR_output(void);
extern void watering_controller_AVR_update(void);

/* Real-time Model object */
//extern RT_MODEL_watering_controller__T *const watering_controller_AVR_M;       //*********************here!!!!!!!!!!!!here!!!!!!!!!!!!!!**********************************

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'watering_controller_AVR'
 * '<S1>'   : 'watering_controller_AVR/Watering_Controller'
 */
#endif                                 /* RTW_HEADER_watering_controller_AVR_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
