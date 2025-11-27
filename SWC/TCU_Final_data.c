/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TCU_Final_data.c
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

#include "TCU_Final.h"

/* Constant parameters (default storage) */
const ConstP_TCU_Final_T TCU_Final_ConstP = {
  /* Expression: [ 0.2  0.2 0.1 0.0 0.0 0.0 0.1 0.2 ]
   * Referenced by: '<S5>/Ajuste_Temp'
   */
  { 0.2, 0.2, 0.1, 0.0, 0.0, 0.0, 0.1, 0.2 },

  /* Pooled Parameter (Expression: [ -20    0   20   40   60   80  100  120 ])
   * Referenced by:
   *   '<S4>/Ajuste_Temperature'
   *   '<S5>/Ajuste_Temp'
   */
  { -20.0, 0.0, 20.0, 40.0, 60.0, 80.0, 100.0, 120.0 },

  /* Expression: [
     0.4   0.5   0.6 ;
     0.6   0.7   0.8 ;
     0.8   0.9   1.0 ;
     1.0   1.1   1.2 ;
     1.2   1.3   1.4 ;
     1.4   1.5   1.6 ;
     1.6   1.7   1.8 ;
     1.8   1.9   2.0 ]
   * Referenced by: '<S5>/Raw_Pressure'
   */
  { 0.4, 0.6, 0.8, 1.0, 1.2, 1.4, 1.6, 1.8, 0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.7,
    1.9, 0.6, 0.8, 1.0, 1.2, 1.4, 1.6, 1.8, 2.0 },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S4>/Pressure_Raw'
   *   '<S5>/Raw_Pressure'
   */
  { 0.0, 50.0, 100.0, 150.0, 200.0, 250.0, 300.0, 350.0 },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S4>/Ajuste_Drive_Mode'
   *   '<S5>/OSS_lock_min_rpm_by_mode'
   *   '<S5>/Raw_Pressure'
   *   '<S5>/Tq_lock_max_Nm_by_mode'
   */
  { 0.0, 1.0, 2.0 },

  /* Expression: [ 4.0 5.5  7.0  8.5 10.0 12.0 14.0 16.0 ]
   * Referenced by: '<S4>/Pressure_Raw'
   */
  { 4.0, 5.5, 7.0, 8.5, 10.0, 12.0, 14.0, 16.0 },

  /* Expression: [ -2.0  0.0  2.0 ]
   * Referenced by: '<S4>/Ajuste_Drive_Mode'
   */
  { -2.0, 0.0, 2.0 },

  /* Expression: [  3.0  2.0 1.5  0.5  0.0  0.0 0.5  1.0 ]
   * Referenced by: '<S4>/Ajuste_Temperature'
   */
  { 3.0, 2.0, 1.5, 0.5, 0.0, 0.0, 0.5, 1.0 },

  /* Expression: [0.0  0.0  0.2  0.5  0.8  1.0  1.2 ]
   * Referenced by: '<S4>/Ajuste_OSS'
   */
  { 0.0, 0.0, 0.2, 0.5, 0.8, 1.0, 1.2 },

  /* Expression: [    0   300   800  1500  2500  3500  4500 ]
   * Referenced by: '<S4>/Ajuste_OSS'
   */
  { 0.0, 300.0, 800.0, 1500.0, 2500.0, 3500.0, 4500.0 },

  /* Expression: [ 1000  900  800 ]
   * Referenced by: '<S5>/OSS_lock_min_rpm_by_mode'
   */
  { 1000.0, 900.0, 800.0 },

  /* Expression: [ 180  220  260 ]
   * Referenced by: '<S5>/Tq_lock_max_Nm_by_mode'
   */
  { 180.0, 220.0, 260.0 },

  /* Computed Parameter: Raw_Pressure_maxIndex
   * Referenced by: '<S5>/Raw_Pressure'
   */
  { 7U, 2U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
