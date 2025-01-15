#ifndef __CRXDBVIEW3D_H_
#define __CRXDBVIEW3D_H_

//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//

#include "dbmain.h"
#pragma pack(push, 8)


/*------------------------------------------------------------------------------
// CrxDbView3D : 三维视图
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(107EDD1A-6559-4E9B-B7CB-EB5B5A065517,CRxDbView3D)
class CRXDB_API CRxDbView3D: public CRxDbEntity
{
public:
	CRxDbView3D(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbView3D)
};

#pragma pack(pop)

#endif