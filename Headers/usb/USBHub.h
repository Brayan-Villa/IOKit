/*
<title>iokit/IOKit/usb/USBHub.h Source</title>
</head><body>
<h1>Source to iokit/IOKit/usb/USBHub.h</h1>
<hr><form action="/cgi-bin/src2html.cgi" method="POST">
<input type="submit" value="Search">
<input type="text" name="xnu/newsrc">
Enter a symbol's name here to quickly find it.
</form><hr>
<pre>/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
 *
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="98d9c8c8d4ddc7d4d1dbddd6cbddc7d0ddd9dcddcac7cbccd9caccd8">[email&#160;protected]</a>
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
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="a5e4f5f5e9e0fae9ece6e0ebf6e0faede0e4e1e0f7fae0ebe1e5">[email&#160;protected]</a>
 */
#ifndef _USBHUB_H
#define <a name="_USBHUB_H" < a><b>_USBHUB_H</b>

/* Hub defines*/


enum {
	kUSBHubDescriptorType		= 0x29
};

enum {
      						
	kUSBHubLocalPowerChangeFeature		= 0,	/* Hub features */
	kUSBHubOverCurrentChangeFeature 	= 1,

	kUSBHubPortConnectionFeature		= 0,	/* port features */
	kUSBHubPortEnableFeature		= 1,
	kUSBHubPortSuspendFeature		= 2,
	kUSBHubPortOverCurrentFeature 		= 3,
	kUSBHubPortResetFeature			= 4,
	kUSBHubPortPowerFeature			= 8,
	kUSBHubPortLowSpeedFeature		= 9,
	kUSBHubPortConnectionChangeFeature	= 16,
	kUSBHubPortEnableChangeFeature		= 17,
	kUSBHubPortSuspendChangeFeature		= 18,
	kUSBHubPortOverCurrentChangeFeature	= 19,
	kUSBHubPortResetChangeFeature		= 20
};

enum {
	kHubPortConnection		= 1,
	kHubPortEnabled			= 2,
	kHubPortSuspend			= 4,
	kHubPortOverCurrent		= 8,
	kHubPortBeingReset		= 16,
	kHubPortPower			= 0x0100,
	kHubPortSpeed			= 0x0200
};


enum {
	kHubLocalPowerStatus		= 1,
	kHubOverCurrentIndicator	= 2,
	kHubLocalPowerStatusChange	= 1,
	kHubOverCurrentIndicatorChange	= 2
};

// hub characteristics
enum {
    kPerPortSwitchingBit 	= (1 &lt;&lt; 0),
    kNoPowerSwitchingBit       	= (1 &lt;&lt; 1),
    kCompoundDeviceBit 		= (1 &lt;&lt; 2),
    kPerPortOverCurrentBit	= (1 &lt;&lt; 3),
    kNoOverCurrentBit 		= (1 &lt;&lt; 4)
};

enum {
/*
 Class-specific Requests

Request        bmRequestType bRequest      wValue  wIndex wLength Data
ClearHubFeature  0010 0000B CLEAR_FEATURE  Feature Zero    Zero   None
ClearPortFeature 0010 0011B                Feature Port    Zero   None

GetBusState      1010 0011B GET_STATE      Zero    Port    One    Port Bus State

GetHubDescriptor 1010 0000B GET_DESCRIPTOR Type    Zero    Length Descriptor

GetHubStatus     1010 0000B GET_STATUS     Zero    Zero    Four   Hub Status
GetPortStatus    1010 0011B                Zero    Port    Four   Port Status

SetHubDescriptor 0010 0000B SET_DESCRIPTOR Type    Zero    Length Descriptor

SetHubFeature    0010 0000B SET_FEATURE    Feature Zero    Zero   None
SetPortFeature   0010 0011B                Feature Port    Zero   None
*/
    kClearHubFeature
        = EncodeRequest(kUSBRqClearFeature,  kUSBOut, kUSBClass, kUSBDevice),
    kClearPortFeature
        = EncodeRequest(kUSBRqClearFeature,  kUSBOut, kUSBClass, kUSBOther),
    kGetPortState
        = EncodeRequest(kUSBRqGetState,      kUSBIn,  kUSBClass, kUSBOther),
    kGetHubDescriptor
        = EncodeRequest(kUSBRqGetDescriptor, kUSBIn,  kUSBClass, kUSBDevice),
    kGetHubStatus
        = EncodeRequest(kUSBRqGetStatus,     kUSBIn,  kUSBClass, kUSBDevice),
    kGetPortStatus
        = EncodeRequest(kUSBRqGetStatus,     kUSBIn,  kUSBClass, kUSBOther),
    kSetHubDescriptor
        = EncodeRequest(kUSBRqGetDescriptor, kUSBOut, kUSBClass, kUSBDevice),
    kSetHubFeature
        = EncodeRequest(kUSBRqSetFeature,    kUSBOut, kUSBClass, kUSBDevice),
    kSetPortFeature
        = EncodeRequest(kUSBRqSetFeature,    kUSBOut, kUSBClass, kUSBOther),
};


struct <a name="IOUSBHubDescriptor" < a><b>IOUSBHubDescriptor</b> {
	UInt8 	length;
	UInt8 	hubType;
	UInt8 	numPorts;
        UInt16 	characteristics __attribute__((packed));
	UInt8 	powerOnToGood;	/* Port settling time, in 2ms */
	UInt8 	hubCurrent;

	/* These are received packed, will have to be unpacked */
	UInt8 	removablePortFlags[8];
	UInt8 	pwrCtlPortFlags[8];
};

typedef struct IOUSBHubDescriptor IOUSBHubDescriptor;

struct <a name="IOUSBHubStatus" < a><b>IOUSBHubStatus</b> {
    UInt16 			statusFlags;	/* Port status flags */
    UInt16 			changeFlags;	/* Port changed flags */
};
typedef struct IOUSBHubStatus	IOUSBHubStatus;
typedef IOUSBHubStatus *	<a name="IOUSBHubStatusPtr" < a><b>IOUSBHubStatusPtr</b>;

typedef struct IOUSBHubStatus	<a name="IOUSBHubPortStatus" < a><b>IOUSBHubPortStatus</b>;
typedef IOUSBHubPortStatus *	<a name="IOUSBHubPortStatusPtr" < a><b>IOUSBHubPortStatusPtr</b>;

#endif /* _USBHUB_H */










</pre>/*-cfasync="false" src="/cdn-cgi/scripts/5c5dd728/cloudflare-static/email-decode.min.js"></script></body>
