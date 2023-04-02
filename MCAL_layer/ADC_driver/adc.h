
/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for the ATmega32 ADC driver
 *
 * Author: MOHAMED IBRAHIM
 *
 *******************************************************************************/

#ifndef ADC_DRIVER_ADC_H_
#define ADC_DRIVER_ADC_H_


/***********************************************************************************************/
/*								  Section: INCLUDES                                            */
/***********************************************************************************************/
#include "../../STD_types.h"
#include "../../Common_Macros.h"
#include <avr/io.h>

/***********************************************************************************************/
/*								  Section: MACRO DECLARATIONS                                  */
/***********************************************************************************************/
#define ADC_MAX_VALUE 			1023       /* range of 10-bit ADC is from 0 -> 1023 */
#define ADC_REF_VOLTAGE_VALUE 	5		   /* must be updated whether internal or external reference used */

/***********************************************************************************************/
/*								  Section: MACRO FUNCTIONS DECLARATIONS                        */
/***********************************************************************************************/
#define ADC_ENABLE_LEFT_ADJUSTMENT() 			SET_BIT(ADMUX, ADLAR)
#define ADC_ENABLE_AUTO_TRIGGER()				SET_BIT(ADCSRA, ADATE)

/***********************************************************************************************/
/*								  Section: DATA TYPE DECLARATIONS                              */
/***********************************************************************************************/
typedef enum
{
	ADC_CHANNEL_0,
	ADC_CHANNEL_1,
	ADC_CHANNEL_2,
	ADC_CHANNEL_3,
	ADC_CHANNEL_4,
	ADC_CHANNEL_5,
	ADC_CHANNEL_6,
	ADC_CHANNEL_7,
}adc_channel_t;

typedef enum
{
	ADC_PRESCALER_2 = 1,
	ADC_PRESCALER_4,
	ADC_PRESCALER_8,
	ADC_PRESCALER_16,
	ADC_PRESCALER_32,
	ADC_PRESCALER_64,
	ADC_PRESCALER_128
}adc_prescaler_t;



/***********************************************************************************************/
/*								  Section: FUNCTION DECLARATIONS                               */
/***********************************************************************************************/
/**
 * * @brief: Initializes ADC. Default: AVCC is chosen, ADC interrupt is Disabled, Right adjustment is set,
 * 					                 auto trigger is disabled.
 * @param prescaler: The prescaler by which F_CPU is divided 	@ref adc_prescaler_t
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 *
 */
STD_ReturnType ADC_init(const adc_prescaler_t prescaler_id);

/**
 * @brief:  Function responsible for read analog data from a certain ADC channel
  	  	  	and convert it to digital using the ADC driver.
 * @param ch_num: The channel to read signal from. 	@ref adc_channel_t
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 *
 */
STD_ReturnType ADC_readChannel(const adc_channel_t ch_num, uint16 * digital_out);


#endif /* ADC_DRIVER_ADC_H_ */
