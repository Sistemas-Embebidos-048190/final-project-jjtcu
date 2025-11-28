/*
 * Rte_Read.h
 *
 *  Created on: Nov 24, 2025
 *      Author: joshu
 */

#ifndef RTE_READ_H_
#define RTE_READ_H_

#include "Global_Signals.h"
#include "Get_Signals.h"



// ECU → TCU
void Read_CAN_EngineRPM(uint32 *value);
void Read_CAN_EngineTorqueActual(sint32 *value);
void Read_CAN_EngineCoolantTemp(sint32 *value);
void Read_CAN_ThrottlePosition(uint32 *value);

// ABS → TCU
void Read_CAN_VehicleSpeedRef(uint32 *value);

// BCM / Switch Panel
void Read_CAN_DriverModeSelection(uint32 *value);

// DIRECT INPUT SIGNALS
void Read_IO_BrakeLightSwitch(uint32 *value);
void Read_IO_Gear_Lever_Position(uint32 *value);

// INTERNAL TRANSMISSION SENSORS
void Read_TCM_TurbineSpeed_TSS(uint32 *value);
void Read_TCM_OutputSpeed_OSS(uint32 *value);
void Read_TCM_FluidTemp_TFT(sint32 *value);

// CAN OUTPUT SIGNALS
void Read_CAN_TorqueReductionRequest(uint32 *value);
void Read_CAN_SelectedGear(uint32 *value);

// SOLENOID CONTROL OUTPUTS (PWM / DIGITAL)
void Read_PWM_LinePressure(uint32 *value);
void Read_PWM_TCC(uint32 *value);

void Read_SOL_ClutchParking(uint32 *value);
void Read_SOL_ClutchReverse(uint32 *value);
void Read_SOL_ClutchNeutral(uint32 *value);

void Read_SOL_ClutchA(uint32 *value);
void Read_SOL_ClutchB(uint32 *value);
void Read_SOL_ClutchC(uint32 *value);
void Read_SOL_ClutchD(uint32 *value);
void Read_SOL_ShiftLock(uint32 *value);

// INTERNAL LOGIC OUTPUTS
void Read_TCM_CurrentGear(uint32 *value);
void Read_TCM_TargetGear(uint32 *value);
void Read_TCM_ShiftInProgress(uint32 *value);
void Read_TCM_ShiftQualityIndex(uint32 *value);



#endif /* RTE_READ_H_ */
