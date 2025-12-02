/*
 * Get_Signals.h
 *
 *  Created on: Nov 24, 2025
 *      Author: joshu
 */

#ifndef GET_SIGNALS_H_
#define GET_SIGNALS_H_

#include "Platform_Types.h"
#include "Global_Signals.h"

// ============================================================================
// GET FUNCTION PROTOTYPES (USING POINTER ARGUMENT)
// ============================================================================

// ECU → TCU
void Get_CAN_EngineRPM(uint32 *value);
void Get_CAN_EngineTorqueActual(sint32 *value);
void Get_CAN_EngineCoolantTemp(sint32 *value);
void Get_CAN_ThrottlePosition(uint32 *value);

// ABS → TCU
void Get_CAN_VehicleSpeedRef(uint32 *value);

// BCM / Switch Panel
void Get_CAN_DriverModeSelection(uint32 *value);


// =====================
// DIRECT INPUT SIGNALS
// =====================
void Get_IO_BrakeLightSwitch(uint32 *value);
void Get_IO_Gear_Lever_Position(uint32 *value);


// =====================
// INTERNAL TRANSMISSION SENSORS
// =====================
void Get_TCM_TurbineSpeed_TSS(uint32 *value);
void Get_TCM_OutputSpeed_OSS(uint32 *value);
void Get_TCM_FluidTemp_TFT(sint32 *value);


// ============================================================================
// CAN OUTPUT SIGNALS
// ============================================================================
void Get_CAN_TorqueReductionRequest(uint32 *value);
void Get_CAN_SelectedGear(uint32 *value);


// ============================================================================
// SOLENOID CONTROL OUTPUTS (PWM / DIGITAL)
// ============================================================================
void Get_PWM_LinePressure(float *value);
void Get_PWM_TCC(float *value);

void Get_SOL_ClutchParking(uint32 *value);
void Get_SOL_ClutchReverse(uint32 *value);
void Get_SOL_ClutchNeutral(uint32 *value);

void Get_SOL_ClutchA(uint32 *value);
void Get_SOL_ClutchB(uint32 *value);
void Get_SOL_ClutchC(uint32 *value);
void Get_SOL_ClutchD(uint32 *value);
void Get_SOL_ShiftLock(uint32 *value);


// ============================================================================
// INTERNAL LOGIC OUTPUTS
// ============================================================================
void Get_TCM_CurrentGear(uint32 *value);
void Get_TCM_TargetGear(uint32 *value);
void Get_TCM_ShiftInProgress(uint32 *value);
void Get_TCM_ShiftQualityIndex(uint32 *value);


#endif /* GET_SIGNALS_H_ */
