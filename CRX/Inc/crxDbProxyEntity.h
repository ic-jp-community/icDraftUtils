//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//

#include "DbMain.h"

CRX_DEFINE_CLSID(286FF874-27E2-4e59-A3A3-BCC8E4E6F3EC,CRxDbProxyEntity)
class CRXDB_API CRxDbProxyEntity : CRxDbEntity
{
	CRX_DECLARE_DYNCREATE(CRxDbProxyEntity)

	CRxDbProxyEntity(ICxCrxObject *i_pCrxObject = NULL);
};