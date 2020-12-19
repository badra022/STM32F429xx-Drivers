/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 23/8/2020				*************/
/*********** Version	: V02					*************/
/************************************************************/

/************************************************************/
/*			GUARD FILE TO PREVENT MULTIPLE INCLUSION		*/
/************************************************************/
#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_

#define LINE0		0
#define LINE1		1
#define LINE2		2
#define LINE3		3
#define LINE4		4
#define LINE5		5
#define LINE6		6
#define LINE7		7
#define LINE8		8
#define LINE9		9
#define LINE10		10
#define LINE11		11
#define LINE12		12
#define LINE13		13
#define LINE14		14
#define LINE15		15

#define RISING		0
#define FALLING 	1
#define ON_CHANGE	2

/************************************************************/
/*						FUNCTION PROTOTYPES					*/
/************************************************************/

void MEXTI_voidEnableExti(u8 copy_u8Line);
void MEXTI_voidDisableExti(u8 copy_u8Line);
void MEXTI_voidSwTrigger(u8 copy_u8Line);
void MEXTI_voidSelectTriggerSignal(u8 copy_u8Line, u8 copy_u8Mode);
void MEXTI_voidResetPendingFlag(u8 copy_u8Line);

#endif
