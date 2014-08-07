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
void HW_initialize_ETH(void);

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

  UARTConfigStruct.Baud_rate = baud_rate;

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

void HardFault_Handler(void)
{
	uint8_t value = 0;
	value = 1;
	value ++;
	//fnet_printf("!HARD FAULT!   \n");
}

// MII ethernet interface
void HW_initialize_ETH(void)
{
  PINSEL_ConfigPin(1,0,1);		// P1.0 - alternate function no.1, FUNC_ENET_TXD0
  PINSEL_ConfigPin(1,1,1);		// P1.1 - alternate function no.1, FUNC_ENET_TXD1
  PINSEL_ConfigPin(1,4,1);		// P1.4 - alternate function no.1, FUNC_ENET_TX_EN
  PINSEL_ConfigPin(1,8,1);		// P1.8 - alternate function no.1, FUNC_ENET_CRS
  PINSEL_ConfigPin(1,9,1);		// P1.9 - alternate function no.1, FUNC_ENET_RXD0
  PINSEL_ConfigPin(1,14,1);		// P1.14 - alternate function no.1, FUNC_ENET_RX_ER
  PINSEL_ConfigPin(1,15,1);		// P1.15 - alternate function no.1, ENET_RX_CLK
  PINSEL_ConfigPin(1,16,1);		// P1.16 - alternate function no.1, FUNC_ENET_MDC
  PINSEL_ConfigPin(1,17,1);		// P1.16 - alternate function no.1, FUNC_ENET_MDIO

}

void Initialize_UART(long port_number, unsigned long baud_rate)
{
  UART_ID_Type Used_Uart = (UART_ID_Type) port_number;

  // UART Configuration structure variable
  UART_CFG_Type UARTConfigStruct;
  // UART FIFO configuration Struct variable
  UART_FIFO_CFG_Type UARTFIFOConfigStruct;

  // uint32_t idx, len;
  // FlagStatus exitflag;
  // uint8_t buffer[10];

  switch (port_number)
  {
    case 1:	// Initialize UART1 pin connect: P0.15: U1_TXD, P0.16: U1_RXD
      {
	PINSEL_ConfigPin(0,15,1);
	PINSEL_ConfigPin(0,16,1);
	break;
      }
    case 2: 	// Initialize UART2 pin connect: P0.10: U2_TXD, P0.11: U2_RXD
      {
	PINSEL_ConfigPin(0,10,1);
	PINSEL_ConfigPin(0,11,1);
	break;
      }
    case 3:	// Initialize UART3 pin connect: P0.2: U3_TXD, P0.3: U3_RXD
      {
	PINSEL_ConfigPin(0,2,2);
	PINSEL_ConfigPin(0,3,2);
	break;
      }
    case 4:	// Initialize UART4 pin connect: P0.22: U4_TXD, P2.9: U4_RXD
      {
	PINSEL_ConfigPin(0,22,3);
	PINSEL_ConfigPin(2,9,3);
	break;
      }
    default:	// Initialize UART0 pin connect: P0.2: U0_TXD, P0.3: U0_RXD
      {
       PINSEL_ConfigPin(0,2,1);
       PINSEL_ConfigPin(0,3,1);
      }
  }


  // Initialize UART Configuration parameter structure to default state:
  // Baudrate = $baud_rate, 8 data bit, 1 Stop bit, None parity
  UART_ConfigStructInit(&UARTConfigStruct);

  // Initialize UART peripheral with given to corresponding parameter
  UART_Init(Used_Uart, &UARTConfigStruct);

  //	Initialize FIFOConfigStruct to default state:
  //	- FIFO_DMAMode = DISABLE
  //	- FIFO_Level = UART_FIFO_TRGLEV0
  //	- FIFO_ResetRxBuf = ENABLE
  //	- FIFO_ResetTxBuf = ENABLE
  //	- FIFO_State = ENABLE
  UART_FIFOConfigStructInit(&UARTFIFOConfigStruct);

  // Initialize FIFO for UART0 peripheral
  UART_FIFOConfig(Used_Uart, &UARTFIFOConfigStruct);

  // Enable UART Transmit
  UART_TxCmd(Used_Uart, ENABLE);
}


int main (void)
{
	uint32_t value = 0;

	//uint32_t cclk = CLKPWR_GetCLK(CLKPWR_CLKTYPE_CPU);
	/* Generate interrupt each 1 ms   */
	//SysTick_Config(cclk/1000 - 1);

	GPIO_Init();
	GPIO_SetDir(BRD_LED_1_CONNECTED_PORT, BRD_LED_1_CONNECTED_MASK, GPIO_DIRECTION_OUTPUT);
	GPIO_SetDir(BRD_LED_2_CONNECTED_PORT, BRD_LED_2_CONNECTED_MASK, GPIO_DIRECTION_OUTPUT);
	led1_off(); led2_off();

	Initialize_UART(FNET_CFG_CPU_SERIAL_PORT_DEFAULT, FNET_CFG_CPU_SERIAL_BAUD_DEFAULT);

	led1_on(); led2_on();
	FNET_START();
	led1_off(); led2_off();

	fnet_printf("Goto main loop...\n");
	while (1)
	{
		if (value >0x100) { value =0; }
		fnet_poll_services();
		value ++ ;
	}

 return (0);
}
