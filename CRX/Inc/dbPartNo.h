#ifndef __CRXDBPARTNO_H_
#define __CRXDBPARTNO_H_

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
// CrxDbPartNo : 序号
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(DB778346-3D2B-4EB3-852D-80637E5CA149,CRxDbPartNo)
class CRXDB_API CRxDbPartNo: public CRxDbEntity
{
public:
	CRxDbPartNo(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbPartNo)
};

#pragma pack(pop)

#endif