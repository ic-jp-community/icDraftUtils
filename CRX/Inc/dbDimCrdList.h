#ifndef __CRXDBDIMCRDLIST_H_
#define __CRXDBDIMCRDLIST_H_

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#include "dbmain.h"
#include "dbdim.h"
#pragma pack(push, 8)


/*------------------------------------------------------------------------------
// CrxDbDimCrdList : 自动列表
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