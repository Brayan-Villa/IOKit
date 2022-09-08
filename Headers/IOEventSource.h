/*
<title>iokit/IOKit/IOEventSource.h Source</title>
</head><body>
<h1>Source to iokit/IOKit/IOEventSource.h</h1>
<hr><form action="/cgi-bin/src2html.cgi" method="POST">
<input type="submit" value="Search">
<input type="text" name="xnu/newsrc">
Enter a symbol's name here to quickly find it.
</form><hr>
<pre>/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
 *
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="115041415d544e5d5852545f42544e5954505554434e424550434551">[email&#160;protected]</a>
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
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="a8e9f8f8e4edf7e4e1ebede6fbedf7e0ede9ecedfaf7ede6ece8">[email&#160;protected]</a>
 */
/*
Copyright (c) 1998 Apple Computer, Inc.	 All rights reserved.
HISTORY
    1998-7-13	Godfrey van der Linden(gvdl)
	Created.
    1998-10-30	Godfrey van der Linden(gvdl)
	Converted to C++
*/
#ifndef _IOKIT_IOEVENTSOURCE_H
#define <a name="_IOKIT_IOEVENTSOURCE_H" < a><b>_IOKIT_IOEVENTSOURCE_H</b>

#include &lt;sys/cdefs.h&gt;

#include &lt;libkern/c++/OSObject.h&gt;

#include &lt;IOKit/IOLib.h&gt;
#include &lt;IOKit/system.h&gt;

__BEGIN_DECLS
#include &lt;mach/clock_types.h&gt;
#include &lt;kern/clock.h&gt;
__END_DECLS

class <a name="IOWorkLoop" < a><b>IOWorkLoop</b>;

/*!
    @class IOEventSource : public OSObject
    @abstract Abstract class for all work-loop event sources.
    @discussion The IOEventSource declares the abstract super class that all
event sources must inherit from if an IOWorkLoop is to receive events from them.
&lt;br&gt;&lt;br&gt;
	An event source can represent any event that should cause the work-loop of a
device to wake up and perform work.  Two examples of event sources are the
IOInterruptEventSource which delivers interrupt notifications and IOCommandGate
which delivers command requests.
&lt;br&gt;&lt;br&gt;
	A kernel module can always use the work-loop model for serialising access to
anything at all.  The IOEventSource is used for communicating events to the
work-loop, and the chain of event sources should be used to walk the possible
event sources and demultipex them.  Note a particular instance of an event
source may only be a member of 1 linked list chain.  If you need to move it
between chains than make sure it is removed from the original chain before
attempting to move it.
&lt;br&gt;&lt;br&gt;
	The IOEventSource makes no attempt to maintain the consitency of it's internal data across multi-threading.  It is assumed that the user of these basic tools will protect the data that these objects represent in some sort of device wide instance lock.	For example the IOWorkLoop maintains the event chain by handing off change request to its own thread and thus single threading access to its state.
&lt;br&gt;&lt;br&gt;
	All subclasses of the IOEventSource are expected to implement the checkForWork() member function.

&lt;br&gt;&lt;br&gt;
	checkForWork() is the key method in this class.	 It is called by some work-loop when convienient and is expected to evaluate it's internal state and determine if an event has occured since the last call.  In the case of an event having occurred then the instance defined target(owner)/action will be called.	 The action is stored as an ordinary C function pointer but the first parameter is always the owner.  This means that a C++ member function can be used as an action function though this depends on the ABI.
&lt;br&gt;&lt;br&gt;
	Although the eventChainNext variable contains a reference to the next event source in the chain this reference is not retained.  The list 'owner' i.e. the client that creates the event, not the work-loop, is expected to retain the source.
*/
class IOEventSource : public OSObject
{
    OSDeclareAbstractStructors(IOEventSource)
    friend class IOWorkLoop;

public:
/*!
    @typedef Action
    @discussion Placeholder type for C++ function overloading discrimination.
As the all event sources require an action and it has to be stored somewhere
and be of some type, this is that type.
    @param owner
	Target of the function, can be used as a refcon.  The owner is set
during initialisation.	 Note if a C++ function was specified this parameter
is implicitly the first paramter in the target member function's parameter list.
*/
    typedef void (*Action)(OSObject *<a name="owner" < a><b>owner</b>, ...);

/*! @defined IOEventSourceAction
    @discussion Backward compatibilty define for the old non-class scoped type definition.  See $link IOEventSource::Action */
 #define <a name="IOEventSourceAction" < a><b>IOEventSourceAction</b> IOEventSource::Action

protected:
/*! @var eventChainNext
	The next event source in the event chain. nil at end of chain. */
    IOEventSource *eventChainNext;

/*! @var owner The owner object called when an event has been delivered. */
    OSObject *owner;

/*! @var action
	The action method called when an event has been delivered */
    Action action;

/*! @var enabled
	Is this event source enabled to deliver requests to the work-loop. */
    bool enabled;

/*! @var workLoop What is the work-loop for this event source. */
    IOWorkLoop *workLoop;

/*! @var refcon What ever the client wants to do, see $link setRefcon. */
    void *refcon;

/*! @function init
    @abstract Primary initialiser for the IOEventSource class.
    @param owner
	Owner of this instance of an event source.  Used as the first parameter
of the action callout.	Owner will generally be an OSObject it doesn't have to
be as no member functions will be called directly in it.  It can just be a
refcon for a client routine.
    @param action
	Pointer to C call out function.	 Action is a pointer to a C function
that gets called when this event source has outstanding work.  It will usually
be called by the checkForWork member function.	The first parameter of the
action call out will always be the owner, this allows C++ member functions to
be used as actions.  Defaults to 0.
    @result true if the inherited classes and this instance initialise
successfully.
*/
    virtual bool init(OSObject *owner, IOEventSource::Action action = 0);

/*! @function checkForWork
    @abstract Pure Virtual member function used by IOWorkLoop for work
scheduling.
    @discussion This function will be called to request a subclass to check
it's internal state for any work to do and then to call out the owner/action.
    @result Return true if this function needs to be called again before all its outstanding events have been processed.
        */
    virtual bool checkForWork() = 0;

/*! @function setWorkLoop
    @abstract Set'ter for $link workLoop variable.
    @param workLoop
	Target work-loop of this event source instance.	 A subclass of
IOWorkLoop that at least reacts to signalWorkAvailable() and onThread functions. 
*/
    virtual void setWorkLoop(IOWorkLoop *workLoop);

/*! @function setNext
    @abstract Set'ter for $link eventChainNext variable.
    @param next
	Pointer to another IOEventSource instance.
*/
    virtual void setNext(IOEventSource *next);

/*! @function getNext
    @abstract Get'ter for $link eventChainNext variable.
    @result value of eventChainNext.
*/
    virtual IOEventSource *getNext() const;

public:
/*! @function setAction
    @abstract Set'ter for $link action variable.
    @param action Pointer to a C function of type IOEventSource::Action. */
    virtual void setAction(IOEventSource::Action action);

/*! @function getAction
    @abstract Get'ter for $link action variable.
    @result value of action. */
    virtual IOEventSource::Action getAction() const;

/*! @function enable
    @abstract Enable event source.
    @discussion A subclass implementation is expected to respect the enabled
state when checkForWork is called.  Calling this function will cause the
work-loop to be signalled so that a checkForWork is performed. */
    virtual void enable();

/*! @function disable
    @abstract Disable event source.
    @discussion A subclass implementation is expected to respect the enabled
state when checkForWork is called. */
    virtual void disable();

/*! @function isEnabled
    @abstract Get'ter for $link enable variable.
    @result true if enabled. */
    virtual bool isEnabled() const;

/*! @function getWorkLoop
    @abstract Get'ter for $link workLoop variable.
    @result value of workLoop. */
    virtual IOWorkLoop *getWorkLoop() const;

/*! @function onThread
    @abstract Convenience function for workLoop-&gt;onThread.
    @result true if called on the work-loop thread.
*/
    virtual bool onThread() const;
};

#endif /* !_IOKIT_IOEVENTSOURCE_H */










/* data-cfasync="false" src="/cdn-cgi/scripts/5c5dd728/cloudflare-static/email-decode.min.js">*/
