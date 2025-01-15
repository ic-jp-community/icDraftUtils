//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#include "DbMain.h"

CRX_DEFINE_CLSID(286FF874-27E2-4e59-A3A3-BCC8E4E6F3EC,CRxDbProxyEntity)
class CRXDB_API CRxDbProxyEntity : CRxDbEntity
{
	CRX_DECLARE_DYNCREATE(CRxDbProxyEntity)

	CRxDbProxyEntity(ICxCrxObject *i_pCrxObject = NULL);
};