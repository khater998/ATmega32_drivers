/*
 * BUTTON_driver.c
 *
 *  Created on: Mar 15, 2023
 *      Author: khater
 */

#include "button.h"


/**
 * @brief initializes the button pin to be input
 * @param btn: a pointer to the module button configuration
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 */
STD_ReturnType BUTTON_init(const button_t *btn)
{
	STD_ReturnType error_status = E_OK;
	if(NULL == btn)
	{
		error_status = E_NOT_OK;
	}
	else
	{
		pin_obj_t btn_pin = {.port_id = btn->port_id, .pin_id = btn->pin_id,
				.direction = GPIO_INPUT, .logic = btn->internal_pullup_t};
		error_status = GPIO_pinInit(&btn_pin);
	}

	return error_status;
}

/**
 * @brief reads the status of the button
 * @param btn: a pointer to the module button configuration
 * @param btn_state: the variable that will store the button state
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 */
STD_ReturnType BUTTON_read(const button_t *btn, uint8 *btn_state)
{
	STD_ReturnType error_status = E_OK;
	GPIO_logic_t btn_pin_status;
	if(NULL == btn)
	{
		error_status = E_NOT_OK;
	}
	else
	{
		pin_obj_t btn_pin = {.port_id = btn->port_id, .pin_id = btn->pin_id};
		error_status = GPIO_pinRead(&btn_pin, &btn_pin_status);
		switch(btn->button_active_t)
		{
		case BUTTON_ACTIVE_HIGH:

			(*btn_state) = btn_pin_status == GPIO_HIGH ? BUTTON_PRESSED : BUTTON_RELEASED;
			break;

		case BUTTON_ACTIVE_LOW:

			(*btn_state) = btn_pin_status == GPIO_LOW ? BUTTON_PRESSED : BUTTON_RELEASED;
			break;

		default:
			error_status = E_NOT_OK;
		}
	}
	return error_status;
}
