#include "LED.h"
#include "stm32f4xx_hal.h"

void LEDInit(void)
{

}

void LEDToggle(void)
{
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}