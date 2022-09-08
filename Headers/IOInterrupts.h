/*
<title>iokit/IOKit/IOInterrupts.h Source</title>
</head><body>
<h1>Source to iokit/IOKit/IOInterrupts.h</h1>
<hr><form action="/cgi-bin/src2html.cgi" method="POST">
<input type="submit" value="Search">
<input type="text" name="xnu/newsrc">
Enter a symbol's name here to quickly find it.
</form><hr>
<pre>/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
 *
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="b6f7e6e6faf3e9fafff5f3f8e5f3e9fef3f7f2f3e4e9e5e2f7e4e2f6">[email&#160;protected]</a>
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
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="e5a4b5b5a9a0baa9aca6a0abb6a0baada0a4a1a0b7baa0aba1a5">[email&#160;protected]</a>
 */
/*
 * Copyright (c) 1999 Apple Computer, Inc.  All rights reserved. 
 *
 *  DRI: Josh de Cesare
 *
 */


#ifndef _IOKIT_IOINTERRUPTS_H
#define <a name="_IOKIT_IOINTERRUPTS_H" < a><b>_IOKIT_IOINTERRUPTS_H</b>

#define <a name="kIOInterruptTypeEdge" < a><b>kIOInterruptTypeEdge</b>  (0)
#define <a name="kIOInterruptTypeLevel" < a><b>kIOInterruptTypeLevel</b> (1)

#ifdef __cplusplus

class <a name="OSData" < a><b>OSData</b>;
class <a name="IOInterruptController" < a><b>IOInterruptController</b>;

struct <a name="IOInterruptSource" < a><b>IOInterruptSource</b> {
  IOInterruptController *interruptController;
  OSData                *vectorData;
};
typedef struct IOInterruptSource IOInterruptSource;

#endif /* __cplusplus */

typedef void (*IOInterruptHandler)(void *<a name="target" < a><b>target</b>, void *<a name="refCon" < a><b>refCon</b>,
				   void *<a name="nub" < a><b>nub</b>, int source);

#endif /* ! _IOKIT_IOINTERRUPTS_H */










/* data-cfasync="false" src="/cdn-cgi/scripts/5c5dd728/cloudflare-static/email-decode.min.js">*/
