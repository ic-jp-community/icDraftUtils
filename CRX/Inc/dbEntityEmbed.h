#ifndef __CRXDBENTITYEMBED_H_
#define __CRXDBENTITYEMBED_H_

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
// CRxDbEntityEmbed : ֧��COM���ο�����Ƕ�����
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(F099C9D0-5E3E-4bf7-B0D3-80A64DD5BE07,CRxDbEntityEmbed)
class CRXDB_API CRxDbEntityEmbed: public CRxDbEntity
{
public:
	CRxDbEntityEmbed(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbEntityEmbed)
};


#pragma pack(pop)

#endif