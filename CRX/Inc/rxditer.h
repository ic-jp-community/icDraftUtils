#ifndef _RXDITER_H
#define _RXDITER_H 1
//
//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//
//
#include "rxobject.h"
#include "rxiter.h"
#include "crxChar.h"
#pragma pack (push, 8)

CRX_DEFINE_NULL_CLSID(CRxDictionaryIterator)
class CRXDB_CLASS CRxDictionaryIterator: public CRxIterator
{
public:
    CRX_DECLARE_DYNAMIC(CRxDictionaryIterator);

    virtual const CxCHAR * key   () const = 0;
    virtual CRxObject*   object() const = 0;
    virtual CAXA::UInt32 id    () const = 0;
};

#pragma pack (pop)
#endif
