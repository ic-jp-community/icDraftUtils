#ifndef __CRXDBMLEADERSTYLE_H_
#define __CRXDBMLEADERSTYLE_H_

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
// CRxDbMLeaderStyle : 多引线风格
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(17988C80-33F5-44B2-B4F3-AF07D3C74C08,CRxDbMLeaderStyle)
class CRXDB_API CRxDbMLeaderStyle: public CRxDbObject
{
public:
	CRxDbMLeaderStyle(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbMLeaderStyle)
};

#pragma pack(pop)

#endif