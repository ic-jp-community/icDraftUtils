//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//
#ifndef CRXDBDOUBLECLICKEDIT_H
#define CRXDBDOUBLECLICKEDIT_H

#include "StdAfx.h"
#include "dbmain.h"
#include "rxObject.h"
#include "CrxEdApiCx.h"

class CRxGePoint3d;
class CRxDbEntity;


CRX_DEFINE_NULL_CLSID(CrxDbDoubleClickEdit)
class CRXEDAPI_CLASS CAXA_NO_VTABLE  CrxDbDoubleClickEdit : public CRxObject
	//
	//  CrxDbDoubleClickEdit Protocol extension abstract base class. 
	//
{
public:
	CRX_DECLARE_DYNAMIC(CrxDbDoubleClickEdit);
	CrxDbDoubleClickEdit(void){};
	~CrxDbDoubleClickEdit(void){};
	virtual void startEdit(CRxDbEntity *pEnt, CRxGePoint3d pt) = 0; 
	virtual void finishEdit(void) = 0;
};
 

#endif //CRXDBDOUBLECLICKEDIT_H
