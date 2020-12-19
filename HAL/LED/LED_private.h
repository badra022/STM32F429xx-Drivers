/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 30/8/2020				*************/
/*********** Version	: V01					*************/
/************************************************************/

/************************************************************/
/*			GUARD FILE TO PREVENT MULTIPLE INCLUSION		*/
/************************************************************/
#ifndef _LED_PRIVATE_H_
#define _LED_PRIVATE_H_

#define USER_GREEN_LED_BITBAND		*((volatile u32*)(BITBAND_PERI((u32)(&(GPIOG->ODR)), 13)))
#define USER_RED_LED_BITBAND		*((volatile u32*)(BITBAND_PERI((u32)(&(GPIOG->ODR)), 14)))

#endif /* _LED_PRIVATE_H_ */