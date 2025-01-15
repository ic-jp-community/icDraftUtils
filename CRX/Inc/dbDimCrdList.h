#ifndef __CRXDBDIMCRDLIST_H_
#define __CRXDBDIMCRDLIST_H_

//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//

#include "dbmain.h"
#include "dbdim.h"
#pragma pack(push, 8)


/*------------------------------------------------------------------------------
// CrxDbDimCrdList : �Զ��б�
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(131E29F6-4EF8-4503-829C-451ACF7848C9,CRxDbDimCrdList)
class CRXDB_API CRxDbDimCrdList: public CRxDbDimension
{
public:
	CRxDbDimCrdList(ICxCrxObject *i_pCrxObject = NULL);
	CRxDbDimCrdList::CRxDbDimCrdList(	
									const CRxGePoint3d& startPoint,
									const CRxGePoint3d& endPoint,
									const CxCHAR *      dimText = NULL,
									CRxDbObjectId       dimStyle = CRxDbObjectId::kNull);
	CRX_DECLARE_DYNCREATE(CRxDbDimCrdList)

	CRxGePoint3d    startPoint() const;
	CDraft::ErrorStatus   setStartPoint(const CRxGePoint3d& pt);

	CRxGePoint3d   endPoint() const;
	CDraft::ErrorStatus   setEndPoint(const CRxGePoint3d& pt);

	bool leaderLine() const;
	CDraft::ErrorStatus   setLeaderLine(bool value);

};

#pragma pack(pop)

#endif