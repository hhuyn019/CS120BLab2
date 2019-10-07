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
	DDRC = 0x8F; PORTC = 0x00;
	//unsigned char tmpB = 0x00;
	unsigned char tmpA3 = 0x00;
	unsigned char tmpA2 = 0x00;
	unsigned char tmpA1 = 0x00;
	unsigned char tmpA0 = 0x00;
	unsigned char cntavail = 0x00;
	unsigned char tmpB = 0x00;
    /* Insert your solution below */
    while (1) {
	tmpA3 = PINA & 0x08;
	tmpA2 = PINA & 0x04;
	tmpA1 = PINA & 0x02;
	tmpA0 = PINA & 0x01;
	tmpA3 = tmpA3 >> 3;
	tmpA2 = tmpA2 >> 2;
	tmpA1 = tmpA1 >> 1;
	cntavail = ((tmpA3) + (tmpA2) + (tmpA1) + tmpA0);
	tmpB = 0x04 - cntavail;
	PORTC = tmpB;
	if (cntavail == 0x04) {
		tmpB = 0x80;
		PORTC = tmpB;
	}
    }
	return 1;
}
