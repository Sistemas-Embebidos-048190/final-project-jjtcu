/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: HydraulicPressureControl.h
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

#ifndef HydraulicPressureControl_h_
#define HydraulicPressureControl_h_
#ifndef TCU_Final_COMMON_INCLUDES_
#define TCU_Final_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* TCU_Final_COMMON_INCLUDES_ */

extern void TCU_Fi_HydraulicPressureControl(real_T rtu_Transmission_Fluid_Temp,
  real_T rtu_Engine_Torque_Actual, real_T rtu_Driver_Mode_Selection, real_T
  rtu_Output_Speed_Sensor, real_T rtu_Torque_Reduction_Request, real_T
  *rty_Line_Pressure_Control_Solen, real_T *rty_TCC_Control_Solenoid);

#endif                                 /* HydraulicPressureControl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
