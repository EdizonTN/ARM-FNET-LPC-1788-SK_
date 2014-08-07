/*
===============================================================================
 Name        : main.c
 Author      : 
 Version     :
 Copyright   : Copyright (C) 
 Description : main definition
===============================================================================
*/


#include "global.h"

int FNET_main(void);


#ifdef __CODE_RED
#include <cr_section_macros.h>
#include <NXP/crp.h>

// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
__CRP const unsigned int CRP_WORD = CRP_NO_CRP ;

#endif
// TODO: insert other include files here

// TODO: insert other definitions and declarations here

#include "fnet.h"
#include "fnet_arp.h"
#include "fnet_cpu.h"

#include "fnet_dhcp.h"
#include "fnet_fs.h"

#include "fnet_timer_prv.h"

#include "fnet_mempool.h"
#include "lpc_debug.h"

#if FNET_CFG_FS
extern const struct fnet_fs_rom_image fnet_fs_image;
#endif

#if FNET_CFG_HTTP
extern void init_http(void);
#endif


#if FREE_MEM_DEBUG
void print_free_mem() {
	unsigned long freeHeap = fnet_free_mem_status();
	fnet_printf("F:%ld\n",freeHeap);
}
#endif

#if FNET_CFG_IP6
fnet_timer_desc_t ip6addr_timer;
void print_ipv6_addr() {
	struct fnet_netif_ip6_addr_info ip6_addr;
	fnet_netif_desc_t netif = fnet_netif_get_default();
	char ipv6addr[50];

	uint32_t loop;
	for(loop=0;loop<FNET_CFG_NETIF_IP6_ADDR_MAX;loop++) {
		int hasAddr = fnet_netif_get_ip6_addr(netif,loop,&ip6_addr);
		if (hasAddr == FNET_TRUE) {
			fnet_inet_ntop(AF_INET6, &ip6_addr, &ipv6addr[0],50);
			fnet_println("IPv6 Address: %s",ipv6addr);
		} else {
			break;
		}
	}
	fnet_timer_free(ip6addr_timer);
}
#endif

void FNET_START(void) {
	

	    /* Init UART */
		//fnet_cpu_serial_init(FNET_CFG_CPU_SERIAL_PORT_DEFAULT, 9600);
		fnet_printf("UART %i init @%u\n", FNET_CFG_CPU_SERIAL_PORT_DEFAULT, FNET_CFG_CPU_SERIAL_BAUD_DEFAULT);

		/* Enable interrupts */
		fnet_cpu_irq_enable(0);

		if (fnet_init_static() != FNET_ERR) {
			fnet_printf("\nFNET INIT is done\r");
		} else {
			fnet_printf("\nFNET INIT failed\r");
		}
#if FNET_CFG_DHCP
	fnet_netif_desc_t netif;
	struct fnet_dhcp_params dhcp_params;
	// Get current net interface.
	if ((netif = fnet_netif_get_default()) == 0) {
		fnet_printf("ERROR: Network Interface is not configurated!");
	} else {
		if (fnet_arp_init(netif) != FNET_ERR) {
			fnet_printf("ARP init success\n");
		} else {
			fnet_printf("ARP init fail\n");
		}
		fnet_memset_zero(&dhcp_params, sizeof(struct fnet_dhcp_params));

		fnet_println("DHCP ");
		// Enable DHCP client.
		if (fnet_dhcp_init(netif, &dhcp_params) != FNET_ERR) {
			fnet_println(" success");
		} else {
			fnet_println(" fail!");
		}
        }
#endif
                


#if FNET_CFG_FS
		fnet_printf("FS init ");
		if (fnet_fs_init() != FNET_ERR) {
			 fnet_printf("success\n");
			 fnet_fs_rom_register( );

			 // Mount FNET ROM FS image.
			 if( fnet_fs_mount( FNET_FS_ROM_NAME, "rom", (void *)&fnet_fs_image ) == FNET_ERR )
				 fnet_println("ERROR: FS image mount is failed!");
		} else {
			fnet_printf("fail\n");
		}
#endif
	

#if FREE_MEM_DEBUG
	fnet_timer_new(20,&print_free_mem,0);
#endif
#if FNET_CFG_IP6
	ip6addr_timer = fnet_timer_new(100,&print_ipv6_addr,0);
#endif
#if FNET_CFG_HTTP
	init_http();
#endif
	// Enter an infinite loop, just incrementing a counter
	//volatile static int x;
	//while(1) {
		//led2_on();
	//	fnet_poll_services();
	//	x++;
		//led2_off();
	//}
	//return 0 ;
}
