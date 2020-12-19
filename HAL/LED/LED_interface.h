/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 30/8/2020				*************/
/*********** Version	: V01					*************/
/************************************************************/

/************************************************************/
/*			GUARD FILE TO PREVENT MULTIPLE INCLUSION		*/
/************************************************************/
#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_

typedef enum
{
	USER_GREEN_LED,
	USER_RED_LED,
}Led_TypeId;

/************************************************************/
/*						FUNCTION PROTOTYPES					*/
/************************************************************/

void HLED_voidTurnON(Led_TypeId copy_ID);

void HLED_init(Led_TypeId copy_ID);

void HLED_voidTurnOFF(Led_TypeId copy_ID);


#endif /* _LED_INTERFACE_H_ */
