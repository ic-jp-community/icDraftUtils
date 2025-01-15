#ifndef __CRXDBDIMMLEADER_H_
#define __CRXDBDIMMLEADER_H_

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
// CrxDbDimCoord : 多引线
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(B4E9F8BB-78B7-4B64-B2D3-D26F0C373CEB,CRxDbDimMLeader)
class CRXDB_API CRxDbDimMLeader: public CRxDbEntity
{
public:
	CRxDbDimMLeader(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbDimMLeader)
};

#pragma pack(pop)

#endif