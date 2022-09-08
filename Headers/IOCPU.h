/*
<title>iokit/IOKit/IOCPU.h Source</title>
</head><body>
<h1>Source to iokit/IOKit/IOCPU.h</h1>
<hr><form action="/cgi-bin/src2html.cgi" method="POST">
<input type="submit" value="Search">
<input type="text" name="xnu/newsrc">
Enter a symbol's name here to quickly find it.
</form><hr>
<pre>/*
 * Copyright (c) 1999 Apple Computer, Inc.  All rights reserved.
 *
 *  DRI: Josh de Cesare
 *
 */

#ifndef _IOKIT_CPU_H
#define <a name="_IOKIT_CPU_H" < a><b>_IOKIT_CPU_H</b>

extern "C" {
#include &lt;machine/machine_routines.h&gt;
#include &lt;pexpert/pexpert.h&gt;
}

#include &lt;IOKit/IOService.h&gt;
#include &lt;IOKit/IOInterruptController.h&gt;

#define <a name="kIOCPUStateUnregistered" < a><b>kIOCPUStateUnregistered</b> (0)
#define <a name="kIOCPUStateUninitalized" < a><b>kIOCPUStateUninitalized</b> (1)
#define <a name="kIOCPUStateStopped" < a><b>kIOCPUStateStopped</b>      (2)
#define <a name="kIOCPUStateRunning" < a><b>kIOCPUStateRunning</b>      (3)

class <a name="IOCPUInterruptController" < a><b>IOCPUInterruptController</b>;

extern IOCPUInterruptController *<a name="gIOCPUInterruptController" < a><b>gIOCPUInterruptController</b>;

class IOCPU : public IOService
{
  OSDeclareAbstractStructors(IOCPU);
  
protected:
  OSDictionary  *cpuGroup;
  IOService     *cpuNub;
  int           physCPU;
  int           cpuState;
  processor_t   machProcessor;
  ipi_handler_t ipi_handler;
  
public:
  static  void          initCPUs(void);
  
  virtual bool          start(IOService *provider);
  virtual void          initCPU(void);
  virtual kern_return_t startCPU(vm_offset_t start_paddr,
				 vm_offset_t arg_paddr);
  virtual void          haltCPU(vm_offset_t start_paddr,
				vm_offset_t arg_paddr);
  virtual void          signalCPU(IOCPU *target);
  
  virtual int           getCPUNumber(void);
  virtual int           getCPUState(void);
  virtual OSDictionary  *getCPUGroup(void);
  virtual int           getCPUGroupSize(void);
  
  virtual OSSymbol      *getCPUName(void) = 0;
};

class IOCPUInterruptController : public IOInterruptController
{
  OSDeclareDefaultStructors(IOCPUInterruptController);
  
private:
  int   enabledCPUs;
  
protected:  
  int   numCPUs;
  IOCPU **cpus;
  
  
public:
  virtual IOReturn initCPUInterruptController(int sources);
  virtual void     registerCPUInterruptController(void);
  virtual void     setCPUInterruptProperties(IOService *service);
  virtual void     enableCPUInterrupt(IOCPU *cpu);
  
  virtual IOReturn registerInterrupt(IOService *nub, int source,
				     void *target,
				     IOInterruptHandler handler,
				     void *refCon);
  
  virtual IOReturn getInterruptType(IOService *nub, int source,
				    int *interruptType);
  
  virtual IOReturn enableInterrupt(IOService *nub, int source);
  virtual IOReturn disableInterrupt(IOService *nub, int source);
  virtual IOReturn causeInterrupt(IOService *nub, int source);
  
  virtual IOReturn handleInterrupt(void *refCon, IOService *nub,
				   int source);
};

#endif /* ! _IOKIT_CPU_H */










</pre></body>
