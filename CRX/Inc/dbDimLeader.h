#ifndef __CRXDBDIMLEADER_H_
#define __CRXDBDIMLEADER_H_

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
// CrxDbDimLeader : 引出说明
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(CC8682E6-A8CF-4A4F-AA36-C600B07AA69C,CRxDbDimLeader)
class CRXDB_API CRxDbDimLeader: public CRxDbDimension
{
public:
	CRxDbDimLeader(ICxCrxObject *i_pCrxObject = NULL);
	CRxDbDimLeader::CRxDbDimLeader(
									const CRxGePoint3d& leaderStartPoint,
									const CRxGePoint3dArray& leaderPoints,
									const CRxGePoint3d& locPoint,
									const CxCHAR *      upTxt = NULL,
									const CxCHAR *      downTxt = NULL,
									CRxDbObjectId       dimStyle = CRxDbObjectId::kNull);
	CRX_DECLARE_DYNCREATE(CRxDbDimLeader)


	CRxGePoint3d   startPoint() const;
	CDraft::ErrorStatus   setStartPoint(const CRxGePoint3d& pt);

	CRxGePoint3dArray leaderPoints() const;
	CDraft::ErrorStatus   setLeaderPoints(const CRxGePoint3dArray& pts);

	CRxDbObjectId  style() const;
	CDraft::ErrorStatus   setStyle(const CRxDbObjectId&  id);

	CxCHAR *  text() const;
	CDraft::ErrorStatus   setText(const CxCHAR * value );

	CDraft::ErrorStatus   setPaperScale(double i_dPaperScale);
};

#pragma pack(pop)

#endif