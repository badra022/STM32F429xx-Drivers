/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 27/8/2020				*************/
/*********** Version	: V01					*************/
/*********** Brief		: sysCFG interface file	*************/
/************************************************************/

/************************************************************/
/*			GUARD FILE TO PREVENT MULTIPLE INCLUSION		*/
/************************************************************/
#ifndef _SYSCFG_INTERFACE_H_
#define _SYSCFG_INTERFACE_H_

/************************************************************/
/*				FUNCTION PARAMETERS DEFINITIONS				*/
/************************************************************/
#define SYSCFG_GPIOA		0
#define SYSCFG_GPIOB		1
#define SYSCFG_GPIOC		2
#define SYSCFG_GPIOD		3
#define SYSCFG_GPIOE		4
#define SYSCFG_GPIOF		5
#define SYSCFG_GPIOG		6
#define SYSCFG_GPIOH		7
#define SYSCFG_GPIOI		8
#define SYSCFG_GPIOJ		9
#define SYSCFG_GPIOK		10


#define RCC_SYSCFG_EN		14

/************************************************************/
/*						FUNCTION PROTOTYPES					*/
/************************************************************/

void MSYSCFG_voidExtIConfiguration(u8 copy_u8Line, u8 copy_u8PortMap);
void MSYSCFG_voidEnableCompensationCell(void);

#endif
