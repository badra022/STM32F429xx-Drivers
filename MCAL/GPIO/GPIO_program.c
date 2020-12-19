/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 30/8/2020				*************/
/*********** Version	: V02					*************/
/************************************************************/

/************************************************************/
/*							INCLUDES						*/
/************************************************************/
#include"STD_types.h"
#include"MATH_macros.h"
#include "STM32f429xx.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

/************************************************************/
/*						FUNCTION DEFINITIONS				*/
/************************************************************/

/***************************************************************************/
/****	Brief	:	output either HIGH or LOW in selected pin 			****/
/**** 	Return	:	None												****/
/****	param	:	the port, the pin number and the value (1/0)		****/
/***************************************************************************/
void MGPIO_voidSetPinValue(GPIO_TypeDef* copy_port, u8 copy_pin, bool copy_value)
{
//	if(copy_value)
//	{
//		copy_port->BSRRL = (1 << copy_pin);
//	}
//	else
//	{
//		copy_port->BSRRH = (1 << copy_pin);
//	}
	if(copy_value)
	{
		*((volatile u32*)BITBAND_PERI((u32)(&(copy_port->ODR)), copy_pin)) = HIGH;
	}
	else
	{
		*((volatile u32*)(BITBAND_PERI((u32)(&(copy_port->ODR)), copy_pin))) = LOW;
	}
}

/***************************************************************************/
/****	Brief	:	configure the selected pin 						 	****/
/**** 	Return	:	None												****/
/****	param	:	the port, the pin number and the configuration		****/
/***************************************************************************/
void MGPIO_voidSetPinDirection(GPIO_TypeDef* copy_port, u8 copy_pin,
		DIO_pinMode copy_mode, DIO_outputType copy_oType,
		DIO_outputSpeed copy_speed, DIO_internalResistance copy_internalRes)
{
	/* setting the mode for the pin passed in the parameters */
	copy_port->MODER &= ~(0b11 << (copy_pin * 2) );
	copy_port->MODER |= (copy_mode << (copy_pin * 2) );

	if(copy_mode == OUTPUT || copy_mode == AF)
	{
		/* setting the type passed in parameters */
		copy_port->OTYPER |= (copy_oType << copy_pin);

		/* setting the speed passed to the function */
		copy_port->OSPEEDR |= (copy_speed << (copy_pin * 2) );
	}
	/* set pull up-down */
	copy_port->PUPDR |= (copy_internalRes << (copy_pin * 2) );

}

/***************************************************************************/
/****	Brief	:	read selected pin								 	****/
/**** 	Return	:	pin's value that is input							****/
/****	param	:	the port and pin number								****/
/***************************************************************************/
bool MGPIO_voidGetPinValue(GPIO_TypeDef* copy_port,u8 copy_pinId)
{
//	if(copy_pinId <= 15)
//	{
//			return GET_BIT(copy_port->IDR, copy_pinId);
//	}
	if(copy_pinId <= 15)
	{
		return *((volatile u32*)BITBAND_PERI((u32)(&(copy_port->IDR)), copy_pinId));
	}
	return ERROR;
}

/***************************************************************************/
/****	Brief	:	set some u8 value in some region of ODR 			****/
/**** 	Return	:	None												****/
/****	param	:	the port, the pin number and the value 				****/
/***************************************************************************/
void MGPIO_voidSetPortValue(GPIO_TypeDef* copy_u8Port, u8 copy_u8StartBit, u8 copy_u8Value)
{
	copy_u8Port->ODR &= ~(0xFF << copy_u8StartBit);
	copy_u8Port->ODR |= (copy_u8Value << copy_u8StartBit);
}

/***************************************************************************/
/****	Brief	:	toggle selected pre-configured pin as output 		****/
/**** 	Return	:	None												****/
/****	param	:	the port, the pin number and the value 				****/
/***************************************************************************/
void MGPIO_voidTogglePinValue(GPIO_TypeDef* copy_u8Port, u8 copy_u8Pin)
{
	TOGGLE_BIT(copy_u8Port->ODR, copy_u8Pin);
}
