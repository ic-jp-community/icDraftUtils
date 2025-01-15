#ifndef __CRXDBIMAGEREF_H_
#define __CRXDBIMAGEREF_H_

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
// CRxDbImageRef : ͼƬ����
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(B4500E0A-C715-424e-BC25-08A152DBB98B,CRxDbImageRef)
class CRXDB_API CRxDbImageRef: public CRxDbEntity
{
public:
	CRxDbImageRef(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbImageRef)
};

#pragma pack(pop)

#endif
