#ifndef IOHWAB_PWM_H
#define IOHWAB_PWM_H

#include "app.h"
#include "fsl_port.h"
#include "board.h"
#include "fsl_common.h"
#include "fsl_pwm.h"
#include "Platform_Types.h"

#include "Rte_Read.h"


// PRESSURE CONTROL
void Pin_init_PWM(void);
void PWM_InitPins(void);
void LinePressure_SetDuty(void);
void TCCPressure_SetDuty(void);





#endif /* IOHWAB_PWM_H */
