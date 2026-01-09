/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TCU.h
 *
 * Code generated for Simulink model 'TCU_Final'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Mon Dec  1 11:27:07 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef TCU_h_
#define TCU_h_
#ifndef TCU_Final_COMMON_INCLUDES_
#define TCU_Final_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* TCU_Final_COMMON_INCLUDES_ */

#include "Gear_Selection.h"

/* Block states (default storage) for system '<Root>/TCU' */
typedef struct {
  DW_Gear_Selection_TCU_Final_T sf_Gear_Selection;/* '<S1>/Gear_Selection' */
} DW_TCU_TCU_Final_T;

extern void TCU_Final_TCU_Init(boolean_T *rty_Shift_Solenoid_Park, boolean_T
  *rty_Shift_Solenoid_Reverse, boolean_T *rty_Shift_Solenoid_Neutral, boolean_T *
  rty_Shift_Solenoid_A, boolean_T *rty_Shift_Solenoid_B, boolean_T
  *rty_Shift_Solenoid_C, boolean_T *rty_Shift_Solenoid_D, real_T
  *rty_Torque_Reduction_Request);
extern void TCU_Final_TCU(real_T rtu_Ignition, real_T rtu_Gear_Level_Position,
  real_T rtu_Engine_RPM, real_T rtu_Vehicle_Speed_Reference, real_T
  rtu_Throttle_Position_Sensor, boolean_T rtu_Brake_Pedal_Switch, real_T
  rtu_Driver_Mode_Selection, real_T rtu_Transmission_Fluid_Temp, real_T
  rtu_Engine_Torque_Actual, real_T rtu_Output_Speed_Sensor, boolean_T
  *rty_Shift_Solenoid_Park, boolean_T *rty_Shift_Solenoid_Reverse, boolean_T
  *rty_Shift_Solenoid_Neutral, boolean_T *rty_Shift_Solenoid_A, boolean_T
  *rty_Shift_Solenoid_B, boolean_T *rty_Shift_Solenoid_C, boolean_T
  *rty_Shift_Solenoid_D, real_T *rty_Torque_Reduction_Request, real_T
  *rty_Line_Pressure_Control_Solen, real_T *rty_TCC_Control_Solenoid,
  DW_TCU_TCU_Final_T *localDW);

#endif                                 /* TCU_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
