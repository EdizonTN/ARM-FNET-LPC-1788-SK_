/***********************************************************
 *                   ---  BLINKY  ---
 * main.c  https://code.google.com/p/lpc1788-uart/source/checkout
 *
 *  Created on: Jul 28, 2014
 *      Author: peterj
 *      DEMO application for NXP LPCXpresso (OM13053) board
 *      MCU: LPC1788FBD208 - Cortex M3, 512kB FLASH, 64kB RAM, 12MHz
 *      ExRAM: K4S561632C - 256Mbit SDRAM, 2 pcs, total 4Mx32
 *      HW: IAR LPC-1788-SK (Olimex starter kit)
 ***********************************************************/

#include "global.h"
void cpu_serial_init(long port_number, unsigned long baud_rate);


/************************** PRIVATE DEFINITIONS *************************/

/************************** PRIVATE VARIABLES *************************/
/* SysTick Counter */
volatile unsigned long SysTickCnt;

/************************** PRIVATE FUNCTIONS *************************/
void SysTick_Handler (void);

void Delay (unsigned long tick);

/*----------------- INTERRUPT SERVICE ROUTINES --------------------------*/
/*********************************************************************//**
 * @brief		SysTick handler sub-routine (1ms)
 * @param[in]	None
 * @return 		None
 **********************************************************************/
void SysTick_Handler (void)
{
	SysTickCnt++;
}

/*-------------------------SHARED FUNCTIONS------------------------------*/
/* ********************************************************************* */


void cpu_serial_init(long port_number, unsigned long baud_rate)
{
  UART_CFG_Type UARTConfigStruct;

  UART_ConfigStructInit(&UARTConfigStruct);

  UARTConfigStruct.Baud_rate = 115200;

  // Initialize UART0 peripheral with given to corresponding parameter
  UART_Init(port_number, &UARTConfigStruct);

}


/*-------------------------PRIVATE FUNCTIONS------------------------------*/
/*********************************************************************//**
 * @brief		Delay function
 * @param[in]	tick - number milisecond of delay time
 * @return 		None
 **********************************************************************/
void Delay (unsigned long tick)
{
	unsigned long systickcnt;

	systickcnt = SysTickCnt;
	while ((SysTickCnt - systickcnt) < tick);
}


int main (void)
{
	uint8_t value = 0;
	//uint32_t cclk = CLKPWR_GetCLK(CLKPWR_CLKTYPE_CPU);
	/* Generate interrupt each 1 ms   */
	//SysTick_Config(cclk/1000 - 1);
	GPIO_Init();
	GPIO_SetDir(BRD_LED_1_CONNECTED_PORT, BRD_LED_1_CONNECTED_MASK, GPIO_DIRECTION_OUTPUT);
	GPIO_OutputValue(BRD_LED_1_CONNECTED_PORT, BRD_LED_1_CONNECTED_MASK, 1);

	FNET_START();
	GPIO_OutputValue(BRD_LED_1_CONNECTED_PORT, BRD_LED_1_CONNECTED_MASK, 0);

	while (1)
	{
		GPIO_OutputValue(BRD_LED_1_CONNECTED_PORT, BRD_LED_1_CONNECTED_MASK, value);
		fnet_poll_services();

		value = !value;
		Delay(500);
	}

 return (0);
}
