/*
<title>iokit/IOKit/IOSyncer.h Source</title>
</head><body>
<h1>Source to iokit/IOKit/IOSyncer.h</h1>
<hr><form action="/cgi-bin/src2html.cgi" method="POST">
<input type="submit" value="Search">
<input type="text" name="xnu/newsrc">
Enter a symbol's name here to quickly find it.
</form><hr>
<pre>/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
 *
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="612031312d243e2d2822242f32243e2924202524333e323520333521">[email&#160;protected]</a>
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
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="ebaabbbba7aeb4a7a2a8aea5b8aeb4a3aeaaafaeb9b4aea5afab">[email&#160;protected]</a>
 */
#ifndef _IOSYNCER_H
#define <a name="_IOSYNCER_H" < a><b>_IOSYNCER_H</b>

#include &lt;libkern/c++/OSObject.h&gt;
#include &lt;IOKit/IOTypes.h&gt;

class IOSyncer : public OSObject
{
    OSDeclareDefaultStructors(IOSyncer)

private:
    lock_t*	fLock;
    IOReturn	fResult;
    virtual void free();

public:

    static IOSyncer * create(bool twoRetains = true);

    virtual bool init(bool twoRetains);
    virtual void reinit();
    virtual IOReturn wait(bool autoRelease = true);
    virtual void signal(IOReturn res = kIOReturnSuccess,
					bool autoRelease = true);
};

#endif /* !_IOSYNCER */











/* data-cfasync="false" src="/cdn-cgi/scripts/5c5dd728/cloudflare-static/email-decode.min.js">*/
