/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 24/9/2020				*************/
/*********** Version	: V01					*************/
/************************************************************/

/************************************************************/
/*							INCLUDES						*/
/************************************************************/
#include"STD_types.h"
#include"MATH_macros.h"

#include "SYSTICK_interface.h"

#include "OS_interface.h"
#include "OS_config.h"
#include "OS_private.h"


/************************************************************/
/*						FUNCTION DEFINITIONS				*/
/************************************************************/
void SOS_voidCreateTask(u8 Copy_u8TaskID,u16 period,void (*ptr)(void),u16 Copy_u16firstDelay)
{
	OStasks[Copy_u8TaskID].Period = period;
	OStasks[Copy_u8TaskID].TaskHandler = ptr;
	OStasks[Copy_u8TaskID].firstDelay = Copy_u16firstDelay;
	OStasks[Copy_u8TaskID].State = TASK_READY;
}

void SOS_voidStart(void)
{
	MSTK_voidInit();

	/*when HSE=8Mhz , sytem tick is 1ms*/
	MSTK_SetIntervalPeriodic(1000 , SCHEDULER );

}

void SOS_voidSuspendTask(u8 Copy_u8TaskID)
{
	OStasks[Copy_u8TaskID].State=TASK_SUSPENDED;
}

void SOS_voidResumeTask(u8 Copy_u8TaskID)
{
	OStasks[Copy_u8TaskID].State=TASK_READY;
}

void SOS_voidDeleteTask(u8 Copy_u8TaskID)
{
	OStasks[Copy_u8TaskID].TaskHandler=NULL;
}
