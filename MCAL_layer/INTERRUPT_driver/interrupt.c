/*
 * interrupt.c
 *
 *  Created on: Mar 29, 2023
 *      Author: khater
 */


#include "interrupt.h"


void INT0_vect (void) __attribute__ ((signal, used, externally_visible));
void INT1_vect (void) __attribute__ ((signal, used, externally_visible));
void INT2_vect (void) __attribute__ ((signal, used, externally_visible));

static void (* pf_EXTI0_callback)(void) = NULL;
static void (* pf_EXTI1_callback)(void) = NULL;
static void (* pf_EXTI2_callback)(void) = NULL;

/**
 * @brief: Set the trigger condition for EXTI0
 * @param trigger: The required trigger condition for EXTI0 	@ref interrupt_trigger_t
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 *
 */
STD_ReturnType INTERRUPT_EXTI0_setTrigger(const interrupt_trigger_t trigger)
{
	STD_ReturnType error_status = E_OK;						/* to store the error value to be returned */

	/* check required trigger */
	switch(trigger)
	{
	case LOW_LEVEL:
		MCUCR = (MCUCR & 0xFC) | (0x00); 					/* modify ISC01 && ISC00 only to 0,0 */
		break;

	case ANY_LOGICAL_CHANGE:
		MCUCR = (MCUCR & 0xFC) | (0x01); 					/* modify ISC01 && ISC00 only to 0,1 */
		break;

	case FALLING_EDGE:
		MCUCR = (MCUCR & 0xFC) | (0x02); 					/* modify ISC01 && ISC00 only to 1,0 */
		break;

	case RISING_EGDE:
		MCUCR = (MCUCR & 0xFC) | (0x03); 					/* modify ISC01 && ISC00 only to 1,1 */
		break;

	default:
		error_status = E_NOT_OK;
	}

	return error_status;
}

/**
 * @brief: Set the trigger condition for EXTI1
 * @param trigger: The required trigger condition for EXTI1 	@ref interrupt_trigger_t
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 *
 */
STD_ReturnType INTERRUPT_EXTI1_setTrigger(const interrupt_trigger_t trigger)
{
	STD_ReturnType error_status = E_OK;						/* to store the error value to be returned */

		/* check required trigger */
		switch(trigger)
		{
		case LOW_LEVEL:
			MCUCR = (MCUCR & 0xF3) | (0x00); 					/* modify ISC11 && ISC10 only to 0,0 */
			break;

		case ANY_LOGICAL_CHANGE:
			MCUCR = (MCUCR & 0xF3) | (0x04); 					/* modify ISC11 && ISC10 only to 0,1 */
			break;

		case FALLING_EDGE:
			MCUCR = (MCUCR & 0xF3) | (0x08); 					/* modify ISC11 && ISC10 only to 1,0 */
			break;

		case RISING_EGDE:
			MCUCR = (MCUCR & 0xF3) | (0x0C); 					/* modify ISC11 && ISC10 only to 1,1 */
			break;

		default:
			error_status = E_NOT_OK;
		}

		return error_status;
}

/**
 * @brief: Set the trigger condition for EXTI2
 * @param trigger: The required trigger condition for EXTI2 	@ref interrupt_trigger_t
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 *
 */


STD_ReturnType INTERRUPT_EXTI2_setTrigger(const interrupt_trigger_t trigger)
{
	STD_ReturnType error_status = E_OK;						/* to store the error value to be returned */

		/* check required trigger */
		switch(trigger)
		{
		case FALLING_EDGE:
			CLR_BIT(MCUCSR, ISC2);
			break;

		case RISING_EGDE:
			SET_BIT(MCUCSR, ISC2);
			break;

		default:
			error_status = E_NOT_OK;
		}

		return error_status;
}

/**
 * @brief: Set the ISR routine to be executed to the passed function
 * @param pf_ISR: pointer to a function that represents ISR(INT0_vect)
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 */
STD_ReturnType INTERRUPT_EXTI0_setCallback(void (* pf_ISR) (void)){
	STD_ReturnType error_status = E_OK;					/* to store the error value to be returned */


	if(NULL == pf_ISR)
	{
		error_status = E_NOT_OK;
	}
	else
	{
		pf_EXTI0_callback = pf_ISR;
	}
	return error_status;
}
/**
 * @brief: Set the ISR routine to be executed to the passed function
 * @param pf_ISR: pointer to a function that represents ISR(INT1_vect)
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 */
STD_ReturnType INTERRUPT_EXTI1_setCallback(void (* pf_ISR) (void)){
	STD_ReturnType error_status = E_OK;					/* to store the error value to be returned */


	if(NULL == pf_ISR)
	{
		error_status = E_NOT_OK;
	}
	else
	{
		pf_EXTI1_callback = pf_ISR;
	}
	return error_status;
}

/**
 * @brief: Set the ISR routine to be executed to the passed function
 * @param pf_ISR: pointer to a function that represents ISR(INT2_vect)
 * @return status of the function:
 * 						(E_OK): the function finished successfully
 * 						(E_NOT_OK): A problem occurred in function
 */
STD_ReturnType INTERRUPT_EXTI2_setCallback(void (* pf_ISR) (void)){
	STD_ReturnType error_status = E_OK;					/* to store the error value to be returned */


	if(NULL == pf_ISR)
	{
		error_status = E_NOT_OK;
	}
	else
	{
		pf_EXTI2_callback = pf_ISR;
	}
	return error_status;
}

void INT0_vect(void)
{
	pf_EXTI0_callback();
}
void INT1_vect(void)
{
	pf_EXTI1_callback();
}
void INT2_vect(void)
{
	pf_EXTI2_callback();
}

#if 0
ISR(INT0_vect)
{
	pf_EXTI0_callback();
}

ISR(INT1_vect)
{
	pf_EXTI1_callback();
}

ISR(INT2_vect)
{
	pf_EXTI2_callback();
}
#endif
