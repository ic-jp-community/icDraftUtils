#ifndef   _CDRAFT_H
#define  _CDRAFT_H

//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//	End-users must also comply with the terms and conditions 
//	in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//	版权所有（C）北京数码大方科技股份有限公司
//	最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
// 

#include "crxChar.h"            

// #define CDraft_Boolean_is_bool 1
#pragma pack (push, 8)

struct CAXA
{
    // The types Int8, Int16 and Int32 will be conditionally compiled
    // to guarantee that each one represents an integer type of exactly
    // 8, 16 and 32 bits respectively.    These are to be used only when
    // the EXACT size of the integer is critical.
    //
    typedef char       Int8;
    typedef short      Int16;
    typedef long       Int32;
    typedef __int64    Int64;

    //
    // The unsigned versions of the above types.
    //
    typedef unsigned char  UInt8;
    typedef unsigned short UInt16;
    typedef unsigned long  UInt32;
    typedef unsigned __int64 UInt64;

    // Convenient abbreviations (use optionally).
    //
    typedef unsigned char  uchar;
    typedef unsigned short ushort;
    typedef unsigned int   uint;
    typedef unsigned long  ulong;

    // integer/unsigned integers that can hold a pointer value.
    // These change size depending on the platform and should NEVER
    // be streamed out to permanent storage.
#ifndef _WIN64

    // Using __w64 let's us catch potential errors at compile time
    // when /Wp64 is enabled.  Also, we use long, instead of int,
    // in the 32-bit build.  That's for compatibility with the Int32
    // and UInt32 types.
    //
    typedef __w64 long          LongPtr;
    typedef __w64 unsigned long ULongPtr;
    //
    typedef __w64 int           IntPtr;
    typedef __w64 unsigned int  UIntPtr;
#else   // _WIN64
    typedef __int64             LongPtr;
    typedef unsigned __int64    ULongPtr;
    typedef __int64             IntPtr;
    typedef unsigned __int64    UIntPtr;
#endif

    typedef LongPtr IntDbId;
    typedef IntPtr GsMarker;

    // Logical type (Note: never use int when Boolean is intended!)
    //
#ifndef CAXA_Boolean_is_bool
    typedef int        Boolean;
    enum           { kFalse = 0, kTrue = 1 };
#else
    typedef bool       Boolean;
    enum           { kFalse = false, kTrue = true };
#endif

};

#ifndef NULL
#define NULL 0
#endif

#pragma pack (pop)

//  These are constant definitions: regardless of whether the Unicode
//  or legacy character system is in use, the legacy character type
//  will always be an 8-bit character.
//
//  Note: use LEGACY_CHAR to represent *textual* information; do not
//  use it for 8-bit binary data; the AC_BYTE type, below, is intended
//  for that use.  Use legacy characters sparingly, where CxCHAR is
//  inappropriate.
typedef          char         LEGACY_CHAR;
typedef          char*        LEGACY_STRING;
typedef const    char*        LEGACY_STRING_CONST;
typedef       unsigned short  WIDE_CHAR;          // UTF-16 format
typedef       unsigned short* WIDE_STRING;        // UTF-16 format
typedef const unsigned short* WIDE_STRING_CONST;  // UTF-16 format

//  One of the (ab)uses of the char type is to point to bytes of memory.
//  The (void*) isn't good for this because the sizeof a void element may
//  not be what one expects.  This type is offered as a generic pointer
//  to memory, but in which sizeof(element) == 1.  We use char instead
//  of byte only because signed/unsigned mismatches will cause a flurry
//  of warnings in the transition; eventually, the type can be anything
//  we want.
typedef          char*   MEMORY_POINTER;
typedef const    char*   MEMORY_POINTER_CONST;

//  Describes an 8-bit numerical quantity, *not* a character.
typedef unsigned char    CX_BYTE;

// Use CAXA_NO_VTABLE on base classes which:
//   1. have virtual methods
//   2. are never instantiated
//   3. have a ctor and/or a dtor
//   4. do not call any virtual methods in the ctor or dtor
// This allows the compiler to avoid assigning a vtable pointer at
// the top of the base class's ctor and dtor.  So the vtable itself
// and any methods it points to which aren't used elsewhere can be
// omitted by the linker and reduce overall space.
//
// Make sure though that the base class is never instantiated.  Making
// the ctor protected or using pure virtual methods can help with this.
//
#define CAXA_NO_VTABLE __declspec(novtable)
#define CAXA_STDCALL   __stdcall
#define CAXA_DEPRECATED __declspec(deprecated)

#endif
