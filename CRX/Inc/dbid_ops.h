#ifndef _CRX_DBID_OPS_H
#define _CRX_DBID_OPS_H 1
//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//
// DESCRIPTION:
//
// This file declares functions called by the app versions of the comparison
// operators of class CrxDbObjectId.  This file currently contains the c4 
// versions of these functions and will be updated to contain c5 versions
// of these functions.  Adjacent apps that compile against c4 will thus not
// experience behavioral changes when c5 CaxaDraft ships.  However, by 
// recompiling against c5, adjacent apps can pick up the modified behavior 
// of these operators, as the operators themselves will be modified to
// call the new functions in the header dbidapps.h
//
// Presumably, this file will be eliminated, and these functions will be
// collapsed back into dbid.h as inlines, at a later date.
//
// For further description of the CrxDbObjectId types, see dbid.h

#include "cdraft.h"
#include "dbid.h"

//class AcDbStub;
CRXDB_API
bool
c5ObjIdIsLessThan(const CRxDbStub * lhs, const CRxDbStub * rhs); 

CRXDB_API
bool
c5ObjIdIsGreaterThan(const CRxDbStub * lhs, const CRxDbStub * rhs); 

CRXDB_API
bool
c5ObjIdLessThanOrEqual(const CRxDbStub * lhs, const CRxDbStub * rhs); 

CRXDB_API
bool
c5ObjIdGreaterThanOrEqual(const CRxDbStub * lhs, const CRxDbStub * rhs); 

CRXDB_API
bool
c5ObjIdIsEqualTo(const CRxDbStub * lhs, const CRxDbStub * rhs); 

CRXDB_API
bool
c4ObjIdIsLessThan(CAXA::ULongPtr lhs, CAXA::ULongPtr rhs); 

CRXDB_API
bool
c4ObjIdIsGreaterThan(CAXA::ULongPtr lhs, CAXA::ULongPtr rhs); 

CRXDB_API
bool
c4ObjIdLessThanOrEqual(CAXA::ULongPtr lhs, CAXA::ULongPtr rhs); 

CRXDB_API
bool
c4ObjIdGreaterThanOrEqual(CAXA::ULongPtr lhs, CAXA::ULongPtr rhs); 

CRXDB_API
bool
c4ObjIdIsEqualTo(CAXA::ULongPtr lhs, CAXA::ULongPtr rhs); 

CRXDB_API
bool
c4ObjIdNotEqualTo(CAXA::ULongPtr lhs, CAXA::ULongPtr rhs); 

#endif

