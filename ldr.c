#include "ldr.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_adc.h"
#include "stm32f4xx_hal_gpio.h"

extern ADC_HandleTypeDef hadc1;

void LDR_Init(void)
{
    (void)HAL_ADC_Start(&hadc1);
}

uint16_t LDR_Read(void)
{
    HAL_StatusTypeDef status;
    uint16_t adc_value = 0U;

    status = HAL_ADC_Start(&hadc1);
    if (status == HAL_OK)
    {
        status = HAL_ADC_PollForConversion(&hadc1, 10U);
        if (status == HAL_OK)
        {
            adc_value = (uint16_t)HAL_ADC_GetValue(&hadc1);
        }
    }

    (void)HAL_ADC_Stop(&hadc1);

    return adc_value;
}