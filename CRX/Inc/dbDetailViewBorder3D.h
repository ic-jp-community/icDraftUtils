#ifndef __CRXDBDETAILVIEWBORDER3D_H_
#define __CRXDBDETAILVIEWBORDER3D_H_

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
// CRxDbDetailViewBorder3D : ��ά�ֲ��Ŵ���ͼ�߽�
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(37297F38-3266-4BFE-AD9B-2AB40369A322,CRxDbDetailViewBorder3D)
class CRXDB_API CRxDbDetailViewBorder3D: public CRxDbEntity
{
public:
	CRxDbDetailViewBorder3D(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbDetailViewBorder3D)
};

#pragma pack(pop)

#endif