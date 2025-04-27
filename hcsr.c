#include "hcsr.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_adc.h"
#include "stm32f4xx_hal_gpio.h"


extern TIM_HandleTypeDef htim1;
uint32_t ic_val1 = 0, ic_val2 = 0;
uint8_t is_first_captured = 0;
uint32_t difference = 0;
float distance = 0;

void HCSR_Init(void)
{
    HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_1);  // Start Input Capture Interrupt
}

void HCSR_Trigger(void)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
    HAL_Delay(1);  // 10 us
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
}

float HCSR_GetDistance(void)
{
    return distance;
}

// Call this in HAL_TIM_IC_CaptureCallback
void HCSR_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
    {
        if (is_first_captured == 0)
        {
            ic_val1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
            is_first_captured = 1;
            __HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
        }
        else
        {
            ic_val2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
            __HAL_TIM_SET_COUNTER(htim, 0);

            if (ic_val2 > ic_val1)
                difference = ic_val2 - ic_val1;
            else
                difference = (0xFFFF - ic_val1 + ic_val2);

            distance = (float)difference * 0.034 / 2;
            is_first_captured = 0;
            __HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
        }
    }
}
