
#include "IoHwAb.h"

void Init_All_Pins(void){

	Init_Gear_Selection_Pins();
	Init_Brake_Pedal_Pins();
	Init_Shifter_Output_Pins();
	Init_ADC_Pins();
	TCM_LPADC_InitSensors();
	Pin_init_PWM();
}


void Update_Pin_Values(void){

	// GPIO
	// GET
	Brake_Pedal_Read();
	Gear_Selection_GetPosition();

	// SET
	Set_Shift_Lock_Sol();
	Set_Shift_Sol_A;
	Set_Shift_Sol_B;
	Set_Shift_Sol_C;
	Set_Shift_Sol_D;

	// ADC
	// GET
	TCM_Read_OutputSpeedSensor();
	TCM_Read_FluidTempSensor();
	TCM_Read_TurbineSpeedSensor();

	//PWM
	//SET
	LinePressure_SetDuty();
	TCCPressure_SetDuty();


}

