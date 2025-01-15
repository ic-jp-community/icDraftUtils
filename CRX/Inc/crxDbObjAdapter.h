//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#include "DbMain.h"

CRX_DEFINE_NULL_CLSID(CRxDbObjAdapter)
class CRXDB_API CRxDbObjAdapter : public CRxDbObject
{
	CRX_DECLARE_DYNAMIC(CRxDbObjAdapter)
	CRxDbObjAdapter(ICxCrxObject *i_pCrxObject = NULL);
};