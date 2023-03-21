/*
 * LED_driver.c
 *
 *  Created on: Mar 15, 2023
 *      Author: khater
 */

#include "led.h"


/**
 * @brief initializes the led pin to be output
 * @param led: pointer to the module led configuration
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 */
STD_ReturnType LED_init(const led_t *led)
{
	STD_ReturnType error_status = E_OK;
	if(NULL == led)
	{
		error_status = E_NOT_OK;
	}
	else
	{
		pin_obj_t led_pin = {.port_id = led->port_id, .pin_id = led->pin_id,
				.direction = GPIO_OUTPUT, .logic = led->led_initial_state};
		error_status = GPIO_pinInit(&led_pin);
	}

	return error_status;
}

/**
 * @brief turns on the led
 * @param led: pointer to the module led configuration
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 */
STD_ReturnType LED_on(const led_t *led)
{
	STD_ReturnType error_status = E_OK;
	if(NULL == led)
	{
		error_status = E_NOT_OK;
	}
	else
	{
		pin_obj_t led_pin = {.port_id = led->port_id, .pin_id = led->pin_id};
		error_status = GPIO_pinWrite(&led_pin, GPIO_HIGH);

	}

	return error_status;
}
/**
 * @brief turns off the led
 * @param led: pointer to the module led configuration
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 */
STD_ReturnType LED_off(const led_t *led)
{
	STD_ReturnType error_status = E_OK;
	if(NULL == led)
	{
		error_status = E_NOT_OK;
	}
	else
	{
		pin_obj_t led_pin = {.port_id = led->port_id, .pin_id = led->pin_id};
		error_status = GPIO_pinWrite(&led_pin, GPIO_LOW);

	}

	return error_status;
}
/**
 * @brief toggle the led status
 * @param led: pointer to the module led configuration
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 */
STD_ReturnType LED_toggle(const led_t *led)
{
	STD_ReturnType error_status = E_OK;
	if(NULL == led)
	{
		error_status = E_NOT_OK;
	}
	else
	{
		pin_obj_t led_pin = {.port_id = led->port_id, .pin_id = led->pin_id};
		error_status = GPIO_pinToggle(&led_pin);

	}

	return error_status;
}

