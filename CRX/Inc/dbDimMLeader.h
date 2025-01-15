#ifndef __CRXDBDIMMLEADER_H_
#define __CRXDBDIMMLEADER_H_

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
// CrxDbDimCoord : ������
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(B4E9F8BB-78B7-4B64-B2D3-D26F0C373CEB,CRxDbDimMLeader)
class CRXDB_API CRxDbDimMLeader: public CRxDbEntity
{
public:
	CRxDbDimMLeader(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbDimMLeader)
};

#pragma pack(pop)

#endif