#ifndef __CRXDBBOMItem_H_
#define __CRXDBBOMItem_H_

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
// CRxDbBomItem : ��ϸ����
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(1A6EFF84-514F-483D-8FF5-DF5B204E2BA8,CRxDbBomItem)
class CRXDB_API CRxDbBomItem: public CRxDbEntity
{
public:
	CRxDbBomItem(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbBomItem)
};
#pragma pack(pop)

#endif