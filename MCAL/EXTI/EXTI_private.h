/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 23/8/2020				*************/
/*********** Version	: V02					*************/
/************************************************************/

/************************************************************/
/*			GUARD FILE TO PREVENT MULTIPLE INCLUSION		*/
/************************************************************/
#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_

typedef struct {
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
	
}EXTI_TypeDef;

#define EXTI_PERIPHERAL_BASE	0x40013C00
#define EXTI	((volatile EXTI_TypeDef*)EXTI_PERIPHERAL_BASE) 

#endif
