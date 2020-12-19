/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 30/8/2020				*************/
/*********** Version	: V02					*************/
/************************************************************/


/************************************************************/
/*							INCLUDES						*/
/************************************************************/
#include"STD_types.h"
#include"MATH_macros.h"
#include "STM32f429xx.h"

#include"SYSTICK_interface.h"
#include"SYSTICK_private.h"
#include"SYSTICK_config.h"

static void (* volatile g_StkCallBackFunction)(void) = NULL;

/************************************************************/
/*						FUNCTION DEFINITIONS				*/
/************************************************************/

static void MSTK_voidSetCallBackFunction(void (*copy_ptr)(void))
{
	g_StkCallBackFunction = copy_ptr;
}

static void MSTK_voidInit(void)
{
	/* choose the clock and enable the peripheral's interrupt */
	#if(SYSTICK_INTERRUPT_USED == TRUE)
		SysTick->CTRL = CLOCK_SOURCE | 0x02;
	#else
		SysTick->CTRL = CLOCK_SOURCE;
	#endif
	
}
void MSTK_voidSetBusyWait(u32 copy_u32Ticks)
{
	/* set the load register */
	if(copy_u32Ticks < 0xFFFFFF)
	{
		SysTick->LOAD = copy_u32Ticks;
	}
	/* start the count down (using or not using interrupt)*/
	SysTick->CTRL |= 0x01;
	while(!(SysTick->CTRL >> COUNTFLAG_BIT)){}
	return;
}

#if(SYSTICK_INTERRUPT_USED == TRUE)

void MSTK_SetIntervalSingle(u32 copy_u32Ticks, void (*copy_ptr) (void))
{
	/* set the load register */
	if(copy_u32Ticks < 0xFFFFFF)
	{
		SysTick->LOAD = copy_u32Ticks;
	}
	/* set the call back function in the ISR */
	MSTK_voidSetCallBackFunction(copy_ptr);
	
	/* start the count down (using or not using interrupt)*/
	SysTick->CTRL |= 0x01;
	
}
void MSTK_SetIntervalPeriodic(u32 copy_u32Ticks, void (*copy_ptr) (void))
{
		/* set the load register */
	if(copy_u32Ticks < 0xFFFFFF)
	{
		SysTick->LOAD = copy_u32Ticks - 1;
	}
	/* set the call back function in the ISR */
	MSTK_voidSetCallBackFunction(copy_ptr);
	
	/* start the count down (using or not using interrupt)*/
	SysTick->CTRL |= 0x01;
	
}
void MSTK_voidStopTimer(void)
{
	SysTick->CTRL &= ~1;	
}

u32  MSTK_u32GetRemainingTime(void)
{
	return SysTick->VALUE;
}

u32  MSTK_u32GetElapsedTime(void)
{
	return ((u32)SysTick->LOAD - (u32)SysTick->VALUE);
}
#endif

void SysTick_Handler(void)
{
	if(g_StkCallBackFunction != NULL)
	{
		g_StkCallBackFunction();
	}
}