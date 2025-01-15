//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
#ifndef CRXDBDOUBLECLICKEDIT_H
#define CRXDBDOUBLECLICKEDIT_H

#include "StdAfx.h"
#include "dbmain.h"
#include "rxObject.h"
#include "CrxEdApiCx.h"

class CRxGePoint3d;
class CRxDbEntity;


CRX_DEFINE_NULL_CLSID(CrxDbDoubleClickEdit)
class CRXEDAPI_CLASS CAXA_NO_VTABLE  CrxDbDoubleClickEdit : public CRxObject
	//
	//  CrxDbDoubleClickEdit Protocol extension abstract base class. 
	//
{
public:
	CRX_DECLARE_DYNAMIC(CrxDbDoubleClickEdit);
	CrxDbDoubleClickEdit(void){};
	~CrxDbDoubleClickEdit(void){};
	virtual void startEdit(CRxDbEntity *pEnt, CRxGePoint3d pt) = 0; 
	virtual void finishEdit(void) = 0;
};
 

#endif //CRXDBDOUBLECLICKEDIT_H
