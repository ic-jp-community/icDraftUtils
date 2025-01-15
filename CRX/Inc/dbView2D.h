#ifndef __CRXDBVIEW2D_H_
#define __CRXDBVIEW2D_H_

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
// CrxDbView2D : ��ά�ֲ��Ŵ�ͼ
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(BDF700DA-E09C-4ade-A1E4-0EADF201FF16,CRxDbView2D)
class CRXDB_API CRxDbView2D: public CRxDbEntity
{
public:
	CRxDbView2D(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbView2D)
};

#pragma pack(pop)

#endif