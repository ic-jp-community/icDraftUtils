//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
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

//���õ�ǰPaper�Ŀ��ߺͱ���
CRXDB_API CDraft::ErrorStatus SetCurPaperSizeAndScale(CRxDbDatabase* pCrxDb, double dPaperWidth, double dPaperHeight, double dPaperScale);

#endif // __CRXDBBOMGLOBALS_H_
