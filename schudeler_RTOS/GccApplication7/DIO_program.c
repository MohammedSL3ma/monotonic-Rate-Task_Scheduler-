/*
 * DIO_program.c
 *
 *  Created on: Aug 10, 2024
 *      Author: Kareem Hussein
 */

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"
#include "DIO_register.h"
#include <avr/io.h>

// Set pin direction
void DIO_voidSetPinDirection(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection) {
    switch (copy_u8PortId) {
        case DIO_PORTB:
            if (copy_u8PinDirection == DIO_PIN_OUTPUT) {
                SET_BIT(DDRB, copy_u8PinId);
            } else {
                CLR_BIT(DDRB, copy_u8PinId);
            }
            break;
        // Add other ports if necessary
    }
}

// Toggle pin value
void DIO_voidTogglePinValue(u8 copy_u8PortId, u8 copy_u8PinId) {
    switch (copy_u8PortId) {
        case DIO_PORTB:
            TOG_BIT(PORTB, copy_u8PinId);
            break;
        // Add other ports if necessary
    }
}
