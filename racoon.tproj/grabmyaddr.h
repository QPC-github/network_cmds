/*	$KAME: grabmyaddr.h,v 1.6 2001/12/12 15:29:12 sakane Exp $	*/

/*
 * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

struct myaddrs {
	struct myaddrs *next;
	struct sockaddr *addr;
	int sock;
#ifdef IKE_NAT_T
	int	nattsock;	/* nat-traversal socket (port PORT_ISAKMP_NATT), for IPv4 sockets only */
#endif
};

extern void clear_myaddr __P((struct myaddrs **));
extern void grab_myaddrs __P((void));
extern int update_myaddrs __P((void));
extern int autoconf_myaddrsport __P((void));
extern u_short getmyaddrsport __P((struct sockaddr *));
extern struct myaddrs *newmyaddr __P((void));
extern void insmyaddr __P((struct myaddrs *, struct myaddrs **));
extern void delmyaddr __P((struct myaddrs *));
extern int initmyaddr __P((void));
extern int getsockmyaddr __P((struct sockaddr *));