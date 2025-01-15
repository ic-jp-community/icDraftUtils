#ifndef __CRXDBBOMHEAD_H_
#define __CRXDBBOMHEAD_H_

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
// CRxDbBomHead : ��ϸ��ͷ
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(72F972F6-CD18-4D91-B00E-933D81947807,CRxDbBomHead)
class CRXDB_API CRxDbBomHead: public CRxDbEntity
{
public:
	CRxDbBomHead(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbBomHead)
};
#pragma pack(pop)

#endif