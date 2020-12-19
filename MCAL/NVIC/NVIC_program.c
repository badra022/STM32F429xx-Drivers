/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 23/8/2020				*************/
/*********** Version	: V02					*************/
/************************************************************/
#include"STD_types.h"
#include"MATH_macros.h"
#include "STM32f429xx.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

/************************************************************/
/*						FUNCTION DEFINITIONS				*/
/************************************************************/

/***************************************************************************/
/****	Brief	:	enables the ext interrupt by the NVIC 				****/
/**** 	Return	:	None												****/
/****	param	:	bit number that corresponds to the ext peri			****/
/***************************************************************************/
void MNVIC_voidEnableInterrupt(u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <= 31)
	{
		NVIC_ISER0 = 1 << copy_u8IntNumber;
	}
	else if(copy_u8IntNumber <= 63)
	{
		NVIC_ISER1 = 1 << (copy_u8IntNumber - 32);
	}
	else if(copy_u8IntNumber <= 90)
	{
		NVIC_ISER2 = 1 << (copy_u8IntNumber - 64);
	}
	else
	{
		/* return error */
	}
}

/***************************************************************************/
/****	Brief	:	disables the ext interrupt by the NVIC		 		****/
/**** 	Return	:	None												****/
/****	param	:	bit number that corresponds to the ext peri			****/
/***************************************************************************/
void MNVIC_voidDisableInterrupt(u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <= 31)
	{
		NVIC_ICER0 = 1 << copy_u8IntNumber;
	}
	else if(copy_u8IntNumber <= 63)
	{
		NVIC_ICER1 = 1 << (copy_u8IntNumber - 32);
	}
	else if(copy_u8IntNumber <= 90)
	{
		NVIC_ICER2 = 1 << (copy_u8IntNumber - 64);
	}
	else
	{
		/* return error */
	}
}

/***************************************************************************/
/****	Brief	:	set the pending flag for the ext interrupt by NVIC	****/
/**** 	Return	:	None												****/
/****	param	:	bit number that corresponds to the ext peri			****/
/***************************************************************************/
void MNVIC_voidSetPendingFlag(u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <= 31)
	{
		NVIC_ISPR0 = 1 << copy_u8IntNumber;
	}
	else if(copy_u8IntNumber <= 63)
	{
		NVIC_ISPR1 = 1 << (copy_u8IntNumber - 32);
	}
	else if(copy_u8IntNumber <= 90)
	{
		NVIC_ISPR2 = 1 << (copy_u8IntNumber - 64);
	}
	else
	{
		/* return error */
	}	
}

/***************************************************************************/
/****	Brief	:	reset the pending flag for the ext interrupt by NVIC****/
/**** 	Return	:	None												****/
/****	param	:	bit number that corresponds to the ext peri			****/
/***************************************************************************/
void MNVIC_voidResetPendingFlag(u8 copy_u8IntNumber)
{
	if(copy_u8IntNumber <= 31)
	{
		NVIC_ICPR0 = 1 << copy_u8IntNumber;
	}
	else if(copy_u8IntNumber <= 63)
	{
		NVIC_ICPR1 = 1 << (copy_u8IntNumber - 32);
	}
	else if(copy_u8IntNumber <= 90)
	{
		NVIC_ICPR2 = 1 << (copy_u8IntNumber - 64);
	}
	else
	{
		/* return error */
	}
}

u8 MNVIC_voidGetActiveFlag(u8 copy_u8IntNumber)
{
	u8 Local_u8Result;
	if(copy_u8IntNumber <= 31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0, copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 63)
	{
		copy_u8IntNumber -= 32;
		Local_u8Result = GET_BIT(NVIC_IABR1, copy_u8IntNumber);
	}
	else if(copy_u8IntNumber <= 90)
	{
		copy_u8IntNumber -= 64;
		Local_u8Result = GET_BIT(NVIC_IABR2, copy_u8IntNumber);
	}
	else
	{
		/* return error */
	}
	
	return Local_u8Result;
}

/***************************************************************************/
/****	Brief	:	set the priority as group/sub group passed 			****/
/**** 	Return	:	None												****/
/****	param	:	group/sub-group priority, interrupt id for the NVIC	****/
/***************************************************************************/
void MNVIC_voidSetPriority(s8 copy_s8IntId, u8 copy_u8GroupPriority, u8 copy_u8SubGroupPriority, u32 copy_u32Group)
{
	u8 local_u8Priority = copy_u8SubGroupPriority |( copy_u8GroupPriority << ((copy_u32Group - MNVIC_GROUP3)/0x100));
	/* core peripheral */
	
	/* external peripheral */
	if(copy_s8IntId >= 0)
	{
		NVIC_IPR[copy_s8IntId] = local_u8Priority << 4;
	}
	SCB_AIRCR = copy_u32Group;
}
