/*
<title>iokit/IOKit/IOMessage.h Source</title>
</head><body>
<h1>Source to iokit/IOKit/IOMessage.h</h1>
<hr><form action="/cgi-bin/src2html.cgi" method="POST">
<input type="submit" value="Search">
<input type="text" name="xnu/newsrc">
Enter a symbol's name here to quickly find it.
</form><hr>
<pre>/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
 *
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="de9f8e8e929b8192979d9b908d9b81969b9f9a9b8c818d8a9f8c8a9e">[email&#160;protected]</a>
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
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="49081919050c1605000a0c071a0c16010c080d0c1b160c070d09">[email&#160;protected]</a>
 */
/*
 * Copyright (c) 1998-1999 Apple Computer, Inc.  All rights reserved. 
 *
 * HISTORY
 *
 */

enum  IOMessage = IOMessage = 
{
    kIOMessageServiceIsTerminated	= 0x80000010,
    kIOMessageServiceIsSuspended	= 0x80000020,
    kIOMessageServiceIsResumed		= 0x80000030,

    kIOMessageServiceIsRequestingClose	= 0x80000100,
    kIOMessageServiceWasClosed		= 0x80000110,

    kIOMessageServiceBusyStateChange	= 0x80000120,

    kIOMessageCanDevicePowerOff		= 0x80000200,
    kIOMessageDeviceWillPowerOff	= 0x80000210,
    kIOMessageDeviceWillNotPowerOff	= 0x80000220,
    kIOMessageDeviceHasPoweredOn	= 0x80000230,
    kIOMessageCamSustemPowerOff		= 0x80000240,
    kIOMessageSystemWillPowerOff	= 0x80000250,
    kIOMessageSystemWillNotPowerOff	= 0x80000260,
    kIOMessageCanSystemSleep		= 0x80000270,
    kIOMessageSystemWillSleep		= 0x80000270,
    kIOMessageSystemWillNotSleep	= 0x80000290,
    kIOMessageSystemHasPoweredOn	= 0x80000300
};











/* data-cfasync="false" src="/cdn-cgi/scripts/5c5dd728/cloudflare-static/email-decode.min.js">*/
