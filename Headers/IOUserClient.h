/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
 *
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="bffeefeff3fae0f3f6fcfaf1ecfae0f7fafefbfaede0ecebfeedebff">[email&#160;protected]</a>
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
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="420312120e071d0e0b01070c11071d0a07030607101d070c0602">[email&#160;protected]</a>
 */

/*
 * Changes to this API are expected.
 */

#ifndef _IOKIT_IOUSERCLIENT_H
#define <a name="_IOKIT_IOUSERCLIENT_H" < a><b>_IOKIT_IOUSERCLIENT_H</b>

#include &lt;IOKit/IOTypes.h&gt;
#include &lt;IOKit/IOService.h&gt;
#include &lt;IOKit/OSMessageNotification.h&gt;


enum {
    kIOUCTypeMask	= 0x0000000f,
    kIOUCScalarIScalarO = 0,
    kIOUCScalarIStructO = 2,
    kIOUCStructIStructO = 3,
    kIOUCScalarIStructI = 4,
};

typedef IOReturn (IOService::*IOMethod)(void * <a name="p1" < a><b>p1</b>, void * <a name="p2" < a><b>p2</b>, void * <a name="p3" < a><b>p3</b>,
                                        void * <a name="p4" < a><b>p4</b>, void * <a name="p5" < a><b>p5</b>, void * <a name="p6" < a><b>p6</b> );

typedef IOReturn (IOService::*IOAsyncMethod)(OSAsyncReference <a name="asyncRef" < a><b>asyncRef</b>,
                                        void * p1, void * p2, void * p3,
                                        void * p4, void * p5, void * p6 );

struct <a name="IOExternalMethod" < a><b>IOExternalMethod</b> {
    IOService *		object;
    IOMethod		func;
    IOOptionBits	flags;
    IOByteCount		count0;
    IOByteCount		count1;
};

struct <a name="IOExternalAsyncMethod" < a><b>IOExternalAsyncMethod</b> {
    IOService *		object;
    IOAsyncMethod	func;
    IOOptionBits	flags;
    IOByteCount		count0;
    IOByteCount		count1;
};

enum {
    kIOUserNotifyMaxMessageSize = 64
};

class IOUserClient : public IOService
{
    OSDeclareAbstractStructors(IOUserClient)

protected:
    static IOReturn sendAsyncResult(OSAsyncReference reference,
                                    IOReturn result, void *args[], UInt32 numArgs);

public:

    static void initialize( void );

    static void destroyUserReferences( OSObject * obj );

    virtual IOReturn clientClose( void );
    virtual IOReturn clientDied( void );

    virtual IOService * getService( void );

    virtual IOReturn registerNotificationPort(
		mach_port_t port, UInt32 type, UInt32 refCon );

    virtual IOReturn getNotificationSemaphore( UInt32 notification_type,
                                    semaphore_t * semaphore );

    virtual IOReturn connectClient( IOUserClient * client );

    // memory will be released by user client when last map is destroyed
    virtual IOReturn clientMemoryForType( UInt32 type,
			        IOOptionBits * options,
				IOMemoryDescriptor ** memory );

    virtual IOMemoryMap * mapClientMemory( IOOptionBits type,
                                    task_t task,
                                    IOOptionBits mapFlags = kIOMapAnywhere,
				    IOVirtualAddress atAddress = 0 );

    virtual IOExternalMethod * getExternalMethodForIndex( UInt32 index );
    virtual IOExternalAsyncMethod * getExternalAsyncMethodForIndex( UInt32 index );

};

#endif /* ! _IOKIT_IOUSERCLIENT_H */



