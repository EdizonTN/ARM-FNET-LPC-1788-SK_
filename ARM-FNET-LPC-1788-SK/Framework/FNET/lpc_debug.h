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

void led_init (void);

#define led1_on() LPC_GPIO0->FIOSET = (1 << 22)
#define led1_off() LPC_GPIO0->FIOCLR = (1 << 22)
#define led2_on() LPC_GPIO2->FIOSET = (1<<13)
#define led2_off() LPC_GPIO2->FIOCLR = (1<<13)

void led2_invert(void);

#endif
#endif /* LPC_DEBUG_H_ */
