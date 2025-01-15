//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
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
