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
#include "ECUAL_layer/SEVEN_SEG_driver/seven_seg.h"

#if 0
/***************** 7-SEG driver testing without decoder ********************************/
int main()
{
	pin_obj_t pin1 = {.port_id = PORTD_ID, .pin_id = PIN_0};
	pin_obj_t pin2 = {.port_id = PORTD_ID, .pin_id = PIN_1};
	pin_obj_t pin3 = {.port_id = PORTD_ID, .pin_id = PIN_2};
	pin_obj_t pin4 = {.port_id = PORTD_ID, .pin_id = PIN_3};
	pin_obj_t pin5 = {.port_id = PORTD_ID, .pin_id = PIN_4};
	pin_obj_t pin6 = {.port_id = PORTD_ID, .pin_id = PIN_5};
	pin_obj_t pin7 = {.port_id = PORTD_ID, .pin_id = PIN_6};

	seven_seg_t seg1_obj = {
			.segment_pins[0] = pin1,
			.segment_pins[1] = pin2,
			.segment_pins[2] = pin3,
			.segment_pins[3] = pin4,
			.segment_pins[4] = pin5,
			.segment_pins[5] = pin6,
			.segment_pins[6] = pin7,
			.segment_type = COMMON_CATHODE
	};

		pin_obj_t pin11 = {.port_id = PORTB_ID, .pin_id = PIN_0};
		pin_obj_t pin22 = {.port_id = PORTB_ID, .pin_id = PIN_1};
		pin_obj_t pin33 = {.port_id = PORTB_ID, .pin_id = PIN_2};
		pin_obj_t pin44 = {.port_id = PORTB_ID, .pin_id = PIN_3};
		pin_obj_t pin55 = {.port_id = PORTB_ID, .pin_id = PIN_4};
		pin_obj_t pin66 = {.port_id = PORTB_ID, .pin_id = PIN_5};
		pin_obj_t pin77 = {.port_id = PORTB_ID, .pin_id = PIN_6};

		seven_seg_t seg2_obj = {
				.segment_pins[0] = pin11,
				.segment_pins[1] = pin22,
				.segment_pins[2] = pin33,
				.segment_pins[3] = pin44,
				.segment_pins[4] = pin55,
				.segment_pins[5] = pin66,
				.segment_pins[6] = pin77,
				.segment_type = COMMON_ANODE
		};

	SEVEN_SEG_init(&seg1_obj);
	SEVEN_SEG_init(&seg2_obj);

	uint8 counter = 0;

	while(1)
	{
		for(; counter <= 9; counter++)
		{
			SEVEN_SEG_write(&seg1_obj, counter);
			SEVEN_SEG_write(&seg2_obj, counter);
			_delay_ms(500);
		}
		counter = 0;

	}
}
#endif

#if 0
/***************** 7-SEG driver testing with decoder ********************************/
int main()
{
	pin_obj_t pin111 = {.port_id = PORTC_ID, .pin_id = PIN_0};
	pin_obj_t pin222 = {.port_id = PORTC_ID, .pin_id = PIN_1};
	pin_obj_t pin333 = {.port_id = PORTC_ID, .pin_id = PIN_2};
	pin_obj_t pin444 = {.port_id = PORTC_ID, .pin_id = PIN_3};

	seven_seg_t seg3_obj = {
			.segment_pins[0] = pin111,
			.segment_pins[1] = pin222,
			.segment_pins[2] = pin333,
			.segment_pins[3] = pin444,
			.segment_type = COMMON_ANODE
	};

	SEVEN_SEG_init(&seg3_obj);
	uint8 counter = 0;

	while(1)
	{
		for(; counter <= 9; counter++)
		{
			SEVEN_SEG_write(&seg_obj, counter);
			_delay_ms(500);
		}
		counter = 0;

	}
}
#endif


#if 0
/***************** KEYPAD driver testing ********************************/
int main()
{
	pin_obj_t row1 = {.port_id = PORTC_ID, .pin_id = PIN_0};
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
#endif

