#ifndef __CRXDBIMAGEREF_H_
#define __CRXDBIMAGEREF_H_

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
// CRxDbImageRef : 图片引用
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(B4500E0A-C715-424e-BC25-08A152DBB98B,CRxDbImageRef)
class CRXDB_API CRxDbImageRef: public CRxDbEntity
{
public:
	CRxDbImageRef(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbImageRef)
};

#pragma pack(pop)

#endif
