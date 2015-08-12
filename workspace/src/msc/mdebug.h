#ifndef _MDEBUG_H_
#define _MDEBUG_H_

/****************************************************************************
 *
 *            Copyright (c) 2005 by HCC Embedded 
 *
 * This software is copyrighted by and is the sole property of 
 * HCC.  All rights, title, ownership, or other interests
 * in the software remain the property of HCC.  This
 * software may only be used in accordance with the corresponding
 * license agreement.  Any unauthorized use, duplication, transmission,  
 * distribution, or disclosure of this software is expressly forbidden.
 *
 * This Copyright notice may not be removed or modified without prior
 * written consent of HCC.
 *
 * HCC reserves the right to modify this software without notice.
 *
 * HCC Embedded
 * Budapest 1132
 * Victor Hugo Utca 11-15
 * Hungary
 *
 * Tel:  +36 (1) 450 1302
 * Fax:  +36 (1) 450 1303
 * http: www.hcc-embedded.com
 * email: info@hcc-embedded.com
 *
 ***************************************************************************/
//debug modes are: DEBMODE_NONE, DEBMODE_DUMP, DEBMODE_STDO
#define DEBMODE_NONE	0
#define DEBMODE_DUMP	1
#define DEBMODE_STDO	2

#define DEBUGMODE		DEBMODE_NONE

#if	  (DEBUGMODE == DEBMODE_NONE)
	#define DEBOPEN()			do {} while (0)
	#define DEBPR0(s)			do {} while (0)
	#define DEBPR1(s,p1)		do {} while (0)
	#define DEBPR2(s,p1,p2)		do {} while (0)
	#define DEBPR3(s,p1,p2,p3)	do {} while (0)

#elif (DEBUGMODE == DEBMODE_DUMP)
	#include "stdio.h"

	#ifdef _MLAYER_C_
		FILE *debfile=0;
		tu08CPU   debug_init = 0;
	#else
		extern FILE *debfile;
		extern tu08CPU   debug_init;
	#endif

	#define DEBOPEN()			do {if (!debfile) debfile=fopen("C:/HCCDeb.txt","wt+"); debug_init=1;	} while (0)
	#define DEBPR0(s)			do {if(debug_init == 0) DEBOPEN(); fprintf (debfile,s); 				} while (0)
	#define DEBPR1(s,p1)		do {if(debug_init == 0) DEBOPEN(); fprintf (debfile,s,p1); 				} while (0)
	#define DEBPR2(s,p1,p2)		do {if(debug_init == 0) DEBOPEN(); fprintf (debfile,s,p1,p2);			} while (0)
	#define DEBPR3(s,p1,p2,p3)	do {if(debug_init == 0) DEBOPEN(); fprintf (debfile,s,p1,p2,p3);		} while (0)

#elif (DEBUGMODE == DEBMODE_STDO)
	#include "stdio.h"

	#define DEBOPEN()			do {											} while (0)
	#define DEBPR0(s)			do {printf("\r\n<DEB>"); printf (s); 			} while (0)
	#define DEBPR1(s,p1)		do {printf("\r\n<DEB>"); printf (s,p1); 		} while (0)
	#define DEBPR2(s,p1,p2)		do {printf("\r\n<DEB>"); printf (s,p1,p2);		} while (0)
	#define DEBPR3(s,p1,p2,p3)	do {printf("\r\n<DEB>"); printf (s,p1,p2,p3);	} while (0)

#else
	#error ERROR: define a valid debug mode
#endif

/****************************************************************************
 *
 * end of mdebug.h
 *
 ***************************************************************************/

#endif //_MDEBUG_H_
