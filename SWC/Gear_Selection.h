/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Gear_Selection.h
 *
 * Code generated for Simulink model 'TCU_Final'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Wed Nov 26 16:44:55 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Gear_Selection_h_
#define Gear_Selection_h_
#ifndef TCU_Final_COMMON_INCLUDES_
#define TCU_Final_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* TCU_Final_COMMON_INCLUDES_ */

/* Block states (default storage) for system '<S1>/Gear_Selection' */
typedef struct {
  real_T D;                            /* '<S1>/Gear_Selection' */
  real_T Current_Gear_State;           /* '<S1>/Gear_Selection' */
  real_T styleState;                   /* '<S1>/Gear_Selection' */
  real_T prevSpeed;                    /* '<S1>/Gear_Selection' */
  uint8_T is_active_c1_TCU_GS;         /* '<S1>/Gear_Selection' */
  uint8_T is_c1_TCU_GS;                /* '<S1>/Gear_Selection' */
  uint8_T is_Gear_Selection;           /* '<S1>/Gear_Selection' */
  uint8_T is_Selection;                /* '<S1>/Gear_Selection' */
  uint8_T temporalCounter_i1;          /* '<S1>/Gear_Selection' */
  boolean_T initialized_not_empty;     /* '<S1>/Gear_Selection' */
} DW_Gear_Selection_TCU_Final_T;

extern void TCU_Final_Gear_Selection_Init(boolean_T *rty_Shift_Solenoid_Park,
  boolean_T *rty_Shift_Solenoid_Reverse, boolean_T *rty_Shift_Solenoid_Neutral,
  boolean_T *rty_Shift_Solenoid_A, boolean_T *rty_Shift_Solenoid_B, boolean_T
  *rty_Shift_Solenoid_C, boolean_T *rty_Shift_Solenoid_D, real_T
  *rty_Torque_Reduction_Request);
extern void TCU_Final_Gear_Selection(real_T rtu_Ignition, real_T
  rtu_Gear_Lever_Position, real_T rtu_Engine_RPM, real_T
  rtu_Vehicle_Speed_Reference, real_T rtu_Throttle_Position_Sensor, boolean_T
  rtu_Brake_Pedal_Switch, real_T rtu_Driver_Mode_Selection, boolean_T
  *rty_Shift_Solenoid_Park, boolean_T *rty_Shift_Solenoid_Reverse, boolean_T
  *rty_Shift_Solenoid_Neutral, boolean_T *rty_Shift_Solenoid_A, boolean_T
  *rty_Shift_Solenoid_B, boolean_T *rty_Shift_Solenoid_C, boolean_T
  *rty_Shift_Solenoid_D, real_T *rty_Torque_Reduction_Request,
  DW_Gear_Selection_TCU_Final_T *localDW);

#endif                                 /* Gear_Selection_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
