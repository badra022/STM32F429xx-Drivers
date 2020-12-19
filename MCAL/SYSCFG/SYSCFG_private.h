/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 27/8/2020				*************/
/*********** Version	: V01					*************/
/*********** Brief		: sysCFG private regs	*************/
/************************************************************/

/************************************************************/
/*			GUARD FILE TO PREVENT MULTIPLE INCLUSION		*/
/************************************************************/
#ifndef _SYSCFG_PRIVATE_H_
#define _SYSCFG_PRIVATE_H_

typedef struct {
	volatile u32 MEMRMP;
	volatile u32 PMC;
	volatile u32 EXTICR[4];
	volatile u32 CMPCR;
}SYSCFG_TypeDef;

#define SYSCFG_PERIPHERAL_BASE	0x40013800
#define SYSCFG	((volatile SYSCFG_TypeDef* )SYSCFG_PERIPHERAL_BASE)


#endif
