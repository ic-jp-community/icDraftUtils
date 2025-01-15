#ifndef CRXDB_XRECORD_H
#define CRXDB_XRECORD_H
//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//

// DESCRIPTION: CRxDbXrecord class definition.

#include "crxChar.h"
#include "dbmain.h"

#define CRXDB_XRECORD_CLASS          CRX_T(/*MSG0*/"CRxDbXrecord")
#define CRXDB_XRECORD_ITERATOR_CLASS CRX_T(/*MSG0*/"CRxDbXrecordClass")

#pragma pack(push, 8)

CRX_DEFINE_CLSID(D772ED20-4B99-4374-8F45-A7663D8D1CD9,CRxDbXrecord)
class CRXDB_CLASS CRxDbXrecord: public CRxDbObject
{
public:
    CRX_DECLARE_DYNCREATE(CRxDbXrecord);

    CRxDbXrecord(ICxCrxObject *i_pCrxObject = NULL);
    virtual ~CRxDbXrecord();

    // auxDb parameter only useded when working with
    // non-Database-resident instances.

    CDraft::ErrorStatus rbChain(resbuf** ppRb, CRxDbDatabase* auxDb = NULL) const;
    CDraft::ErrorStatus setFromRbChain(const resbuf& pRb, CRxDbDatabase* auxDb = NULL);

    bool              isXlateReferences() const;
    void              setXlateReferences(bool translate);

    // Overridden methods from CrxDbObject
    //
    virtual CDraft::ErrorStatus subClose();
    //virtual CDraft::ErrorStatus dwgInFields(CRxDbDwgFiler* filer);
    //virtual CDraft::ErrorStatus dwgOutFields(CRxDbDwgFiler* filer) const;
    //virtual CDraft::ErrorStatus dxfInFields(CRxDbDxfFiler* filer);
    //virtual CDraft::ErrorStatus dxfOutFields(CRxDbDxfFiler* filer) const;

    //virtual CRxDb::DuplicateRecordCloning mergeStyle() const;
    //virtual void  setMergeStyle(CRxDb::DuplicateRecordCloning style);
};

//class CRxDbImpXrecordIterator;
//
//class CRxDbXrecordIterator: public CrxRxObject
//{
//public:
//    ACRX_DECLARE_MEMBERS(CRxDbXrecordIterator);
// 
//    CRxDbXrecordIterator(const CrxDbXrecord* pXrecord);
//    virtual ~CRxDbXrecordIterator();
//
//    void              start();
//    bool              done() const;
//    CDraft::ErrorStatus next();
//    int               curRestype() const;
//    CDraft::ErrorStatus getCurResbuf(resbuf& outItem, CrxDbDatabase* db) const;
//
//protected:
//    CRxDbXrecordIterator() {};
//private:
//    friend class CrxDbXrecord;
//    friend class CRxDbImpXrecord;
//    CRxDbImpXrecordIterator* mpImpIter;
//};

#pragma pack(pop)

#endif
