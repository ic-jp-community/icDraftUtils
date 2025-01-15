#ifndef __CRXDBPDFREF_H_
#define __CRXDBPDFREF_H_

//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//

#include "dbmain.h"
#pragma pack(push, 8)

/*------------------------------------------------------------------------------
// CRxDbPDFRef : PDF����
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(CEF45391-2505-4F4C-BADF-9B88A82FC975,CRxDbPDFRef)
class CRXDB_API CRxDbPDFRef: public CRxDbEntity
{
public:
	CRxDbPDFRef(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbPDFRef)
};

#pragma pack(pop)

#endif
