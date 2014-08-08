/***********************************************************
 * Configuration.h
 *
 *  Created on: 25.7.2014
 *      Author: peterj
 ***********************************************************/

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_



#define CHIP_LPC177X_8X
#define __STACK_SIZE	0x400
#define __HEAP_SIZE		0xd00

#warning "Add into assembler's include also Configuration.h file!"
#define ARM_MATH_CM3


//#define DEBUG_UART_PORT       (UART_TypeDef *)UART1   // Select UART1
#define FNET_CFG_CPU_SERIAL_BAUD_DEFAULT	115200

//#define FNET_CFG_DEBUG_TRACE_ARP (1)

//LED indicators preset
#define BRD_LED_1_CONNECTED_PORT		(1)
#define BRD_LED_1_CONNECTED_PIN			(13)
#define BRD_LED_1_CONNECTED_MASK		(1 << BRD_LED_1_CONNECTED_PIN)

#define BRD_LED_2_CONNECTED_PORT		(1)
#define BRD_LED_2_CONNECTED_PIN			(18)
#define BRD_LED_2_CONNECTED_MASK		(1 << BRD_LED_2_CONNECTED_PIN)


#define _CURR_USING_BRD 			_IAR_OLIMEX_BOARD

/*********************************************************************************/
/******************* FNET Configuration -> override default one ******************/
#define FNET_CFG_CPU_LPC_ETH_ADVANCED_DEBUG		0
#define FNET_CFG_SERIAL_PRINTF_N_TO_RN			0

#define _FAPP_USER_CONFIG_H_
#define FAPP_CFG_NAME                   "VRM FNET Shell Application"
#define FAPP_CFG_SHELL_PROMPT           "SHELL> "
/*  "dhcp" command.*/

#define FAPP_CFG_DHCP_CMD               (0)
#define FAPP_CFG_DHCP_CMD_DISCOVER_MAX  (5)
/*  "set/get" command.*/
#define FAPP_CFG_SETGET_CMD_IP          (0)
#define FAPP_CFG_SETGET_CMD_GATEWAY     (0)
#define FAPP_CFG_SETGET_CMD_NETMASK     (0)
#define FAPP_CFG_SETGET_CMD_MAC         (0)
#define FAPP_CFG_SETGET_CMD_DNS         (0)
/*  "info" command. */
#define FAPP_CFG_INFO_CMD               (0)
/*  "http" command.*/
#define FAPP_CFG_HTTP_CMD               (0)
/*  "exp" command.*/
#define FAPP_CFG_EXP_CMD                (0)
/*  "telnet" command.*/
#define FAPP_CFG_TELNET_CMD             (0)
/*  "dns" command.*/
#define FAPP_CFG_DNS_CMD                (0)
/*  "save" command.*/
#define FAPP_CFG_SAVE_CMD               (0)
/*  "reset" command.*/
#define FAPP_CFG_RESET_CMD              (0)
/* Reading of the configuration parameters
 * from the Flash memory during the application bootup. */
#define FAPP_CFG_PARAMS_READ_FLASH      (0)
/* Rewriting of the configuration parameters in
 * the Flash memory duiring flashing of the application. */
#define FAPP_CFG_PARAMS_REWRITE_FLASH   (0)
/*  "ping" command.*/
#define FAPP_CFG_PING_CMD               (0)
#if 1 /* To run HTTP and Telnet server on startup set to 1. */
    #define FAPP_CFG_STARTUP_SCRIPT_ENABLED	(0)
    #define FAPP_CFG_STARTUP_SCRIPT     "http; telnet"
#endif






#endif /* CONFIGURATION_H_ */
