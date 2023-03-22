/*
 * seven_seg.h
 *
 *  Created on: Mar 22, 2023
 *      Author: khater
 */

#ifndef ECUAL_LAYER_SEVEN_SEG_DRIVER_SEVEN_SEG_H_
#define ECUAL_LAYER_SEVEN_SEG_DRIVER_SEVEN_SEG_H_

/***********************************************************************************************/
/*								  Section: INCLUDES                                            */
/***********************************************************************************************/
#include "../../MCAL_layer/GPIO_driver/gpio.h"


/***********************************************************************************************/
/*								  Section: MACRO DECLARATIONS                                  */
/***********************************************************************************************/

#define with_decoder 0 				/* define if a decoder will be used or not */

#if (with_decoder == 1)
	#define NO_SEGMENT_PINS 	4	/* with decoder, required microcontroller pins are 4 */
#else
	#define NO_SEGMENT_PINS 	7	/* without decoder, required microcontroller pins are 7 */

	#define COMMON_CATHODE_0 		0b0111111	/*pins required states to print 0 on common cathode 7-segment*/
	#define COMMON_CATHODE_1		0b0000110	/*pins required states to print 1 on common cathode 7-segment*/
	#define COMMON_CATHODE_2		0b1011011	/*pins required states to print 2 on common cathode 7-segment*/
	#define COMMON_CATHODE_3		0b1001111	/*pins required states to print 3 on common cathode 7-segment*/
	#define COMMON_CATHODE_4		0b1100110	/*pins required states to print 4 on common cathode 7-segment*/
	#define COMMON_CATHODE_5		0b1101101	/*pins required states to print 5 on common cathode 7-segment*/
	#define COMMON_CATHODE_6		0b1111101	/*pins required states to print 6 on common cathode 7-segment*/
	#define COMMON_CATHODE_7		0b0000111	/*pins required states to print 7 on common cathode 7-segment*/
	#define COMMON_CATHODE_8		0b1111111	/*pins required states to print 8 on common cathode 7-segment*/
	#define COMMON_CATHODE_9		0b1100111	/*pins required states to print 9 on common cathode 7-segment*/


#endif
/***********************************************************************************************/
/*								  Section: MACRO FUNCTIONS DECLARATIONS                        */
/***********************************************************************************************/




/***********************************************************************************************/
/*								  Section: DATA TYPE DECLARATIONS                              */
/***********************************************************************************************/
typedef enum{									/* to specify whether the 7-segment is common anode or cathode*/
	COMMON_ANODE,
	COMMON_CATHODE
}seven_seg_type_t;



typedef struct{

#if (1 == with_decoder)					/* if decoder user, only 4 pins required for 7-segment object */
	pin_obj_t segment_pins[4];			/** @ref pin_obj_t */

#else									/* without decoder, 7 pins of 7-segment needs to be defined */
	pin_obj_t segment_pins[7];
#endif

	/* to specify the type of 7-segment used (COMMON ANODE OR COMMON CATHODE)*/
	seven_seg_type_t segment_type;		/** @ref seven_seg_type_t */
}seven_seg_t;

/***********************************************************************************************/
/*								  Section: FUNCTION DECLARATIONS                               */
/***********************************************************************************************/
/**
 * @brief Initializes decoder pins as output
 * @param seven_seg: pointer to the 7-segment object
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 */
STD_ReturnType SEVEN_SEG_init(const seven_seg_t *seven_seg);

/**
 * @brief Writes the passed number argument on the 7-segment
 * @param seven_seg: pointer to the 7-segment object
 * @param number
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 */
STD_ReturnType SEVEN_SEG_write(const seven_seg_t *seven_seg, uint8 number);


#endif /* ECUAL_LAYER_SEVEN_SEG_DRIVER_SEVEN_SEG_H_ */
