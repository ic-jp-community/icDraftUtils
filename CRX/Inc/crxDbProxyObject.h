//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//

#include "DbMain.h"

CRX_DEFINE_CLSID(EE13E2A7-57E0-4198-9A3E-7B054530EB50,CRxDbProxyObject)
class CRXDB_API CRxDbProxyObject : public CRxDbObject
{
	CRX_DECLARE_DYNCREATE(CRxDbProxyObject)

	CRxDbProxyObject(ICxCrxObject *i_pCrxObject = NULL);
};