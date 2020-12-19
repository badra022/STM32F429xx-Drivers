/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 30/8/2020				*************/
/*********** Version	: V02					*************/
/************************************************************/

/************************************************************/
/*			GUARD FILE TO PREVENT MULTIPLE INCLUSION		*/
/************************************************************/
#ifndef	_GPIO_INTERFACE_
#define	_GPIO_INTERFACE_

typedef struct
{
  __IO uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
  __IO uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
  __IO uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
  __IO uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  __IO uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
  __IO uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
  __IO uint16_t BSRRL;    /*!< GPIO port bit set/reset low register,  Address offset: 0x18      */
  __IO uint16_t BSRRH;    /*!< GPIO port bit set/reset high register, Address offset: 0x1A      */
  __IO uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  __IO uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;


#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF               ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG               ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH               ((GPIO_TypeDef *) GPIOH_BASE)
#define GPIOI               ((GPIO_TypeDef *) GPIOI_BASE)
#define GPIOJ               ((GPIO_TypeDef *) GPIOJ_BASE)
#define GPIOK               ((GPIO_TypeDef *) GPIOK_BASE)

#define RCC_GPIOA_EN		0
#define RCC_GPIOB_EN		1
#define RCC_GPIOC_EN		2
#define RCC_GPIOD_EN		3
#define RCC_GPIOE_EN		4
#define RCC_GPIOF_EN		5
#define RCC_GPIOG_EN		6
#define RCC_GPIOH_EN		7
#define RCC_GPIOI_EN		8
#define RCC_GPIOJ_EN		9
#define RCC_GPIOK_EN		10

/************************************************************/
/*				FUNCTIONS PARAMETERS DEFINITIONS			*/
/************************************************************/

typedef enum{
	INPUT,
	OUTPUT,
	AF,
	ANALOG,
}DIO_pinMode;

typedef enum{
	PUSH_PULL,
	OPEN_DRAIN,
}DIO_outputType;

typedef enum{
	LOW_SPEED,
	MEDIUM_SPEED,
	HIGH_SPEED,
	VERY_HIGH_SPEED,
}DIO_outputSpeed;

typedef enum{
	NONE,
	PULL_UP,
	PULL_DOWN,
}DIO_internalResistance;


/************************************************************/
/*						FUNCTION PROTOTYPES					*/
/************************************************************/

/***************************************************************************/
/****	Brief	:	output either HIGH or LOW in selected pin 			****/
/**** 	Return	:	None												****/
/****	param	:	the port, the pin number and the value (1/0)		****/
/***************************************************************************/
void MGPIO_voidSetPinValue(GPIO_TypeDef* copy_port, u8 copy_pin, bool copy_value);

/***************************************************************************/
/****	Brief	:	configure the selected pin 						 	****/
/**** 	Return	:	None												****/
/****	param	:	the port, the pin number and the configuration		****/
/***************************************************************************/
void MGPIO_voidSetPinDirection(GPIO_TypeDef* copy_port, u8 copy_pin,
		DIO_pinMode copy_mode, DIO_outputType copy_oType,
		DIO_outputSpeed copy_speed,
		DIO_internalResistance copy_internalRes);

/***************************************************************************/
/****	Brief	:	read selected pin								 	****/
/**** 	Return	:	pin's value that is input							****/
/****	param	:	the port and pin number								****/
/***************************************************************************/
bool MGPIO_voidGetPinValue(GPIO_TypeDef* copy_port,u8 copy_pinId);

/***************************************************************************/
/****	Brief	:	set some u8 value in some region of ODR 			****/
/**** 	Return	:	None												****/
/****	param	:	the port, the pin number and the value 				****/
/***************************************************************************/
void MGPIO_voidSetPortValue(GPIO_TypeDef* copy_u8Port, u8 copy_u8StartBit, u8 copy_u8Value);

/***************************************************************************/
/****	Brief	:	toggle selected pre-configured pin as output 		****/
/**** 	Return	:	None												****/
/****	param	:	the port, the pin number and the value 				****/
/***************************************************************************/
void MGPIO_voidTogglePinValue(GPIO_TypeDef* copy_u8Port, u8 copy_u8Pin);


#endif
