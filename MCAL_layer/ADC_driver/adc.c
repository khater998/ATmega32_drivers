/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega32 ADC driver
 *
 * Author: MOHAMED IBRAHIM
 *
 *******************************************************************************/
#include "adc.h"
/**
 * @brief: Initializes ADC. Default: AVCC is chosen, ADC interrupt is Disabled, Right adjustment is set,
 * 					                 auto trigger is disabled.
 * @param prescaler: The prescaler by which F_CPU is divided 	@ref adc_prescaler_t
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 *
 */
STD_ReturnType ADC_init(const adc_prescaler_t prescaler_id){
	STD_ReturnType error_status = E_OK;					/* to store the error value to be returned */

	if (prescaler_id < 0 || prescaler_id > 7)		/* check if prescaler_id is not of the specified set of values */
	{
		error_status = E_NOT_OK;
	}
	else
	{
		/* ADMUX Register Bits Description:
		 * REFS1:0 = 01 to choose AVCC = 5v as reference voltage
		 * ADLAR   = 0 right adjusted
		 * MUX4:0  = 00000 to choose channel 0 as initialization
		 */
		ADMUX = (1 << REFS0);

		/* ADCSRA Register Bits Description:
		 * ADEN    = 1 Enable ADC
		 * ADIE    = 0 Disable ADC Interrupt
		 * ADATE   = 0 Disable Auto Trigger
		 * ADPS2:0 = user passed value --> ADC must operate in range 50-200Khz
		 */
		ADCSRA = prescaler_id | (1 << ADEN);
	}
	return error_status;
}

/**
 * @brief:  Function responsible for read analog data from a certain ADC channel
  	  	  	and convert it to digital using the ADC driver.
 * @param ch_num: The channel to read signal from. 	@ref adc_channel_t
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 *
 */
STD_ReturnType ADC_readChannel(const adc_channel_t ch_num, uint16 * digital_out){
	STD_ReturnType error_status = E_OK;					/* to store the error value to be returned */

	if(ch_num < 0 || ch_num > 7)						/* check if ch_num is invalid */
	{
		error_status = E_NOT_OK;
	}
	else
	{
		ADMUX |= (ADMUX & 0xF8) | (ch_num & 0x07); 	/* assign the ch_num to the first 3 bits of ADMUX register */
		SET_BIT(ADCSRA, ADSC);						/* start conversion */
		LOOP_UNTIL_BIT_IS_SET(ADCSRA, ADIF);		/* wait for conversion to complete */
		SET_BIT(ADCSRA, ADIF);						/* clear adc interrupt flag by setting it to 1 */
		*digital_out = ADC;							/* store conversion result in the passed argument */
	}

	return error_status;
}
