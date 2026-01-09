
#include "CAN_signals_simulations.h"
// =========================================================
// 1. DEFINICIÓN DE TIPOS DE DATOS (Basado en las imágenes)
// =========================================================



//
// Variable Global que representa el estado actual de las entradas del Micro
TCU_Input_Signals_t current_inputs;
// =========================================================
// 2. ARREGLOS DE DATOS DE ESCENARIO (SIMULACIÓN)
// =========================================================
// Escenario: El auto está en Parking, se enciende, pasa a Drive,
// acelera suavemente pasando por 1ra y 2da marcha, y luego suelta el acelerador.
// Asumimos un muestreo cada 100ms (0.1s).

// Paso 0-4: Idle en Parking
// Paso 5: Cambio a Drive
// Paso 6-20: Aceleración (Cambio de marcha simulado en el paso 13)
// Paso 21-24: Soltar acelerador (Coasting)

const uint16_t DATA_ENGINE_RPM[SCENARIO_STEPS] = {
    800, 800, 800, 800, 800, 900, 950, 1500, 1833, 2167,
    2500, 2500, 1500, 1700, 2067, 2433, 2800, 2800, 1700, 1900,
    2300, 2700, 3100, 3100, 1900, 2100, 2533, 2967, 3400, 3400,
    2100, 2300, 2767, 3233, 3700, 3700, 2300, 2500, 3000, 3500,
    4000, 4000, 2500, 2500, 2442, 2383, 2325, 2267, 2208, 2150,
    2092, 2033, 1975, 1917, 1858, 1800, 1800, 1723, 1646, 1569,
    1492, 1415, 1338, 1262, 1185, 1108, 1031, 954, 877, 800
};

const uint8_t DATA_THROTTLE[SCENARIO_STEPS] = {
    0, 0, 0, 0, 0, 5, 10, 25, 25, 25,
    25, 30, 30, 30, 30, 30, 30, 35, 35, 35,
    35, 35, 35, 40, 40, 40, 40, 40, 40, 45,
    45, 45, 45, 45, 45, 50, 50, 50, 50, 50,
    50, 55, 55, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

const uint8_t DATA_VEHICLE_SPEED[SCENARIO_STEPS] = {
    0, 0, 0, 0, 0, 0, 0, 0, 3, 6,
    9, 12, 15, 15, 19, 23, 27, 31, 35, 35,
    40, 45, 50, 55, 60, 60, 66, 72, 78, 84,
    90, 90, 98, 106, 114, 122, 130, 130, 140, 150,
    160, 170, 180, 180, 177, 173, 170, 167, 163, 160,
    157, 153, 150, 147, 143, 140, 140, 129, 118, 108,
    97, 86, 75, 65, 54, 43, 32, 22, 11, 0
};

const int16_t DATA_TORQUE[SCENARIO_STEPS] = {
    10, 10, 10, 10, 10, 30, 40, 80, 80, 80,
    80, 100, 50, 100, 100, 100, 100, 120, 70, 120,
    120, 120, 120, 140, 90, 140, 140, 140, 140, 160,
    110, 160, 160, 160, 160, 180, 130, 180, 180, 180,
    180, 200, 150, -5, -6, -8, -9, -10, -11, -12,
    -14, -15, -16, -18, -19, -20, -20, -23, -26, -29,
    -32, -35, -38, -42, -45, -48, -51, -54, -57, -60
};

const GearLeverPos_t DATA_GEAR_LEVER[SCENARIO_STEPS] = {
    GEAR_POS_P, GEAR_POS_P, GEAR_POS_P, GEAR_POS_P, GEAR_POS_N, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D,
    GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D,
    GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D,
    GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D,
    GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D,
    GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D,
    GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D, GEAR_POS_D
};

const bool DATA_BRAKE_SW[SCENARIO_STEPS] = {
    1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};



// =========================================================
// 3. FUNCIONES DE SIMULACIÓN E INTERFAZ
// =========================================================

/**
 * @brief Simula la recepción de tramas CAN y lectura de sensores.
 * Esta función debe ser llamada periódicamente (ej. cada 100ms) en tu loop principal de prueba.
 * * @param step_index El índice actual del tiempo de simulación.
 */
void Simulate_CAN_Bus_Update(int step_index) {
    if (step_index < 0 || step_index >= SCENARIO_STEPS) {
        // Si se acaba el escenario, mantenemos los últimos valores seguros (Idle)
        current_inputs.engine_rpm = 800;
        current_inputs.throttle_pos = 0;
        current_inputs.engine_torque = 10;
        current_inputs.vehicle_speed_ref = 0;
        return;
    }

    // --- 1. Cargar señales CAN desde los arreglos ---
    current_inputs.engine_rpm = DATA_ENGINE_RPM[step_index];
    current_inputs.throttle_pos = DATA_THROTTLE[step_index];
    current_inputs.engine_torque = DATA_TORQUE[step_index];
    current_inputs.vehicle_speed_ref = DATA_VEHICLE_SPEED[step_index];
    current_inputs.drive_mode = DRIVE_MODE_ECO; // Valor fijo para este test
    
    // --- 2. Cargar señales Hardwired ---
    current_inputs.gear_lever = DATA_GEAR_LEVER[step_index];
    current_inputs.brake_pedal_sw = DATA_BRAKE_SW[step_index];

    // --- 3. Calcular Lógica de Sensores Internos (Coherencia) ---
    // Para que la simulación "haga sentido", los sensores internos deben coincidir con el CAN.
    
    // Turbine Speed: Generalmente igual a Engine RPM (si el convertidor está bloqueado)
    // o ligeramente menor (si hay resbalamiento). Simulamos un resbalamiento del 5%.
    if (current_inputs.engine_rpm > 0) {
        current_inputs.turbine_speed = current_inputs.engine_rpm * 0.95;
    } else {
        current_inputs.turbine_speed = 0;
    }

    // Output Speed: Directamente proporcional a la velocidad del vehículo.
    // Asumimos un factor de conversión arbitrario (ej. RPM = KPH * 30 para el diferencial)
    current_inputs.output_speed = current_inputs.vehicle_speed_ref * 30; 

    // Temperatura: Simulamos un calentamiento lento
    current_inputs.trans_fluid_temp = 40 + (step_index / 2); // Sube 0.5 grados por step

	vTaskDelay(pdMS_TO_TICKS(100));

}

/**
 * @brief Función auxiliar para imprimir el estado (Como si fuera un Log)
 */
void Print_System_State(int time_step) {
    printf("T=%02d | GearLv: %d | Mode: %s | RPM: %04d | Speed: %03d km/h | Trq: %03d Nm | Thr: %03d%% | Brake: %d\n", 
           time_step,
           current_inputs.gear_lever,
           (current_inputs.drive_mode == DRIVE_MODE_SPORT) ? "SPT" : "ECO",
           current_inputs.engine_rpm,
           current_inputs.vehicle_speed_ref,
           current_inputs.engine_torque,
           current_inputs.throttle_pos,
           current_inputs.brake_pedal_sw);
           
    // Detección simple de cambio de marcha basado en la caída de RPM mientras se acelera
    if(time_step == 12) printf("      >> LOGIC EVENT: Preparando Shift UP \n");
    if(time_step == 13) printf("      >> LOGIC EVENT: Shift Executed (RPM Drop) \n");
}

