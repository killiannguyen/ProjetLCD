#include "lcd.h"

void LCDInit(void)
{
	LCDCommande(0x03);
	LCDCommande(0x02);
	LCDCommande(0x28);
	LCDCommande(0x08);
	LCDCommande(0x0F);
	LCDCommande(0x06);
	LCDCommande(0x00);
	LCDCommande(0x01);
}

void LCDCommande(uint16_t mycmd)
{
	HAL_GPIO_WritePin(GPIOC, RS, 0);
	HAL_GPIO_WritePin(GPIOC, RW, 0);
	
	GPIOC->ODR = ((GPIOC->ODR & 0x00F0)|(mycmd>>4));
	LCDEnvoi();
	HAL_Delay(1);
	
	GPIOC->ODR = ((GPIOC->ODR & 0x00F0)|(mycmd & 0x000F));
	LCDEnvoi();
	HAL_Delay(2);
}

void LCDDonnee(uint16_t mydata)
{
	HAL_GPIO_WritePin(GPIOC, RS, 1);
	HAL_GPIO_WritePin(GPIOC, RW, 0);
	
	GPIOC->ODR = ((GPIOC->ODR & 0x00F0)|(mydata>>4));
	LCDEnvoi();
	HAL_Delay(1);
	
	GPIOC->ODR = ((GPIOC->ODR & 0x00F0)|(mydata & 0x000F));
	LCDEnvoi();
	HAL_Delay(2);
}

void LCDClear(void)
{
	LCDCommande(0x01);
}

void LCDGoto(uint8_t Ln, uint8_t Cl)
{
	if((Ln > 1) || (Cl > 15))
		return;
	LCDCommande((Ln == 1) ? (0xC0 | Cl) : (0x80 | Cl)); 
}

void LCDChaine(const char *Chaine)
{
	uint8_t i = 0;                                     // Char index buffer                                                                                                                                                                                                                                                              
  while (Chaine[i])                                   // While string not finished
    LCDDonnee(Chaine[i++]);                          // Go display current char
}
