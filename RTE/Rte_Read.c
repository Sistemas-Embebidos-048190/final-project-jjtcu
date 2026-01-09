/*
 * Rte_Read.c
 *
 *  Created on: Nov 24, 2025
 *      Author: joshu
 */

#include "Rte_Read.h"



// ============================================================================
// ECU → TCU
// ============================================================================
void Read_CAN_EngineRPM(uint32 *value)
{
    Get_CAN_EngineRPM(value);
}

void Read_CAN_EngineTorqueActual(sint32 *value)
{
    Get_CAN_EngineTorqueActual(value);
}

void Read_CAN_EngineCoolantTemp(sint32 *value)
{
    Get_CAN_EngineCoolantTemp(value);
}

void Read_CAN_ThrottlePosition(uint32 *value)
{
    Get_CAN_ThrottlePosition(value);
}


// ============================================================================
// ABS → TCU
// ============================================================================
void Read_CAN_VehicleSpeedRef(uint32 *value)
{
    Get_CAN_VehicleSpeedRef(value);
}


// ============================================================================
// BCM / Switch Panel
// ============================================================================
void Read_CAN_DriverModeSelection(uint32 *value)
{
    Get_CAN_DriverModeSelection(value);
}


// ============================================================================
// DIRECT INPUT SIGNALS
// ============================================================================
void Read_IO_BrakeLightSwitch(uint32 *value)
{
    Get_IO_BrakeLightSwitch(value);
}

void Read_IO_Gear_Lever_Position(uint32 *value)
{
    Get_IO_Gear_Lever_Position(value);
}


// ============================================================================
// INTERNAL TRANSMISSION SENSORS
// ============================================================================
void Read_TCM_TurbineSpeed_TSS(uint32 *value)
{
    Get_TCM_TurbineSpeed_TSS(value);
}

void Read_TCM_OutputSpeed_OSS(uint32 *value)
{
    Get_TCM_OutputSpeed_OSS(value);
}

void Read_TCM_FluidTemp_TFT(sint32 *value)
{
    Get_TCM_FluidTemp_TFT(value);
}


// ============================================================================
// CAN OUTPUT SIGNALS
// ============================================================================
void Read_CAN_TorqueReductionRequest(uint32 *value)
{
    Get_CAN_TorqueReductionRequest(value);
}

void Read_CAN_SelectedGear(uint32 *value)
{
    Get_CAN_SelectedGear(value);
}


// ============================================================================
// SOLENOID CONTROL OUTPUTS (PWM / DIGITAL)
// ============================================================================
void Read_PWM_LinePressure(float *value)
{
    Get_PWM_LinePressure(value);
}

void Read_PWM_TCC(float *value)
{
    Get_PWM_TCC(value);
}

void Read_SOL_ClutchParking(uint32 *value)
{
    Get_SOL_ClutchParking(value);
}
void Read_SOL_ClutchReverse(uint32 *value)
{
    Get_SOL_ClutchReverse(value);
}
void Read_SOL_ClutchNeutral(uint32 *value)
{
    Get_SOL_ClutchNeutral(value);
}

void Read_SOL_ClutchA(uint32 *value)
{
    Get_SOL_ClutchA(value);
}

void Read_SOL_ClutchB(uint32 *value)
{
    Get_SOL_ClutchB(value);
}

void Read_SOL_ClutchC(uint32 *value)
{
    Get_SOL_ClutchC(value);
}

void Read_SOL_ClutchD(uint32 *value)
{
    Get_SOL_ClutchD(value);
}

void Read_SOL_ShiftLock(uint32 *value)
{
    Get_SOL_ShiftLock(value);
}


// ============================================================================
// INTERNAL LOGIC OUTPUTS
// ============================================================================
void Read_TCM_CurrentGear(uint32 *value)
{
    Get_TCM_CurrentGear(value);
}

void Read_TCM_TargetGear(uint32 *value)
{
    Get_TCM_TargetGear(value);
}

void Read_TCM_ShiftInProgress(uint32 *value)
{
    Get_TCM_ShiftInProgress(value);
}

void Read_TCM_ShiftQualityIndex(uint32 *value)
{
    Get_TCM_ShiftQualityIndex(value);
}


