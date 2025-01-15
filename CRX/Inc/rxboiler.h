#ifndef CRX_RXBOILER_H
#define CRX_RXBOILER_H
//
//（C）Copyright 2009 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//


#include "crxChar.h"
#include "rxnames.h"
#pragma pack (push, 8)

// CRX_DECLARE_MEMBERS(CLASS_NAME)
//
// Use this macro to declare the member-functions "isA()", "desc()"
// and "cast()" for the class "CLASS_NAME" which is derived (at some
// level) from CrxRxObject.  Declaring these functions is required for
// the class to participate in the CrxRxObject runtime type identification
// mechanism.
//
// Note that you don't have to declare the class member-functions "isA()",
// "desc()" and "cast()" (i.e., this macro isn't needed) if you don't need
// to distinguish a class at runtime any further than one of its Rx-defined
// base classes.
//
// The static "rxInit()" function and the static "gpDesc" pointer, also
// declared by this macro, exist to allow us to implement the methods
// "isA()", "desc()" and "cast()".  The macros ACRX_DEFINE_MEMBERS()
// and CRX_xxx_DEFINE_MEMBERS() allow you to define the various
// functions and static variables declared with this macro.
//
// This macro MUST BE used inside the "public" section of the class
// declaration.  For example, use it like this:
//
//     class Foo : public CRxRxObject
//     {
//     public:
//         CRX_DECLARE_MEMBERS(Foo);
//         ...etc...
//     };
//
#define ACRX_DECLARE_MEMBERS(CLASS_NAME) \
    virtual CRxClass* isA() const; \
    static CRxClass* gpDesc; \
    static CRxClass* desc(); \
    static CLASS_NAME* cast(const CRxObject* inPtr) \
        { return ((inPtr == NULL) || !inPtr->isKindOf(CLASS_NAME::desc())) \
          ? NULL : (CLASS_NAME*)inPtr; }; \
    static void rxInit(); \
    static void rxInit(AppNameChangeFuncPtr)

// CRX_DEFINE_MEMBERS(CLASS_NAME)
//
// Use this macro to define the member functions declared with
// the CRX_DECLARE_MEMBERS() macro.
//
// This macro does not create the associated CrxRxClass object; that is
// the responsibility of a service implementation, i.e., the "rxInit()"
// static member-function declared by the ACRX_DECLARE_MEMBERS() macro.
//
// The ACRX_xxx_DEFINE_MEMBERS() macros defined below use this macro,
// as well as provide alternate definitions for the "rxInit()" function.
//
#define ACRX_DEFINE_MEMBERS(CLASS_NAME) \
CRxClass* CLASS_NAME::desc() \
{ \
    if (CLASS_NAME::gpDesc != NULL) \
        return CLASS_NAME::gpDesc; \
    return CLASS_NAME::gpDesc \
        = (CRxClass*)((CrxRxDictionary*)acrxSysRegistry() \
        ->at(ACRX_CLASS_DICTIONARY))->at(CRX_T(#CLASS_NAME)); \
} \
CRxClass* CLASS_NAME::isA() const \
{ \
    if (CLASS_NAME::gpDesc != NULL) \
        return CLASS_NAME::gpDesc; \
    return CLASS_NAME::gpDesc \
        = (CRxClass*)((CrxRxDictionary*)acrxSysRegistry() \
        ->at(ACRX_CLASS_DICTIONARY))->at(CRX_T(#CLASS_NAME)); \
} \
CRxClass* CLASS_NAME::gpDesc = NULL

// ACRX_NO_CONS_DEFINE_MEMBERS()
// ACRX_CONS_DEFINE_MEMBERS()
// ACRX_DXF_DEFINE_MEMBERS()
//
// These macros are similar to the ACRX_DEFINE_MEMBERS() macro,
// except they also provide implementations for the static "rxInit()"
// function.
//
// The differences between the three macros are manifested in how
// the CrxRxClass object responds to CrxRxClass::create() and
// CrxRxClass::dxfName() member functions.
//
// ACRX_NO_CONS_DEFINE_MEMBERS(CLASS_NAME,PARENT_CLASS)
//
//       For abstract classes and desired concrete classes, for
//       which no pseudo-constructor function is associated with
//       its CrxRxClass object.  For example, a class with a
//       protected/private default constructor should use
//       this macro.  <ClassName>::desc()->create()
//       returns NULL for CrxRxClass objects defined this way.
//       The class has no direct DWG or DXF file representation.
//
// ACRX_CONS_DEFINE_MEMBERS(CLASS_NAME,PARENT_CLASS)
//
//       For concrete classes with a meaningful default constructor.
//       Causes <ClassName::desc()->create() to return an instance of the
//       object created with its default constructor. Causes
//       <ClassName::desc()->dxfName() to return NULL.
//
// ACRX_DXF_DEFINE_MEMBERS(CLASS_NAME,PARENT_CLASS,PROXY_FLAGS,DXF_NAME,APP)
//
//       For classes directly instantiated in DWG and DXF,
//       <ClassName::desc()->create() returns an instance of the
//       object created with its default constructor.
//       <ClassName::desc()->dxfName() defines a string that
//       the CaxaDraft database queries as the preferred DXF
//       "object type" name.
//
// ACRX_STATIC_CHECK(CLASS_NAME)
//       Helper macro used by the various rxInit() implementations.
//       It makes sure that the static varible gpDesc is appropriately
//       reinitialized when necessary.
#include "crxChar.h"

extern "C" void  crx_abort (const CxCHAR * format, ...);
#define ACRX_STATIC_CHECK(CLASS_NAME) \
    if (CLASS_NAME::gpDesc) { \
        CRxClass *pClass = \
        (CRxClass*)((CrxRxDictionary*)acrxSysRegistry() \
            ->at(ACRX_CLASS_DICTIONARY))->at(CRX_T(#CLASS_NAME)); \
        if (pClass) { \
            if (CLASS_NAME::gpDesc == pClass) \
                return; \
            else \
                crx_abort(CRX_T(/*MSGO*/"Class mismatch")); \
        } \
    }

#define ACRX_NO_CONS_DEFINE_MEMBERS(CLASS_NAME,PARENT_CLASS) \
ACRX_DEFINE_MEMBERS(CLASS_NAME); \
void CLASS_NAME::rxInit() { \
    ACRX_STATIC_CHECK(CLASS_NAME); \
    CLASS_NAME::gpDesc = newAcRxClass(CRX_T(#CLASS_NAME), CRX_T(#PARENT_CLASS)); \
}

#define ACRX_CONS_DEFINE_MEMBERS(CLASS_NAME,PARENT_CLASS,VERNO) \
ACRX_DEFINE_MEMBERS(CLASS_NAME); \
static CRxObject * make##CLASS_NAME() { return new CLASS_NAME(); } \
void CLASS_NAME::rxInit() { \
    ACRX_STATIC_CHECK(CLASS_NAME); \
    CLASS_NAME::gpDesc = newAcRxClass(CRX_T(#CLASS_NAME), CRX_T(#PARENT_CLASS), \
        VERNO, &make##CLASS_NAME); \
}

#define ACRX_DXF_DEFINE_MEMBERS(CLASS_NAME,PARENT_CLASS,DWG_VERSION,\
              MAINTENANCE_VERSION,PROXY_FLAGS,DXF_NAME,APP) \
ACRX_DEFINE_MEMBERS(CLASS_NAME); \
static CRxObject * make##CLASS_NAME() { return new CLASS_NAME(); } \
void CLASS_NAME::rxInit() { \
    ACRX_STATIC_CHECK(CLASS_NAME); \
    CLASS_NAME::gpDesc = newAcRxClass(CRX_T(#CLASS_NAME), CRX_T(#PARENT_CLASS), \
        DWG_VERSION,MAINTENANCE_VERSION,PROXY_FLAGS, \
        &make##CLASS_NAME, CRX_T(#DXF_NAME), CRX_T(#APP)); \
} \
void CLASS_NAME::rxInit(AppNameChangeFuncPtr ptr) { \
    ACRX_STATIC_CHECK(CLASS_NAME); \
    CLASS_NAME::gpDesc = newAcRxClass(CRX_T(#CLASS_NAME), CRX_T(#PARENT_CLASS), \
        DWG_VERSION,MAINTENANCE_VERSION,PROXY_FLAGS, \
        &make##CLASS_NAME, CRX_T(#DXF_NAME), CRX_T(#APP), ptr); \
}

#pragma pack (pop)
#endif
