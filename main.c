//Robot Sensor
//Author: Christopher Boulanger
//Created: 4 December 2013
//Description: This programs uses sensors to check for distance from obstacles.
//	Uses analog digital conversion to produce high voltages for close distances.
//	When within a certain distance on the left side, LED1 will light up.
//	When within a certain distance on the right side, LED2 will light up.
//Documentation: Used Captain Branchflower's Lesson 36 Example code as as starting point.

#include <msp430.h> 

#include "sensor.c"
#include "sensor.h"

/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    //initialize ADC10
    ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
    ADC10CTL1 = INCH_4;                       	// input A4
    ADC10AE0 |= BIT4;                         	// PA.1 ADC option select
    ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;         // Select SMCLK

    //set output pins for LED
    P1DIR |= 0x01;                           	 // Set P1.0 to output direction
    P1DIR |= BIT6;								// Set P1.6 to output direction

for (;;){
		ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	    __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit
	    //check for right sensor interrupt
	    if (ADC10MEM < 0x1FF)
	      P1OUT &= ~0x01;                       // Clear P1.0 LED off
	    else
	      P1OUT |= 0x01;                        // Set P1.0 LED on
}
return 0;
}

for (//right sensor interrupt){
		ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
	    __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit
	    //check for left sensor interrupt
	    if (ADC10MEM < 0x1FF)
	      P1OUT &= BIT6;                       // Clear P1.6 LED off
	    else
	      P1OUT |= BIT6;                        // Set P1.6 LED on
}
return 0;
}

	return 0;
}
