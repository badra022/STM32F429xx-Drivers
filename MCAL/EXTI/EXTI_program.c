/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 23/8/2020				*************/
/*********** Version	: V03					*************/
/************************************************************/
#include"STD_types.h"
#include"MATH_macros.h"
#include "STM32f429xx.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

/************************************************************/
/*						FUNCTION DEFINITIONS				*/
/************************************************************/

void MEXTI_voidEnableExti(u8 copy_u8Line)
{
	SET_BIT(EXTI->IMR, copy_u8Line);
}
void MEXTI_voidDisableExti(u8 copy_u8Line)
{
	CLR_BIT(EXTI->IMR, copy_u8Line);
}
void MEXTI_voidSwTrigger(u8 copy_u8Line)
{
	SET_BIT(EXTI->SWIER, copy_u8Line);
}

void MEXTI_voidSelectTriggerSignal(u8 copy_u8Line, u8 copy_u8Mode)
{
	switch(copy_u8Mode)
	{
		case RISING		:SET_BIT(EXTI->RTSR, copy_u8Line); break;
		case FALLING	:SET_BIT(EXTI->FTSR, copy_u8Line); break;
		case ON_CHANGE	:SET_BIT(EXTI->FTSR, copy_u8Line);
						 SET_BIT(EXTI->RTSR, copy_u8Line); break;
	}
}

void MEXTI_voidResetPendingFlag(u8 copy_u8Line)
{
	SET_BIT(EXTI->PR, copy_u8Line);
}

/*
void MEXTI_voidGetPendingFlag(u8 copy_u8Line)
{
	GET_BIT(EXTI->PR, copy_u8Line);
}*/