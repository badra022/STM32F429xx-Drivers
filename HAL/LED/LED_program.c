/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 30/8/2020				*************/
/*********** Version	: V01					*************/
/************************************************************/

/************************************************************/
/*							INCLUDES						*/
/************************************************************/
#include"STD_types.h"
#include"MATH_macros.h"
#include "STM32f429xx.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

/************************************************************/
/*						FUNCTION DEFINITIONS				*/
/************************************************************/
void HLED_voidTurnON(Led_TypeId copy_ID)
{
	switch(copy_ID)
	{
	case USER_GREEN_LED:
		MGPIO_voidSetPinValue(GPIOG, P13, HIGH);
		break;
	case USER_RED_LED:
		MGPIO_voidSetPinValue(GPIOG, P14, HIGH);
		break;
	}
}

void HLED_init(Led_TypeId copy_ID)
{
    /* Enable port G (LEDs) clock */
    RCC_voidEnableClock(RCC_AHB1, RCC_GPIOG_EN);
	// RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;

	MSYSCFG_voidEnableClock();
	MSYSCFG_voidEnableCompensationCell();
	
	switch(copy_ID)
	{
	case USER_GREEN_LED:
		MGPIO_voidSetPinDirection(GPIOG, P13, OUTPUT, PUSH_PULL, VERY_HIGH_SPEED, NONE);
		break;
	case USER_RED_LED:
		MGPIO_voidSetPinDirection(GPIOG, P14, OUTPUT, PUSH_PULL, VERY_HIGH_SPEED, NONE);
		break;
	}
}

void HLED_voidTurnOFF(Led_TypeId copy_ID)
{
	switch(copy_ID)
	{
	case USER_GREEN_LED:
		MGPIO_voidSetPinValue(GPIOG, P13, LOW);
		break;
	case USER_RED_LED:
		MGPIO_voidSetPinValue(GPIOG, P14, LOW);
		break;
	}
}
