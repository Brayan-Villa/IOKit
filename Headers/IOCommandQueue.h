/*
<title>iokit/IOKit/IOCommandQueue.h Source</title>
</head><body>
<h1>Source to iokit/IOKit/IOCommandQueue.h</h1>
<hr><form action="/cgi-bin/src2html.cgi" method="POST">
<input type="submit" value="Search">
<input type="text" name="xnu/newsrc">
Enter a symbol's name here to quickly find it.
</form><hr>
<pre>/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
 *
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="8ccddcdcc0c9d3c0c5cfc9c2dfc9d3c4c9cdc8c9ded3dfd8cdded8cc">[email&#160;protected]</a>
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
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="5a1b0a0a161f051613191f14091f05121f1b1e1f08051f141e1a">[email&#160;protected]</a>
 */
/*
Copyright (c) 1998 Apple Computer, Inc.  All rights reserved.

HISTORY
    1998-7-13	Godfrey van der Linden(gvdl)
        Created.
    1998-10-30	Godfrey van der Linden(gvdl)
        Converted to C++
    1999-9-22	Godfrey van der Linden(gvdl)
	Deprecated
]*/
#ifndef _IOKIT_IOCOMMANDQUEUE_H
#define  _IOKIT_IOCOMMANDQUEUE_H = _IOKIT_IOCOMMANDQUEUE_H = 

#include <IOKit/IOEventSource.h>




#warning IOCommandQueue has been deprecated in favour of IOCommandGate and will be going away before too long.





class  IOCommandQueue = IOCommandQueue = ;

typedef void (*IOCommandQueueAction)
    ( OSObject = OSObject =  *, void * field0 = field0 = , void * field1 = field1 = , void * field2 = field2 = , void * field3 = field3 = );

class IOCommandQueue : public IOEventSource
{
    OSDeclareDefaultStructors(IOCommandQueue)

protected:
    static const int kIOCQDefaultSize = 32;

    void *queue;
    IOLock *producerLock;
    semaphore_port_t producerSema;
    int producerIndex, consumerIndex;
    int size;

    virtual void free();

    virtual bool checkForWork();

public:
    static IOCommandQueue *commandQueue(OSObject *inOwner,
                                        IOCommandQueueAction inAction = 0,
                                        int inSize = kIOCQDefaultSize);
    virtual bool init(OSObject *inOwner,
                      IOCommandQueueAction inAction = 0,
                      int inSize = kIOCQDefaultSize);

    virtual kern_return_t enqueueCommand(bool gotoSleep = true,
                                         void *field0 = 0, void *field1 = 0,
                                         void *field2 = 0, void *field3 = 0);

    // WARNING:  This function can only be safely called from the appropriate
    // work loop context.  You should check IOWorkLoop::onThread is true.
    //
    // For each entry in the commandQueue call the target/action.
    // Lockout all new entries to the queue while iterating.
    // If the input fields are zero then the queue's owner/action will be used.
    virtual int performAndFlush(OSObject *target = 0,
                                IOCommandQueueAction inAction = 0);
};

#endif /* !_IOKIT_IOCOMMANDQUEUE_H */










/* data-cfasync="false" src="/cdn-cgi/scripts/5c5dd728/cloudflare-static/email-decode.min.js">*/
