#ifndef __CRXDBENTITYEMBED_H_
#define __CRXDBENTITYEMBED_H_

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
// CRxDbEntityEmbed : 支持COM二次开发的嵌入对象
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(F099C9D0-5E3E-4bf7-B0D3-80A64DD5BE07,CRxDbEntityEmbed)
class CRXDB_API CRxDbEntityEmbed: public CRxDbEntity
{
public:
	CRxDbEntityEmbed(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbEntityEmbed)
};


#pragma pack(pop)

#endif