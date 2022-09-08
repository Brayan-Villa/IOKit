/*
 * Copyright (c) 1998-2000 Apple Computer, Inc. All rights reserved.
 *
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="6524353529203a292c26202b36203a2d20242120373a363124373125">[email&#160;protected]</a>
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
 * @<a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="713021213d342e3d3832343f22342e3934303534232e343f3531">[email&#160;protected]</a>
 */
/*
 * Copyright (c) 1998 Apple Computer, Inc.  All rights reserved. 
 *
 * HISTORY
 *
 */

#ifndef	__IOKIT_IOTYPES_H
#define <a name="__IOKIT_IOTYPES_H" < a><b>__IOKIT_IOTYPES_H</b>

#ifndef IOKIT
#define <a name="IOKIT" < a><b>IOKIT</b> 1
#endif /* !IOKIT */

#if KERNEL
#include &lt;IOKit/system.h&gt;
#else
#include &lt;mach/message.h&gt;
#include &lt;mach/vm_types.h&gt;
#endif

#include &lt;IOKit/IOReturn.h&gt;

#ifdef __cplusplus
extern "C" {
#endif

#ifndef	NULL
#define	<a name="NULL" < a><b>NULL</b>	0
#endif
	
/*
 * Simple data types.
 */
#ifndef __MACTYPES__	/* CF MacTypes.h */
#ifndef __TYPES__	/* guess... Mac Types.h */

#include &lt;libkern/OSTypes.h&gt;

#ifndef __cplusplus
#if !TYPE_BOOL
#ifdef KERNEL
typedef int	<a name="bool" < a><b>bool</b>;
enum {
    false	= 0,
    true	= 1
};
#endif
#endif
#endif

#endif /* __TYPES__ */
#endif /* __MACTYPES__ */

typedef UInt32		<a name="IOOptionBits" < a><b>IOOptionBits</b>;
typedef SInt32		<a name="IOFixed" < a><b>IOFixed</b>;
typedef UInt32		<a name="IOVersion" < a><b>IOVersion</b>;
typedef UInt32		<a name="IOItemCount" < a><b>IOItemCount</b>;
typedef UInt32  	<a name="IOCacheMode" < a><b>IOCacheMode</b>;

typedef UInt32	 	<a name="IOByteCount" < a><b>IOByteCount</b>;

typedef vm_address_t	 <a name="IOVirtualAddress" < a><b>IOVirtualAddress</b>;
typedef IOVirtualAddress <a name="IOLogicalAddress" < a><b>IOLogicalAddress</b>;

#if 0

typedef UInt64	<a name="IOPhysicalAddress" < a><b>IOPhysicalAddress</b>;
typedef UInt64	<a name="IOPhysicalLength" < a><b>IOPhysicalLength</b>;
#define <a name="IOPhysical32" < a><b>IOPhysical32</b>( hi, lo )		((UInt64) lo + ((UInt64)(hi) &lt;&lt; 32))
#define <a name="IOPhysSize" < a><b>IOPhysSize</b>	64

#else

typedef UInt32	IOPhysicalAddress;
typedef UInt32	IOPhysicalLength;
#define IOPhysical32( hi, lo )		(lo)
#define IOPhysSize	32

#endif

/*
 * Map between #defined or enum'd constants and text description.
 */
typedef struct {
	int value;
	const char *name;
} <a name="IONamedValue" < a><b>IONamedValue</b>;


/*
 * Memory alignment -- specified as a power of two.
 */
typedef unsigned int	<a name="IOAlignment" < a><b>IOAlignment</b>;

#define <a name="IO_NULL_VM_TASK" < a><b>IO_NULL_VM_TASK</b>		((vm_task_t)0)


/*
 * Pull in machine specific stuff.
 */

//#include &lt;IOKit/machine/IOTypes.h&gt;

#ifndef MACH_KERNEL

#ifndef __IOKIT_PORTS_DEFINED__
#define <a name="__IOKIT_PORTS_DEFINED__" < a><b>__IOKIT_PORTS_DEFINED__</b>
#ifdef KERNEL
typedef struct OSObject * <a name="io_object_t" < a><b>io_object_t</b>;
#else /* KERNEL */
typedef mach_port_t	io_object_t;
#endif /* KERNEL */
#endif /* __IOKIT_PORTS_DEFINED__ */

#include &lt;device/device_types.h&gt;

typedef io_object_t	<a name="io_connect_t" < a><b>io_connect_t</b>;
typedef io_object_t	<a name="io_iterator_t" < a><b>io_iterator_t</b>;
typedef io_object_t	<a name="io_registry_entry_t" < a><b>io_registry_entry_t</b>;
typedef io_object_t	<a name="io_service_t" < a><b>io_service_t</b>;

typedef io_object_t	<a name="io_enumerator_t" < a><b>io_enumerator_t</b>;

#endif /* MACH_KERNEL */

// IOConnectMapMemory memoryTypes
enum {
    kIODefaultMemoryType	= 0
};

enum {
    kIODefaultCache		= 0,
    kIOInhibitCache		= 1,
    kIOWriteThruCache		= 2,
    kIOCopybackCache		= 3
};

// IOMemory mapping options
enum {
    kIOMapAnywhere		= 0x00000001,

    kIOMapCacheMask		= 0x00000300,
    kIOMapCacheShift		= 8,
    kIOMapDefaultCache		= kIODefaultCache   &lt;&lt; kIOMapCacheShift,
    kIOMapInhibitCache		= kIOInhibitCache   &lt;&lt; kIOMapCacheShift,
    kIOMapWriteThruCache	= kIOWriteThruCache &lt;&lt; kIOMapCacheShift,
    kIOMapCopybackCache		= kIOCopybackCache  &lt;&lt; kIOMapCacheShift,

    kIOMapUserOptionsMask	= 0x00000fff,

    kIOMapReadOnly		= 0x00001000,

    kIOMapStatic		= 0x01000000,
    kIOMapReference		= 0x02000000
};

/*! @enum Scale Factors
    @discussion Used when a scale_factor parameter is required to define a unit of time.
    @constant kNanosecondScale Scale factor for nanosecond based times.
    @constant kMicrosecondScale Scale factor for microsecond based times.
    @constant kMillisecondScale Scale factor for millisecond based times.
    @constant kSecondScale Scale factor for second based times. */

enum {
    kNanosecondScale  = 1,
    kMicrosecondScale = 1000,
    kMillisecondScale = 1000 * 1000,
    kSecondScale      = 1000 * 1000 * 1000
};

/* compatibility types */

#ifndef KERNEL
/*
 * Machine-independent caching specification.
 */
typedef enum {
        IO_CacheOff,                    // cache inhibit
        IO_WriteThrough,
        IO_CopyBack
} <a name="IOCache" < a><b>IOCache</b>;

//typedef char <a name="OSString" < a><b>OSString</b>[64];
typedef unsigned int <a name="IODeviceNumber" < a><b>IODeviceNumber</b>;
typedef unsigned int <a name="IOObjectNumber" < a><b>IOObjectNumber</b>;

#endif

#ifdef __cplusplus
}
#endif

#endif /* ! __IOKIT_IOTYPES_H */

