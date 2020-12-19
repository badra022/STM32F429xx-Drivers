/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 27/8/2020				*************/
/*********** Version	: V01					*************/
/************************************************************/
#include"STD_types.h"
#include"MATH_macros.h"
#include "STM32f429xx.h"

#include "SYSCFG_interface.h"
#include "SYSCFG_private.h"
#include "SYSCFG_config.h"

/************************************************************/
/*						FUNCTION DEFINITIONS				*/
/************************************************************/
void MSYSCFG_voidExtIConfiguration(u8 copy_u8Line, u8 copy_u8PortMap)
{
	u8 local_u8RegisterIndex = 0;

	if(copy_u8Line <= 3)
	{
		local_u8RegisterIndex = 0;
	}
	else if(copy_u8Line <= 7)
	{
		local_u8RegisterIndex = 1;
		copy_u8Line %= 4;
	}
	else if(copy_u8Line <= 11)
	{
		local_u8RegisterIndex = 2;
		copy_u8Line %= 4;
	}
	else if(copy_u8Line <= 15)
	{
		local_u8RegisterIndex = 3;
		copy_u8Line %= 4;
	}

	SYSCFG->EXTICR[local_u8RegisterIndex] &= ~( 0xF << (copy_u8Line * 4));
	SYSCFG->EXTICR[local_u8RegisterIndex] |= ( copy_u8PortMap << (copy_u8Line * 4));
}

void MSYSCFG_voidEnableCompensationCell(void)
{
	/* enabling the SYSCFG for the compensation cell control register */
	RCC_voidEnableClock(RCC_APB2, RCC_SYSCFG_EN);

	/* enable the CMP CELL */
	SYSCFG->CMPCR |= 1;

	/* wait till it will be ready */
	while((SYSCFG->CMPCR & 0x00000100) != 0x00000100){}
}
