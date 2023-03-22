/*
 * seven_seg.c
 *
 *  Created on: Mar 22, 2023
 *      Author: khater
 */


#include "seven_seg.h"
#if (0 == with_decoder) /* if no decoder used, define array of pin values required to print each number */
const uint8 SEVEN_SEG_INPUT[10] =	{
		COMMON_CATHODE_0, COMMON_CATHODE_1, COMMON_CATHODE_2, COMMON_CATHODE_3, COMMON_CATHODE_4,
		COMMON_CATHODE_5, COMMON_CATHODE_6, COMMON_CATHODE_7, COMMON_CATHODE_8, COMMON_CATHODE_9
};
#endif
/**
 * @brief Initializes decoder pins as output
 * @param seven_seg: pointer to the 7-segment object
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 */
STD_ReturnType SEVEN_SEG_init(const seven_seg_t *seven_seg)
{
	STD_ReturnType error_status = E_OK;				/* to store the error value to be returned */
	if(NULL == seven_seg)							/* check for null pointer */
	{
		error_status = E_NOT_OK;
	}
	else
	{
		uint8 counter;
		/*	Initialize all decoder pins as output */
		for (counter = 0; counter < NO_SEGMENT_PINS; counter++)
		{
			error_status = GPIO_pinDirectionInit(&(seven_seg->segment_pins[counter]), GPIO_OUTPUT);
		}

	}

	return error_status;
}

/**
 * @brief Writes the passed number argument on the 7-segment
 * @param seven_seg: pointer to the 7-segment object
 * @param number
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 */
STD_ReturnType SEVEN_SEG_write(const seven_seg_t *seven_seg, uint8 number)
{
	STD_ReturnType error_status = E_OK;				/* to store the error value to be returned */
	if(NULL == seven_seg || number > 9)				/* check for null pointer or invalid number */
	{
		error_status = E_NOT_OK;
	}
	else
	{
#if(with_decoder == 1) /* decoder used */
		/* print the number by writing its bit values to the pins used by the decoder */
		error_status &= GPIO_pinWrite(&(seven_seg->segment_pins[0]), READ_BIT(number, 0));
		error_status &= GPIO_pinWrite(&(seven_seg->segment_pins[1]), READ_BIT(number, 1));
		error_status &= GPIO_pinWrite(&(seven_seg->segment_pins[2]), READ_BIT(number, 2));
		error_status &= GPIO_pinWrite(&(seven_seg->segment_pins[3]), READ_BIT(number, 3));

#else 					/* without decoder */
		/* 1. determine the type of the 7-segment */
		switch(seven_seg->segment_type)
		{
		case COMMON_ANODE:
			/* get the bit states required to print the number from the global SEVEN_SEG_INPUT array
			 * since the array is made to deal with common cathode configuration,
			 * then, reverse every bit state before writing it to the common anode 7-segment*/

			error_status &= GPIO_pinWrite(&(seven_seg->segment_pins[0]), !READ_BIT(SEVEN_SEG_INPUT[number], 0));
			error_status &= GPIO_pinWrite(&(seven_seg->segment_pins[1]), !READ_BIT(SEVEN_SEG_INPUT[number], 1));
			error_status &= GPIO_pinWrite(&(seven_seg->segment_pins[2]), !READ_BIT(SEVEN_SEG_INPUT[number], 2));
			error_status &= GPIO_pinWrite(&(seven_seg->segment_pins[3]), !READ_BIT(SEVEN_SEG_INPUT[number], 3));
			error_status &= GPIO_pinWrite(&(seven_seg->segment_pins[4]), !READ_BIT(SEVEN_SEG_INPUT[number], 4));
			error_status &= GPIO_pinWrite(&(seven_seg->segment_pins[5]), !READ_BIT(SEVEN_SEG_INPUT[number], 5));
			error_status &= GPIO_pinWrite(&(seven_seg->segment_pins[6]), !READ_BIT(SEVEN_SEG_INPUT[number], 6));
			break;

		case COMMON_CATHODE:
			/* get the bit states required to print the number from the global SEVEN_SEG_INPUT array
			 * write every pin state of array element  on its relevant pin*/

			error_status &= GPIO_pinWrite(&(seven_seg->segment_pins[0]), READ_BIT(SEVEN_SEG_INPUT[number], 0));
			error_status &= GPIO_pinWrite(&(seven_seg->segment_pins[1]), READ_BIT(SEVEN_SEG_INPUT[number], 1));
			error_status &= GPIO_pinWrite(&(seven_seg->segment_pins[2]), READ_BIT(SEVEN_SEG_INPUT[number], 2));
			error_status &= GPIO_pinWrite(&(seven_seg->segment_pins[3]), READ_BIT(SEVEN_SEG_INPUT[number], 3));
			error_status &= GPIO_pinWrite(&(seven_seg->segment_pins[4]), READ_BIT(SEVEN_SEG_INPUT[number], 4));
			error_status &= GPIO_pinWrite(&(seven_seg->segment_pins[5]), READ_BIT(SEVEN_SEG_INPUT[number], 5));
			error_status &= GPIO_pinWrite(&(seven_seg->segment_pins[6]), READ_BIT(SEVEN_SEG_INPUT[number], 6));
			break;

		default:
			error_status = E_NOT_OK;
		}
#endif
	}


	return error_status;
}

