#ifndef CRX_DBBOILER_H
#define CRX_DBBOILER_H

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

//#include "rxboiler.h"

// Macro for common declarations of classes derived from
// CrxDbObject which are built into CaxaDraft.
//
// This macro is NOT intended for application-defined classes derived
// from CrxDbObject when declaring their class header.  This macro declares
// an internally used form of constructor, which takes the
// CRxDbSystemInternals* argument.  Rx applications should not define
// such constructors for their database object classes, but they should
// be ignored by the system anyway.
//
// Application-defined classes are advised to use the ACRX_DECLARE_MEMBERS
// macro instead, and to consult the documentation for related definitions.
//
#define CRXDB_DECLARE_MEMBERS(CLASSNAME) \
private: \
    friend class CRxDbSystemInternals; \
protected: \
    CLASSNAME(CRxDbSystemInternals*); \
public: \
    CRX_DECLARE_DYNAMIC(CLASSNAME)

// The acdbOpenObject() function is a template function defined in
// dbmain.h where the first parameter is of type (CLASSNAME *&).
// The following macro exists for backwards compatibility with prior
// source which required use of this macro to define a type-specific
// version acdbOpenObject().
#define MAKE_ACDBOPENOBJECT_FUNCTION(CLASSNAME)

#endif
