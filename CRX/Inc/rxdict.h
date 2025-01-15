#ifndef _rxdict_h
#define _rxdict_h 1
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
#include "crxChar.h"

#pragma pack (push, 8)

class CRxDictionaryIterator;

CRX_DEFINE_NULL_CLSID(CRxDictionary)
class CRXDB_CLASS CRxDictionary: public CRxObject
{
public:
    CRX_DECLARE_DYNAMIC(CRxDictionary);

    virtual CRxObject*    at      (const CxCHAR* key) const = 0;
    virtual CRxObject*    at      (CAXA::UInt32 id) const = 0;

    CRxObject*            atPut   (const CxCHAR* key, CRxObject* pObject);
    virtual CRxObject*    atPut   (const CxCHAR* key, CRxObject* pObject,
        CAXA::UInt32& retId) = 0;
    virtual CRxObject*    atPut   (CAXA::UInt32 id, CRxObject* pObject) = 0;

    virtual CAXA::Boolean resetKey(const CxCHAR* oldKey, const CxCHAR* newKey) = 0;
    virtual CAXA::Boolean resetKey(CAXA::UInt32 id, const CxCHAR* newKey) = 0;

    virtual CAXA::Boolean atKeyAndIdPut(const CxCHAR* newKey, CAXA::UInt32 id,
        CRxObject* pObject) = 0;

    virtual CRxObject*    remove  (const CxCHAR* key) = 0;
    virtual CRxObject*    remove  (CAXA::UInt32 id) = 0;

    virtual CAXA::Boolean has     (const CxCHAR* entryName) const = 0;
    virtual CAXA::Boolean has     (CAXA::UInt32 id) const = 0;

    virtual CAXA::UInt32  idAt    (const CxCHAR* key) const = 0;

    virtual const CxCHAR*    keyAt   (CAXA::UInt32 id) const = 0;

    virtual CAXA::UInt32  numEntries() const = 0;

    virtual CRxDictionaryIterator* newIterator(
        CxRx::DictIterType type = CxRx::kDictSorted) = 0;

    virtual CAXA::Boolean deletesObjects() const = 0;
    virtual CAXA::Boolean isCaseSensitive() const = 0;
    virtual CAXA::Boolean isSorted() const = 0;
};

CRXDB_API CRxDictionary* crxSysRegistry();

inline CRxObject* CRxDictionary::atPut(const CxCHAR* key, CRxObject* pObj)
{ CAXA::UInt32 temp; return atPut(key, pObj, temp); }

#define crxClassDictionary \
CRxDictionary::cast(crxSysRegistry()->at(CRX_CLASS_DICTIONARY))

#define crxServiceDictionary \
CRxDictionary::cast(crxSysRegistry()->at(CRX_SERVICE_DICTIONARY))

#pragma pack (pop)
#endif
