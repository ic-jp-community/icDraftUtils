//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//

#include "DbMain.h"

CRX_DEFINE_NULL_CLSID(CRxDbObjAdapter)
class CRXDB_API CRxDbObjAdapter : public CRxDbObject
{
	CRX_DECLARE_DYNAMIC(CRxDbObjAdapter)
	CRxDbObjAdapter(ICxCrxObject *i_pCrxObject = NULL);
};