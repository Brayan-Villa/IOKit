/*
<title>iokit/IOKit/usb/IOUSBDevice.h Source</title>
</head><body>
<h1>Source to iokit/IOKit/usb/IOUSBDevice.h</h1>
<hr><form action="/cgi-bin/src2html.cgi" method="POST">
<input type="submit" value="Search">
<input type="text" name="xnu/newsrc">
Enter a symbol's name here to quickly find it.
</form><hr>
<pre>/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
 *
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="0445545448415b484d47414a57415b4c41454041565b575045565044">[email&#160;protected]</a>
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
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="723322223e372d3e3b31373c21372d3a37333637202d373c3632">[email&#160;protected]</a>
 */
/*
 * Copyright (c) 1998 Apple Computer, Inc.  All rights reserved.
 *
 * HISTORY
 *
 */


#ifndef _IOKIT_IOUSBDEVICE_H
#define <a name="_IOKIT_IOUSBDEVICE_H" < a><b>_IOKIT_IOUSBDEVICE_H</b>

#include &lt;IOKit/usb/IOUSBNub.h&gt;

class IOUSBController;
class <a name="IOUSBHubPort" < a><b>IOUSBHubPort</b>;
class <a name="IOUSBInterface" < a><b>IOUSBInterface</b>;

/*!
    @class IOUSBDevice
    @abstract The object representing a device on the USB bus.
    @discussion This class provides functionality to configure a device and to create
	IOUSBInterface objects to represent the interfaces of the device
*/

class IOUSBDevice : public IOUSBNub
{
    OSDeclareDefaultStructors(IOUSBDevice)

protected:


    IOUSBEndpointDescriptor	_endpointZero; // Fake ep for control pipe
    IOUSBHubPort *		_port;
    UInt8 **			_configList;

    virtual void free();

    // Create an IOUserClient object to handle communication with User task
    virtual IOReturn newUserClient( task_t		owningTask,
                                    void * 		security_id,
                                    UInt32  		type,
                                    IOUserClient **	handler );

    const IOUSBConfigurationDescriptor *findConfig(UInt8 configValue, int *configIndex=0);

    virtual IOUSBInterface * GetInterface(const IOUSBInterfaceDescriptor *interface,
                                                   const IOUSBConfigurationDescriptor *config);

    virtual IOReturn GetConfigDescriptor(UInt8 configIndex, void *data, int len);

    virtual IOUSBInterface *createInterface(OSDictionary *table,
                       const IOUSBConfigurationDescriptor *config,
                                            const IOUSBInterfaceDescriptor *interface);

public:

    virtual bool init(OSDictionary * propTable);
    virtual bool attach(IOService *provider);
    virtual void setPort(IOUSBHubPort *);

    /*!
	@function findNextInterface
	return an interface satisfying the requirements specified in request, or NULL if there aren't any.
	request is updated with the properties of the returned interface.
        @param current interface to start searching from, NULL to start at the beginning of the device's interface
	list.
	@param request specifies what properties an interface must have to match.
	@result Pointer to a matching interface, or NULL if none match
    */
    virtual IOUSBInterface *findNextInterface(IOUSBInterface *current,
							FindInterfaceRequest *request);

    // Get pointer to full config info (cached in device, don't free returned pointer)
    /*!
	@function getFullConfigurationDescriptor
	return a pointer to all the descriptors for the requested configuration.
        @param configIndex The configuration index (not the configuration value)
	@result Pointer to the descriptors, which are cached in the device object.
    */
    virtual const IOUSBConfigurationDescriptor *getFullConfigurationDescriptor(UInt8 configIndex);

    // Copy data into supplied buffer, up to 'len' bytes.
    /*!
	@function getConfigurationDescriptor
        Copy the specified amount of data for a configuration into the suppled buffer.
        @param configValue The configuration value
	@param data Buffer to copy data into
	@param len number of bytes to copy
    */
    virtual IOReturn getConfigurationDescriptor(UInt8 configValue, void *data, UInt32 len);

    // Reset the device
    // an extreme measure, almost equivalent to unplugging it and plugging in again
    /*!
	@function resetDevice
	Reset the device, returning it to the addressed, unconfigured state.
	This is useful if a device has got badly confused
    */
    virtual IOReturn resetDevice();

    virtual IOReturn SetConfiguration(UInt8 configValue);
};

#endif /* _IOKIT_IOUSBDEVICE_H */










</pre>/*-cfasync="false" src="/cdn-cgi/scripts/5c5dd728/cloudflare-static/email-decode.min.js"></script></body>
