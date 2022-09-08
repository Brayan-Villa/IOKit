/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
 *
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="96d7c6c6dad3c9dadfd5d3d8c5d3c9ded3d7d2d3c4c9c5c2d7c4c2d6">[email&#160;protected]</a>
 * 
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.1 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 * 
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 * 
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="e6a7b6b6aaa3b9aaafa5a3a8b5a3b9aea3a7a2a3b4b9a3a8a2a6">[email&#160;protected]</a>
 */
#ifndef IOKIT_IOTIMESTAMP_H
#define <a name="IOKIT_IOTIMESTAMP_H" < a><b>IOKIT_IOTIMESTAMP_H</b>

#include &lt;kdebug.h&gt;
#include &lt;sys/kdebug.h&gt;

static inline void
<a name="IOTimeStampStartConstant" < a><b>IOTimeStampStartConstant</b>(unsigned int csc,
			 unsigned int a = 0, unsigned int b = 0,
			 unsigned int c = 0, unsigned int d = 0)
{
    KERNEL_DEBUG_CONSTANT(csc | DBG_FUNC_START, a, b, c, d, 0);
}

static inline void
<a name="IOTimeStampEndConstant" < a><b>IOTimeStampEndConstant</b>(unsigned int csc,
		       unsigned int a = 0, unsigned int b = 0,
		       unsigned int c = 0, unsigned int d = 0)
{
    KERNEL_DEBUG_CONSTANT(csc | DBG_FUNC_END, a, b, c, d, 0);
}

static inline void
<a name="IOTimeStampConstant" < a><b>IOTimeStampConstant</b>(unsigned int csc,
		    unsigned int a = 0, unsigned int b = 0,
		    unsigned int c = 0, unsigned int d = 0)
{
    KERNEL_DEBUG_CONSTANT(csc | DBG_FUNC_NONE, a, b, c, d, 0);
}

#if KDEBUG

static inline void
<a name="IOTimeStampStart" < a><b>IOTimeStampStart</b>(unsigned int csc,
                 unsigned int a = 0, unsigned int b = 0,
                 unsigned int c = 0, unsigned int d = 0)
{
    KERNEL_DEBUG(csc | DBG_FUNC_START, a, b, c, d, 0);
}

static inline void
<a name="IOTimeStampEnd" < a><b>IOTimeStampEnd</b>(unsigned int csc,
               unsigned int a = 0, unsigned int b = 0,
               unsigned int c = 0, unsigned int d = 0)
{
    KERNEL_DEBUG(csc | DBG_FUNC_END, a, b, c, d, 0);
}

static inline void
<a name="IOTimeStamp" < a><b>IOTimeStamp</b>(unsigned int csc,
            unsigned int a = 0, unsigned int b = 0,
            unsigned int c = 0, unsigned int d = 0)
{
    KERNEL_DEBUG(csc | DBG_FUNC_NONE, a, b, c, d, 0);
}

#endif /* KDEBUG */

#define <a name="IODBG_SCSI" < a><b>IODBG_SCSI</b>(code)	(KDBG_CODE(DBG_IOKIT, DBG_IOSCSI, code))
#define <a name="IODBG_DISK" < a><b>IODBG_DISK</b>(code)	(KDBG_CODE(DBG_IOKIT, DBG_IODISK, code))
#define <a name="IODBG_NETWORK" < a><b>IODBG_NETWORK</b>(code)	(KDBG_CODE(DBG_IOKIT, DBG_IONETWORK, code))
#define <a name="IODBG_KEYBOARD" < a><b>IODBG_KEYBOARD</b>(code)	(KDBG_CODE(DBG_IOKIT, DBG_IOKEYBOARD, code))
#define <a name="IODBG_POINTING" < a><b>IODBG_POINTING</b>(code)	(KDBG_CODE(DBG_IOKIT, DBG_IOPOINTING, code))
#define <a name="IODBG_AUDIO" < a><b>IODBG_AUDIO</b>(code)	(KDBG_CODE(DBG_IOKIT, DBG_IOAUDIO, code))
#define <a name="IODBG_FLOPPY" < a><b>IODBG_FLOPPY</b>(code)	(KDBG_CODE(DBG_IOKIT, DBG_IOFLOPPY, code))
#define <a name="IODBG_SERIAL" < a><b>IODBG_SERIAL</b>(code)	(KDBG_CODE(DBG_IOKIT, DBG_IOSERIAL, code))
#define <a name="IODBG_TTY" < a><b>IODBG_TTY</b>(code)		(KDBG_CODE(DBG_IOKIT, DBG_IOTTY, code))

/* IOKit infrastructure subclasses */
#define <a name="IODBG_WORKLOOP" < a><b>IODBG_WORKLOOP</b>(code)	(KDBG_CODE(DBG_IOKIT, DBG_IOWORKLOOP, code))
#define <a name="IODBG_INTES" < a><b>IODBG_INTES</b>(code)	(KDBG_CODE(DBG_IOKIT, DBG_IOINTES, code))
#define <a name="IODBG_TIMES" < a><b>IODBG_TIMES</b>(code)	(KDBG_CODE(DBG_IOKIT, DBG_IOCLKES, code))
#define <a name="IODBG_CMDQ" < a><b>IODBG_CMDQ</b>(code)	(KDBG_CODE(DBG_IOKIT, DBG_IOCMDQ, code))
#define <a name="IODBG_MCURS" < a><b>IODBG_MCURS</b>(code)	(KDBG_CODE(DBG_IOKIT, DBG_IOMCURS, code))
#define <a name="IODBG_MDESC" < a><b>IODBG_MDESC</b>(code)	(KDBG_CODE(DBG_IOKIT, DBG_IOMDESC, code))

/* IOKit specific codes - within each subclass */

/* DBG_IOKIT/DBG_IOSCSI codes */

/* DBG_IOKIT/DBG_IODISK codes */

/* DBG_IOKIT/DBG_IONETWORK codes */

/* DBG_IOKIT/DBG_IOKEYBOARD codes */

/* DBG_IOKIT/DBG_IOPOINTING codes */

/* DBG_IOKIT/DBG_IOAUDIO codes */

/* DBG_IOKIT/DBG_IOFLOPPY codes */

/* DBG_IOKIT/DBG_IOSERIAL codes */

/* DBG_IOKIT/DBG_IOTTY codes */

/* DBG_IOKIT/DBG_IOWORKLOOP codes */
#define <a name="IOWL_CLIENT" < a><b>IOWL_CLIENT</b>	1	/* 0x050a0004 */
#define <a name="IOWL_WORK" < a><b>IOWL_WORK</b>	2	/* 0x050a0008 */

/* DBG_IOKIT/DBG_IOINTES codes */
#define <a name="IOINTES_CLIENT" < a><b>IOINTES_CLIENT</b>	1	/* 0x050b0004 */
#define <a name="IOINTES_LAT" < a><b>IOINTES_LAT</b>	2	/* 0x050b0008 */
#define <a name="IOINTES_SEMA" < a><b>IOINTES_SEMA</b>	3	/* 0x050b000c */
#define <a name="IOINTES_INTCTXT" < a><b>IOINTES_INTCTXT</b> 4	/* 0x050b0010 */
#define <a name="IOINTES_INTFLTR" < a><b>IOINTES_INTFLTR</b> 5	/* 0x050b0014 */
#define <a name="IOINTES_ACTION" < a><b>IOINTES_ACTION</b>	6	/* 0x050b0018 */
#define <a name="IOINTES_FILTER" < a><b>IOINTES_FILTER</b>	7	/* 0x050b001c */

/* DBG_IOKIT/DBG_IOTIMES codes */
#define <a name="IOTIMES_CLIENT" < a><b>IOTIMES_CLIENT</b>	1	/* 0x050c0004 */
#define <a name="IOTIMES_LAT" < a><b>IOTIMES_LAT</b>	2	/* 0x050c0008 */
#define <a name="IOTIMES_SEMA" < a><b>IOTIMES_SEMA</b>	3	/* 0x050c000c */
#define <a name="IOTIMES_ACTION" < a><b>IOTIMES_ACTION</b>	4	/* 0x050c0010 */

/* DBG_IOKIT/DBG_IOCMDQ codes */
#define <a name="IOCMDQ_CLIENT" < a><b>IOCMDQ_CLIENT</b>	1	/* 0x050d0004 */
#define <a name="IOCMDQ_LAT" < a><b>IOCMDQ_LAT</b>	2	/* 0x050d0008 */
#define <a name="IOCMDQ_SEMA" < a><b>IOCMDQ_SEMA</b>	3	/* 0x050d000c */
#define <a name="IOCMDQ_PSEMA" < a><b>IOCMDQ_PSEMA</b>	4	/* 0x050d0010 */
#define <a name="IOCMDQ_PLOCK" < a><b>IOCMDQ_PLOCK</b>	5	/* 0x050d0014 */
#define <a name="IOCMDQ_ACTION" < a><b>IOCMDQ_ACTION</b>	6	/* 0x050d0018 */

/* DBG_IOKIT/DBG_IOMCURS codes */

/* DBG_IOKIT/DBG_IOMDESC codes */

#endif /* ! IOKIT_IOTIMESTAMP_H */



