//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
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
