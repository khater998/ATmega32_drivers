/******************************************************************************
 *
 * Module: INTERRUPT
 *
 * File Name: interrupt.c
 *
 * Description: Source file for the ATmega32 INTERRUPT driver
 *
 * Author: MOHAMED IBRAHIM
 *
 *******************************************************************************/

#include "eeprom.h"


/**
 * @brief: Gets the contents of a specific EEPROM address.
 * @param address: The address to be read from the EEPROM.
 * @param data:    The pointer of the variable that will receive the read data.
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 *
 */
STD_ReturnType EEPROM_read(const uint16 address, uint8* data){
	STD_ReturnType error_status = E_OK;					/* to store the error value to be returned */


	if(NULL == data)
	{
		error_status = E_NOT_OK;
	}
	else
	{
		/* Wait for completion of previous write */
		while(READ_BIT(EECR, EEWE));

		/* 1. update address registers */
		EEARH = (uint8) (address >> 8) & 0x03;
		EEARH = (uint8) (address & 0xFF);

		/* 2. Write logical one to EERE */
		SET_BIT(EECR, EERE);

		/* Store EEDR content in data */
		*data = EEDR;
	}
	return error_status;
}




/**
 * @brief: Write data at a specific address in EEPROM.
 * @param address: The address to put the data in.
 * @param data:	   The data to be written in the address.
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 *
 */
STD_ReturnType EEPROM_write(const uint16 address, uint8 data){
	STD_ReturnType error_status = E_OK;					/* to store the error value to be returned */

	/* Wait for completion of previous write */
	while(READ_BIT(EECR, EEWE));

	/* 1. read global interrupt status */
	uint8 global_interrupt_status = READ_BIT(SREG, 7);

	/* 2. disable global interrupt*/
	CLR_BIT(SREG, 7);

	/* 3. update address registers */
	EEARH = (uint8) (address >> 8) & 0x03;
	EEARH = (uint8) (address & 0xFF);

	/* 4. update data register */
	EEDR = data;

	/* 5. set EEMWE */
	SET_BIT(EECR, EEMWE);

	/* 6. set EEWE */
	SET_BIT(EECR, EEWE);

	/* 7. set global interrupt flag to its original value */
	global_interrupt_status == 1 ? SET_BIT(SREG, 7) : CLR_BIT(SREG, 7);


	return error_status;
}

