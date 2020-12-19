/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 30/8/2020				*************/
/*********** Version	: V01					*************/
/************************************************************/

/************************************************************/
/*			GUARD FILE TO PREVENT MULTIPLE INCLUSION		*/
/************************************************************/
#ifndef _SWITCH_INTERFACE_H_
#define _SWITCH_INTERFACE_H_



typedef enum
{
	USER_BUTTON,
}Button_TypeId;


/************************************************************/
/*						FUNCTION PROTOTYPES					*/
/************************************************************/

void HButton_voidinit(Button_TypeId copy_ID);

bool HButton_BoolReadValue(Button_TypeId copy_ID);


#endif /* _SWITCH_INTERFACE_H_ */
