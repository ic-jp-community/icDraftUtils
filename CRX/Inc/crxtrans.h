#ifndef   _CRXTRANS_H
#define   _CRXTRANS_H
//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//  DESCRIPTION: Header for Transaction Modeler.

#include "rxnames.h"
#include "crxed.h"
#include "dbptrar.h"
#include "dbtrans.h"
#include "crxdocman.h"
#include "crxDefine.h"
#pragma pack (push, 8)


class CRXDB_API CRxTransactionManager: public CRxDbTransactionManager 
{ 
public:
//     ACRX_DECLARE_MEMBERS(CRxTransactionManager);

    virtual CDraft::ErrorStatus   enableGraphicsFlush(bool doEnable) = 0;
    virtual void                flushGraphics() = 0; 
};

CRXDB_API CRxTransactionManager* crxTransactionManagerPtr();
/* Inline实现改为内部实现
inline CRxTransactionManager* crxTransactionManagerPtr()
{
    AcApDocument* pDoc = crxDocManager->curDocument();
    return pDoc ? pDoc->transactionManager() : NULL;
}
*/

#define crxtrTransactionManager  crxTransactionManagerPtr()

#pragma pack (pop)
#endif
