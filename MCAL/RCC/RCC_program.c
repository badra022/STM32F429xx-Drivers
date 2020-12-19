/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 14/8/2020				*************/
/*********** Version	: V01					*************/
/*********** Brief		: RCC func defs			*************/
/************************************************************/

/************************************************************/
/*							INCLUDES						*/
/************************************************************/
#include"STD_types.h"
#include"MATH_macros.h"
#include "STM32f429xx.h"

#include"RCC_interface.h"
#include"RCC_private.h"
#include"RCC_config.h"

/************************************************************/
/*						FUNCTION DEFINITIONS				*/
/************************************************************/

/***************************************************************************/
/****	Brief	:	initiates the system clock as the user configured 	****/
/**** 	Return	:	None												****/
/****	param	:	None												****/
/***************************************************************************/
void RCC_initSystemClock(void)
{
	/* reset clock interrupt register (initially no interrupts set) */
	RCC_CIR = 0x00000000;
	
	/* set the configured bits in RCC_CFGR as the user confifured */
	RCC_CFGR = (SYSCLK_AHP_PRESCALER << 4)
				| (AHB_TO_APB2_PRESCALER << 13)
				| (AHB_TO_APB1_PRESCALER << 10)
				| (MCO1_CLOCK_SOURCE << 21)
				| (RTC_PRESCALER << 16)
				| (MCO1_PRESCALER << 24)
				| (MCO2_PRESCALER << 27)
				| (MCO2_CLOCK_SOURCE << 30);
				
	#if(RCC_SYSTEM_CLOCK == RCC_HSI)
		/* set the HSI ON */
		RCC_CR |= 0x00000001;
		
		/* set HSI as the system clock */
		RCC_CFGR |= 0x00000000;
	#elif(RCC_SYSTEM_CLOCK == RCC_HSE_CRYSTAL)
		/* set the HSE ON */
		/* and set the CSS ON as configured */
		RCC_CR |= (0x00010000 | (CLOCK_SECURITY_SYSTEM << 19));
		
		/* set HSE as the system clock */
		RCC_CFGR |= 0x00000001;
	#elif(RCC_SYSTEM_CLOCK == RCC_HSE_RC)
		/* set the HSE ON and set PYPASS bit */
		/* and set the CSS ON as configured */
		RCC_CR |= (0x00050000 | (CLOCK_SECURITY_SYSTEM << 19));
		
		/* set HSE as the system clock */
		RCC_CFGR |= 0x00000001;
	#elif(RCC_SYSTEM_CLOCK == RCC_PLL)

		/* set PLL equation factors M, N, Q, P */
		RCC_PLLCFGR = (PLL_M) | (PLL_N << 6) | (PLL_P << 16)
					| (PLL_Q << 24);

		#if(PLL_PLLI2S_SOURCE == PLL_HSI)
			/* set the HSI ON and PLL ON */
			RCC_CR |= (0x01000001 | (CLOCK_SECURITY_SYSTEM << 19));
			
			/* set HSI as the clock source for PLL */
			 RCC_PLLCFGR |= PLL_PLLI2S_SOURCE << 22;

			/* set PLL as the system clock */
			RCC_CFGR |= 0x00000002;
		#elif(PLL_SOURCE == PLL_HSE_CRYSTAL)
			/* set the HSE ON and PLL ON */
			RCC_CR |= (0x01010000 | (CLOCK_SECURITY_SYSTEM << 19));
			
			/* set HSI as the clock source for PLL */
			 RCC_PLLCFGR |= PLL_PLLI2S_SOURCE << 22;

			/* set PLL as the system clock */
			RCC_CFGR |= 0x00000002;
		#endif

#endif
}

/***************************************************************************/
/****	Brief	:	enable the clock for the periphral passed(pinId) 	****/
/**** 	Return	:	None												****/
/****	param	:	bus id (AHP,APB1,APB2) and pin number to write		****/
/***************************************************************************/
void RCC_voidEnableClock(u8 copy_busId, u8 copy_pinId)
{
	if(copy_pinId <= 31)
	{
		/* the inserted pin number is accessible in 32bit registers */
		/* now depending on the busId, we will select the register to write to */
		switch(copy_busId)
		{
			case RCC_AHB1:	SET_BIT(RCC_AHB1ENR, copy_pinId);	break;
			case RCC_AHB2:	SET_BIT(RCC_AHB2ENR, copy_pinId);	break;
			case RCC_AHB3:	SET_BIT(RCC_AHB3ENR, copy_pinId);	break;
			case RCC_APB1:	SET_BIT(RCC_APB1ENR, copy_pinId);	break;
			case RCC_APB2:	SET_BIT(RCC_APB2ENR, copy_pinId);	break;
		}
	}
	else
	{
		/* throw an access error */
	}
}

/***************************************************************************/
/****	Brief	:	disable the clock for the periphral passed(pinId) 	****/
/**** 	Return	:	None												****/
/****	param	:	bus id (AHP,APB1,APB2) and pin number to write		****/
/***************************************************************************/
void RCC_voidDisableClock(u8 copy_busId, u8 copy_pinId)
{
	if(copy_pinId <= 31)
		{
			/* the inserted pin number is accessible in 32bit registers */
			/* now depending on the busId, we will select the register to write to */
			switch(copy_busId)
			{
				case RCC_AHB1:	CLR_BIT(RCC_AHB1ENR, copy_pinId);	break;
				case RCC_AHB2:	CLR_BIT(RCC_AHB2ENR, copy_pinId);	break;
				case RCC_AHB3:	CLR_BIT(RCC_AHB3ENR, copy_pinId);	break;
				case RCC_APB1:	CLR_BIT(RCC_APB1ENR, copy_pinId);	break;
				case RCC_APB2:	CLR_BIT(RCC_APB2ENR, copy_pinId);	break;
			}
		}
		else
		{
			/* throw an access error */
		}
}

/***************************************************************************/
/****	Brief	:	read the SWS value to indicate the system clock type****/
/**** 	Return	:	0 -> HSI , 1 -> HSE , 2 -> PLL						****/
/****	param	:	None												****/
/***************************************************************************/
u8 RCC_u8GetSystemClockType(void)
{
	return (RCC_CFGR >> 2) & 0b11;
}
