/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 19/8/2020				*************/
/*********** Version	: V01					*************/
/************************************************************/

/************************************************************/
/*			GUARD FILE TO PREVENT MULTIPLE INCLUSION		*/
/************************************************************/
#ifndef	_NVIC_PRIVATE_H_
#define	_NVIC_PRIVATE_H_

/* 0xE000E100 Base address */

#define NVIC_PERIPHERAL_BASE	0xE000E100
#define SCB_PERIPHERAL_BASE		0xE000ED00

#define NVIC_ISER0	*((u32*)(NVIC_PERIPHERAL_BASE + 0x100))
#define NVIC_ISER1	*((u32*)(NVIC_PERIPHERAL_BASE + 0x104))
#define NVIC_ISER2	*((u32*)(NVIC_PERIPHERAL_BASE + 0x108))

#define NVIC_ICER0	*((u32*)(NVIC_PERIPHERAL_BASE + 0x180))
#define NVIC_ICER1	*((u32*)(NVIC_PERIPHERAL_BASE + 0x184))
#define NVIC_ICER2	*((u32*)(NVIC_PERIPHERAL_BASE + 0x188))

#define NVIC_ISPR0	*((u32*)(NVIC_PERIPHERAL_BASE + 0x200))
#define NVIC_ISPR1	*((u32*)(NVIC_PERIPHERAL_BASE + 0x204))
#define NVIC_ISPR2	*((u32*)(NVIC_PERIPHERAL_BASE + 0x208))

#define NVIC_ICPR0	*((u32*)(NVIC_PERIPHERAL_BASE + 0x280))
#define NVIC_ICPR1	*((u32*)(NVIC_PERIPHERAL_BASE + 0x284))
#define NVIC_ICPR2	*((u32*)(NVIC_PERIPHERAL_BASE + 0x288))

#define NVIC_IABR0	*((volatile u32*)(NVIC_PERIPHERAL_BASE + 0x300))
#define NVIC_IABR1	*((volatile u32*)(NVIC_PERIPHERAL_BASE + 0x304))
#define NVIC_IABR2	*((volatile u32*)(NVIC_PERIPHERAL_BASE + 0x308))

#define NVIC_IPR	 ((volatile u8*) (NVIC_PERIPHERAL_BASE + 0x400))
#define SCB_AIRCR	*((volatile u32*)(SCB_PERIPHERAL_BASE + 0x0C ))

#endif
