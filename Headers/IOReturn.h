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
#define <a name="__IOKIT_IORETURN_H" < a><b>__IOKIT_IORETURN_H</b>

#ifdef __cplusplus
extern "C" {
#endif

#include &lt;mach/error.h&gt;

typedef	kern_return_t		<a name="IOReturn" < a><b>IOReturn</b>;

#ifndef sys_iokit
#define <a name="sys_iokit" < a><b>sys_iokit</b>                err_system(0x38)
#endif /* sys_iokit */
#define <a name="sub_iokit_common" < a><b>sub_iokit_common</b>         err_sub(0)
#define <a name="sub_iokit_usb" < a><b>sub_iokit_usb</b>         	 err_sub(1)
#define <a name="sub_iokit_firewire" < a><b>sub_iokit_firewire</b>	 err_sub(2)
#define <a name="sub_iokit_reserved" < a><b>sub_iokit_reserved</b>       err_sub(-1)
#define	<a name="iokit_common_err" < a><b>iokit_common_err</b>(return) (sys_iokit|sub_iokit_common|return)

#define <a name="kIOReturnSuccess" < a><b>kIOReturnSuccess</b>         KERN_SUCCESS          // OK
#define <a name="kIOReturnError" < a><b>kIOReturnError</b>           iokit_common_err(700) // general error 	
#define <a name="kIOReturnNoMemory" < a><b>kIOReturnNoMemory</b>        iokit_common_err(701) // can't allocate memory 
#define <a name="kIOReturnNoResources" < a><b>kIOReturnNoResources</b>     iokit_common_err(702) // resource shortage 
#define <a name="kIOReturnIPCError" < a><b>kIOReturnIPCError</b>        iokit_common_err(703) // error during IPC 
#define <a name="kIOReturnNoDevice" < a><b>kIOReturnNoDevice</b>        iokit_common_err(704) // no such device 
#define <a name="kIOReturnNotPrivileged" < a><b>kIOReturnNotPrivileged</b>   iokit_common_err(705) // privilege violation 
#define <a name="kIOReturnBadArgument" < a><b>kIOReturnBadArgument</b>     iokit_common_err(706) // invalid argument 
#define <a name="kIOReturnLockedRead" < a><b>kIOReturnLockedRead</b>      iokit_common_err(707) // device read locked 
#define <a name="kIOReturnLockedWrite" < a><b>kIOReturnLockedWrite</b>     iokit_common_err(708) // device write locked 
#define <a name="kIOReturnExclusiveAccess" < a><b>kIOReturnExclusiveAccess</b> iokit_common_err(709) // exclusive access and
                                                       //   device already open 
#define <a name="kIOReturnBadMessageID" < a><b>kIOReturnBadMessageID</b>    iokit_common_err(710) // sent/received messages
                                                       //   had different msg_id
#define <a name="kIOReturnUnsupported" < a><b>kIOReturnUnsupported</b>     iokit_common_err(711) // unsupported function 
#define <a name="kIOReturnVMError" < a><b>kIOReturnVMError</b>         iokit_common_err(712) // misc. VM failure 
#define <a name="kIOReturnInternalError" < a><b>kIOReturnInternalError</b>   iokit_common_err(713) // internal error 
#define <a name="kIOReturnIOError" < a><b>kIOReturnIOError</b>         iokit_common_err(714) // General I/O error 
#define <a name="kIOReturnCannotLock" < a><b>kIOReturnCannotLock</b>      iokit_common_err(716) // can't acquire lock
#define <a name="kIOReturnNotOpen" < a><b>kIOReturnNotOpen</b>         iokit_common_err(717) // device not open 
#define <a name="kIOReturnNotReadable" < a><b>kIOReturnNotReadable</b>     iokit_common_err(718) // read not supported 
#define <a name="kIOReturnNotWritable" < a><b>kIOReturnNotWritable</b>     iokit_common_err(719) // write not supported 
#define <a name="kIOReturnNotAligned" < a><b>kIOReturnNotAligned</b>      iokit_common_err(720) // alignment error 
#define <a name="kIOReturnBadMedia" < a><b>kIOReturnBadMedia</b>        iokit_common_err(721) // Media Error 
#define <a name="kIOReturnStillOpen" < a><b>kIOReturnStillOpen</b>       iokit_common_err(722) // device(s) still open 
#define <a name="kIOReturnRLDError" < a><b>kIOReturnRLDError</b>        iokit_common_err(723) // rld failure 
#define <a name="kIOReturnDMAError" < a><b>kIOReturnDMAError</b>        iokit_common_err(724) // DMA failure 
#define <a name="kIOReturnBusy" < a><b>kIOReturnBusy</b>            iokit_common_err(725) // Device Busy 
#define <a name="kIOReturnTimeout" < a><b>kIOReturnTimeout</b>         iokit_common_err(726) // I/O Timeout 
#define <a name="kIOReturnOffline" < a><b>kIOReturnOffline</b>         iokit_common_err(727) // device offline 
#define <a name="kIOReturnNotReady" < a><b>kIOReturnNotReady</b>        iokit_common_err(728) // not ready 
#define <a name="kIOReturnNotAttached" < a><b>kIOReturnNotAttached</b>     iokit_common_err(729) // device not attached 
#define <a name="kIOReturnNoChannels" < a><b>kIOReturnNoChannels</b>      iokit_common_err(730) // no DMA channels left
#define <a name="kIOReturnNoSpace" < a><b>kIOReturnNoSpace</b>         iokit_common_err(731) // no space for data 
#define <a name="kIOReturnPortExists" < a><b>kIOReturnPortExists</b>      iokit_common_err(733) // port already exists
#define <a name="kIOReturnCannotWire" < a><b>kIOReturnCannotWire</b>      iokit_common_err(734) // can't wire down 
                                                       //   physical memory
#define <a name="kIOReturnNoInterrupt" < a><b>kIOReturnNoInterrupt</b>     iokit_common_err(735) // no interrupt attached
#define <a name="kIOReturnNoFrames" < a><b>kIOReturnNoFrames</b>        iokit_common_err(736) // no DMA frames enqueued
#define <a name="kIOReturnMessageTooLarge" < a><b>kIOReturnMessageTooLarge</b> iokit_common_err(737) // oversized msg received
                                                       //   on interrupt port
#define <a name="kIOReturnNotPermitted" < a><b>kIOReturnNotPermitted</b>    iokit_common_err(738) // not permitted
#define <a name="kIOReturnNoPower" < a><b>kIOReturnNoPower</b>         iokit_common_err(739) // no power to device
#define <a name="kIOReturnNoMedia" < a><b>kIOReturnNoMedia</b>         iokit_common_err(740) // media not present
#define <a name="kIOReturnUnformattedMedia" < a><b>kIOReturnUnformattedMedia</b> iokit_common_err(741) // media not formatted
#define <a name="kIOReturnUnsupportedMode" < a><b>kIOReturnUnsupportedMode</b> iokit_common_err(742) // no such mode
#define <a name="kIOReturnUnderrun" < a><b>kIOReturnUnderrun</b>        iokit_common_err(743) // data underrun
#define <a name="kIOReturnOverrun" < a><b>kIOReturnOverrun</b>         iokit_common_err(744) // data overrun
#define <a name="kIOReturnDeviceError" < a><b>kIOReturnDeviceError</b>	 iokit_common_err(745) // The device is not working properly!
#define <a name="kIOReturnNoCompletion" < a><b>kIOReturnNoCompletion</b>	 iokit_common_err(746) // A completion routine is required
#define <a name="kIOReturnAborted" < a><b>kIOReturnAborted</b>	 iokit_common_err(747) // Operation aborted
#define <a name="kIOReturnNoBandwidth" < a><b>kIOReturnNoBandwidth</b>	 iokit_common_err(748) // Bus bandwidth would be exceeded
#define <a name="kIOReturnNotResponding" < a><b>kIOReturnNotResponding</b>	 iokit_common_err(749) // Device not responding
#define <a name="kIOReturnIsoTooOld" < a><b>kIOReturnIsoTooOld</b>	 iokit_common_err(750) // Isochronous I/O request for distant past!
#define <a name="kIOReturnIsoTooNew" < a><b>kIOReturnIsoTooNew</b>	 iokit_common_err(751) // Isochronous I/O request for distant future
#define <a name="kIOReturnInvalid" < a><b>kIOReturnInvalid</b>         iokit_common_err(1)   // should never be seen

#ifdef __cplusplus
}
#endif

#endif /* ! __IOKIT_IORETURN_H */










/* data-cfasync="false" src="/cdn-cgi/scripts/5c5dd728/cloudflare-static/email-decode.min.js">*/
