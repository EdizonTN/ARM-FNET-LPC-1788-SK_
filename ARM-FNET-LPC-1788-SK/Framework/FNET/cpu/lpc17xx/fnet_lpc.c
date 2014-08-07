/*
 * fnet_lpc.c
 *
 *  Created on: Dec 9, 2012
 *      Author: matt
 */

#include "global.h"
#include "fnet.h"

#if FNET_LPC
/************************************************************************
* NAME: fnet_cpu_irq_disable
*
* DESCRIPTION: Disable IRQs
*************************************************************************/
fnet_cpu_irq_desc_t fnet_cpu_irq_disable(void)
{
	unsigned long x=0;
	NVIC->ICER[0] |= (1 << 28) ;	// disable IRQ
	x = NVIC->ISER[0]; // stub
	fnet_printf("\n..............IRQ:ENA. NVIS.ISER: %d\n",(x&(1 <<28))>>28);

	return 0;
}

/************************************************************************
* NAME: fnet_cpu_irq_enable
*
* DESCRIPTION: Enables IRQs.
*************************************************************************/
void fnet_cpu_irq_enable(fnet_cpu_irq_desc_t irq_desc)
{
	unsigned long x=0;
	NVIC->ISER[0] |= 1 << 28;	// enable IRQ
	x = NVIC->ISER[0]; // stub
	fnet_printf("\n..............IRQ:ENA. NVIS.ISER: %d\n",(x&(1 <<28))>>28);
}

// stub function, we use CMSIS for now
int fnet_cpu_isr_install(unsigned int vector_number, unsigned int priority)
{
	return FNET_OK;
}
#endif
