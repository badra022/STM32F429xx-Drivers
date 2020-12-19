/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 11/9/2020				*************/
/*********** Version	: V01					*************/
/************************************************************/

#include"STD_types.h"
#include"MATH_macros.h"
#include "DELAY.h"

#include "GPIO_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"

/************************************************************/
/*						FUNCTION DEFINITIONS				*/
/************************************************************/
void LEDMRX_voidInit(void)
{
	RCC_voidEnableClock(RCC_AHB1, RCC_GPIOA_EN);
	RCC_voidEnableClock(RCC_AHB1, RCC_GPIOB_EN);
	
	for(int i = 0; i < 8 ; i++)
	{
		MGPIO_voidSetPinDirection(GPIOG, P13, OUTPUT, PUSH_PULL, VERY_HIGH_SPEED, NONE);
		MGPIO_voidSetPinDirection(GPIOG, P13, OUTPUT, PUSH_PULL, VERY_HIGH_SPEED, NONE);
	}
}

void LEDMRX_voidDisplay(u8 *copy_u8Data, u8 copy_u8StartIdx)
{
	u8 Local_u8FPS = 50;
	while(Local_u8FPS--)
	{
		for(int i = 0; i < 8 ; i++)
		{
			DisableAllCols();
			MGPIO_voidSetPinValue(LEDMRX_COLS_PORT, i, LOW);
			SetRowsValues(copy_u8FrameData[i]);
			MSTK_voidSetBusyWait(2500); /* 2.5 msec */
		}
	}
}

void LEDMRX_voidDisplayName(u8 *copy_u8Data)
{
	for(int i = 0; i < 22; i++)
	{
		LEDMRX_voidDisplay(copy_u8Data, i);
	}
}

static void SetRowsValues(u8 copy_u8Value)
{
	u8 Local_u8Bit;

	for(int i = 0 ; i < 8 ; i++)
	{
		Local_u8Bit = GET_BIT(copy_u8Value, i);
		MGPIO_voidSetPinValue(LEDMRX_ROWS_PORT, i, Local_u8Bit);	
	}
}

static void DisableAllCols(void)
{
	/* disable all the columns */
	for(int i = 0; i < 8 ; i++)
	{
		MGPIO_voidSetPinValue(LEDMRX_COLS_PORT, i, HIGH);
	}
}
