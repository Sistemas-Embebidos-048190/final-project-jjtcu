
#include "IoHwAb_adc.h"
#include "fsl_vref.h"
#include "fsl_spc.h"

#define TCM_LPADC_BASE              ADC0
#define DEMO_VREF_BASE VREF0

// IDs de comandos LPADC (1–15 válidos)
#define TCM_LPADC_CMDID_OUTPUT      1U   // P0_14  Output_Speed_Sensor
#define TCM_LPADC_CMDID_FLUID       2U   // P0_22  Fluid_Trans_Temperature
#define TCM_LPADC_CMDID_TURBINE     3U   // P0_15  Turbine_Speed_Sensor

// Triggers de software (0–3 típicamente)
#define TCM_LPADC_TRIG_OUTPUT       0U
#define TCM_LPADC_TRIG_FLUID        1U
#define TCM_LPADC_TRIG_TURBINE      2U

// BORRA esto:
// #define TCM_LPADC_RESULT_MASK       ADC_RESFIFO_D_MASK
// #if (defined(DEMO_LPADC_USE_HIGH_RESOLUTION) && DEMO_LPADC_USE_HIGH_RESOLUTION)
// #define TCM_LPADC_RESULTSHIFT       0U
// #else
// #define TCM_LPADC_RESULTSHIFT       3U
// #endif

// Y déjalo ASÍ:
#define TCM_LPADC_RESULT_MASK   (0xFFFFU)
#define TCM_LPADC_RESULTSHIFT   (0U)


#define DEMO_LPADC_VREF_SOURCE           kLPADC_ReferenceVoltageAlt3
#define DEMO_LPADC_DO_OFFSET_CALIBRATION true
#define DEMO_LPADC_OFFSET_VALUE_A        0x10U
#define DEMO_LPADC_OFFSET_VALUE_B        0x10U

#define DEMO_SPC_BASE           SPC0


void Init_ADC_Pins(void)
{
    CLOCK_EnableClock(kCLOCK_Port0);

    const port_pin_config_t adc_pin_config = {
        kPORT_PullDisable,
        kPORT_LowPullResistor,
        kPORT_FastSlewRate,
        kPORT_PassiveFilterDisable,
        kPORT_OpenDrainDisable,
        kPORT_LowDriveStrength,
		kPORT_MuxAlt0,            // *** ALT0 = P0_x (modo adecuado para ADC)
        kPORT_InputBufferDisable, // desactiva buffer digital (mejor para analógico)
        kPORT_InputNormal,
        kPORT_UnlockRegister
    };

    PORT_SetPinConfig(PORT0, 14U, &adc_pin_config); // OUTPUT  -> ADC0_B14
    PORT_SetPinConfig(PORT0, 22U, &adc_pin_config); // FLUID   -> ADC0_A14
    PORT_SetPinConfig(PORT0, 15U, &adc_pin_config); // TURBINE -> ADC0_B15
}




void TCM_LPADC_InitSensors(void)
{

	vref_config_t vrefConfig;
	/* 1) Configurar el reloj funcional de ADC0 */
	    CLOCK_SetClkDiv(kCLOCK_DivAdc0Clk, 1U);      // divisor = 1
	    CLOCK_AttachClk(kFRO_HF_to_ADC0);            // FRO_HF (48 MHz) → ADC0

	    /* 2) Habilitar clock de periférico y reset */
	    //CLOCK_EnableClock(kCLOCK_Adc0);
	    //RESET_PeripheralReset(kADC0_RST_SHIFT_RSTn);

	    /* enable VREF */
	        SPC_EnableActiveModeAnalogModules(DEMO_SPC_BASE, kSPC_controlVref);

	        VREF_GetDefaultConfig(&vrefConfig);
	        vrefConfig.bufferMode = kVREF_ModeBandgapOnly;
	        /* Initialize VREF module, the VREF module is only used to supply the bias current for LPADC. */
	        VREF_Init(DEMO_VREF_BASE, &vrefConfig);

	    lpadc_config_t              lpadcConfig;
	    lpadc_conv_command_config_t cmdConfig;
	    lpadc_conv_trigger_config_t trigConfig;

	    /* Config básica del LPADC */
	    LPADC_GetDefaultConfig(&lpadcConfig);
	    lpadcConfig.powerLevelMode = kLPADC_PowerLevelAlt4;
	    lpadcConfig.enableAnalogPreliminary = true;
	    lpadcConfig.referenceVoltageSource = 2U;
	    //lpadcConfig.enableAnalogPreliminary = true;
	    //lpadcConfig.powerUpDelay            = 0x10U;
//	#if defined(FSL_FEATURE_LPADC_HAS_CFG_PWRSEL) && FSL_FEATURE_LPADC_HAS_CFG_PWRSEL
//	    //lpadcConfig.powerLevelMode          = kLPADC_PowerLevelAlt4;
//	#endif
//
//	    /* (Opcional pero recomendable: usar misma referencia que el demo) */
//	#if defined(DEMO_LPADC_VREF_SOURCE)
//	    lpadcConfig.referenceVoltageSource  = DEMO_LPADC_VREF_SOURCE;
//	#endif






	lpadcConfig.conversionAverageMode = kLPADC_ConversionAverage128;
	LPADC_Init(TCM_LPADC_BASE, &lpadcConfig);

	LPADC_DoOffsetCalibration(TCM_LPADC_BASE);

	LPADC_DoAutoCalibration(TCM_LPADC_BASE);


//    /* Limpiar FIFO y banderas */
//#if (defined(FSL_FEATURE_LPADC_FIFO_COUNT) && (FSL_FEATURE_LPADC_FIFO_COUNT == 2U))
//    LPADC_DoResetFIFO0(TCM_LPADC_BASE);
//    LPADC_DoResetFIFO1(TCM_LPADC_BASE);
//#else
//    LPADC_DoResetFIFO(TCM_LPADC_BASE);
//#endif
//    LPADC_ClearStatusFlags(TCM_LPADC_BASE,
//                           kLPADC_ResultFIFO0OverflowFlag |
//                           kLPADC_ResultFIFO0ReadyFlag);
//
//    /* Si quieres más precisión, puedes habilitar calibración:
//       LPADC_DoAutoCalibration(TCM_LPADC_BASE);
//    */
//
//    /* Config base de comandos de conversión */
    LPADC_GetDefaultConvCommandConfig(&cmdConfig);


    /* OUTPUT_SPEED_SENSOR  (P0_14 = ADC0_B14 → canal 14, lado B) */
    cmdConfig.channelNumber     = 14U;
    cmdConfig.sampleChannelMode = kLPADC_SampleChannelSingleEndSideB;
    LPADC_SetConvCommandConfig(TCM_LPADC_BASE, TCM_LPADC_CMDID_OUTPUT, &cmdConfig);

//    /* FLUID_TRANS_TEMPERATURE (P0_22 = ADC0_A14 → canal 14, lado A) */
//    cmdConfig.channelNumber     = 14U;
//    cmdConfig.sampleChannelMode = kLPADC_SampleChannelSingleEndSideA;
//    LPADC_SetConvCommandConfig(TCM_LPADC_BASE, TCM_LPADC_CMDID_FLUID, &cmdConfig);
//
//    /* TURBINE_SPEED_SENSOR (P0_15 = ADC0_B15 → canal 15, lado B) */
//    cmdConfig.channelNumber     = 15U;
//    cmdConfig.sampleChannelMode = kLPADC_SampleChannelSingleEndSideB;
//    LPADC_SetConvCommandConfig(TCM_LPADC_BASE, TCM_LPADC_CMDID_TURBINE, &cmdConfig);

    /* Triggers de software para cada comando */
    LPADC_GetDefaultConvTriggerConfig(&trigConfig);
    trigConfig.targetCommandId = TCM_LPADC_CMDID_OUTPUT;
    trigConfig.enableHardwareTrigger = false;  // puro software trigger

    //trigConfig.targetCommandId = TCM_LPADC_CMDID_OUTPUT;
    LPADC_SetConvTriggerConfig(TCM_LPADC_BASE, TCM_LPADC_TRIG_OUTPUT, &trigConfig);
//
//    trigConfig.targetCommandId = TCM_LPADC_CMDID_FLUID;
//    LPADC_SetConvTriggerConfig(TCM_LPADC_BASE, TCM_LPADC_TRIG_FLUID, &trigConfig);
//
//    trigConfig.targetCommandId = TCM_LPADC_CMDID_TURBINE;
//    LPADC_SetConvTriggerConfig(TCM_LPADC_BASE, TCM_LPADC_TRIG_TURBINE, &trigConfig);

    /* Encender el ADC (igual que en muchos ejemplos) */
    //LPADC_Enable(TCM_LPADC_BASE, true);
}









void TCM_Read_OutputSpeedSensorRaw(void)
{
	lpadc_conv_result_t result;
	uint32 triggerMask = (1UL << 0);
	const uint32_t g_LpadcResultShift = 3U;

	LPADC_DoSoftwareTrigger(TCM_LPADC_BASE, triggerMask);

	while (!LPADC_GetConvResult(TCM_LPADC_BASE, &result, 0U))
	{
	}
	Write_TCM_OutputSpeed_OSS( (result.convValue) >> g_LpadcResultShift  );
}

void TCM_Read_FluidTempSensorRaw(void)
{
	Write_TCM_FluidTemp_TFT( TCM_LPADC_ReadByTrigger(TCM_LPADC_TRIG_FLUID) );
}

void TCM_Read_TurbineSpeedSensorRaw(void)
{
	Write_TCM_TurbineSpeed_TSS (TCM_LPADC_ReadByTrigger(TCM_LPADC_TRIG_TURBINE) );
}


