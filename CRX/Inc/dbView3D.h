#ifndef __CRXDBVIEW3D_H_
#define __CRXDBVIEW3D_H_

//
//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//
//

#include "dbmain.h"
#pragma pack(push, 8)


/*------------------------------------------------------------------------------
// CrxDbView3D : ��ά��ͼ
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(107EDD1A-6559-4E9B-B7CB-EB5B5A065517,CRxDbView3D)
class CRXDB_API CRxDbView3D: public CRxDbEntity
{
public:
	CRxDbView3D(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbView3D)
};

#pragma pack(pop)

#endif