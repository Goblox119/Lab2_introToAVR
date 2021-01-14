/*	Author: Adam Gunter
 *  Partner(s) Name: Jo Smith
 *	Lab Section: 21
 *	Assignment: Lab #2  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0's
    unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
    unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
    /* Insert your solution below */
    while (1) {
	// 1) Read input
	tmpA = PINA & 0x02;
	// 2) Perform computation
	// if PA1PA0 is 10, set PB0 = 1, else = 0
	if (tmpA == 0x02) { // True if PA1PA0 is 10
		tmpB = (tmpB & 0xFE) | 0x01; // Sets tmpB to bbbbbb01
						 // (clear rightmost bit, then set to 1)
	} else {
		tmpB = (tmpB & 0xFE) | 0x00; // Sets tmpB to bbbbbb00
						 // (clear rightmost bit, then set to 0)
	}	
	// 3) Write output
	PORTB = tmpB;	
    }
    return 0;
}
