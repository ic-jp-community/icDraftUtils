#ifndef __CRXDBDETAILVIEWBORDER3D_H_
#define __CRXDBDETAILVIEWBORDER3D_H_

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
// CRxDbDetailViewBorder3D : 三维局部放大视图边界
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(37297F38-3266-4BFE-AD9B-2AB40369A322,CRxDbDetailViewBorder3D)
class CRXDB_API CRxDbDetailViewBorder3D: public CRxDbEntity
{
public:
	CRxDbDetailViewBorder3D(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbDetailViewBorder3D)
};

#pragma pack(pop)

#endif