//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#ifndef __CRXOBJECT_H_
#define __CRXOBJECT_H_

#include "CrxCx.h"
#include "CrxBase.h"
#include "ICxCrxBase.h"

class CCrxObject
{
public:
	CCrxObject(ICxCrxObject *pCrxObject = NULL);

public:
	virtual CrxRuntimeClass* GetRuntimeClass() const;
	static CrxRuntimeClass classCCrxObject;

public:
	ICxCrxObject *m_pCrxObject;

};

#endif // __CRXOBJECT_H_
