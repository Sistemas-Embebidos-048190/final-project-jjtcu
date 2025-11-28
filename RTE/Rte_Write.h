/*
 * Rte_Write.h
 *
 *  Created on: Nov 24, 2025
 *      Author: joshu
 */

#ifndef RTE_WRITE_H_
#define RTE_WRITE_H_

#include "Global_Signals.h"
#include "Set_Signals.h"



// ECU → TCU
void Write_CAN_EngineRPM(uint32 value);
void Write_CAN_EngineTorqueActual(sint32 value);
void Write_CAN_EngineCoolantTemp(sint32 value);
void Write_CAN_ThrottlePosition(uint32 value);

// ABS → TCU
void Write_CAN_VehicleSpeedRef(uint32 value);

// BCM / Switch Panel
void Write_CAN_DriverModeSelection(uint32 value);

// DIRECT INPUT SIGNALS
void Write_IO_BrakeLightSwitch(uint32 value);
void Write_IO_Gear_Lever_Position(uint32 value);

// INTERNAL TRANSMISSION SENSORS
void Write_TCM_TurbineSpeed_TSS(uint32 value);
void Write_TCM_OutputSpeed_OSS(uint32 value);
void Write_TCM_FluidTemp_TFT(sint32 value);

// CAN OUTPUT SIGNALS
void Write_CAN_TorqueReductionRequest(uint32 value);
void Write_CAN_SelectedGear(uint32 value);

// SOLENOID CONTROL OUTPUTS
void Write_PWM_LinePressure(uint32 value);
void Write_PWM_TCC(uint32 value);

void Write_SOL_ClutchParking(uint32 value);
void Write_SOL_ClutchReverse(uint32 value);
void Write_SOL_ClutchNeutral(uint32 value);

void Write_SOL_ClutchA(uint32 value);
void Write_SOL_ClutchB(uint32 value);
void Write_SOL_ClutchC(uint32 value);
void Write_SOL_ClutchD(uint32 value);
void Write_SOL_ShiftLock(uint32 value);

// INTERNAL LOGIC OUTPUTS
void Write_TCM_CurrentGear(uint32 value);
void Write_TCM_TargetGear(uint32 value);
void Write_TCM_ShiftInProgress(uint32 value);
void Write_TCM_ShiftQualityIndex(uint32 value);






#endif /* RTE_WRITE_H_ */


