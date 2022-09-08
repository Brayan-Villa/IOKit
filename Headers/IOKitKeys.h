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
#define <a name="_IOKIT_IOKITKEYS_H" < a><b>_IOKIT_IOKITKEYS_H</b>

// properties found in the registry root
#define <a name="kIOKitBuildVersionKey" < a><b>kIOKitBuildVersionKey</b>		"IOKitBuildVersion"
#define <a name="kIOKitDiagnosticsKey" < a><b>kIOKitDiagnosticsKey</b>		"IOKitDiagnostics"
	// a dictionary keyed by plane name
#define <a name="kIORegistryPlanesKey" < a><b>kIORegistryPlanesKey</b>		"IORegistryPlanes"
#define <a name="kIOCatalogueKey" < a><b>kIOCatalogueKey</b>			"IOCatalogue"

// registry plane names
#define <a name="kIOServicePlane" < a><b>kIOServicePlane</b>			"IOService"
#define <a name="kIOPowerPlane" < a><b>kIOPowerPlane</b>			"IOPower"
#define <a name="kIODeviceTreePlane" < a><b>kIODeviceTreePlane</b>		"IODeviceTree"
#define <a name="kIOAudioPlane" < a><b>kIOAudioPlane</b>			"IOAudio"
#define <a name="kIOFireWirePlane" < a><b>kIOFireWirePlane</b>		"IOFireWire"

// IOService class name
#define <a name="kIOServiceClass" < a><b>kIOServiceClass</b>			"IOService"

// IOResources class name
#define <a name="kIOResourcesClass" < a><b>kIOResourcesClass</b>		"IOResources"

// IOService driver probing property names
#define <a name="kIOClassKey" < a><b>kIOClassKey</b>			"IOClass"
#define <a name="kIOProbeScoreKey" < a><b>kIOProbeScoreKey</b>		"IOProbeScore"
#define <a name="kIOKitDebugKey" < a><b>kIOKitDebugKey</b>			"IOKitDebug"

// IOService matching property names
#define <a name="kIOProviderClassKey" < a><b>kIOProviderClassKey</b>		"IOProviderClass"
#define <a name="kIONameMatchKey" < a><b>kIONameMatchKey</b>			"IONameMatch"
#define <a name="kIOPathMatchKey" < a><b>kIOPathMatchKey</b>			"IOPathMatch"
#define <a name="kIOLocationMatchKey" < a><b>kIOLocationMatchKey</b>		"IOLocationMatch"
#define <a name="kIOResourceMatchKey" < a><b>kIOResourceMatchKey</b>		"IOResourceMatch"

#define <a name="kIONameMatchedKey" < a><b>kIONameMatchedKey</b>		"IONameMatched"

#define <a name="kIOMatchCategoryKey" < a><b>kIOMatchCategoryKey</b>		"IOMatchCategory"
#define <a name="kIODefaultMatchCategoryKey" < a><b>kIODefaultMatchCategoryKey</b>	"IODefaultMatchCategory"

// IOService notification types
#define <a name="kIOPublishNotification" < a><b>kIOPublishNotification</b>		"IOServicePublish"
#define <a name="kIOFirstPublishNotification" < a><b>kIOFirstPublishNotification</b>	"IOServiceFirstPublish"
#define <a name="kIOMatchedNotification" < a><b>kIOMatchedNotification</b>		"IOServiceMatched"
#define <a name="kIOFirstMatchNotification" < a><b>kIOFirstMatchNotification</b>	"IOServiceFirstMatch"
#define <a name="kIOTerminatedNotification" < a><b>kIOTerminatedNotification</b>	"IOServiceTerminate"

// IOService interest notification types
#define <a name="kIOGeneralInterest" < a><b>kIOGeneralInterest</b>		"IOGeneralInterest"
#define <a name="kIOBusyInterest" < a><b>kIOBusyInterest</b>			"IOBusyInterest"

// IOService interest notification types
#define <a name="kIOCFPlugInTypesKey" < a><b>kIOCFPlugInTypesKey</b>		"IOCFPlugInTypes"


#endif /* ! _IOKIT_IOKITKEYS_H */











/* data-cfasync="false" src="/cdn-cgi/scripts/5c5dd728/cloudflare-static/email-decode.min.js">*/
