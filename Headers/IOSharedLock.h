/*
<title>iokit/IOKit/IOSharedLock.h Source</title>
</head><body>
<h1>Source to iokit/IOKit/IOSharedLock.h</h1>
<hr><form action="/cgi-bin/src2html.cgi" method="POST">
<input type="submit" value="Search">
<input type="text" name="xnu/newsrc">
Enter a symbol's name here to quickly find it.
</form><hr>
<pre>/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
 *
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="3f7e6f6f737a6073767c7a716c7a60777a7e7b7a6d606c6b7e6d6b7f">[email&#160;protected]</a>
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
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="a7e6f7f7ebe2f8ebeee4e2e9f4e2f8efe2e6e3e2f5f8e2e9e3e7">[email&#160;protected]</a>
 */
/*
 * Copyright (c) 1998 Apple Computer, Inc.  All rights reserved. 
 *
 * HISTORY
 *
 */

/*
 * Multiprocessor locks used within the shared memory area between the
 * kernel and event system.  These must work in both user and kernel mode.
 * 
 * These routines are public, for the purpose of writing frame buffer device
 * drivers which handle their own cursors.  Certain architectures define a
 * generic display class which handles cursor drawing and is subclassed by
 * driver writers.  These drivers need not be concerned with the following
 * types and definitions.
 *
 * The ev_lock(), ev_unlock(), and ev_try_lock() functions are available only
 * to drivers built in or dynamically loaded into the kernel, and to DPS
 * drivers built in or dynamically loaded into the Window Server.  They do not
 * exist in any shared library.
 *
 * --&gt; They're now in IOKit user lib.
 */

#ifndef _IOKIT_IOSHAREDLOCK_H
#define <a name="_IOKIT_IOSHAREDLOCK_H" < a><b>_IOKIT_IOSHAREDLOCK_H</b>

#ifdef __cplusplus
extern "C" {
#endif

// should be 32 bytes on PPC
typedef volatile int		<a name="IOSharedLockData" < a><b>IOSharedLockData</b>;
typedef <a name="IOSharedLock" < a><b>IOSharedLock</b>Data    *   IOSharedLock;

#define <a name="IOSpinLockInit" < a><b>IOSpinLockInit</b>(l)	(*(l) = (IOSpinLockData)0)

extern void IOSpinLock(IOSharedLock l);
extern void IOSpinUnlock(IOSharedLock l);
extern boolean_t IOTrySpinLock(IOSharedLock l);

/* exact same stuff &amp; implementation */

typedef IOSharedLockData 	<a name="ev_lock_data_t" < a><b>ev_lock_data_t</b>;
typedef ev_lock_data_t	    *	<a name="ev_lock_t" < a><b>ev_lock_t</b>;

#define <a name="ev_init_lock" < a><b>ev_init_lock</b>(l)		(*(l) = (ev_lock_data_t)0)
// needs isync?
//#define <a name="ev_is_locked" < a><b>ev_is_locked</b>(l)	(*(l) != (ev_lock_data_t)0)

extern void ev_lock(ev_lock_t l);		// Spin lock!
extern void ev_unlock(ev_lock_t l);
extern boolean_t ev_try_lock(ev_lock_t l);

#ifdef __cplusplus
}
#endif
#endif /* ! _IOKIT_IOSHAREDLOCK_H */










/* data-cfasync="false" src="/cdn-cgi/scripts/5c5dd728/cloudflare-static/email-decode.min.js">*/
