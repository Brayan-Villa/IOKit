/*
<title>iokit/IOKit/IODeviceTreeSupport.h Source</title>
</head><body>
<h1>Source to iokit/IOKit/IODeviceTreeSupport.h</h1>
<hr><form action="/cgi-bin/src2html.cgi" method="POST">
<input type="submit" value="Search">
<input type="text" name="xnu/newsrc">
Enter a symbol's name here to quickly find it.
</form><hr>
<pre>/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
 *
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="ebaabbbba7aeb4a7a2a8aea5b8aeb4a3aeaaafaeb9b4b8bfaab9bfab">[email&#160;protected]</a>
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
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="beffeeeef2fbe1f2f7fdfbf0edfbe1f6fbfffafbece1fbf0fafe">[email&#160;protected]</a>
 */
/*
 * Copyright (c) 1998 Apple Computer, Inc.  All rights reserved. 
 *
 * HISTORY
 *
 */

#ifndef _IOKIT_IODEVICETREE_H
#define  _IOKIT_IODEVICETREE_H = _IOKIT_IODEVICETREE_H = 

#include <IOKit/IORegistryEntry.h>
#include <libkern/c++/OSData.h>

class  IODeviceMemory = IODeviceMemory = ;
class IOService;

extern const IORegistryPlane *	 gIODTPlane = gIODTPlane = ;

extern const OSSymbol *		 gIODTCompatibleKey = gIODTCompatibleKey = ;
extern const OSSymbol * 	 gIODTTypeKey = gIODTTypeKey = ;
extern const OSSymbol * 	 gIODTModelKey = gIODTModelKey = ;

extern const OSSymbol *		 gIODTAAPLInterruptsKey = gIODTAAPLInterruptsKey = ;
extern const OSSymbol *		 gIODTDefaultInterruptController = gIODTDefaultInterruptController = ;
extern const OSSymbol *		 gIODTNWInterruptMappingKey = gIODTNWInterruptMappingKey = ;

IORegistryEntry * IODeviceTreeAlloc( void * dtTop );


bool IODTMatchNubWithKeys( IORegistryEntry * nub,
                                    const char * keys );

bool IODTCompareNubName( const IORegistryEntry * regEntry,
			 OSString * name, OSString ** matchingName );

enum {
    kIODTRecursive	= 0x00000001,
    kIODTExclusive	= 0x00000002,
};

OSCollectionIterator * IODTFindMatchingEntries( IORegistryEntry * from,
			IOOptionBits options, const char * keys );

typedef SInt32 (*IODTCompareAddressCellFunc)
	(UInt32  cellCount = cellCount = , UInt32  left = left = [], UInt32  right = right = []);
typedef void (*IODTNVLocationFunc)
	(IORegistryEntry *  entry = entry = ,
	UInt8 *  busNum = busNum = , UInt8 *  deviceNum = deviceNum = , UInt8 *  functionNum = functionNum =  );

void IODTSetResolving( IORegistryEntry * 	regEntry,
		IODTCompareAddressCellFunc	compareFunc,
		IODTNVLocationFunc		locationFunc );

bool IODTResolveAddressCell( IORegistryEntry * regEntry,
                             UInt32 cellsIn[],
                             IOPhysicalAddress * phys, IOPhysicalLength * len );

OSArray * IODTResolveAddressing( IORegistryEntry * regEntry,
			const char * addressPropertyName,
			IODeviceMemory * parent );

#pragma options align=mac68k

struct  IONVRAMDescriptor = IONVRAMDescriptor =  {
    unsigned int format:4;
    unsigned int marker:1;
    unsigned int bridgeCount:3;
    unsigned int busNum:2;
    unsigned int bridgeDevices:6 * 5;
    unsigned int functionNum:3;
    unsigned int deviceNum:5;
};

#pragma options align=reset

IOReturn IODTMakeNVDescriptor( IORegistryEntry * regEntry,
				IONVRAMDescriptor * hdr );

OSData * IODTFindSlotName( IORegistryEntry * regEntry, UInt32 deviceNumber );

const OSSymbol * IODTInterruptControllerName(
			IORegistryEntry * regEntry );

bool IODTMapInterrupts( IORegistryEntry * regEntry );

#ifdef __cplusplus
extern "C" {
#endif

IOReturn IONDRVLibrariesInitialize( IOService * provider );

#ifdef __cplusplus
}
#endif

#endif /* _IOKIT_IODEVICETREE_H */











/* data-cfasync="false" src="/cdn-cgi/scripts/5c5dd728/cloudflare-static/email-decode.min.js">*/
