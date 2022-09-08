/*
<title>iokit/IOKit/IOFilterInterruptEventSource.h Source</title>
</head><body>
<h1>Source to iokit/IOKit/IOFilterInterruptEventSource.h</h1>
<hr><form action="/cgi-bin/src2html.cgi" method="POST">
<input type="submit" value="Search">
<input type="text" name="xnu/newsrc">
Enter a symbol's name here to quickly find it.
</form><hr>
<pre>/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
 *
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="e4a5b4b4a8a1bba8ada7a1aab7a1bbaca1a5a0a1b6bbb7b0a5b6b0a4">[email&#160;protected]</a>
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
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="2564757569607a696c66606b76607a6d60646160777a606b6165">[email&#160;protected]</a>
 */
/*
Copyright (c) 1999 Apple Computer, Inc.	 All rights reserved.

HISTORY
    1999-4-15	Godfrey van der Linden(gvdl)
	Created.
*/
#ifndef _IOKIT_IOFILTERINTERRUPTEVENTSOURCE_H
#define <a name="_IOKIT_IOFILTERINTERRUPTEVENTSOURCE_H" < a><b>_IOKIT_IOFILTERINTERRUPTEVENTSOURCE_H</b>

#include &lt;IOKit/IOInterruptEventSource.h&gt;

class IOService;

/*! @class IOFilterInterruptEventSource : public IOInterruptEventSource
    @abstract Filtering varient of the $link IOInterruptEventSource.
    @discussion An interrupt event source that calls the client to determine if a interrupt event needs to be scheduled on the work loop.  A filter interrupt event source call's the client in the primary interrupt context, the client can then interrogate it's hardware and determine if the interrupt needs to be processed yet.
&lt;br&gt;&lt;br&gt;
    As the routine is called in the primary interrupt context great care must be taken in the writing of this routine.  In general none of the generic IOKit environment is safe to call in this context.  We intend this routine to be used by hardware that can interrogate it's registers without destroying state.  Primarily this variant of event sources will be used by drivers that share interrupts.  The filter routine will determine if the interrupt is a real interrupt or a ghost and thus optimise the work thread context switch away.
&lt;br&gt;&lt;br&gt;
    CAUTION:  Called in primary interrupt context, if you need to disable interrupt to guard you registers against an unexpected call then it is better to use a straight IOInterruptEventSource and it's secondary interrupt delivery mechanism.
*/
class IOFilterInterruptEventSource : public IOInterruptEventSource
{
    OSDeclareDefaultStructors(IOFilterInterruptEventSource)

public:
/*!
    @typedef Filter
    @discussion C Function pointer to a routine to call when an interrupt occurs.
    @param owner Pointer to the owning/client instance.
    @param sender Where is the interrupt comming from.
    @result false if this interrupt can be ignored. */
    typedef bool (*Filter)(OSObject *, <a name="IOFilterInterruptEventSource" < a><b>IOFilterInterruptEventSource</b> *);

/*! @defined IOFilterInterruptAction
    @discussion Backward compatibilty define for the old non-class scoped type definition.  See $link IOFilterInterruptSource::Filter */
#define <a name="IOFilterInterruptAction" < a><b>IOFilterInterruptAction</b> IOFilterInterruptEventSource::Filter

private:
    // Hide the superclass initializers
    virtual bool init(OSObject *inOwner,
		      IOInterruptEventSource::Action inAction = 0,
		      IOService *inProvider = 0,
		      int inIntIndex = 0);

    static IOInterruptEventSource *
	interruptEventSource(OSObject *inOwner,
			     IOInterruptEventSource::Action inAction = 0,
			     IOService *inProvider = 0,
			     int inIntIndex = 0);

protected:
/*! @var filterAction Filter callout */
    Filter filterAction;

public:
/*! @function filterInterruptEventSource
    @abstract Factor method to create and initialise an IOFilterInterruptEventSource.  See $link init.
    @param owner Owner/client of this event source.
    @param action 'C' Function to call when something happens.
    @param filter 'C' Function to call when interrupt occurs.
    @param provider Service that provides interrupts.
    @param intIndex Defaults to 0.
    @result a new event source if succesful, 0 otherwise.  */
    static IOFilterInterruptEventSource *
	filterInterruptEventSource(OSObject *owner,
				   IOInterruptEventSource::Action action,
				   Filter filter,
				   IOService *provider,
				   int intIndex = 0);

/*! @function init
    @abstract Primary initialiser for the IOFilterInterruptEventSource class.
    @param owner Owner/client of this event source.
    @param action 'C' Function to call when something happens.
    @param filter 'C' Function to call in primary interrupt context.
    @param provider Service that provides interrupts.
    @param intIndex Interrupt source within provider.  Defaults to 0.
    @result true if the inherited classes and this instance initialise
successfully.  */
    virtual bool init(OSObject *owner,
		      IOInterruptEventSource::Action action,
		      Filter filter,
		      IOService *provider,
		      int intIndex = 0);


/*! @function getFilterAction
    @abstract Get'ter for filterAction variable.
    @result value of filterAction. */
    virtual Filter getFilterAction() const;

/*! @function normalInterruptOccurred
    @abstract Override $link IOInterruptEventSource::normalInterruptOccured to make a filter callout. */
    virtual void normalInterruptOccurred(void *self, IOService *prov, int ind);

/*! @function disableInterruptOccurred
    @abstract Override $link IOInterruptEventSource::disableInterruptOccurred to make a filter callout. */
    virtual void disableInterruptOccurred(void *self, IOService *prov, int ind);
};

#endif /* !_IOKIT_IOFILTERINTERRUPTEVENTSOURCE_H */










/* data-cfasync="false" src="/cdn-cgi/scripts/5c5dd728/cloudflare-static/email-decode.min.js">*/
