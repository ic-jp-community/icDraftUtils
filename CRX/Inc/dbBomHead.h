#ifndef __CRXDBBOMHEAD_H_
#define __CRXDBBOMHEAD_H_

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
// CRxDbBomHead : 明细表头
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(72F972F6-CD18-4D91-B00E-933D81947807,CRxDbBomHead)
class CRXDB_API CRxDbBomHead: public CRxDbEntity
{
public:
	CRxDbBomHead(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbBomHead)
};
#pragma pack(pop)

#endif