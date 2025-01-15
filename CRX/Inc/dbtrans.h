#ifndef   _CRXDBTRANS_H__
#define   _CRXDBTRANS_H__

//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//
//  DESCRIPTION: Header for Transaction Modeler.

#include "dbapserv.h"

#pragma pack (push, 8)

class CRxTransaction;
class CRxTransactionReactor;

class CRXDB_API CRxDbTransactionManager: public CRxObject
{ 
public:
//  CRX_DECLARE_DYNAMIC(CRxDbTransactionManager);

    virtual CRxTransaction*      startTransaction() = 0;
    virtual CDraft::ErrorStatus   endTransaction  () = 0;
    virtual CDraft::ErrorStatus   abortTransaction() = 0;

    virtual int                 numActiveTransactions() = 0;
    virtual CRxTransaction*      topTransaction() = 0;
    virtual CDraft::ErrorStatus   addNewlyCreatedDBRObject(CRxDbObject* obj,
                                     bool add = true) = 0;

    virtual CDraft::ErrorStatus   getAllObjects(CRxDbVoidPtrArray& objs) = 0;

    virtual void                addReactor(CRxTransactionReactor* reactor) = 0;
    virtual void                removeReactor(CRxTransactionReactor* reactor) =0;

    virtual CDraft::ErrorStatus   getObject(CRxDbObject*& obj, CRxDbObjectId id,
                                          CRxDb::OpenMode mode, 
                                          bool openErasedObj = false) = 0; 

    virtual CDraft::ErrorStatus   markObjectPageable(CRxDbObject* pObject) = 0;
    virtual CDraft::ErrorStatus   queueForGraphicsFlush() = 0;

};

//CRX_DEFINE_CLSID(BB3E3C1C-7851-46B5-AAC4-7D5E6C4DD644,AcTransaction)
class CRXDB_API CRxTransaction: public CRxObject
{ 
public:
    //CRX_DECLARE_DYNCREATE(AcTransaction);
	
    virtual 
    CDraft::ErrorStatus getObject(CRxDbObject*& obj, 
                                CRxDbObjectId   objectId, CRxDb::OpenMode mode,
                                bool openErasedObject = false) = 0;

    virtual 
    CDraft::ErrorStatus markObjectPageable(CRxDbObject* pObject) = 0;

    virtual CDraft::ErrorStatus   getAllObjects(CRxDbVoidPtrArray& objs) = 0;
};

//class CRXDB_API CRxTransactionReactor: public CrxRxObject
////
//// Reactor for transaction management.
////
//{
//public:
//    CRX_DECLARE_DYNAMIC(CRxTransactionReactor);
//
//    virtual void transactionAboutToStart (int& numTransactions,
//        CRxDbTransactionManager* transactionManagerPtr);
//    virtual void transactionStarted      (int& numTransactions,
//        CRxDbTransactionManager* transactionManagerPtr);
//    virtual void transactionAboutToEnd   (int& numTransactions,
//        CRxDbTransactionManager* transactionManagerPtr);
//    virtual void transactionEnded        (int& numTransactions,
//        CRxDbTransactionManager* transactionManagerPtr);
//    virtual void transactionAboutToAbort (int& numTransactions,
//        CRxDbTransactionManager* transactionManagerPtr);
//    virtual void transactionAborted      (int& numTransactions,
//        CRxDbTransactionManager* transactionManagerPtr);
//    virtual void endCalledOnOutermostTransaction (int& numTransactions,
//        CRxDbTransactionManager* transactionManagerPtr);
//    virtual void objectIdSwapped (const CrxDbObject* pTransResObj,
//        const CrxDbObject* pOtherObj,
//        CRxDbTransactionManager* transactionManagerPtr);
//};

inline CRxDbTransactionManager* crxdbTransactionManagerPtr()
{
    return crxdbHostApplicationServices()->workingTransactionManager();
}

#define crxdbTransactionManager  crxdbTransactionManagerPtr()

#pragma pack (pop)

#endif   _CRXDBTRANS_H__
