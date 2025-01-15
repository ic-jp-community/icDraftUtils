//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#ifndef __CRXDBBOMGLOBALS_H_
#define __CRXDBBOMGLOBALS_H_

#include "CrxCx.h"
#include "dbapserv.h"
#include "dbid.h"

CRXDB_API CRxDbObjectId GetCrxDbDataTable(CRxDbDatabase* pCrxDb = NULL);

CRXDB_API CRxDbObjectId GetCrxDbBomTable(CRxDbDatabase* pCrxDb = NULL);

CRXDB_API CRxDbObjectId GetCrxDbTitleBlk(CRxDbDatabase* pCrxDb = NULL);

CRXDB_API CRxDbObjectId GetCrxDbFrameBlk(CRxDbDatabase* pCrxDb = NULL);

//设置当前Paper的宽、高和比例
CRXDB_API CDraft::ErrorStatus SetCurPaperSizeAndScale(CRxDbDatabase* pCrxDb, double dPaperWidth, double dPaperHeight, double dPaperScale);

#endif // __CRXDBBOMGLOBALS_H_
