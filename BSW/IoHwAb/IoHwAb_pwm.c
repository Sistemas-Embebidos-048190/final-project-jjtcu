
#include "IoHwAb_pwm.h"


#include "IoHwAb_pwm.h"

#include "IoHwAb_pwm.h"

#include "IoHwAb_pwm.h"

void Init_Pressure_Solenoids_Pwm(void)
{
    /* Clocks de puerto y PWM */
    CLOCK_EnableClock(kCLOCK_Port2);
    CLOCK_EnableClock(kCLOCK_Pwm1);
    CLOCK_EnableClock(kCLOCK_Pwm1_Sm0);

    /* ==== MUX de pines ==== */
    const port_pin_config_t port2_6_pinK2_config = {
        kPORT_PullDisable,
        kPORT_LowPullResistor,
        kPORT_FastSlewRate,
        kPORT_PassiveFilterDisable,
        kPORT_OpenDrainDisable,
        kPORT_LowDriveStrength,
        kPORT_MuxAlt5,            // ALT5 = PWM1_A0 (J3-15)
        kPORT_InputBufferEnable,
        kPORT_InputNormal,
        kPORT_UnlockRegister
    };
    PORT_SetPinConfig(PORT2, 6U, &port2_6_pinK2_config);

    const port_pin_config_t port2_7_pinL2_config = {
        kPORT_PullDisable,
        kPORT_LowPullResistor,
        kPORT_FastSlewRate,
        kPORT_PassiveFilterDisable,
        kPORT_OpenDrainDisable,
        kPORT_LowDriveStrength,
        kPORT_MuxAlt5,            // ALT5 = PWM1_B0 (J3-13)
        kPORT_InputBufferEnable,
        kPORT_InputNormal,
        kPORT_UnlockRegister
    };
    PORT_SetPinConfig(PORT2, 7U, &port2_7_pinL2_config);

    /* ==== Config básica del PWM ==== */
    pwm_config_t pwmConfig;
    PWM_GetDefaultConfig(&pwmConfig);

    pwmConfig.reloadLogic   = kPWM_ReloadImmediate;
    pwmConfig.pairOperation = kPWM_Independent;
    pwmConfig.prescale      = kPWM_Prescale_Divide_16;

    PWM_Init(PWM1, kPWM_Module_0, &pwmConfig);

    /* ==== Señales A y B al 50 % para prueba ==== */
    pwm_signal_param_t pwmSignals[2];

    pwmSignals[0].pwmChannel       = kPWM_PwmA;
    pwmSignals[0].level            = kPWM_HighTrue;
    pwmSignals[0].dutyCyclePercent = 50;
    pwmSignals[0].deadtimeValue    = 0;
    pwmSignals[0].faultState       = kPWM_PwmFaultState0;
    pwmSignals[0].pwmchannelenable = true;

    pwmSignals[1].pwmChannel       = kPWM_PwmB;
    pwmSignals[1].level            = kPWM_HighTrue;
    pwmSignals[1].dutyCyclePercent = 50;
    pwmSignals[1].deadtimeValue    = 0;
    pwmSignals[1].faultState       = kPWM_PwmFaultState0;
    pwmSignals[1].pwmchannelenable = true;

    uint32_t pwmFreq  = 200U;                       // Hz
    uint32_t srcClock = CLOCK_GetFreq(kCLOCK_BusClk);

    PWM_SetupPwm(PWM1,
                 kPWM_Module_0,
                 pwmSignals,
                 2,
                 kPWM_EdgeAligned,
                 pwmFreq,
                 srcClock);

    /* Cargar registros */
    PWM_SetPwmLdok(PWM1, (1U << kPWM_Module_0), true);

    /* *** HABILITAR SALIDAS A y B *** */
    PWM_OutputEnable(PWM1,
                     kPWM_PwmA | kPWM_PwmB,
                     kPWM_Module_0);

    /* Arrancar el temporizador */
    PWM_StartTimer(PWM1, (1U << kPWM_Module_0));
}



void LinePressure_SetDuty(void)
{
    uint16 duty = 0;

    Read_PWM_LinePressure(&duty);
    if (duty > 100) duty = 100;

    PWM_UpdatePwmDutycycle(PWM1,
                           kPWM_Module_0,
                           kPWM_PwmA,
                           kPWM_EdgeAligned,
                           duty);

    PWM_SetPwmLdok(PWM1, 1U << kPWM_Module_0, true);
}

void TCCPressure_SetDuty(void)
{
    uint16 duty = 0;

    Read_PWM_TCC(&duty);
    if (duty > 100) duty = 100;

    PWM_UpdatePwmDutycycle(PWM1,
                           kPWM_Module_0,
                           kPWM_PwmB,
                           kPWM_EdgeAligned,
                           duty);

    PWM_SetPwmLdok(PWM1, 1U << kPWM_Module_0, true);
}
