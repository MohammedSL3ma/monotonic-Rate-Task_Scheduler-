/*
 * GccApplication7.c
 *
 * Created: 9/12/2024 10:25:05 AM
 * Author : zas
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h" 
#include "DIO_interface.h"
#include "TMR1_interface.h"
#include "GI_interface.h"

// Task periods in milliseconds
#define TASK1_PERIOD 10
#define TASK2_PERIOD 20
#define TASK3_PERIOD 50

// Global variables to track task timing
volatile u16 task1_timer = 0;
volatile u16 task2_timer = 0;
volatile u16 task3_timer = 0;

// Function prototypes
void task1(void);
void task2(void);
void task3(void);
void timer_interrupt_handler(void);   // Declare the function prototype here

// Initialize the scheduler using Timer1
void scheduler_init(void) {
	// Initialize Timer1 for scheduling
	TMR1_voidInit();
	TMR1_voidSetCallBack(timer_interrupt_handler, TMR1_CTC_COMPARE_MATCH_A);
	TMR1_voidStart();

	// Enable global interrupts
	GI_voidEnable();
}

// Timer interrupt handler (executed every 1ms)
void timer_interrupt_handler(void) {
	task1_timer++;
	task2_timer++;
	task3_timer++;

	// Check and run task1 (High priority, 10ms period)
	if (task1_timer >= TASK1_PERIOD) {
		task1_timer = 0;
		task1();
	}

	// Check and run task2 (Medium priority, 20ms period)
	if (task2_timer >= TASK2_PERIOD) {
		task2_timer = 0;
		task2();
	}

	// Check and run task3 (Low priority, 50ms period)
	if (task3_timer >= TASK3_PERIOD) {
		task3_timer = 0;
		task3();
	}
}

// Task 1: Toggle LED on PB0
void task1(void) {
	DIO_voidTogglePinValue(DIO_PORTB, DIO_PIN0);
}

// Task 2: Toggle LED on PB1
void task2(void) {
	DIO_voidTogglePinValue(DIO_PORTB, DIO_PIN1);
}

// Task 3: Toggle LED on PB2
void task3(void) {
	DIO_voidTogglePinValue(DIO_PORTB, DIO_PIN2);
}

int main(void) {
	// Initialize DIO pins for LEDs
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN0, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN1, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN2, DIO_PIN_OUTPUT);

	// Initialize the scheduler (Timer1)
	scheduler_init();

	// Main loop
	while (1) {
		// Task execution is handled by the ISR
	}
	return 0;
}
