//Robot Sensor
//Author: Christopher Boulanger
//Created: 4 December 2013
//Description: This programs uses sensors to check for distance from obstacles.
//	Uses analog digital conversion to produce high voltages for close distances.
//	When within a certain distance on the left side, LED1 will light up.
//	When within a certain distance on the right side, LED2 will light up.
//Documentation: Used Captain Branchflower's Lesson 36 Example code as as starting point.
//Worked with C2C Mossing.

#include <msp430.h> 
#include "sensor.h"

unsigned int leftSensorVoltage, rightSensorVoltage;
/*
 * main.c
 */
int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

   initializeADC10();
   P1DIR |= BIT0;
   P1DIR |= BIT6;

for (;;){
	leftSensorVoltage=getLeftSensorVoltage();

	if(leftSensorVoltage < 0x230){
		P1OUT &= ~BIT0;
	}
	else{
		P1OUT |= BIT0;
	}

	rightSensorVoltage=getRightSensorVoltage();

	if(rightSensorVoltage<0x230){
		P1OUT &= ~BIT6;
	}
	else{
		P1OUT |= BIT6;
	}
}

return 0;

}

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void){
	__bic_SR_register_on_exit(CPUOFF);
}
