#ifndef __CRXDBPDFREF_H_
#define __CRXDBPDFREF_H_

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
// CRxDbPDFRef : PDF引用
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(CEF45391-2505-4F4C-BADF-9B88A82FC975,CRxDbPDFRef)
class CRXDB_API CRxDbPDFRef: public CRxDbEntity
{
public:
	CRxDbPDFRef(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbPDFRef)
};

#pragma pack(pop)

#endif
