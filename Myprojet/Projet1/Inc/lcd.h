#include "stm32f4xx_hal.h"

#define D0 GPIO_PIN_0
#define D1 GPIO_PIN_1
#define D2 GPIO_PIN_2
#define D3 GPIO_PIN_3

#define RS GPIO_PIN_4
#define RW GPIO_PIN_5
#define EN GPIO_PIN_6

#define LCDEnvoi() 	HAL_GPIO_WritePin(GPIOC, EN, 1);\
										HAL_GPIO_WritePin(GPIOC, EN, 0);

void LCDInit(void);
void LCDCommande(uint16_t mycmd);
void LCDDonnee(uint16_t mydata);
void LCDClear(void);
void LCDGoto(uint8_t Ln, uint8_t Cl);
void LCDChaine(const char *Chaine);