/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: HydraulicPressureControl.c
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
#include "HydraulicPressureControl.h"
#include "TCU_Final.h"
#include "TCU_Final_private.h"

/* Output and update for atomic system: '<S1>/HydraulicPressureControl' */
void TCU_Fi_HydraulicPressureControl(real_T rtu_Transmission_Fluid_Temp, real_T
  rtu_Engine_Torque_Actual, real_T rtu_Driver_Mode_Selection, real_T
  rtu_Output_Speed_Sensor, real_T rtu_Torque_Reduction_Request, real_T
  *rty_Line_Pressure_Control_Solen, real_T *rty_TCC_Control_Solenoid)
{
  boolean_T rtb_RelationalOperator;

  /* Lookup_n-D: '<S4>/Pressure_Raw' */
  *rty_Line_Pressure_Control_Solen = look1_binlxpw(rtu_Engine_Torque_Actual,
    TCU_Final_ConstP.pooled2, TCU_Final_ConstP.Pressure_Raw_tableData, 7U);

  /* Lookup_n-D: '<S4>/Ajuste_OSS' */
  *rty_TCC_Control_Solenoid = look1_binlxpw(rtu_Output_Speed_Sensor,
    TCU_Final_ConstP.Ajuste_OSS_bp01Data, TCU_Final_ConstP.Ajuste_OSS_tableData,
    6U);

  /* Sum: '<S4>/Add' incorporates:
   *  Gain: '<S4>/Gain'
   *  Lookup_n-D: '<S4>/Ajuste_Drive_Mode'
   *  Lookup_n-D: '<S4>/Ajuste_Temperature'
   */
  *rty_Line_Pressure_Control_Solen = (((*rty_Line_Pressure_Control_Solen +
    look1_binlxpw(rtu_Driver_Mode_Selection, TCU_Final_ConstP.pooled3,
                  TCU_Final_ConstP.Ajuste_Drive_Mode_tableData, 2U)) +
    look1_binlxpw(rtu_Transmission_Fluid_Temp, TCU_Final_ConstP.pooled1,
                  TCU_Final_ConstP.Ajuste_Temperature_tableData, 7U)) +
    *rty_TCC_Control_Solenoid) + 2.0 * rtu_Torque_Reduction_Request;

  /* Saturate: '<S4>/Saturation' */
  if (*rty_Line_Pressure_Control_Solen > 18.0) {
    *rty_Line_Pressure_Control_Solen = 18.0;
  } else if (*rty_Line_Pressure_Control_Solen < 4.0) {
    *rty_Line_Pressure_Control_Solen = 4.0;
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* Gain: '<S6>/Gain' */
  *rty_Line_Pressure_Control_Solen *= 5.0;

  /* Saturate: '<S6>/Saturation' */
  if (*rty_Line_Pressure_Control_Solen > 100.0) {
    *rty_Line_Pressure_Control_Solen = 100.0;
  } else if (*rty_Line_Pressure_Control_Solen < 0.0) {
    *rty_Line_Pressure_Control_Solen = 0.0;
  }

  /* End of Saturate: '<S6>/Saturation' */

  /* Lookup_n-D: '<S5>/OSS_lock_min_rpm_by_mode' */
  *rty_TCC_Control_Solenoid = look1_binlxpw(rtu_Driver_Mode_Selection,
    TCU_Final_ConstP.pooled3, TCU_Final_ConstP.OSS_lock_min_rpm_by_mode_tableD,
    2U);

  /* RelationalOperator: '<S5>/Relational Operator' */
  rtb_RelationalOperator = (rtu_Output_Speed_Sensor > *rty_TCC_Control_Solenoid);

  /* Lookup_n-D: '<S5>/Tq_lock_max_Nm_by_mode' */
  *rty_TCC_Control_Solenoid = look1_binlxpw(rtu_Driver_Mode_Selection,
    TCU_Final_ConstP.pooled3, TCU_Final_ConstP.Tq_lock_max_Nm_by_mode_tableDat,
    2U);

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Offset_Lock'
   *  Constant: '<S5>/Release_TCC'
   *  Logic: '<S5>/Logical Operator'
   *  Logic: '<S5>/Logical Operator1'
   *  Logic: '<S5>/Logical Operator2'
   *  Lookup_n-D: '<S5>/Ajuste_Temp'
   *  Lookup_n-D: '<S5>/Raw_Pressure'
   *  RelationalOperator: '<S5>/Relational Operator1'
   *  Sum: '<S5>/Add'
   */
  if (rtb_RelationalOperator && (rtu_Engine_Torque_Actual <
       *rty_TCC_Control_Solenoid) && (!(rtu_Torque_Reduction_Request != 0.0))) {
    *rty_TCC_Control_Solenoid = (look2_binlxpw(rtu_Engine_Torque_Actual,
      rtu_Driver_Mode_Selection, TCU_Final_ConstP.pooled2,
      TCU_Final_ConstP.pooled3, TCU_Final_ConstP.Raw_Pressure_tableData,
      TCU_Final_ConstP.Raw_Pressure_maxIndex, 8U) + look1_binlxpw
      (rtu_Transmission_Fluid_Temp, TCU_Final_ConstP.pooled1,
       TCU_Final_ConstP.Ajuste_Temp_tableData, 7U)) + 0.5;
  } else {
    *rty_TCC_Control_Solenoid = 0.2;
  }

  /* End of Switch: '<S5>/Switch' */

  /* Saturate: '<S5>/Saturation' */
  if (*rty_TCC_Control_Solenoid > 8.0) {
    *rty_TCC_Control_Solenoid = 8.0;
  } else if (*rty_TCC_Control_Solenoid < 0.0) {
    *rty_TCC_Control_Solenoid = 0.0;
  }

  /* End of Saturate: '<S5>/Saturation' */

  /* Gain: '<S6>/Gain1' */
  *rty_TCC_Control_Solenoid *= 11.25;

  /* Saturate: '<S6>/Saturation1' */
  if (*rty_TCC_Control_Solenoid > 100.0) {
    *rty_TCC_Control_Solenoid = 100.0;
  } else if (*rty_TCC_Control_Solenoid < 0.0) {
    *rty_TCC_Control_Solenoid = 0.0;
  }

  /* End of Saturate: '<S6>/Saturation1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
