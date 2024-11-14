/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Peripherals v15.0
processor: LPC55S69
package_id: LPC55S69JBD100
mcu_data: ksdk2_0
processor_version: 16.3.0
functionalGroups:
- name: BOARD_InitPeripherals
  UUID: b6a905f1-efe8-415c-a5d7-501252de7c4a
  called_from_default_init: true
  selectedCore: cm33_core0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'system'
- type_id: 'system'
- global_system_definitions:
  - user_definitions: ''
  - user_includes: ''
  - global_init: ''
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'uart_cmsis_common'
- type_id: 'uart_cmsis_common'
- global_USART_CMSIS_common:
  - quick_selection: 'default'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'gpio_adapter_common'
- type_id: 'gpio_adapter_common'
- global_gpio_adapter_common:
  - quick_selection: 'default'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "peripherals.h"

/***********************************************************************************************************************
 * BOARD_InitPeripherals functional group
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * NVIC initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'NVIC'
- type: 'nvic'
- mode: 'general'
- custom_name_enabled: 'false'
- type_id: 'nvic'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'NVIC'
- config_sets:
  - nvic:
    - interrupt_table:
      - 0: []
    - interrupts: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/* Empty initialization function (commented out)
static void NVIC_init(void) {
} */

/***********************************************************************************************************************
 * CTIMER1 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'CTIMER1'
- type: 'ctimer'
- mode: 'Capture_Match'
- custom_name_enabled: 'false'
- type_id: 'ctimer_2.2.2'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'CTIMER1'
- config_sets:
  - fsl_ctimer:
    - ctimerConfig:
      - mode: 'kCTIMER_TimerMode'
      - clockSource: 'FunctionClock'
      - clockSourceFreq: 'ClocksTool_DefaultInit'
      - timerPrescaler: '1000Hz'
    - EnableTimerInInit: 'false'
    - matchChannels:
      - 0:
        - matchChannelPrefixId: 'Match_0'
        - matchChannel: 'kCTIMER_Match_0'
        - matchValueStr: '10Hz'
        - enableCounterReset: 'true'
        - enableCounterStop: 'false'
        - outControl: 'kCTIMER_Output_NoAction'
        - outPinInitValue: 'low'
        - enableInterrupt: 'true'
    - captureChannels: []
    - interruptCallbackConfig:
      - interrupt:
        - IRQn: 'CTIMER1_IRQn'
        - enable_priority: 'false'
        - priority: '0'
      - callback: 'kCTIMER_SingleCallback'
      - singleCallback: 'TimerIRQ'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const ctimer_config_t CTIMER1_config = {
  .mode = kCTIMER_TimerMode,
  .input = kCTIMER_Capture_0,
  .prescale = 149999
};
const ctimer_match_config_t CTIMER1_Match_0_config = {
  .matchValue = 99,
  .enableCounterReset = true,
  .enableCounterStop = false,
  .outControl = kCTIMER_Output_NoAction,
  .outPinInitState = false,
  .enableInterrupt = true
};
/* Single callback functions definition */
ctimer_callback_t CTIMER1_callback[] = {TimerIRQ};

static void CTIMER1_init(void) {
  /* CTIMER1 peripheral initialization */
  CTIMER_Init(CTIMER1_PERIPHERAL, &CTIMER1_config);
  /* Match channel 0 of CTIMER1 peripheral initialization */
  CTIMER_SetupMatch(CTIMER1_PERIPHERAL, CTIMER1_MATCH_0_CHANNEL, &CTIMER1_Match_0_config);
  CTIMER_RegisterCallBack(CTIMER1_PERIPHERAL, CTIMER1_callback, kCTIMER_SingleCallback);
}

/***********************************************************************************************************************
 * CTIMER2 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'CTIMER2'
- type: 'ctimer'
- mode: 'PWM'
- custom_name_enabled: 'false'
- type_id: 'ctimer_2.2.2'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'CTIMER2'
- config_sets:
  - fsl_ctimer:
    - ctimerConfig:
      - mode: 'kCTIMER_TimerMode'
      - clockSource: 'FunctionClock'
      - clockSourceFreq: 'ClocksTool_DefaultInit'
      - timerPrescaler: '20000Hz'
    - EnableTimerInInit: 'false'
    - pwmConfig:
      - pwmPeriodChannel: 'kCTIMER_Match_1'
      - pwmPeriodValueStr: '1/2Hz'
      - enableInterrupt: 'false'
      - pwmChannels:
        - 0:
          - pwmChannelPrefixId: 'PWM_0'
          - pwmChannel: 'kCTIMER_Match_2'
          - pwmDutyValueStr: '1'
          - enableInterrupt: 'false'
    - interruptCallbackConfig:
      - interrupt:
        - IRQn: 'CTIMER2_IRQn'
        - enable_priority: 'false'
        - priority: '0'
      - callback: 'kCTIMER_SingleCallback'
      - singleCallback: 'CTIMER2_IRQ'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const ctimer_config_t CTIMER2_config = {
  .mode = kCTIMER_TimerMode,
  .input = kCTIMER_Capture_0,
  .prescale = 7499
};

static void CTIMER2_init(void) {
  /* CTIMER2 peripheral initialization */
  CTIMER_Init(CTIMER2_PERIPHERAL, &CTIMER2_config);
  /* PWM channel 2 of CTIMER2 peripheral initialization */
  CTIMER_SetupPwmPeriod(CTIMER2_PERIPHERAL, CTIMER2_PWM_PERIOD_CH, CTIMER2_PWM_0_CHANNEL, CTIMER2_PWM_PERIOD, CTIMER2_PWM_0_DUTY, false);
}

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/
void BOARD_InitPeripherals(void)
{
  /* Initialize components */
  CTIMER1_init();
  CTIMER2_init();
}

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void)
{
  BOARD_InitPeripherals();
}
