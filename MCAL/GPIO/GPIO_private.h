/************************************************************/
/*********** Author		: Ahmed Mohamed Badra	*************/
/*********** Date		: 30/8/2020				*************/
/*********** Version	: V02					*************/
/************************************************************/

/************************************************************/
/*			GUARD FILE TO PREVENT MULTIPLE INCLUSION		*/
/************************************************************/
#ifndef	_GPIO_PRIVATE_
#define _GPIO_PRIVATE_


/********BIT BANDING MACROS*************************************/

/*          General equation:
*          bit_word_addr = bit_band_base + (byte_offset * 32) + (bit_number * 4)
*
*          peripheral_base_address = 0x40000000 (Fixed for all ARM Cortex-M4)
*          bit_band_base           = 0x42000000 (Fixed for all ARM Cortex-M4)
*          port_G_address          = 0x40021800 (From STM32F4 datasheet)
*          register_ODR_offset     = 0x14       (From STM32F4 reference manual)
*
*          byte_offset = port_G_address + register_ODR_offset - peripheral_base_address
*                      = 0x40021800 + 0x14 - 0x40000000
*                      = 0x00021814
*
*          bit_number  = 13 (Green LED connected to PG13)
*
*          bit_word_addr = 0x42000000 + (0x00021814 * 32) + (13 * 4)
*                        = 0x42000000 + 0x00430280 + 0x34
*                        = 0x424302B4
*/

/* standard macros */
#define BITBAND_PERIPHERAL_BASE 0x40000000

#define ALIAS_PERIPHERAL_BASE 0x42000000

#define BITBAND_PERI(reg_address, bit_number) ((ALIAS_PERIPHERAL_BASE + \
                (reg_address - BITBAND_PERIPHERAL_BASE) * 32 + (bit_number * 4)))




#endif