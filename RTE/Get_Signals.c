/*
 * Get_Signals.c
 *
 *  Created on: Nov 24, 2025
 *      Author: joshu
 */

#include "Get_Signals.h"

// ============================================================================
// GET FUNCTIONS (USING POINTER ARGUMENT)
// ============================================================================

// ECU → TCU
void Get_CAN_EngineRPM(uint16 *value) { *value = g_CAN_EngineRPM; }
void Get_CAN_EngineTorqueActual(sint16 *value) { *value = g_CAN_EngineTorqueActual; }
void Get_CAN_EngineCoolantTemp(sint16 *value) { *value = g_CAN_EngineCoolantTemp; }
void Get_CAN_ThrottlePosition(uint8 *value) { *value = g_CAN_ThrottlePosition; }

// ABS → TCU
void Get_CAN_VehicleSpeedRef(uint16 *value) { *value = g_CAN_VehicleSpeedRef; }

// BCM / Switch Panel
void Get_CAN_DriverModeSelection(uint8 *value) { *value = g_CAN_DriverModeSelection; }


// =====================
// DIRECT INPUT SIGNALS
// =====================
void Get_IO_BrakeLightSwitch(uint8 *value) { *value = g_IO_BrakeLightSwitch; }
void Get_IO_Gear_Lever_Position(uint8 *value) { *value = g_IO_Gear_Lever_Position; }


// =====================
// INTERNAL TRANSMISSION SENSORS
// =====================
void Get_TCM_TurbineSpeed_TSS(uint16 *value) { *value = g_TCM_TurbineSpeed_TSS; }
void Get_TCM_OutputSpeed_OSS(uint16 *value) { *value = g_TCM_OutputSpeed_OSS; }
void Get_TCM_FluidTemp_TFT(sint16 *value) { *value = g_TCM_FluidTemp_TFT; }


// ============================================================================
// CAN OUTPUT SIGNALS
// ============================================================================
void Get_CAN_TorqueReductionRequest(uint8 *value) { *value = g_CAN_TorqueReductionRequest; }
void Get_CAN_SelectedGear(uint8 *value) { *value = g_CAN_SelectedGear; }


// ============================================================================
// SOLENOID CONTROL OUTPUTS (PWM / DIGITAL)
// ============================================================================
void Get_PWM_LinePressure(uint16 *value) { *value = g_PWM_LinePressure; }
void Get_PWM_TCC(uint16 *value) { *value = g_PWM_TCC; }

void Get_SOL_ClutchA(uint8 *value) { *value = g_SOL_ClutchA; }
void Get_SOL_ClutchB(uint8 *value) { *value = g_SOL_ClutchB; }
void Get_SOL_ClutchC(uint8 *value) { *value = g_SOL_ClutchC; }
void Get_SOL_ClutchD(uint8 *value) { *value = g_SOL_ClutchD; }
void Get_SOL_ShiftLock(uint8 *value) { *value = g_SOL_ShiftLock; }


// ============================================================================
// INTERNAL LOGIC OUTPUTS
// ============================================================================
void Get_TCM_CurrentGear(uint8 *value) { *value = g_TCM_CurrentGear; }
void Get_TCM_TargetGear(uint8 *value) { *value = g_TCM_TargetGear; }
void Get_TCM_ShiftInProgress(uint8 *value) { *value = g_TCM_ShiftInProgress; }
void Get_TCM_ShiftQualityIndex(uint8 *value) { *value = g_TCM_ShiftQualityIndex; }

