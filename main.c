/*
 * main.c
 *
 *  Created on: Mar 14, 2023
 *      Author: khater
 */

#include <util/delay.h>
#include "STD_types.h"
#include "Common_Macros.h"
#include "MCAL_layer/GPIO_driver/gpio.h"
#include "MCAL_layer/INTERRUPT_driver/interrupt.h"
#include "MCAL_layer/ADC_driver/adc.h"


#include "ECUAL_layer/BUTTON_driver/button.h"
#include "ECUAL_layer/LED_driver/led.h"
#include "ECUAL_layer/KEYPAD_driver/keypad.h"
#include "ECUAL_layer/SEVEN_SEG_driver/seven_seg.h"
#include "ECUAL_layer/LCD_driver/lcd.h"

lcd_t board_lcd =
{
		.rs.port_id = PORTA_ID,
		.rs.pin_id  = PIN_1,
		.en.port_id = PORTA_ID,
		.en.pin_id  = PIN_2,

		.data_pin[0].port_id = PORTA_ID,
		.data_pin[0].pin_id = PIN_3,
		.data_pin[1].port_id = PORTA_ID,
		.data_pin[1].pin_id = PIN_4,
		.data_pin[2].port_id = PORTA_ID,
		.data_pin[2].pin_id = PIN_5,
		.data_pin[3].port_id = PORTA_ID,
		.data_pin[3].pin_id = PIN_6,

};
int main()
{
	ADC_init(ADC_PRESCALER_128);
	LCD_init(&board_lcd);
	uint16 value;

	while(1)
	{
		ADC_readChannel(ADC_CHANNEL_0, &value);

		//LCD_4bit_clear(&board_lcd);
		if(value >= 1000)
		{
			LCD_setCursorLocation(&board_lcd, 1, 1);
			LCD_sendNum(&board_lcd, value);
		}
		else if(value >= 100)
		{
			LCD_setCursorLocation(&board_lcd, 1, 1);
			LCD_sendNum(&board_lcd, value);
			LCD_sendChar(&board_lcd, ' ');
		}
		else
		{
		LCD_setCursorLocation(&board_lcd, 1, 1);
		LCD_sendNum(&board_lcd, value);
		LCD_sendString(&board_lcd, "  ");

		}
		//_delay_ms(100);

	}
}
