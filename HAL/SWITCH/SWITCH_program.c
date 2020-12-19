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

#include "SWITCH_interface.h"
#include "SWITCH_private.h"
#include "SWITCH_config.h"

/************************************************************/
/*						FUNCTION DEFINITIONS				*/
/************************************************************/
bool HButton_BoolReadValue(Button_TypeId copy_ID)
{
	switch(copy_ID)
	{
	case USER_BUTTON:
		return MGPIO_voidGetPinValue(GPIOA, P0)?1:0;
		break;
	}
	return 0;
}

void HButton_voidinit(Button_TypeId copy_ID)
{
    /* Enable port A (switches) clock */
    RCC_voidEnableClock(RCC_AHB1, RCC_GPIOA_EN);
	
	switch(copy_ID)
	{
	case USER_BUTTON:
		MGPIO_voidSetPinDirection(GPIOA, P0, INPUT, 0 , 0, NONE);
		break;
	}
}

