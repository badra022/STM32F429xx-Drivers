/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 14/8/2020				*************/
/*********** Version	: V02					*************/
/*********** Brief		: RCC config file		*************/
/************************************************************/

/************************************************************/
/*			GUARD FILE TO PREVENT MULTIPLE INCLUSION		*/
/************************************************************/
#ifndef	_RCC_CONFIG_
#define	_RCC_CONFIG_

/*	options:	RCC_HSI (16 MHZ)
				RCC_HSE_CRYSTAL
				RCC_HSE_RC
				RCC_PLL (max 180MHZ)
	*/
#define	RCC_SYSTEM_CLOCK			RCC_HSI


/*	options:	DISABLE, ENABLE	*/
#define	CLOCK_SECURITY_SYSTEM		DISABLE


#if(RCC_SYSTEM_CLOCK == RCC_PLL)

/* options:	RCC_HSI, RCC_HSE_CRYSTAL */
#define PLL_PLLI2S_SOURCE		RCC_HSI

/* options:	2....15 */
#define PPL_Q		5

/* options:	2, 4, 6, 8 */
#define PPL_P		6

/* options:	50....432 */
#define PPL_N		300

/* options: 2....63 */
#define PPL_M		60

#endif

/*	options:	MCO2_SYSTEM_CLOCK
				MCO2_PPLI2S
				MCO2_HSE
				MCO2_MAIN_PLL
*/
#define	MCO2_CLOCK_SOURCE		MCO2_SYSTEM_CLOCK

/* options:		MCO_SOURCE_NO_DIV
 * 				MCO_SOURCE_DIV_2
 * 				MCO_SOURCE_DIV_3
 * 				MCO_SOURCE_DIV_4
 * 				MCO_SOURCE_DIV_5
 */
#define MCO2_PRESCALER			MCO_SOURCE_NO_DIV

/*	options:	MCO1_HSI
				MCO1_LSE
				MCO1_HSE
				MCO1_MAIN_PLL
*/
#define	MCO1_CLOCK_SOURCE		MCO1_HSI

/* options:		MCO_SOURCE_NO_DIV
 * 				MCO_SOURCE_DIV_2
 * 				MCO_SOURCE_DIV_3
 * 				MCO_SOURCE_DIV_4
 * 				MCO_SOURCE_DIV_5
 */
#define MCO1_PRESCALER			MCO_SOURCE_NO_DIV

/* options:		0, 1 -> NO clock
 * 				2....31	-> prescaler
 */
#define RTC_PRESCALER			0

/*	options:	AHB_APB_NO_PRESCALE
				AHB_APB_DIV_2
				AHB_APB_DIV_4
				AHB_APB_DIV_8
				AHB_APB_DIV_16
	*/
#define	AHB_TO_APB1_PRESCALER		AHB_APB_DIV_2

/*	options:	AHB_APB_NO_PRESCALE
				AHB_APB_DIV_2
				AHB_APB_DIV_4
				AHB_APB_DIV_8
				AHB_APB_DIV_16
	*/
#define	AHB_TO_APB2_PRESCALER		AHB_APB_DIV_2

/*	options:	SYSCLK_AHP_NO_PRESCALE
				SYSCLK_AHP_DIV_2
				SYSCLK_AHP_DIV_4
				SYSCLK_AHP_DIV_8
				SYSCLK_AHP_DIV_16
				SYSCLK_AHP_DIV_64
				SYSCLK_AHP_DIV_128
				SYSCLK_AHP_DIV_256
				SYSCLK_AHP_DIV_512
	*/
#define	SYSCLK_AHP_PRESCALER		SYSCLK_AHP_DIV_2		

#endif
