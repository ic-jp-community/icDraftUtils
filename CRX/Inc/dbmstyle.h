//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//
//


#ifndef __CRXDBMLINESTYLE_H_
#define __CRXDBMLINESTYLE_H_

#include "dbmain.h"

#pragma pack(push, 8)

CRX_DEFINE_CLSID(28F12394-CFF0-42d7-BD3C-421B721579E5,CRxDbMlineStyle)
class CRXDB_CLASS CRxDbMlineStyle: public CRxDbObject
{
public:
	CRX_DECLARE_DYNCREATE(CRxDbMlineStyle);

	CRxDbMlineStyle(ICxCrxObject *i_pCrxObject = NULL);
};


#pragma pack(pop)

#endif

