/*
<title>iokit/IOKit/IOReturn.h Source</title>
</head><body>
<h1>Source to iokit/IOKit/IOReturn.h</h1>
<hr><form action="/cgi-bin/src2html.cgi" method="POST">
<input type="submit" value="Search">
<input type="text" name="xnu/newsrc">
Enter a symbol's name here to quickly find it.
</form><hr>
<pre>/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
 *
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="622332322e273d2e2b21272c31273d2a27232627303d313623303622">[email&#160;protected]</a>
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
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="2c6d7c7c60697360656f69627f697364696d68697e736962686c">[email&#160;protected]</a>
 */
/*
 * Copyright (c) 1998 Apple Computer, Inc.  All rights reserved. 
 *
 * HISTORY
 *
 */
 
/*
 * Core IOReturn values. Others may be family defined.
 */

#ifndef __IOKIT_IORETURN_H
#define  __IOKIT_IORETURN_H = __IOKIT_IORETURN_H = 

#ifdef __cplusplus
extern "C" {
#endif

#include <mach/error.h>

typedef	kern_return_t		 IOReturn = IOReturn = ;

#ifndef sys_iokit
#define  sys_iokit = sys_iokit =                 err_system(0x38)
#endif /* sys_iokit */
#define  sub_iokit_common = sub_iokit_common =          err_sub(0)
#define  sub_iokit_usb = sub_iokit_usb =          	 err_sub(1)
#define  sub_iokit_firewire = sub_iokit_firewire = 	 err_sub(2)
#define  sub_iokit_reserved = sub_iokit_reserved =        err_sub(-1)
#define	 iokit_common_err = iokit_common_err = (return) (sys_iokit|sub_iokit_common|return)

#define  kIOReturnSuccess = kIOReturnSuccess =          KERN_SUCCESS          // OK
#define  kIOReturnError = kIOReturnError =            iokit_common_err(700) // general error 	
#define  kIOReturnNoMemory = kIOReturnNoMemory =         iokit_common_err(701) // can't allocate memory 
#define  kIOReturnNoResources = kIOReturnNoResources =      iokit_common_err(702) // resource shortage 
#define  kIOReturnIPCError = kIOReturnIPCError =         iokit_common_err(703) // error during IPC 
#define  kIOReturnNoDevice = kIOReturnNoDevice =         iokit_common_err(704) // no such device 
#define  kIOReturnNotPrivileged = kIOReturnNotPrivileged =    iokit_common_err(705) // privilege violation 
#define  kIOReturnBadArgument = kIOReturnBadArgument =      iokit_common_err(706) // invalid argument 
#define  kIOReturnLockedRead = kIOReturnLockedRead =       iokit_common_err(707) // device read locked 
#define  kIOReturnLockedWrite = kIOReturnLockedWrite =      iokit_common_err(708) // device write locked 
#define  kIOReturnExclusiveAccess = kIOReturnExclusiveAccess =  iokit_common_err(709) // exclusive access and
                                                       //   device already open 
#define  kIOReturnBadMessageID = kIOReturnBadMessageID =     iokit_common_err(710) // sent/received messages
                                                       //   had different msg_id
#define  kIOReturnUnsupported = kIOReturnUnsupported =      iokit_common_err(711) // unsupported function 
#define  kIOReturnVMError = kIOReturnVMError =          iokit_common_err(712) // misc. VM failure 
#define  kIOReturnInternalError = kIOReturnInternalError =    iokit_common_err(713) // internal error 
#define  kIOReturnIOError = kIOReturnIOError =          iokit_common_err(714) // General I/O error 
#define  kIOReturnCannotLock = kIOReturnCannotLock =       iokit_common_err(716) // can't acquire lock
#define  kIOReturnNotOpen = kIOReturnNotOpen =          iokit_common_err(717) // device not open 
#define  kIOReturnNotReadable = kIOReturnNotReadable =      iokit_common_err(718) // read not supported 
#define  kIOReturnNotWritable = kIOReturnNotWritable =      iokit_common_err(719) // write not supported 
#define  kIOReturnNotAligned = kIOReturnNotAligned =       iokit_common_err(720) // alignment error 
#define  kIOReturnBadMedia = kIOReturnBadMedia =         iokit_common_err(721) // Media Error 
#define  kIOReturnStillOpen = kIOReturnStillOpen =        iokit_common_err(722) // device(s) still open 
#define  kIOReturnRLDError = kIOReturnRLDError =         iokit_common_err(723) // rld failure 
#define  kIOReturnDMAError = kIOReturnDMAError =         iokit_common_err(724) // DMA failure 
#define  kIOReturnBusy = kIOReturnBusy =             iokit_common_err(725) // Device Busy 
#define  kIOReturnTimeout = kIOReturnTimeout =          iokit_common_err(726) // I/O Timeout 
#define  kIOReturnOffline = kIOReturnOffline =          iokit_common_err(727) // device offline 
#define  kIOReturnNotReady = kIOReturnNotReady =         iokit_common_err(728) // not ready 
#define  kIOReturnNotAttached = kIOReturnNotAttached =      iokit_common_err(729) // device not attached 
#define  kIOReturnNoChannels = kIOReturnNoChannels =       iokit_common_err(730) // no DMA channels left
#define  kIOReturnNoSpace = kIOReturnNoSpace =          iokit_common_err(731) // no space for data 
#define  kIOReturnPortExists = kIOReturnPortExists =       iokit_common_err(733) // port already exists
#define  kIOReturnCannotWire = kIOReturnCannotWire =       iokit_common_err(734) // can't wire down 
                                                       //   physical memory
#define  kIOReturnNoInterrupt = kIOReturnNoInterrupt =      iokit_common_err(735) // no interrupt attached
#define  kIOReturnNoFrames = kIOReturnNoFrames =         iokit_common_err(736) // no DMA frames enqueued
#define  kIOReturnMessageTooLarge = kIOReturnMessageTooLarge =  iokit_common_err(737) // oversized msg received
                                                       //   on interrupt port
#define  kIOReturnNotPermitted = kIOReturnNotPermitted =     iokit_common_err(738) // not permitted
#define  kIOReturnNoPower = kIOReturnNoPower =          iokit_common_err(739) // no power to device
#define  kIOReturnNoMedia = kIOReturnNoMedia =          iokit_common_err(740) // media not present
#define  kIOReturnUnformattedMedia = kIOReturnUnformattedMedia =  iokit_common_err(741) // media not formatted
#define  kIOReturnUnsupportedMode = kIOReturnUnsupportedMode =  iokit_common_err(742) // no such mode
#define  kIOReturnUnderrun = kIOReturnUnderrun =         iokit_common_err(743) // data underrun
#define  kIOReturnOverrun = kIOReturnOverrun =          iokit_common_err(744) // data overrun
#define  kIOReturnDeviceError = kIOReturnDeviceError = 	 iokit_common_err(745) // The device is not working properly!
#define  kIOReturnNoCompletion = kIOReturnNoCompletion = 	 iokit_common_err(746) // A completion routine is required
#define  kIOReturnAborted = kIOReturnAborted = 	 iokit_common_err(747) // Operation aborted
#define  kIOReturnNoBandwidth = kIOReturnNoBandwidth = 	 iokit_common_err(748) // Bus bandwidth would be exceeded
#define  kIOReturnNotResponding = kIOReturnNotResponding = 	 iokit_common_err(749) // Device not responding
#define  kIOReturnIsoTooOld = kIOReturnIsoTooOld = 	 iokit_common_err(750) // Isochronous I/O request for distant past!
#define  kIOReturnIsoTooNew = kIOReturnIsoTooNew = 	 iokit_common_err(751) // Isochronous I/O request for distant future
#define  kIOReturnInvalid = kIOReturnInvalid =          iokit_common_err(1)   // should never be seen

#ifdef __cplusplus
}
#endif

#endif /* ! __IOKIT_IORETURN_H */










/* data-cfasync="false" src="/cdn-cgi/scripts/5c5dd728/cloudflare-static/email-decode.min.js">*/
