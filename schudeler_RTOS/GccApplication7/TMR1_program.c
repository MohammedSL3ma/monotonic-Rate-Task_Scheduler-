/******************************************************************************
 *                                                                            *
 *************************  SWC     : TMR1_program    *************************
 *************************  Date    : 14/01/2024      *************************
 *************************  Author  : Kareem Hussein  *************************
 *************************  Version : 1.0             *************************
 *                                                                            *
 ******************************************************************************/


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "VECTOR_NUM.h"

/* MCAL */
#include "TMR1_interface.h"
#include "TMR1_config.h"
#include "TMR1_private.h"
#include "TMR1_register.h"

#include <avr/io.h>
#include <avr/interrupt.h>

// Function pointers for callback
static void (*TMR1_OVF_Callback)(void) = NULL;
static void (*TMR1_CTC_Callback)(void) = NULL;

// Initialize Timer1 in CTC mode for 1ms tick
void TMR1_voidInit(void) {
    // Set Timer1 to CTC mode
    TCCR1B |= (1 << WGM12);

    // Set the prescaler to 64
    TCCR1B |= (1 << CS11) | (1 << CS10);

    // Set compare value for 1ms interrupt (with 16MHz clock)
    OCR1A = 249;

    // Enable Compare Match A interrupt
    SET_BIT(TIMSK, OCIE1A);
}

// Start the Timer1
void TMR1_voidStart(void) {
    // The timer is already configured to run once initialized
}

// Stop the Timer1
void TMR1_voidStop(void) {
    // Clear the prescaler to stop the timer
    TCCR1B &= ~((1 << CS11) | (1 << CS10));
}

// Set callback for Timer1 interrupts
void TMR1_voidSetCallBack(void(*copy_pFunAction)(void), u8 copy_u8InterruptSource) {
    if (copy_u8InterruptSource == TMR1_CTC_COMPARE_MATCH_A) {
        TMR1_CTC_Callback = copy_pFunAction;
    } else if (copy_u8InterruptSource == TMR1_NORMAL_OVER_FLOW) {
        TMR1_OVF_Callback = copy_pFunAction;
    }
}

// ISR for Timer1 Compare Match A
ISR(TIMER1_COMPA_vect) {
    if (TMR1_CTC_Callback != NULL) {
        TMR1_CTC_Callback();
    }
}
