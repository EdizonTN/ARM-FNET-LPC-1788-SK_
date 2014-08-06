/***********************************************************
 * global.h
 *
 *  Created on: 25.7.2014
 *      Author: peterj
 ***********************************************************/


#ifndef GLOBAL_H_
#define GLOBAL_H_

// ************ SYSTEM HEADERS ****************************************************
#include "stdint.h"


// ************ APPLICATION CONFIG ************************************************
#include "Configuration.h"


// ************ CHIP HEADERS ******************************************************
//#include "../Chip/Include/arm_common_tables.h"
//#include "../Chip/Include/arm_const_structs.h"
//#include "../Chip/Include/arm_math.h"
//#include "../Chip/Include/core_cm0.h"
//#include "../Chip/Include/core_cm0plus.h"
//#include "../Chip/Include/core_cm3.h"
//#include "../Chip/Include/core_cm4.h"
//#include "../Chip/Include/core_cm4_simd.h"
//#include "../Chip/Include/core_cmFunc.h"
//#include "../Chip/Include/core_cmInstr.h"
//#include "../Chip/Include/core_sc000.h"
//#include "../Chip/Include/core_sc300.h"

#include "../Chip/Driver/Include/lpc177x_8x_pinsel.h"
//#include "./Chip/Driver/Include/lpc17xx.h"
//#include "./Chip/Driver/Include/lpc17xx_8x_libcfg.h" // load library configuration
#include "../Chip/Driver/Include/lpc177x_8x_gpio.h"
#include "../Chip/Driver/Include/lpc177x_8x_clkpwr.h"
#include "../Chip/Driver/Include/lpc177x_8x_uart.h"
// ************ BOARD SUPPORT PACKAGE HEADERS *************************************
//I "./BSP/Include"`
 // #pragma GCC system_header

// ************ FRAMEWORK HEADERS *************************************************
#include "bsp.h"
#pragma GCC system_header
#include "fnet.h"
#include "fnet_config.h"


// export from main.c module
extern void cpu_serial_init(long port_number, unsigned long baud_rate);
extern void FNET_START(void);
extern void HW_initialize_ETH(void);

#endif /* GLOBAL_H_ */
