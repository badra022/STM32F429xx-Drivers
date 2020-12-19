/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 30/8/2020				*************/
/*********** Version	: V02					*************/
/************************************************************/


/************************************************************/
/*			GUARD FILE TO PREVENT MULTIPLE INCLUSION		*/
/************************************************************/
#ifndef _SYSTICK_INTERFACE_H_
#define _SYSTICK_INTERFACE_H_

/************************************************************/
/*						FUNCTION PROTOTYPES					*/
/************************************************************/

void MSTK_voidInit(void);
void MSTK_voidSetBusyWait(u32 copy_u32Ticks);
void MSTK_SetIntervalSingle(u32 copy_u32Ticks, void (*copy_ptr) (void));
void MSTK_SetIntervalPeriodic(u32 copy_u32Ticks, void (*copy_ptr) (void));
void MSTK_voidStopTimer(void);
u32  MSTK_u32GetRemainingTime(void);
u32  MSTK_u32GetElapsedTime(void);

#endif