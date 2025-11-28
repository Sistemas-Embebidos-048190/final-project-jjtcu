/*
 * Set_Signals.h
 *
 *  Created on: Nov 24, 2025
 *      Author: joshu
 */

#ifndef SET_SIGNALS_H_
#define SET_SIGNALS_H_

#include "Platform_Types.h"
#include "Global_Signals.h"

// ECU → TCU
void Set_CAN_EngineRPM(uint32 value);
void Set_CAN_EngineTorqueActual(sint32 value);
void Set_CAN_EngineCoolantTemp(sint32 value);
void Set_CAN_ThrottlePosition(uint32 value);

// ABS → TCU
void Set_CAN_VehicleSpeedRef(uint32 value);

// BCM / Switch Panel
void Set_CAN_DriverModeSelection(uint32 value);


// =====================
// DIRECT INPUT SIGNALS
// =====================
void Set_IO_BrakeLightSwitch(uint32 value);
void Set_IO_Gear_Lever_Position(uint32 value);


// =====================
// INTERNAL TRANSMISSION SENSORS
// =====================
void Set_TCM_TurbineSpeed_TSS(uint32 value);
void Set_TCM_OutputSpeed_OSS(uint32 value);
void Set_TCM_FluidTemp_TFT(sint32 value);


// ============================================================================
// CAN OUTPUT SIGNALS
// ============================================================================
void Set_CAN_TorqueReductionRequest(uint32 value);
void Set_CAN_SelectedGear(uint32 value);


// ============================================================================
// SOLENOID CONTROL OUTPUTS (PWM / DIGITAL)
// ============================================================================
void Set_PWM_LinePressure(uint32 value);
void Set_PWM_TCC(uint32 value);

void Set_SOL_ClutchParking(uint32 value);
void Set_SOL_ClutchNeutral(uint32 value);
void Set_SOL_ClutchReverse(uint32 value);

void Set_SOL_ClutchA(uint32 value);
void Set_SOL_ClutchB(uint32 value);
void Set_SOL_ClutchC(uint32 value);
void Set_SOL_ClutchD(uint32 value);
void Set_SOL_ShiftLock(uint32 value);


// ============================================================================
// INTERNAL LOGIC OUTPUTS
// ============================================================================
void Set_TCM_CurrentGear(uint32 value);
void Set_TCM_TargetGear(uint32 value);
void Set_TCM_ShiftInProgress(uint32 value);
void Set_TCM_ShiftQualityIndex(uint32 value);



#endif /* SET_SIGNALS_H_ */
