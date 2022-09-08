/*
<title>iokit/IOKit/usb/IOUSBInterface.h Source</title>
</head><body>
<h1>Source to iokit/IOKit/usb/IOUSBInterface.h</h1>
<hr><form action="/cgi-bin/src2html.cgi" method="POST">
<input type="submit" value="Search">
<input type="text" name="xnu/newsrc">
Enter a symbol's name here to quickly find it.
</form><hr>
<pre>/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
 *
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="5415040418110b181d17111a07110b1c11151011060b070015060014">[email&#160;protected]</a>
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
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="efaebfbfa3aab0a3a6acaaa1bcaab0a7aaaeabaabdb0aaa1abaf">[email&#160;protected]</a>
 */
/*
 * Copyright (c) 1998 Apple Computer, Inc.  All rights reserved.
 *
 * HISTORY
 *
 */


#ifndef _IOKIT_IOUSBINTERFACE_H
#define <a name="_IOKIT_IOUSBINTERFACE_H" < a><b>_IOKIT_IOUSBINTERFACE_H</b>

#include &lt;IOKit/IOService.h&gt;
#include &lt;libkern/c++/OSData.h&gt;

#include &lt;IOKit/usb/USB.h&gt;
#include &lt;IOKit/usb/IOUSBNub.h&gt;

class <a name="IOUSBDevice" < a><b>IOUSBDevice</b>;

/*!
    @class IOUSBInterface
    @abstract The object representing an interface of a device on the USB bus.
    @discussion This class provides functionality to find the pipes of an interface and
	to read the descriptors associated with an interface. When an interface is open()ed,
	all its pipes are created
*/
class IOUSBInterface : public IOUSBNub
{
    OSDeclareDefaultStructors(IOUSBInterface)

protected:
    IOUSBPipe * 			_pipeList[kUSBMaxPipes];
    const IOUSBConfigurationDescriptor *_configDesc;
    const IOUSBInterfaceDescriptor *	_interfaceDesc;
    IOUSBDevice *			_device;
    UInt8 				_currentAlt;

    virtual void cleanPipes(void);	// close all pipes (except pipe zero)
    // Create an IOUserClient object to handle communication with User task
    virtual IOReturn newUserClient( task_t		owningTask,
                                void * 		security_id,
                                UInt32  		type,
                                IOUserClient **	handler );


public:

    virtual bool init(OSDictionary * propTable,
		const IOUSBConfigurationDescriptor *cfDesc,
                      const IOUSBInterfaceDescriptor *ifDesc);
    virtual bool attach(IOService *provider);
    virtual bool finalize(IOOptionBits options);

    /*!
        @function findNextAltInterface
        return alternate interface descriptor satisfying the requirements specified in request, or NULL if there aren't any.
        request is updated with the properties of the returned interface.
        @param current interface descriptor to start searching from, NULL to start at alternate interface 0.
        @param request specifies what properties an interface must have to match.
        @result Pointer to a matching interface descriptor, or NULL if none match.
    */
    virtual const IOUSBInterfaceDescriptor *findNextAltInterface(const IOUSBInterfaceDescriptor *current,
                                                        FindInterfaceRequest *request);

    /*!
	@function findNextPipe
	Find a pipe of the interface that matches the requirements, either
	starting from the beginning of the interface's pipe list or from a specified
	pipe.
	@param current Pipe to start searching from, NULL to start from beginning of list.
	@param request Requirements for pipe to match, updated with the found pipe's
	properties.
	@result Pointer to the pipe, or NULL if no pipe matches the request.
    */
    virtual IOUSBPipe *findNextPipe(IOUSBPipe *current,
				IOUSBFindEndpointRequest *request);

    /*!
        @function findNextAssociatedDescriptor
        Find the next descriptor of the requested type associated with the interface.
	@param current Descriptor to start searching from, NULL to start from beginning of list.
	@param type Descriptor type to search for, or kUSBAnyDesc to return any descriptor type.
	@result Pointer to the descriptor, or NULL if no matching descriptors found.
    */
    virtual const IOUSBDescriptorHeader *
	findNextAssociatedDescriptor(const void *current, UInt8 type);

    /*!
        @function setAlternateInterface
        Select the specified alternate interface.
	@param alternateSetting Alternate setting (from the alternate interface's interface descriptor).
    */
    virtual IOReturn setAlternateInterface(UInt8 alternateSetting);

    /* Open / Close, overriden to open/close all the pipes */
    virtual bool open( 	 IOService *	   forClient,
                         IOOptionBits	   options = 0,
                         void *		   arg = 0 );
    virtual void close(  IOService *	   forClient,
                         IOOptionBits	   options = 0 );

    // Lowlevel requests for non-standard device requests
    virtual IOReturn deviceRequest(IOUSBDevRequest	*request,
                                   IOUSBCompletion	*completion = 0);

    /*!
        @function getConfigValue
	returns the device configuration value for the interface
	@result The device configuration value.
    */
    UInt8 getConfigValue();
    /*!
        @function interfaceDescriptor
        returns the interface descriptor for the interface
	@result Pointer to the interface descriptor.
    */
    const IOUSBInterfaceDescriptor * interfaceDescriptor();
    /*!
        @function device
        returns the device the interface is part of.
	@result Pointer to the device.
    */
    IOUSBDevice * device();
};

#endif /* _IOKIT_IOUSBINTERFACE_H */










</pre>/*-cfasync="false" src="/cdn-cgi/scripts/5c5dd728/cloudflare-static/email-decode.min.js"></script></body>
