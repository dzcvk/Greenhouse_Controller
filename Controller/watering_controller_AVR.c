/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: watering_controller_AVR.c
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

#include "watering_controller_AVR.h"
#include "watering_controller_AVR_private.h"

/* Named constants for Chart: '<Root>/Watering_Controller' */
#define watering_con_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define watering_cont_IN_automatic_mode ((uint8_T)1U)
#define watering_control_IN_manual_mode ((uint8_T)2U)
#define watering_controller_AVR_IN_off ((uint8_T)1U)
#define watering_controller_AVR_IN_on  ((uint8_T)2U)

/* Block states (auto storage) */
DW_watering_controller_AVR_T watering_controller_AVR_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_watering_controller_AVR_T watering_controller_AVR_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_watering_controller_AVR_T watering_controller_AVR_Y;

/* Real-time model */
RT_MODEL_watering_controller__T watering_controller_AVR_M_;
RT_MODEL_watering_controller__T *const watering_controller_AVR_M =
  &watering_controller_AVR_M_;

/* Model output function */
void watering_controller_AVR_output(void)
{
  /* Chart: '<Root>/Watering_Controller' incorporates:
   *  Inport: '<Root>/Dampness'
   *  Inport: '<Root>/Lower_threshold'
   *  Inport: '<Root>/Manual_Automatic'
   *  Inport: '<Root>/Manual_On_Off'
   *  Inport: '<Root>/Upper_threshold'
   */
  /* Gateway: Watering_Controller */
  /* During: Watering_Controller */
  if (watering_controller_AVR_DW.is_active_c3_watering_controlle == 0U) {
    /* Entry: Watering_Controller */
    watering_controller_AVR_DW.is_active_c3_watering_controlle = 1U;

    /* Entry Internal: Watering_Controller */
    /* Transition: '<S1>:15' */
    watering_controller_AVR_DW.is_c3_watering_controller_AVR =
      watering_control_IN_manual_mode;

    /* Entry Internal 'manual_mode': '<S1>:1' */
    /* Transition: '<S1>:7' */
    watering_controller_AVR_DW.is_manual_mode = watering_controller_AVR_IN_off;

    /* Outport: '<Root>/Valve-Relay' */
    /* Entry 'off': '<S1>:4' */
    watering_controller_AVR_Y.ValveRelay = 0U;

    /* updateYun */
  } else if (watering_controller_AVR_DW.is_c3_watering_controller_AVR ==
             watering_cont_IN_automatic_mode) {
    /* During 'automatic_mode': '<S1>:2' */
    if (watering_controller_AVR_U.Manual_Automatic == 0U) {
      /* Transition: '<S1>:23' */
      /* Exit Internal 'automatic_mode': '<S1>:2' */
      watering_controller_AVR_DW.is_automatic_mode =
        watering_con_IN_NO_ACTIVE_CHILD;
      watering_controller_AVR_DW.is_c3_watering_controller_AVR =
        watering_control_IN_manual_mode;

      /* Entry Internal 'manual_mode': '<S1>:1' */
      /* Transition: '<S1>:7' */
      watering_controller_AVR_DW.is_manual_mode = watering_controller_AVR_IN_off;

      /* Outport: '<Root>/Valve-Relay' */
      /* Entry 'off': '<S1>:4' */
      watering_controller_AVR_Y.ValveRelay = 0U;

      /* updateYun */
    } else if (watering_controller_AVR_DW.is_automatic_mode ==
               watering_controller_AVR_IN_off) {
      /* During 'off': '<S1>:6' */
      if (watering_controller_AVR_U.Dampness <
          watering_controller_AVR_U.Lower_threshold) {
        /* Transition: '<S1>:28' */
        watering_controller_AVR_DW.is_automatic_mode =
          watering_controller_AVR_IN_on;

        /* Outport: '<Root>/Valve-Relay' */
        /* Entry 'on': '<S1>:5' */
        watering_controller_AVR_Y.ValveRelay = 1U;

        /* updateYun */
      }
    } else {
      /* During 'on': '<S1>:5' */
      if (watering_controller_AVR_U.Dampness >
          watering_controller_AVR_U.Upper_threshold) {
        /* Transition: '<S1>:29' */
        watering_controller_AVR_DW.is_automatic_mode =
          watering_controller_AVR_IN_off;

        /* Outport: '<Root>/Valve-Relay' */
        /* Entry 'off': '<S1>:6' */
        watering_controller_AVR_Y.ValveRelay = 0U;

        /* updateYun */
      }
    }
  } else {
    /* During 'manual_mode': '<S1>:1' */
    if (watering_controller_AVR_U.Manual_Automatic == 1U) {
      /* Transition: '<S1>:22' */
      /* Exit Internal 'manual_mode': '<S1>:1' */
      watering_controller_AVR_DW.is_manual_mode =
        watering_con_IN_NO_ACTIVE_CHILD;
      watering_controller_AVR_DW.is_c3_watering_controller_AVR =
        watering_cont_IN_automatic_mode;

      /* Entry Internal 'automatic_mode': '<S1>:2' */
      /* Transition: '<S1>:8' */
      watering_controller_AVR_DW.is_automatic_mode =
        watering_controller_AVR_IN_off;

      /* Outport: '<Root>/Valve-Relay' */
      /* Entry 'off': '<S1>:6' */
      watering_controller_AVR_Y.ValveRelay = 0U;

      /* updateYun */
    } else if (watering_controller_AVR_DW.is_manual_mode ==
               watering_controller_AVR_IN_off) {
      /* During 'off': '<S1>:4' */
      if (watering_controller_AVR_U.Manual_On_Off == 1U) {
        /* Transition: '<S1>:26' */
        watering_controller_AVR_DW.is_manual_mode =
          watering_controller_AVR_IN_on;

        /* Outport: '<Root>/Valve-Relay' */
        /* Entry 'on': '<S1>:3' */
        watering_controller_AVR_Y.ValveRelay = 1U;

        /* updateYun */
      }
    } else {
      /* During 'on': '<S1>:3' */
      if (watering_controller_AVR_U.Manual_On_Off == 0U) {
        /* Transition: '<S1>:27' */
        watering_controller_AVR_DW.is_manual_mode =
          watering_controller_AVR_IN_off;

        /* Outport: '<Root>/Valve-Relay' */
        /* Entry 'off': '<S1>:4' */
        watering_controller_AVR_Y.ValveRelay = 0U;

        /* updateYun */
      }
    }
  }

  /* End of Chart: '<Root>/Watering_Controller' */
}

/* Model update function */
void watering_controller_AVR_update(void)
{
  /* (no update code required) */

}

/* Model initialize function */
void watering_controller_AVR_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(watering_controller_AVR_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&watering_controller_AVR_DW, 0,
                sizeof(DW_watering_controller_AVR_T));

  /* external inputs */
  (void) memset((void *)&watering_controller_AVR_U, 0,
                sizeof(ExtU_watering_controller_AVR_T));

  /* external outputs */
  watering_controller_AVR_Y.ValveRelay = 0U;

  /* InitializeConditions for Chart: '<Root>/Watering_Controller' */
  watering_controller_AVR_DW.is_automatic_mode = watering_con_IN_NO_ACTIVE_CHILD;
  watering_controller_AVR_DW.is_manual_mode = watering_con_IN_NO_ACTIVE_CHILD;
  watering_controller_AVR_DW.is_active_c3_watering_controlle = 0U;
  watering_controller_AVR_DW.is_c3_watering_controller_AVR =
    watering_con_IN_NO_ACTIVE_CHILD;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
