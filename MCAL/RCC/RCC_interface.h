/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 14/8/2020				*************/
/*********** Version	: V01					*************/
/*********** Brief		: RCC func prototypes	*************/
/************************************************************/

/************************************************************/
/*			GUARD FILE TO PREVENT MULTIPLE INCLUSION		*/
/************************************************************/

#ifndef	_RCC_INTERFACE_
#define	_RCC_INTERFACE_

/************************************************************/
/*				FUNCTIONS PARAMETERS DEFINITIONS			*/
/************************************************************/
#define	RCC_AHB1		0
#define	RCC_AHB2		1
#define	RCC_AHB3		2
#define	RCC_APB1		3
#define	RCC_APB2		4


/************************************************************/
/*						FUNCTION PROTOTYPES					*/
/************************************************************/

/***************************************************************************/
/****	Brief	:	enable the clock for the periphral passed(pinId) 	****/
/**** 	Return	:	None												****/
/****	param	:	bus id (AHP,APB1,APB2) and pin number to write		****/
/***************************************************************************/
void RCC_voidEnableClock(u8 copy_busId, u8 copy_pinId);

/***************************************************************************/
/****	Brief	:	initiates the system clock as the user configured 	****/
/**** 	Return	:	None												****/
/****	param	:	None												****/
/***************************************************************************/
void RCC_initSystemClock(void);

/***************************************************************************/
/****	Brief	:	disable the clock for the periphral passed(pinId) 	****/
/**** 	Return	:	None												****/
/****	param	:	bus id (AHP,APB1,APB2) and pin number to write		****/
/***************************************************************************/
void RCC_voidDisableClock(u8 copy_busId, u8 copy_pinId);

/***************************************************************************/
/****	Brief	:	read the SWS value to indicate the system clock type****/
/**** 	Return	:	SWS value (0 -> 3)									****/
/****	param	:	None												****/
/***************************************************************************/
u8 RCC_u8GetSystemClockType(void);
#endif
