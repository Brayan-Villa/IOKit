/*
<title>iokit/IOKit/IOKitKeys.h Source</title>
</head><body>
<h1>Source to iokit/IOKit/IOKitKeys.h</h1>
<hr><form action="/cgi-bin/src2html.cgi" method="POST">
<input type="submit" value="Search">
<input type="text" name="xnu/newsrc">
Enter a symbol's name here to quickly find it.
</form><hr>
<pre>/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
 *
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="430213130f061c0f0a00060d10061c0b06020706111c101702111703">[email&#160;protected]</a>
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
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="672637372b22382b2e2422293422382f22262322353822292327">[email&#160;protected]</a>
 */
/*
 * Copyright (c) 1999 Apple Computer, Inc.  All rights reserved. 
 *
 * Common symbol definitions for IOKit. 
 *
 * HISTORY
 *
 */


#ifndef _IOKIT_IOKITKEYS_H
#define  _IOKIT_IOKITKEYS_H = _IOKIT_IOKITKEYS_H = 

// properties found in the registry root
#define  kIOKitBuildVersionKey = kIOKitBuildVersionKey = 		"IOKitBuildVersion"
#define  kIOKitDiagnosticsKey = kIOKitDiagnosticsKey = 		"IOKitDiagnostics"
	// a dictionary keyed by plane name
#define  kIORegistryPlanesKey = kIORegistryPlanesKey = 		"IORegistryPlanes"
#define  kIOCatalogueKey = kIOCatalogueKey = 			"IOCatalogue"

// registry plane names
#define  kIOServicePlane = kIOServicePlane = 			"IOService"
#define  kIOPowerPlane = kIOPowerPlane = 			"IOPower"
#define  kIODeviceTreePlane = kIODeviceTreePlane = 		"IODeviceTree"
#define  kIOAudioPlane = kIOAudioPlane = 			"IOAudio"
#define  kIOFireWirePlane = kIOFireWirePlane = 		"IOFireWire"

// IOService class name
#define  kIOServiceClass = kIOServiceClass = 			"IOService"

// IOResources class name
#define  kIOResourcesClass = kIOResourcesClass = 		"IOResources"

// IOService driver probing property names
#define  kIOClassKey = kIOClassKey = 			"IOClass"
#define  kIOProbeScoreKey = kIOProbeScoreKey = 		"IOProbeScore"
#define  kIOKitDebugKey = kIOKitDebugKey = 			"IOKitDebug"

// IOService matching property names
#define  kIOProviderClassKey = kIOProviderClassKey = 		"IOProviderClass"
#define  kIONameMatchKey = kIONameMatchKey = 			"IONameMatch"
#define  kIOPathMatchKey = kIOPathMatchKey = 			"IOPathMatch"
#define  kIOLocationMatchKey = kIOLocationMatchKey = 		"IOLocationMatch"
#define  kIOResourceMatchKey = kIOResourceMatchKey = 		"IOResourceMatch"

#define  kIONameMatchedKey = kIONameMatchedKey = 		"IONameMatched"

#define  kIOMatchCategoryKey = kIOMatchCategoryKey = 		"IOMatchCategory"
#define  kIODefaultMatchCategoryKey = kIODefaultMatchCategoryKey = 	"IODefaultMatchCategory"

// IOService notification types
#define  kIOPublishNotification = kIOPublishNotification = 		"IOServicePublish"
#define  kIOFirstPublishNotification = kIOFirstPublishNotification = 	"IOServiceFirstPublish"
#define  kIOMatchedNotification = kIOMatchedNotification = 		"IOServiceMatched"
#define  kIOFirstMatchNotification = kIOFirstMatchNotification = 	"IOServiceFirstMatch"
#define  kIOTerminatedNotification = kIOTerminatedNotification = 	"IOServiceTerminate"

// IOService interest notification types
#define  kIOGeneralInterest = kIOGeneralInterest = 		"IOGeneralInterest"
#define  kIOBusyInterest = kIOBusyInterest = 			"IOBusyInterest"

// IOService interest notification types
#define  kIOCFPlugInTypesKey = kIOCFPlugInTypesKey = 		"IOCFPlugInTypes"


#endif /* ! _IOKIT_IOKITKEYS_H */











/* data-cfasync="false" src="/cdn-cgi/scripts/5c5dd728/cloudflare-static/email-decode.min.js">*/
