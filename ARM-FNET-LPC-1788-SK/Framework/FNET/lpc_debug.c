/*
 * lpc_debug.c
 *
 *  Created on: Jan 2, 2013
 *      Author: matt
 */

#ifdef __USE_CMSIS
#include "LPC177x_8x.h"
#endif

#include "fnet_user_config.h"

#if LPC_DEBUG_LEDS
void led_init (void)
{
	// Set P0_22 to 00 - GPIO
	LPC_PINCON->PINSEL1	&= (~(3 << 12));
	LPC_PINCON->PINSEL4 &= (~(3 << 26));
	// Set GPIO - P0_22 - to be output
	LPC_GPIO0->FIODIR |= (1 << 22);
	LPC_GPIO2->FIODIR |= (1 << 13);
	//LPC_GPIO0->FIODIR |= (1 << 9);
}


void led2_invert (void) {
	int ledstate;

		// Read current state of GPIO P0_0..31, which includes LED2
		ledstate = LPC_GPIO2->FIOPIN;
		// Turn off LED2 if it is on
		// (ANDing to ensure we only affect the LED output)
		LPC_GPIO2->FIOCLR = ledstate & (1 << 13);
		// Turn on LED2 if it is off
		// (ANDing to ensure we only affect the LED output)
		LPC_GPIO2->FIOSET = ((~ledstate) & (1 << 13));
}
#endif
