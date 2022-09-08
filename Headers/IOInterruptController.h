/*
<title>iokit/IOKit/IOInterruptController.h Source</title>
</head><body>
<h1>Source to iokit/IOKit/IOInterruptController.h</h1>
<hr><form action="/cgi-bin/src2html.cgi" method="POST">
<input type="submit" value="Search">
<input type="text" name="xnu/newsrc">
Enter a symbol's name here to quickly find it.
</form><hr>
<pre>/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
 *
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="89c8d9d9c5ccd6c5c0caccc7daccd6c1ccc8cdccdbd6daddc8dbddc9">[email&#160;protected]</a>
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
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="a7e6f7f7ebe2f8ebeee4e2e9f4e2f8efe2e6e3e2f5f8e2e9e3e7">[email&#160;protected]</a>
 */
/*
 * Copyright (c) 1999 Apple Computer, Inc.  All rights reserved.
 *
 *  DRI: Josh de Cesare
 *  
 */


#ifndef _IOKIT_IOINTERRUPTCONTROLLER_H
#define <a name="_IOKIT_IOINTERRUPTCONTROLLER_H" < a><b>_IOKIT_IOINTERRUPTCONTROLLER_H</b>

#include &lt;IOKit/IOLocks.h&gt;
#include &lt;IOKit/IOService.h&gt;
#include &lt;IOKit/IOInterrupts.h&gt;


class <a name="IOSharedInterruptController" < a><b>IOSharedInterruptController</b>;

struct <a name="IOInterruptVector" < a><b>IOInterruptVector</b> {
  volatile char               interruptActive;
  volatile char               interruptDisabledSoft;
  volatile char               interruptDisabledHard;
  volatile char               interruptRegistered;
  IOLock *                    interruptLock;
  IOService *                 nub;
  long                        source;
  void *                      target;
  IOInterruptHandler          handler;
  void *                      refCon;
  IOSharedInterruptController *sharedController;
};

typedef struct IOInterruptVector IOInterruptVector;


class IOInterruptController : public IOService
{
  OSDeclareAbstractStructors(IOInterruptController);

protected:
  IOInterruptVector *vectors;
  
public:
  virtual IOReturn registerInterrupt(IOService *nub, int source,
				     void *target,
				     IOInterruptHandler handler,
				     void *refCon);
  virtual IOReturn unregisterInterrupt(IOService *nub, int source);
  
  virtual IOReturn getInterruptType(IOService *nub, int source,
				    int *interruptType);
  
  virtual IOReturn enableInterrupt(IOService *nub, int source);
  virtual IOReturn disableInterrupt(IOService *nub, int source);
  virtual IOReturn causeInterrupt(IOService *nub, int source);
  
  virtual IOInterruptAction getInterruptHandlerAddress(void);
  virtual IOReturn handleInterrupt(void *refCon, IOService *nub,
				   int source);
  
  // Methods to be overridden for simplifed interrupt controller subclasses.
  
  virtual bool vectorCanBeShared(long vectorNumber, IOInterruptVector *vector);
  virtual void initVector(long vectorNumber, IOInterruptVector *vector);
  virtual int  getVectorType(long vectorNumber, IOInterruptVector *vector);
  virtual void disableVectorHard(long vectorNumber, IOInterruptVector *vector);
  virtual void enableVector(long vectorNumber, IOInterruptVector *vector);
  virtual void causeVector(long vectorNumber, IOInterruptVector *vector);
};


class IOSharedInterruptController : public IOInterruptController
{
  OSDeclareDefaultStructors(IOSharedInterruptController);
  
private:
  IOService         *provider;
  int               numVectors;
  int               vectorsRegistered;
  int               vectorsEnabled;
  volatile long     controllerDisabled;
  bool              sourceIsLevel;
  
public:
  virtual IOReturn initInterruptController(IOInterruptController *parentController, OSData *parentSource);
  
  virtual IOReturn registerInterrupt(IOService *nub, int source,
                                     void *target,
                                     IOInterruptHandler handler,
                                     void *refCon);
  virtual IOReturn unregisterInterrupt(IOService *nub, int source);
  
  virtual IOReturn getInterruptType(IOService *nub, int source,
				    int *interruptType);
  
  virtual IOReturn enableInterrupt(IOService *nub, int source);
  virtual IOReturn disableInterrupt(IOService *nub, int source);
  
  virtual IOInterruptAction getInterruptHandlerAddress(void);
  virtual IOReturn handleInterrupt(void *refCon, IOService *nub, int source);
};


#endif /* ! _IOKIT_IOINTERRUPTCONTROLLER_H */










/* data-cfasync="false" src="/cdn-cgi/scripts/5c5dd728/cloudflare-static/email-decode.min.js">*/
