/*
 * CAN_signals_simulations.h
 *
 *  Created on: Dec 1, 2025
 *      Author: joshu
 */

#ifndef CAN_SIGNALS_SIMULATIONS_H_
#define CAN_SIGNALS_SIMULATIONS_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "FreeRTOS.h"
#include "task.h"

#define SCENARIO_STEPS 25
//Estructura que representa todas las entradas que el Microcontrolador recibe
// (Tanto las que vendrían por CAN como las Hardwired simuladas)
// Enum para Gear Lever Position (0-7)
typedef enum {
    GEAR_POS_P = 0,
    GEAR_POS_R = 1,
    GEAR_POS_N = 2,
    GEAR_POS_D = 3,
    GEAR_POS_LOW = 4,
    // Otros estados reservados...
} GearLeverPos_t;

// Enum para Driver Mode Selection
typedef enum {
    DRIVE_MODE_ECO = 0,
    DRIVE_MODE_SPORT = 1
} DriveMode_t;
typedef struct {
    // --- Señales CAN (Simuladas) ---
    uint16_t engine_rpm;        // 0 - 8000 RPM
    uint8_t  throttle_pos;      // 0 - 100 %
    int16_t  engine_torque;     // -50 a 400 Nm
    uint8_t  vehicle_speed_ref; // 0 - 250 kph (ABS)
    DriveMode_t drive_mode;     // Eco/Sport

    // --- Señales Hardwired (Simuladas para coherencia) ---
    // Aunque son hardwired, necesitas inyectar valores para probar tu lógica
    GearLeverPos_t gear_lever;
    bool     brake_pedal_sw;    // 0 o 1
    uint16_t turbine_speed;     // Entrada a la transmisión
    uint16_t output_speed;      // Salida de la transmisión
    int16_t  trans_fluid_temp;  // -40 a 150 C
} TCU_Input_Signals_t;

extern TCU_Input_Signals_t current_inputs;

void Simulate_CAN_Bus_Update(int step_index);
void Print_System_State(int time_step);



#endif /* CAN_SIGNALS_SIMULATIONS_H_ */
