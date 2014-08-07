/*
 * lpc_debug.h
 *
 *  Created on: Jan 2, 2013
 *      Author: matt
 */

#ifndef LPC_DEBUG_H_
#define LPC_DEBUG_H_

#ifdef __USE_CMSIS
#include "LPC177x_8x.h"
#endif

#include "fnet_user_config.h"
#if LPC_DEBUG_LEDS

#define led1_on() GPIO_OutputValue(BRD_LED_1_CONNECTED_PORT, BRD_LED_1_CONNECTED_MASK, 0)
#define led1_off() GPIO_OutputValue(BRD_LED_1_CONNECTED_PORT, BRD_LED_1_CONNECTED_MASK, 1)
#define led2_on() GPIO_OutputValue(BRD_LED_2_CONNECTED_PORT, BRD_LED_2_CONNECTED_MASK, 0)
#define led2_off() GPIO_OutputValue(BRD_LED_2_CONNECTED_PORT, BRD_LED_2_CONNECTED_MASK, 1)

#define led2_invert() GPIO_OutputValue(BRD_LED_2_CONNECTED_PORT, BRD_LED_2_CONNECTED_MASK, ~GPIO2->PIN)

#endif
#endif /* LPC_DEBUG_H_ */
