//
//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//
//

#ifndef _rxiter_h
#define _rxiter_h 1

#include "rxobject.h"
#pragma pack (push, 8)

CRX_DEFINE_NULL_CLSID(CRxIterator)
class CRXDB_CLASS CRxIterator: public CRxObject
{
public:
    CRX_DECLARE_DYNAMIC(CRxIterator);

    virtual CAXA::Boolean done() const = 0;
    virtual CAXA::Boolean next() = 0;
    virtual CRxObject*    object() const = 0;
};

#pragma pack (pop)
#endif
