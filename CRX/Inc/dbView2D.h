#ifndef __CRXDBVIEW2D_H_
#define __CRXDBVIEW2D_H_

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
// CrxDbView2D : 二维局部放大图
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(BDF700DA-E09C-4ade-A1E4-0EADF201FF16,CRxDbView2D)
class CRXDB_API CRxDbView2D: public CRxDbEntity
{
public:
	CRxDbView2D(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbView2D)
};

#pragma pack(pop)

#endif