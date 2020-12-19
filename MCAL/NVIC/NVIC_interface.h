/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 19/8/2020				*************/
/*********** Version	: V01					*************/
/************************************************************/

/************************************************************/
/*			GUARD FILE TO PREVENT MULTIPLE INCLUSION		*/
/************************************************************/
#ifndef	_NVIC_INTERFACE_H_
#define	_NVIC_INTERFACE_H_

/************************************************************/
/*						MACROS								*/
/************************************************************/
#define MNVIC_GROUP3		0x05FA0300	// 4 bits for grouping in IPR, No bits for sub grouping
#define MNVIC_GROUP4		0x05FA0400	// 3 bits for grouping in IPR, 1 bits for sub grouping
#define MNVIC_GROUP5		0x05FA0500	// 2 bits for grouping in IPR, 2 bits for sub grouping
#define MNVIC_GROUP6		0x05FA0600	// 1 bits for grouping in IPR, 3 bits for sub grouping
#define MNVIC_GROUP7		0x05FA0700	// No bits for grouping in IPR, 4 bits for sub grouping

/************************************************************/
/*						FUNCTION PROTOTYPES					*/
/************************************************************/

/***************************************************************************/
/****	Brief	:	enables the ext interrupt by the NVIC 				****/
/**** 	Return	:	None												****/
/****	param	:	bit number that corresponds to the ext peri			****/
/***************************************************************************/
void MNVIC_voidEnableInterrupt(u8 copy_u8IntNumber);

/***************************************************************************/
/****	Brief	:	disables the ext interrupt by the NVIC		 		****/
/**** 	Return	:	None												****/
/****	param	:	bit number that corresponds to the ext peri			****/
/***************************************************************************/
void MNVIC_voidDisableInterrupt(u8 copy_u8IntNumber);

/***************************************************************************/
/****	Brief	:	set the pending flag for the ext interrupt by NVIC	****/
/**** 	Return	:	None												****/
/****	param	:	bit number that corresponds to the ext peri			****/
/***************************************************************************/
void MNVIC_voidSetPendingFlag(u8 copy_u8IntNumber);

/***************************************************************************/
/****	Brief	:	reset the pending flag for the ext interrupt by NVIC****/
/**** 	Return	:	None												****/
/****	param	:	bit number that corresponds to the ext peri			****/
/***************************************************************************/
void MNVIC_voidResetPendingFlag(u8 copy_u8IntNumber);

/***************************************************************************/
/****	Brief	:	get the state of the active flag of the ext int		****/
/**** 	Return	:	the state either 0(pending or no int)or 1(executing)****/
/****	param	:	bit number that corresponds to the ext peri			****/
/***************************************************************************/
u8 MNVIC_voidGetActiveFlag(u8 copy_u8IntNumber);

/***************************************************************************/
/****	Brief	:	set the priority as group/sub group passed 			****/
/**** 	Return	:	None												****/
/****	param	:	group/sub-group priority, interrupt id for the NVIC	****/
/***************************************************************************/
void MNVIC_voidSetPriority(s8 copy_s8IntId, u8 copy_u8GroupPriority, u8 copy_u8SubGroupPriority, u32 copy_u32Group);

#endif
