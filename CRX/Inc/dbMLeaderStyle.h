#ifndef __CRXDBMLEADERSTYLE_H_
#define __CRXDBMLEADERSTYLE_H_

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
// CRxDbMLeaderStyle : �����߷��
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(17988C80-33F5-44B2-B4F3-AF07D3C74C08,CRxDbMLeaderStyle)
class CRXDB_API CRxDbMLeaderStyle: public CRxDbObject
{
public:
	CRxDbMLeaderStyle(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbMLeaderStyle)
};

#pragma pack(pop)

#endif