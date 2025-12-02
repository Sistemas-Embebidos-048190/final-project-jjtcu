/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TCU_Final_private.h
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

#ifndef TCU_Final_private_h_
#define TCU_Final_private_h_
#include "rtwtypes.h"
#include "TCU_Final_types.h"
#include "TCU_Final.h"

extern real_T rt_roundd_snf(real_T u);
extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern real_T look2_binlxpw(real_T u0, real_T u1, const real_T bp0[], const
  real_T bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T stride);

#endif                                 /* TCU_Final_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
