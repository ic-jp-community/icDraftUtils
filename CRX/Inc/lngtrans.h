//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//

//////////////////////////////////////////////////////////////////////////////
//
//  DESCRIPTION:  Header for Long Transaction Manager.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef   _LTRANSMAN_H
#define   _LTRANSMAN_H

#include "rxnames.h"
#include "dbidar.h"
#pragma pack (push, 8)

class CRxDbLongTransaction;
class CRxDbDatabase;
class CRxDbIdMapping;
class CRxApDocument;

#define CRX_LONG_TRANSACTION_MANAGER_OBJ _T("CRxApLongTransactionManager")

/*class CRxApLongTransactionReactor: public CRxObject 
{ 
public:
    ACRX_DECLARE_MEMBERS(CRxApLongTransactionReactor);

    // To identify and connect this notification with the deepClone
    // notifications, CRxDbLongTransactionWorkSet::activeIdMap()
    // will return the cloning idMap.  CheckOut and CheckIn, for
    // the same transaction, will use different maps.  
    //
    virtual void beginCheckOut        (CRxDbLongTransaction& ,
                                       CRxDbObjectIdArray& originList);
    virtual void endCheckOut          (CRxDbLongTransaction& );
    virtual void beginCheckIn         (CRxDbLongTransaction& );
    virtual void endCheckIn           (CRxDbLongTransaction& );
    virtual void abortLongTransaction (CRxDbLongTransaction& );

protected:
    CDraft::ErrorStatus veto ();  // beginCheckOut() can be vetoed

private:
    CAXA::UInt8 mVeto;

friend class AcApImpLongTransactionManager;
};*/

class CRxApLongTransactionManager: public CRxObject 
{ 
public:
    CRX_DECLARE_DYNAMIC(CRxApLongTransactionManager);

    virtual CDraft::ErrorStatus   checkOut(
                                   CRxDbObjectId& transId,
                                   CRxDbObjectIdArray& objList,
                                   CRxDbObjectId toBlock,
                                   CRxDbIdMapping& errorMap,
                                   CRxDbObjectId lockBlkRef = 
                                       CRxDbObjectId::kNull) = 0;

    virtual CDraft::ErrorStatus   checkIn  (
                                   CRxDbObjectId transId,
                                   CRxDbIdMapping& errorMap,
                                   bool keepObjs = false) = 0;

    virtual CDraft::ErrorStatus   abortLongTransaction(
                                   CRxDbObjectId transId,
                                   bool keepObjs = false) = 0;

    virtual CRxDbObjectId        currentLongTransactionFor(
                                   const CRxApDocument* pDoc) const = 0;

    virtual void                addReactor(CRxApLongTransactionReactor*) = 0;
    virtual void                removeReactor(CRxApLongTransactionReactor*) = 0;

    // For filtering classes out of Long Transactions
    //
    virtual CDraft::ErrorStatus   addClassFilter (CRxClass* ) = 0;
    virtual bool                isFiltered (CRxClass* ) const = 0;
};

extern CRxApLongTransactionManager* CRxApLongTransactionManagerPtr();
#define CRxApLongTransactionManager  CRxApLongTransactionManagerPtr()

#pragma pack (pop)
#endif  // !_LTRANSMAN_H
