/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 11/9/2020				*************/
/*********** Version	: V01					*************/
/************************************************************/


/************************************************************/
/*			GUARD FILE TO PREVENT MULTIPLE INCLUSION		*/
/************************************************************/
#ifndef _LEDMRX_INTERFACE_H_
#define _LEDMRX_INTERFACE_H_

/************************************************************/
/*						FUNCTION PROTOTYPES					*/
/************************************************************/

void LEDMRX_voidInit(void);
void LEDMRX_voidDisplay(u8 *copy_u8Data);
void LEDMRX_voidDisplayName(u8 *copy_u8Data);

#endif