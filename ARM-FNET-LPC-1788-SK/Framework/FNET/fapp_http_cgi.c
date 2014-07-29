/*
 * fapp_http_cgi.c
 *
 *  Created on: Jan 2, 2013
 *      Author: matt
 */

/**************************************************************************
*
* Copyright 2012 by Andrey Butok. FNET Community.
* Copyright 2005-2011 by Andrey Butok. Freescale Semiconductor, Inc.
*
***************************************************************************
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License Version 3
* or later (the "LGPL").
*
* As a special exception, the copyright holders of the FNET project give you
* permission to link the FNET sources with independent modules to produce an
* executable, regardless of the license terms of these independent modules,
* and to copy and distribute the resulting executable under terms of your
* choice, provided that you also meet, for each linked independent module,
* the terms and conditions of the license of that module.
* An independent module is a module which is not derived from or based
* on this library.
* If you modify the FNET sources, you may extend this exception
* to your version of the FNET sources, but you are not obligated
* to do so. If you do not wish to do so, delete this
* exception statement from your version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* You should have received a copy of the GNU General Public License
* and the GNU Lesser General Public License along with this program.
* If not, see <http://www.gnu.org/licenses/>.
*
**********************************************************************/

//static fnet_http_desc_t fapp_http_desc = 0; /* HTTP service descriptor. */

#include "fnet.h"

unsigned static long fapp_http_string_buffer_respond(char * buffer, unsigned long buffer_size, char * eof, long *cookie);

#if FNET_CFG_HTTP

#if FNET_CFG_HTTP_CGI
static int fapp_http_cgi_stdata_handle(char * query, long *cookie);
static int fapp_http_cgi_graph_handle(char * query, long *cookie);

static const struct fnet_http_cgi fapp_cgi_table[] =
{
    {"stdata.cgi", fapp_http_cgi_stdata_handle, fapp_http_string_buffer_respond},
    {"graph.cgi", fapp_http_cgi_graph_handle, fapp_http_string_buffer_respond},
#if FNET_CFG_HTTP_POST
    {"post.cgi", fapp_http_cgi_post_handle, fapp_http_string_buffer_respond},
#endif
    {0, 0, 0} /* End of the table. */
};

#endif
//struct sockaddr http_listen_all = {
//		AF_INET,
//		0,
//		0
//};


fnet_netif_desc_t fapp_default_netif;

void init_http() {
	fapp_default_netif = fnet_netif_get_default();

	struct fnet_http_params params;
	fnet_memset_zero(&params, sizeof(struct fnet_http_params));
	params.root_path = "rom";
	params.index_path = "index.html";
	//params.address = http_listen_all;

#if FNET_CFG_HTTP_CGI
	params.cgi_table = &fapp_cgi_table[0];
#endif
	fnet_http_desc_t httpSrv = fnet_http_init(&params);
	fnet_printf("http ");
	if (httpSrv != FNET_ERR) {
		fnet_println("ok");
	} else {
		fnet_println("fail");
	}
}
#if FNET_CFG_HTTP_CGI


#if FNET_CFG_HTTP_POST
int fapp_http_cgi_post_handle(char * query, long *cookie);
#endif


/* CGI table */
#define CGI_MAX        sizeof("({ \"time\":\"00:00:00\",\"tx\":0000000000,\"rx\":0000000000})")
static char fapp_http_cgi_buffer[CGI_MAX]; /* CGI Temporary buffer. */


/************************************************************************
* NAME: fapp_http_cgi_stdata_handle
*
* DESCRIPTION:
*************************************************************************/
static int fapp_http_cgi_stdata_handle(char * query, long *cookie)
{
    unsigned long time, t_hour, t_min, t_sec;
	struct fnet_netif_statistics statistics;

    FNET_COMP_UNUSED_ARG(query);

	/* Get Time. */
	time = fnet_timer_ticks();
	t_hour = time/FNET_TIMER_TICK_IN_HOUR;
	t_min  = (time%FNET_TIMER_TICK_IN_HOUR)/FNET_TIMER_TICK_IN_MIN;
	t_sec  = (time%FNET_TIMER_TICK_IN_MIN)/FNET_TIMER_TICK_IN_SEC;

	/* Get statistics. */
    fnet_memset_zero( &statistics, sizeof(struct fnet_netif_statistics) );
    fnet_netif_get_statistics(fapp_default_netif, &statistics);

	/* Write to the temprorary buffer. */
    fnet_snprintf(fapp_http_cgi_buffer, sizeof(fapp_http_cgi_buffer), "({ \"time\":\"%02d:%02d:%02d\",\"tx\":%d,\"rx\":%d})",
                             t_hour, t_min, t_sec, statistics.tx_packet, statistics.rx_packet);

    *cookie = (long)fapp_http_cgi_buffer; /* Save fapp_http_cgi_buffer as cookie.*/

    return FNET_OK;
}

#define FAPP_HTTP_CGI_GRAPH_MIN     (30)
static int fapp_http_cgi_rand_next;
/************************************************************************
* NAME: fapp_http_cgi_rand
*
* DESCRIPTION:
*************************************************************************/
static unsigned int fapp_http_cgi_rand(void)
{
  fapp_http_cgi_rand_next = fapp_http_cgi_rand_next * 11 + 12;
  return (unsigned int)(((fapp_http_cgi_rand_next>>4) & 0xFF) + FAPP_HTTP_CGI_GRAPH_MIN);
}

/************************************************************************
* NAME: fapp_http_cgi_graph_handle
*
* DESCRIPTION:
*************************************************************************/
static int fapp_http_cgi_graph_handle(char * query, long *cookie)
{
    int q1= (int)fapp_http_cgi_rand();
    int q2= (int)fapp_http_cgi_rand();
    int q3= (int)fapp_http_cgi_rand();
    int q4= (int)fapp_http_cgi_rand();
    int q5= (int)fapp_http_cgi_rand();

    FNET_COMP_UNUSED_ARG(query);

	/* Wrie to the temprorary buffer. */
    fnet_snprintf(fapp_http_cgi_buffer, sizeof(fapp_http_cgi_buffer),
                        "({\"q1\":%d,\"q2\":%d,\"q3\":%d,\"q4\":%d,\"q5\":%d})",
                        q1, q2, q3, q4, q5);

    *cookie = (long)fapp_http_cgi_buffer; /* Save fapp_http_cgi_buffer as cookie.*/

    return FNET_OK;
}

#endif

static unsigned long fapp_http_string_buffer_respond(char * buffer, unsigned long buffer_size, char * eof, long *cookie)
{
    unsigned long result = 0;

    char *string_buffer_ptr = (char *) *cookie;

    unsigned long send_size = fnet_strlen(string_buffer_ptr);


    *eof = 1; /* No aditional send by default. */

    if(buffer && buffer_size)
    {
	    if(send_size>buffer_size)
	        send_size = buffer_size;

	    fnet_memcpy(buffer, string_buffer_ptr, send_size);

	    string_buffer_ptr += send_size;
	    if(*string_buffer_ptr!='\0') /* If any data for sending.*/
	        *eof = 0;    /* Need more itteration. */

	    result = send_size;

	    *cookie = (long)string_buffer_ptr; /* Save cgi_buffer_ptr as cookie.*/
    }

    return result;
}

#endif
