/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 14/8/2020				*************/
/*********** Version	: V01					*************/
/*********** Brief		: RCC private section	*************/
/************************************************************/

/************************************************************/
/*			GUARD FILE TO PREVENT MULTIPLE INCLUSION		*/
/************************************************************/

#ifndef	_RCC_PRIVATE_
#define	_RCC_PRIVATE_

/************************************************************/
/*				BASE ADDRESSES FOR RCC PERIPHERALS			*/
/************************************************************/
#define	RCC_BASE_ADDRESS		0x40023800

/************************************************************/
/*						PERIPHERAL REGISTER DEFINITIONS		*/
/************************************************************/
#define	RCC_CR						*((u32*) RCC_BASE_ADDRESS + 0x00 )
#define	RCC_PLLCFGR					*((u32*) RCC_BASE_ADDRESS + 0x04 )
#define	RCC_CFGR					*((u32*) RCC_BASE_ADDRESS + 0x08 )
#define	RCC_CIR						*((u32*) RCC_BASE_ADDRESS + 0x0C )
#define	RCC_AHB1RSTR				*((u32*) RCC_BASE_ADDRESS + 0x10 )
#define	RCC_AHB2RSTR				*((u32*) RCC_BASE_ADDRESS + 0x14 )
#define	RCC_AHB3RSTR				*((u32*) RCC_BASE_ADDRESS + 0x18 )
#define	RCC_APB1RSTR				*((u32*) RCC_BASE_ADDRESS + 0x20 )
#define	RCC_APB2RSTR				*((u32*) RCC_BASE_ADDRESS + 0x24 )
#define	RCC_AHB1ENR					*((u32*) RCC_BASE_ADDRESS + 0x30 )
#define	RCC_AHB2ENR					*((u32*) RCC_BASE_ADDRESS + 0x34 )
#define	RCC_AHB3ENR					*((u32*) RCC_BASE_ADDRESS + 0x38 )
#define	RCC_APB1ENR					*((u32*) RCC_BASE_ADDRESS + 0x40 )
#define	RCC_APB2ENR					*((u32*) RCC_BASE_ADDRESS + 0x44 )
#define	RCC_AHB1LPENR				*((u32*) RCC_BASE_ADDRESS + 0x50 )
#define	RCC_AHB2LPENR				*((u32*) RCC_BASE_ADDRESS + 0x54 )
#define	RCC_AHB3LPENR				*((u32*) RCC_BASE_ADDRESS + 0x58 )
#define	RCC_APB1LPENR				*((u32*) RCC_BASE_ADDRESS + 0x60 )
#define	RCC_APB2LPENR				*((u32*) RCC_BASE_ADDRESS + 0x64)
#define	RCC_BDCR					*((u32*) RCC_BASE_ADDRESS + 0x70 )
#define	RCC_CSR						*((u32*) RCC_BASE_ADDRESS + 0x74 )
#define	RCC_SSCGR					*((u32*) RCC_BASE_ADDRESS + 0x80 )
#define	RCC_PLLI2SCFGR				*((u32*) RCC_BASE_ADDRESS + 0x84 )
#define	RCC_PLLSAICFGR				*((u32*) RCC_BASE_ADDRESS + 0x88 )
#define	RCC_DCKCFGR					*((u32*) RCC_BASE_ADDRESS + 0x8C )

/************************************************************/
/*					CONFIGURATION STATES DEFINITIONS		*/
/************************************************************/
#define	RCC_HSI				0
#define	RCC_HSE_CRYSTAL		1
#define	RCC_HSE_RC			2
#define	RCC_PLL				3

#define MCO2_SYSTEM_CLOCK	0
#define MCO2_PPLI2S			1
#define MCO2_HSE			2
#define MCO2_MAIN_PLL		3

#define MCO_SOURCE_NO_DIV	0
#define MCO_SOURCE_DIV_2	4
#define MCO_SOURCE_DIV_3	5
#define MCO_SOURCE_DIV_4	6
#define MCO_SOURCE_DIV_5	7

#define	MCO1_HSI			0
#define	MCO1_LSE			1
#define	MCO1_HSE			2
#define	MCO1_MAIN_PLL		3


#define	AHB_APB_NO_PRESCALE	0
#define	AHB_APB_DIV_2		4
#define	AHB_APB_DIV_4		5
#define	AHB_APB_DIV_8		6
#define	AHB_APB_DIV_16		7

#define	SYSCLK_AHP_NO_PRESCALE	0
#define	SYSCLK_AHP_DIV_2		8
#define	SYSCLK_AHP_DIV_4		9
#define	SYSCLK_AHP_DIV_8		10
#define	SYSCLK_AHP_DIV_16		11
#define	SYSCLK_AHP_DIV_64		12
#define	SYSCLK_AHP_DIV_128		13
#define	SYSCLK_AHP_DIV_256		14
#define	SYSCLK_AHP_DIV_512		15


#endif
