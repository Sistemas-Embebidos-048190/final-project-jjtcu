/*
 * Rte_Write.c
 *
 *  Created on: Nov 24, 2025
 *      Author: joshu
 */

#include "Rte_Write.h"

// ECU → TCU
void Write_CAN_EngineRPM(uint32 value)
{
    Set_CAN_EngineRPM(value);
}

void Write_CAN_EngineTorqueActual(sint32 value)
{
    Set_CAN_EngineTorqueActual(value);
}

void Write_CAN_EngineCoolantTemp(sint32 value)
{
    Set_CAN_EngineCoolantTemp(value);
}

void Write_CAN_ThrottlePosition(uint32 value)
{
    Set_CAN_ThrottlePosition(value);
}


// ABS → TCU
void Write_CAN_VehicleSpeedRef(uint32 value)
{
    Set_CAN_VehicleSpeedRef(value);
}


// BCM / Switch Panel
void Write_CAN_DriverModeSelection(uint32 value)
{
    Set_CAN_DriverModeSelection(value);
}


// =====================
// DIRECT INPUT SIGNALS
// =====================
void Write_IO_BrakeLightSwitch(uint32 value)
{
    Set_IO_BrakeLightSwitch(value);
}

void Write_IO_Gear_Lever_Position(uint32 value)
{
    Set_IO_Gear_Lever_Position(value);
}


// =====================
// INTERNAL TRANSMISSION SENSORS
// =====================
void Write_TCM_TurbineSpeed_TSS(uint32 value)
{
    Set_TCM_TurbineSpeed_TSS(value);
}

void Write_TCM_OutputSpeed_OSS(uint32 value)
{
    Set_TCM_OutputSpeed_OSS(value);
}

void Write_TCM_FluidTemp_TFT(sint32 value)
{
    Set_TCM_FluidTemp_TFT(value);
}


// ============================================================================
// CAN OUTPUT SIGNALS
// ============================================================================
void Write_CAN_TorqueReductionRequest(uint32 value)
{
    Set_CAN_TorqueReductionRequest(value);
}

void Write_CAN_SelectedGear(uint32 value)
{
    Set_CAN_SelectedGear(value);
}


// ============================================================================
// SOLENOID CONTROL OUTPUTS
// ============================================================================
void Write_PWM_LinePressure(uint32 value)
{
    Set_PWM_LinePressure(value);
}

void Write_PWM_TCC(uint32 value)
{
    Set_PWM_TCC(value);
}
void Write_SOL_ClutchParking(uint32 value)
{
    Set_SOL_ClutchParking(value);
}

void Write_SOL_ClutchReverse(uint32 value)
{
    Set_SOL_ClutchReverse(value);
}

void Write_SOL_ClutchNeutral(uint32 value)
{
    Set_SOL_ClutchNeutral(value);
}

void Write_SOL_ClutchA(uint32 value)
{
    Set_SOL_ClutchA(value);
}

void Write_SOL_ClutchB(uint32 value)
{
    Set_SOL_ClutchB(value);
}

void Write_SOL_ClutchC(uint32 value)
{
    Set_SOL_ClutchC(value);
}

void Write_SOL_ClutchD(uint32 value)
{
    Set_SOL_ClutchD(value);
}

void Write_SOL_ShiftLock(uint32 value)
{
    Set_SOL_ShiftLock(value);
}


// ============================================================================
// INTERNAL LOGIC OUTPUTS
// ============================================================================
void Write_TCM_CurrentGear(uint32 value)
{
    Set_TCM_CurrentGear(value);
}

void Write_TCM_TargetGear(uint32 value)
{
    Set_TCM_TargetGear(value);
}

void Write_TCM_ShiftInProgress(uint32 value)
{
    Set_TCM_ShiftInProgress(value);
}

void Write_TCM_ShiftQualityIndex(uint32 value)
{
    Set_TCM_ShiftQualityIndex(value);
}
