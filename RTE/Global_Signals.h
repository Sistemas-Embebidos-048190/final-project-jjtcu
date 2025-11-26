#ifndef GLOBAL_SIGNALS_H
#define GLOBAL_SIGNALS_H

#include "Platform_Types.h"


typedef enum
{
    GEAR_PARKING = 1,  // 0
    GEAR_REVERSE,      // 1
    GEAR_NEUTRAL,      // 2
    GEAR_DRIVE,        // 3
    GEAR_FIRST,        // 4
    GEAR_SECOND,       // 5
    GEAR_THIRD,        // 6
    GEAR_INVALID       // 7 -> cuando no hay nada válido o hay error
} gear_selector_t;




// ECU → TCU
extern uint16 g_CAN_EngineRPM;               // Engine_RPM
extern sint16 g_CAN_EngineTorqueActual;      // Engine_Torque_Actual (puede ser negativo)
extern sint16 g_CAN_EngineCoolantTemp;       // Engine_Coolant_Temp
extern uint8  g_CAN_ThrottlePosition;        // Throttle_Position_Sensor (0-100%)

// ABS → TCU
extern uint16 g_CAN_VehicleSpeedRef;         // Vehicle_Speed_Reference

// BCM / Switch Panel
extern uint8 g_CAN_DriverModeSelection;       // Driver_Mode_Selection (0=Eco,1=Sport)


// =====================
// DIRECT INPUT SIGNALS
// =====================
extern uint8  g_IO_BrakeLightSwitch;          // Brake Light Switch (0/1)
extern uint8  g_IO_Gear_Lever_Position;       // Lever Position


// =====================
// INTERNAL TRANSMISSION SENSORS
// =====================
extern uint16 g_TCM_TurbineSpeed_TSS;        // Turbine/Input Speed Sensor
extern uint16 g_TCM_OutputSpeed_OSS;         // Output Speed Sensor
extern sint16 g_TCM_FluidTemp_TFT;           // Transmission Fluid Temperature


// ============================================================================
// TCU OUTPUT SIGNALS
// ============================================================================

// =====================
// CAN OUTPUT SIGNALS
// =====================
extern uint8  g_CAN_TorqueReductionRequest;   // Torque_Reduction_Request
extern uint8  g_CAN_SelectedGear;             // Marcha mostrada en cluster (P,R,N,D,1-6)


// =====================
// SOLENOID CONTROL OUTPUTS (PWM / DIGITAL)
// =====================
extern uint16 g_PWM_LinePressure;             // Solenoide presión de línea
extern uint16 g_PWM_TCC;                      // Solenoide Torque Converter Clutch (TCC)
extern uint8  g_SOL_ClutchA;                  // Solenoide embrague A
extern uint8  g_SOL_ClutchB;                  // Solenoide embrague B
extern uint8  g_SOL_ClutchC;                  // Solenoide embrague C
extern uint8  g_SOL_ClutchD;                  // Solenoide embrague D
extern uint8  g_SOL_ShiftLock;                // Solenoide de bloqueo


// =====================
// INTERNAL LOGIC OUTPUTS
// =====================
extern uint8  g_TCM_CurrentGear;              // Gear_Selection_State (1-6, P,R,N,D)
extern uint8  g_TCM_TargetGear;               // Gear solicitado por mapa
extern uint8  g_TCM_ShiftInProgress;          // Estado de transición (0/1)
extern uint8  g_TCM_ShiftQualityIndex;        // Calidad del cambio (+/-1)





#endif /* GLOBAL_SIGNALS_H */
