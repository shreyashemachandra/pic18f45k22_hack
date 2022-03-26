//>>> Program Header >>>
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	File Name:	push_to_led.c
	Author:		Shreyas Hemachandra
	Date:		14/03/2022
	Modified:	None

	Description: LED is connected to PORTB3 and Push Button is connected to RD7.
				This program lites up LED when the push button is pushed. 
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/

// Preprocessor >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#include "pragmas.h"
#include <p18f45k22.h>

// Constants >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define TRUE	1
#define FALSE	0	

// Global Variables >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// Functions >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// >>> Function Header >>>
/*>>> portConfig: >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
Author:		Shreyas
Date:		14/03/2022
Modified:	None
Desc:		Configures the each Pins used.
Input: 		None
Returns:	None
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
void portConfig(void)
{
	ANSELA = 0x00; /* All Digital Pins */
	LATA   = 0x00; /* All Pins OFF */
	TRISA  = 0xFF; /* All Input */

	ANSELB = 0x00; /* All Digital Pins */
	LATB   = 0x00; /* All Pins OFF */
	TRISB  = 0xF7; /* All Input, RB3 set to Output */

	ANSELC = 0x00; /* All Digital Pins */
	LATC   = 0x00; /* All Pins OFF */
	TRISC  = 0xFF; /* All Input */

	ANSELD = 0x00; /* All Digital Pins */
	LATD   = 0x00; /* All Pins OFF */
	TRISD  = 0xFF; /* All Input */

	ANSELE = 0x00; /* All Digital Pins */
	LATE   = 0x00; /* All Pins OFF */
	TRISE  = 0xFF; /* All Input */

} // eo portConfig::

/*>>> MAIN: FUNCTION >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
void main( void )
{
	portConfig ();

	while (1)
	{
		LATBbits.LATB3 = !PORTDbits.RD7;
	}

 // eo main::		
}


