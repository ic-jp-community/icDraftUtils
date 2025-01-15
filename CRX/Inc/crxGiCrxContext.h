//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//

#include "crxgi.h"

#ifndef __CRxGiCrxContext_H_
#define __CRxGiCrxContext_H_

CRX_DEFINE_NULL_CLSID(CRxGiCrxContext)
class CRxGiCrxContext : public CRxGiContext
{
	CRX_DECLARE_DYNAMIC(CRxGiCrxContext)

	CAXA::Boolean          isPsOut() const;
	CAXA::Boolean          isPlotGeneration() const;
	CRxDbDatabase *          database() const;
	bool					isBoundaryClipping() const;

	int setTextStyle(int);
};

#endif