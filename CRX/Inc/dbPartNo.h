#ifndef __CRXDBPARTNO_H_
#define __CRXDBPARTNO_H_

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
// CrxDbPartNo : ���
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(DB778346-3D2B-4EB3-852D-80637E5CA149,CRxDbPartNo)
class CRXDB_API CRxDbPartNo: public CRxDbEntity
{
public:
	CRxDbPartNo(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbPartNo)
};

#pragma pack(pop)

#endif