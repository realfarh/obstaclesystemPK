#ifndef INC_HCSR_H_
#define INC_HCSR_H_

#include "stm32f4xx_hal.h"

void HCSR_Init(void);
void HCSR_Trigger(void);
float HCSR_GetDistance(void);

#endif /* INC_HCSR_H_ */
