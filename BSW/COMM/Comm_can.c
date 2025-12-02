#include "Comm_can.h"




void Can_Update(void){
	// =========================================================
	// 4. FUNCIÓN MAIN (EJEMPLO DE EJECUCIÓN)
	// =========================================================




//	     printf("--- INICIO DE SIMULACIÓN DE TCU (CAN BUS SUBSTITUTE) ---\n");
//	     printf("Simulando: Arranque -> Aceleración (Shift 1-2) -> Coasting\n\n");

	     for (int i = 0; i < SCENARIO_STEPS; i++) {

	         // 1. Actualizar las entradas simuladas
	        Simulate_CAN_Bus_Update(i);
	         // ECU → TCU
			Write_CAN_EngineRPM(current_inputs.engine_rpm);
			Write_CAN_EngineTorqueActual(current_inputs.engine_torque);
			Write_CAN_EngineCoolantTemp(100u);
			Write_CAN_ThrottlePosition(current_inputs.throttle_pos);

			// ABS → TCU
			Write_CAN_VehicleSpeedRef(current_inputs.vehicle_speed_ref);

			// BCM / Switch Panel
			Write_CAN_DriverModeSelection(1u);

//	         // // Simular retardo de tiempo si se corriera en tiempo real
//	          for(uint32 t = 0; t < 10000; t++);
	     }



}
