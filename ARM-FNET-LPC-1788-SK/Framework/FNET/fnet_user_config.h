/*
 * fnet_user_config.h
 *
 *  Created on: Dec 8, 2012
 *      Author: matt
 */

#ifndef FNET_USER_CONFIG_H_
#define FNET_USER_CONFIG_H_

#define FNET_CFG_CPU_LPC1768 1
#define FNET_LPC 1
#define FNET_CFG_ETH0 1

#define FNET_CFG_TCP 1
#define FNET_CFG_IP6 0

#define FNET_CFG_OS 0
#define FNET_CFG_TELNET 1

#define FNET_CFG_HTTP 1
#define FNET_CFG_HTTP_CGI 1
#define FNET_CFG_FS_ROM 1
#define FNET_CFG_HTTP_VERSION_NUMBER 1
#define FNET_CFG_HTTP_SSI	1


#define FNET_CFG_DHCP 0
#define FNET_CFG_PING 1

#define FNET_CFG_SHELL 1
// TODO - Zvacsi HEAP aspon na 6*1536!
#define FNET_CFG_HEAP_SIZE (6*1536)
//#define FNET_CFG_HTTP_REQUEST_SIZE_MAX 1400
#define FNET_CFG_DEBUG_TIMER 0
#define FNET_CFG_DEBUG 1
#define FNET_CFG_DEBUG_TRACE 0
#define FNET_CFG_DEBUG_DHCP 1
#define FNET_CFG_DEBUG_HTTP 1
#define FNET_CFG_HTTP_VERSION_MAJOR 1

#define LPC_DEBUG_LEDS  1
#define FREE_MEM_DEBUG	0

#define FNET_CFG_TCP_URGENT                 (1)
#define FNET_CFG_IGMP                   	(0)
#define FNET_CFG_IP4                        (1)




//#define FNET_CFG_ETH_MAC_ADDR       ("0a:02:03:04:05:06")
#define FNET_CFG_OVERLOAD_MEMCPY            (0)
#define FNET_DEBUG_MEMPOOL_CHECK (1)
#define FNET_CFG_DEBUG_TRACE_UDP (1)
#define FNET_CFG_DEBUG_TRACE_ETH (1)
#define FNET_CFG_DEBUG_TRACE_ICMP (1)
#define FNET_CFG_DEBUG_TRACE_IP (1)
#define FNET_CFG_DEBUG_TRACE_TCP    (1)
#define FNET_CFG_DEBUG_TRACE_IGMP   (1)
#define FNET_CFG_DEBUG_ARP          (1)
#define FNET_CFG_DEBUG_MEMPOOL      (1)
#define FNET_CFG_DEBUG_TFTP_CLN     (1)
#define FNET_CFG_DEBUG_TFTP_SRV     (1)
#define FNET_CFG_DEBUG_STACK        (0)
#define FNET_CFG_DEBUG_TELNET       (1)
#define FNET_CFG_DEBUG_SHELL        (1)
#define FNET_CFG_DEBUG_DNS          (1)
#define FNET_CFG_DEBUG_BENCH        (1)
#define FNET_CFG_DEBUG_STARTUP_MS   (1)
#define FNET_CFG_DEBUG_IP6          (0)





#define FNET_CFG_DEBUG_TRACE_ARP (0)


#endif /* FNET_USER_CONFIG_H_ */
