#ifndef __CRXDBOLEOBJECT_H_
#define __CRXDBOLEOBJECT_H_

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#include "dbmain.h"
#pragma pack(push, 8)

/*------------------------------------------------------------------------------
// CrxDbOleObject : Ole对象
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(2C88349A-C486-4EA7-AC2B-063D16B763CC,CRxDbOleObject)
class CRXDB_API CRxDbOleObject: public CRxDbEntity
{
public:
	CRxDbOleObject(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbOleObject)
};

#pragma pack(pop)

#endif