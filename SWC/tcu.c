/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TCU.c
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

#include "rtwtypes.h"
#include "TCU.h"
#include "Gear_Selection.h"
#include "HydraulicPressureControl.h"

/* System initialize for atomic system: '<Root>/TCU' */
void TCU_Final_TCU_Init(boolean_T *rty_Shift_Solenoid_Park, boolean_T
  *rty_Shift_Solenoid_Reverse, boolean_T *rty_Shift_Solenoid_Neutral, boolean_T *
  rty_Shift_Solenoid_A, boolean_T *rty_Shift_Solenoid_B, boolean_T
  *rty_Shift_Solenoid_C, boolean_T *rty_Shift_Solenoid_D, real_T
  *rty_Torque_Reduction_Request)
{
  /* SystemInitialize for Chart: '<S1>/Gear_Selection' */
  TCU_Final_Gear_Selection_Init(rty_Shift_Solenoid_Park,
    rty_Shift_Solenoid_Reverse, rty_Shift_Solenoid_Neutral, rty_Shift_Solenoid_A,
    rty_Shift_Solenoid_B, rty_Shift_Solenoid_C, rty_Shift_Solenoid_D,
    rty_Torque_Reduction_Request);
}

/* Output and update for atomic system: '<Root>/TCU' */
void TCU_Final_TCU(real_T rtu_Ignition, real_T rtu_Gear_Level_Position, real_T
                   rtu_Engine_RPM, real_T rtu_Vehicle_Speed_Reference, real_T
                   rtu_Throttle_Position_Sensor, boolean_T
                   rtu_Brake_Pedal_Switch, real_T rtu_Driver_Mode_Selection,
                   real_T rtu_Transmission_Fluid_Temp, real_T
                   rtu_Engine_Torque_Actual, real_T rtu_Output_Speed_Sensor,
                   boolean_T *rty_Shift_Solenoid_Park, boolean_T
                   *rty_Shift_Solenoid_Reverse, boolean_T
                   *rty_Shift_Solenoid_Neutral, boolean_T *rty_Shift_Solenoid_A,
                   boolean_T *rty_Shift_Solenoid_B, boolean_T
                   *rty_Shift_Solenoid_C, boolean_T *rty_Shift_Solenoid_D,
                   real_T *rty_Torque_Reduction_Request, real_T
                   *rty_Line_Pressure_Control_Solen, real_T
                   *rty_TCC_Control_Solenoid, DW_TCU_TCU_Final_T *localDW)
{
  /* Chart: '<S1>/Gear_Selection' */
  TCU_Final_Gear_Selection(rtu_Ignition, rtu_Gear_Level_Position, rtu_Engine_RPM,
    rtu_Vehicle_Speed_Reference, rtu_Throttle_Position_Sensor,
    rtu_Brake_Pedal_Switch, rtu_Driver_Mode_Selection, rty_Shift_Solenoid_Park,
    rty_Shift_Solenoid_Reverse, rty_Shift_Solenoid_Neutral, rty_Shift_Solenoid_A,
    rty_Shift_Solenoid_B, rty_Shift_Solenoid_C, rty_Shift_Solenoid_D,
    rty_Torque_Reduction_Request, &localDW->sf_Gear_Selection);

  /* Outputs for Atomic SubSystem: '<S1>/HydraulicPressureControl' */
  TCU_Fi_HydraulicPressureControl(rtu_Transmission_Fluid_Temp,
    rtu_Engine_Torque_Actual, rtu_Driver_Mode_Selection, rtu_Output_Speed_Sensor,
    *rty_Torque_Reduction_Request, rty_Line_Pressure_Control_Solen,
    rty_TCC_Control_Solenoid);

  /* End of Outputs for SubSystem: '<S1>/HydraulicPressureControl' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
