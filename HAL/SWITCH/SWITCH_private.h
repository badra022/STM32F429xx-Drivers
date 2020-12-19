/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 30/8/2020				*************/
/*********** Version	: V01					*************/
/************************************************************/

/************************************************************/
/*			GUARD FILE TO PREVENT MULTIPLE INCLUSION		*/
/************************************************************/
#ifndef _SWITCH_PRIVATE_H_
#define _SWITCH_PRIVATE_H_

#define USER_BUTTON_BITBAND		*((volatile u32*)(BITBAND_PERI((u32)(&(GPIOA->IDR)), 0)))

#endif /* _SWITCH_PRIVATE_H_ */