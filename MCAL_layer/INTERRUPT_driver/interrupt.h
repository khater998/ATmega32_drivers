/******************************************************************************
 *
 * Module: INTERRUPT
 *
 * File Name: interrupt.h
 *
 * Description: Header file for the ATmega32 INTERRUPT driver
 *
 * Author: MOHAMED IBRAHIM
 *
 *******************************************************************************/

#ifndef INTERRUPT_DRIVER_INTERRUPT_H_
#define INTERRUPT_DRIVER_INTERRUPT_H_


/***********************************************************************************************/
/*								  Section: INCLUDES                                            */
/***********************************************************************************************/
#include "../../STD_types.h"
#include "../../Common_Macros.h"
#include <avr/io.h>

/***********************************************************************************************/
/*								  Section: MACRO DECLARATIONS                                  */
/***********************************************************************************************/


/***********************************************************************************************/
/*								  Section: MACRO FUNCTIONS DECLARATIONS                        */
/***********************************************************************************************/
#define INTERRUPT_globalInterruptEnable()           SET_BIT(SREG, 7)
#define INTERRUPT_globalInterruptDisable()          CLEAR_BIT(SREG, 7)

#define INTERRUPT_EXTI0_Enable()        			SET_BIT(GICR, INT0)
#define INTERRUPT_EXTI0_Disable()          			CLEAR_BIT(GICR, INT0)

#define INTERRUPT_EXTI1_Enable()        			SET_BIT(GICR, INT1)
#define INTERRUPT_EXTI1_Disable()          			CLEAR_BIT(GICR, INT1)

#define INTERRUPT_EXTI2_Enable()        			SET_BIT(GICR, INT2)
#define INTERRUPT_EXTI2_Disable()          			CLEAR_BIT(GICR, INT2)

#define INTERRUPT_EXTI0_getFlagState()				READ_BIT(GIFR, INTF0)
#define INTERRUPT_EXTI1_getFlagState()				READ_BIT(GIFR, INTF1)
#define INTERRUPT_EXTI2_getFlagState()				READ_BIT(GIFR, INTF2)

#define ISR(vector) void vector(void) __attribute__ ((signal, used, externally_visible)); \
					void vector(void)


/* Peripheral interrupt control macro function (to be added later) */


/***********************************************************************************************/
/*								  Section: DATA TYPE DECLARATIONS                              */
/***********************************************************************************************/
typedef enum
{
	LOW_LEVEL,
	ANY_LOGICAL_CHANGE,
	FALLING_EDGE,
	RISING_EGDE
}interrupt_trigger_t;

/***********************************************************************************************/
/*								  Section: FUNCTION DECLARATIONS                               */
/***********************************************************************************************/
/**
 * @brief: Set the trigger condition for EXTI0
 * @param trigger: The required trigger condition for EXTI0 	@ref interrupt_trigger_t
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 *
 */
STD_ReturnType INTERRUPT_EXTI0_setTrigger(const interrupt_trigger_t trigger);

/**
 * @brief: Set the trigger condition for EXTI1
 * @param trigger: The required trigger condition for EXTI1 	@ref interrupt_trigger_t
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 *
 */
STD_ReturnType INTERRUPT_EXTI1_setTrigger(const interrupt_trigger_t trigger);

/**
 * @brief: Set the trigger condition for EXTI2
 * @param trigger: The required trigger condition for EXTI2 	@ref interrupt_trigger_t
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 *
 */
STD_ReturnType INTERRUPT_EXTI2_setTrigger(const interrupt_trigger_t trigger);

/**
 * @brief: Set the ISR routine to be executed to the passed function
 * @param pf_ISR: pointer to a function that represents ISR(INT0_vect)
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 */
STD_ReturnType INTERRUPT_EXTI0_setCallback(void (* pf_ISR) (void));

/**
 * @brief: Set the ISR routine to be executed to the passed function
 * @param pf_ISR: pointer to a function that represents ISR(INT1_vect)
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 */
STD_ReturnType INTERRUPT_EXTI1_setCallback(void (* pf_ISR) (void));

/**
 * @brief: Set the ISR routine to be executed to the passed function
 * @param pf_ISR: pointer to a function that represents ISR(INT2_vect)
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 */
STD_ReturnType INTERRUPT_EXTI2_setCallback(void (* pf_ISR) (void));



#endif /* INTERRUPT_DRIVER_INTERRUPT_H_ */
