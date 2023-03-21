/*
 * main.c
 *
 *  Created on: Mar 14, 2023
 *      Author: khater
 */

#include <util/delay.h>
#include "STD_types.h"
#include "Common_Macros.h"
#include "ECUAL_layer/BUTTON_driver/button.h"
#include "ECUAL_layer/LED_driver/led.h"
#include "MCAL_layer/GPIO_driver/gpio.h"
#include "ECUAL_layer/KEYPAD_driver/keypad.h"


int main()
{
	pin_obj_t row1 = {.port_id = 6, .pin_id = PIN_0};
	pin_obj_t row2 = {.port_id = PORTC_ID, .pin_id = PIN_1};
	pin_obj_t row3 = {.port_id = PORTC_ID, .pin_id = PIN_2};
	pin_obj_t row4 = {.port_id = PORTC_ID, .pin_id = PIN_3};

	pin_obj_t col1 = {.port_id = PORTC_ID, .pin_id = PIN_4};
	pin_obj_t col2 = {.port_id = PORTC_ID, .pin_id = PIN_5};
	pin_obj_t col3 = {.port_id = PORTC_ID, .pin_id = PIN_6};
	pin_obj_t col4 = {.port_id = PORTC_ID, .pin_id = PIN_7};

	GPIO_portDirectionInit(PORTA_ID, 0xFF);
	GPIO_portWrite(PORTA_ID, 0x0F);
	//DDRA = 0XFF;
	//PORTA = 0XFF;




	keypad_t keypad_4x4 = {
			.rows_pins[0] = row1,
			.rows_pins[1] = row2,
			.rows_pins[2] = row3,
			.rows_pins[3] = row4,

			.columns_pins[0] = col1,
			.columns_pins[1] = col2,
			.columns_pins[2] = col3,
			.columns_pins[3] = col4
	};

	KEYPAD_init(&keypad_4x4);
	uint8 value = 0;

	while(1)
	{
		KEYPAD_getPressedKey(&keypad_4x4, &value);

		if (value == btn1_value)
		{
			GPIO_portWrite(PORTA_ID, 0x01);

		}else if (value == btn2_value)
		{
			GPIO_portWrite(PORTA_ID, 0x02);

		}else if (value == btn3_value)
		{
			GPIO_portWrite(PORTA_ID, 0x04);

		}

	}
}

