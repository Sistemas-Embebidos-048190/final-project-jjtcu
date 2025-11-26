#ifndef IOHWAB_ADC_H
#define IOHWAB_ADC_H

#include "app.h"
#include "fsl_port.h"
#include "board.h"
#include "fsl_common.h"
#include "fsl_port.h"
#include "fsl_lpadc.h"
#include "Platform_Types.h"

#include "Rte_Write.h"

/* Inicialización principal */
void Init_ADC_Pins(void);
void TCM_LPADC_InitSensors(void);

/* Lecturas de sensores (valor crudo ADC 12 bits) */
void TCM_Read_OutputSpeedSensorRaw(void);
void TCM_Read_FluidTempSensorRaw(void);
void TCM_Read_TurbineSpeedSensorRaw(void);

/* Helper para lectura ADC (opcional, pero útil si quieres usar triggers manualmente) */
uint16 TCM_LPADC_ReadByTrigger(uint32 triggerIndex);






#endif /* IOHWAB_ADC_H */
