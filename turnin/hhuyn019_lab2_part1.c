/*	Author: hhuyn019
 *  Partner(s) Name: Melanie 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
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
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpA1 = 0x00;
	unsigned char tmpA0 = 0x00;
    /* Insert your solution below */
    while (1) {
	// 1) Read input
	tmpA1 = PINA & 0x02;
	tmpA0 = PINA & 0x01;
	// 2) Perform computation
	// if PA0 is 1, set PB1PB0 = 01, else = 10
	if (tmpA1 == 0x00 && tmpA0 == 0x01) { // True if PA0 is 1
		tmpB = 0x01; // Sets tmpB to bbbbbb01
	//  (clear rightmost 2 bits, then set to 01)
	} else {
		tmpB = 0x00; // Sets tmpB to bbbbbb10
	// 																		 												 // (clear rightmost 2 bits, then set to 10)
	}	
	// 																		 												 // 3) Write output
	PORTB = tmpB;
}
}
