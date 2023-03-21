/*
 * BUTTON_driver.h
 *
 *  Created on: Mar 15, 2023
 *      Author: khater
 */

#ifndef ECUAL_LAYER_BUTTON_DRIVER_BUTTON_H_
#define ECUAL_LAYER_BUTTON_DRIVER_BUTTON_H_


/***********************************************************************************************/
/*								  Section: INCLUDES                                            */
/***********************************************************************************************/
#include "../../STD_types.h"
#include "../../Common_Macros.h"
#include "../../MCAL_layer/GPIO_driver/gpio.h"



/***********************************************************************************************/
/*								  Section: MACRO DECLARATIONS                                  */
/***********************************************************************************************/


/*************** Section:   MACRO FUNCTIONS DECLARATIONS **************/


/***********************************************************************************************/
/*								  Section: DATA TYPE DECLARATIONS                              */
/***********************************************************************************************/
typedef enum{
	BUTTON_PRESSED = 0,
	BUTTON_RELEASED
}button_state_t;

typedef enum{
	DISABLED,
	ENABLED
}internal_pullup_t;

typedef enum{
	BUTTON_ACTIVE_HIGH = 0, /* button connected to a power source */
	BUTTON_ACTIVE_LOW		/* button connected to the ground */
}button_active_t;

typedef struct{
	uint8 port_id 			:2;		/** @ref port_index_t */
	uint8 pin_id 			:3;		/** @ref pin_index_t */
	uint8 button_active_t	:1;		/** @ref button_active_t */
	uint8 internal_pullup_t :1;		/** @ref internal_pullup_t */
	uint8  					:1;		/** padding the remaining 1 bit*/
}button_t;


/***********************************************************************************************/
/*								  Section: FUNCTION DECLARATIONS                               */
/***********************************************************************************************/
/**
 * @brief initializes the button pin to be input
 * @param btn: a pointer to the module button configuration
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 */
STD_ReturnType BUTTON_init(const button_t *btn);

/**
 * @brief reads the status of the button
 * @param btn: a pointer to the module button configuration
 * @param btn_state: the variable that will store the button state
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 */
STD_ReturnType BUTTON_read(const button_t *btn, uint8 *btn_state);


#endif /* ECUAL_LAYER_BUTTON_DRIVER_BUTTON_H_ */
