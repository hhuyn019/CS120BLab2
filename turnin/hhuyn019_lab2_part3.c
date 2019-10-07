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
	//DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	//unsigned char tmpB = 0x00;
	unsigned char tmpA3 = 0x00;
	unsigned char tmpA2 = 0x00;
	unsigned char tmpA1 = 0x00;
	unsigned char tmpA0 = 0x00;
	unsigned char cntavail = 0;
    /* Insert your solution below */
    while (1) {
	tmpA3 = 0x08 & PINA;
	tmpA2 = 0x04 & PINA;
	tmpA1 = 0x02 & PINA;
	tmpA0 = 0x01 & PINA;
	tmpA3 = tmpA3 >> 3;
	tmpA2 = tmpA2 >> 2;
	tmpA1 = tmpA1 >> 1;
	cntavail = 0x04 - ((tmpA3) + (tmpA2) + (tmpA1) + tmpA0);
	if (tmpA0) {
		PORTC = PINC | 0x01;
	}
	if (tmpA1) {
		PORTC = PINC | 0x02;
	}
	if (tmpA2) {
		PORTC = PINC | 0x04;
	}
	if (tmpA3) {
		PORTC = PINC | 0x08;
	}
	if (cntavail == 0) {
		PORTC = PINC | 0x80;
	}
    }
	return 1;
}
