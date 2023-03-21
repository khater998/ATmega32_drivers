/*
 * LED_driver.h
 *
 *  Created on: Mar 15, 2023
 *      Author: khater
 */

#ifndef ECUAL_LAYER_LED_DRIVER_LED_H_
#define ECUAL_LAYER_LED_DRIVER_LED_H_

/***********************************************************************************************/
/*								  Section: INCLUDES                                            */
/***********************************************************************************************/
#include "../../MCAL_layer/GPIO_driver/gpio.h"


/***********************************************************************************************/
/*								  Section: MACRO DECLARATIONS                                  */
/***********************************************************************************************/


/***********************************************************************************************/
/*								  Section: MACRO FUNCTIONS DECLARATIONS                        */
/***********************************************************************************************/




/***********************************************************************************************/
/*								  Section: DATA TYPE DECLARATIONS                              */
/***********************************************************************************************/
typedef enum{
	LED_OFF,
	LED_ON
}led_status_t;

typedef struct{
	uint8 port_id			:2;		/** @ref port_index_t */
	uint8 pin_id			:3;		/** @ref pin_index_t */
	uint8 led_initial_state :1;  	/** @ref led_status_t */
	uint8 					:2;		/** padding the remaining 2 bits*/
}led_t;

/***********************************************************************************************/
/*								  Section: FUNCTION DECLARATIONS                               */
/***********************************************************************************************/
/**
 * @brief initializes the led pin to be output
 * @param led: pointer to the led object
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 */
STD_ReturnType LED_init(const led_t *led);

/**
 * @brief turns on the led
 * @param led: pointer to the led object
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 */
STD_ReturnType LED_on(const led_t *led);
/**
 * @brief turns off the led
 * @param led: pointer to the led object
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 */
STD_ReturnType LED_off(const led_t *led);
/**
 * @brief toggle the led status
 * @param led: pointer to led object
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 */
STD_ReturnType LED_toggle(const led_t *led);



#endif /* ECUAL_LAYER_LED_DRIVER_LED_H_ */
