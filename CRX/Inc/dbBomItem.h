#ifndef __CRXDBBOMItem_H_
#define __CRXDBBOMItem_H_

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
// CRxDbBomItem : 明细表项
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(1A6EFF84-514F-483D-8FF5-DF5B204E2BA8,CRxDbBomItem)
class CRXDB_API CRxDbBomItem: public CRxDbEntity
{
public:
	CRxDbBomItem(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbBomItem)
};
#pragma pack(pop)

#endif