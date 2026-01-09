/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TCU_Final.c
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

#include "TCU_Final.h"
#include "TCU.h"
#include "TCU_Final_private.h"

/* Block states (default storage) */
DW_TCU_Final_T TCU_Final_DW;

/* External inputs (root inport signals with default storage) */
ExtU_TCU_Final_T TCU_Final_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_TCU_Final_T TCU_Final_Y;

/* Real-time model */
static RT_MODEL_TCU_Final_T TCU_Final_M_;
RT_MODEL_TCU_Final_T *const TCU_Final_M = &TCU_Final_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

real_T look2_binlxpw(real_T u0, real_T u1, const real_T bp0[], const real_T bp1[],
                     const real_T table[], const uint32_T maxIndex[], uint32_T
                     stride)
{
  real_T fractions[2];
  real_T frac;
  real_T yL_0d0;
  real_T yL_0d1;
  uint32_T bpIndices[2];
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = (u0 - bp0[maxIndex[0U] - 1U]) / (bp0[maxIndex[0U]] - bp0[maxIndex[0U]
      - 1U]);
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = (u1 - bp1[0U]) / (bp1[1U] - bp1[0U]);
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = (u1 - bp1[maxIndex[1U] - 1U]) / (bp1[maxIndex[1U]] - bp1[maxIndex[1U]
      - 1U]);
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  yL_0d0 = table[bpIdx];
  yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
  bpIdx += stride;
  yL_0d1 = table[bpIdx];
  return (((table[bpIdx + 1U] - yL_0d1) * fractions[0U] + yL_0d1) - yL_0d0) *
    frac + yL_0d0;
}

/* Model step function */
void TCU_Final_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/TCU' */

  /* Inport: '<Root>/Ignition' incorporates:
   *  Inport: '<Root>/Brake_Pedal_Switch'
   *  Inport: '<Root>/Driver_Mode_Selection'
   *  Inport: '<Root>/Engine_RPM'
   *  Inport: '<Root>/Engine_Torque_Actual'
   *  Inport: '<Root>/Gear_Level_Position'
   *  Inport: '<Root>/Output_Speed_Sensor'
   *  Inport: '<Root>/Throttle_Position_Sensor'
   *  Inport: '<Root>/Transmission_Fluid_Temp'
   *  Inport: '<Root>/Vehicle_Speed_Reference'
   *  Outport: '<Root>/Line_Pressure_Control_Solenoid'
   *  Outport: '<Root>/Shift_Solenoid_A'
   *  Outport: '<Root>/Shift_Solenoid_B'
   *  Outport: '<Root>/Shift_Solenoid_C'
   *  Outport: '<Root>/Shift_Solenoid_D'
   *  Outport: '<Root>/Shift_Solenoid_Neutral'
   *  Outport: '<Root>/Shift_Solenoid_Park'
   *  Outport: '<Root>/Shift_Solenoid_Reverse'
   *  Outport: '<Root>/TCC_Control_Solenoid'
   *  Outport: '<Root>/Torque_Reduction_Request'
   */
  TCU_Final_TCU(TCU_Final_U.Ignition, TCU_Final_U.Gear_Level_Position,
                TCU_Final_U.Engine_RPM, TCU_Final_U.Vehicle_Speed_Reference,
                TCU_Final_U.Throttle_Position_Sensor,
                TCU_Final_U.Brake_Pedal_Switch,
                TCU_Final_U.Driver_Mode_Selection,
                TCU_Final_U.Transmission_Fluid_Temp,
                TCU_Final_U.Engine_Torque_Actual,
                TCU_Final_U.Output_Speed_Sensor,
                &TCU_Final_Y.Shift_Solenoid_Park,
                &TCU_Final_Y.Shift_Solenoid_Reverse,
                &TCU_Final_Y.Shift_Solenoid_Neutral,
                &TCU_Final_Y.Shift_Solenoid_A, &TCU_Final_Y.Shift_Solenoid_B,
                &TCU_Final_Y.Shift_Solenoid_C, &TCU_Final_Y.Shift_Solenoid_D,
                &TCU_Final_Y.Torque_Reduction_Request,
                &TCU_Final_Y.Line_Pressure_Control_Solenoid,
                &TCU_Final_Y.TCC_Control_Solenoid, &TCU_Final_DW.TCU);

  /* End of Outputs for SubSystem: '<Root>/TCU' */
}

/* Model initialize function */
void TCU_Final_initialize(void)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/TCU' */

  /* SystemInitialize for Outport: '<Root>/Shift_Solenoid_Park' incorporates:
   *  Outport: '<Root>/Shift_Solenoid_A'
   *  Outport: '<Root>/Shift_Solenoid_B'
   *  Outport: '<Root>/Shift_Solenoid_C'
   *  Outport: '<Root>/Shift_Solenoid_D'
   *  Outport: '<Root>/Shift_Solenoid_Neutral'
   *  Outport: '<Root>/Shift_Solenoid_Reverse'
   *  Outport: '<Root>/Torque_Reduction_Request'
   */
  TCU_Final_TCU_Init(&TCU_Final_Y.Shift_Solenoid_Park,
                     &TCU_Final_Y.Shift_Solenoid_Reverse,
                     &TCU_Final_Y.Shift_Solenoid_Neutral,
                     &TCU_Final_Y.Shift_Solenoid_A,
                     &TCU_Final_Y.Shift_Solenoid_B,
                     &TCU_Final_Y.Shift_Solenoid_C,
                     &TCU_Final_Y.Shift_Solenoid_D,
                     &TCU_Final_Y.Torque_Reduction_Request);

  /* End of SystemInitialize for SubSystem: '<Root>/TCU' */
}

/* Model terminate function */
void TCU_Final_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
