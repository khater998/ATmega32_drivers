/******************************************************************************
 *
 * Module: INTERRUPT
 *
 * File Name: interrupt.h
 *
 * Description: Header file for the ATmega32 INTERRUPT driver
 *
 * Author: MOHAMED IBRAHIM
 *
 *******************************************************************************/

#ifndef INTERRUPT_DRIVER_INTERRUPT_H_
#define INTERRUPT_DRIVER_INTERRUPT_H_


/***********************************************************************************************/
/*								  Section: INCLUDES                                            */
/***********************************************************************************************/
#include "../../STD_types.h"
#include "../../Common_Macros.h"
#include <avr/io.h>

/***********************************************************************************************/
/*								  Section: MACRO DECLARATIONS                                  */
/***********************************************************************************************/


/***********************************************************************************************/
/*								  Section: MACRO FUNCTIONS DECLARATIONS                        */
/***********************************************************************************************/

/***********************************************************************************************/
/*								  Section: DATA TYPE DECLARATIONS                              */
/***********************************************************************************************/

/***********************************************************************************************/
/*								  Section: FUNCTION DECLARATIONS                               */
/***********************************************************************************************/
/**
 * @brief: Gets the contents of a specific EEPROM address.
 * @param address: The address to be read from the EEPROM.
 * @param data:    The pointer of the variable that will receive the read data.
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 *
 */
STD_ReturnType EEPROM_read(const uint16 address, uint8* data);


/**
 * @brief: Write data at a specific address in EEPROM.
 * @param address: The address to put the data in.
 * @param data:	   The data to be written in the address.
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 *
 */
STD_ReturnType EEPROM_write(const uint16 address, uint8 data);

#endif /* INTERRUPT_DRIVER_INTERRUPT_H_ */
