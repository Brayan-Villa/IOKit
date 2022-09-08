/*
<title>iokit/IOKit/IOBufferMemoryDescriptor.h Source</title>
</head><body>
<h1>Source to iokit/IOKit/IOBufferMemoryDescriptor.h</h1>
<hr><form action="/cgi-bin/src2html.cgi" method="POST">
<input type="submit" value="Search">
<input type="text" name="xnu/newsrc">
Enter a symbol's name here to quickly find it.
</form><hr>
<pre>/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
 *
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="420312120e071d0e0b01070c11071d0a07030607101d111603101602">[email&#160;protected]</a>
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
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="adecfdfde1e8f2e1e4eee8e3fee8f2e5e8ece9e8fff2e8e3e9ed">[email&#160;protected]</a>
 */
#ifndef _IOBUFFERMEMORYDESCRIPTOR_H
#define <a name="_IOBUFFERMEMORYDESCRIPTOR_H" < a><b>_IOBUFFERMEMORYDESCRIPTOR_H</b>

#include &lt;IOKit/IOMemoryDescriptor.h&gt;

class IOBufferMemoryDescriptor : public IOGeneralMemoryDescriptor
{
    OSDeclareDefaultStructors(IOBufferMemoryDescriptor);

protected:
    void *               _buffer;
    vm_size_t            _capacity;
    bool                 _contiguous;
    IOPhysicalAddress *  _physAddrs;
    unsigned             _physSegCount;

    virtual void free();

    IOGeneralMemoryDescriptor::initWithAddress;  /* not supported in subclass */
    IOGeneralMemoryDescriptor::withAddress;      /* not supported in subclass */
    IOGeneralMemoryDescriptor::initWithRanges;   /* not supported in subclass */
    IOGeneralMemoryDescriptor::withRanges;       /* not supported in subclass */

public:

    /*
     * initWithCapacity:
     *
     * Initialize a new IOBufferMemoryDescriptor with a buffer large enough to
     * hold capacity bytes.  The descriptor's length is initially set to zero.
     */
    virtual bool initWithCapacity(vm_size_t   capacity,
                                  IODirection withDirection,
                                  bool        withContiguousMemory = false);

    /*
     * withCapacity:
     *
     * Returns a new IOBufferMemoryDescriptor with a buffer large enough to
     * hold capacity bytes.  The descriptor's length is initially set to zero.
     */
    static IOBufferMemoryDescriptor * withCapacity(
                                     vm_size_t    capacity,
                                     IODirection  withDirection,
                                     bool         withContiguousMemory = false);
    /*
     * initWithBytes:
     *
     * Initialize a new IOBufferMemoryDescriptor preloaded with bytes (copied).
     * The descriptor's length and capacity are set to the input buffer's size.
     */
    virtual bool initWithBytes(const void * bytes,
                               vm_size_t    withLength,
                               IODirection  withDirection,
                               bool         withContiguousMemory = false);

    /*
     * withBytes:
     *
     * Returns a new IOBufferMemoryDescriptor preloaded with bytes (copied).
     * The descriptor's length and capacity are set to the input buffer's size.
     */
    static IOBufferMemoryDescriptor * withBytes(
                                     const void * bytes,
                                     vm_size_t    withLength,
                                     IODirection  withDirection,
                                     bool         withContiguousMemory = false);

    /*
     * setLength:
     *
     * Change the buffer length of the memory descriptor.  When a new buffer is
     * created with initWithBytes, the descriptor's length is set to capacity,
     * or its length is initially zero.  This method allows one to resize the
     * buffer length up to capacity or less.  This eliminates the need to
     * destroy and create new buffers when different sizes are needed.  The
     * descriptor position is implicitly reset to zero as a result of this call.
     */
    virtual void setLength(vm_size_t length);

    /*
     * setDirection:
     *
     * Change the direction of the transfer.  This method allows one to redirect
     * the descriptor's transfer direction.  This eliminates the need to destroy
     * and create new buffers when different transfer directions are needed.
     */
    virtual void setDirection(IODirection direction);

    /*
     * getCapacity:
     *
     * Get the buffer capacity
     */
    virtual vm_size_t getCapacity() const;

    /*
     * getBytesNoCopy:
     *
     * Return the virtual address of the beginning of the buffer
     */
    virtual void *getBytesNoCopy();

    /*
     * getBytesNoCopy:
     *
     * Return the virtual address of an offset from the beginning of the buffer
     */
    virtual void *getBytesNoCopy(vm_size_t start, vm_size_t withLength);

    /*
     * appendBytes:
     *
     * Add some data to the end of the buffer.  This method automatically
     * maintains the memory descriptor buffer length.  Note that appendBytes
     * will not copy past the end of the memory descriptor's current capacity.
     */
    virtual bool appendBytes(const void *bytes, vm_size_t withLength);

    /*
     * getPhysicalSegment:
     *
     * Get the physical address of the buffer, relative to the current position.
     * If the current position is at the end of the buffer, a zero is returned.
     */
    virtual IOPhysicalAddress getPhysicalSegment(IOByteCount offset,
						 IOPhysicalLength * length);    
};

#endif /* !_IOBUFFERMEMORYDESCRIPTOR_H */










/* data-cfasync="false" src="/cdn-cgi/scripts/5c5dd728/cloudflare-static/email-decode.min.js">*/
