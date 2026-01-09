/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: TCU_Final.h
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

#ifndef TCU_Final_h_
#define TCU_Final_h_
#ifndef TCU_Final_COMMON_INCLUDES_
#define TCU_Final_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* TCU_Final_COMMON_INCLUDES_ */

#include "TCU_Final_types.h"
#include "TCU.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  DW_TCU_TCU_Final_T TCU;              /* '<Root>/TCU' */
} DW_TCU_Final_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: [ 0.2  0.2 0.1 0.0 0.0 0.0 0.1 0.2 ]
   * Referenced by: '<S5>/Ajuste_Temp'
   */
  real_T Ajuste_Temp_tableData[8];

  /* Pooled Parameter (Expression: [ -20    0   20   40   60   80  100  120 ])
   * Referenced by:
   *   '<S4>/Ajuste_Temperature'
   *   '<S5>/Ajuste_Temp'
   */
  real_T pooled1[8];

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
  real_T Raw_Pressure_tableData[24];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S4>/Pressure_Raw'
   *   '<S5>/Raw_Pressure'
   */
  real_T pooled2[8];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S4>/Ajuste_Drive_Mode'
   *   '<S5>/OSS_lock_min_rpm_by_mode'
   *   '<S5>/Raw_Pressure'
   *   '<S5>/Tq_lock_max_Nm_by_mode'
   */
  real_T pooled3[3];

  /* Expression: [ 4.0 5.5  7.0  8.5 10.0 12.0 14.0 16.0 ]
   * Referenced by: '<S4>/Pressure_Raw'
   */
  real_T Pressure_Raw_tableData[8];

  /* Expression: [ -2.0  0.0  2.0 ]
   * Referenced by: '<S4>/Ajuste_Drive_Mode'
   */
  real_T Ajuste_Drive_Mode_tableData[3];

  /* Expression: [  3.0  2.0 1.5  0.5  0.0  0.0 0.5  1.0 ]
   * Referenced by: '<S4>/Ajuste_Temperature'
   */
  real_T Ajuste_Temperature_tableData[8];

  /* Expression: [0.0  0.0  0.2  0.5  0.8  1.0  1.2 ]
   * Referenced by: '<S4>/Ajuste_OSS'
   */
  real_T Ajuste_OSS_tableData[7];

  /* Expression: [    0   300   800  1500  2500  3500  4500 ]
   * Referenced by: '<S4>/Ajuste_OSS'
   */
  real_T Ajuste_OSS_bp01Data[7];

  /* Expression: [ 1000  900  800 ]
   * Referenced by: '<S5>/OSS_lock_min_rpm_by_mode'
   */
  real_T OSS_lock_min_rpm_by_mode_tableD[3];

  /* Expression: [ 180  220  260 ]
   * Referenced by: '<S5>/Tq_lock_max_Nm_by_mode'
   */
  real_T Tq_lock_max_Nm_by_mode_tableDat[3];

  /* Computed Parameter: Raw_Pressure_maxIndex
   * Referenced by: '<S5>/Raw_Pressure'
   */
  uint32_T Raw_Pressure_maxIndex[2];
} ConstP_TCU_Final_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Ignition;                     /* '<Root>/Ignition' */
  real_T Gear_Level_Position;          /* '<Root>/Gear_Level_Position' */
  real_T Engine_RPM;                   /* '<Root>/Engine_RPM' */
  real_T Vehicle_Speed_Reference;      /* '<Root>/Vehicle_Speed_Reference' */
  real_T Throttle_Position_Sensor;     /* '<Root>/Throttle_Position_Sensor' */
  boolean_T Brake_Pedal_Switch;        /* '<Root>/Brake_Pedal_Switch' */
  real_T Driver_Mode_Selection;        /* '<Root>/Driver_Mode_Selection' */
  real_T Transmission_Fluid_Temp;      /* '<Root>/Transmission_Fluid_Temp' */
  real_T Engine_Torque_Actual;         /* '<Root>/Engine_Torque_Actual' */
  real_T Output_Speed_Sensor;          /* '<Root>/Output_Speed_Sensor' */
} ExtU_TCU_Final_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T Shift_Solenoid_Park;       /* '<Root>/Shift_Solenoid_Park' */
  boolean_T Shift_Solenoid_Reverse;    /* '<Root>/Shift_Solenoid_Reverse' */
  boolean_T Shift_Solenoid_Neutral;    /* '<Root>/Shift_Solenoid_Neutral' */
  boolean_T Shift_Solenoid_A;          /* '<Root>/Shift_Solenoid_A' */
  boolean_T Shift_Solenoid_B;          /* '<Root>/Shift_Solenoid_B' */
  boolean_T Shift_Solenoid_C;          /* '<Root>/Shift_Solenoid_C' */
  boolean_T Shift_Solenoid_D;          /* '<Root>/Shift_Solenoid_D' */
  real_T Torque_Reduction_Request;     /* '<Root>/Torque_Reduction_Request' */
  real_T Line_Pressure_Control_Solenoid;
                                   /* '<Root>/Line_Pressure_Control_Solenoid' */
  real_T TCC_Control_Solenoid;         /* '<Root>/TCC_Control_Solenoid' */
} ExtY_TCU_Final_T;

/* Real-time Model Data Structure */
struct tag_RTM_TCU_Final_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_TCU_Final_T TCU_Final_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_TCU_Final_T TCU_Final_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_TCU_Final_T TCU_Final_Y;

/* Constant parameters (default storage) */
extern const ConstP_TCU_Final_T TCU_Final_ConstP;

/* Model entry point functions */
extern void TCU_Final_initialize(void);
extern void TCU_Final_step(void);
extern void TCU_Final_terminate(void);

/* Real-time Model object */
extern RT_MODEL_TCU_Final_T *const TCU_Final_M;

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
 * '<Root>' : 'TCU_Final'
 * '<S1>'   : 'TCU_Final/TCU'
 * '<S2>'   : 'TCU_Final/TCU/Gear_Selection'
 * '<S3>'   : 'TCU_Final/TCU/HydraulicPressureControl'
 * '<S4>'   : 'TCU_Final/TCU/HydraulicPressureControl/Desired_Line_Pressure'
 * '<S5>'   : 'TCU_Final/TCU/HydraulicPressureControl/Desired_TCC_Pressure'
 * '<S6>'   : 'TCU_Final/TCU/HydraulicPressureControl/PressureToPWM'
 */
#endif                                 /* TCU_Final_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
