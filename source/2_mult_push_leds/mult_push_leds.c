//>>> Program Header >>>
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	File Name:	mult_push_leds.c
	Author:		Shreyas Hemachandra
	Date:		26/03/2022
	Modified:	None

	Description:  This program demostrates GPIO control on PIC18F45K22 microcontroller
		      	  Push buttons are connected to PortD Higher Nibble and LEDs are 
	       	      connected to Lower Nibble of PortD.
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

// Preprocessor >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#include "pragmas.h"
#include <p18f45k22.h>

// Constants >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define LED_MASK	0x0F
#define LED_SHIFT	4

#define TRUE	1	
#define FALSE	0	

// Global Variables >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Functions >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/*>>> oscConfig: >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Desc:		This function configures FOSC to 4MHz
Input: 		None
Returns:	None
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
void oscConfig (void)
{
	OSCCON = 0x52;
	while( !OSCCONbits.HFIOFS );	// Wait for freq. to be stable.
}//eo oscConfig::

/*>>> portConfig: >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Desc:		This function configures the port pins to work with the 
			2_mult_push_leds.dch schematics
Input: 		None
Returns:	None
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
void portConfig (void)
{
	ANSELA 	= 0x00;	// Set all to digital
	LATA 	= 0x00; // No output voltage
	TRISA	= 0xFF;	// Set all to input direction
	
	ANSELB 	= 0x00;	// Set all to digital
	LATB 	= 0x00; // No output voltage
	TRISB	= 0xFF;	// Set all to input direction
	
	ANSELC 	= 0x00;	// Set all to digital
	LATC 	= 0x00; // Lower nibble on to turn off LEDs (Active Low)
	TRISC	= 0xFF;	// Lower Nibble, Output (RC0-3)
	
	ANSELD 	= 0x00;	// Set all to digital
	LATD 	= 0x00; // No output voltage
	TRISD	= 0xF0;	// Except D0,1,2,3 Other pins confifured as Input
	
	ANSELE 	= 0x00;	// Set all to digital, RE2 set to analog
	LATE 	= 0x00; // No output voltage
	TRISE	= 0xFF;	// Set all to input direction	
}//eo portConfig::

/*>>> initializeSystem: >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Desc:		Calls all the config functions for this platform.
Input: 		None
Returns:	None
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
void initializeSystem (void)
{
	oscConfig();	// configs the Fosc to 4MHz
	portConfig();	// configs all the port pins for this code.
} // eo initializeSystem::

/*>>> MAIN: FUNCTION >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
void main( void )	
{	
	initializeSystem();
	
	// Indefinite Loop
	while(1)
	{
		LATD = (LED_MASK & ((~PORTD) >> LED_SHIFT)); 
	}
} // eo main::



