/*
<title>iokit/IOKit/IOKitDebug.h Source</title>
</head><body>
<h1>Source to iokit/IOKit/IOKitDebug.h</h1>
<hr><form action="/cgi-bin/src2html.cgi" method="POST">
<input type="submit" value="Search">
<input type="text" name="xnu/newsrc">
Enter a symbol's name here to quickly find it.
</form><hr>
<pre>/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
 *
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="9bdacbcbd7dec4d7d2d8ded5c8dec4d3dedadfdec9c4c8cfdac9cfdb">[email&#160;protected]</a>
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
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="89c8d9d9c5ccd6c5c0caccc7daccd6c1ccc8cdccdbd6ccc7cdc9">[email&#160;protected]</a>
 */
/*
 * Copyright (c) 1998 Apple Computer, Inc.  All rights reserved. 
 *
 * HISTORY
 *
 */


#ifndef _IOKIT_IOKITDEBUG_H
#define  _IOKIT_IOKITDEBUG_H = _IOKIT_IOKITDEBUG_H = 

#include <IOKit/IOTypes.h>


#ifdef __cplusplus

#include <libkern/c++/OSObject.h>
#include <libkern/c++/OSDictionary.h>
#include <libkern/c++/OSSerialize.h>

class IOKitDiagnostics : public OSObject
{
    OSDeclareDefaultStructors(IOKitDiagnostics)

public:
    static OSObject * diagnostics( void );
    virtual bool serialize(OSSerialize *s) const;
private:
    static void updateOffset( OSDictionary * dict,
			UInt32 value, const char * name );
};

#endif

#ifdef __cplusplus
extern "C" {
#endif

enum {
// loggage
    kIOLogAttach	= 0x00000001ULL,
    kIOLogProbe 	= 0x00000002ULL,
    kIOLogStart 	= 0x00000004ULL,
    kIOLogRegister 	= 0x00000008ULL,
    kIOLogMatch 	= 0x00000010ULL,
    kIOLogConfig 	= 0x00000020ULL,
    kIOLogYield 	= 0x00000040ULL,
    kIOLogPower 	= 0x00000080ULL,
    kIOLogMapping 	= 0x00000100ULL,
    kIOLogCatalogue 	= 0x00000200ULL,

    kIOLogServiceTree 	= 0x00001000ULL,
    kIOLogDTree 	= 0x00002000ULL,
    kIOLogMemory 	= 0x00004000ULL,

// debug aids - change behaviour
    kIONoFreeObjects 	= 0x00100000ULL
};

extern SInt64	gIOKitDebug;
extern char 	iokit_version[];

struct IORegistryPlane;
extern void	IOPrintPlane( const struct IORegistryPlane * plane );
extern void	OSPrintMemory( void );
#define IOPrintMemory OSPrintMemory

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* ! _IOKIT_IOKITDEBUG_H */










/* data-cfasync="false" src="/cdn-cgi/scripts/5c5dd728/cloudflare-static/email-decode.min.js">*/
