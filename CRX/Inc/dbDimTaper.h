#ifndef __CRXDBDIMTAPER_H_
#define __CRXDBDIMTAPER_H_

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
// CrxDbDimTaper : 锥度标注
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(27D28DA4-5705-40F5-A8E2-395E3F12113A,CRxDbDimTaper)
class CRXDB_API CRxDbDimTaper: public CRxDbDimension
{
public:
	CRxDbDimTaper(ICxCrxObject *i_pCrxObject = NULL);
	CRxDbDimTaper(	const CRxGePoint3d& xLine1Start,
					const CRxGePoint3d& xLine1End,
					const CRxGePoint3d& xLine2Start,
					const CRxGePoint3d& xLine2End,
					const CRxGePoint3d& PointOnBaseLine,
					const CRxGePoint3d& leaderStartPoint,
					const CRxGePoint3d& LeaderEndPoint,
					const CxCHAR *      dimText = NULL ,
					CRxDbObjectId       dimStyle  = CRxDbObjectId::kNull);
	CRX_DECLARE_DYNCREATE(CRxDbDimTaper)

	double txtAng() const;
	CDraft::ErrorStatus   setTxtAng(double value);

	long symbolDir() const;
	CDraft::ErrorStatus   setSymbolDir(long value);

	long quadrant() const;
	CDraft::ErrorStatus   setQuadrant(long value);

	CRxGePoint3d    startPoint() const;
	CDraft::ErrorStatus   setStartPoint(const CRxGePoint3d& pt);

	CRxGePoint3d   endPoint() const;
	CDraft::ErrorStatus   setEndPoint(const CRxGePoint3d&  pt);

	CRxGePoint3d  dimLinePoint() const;
	CDraft::ErrorStatus   setDimLinePoint(const CRxGePoint3d&  pt);

	CRxGePoint3d   baseLinePoint() const;
	CDraft::ErrorStatus   setBaseLinePoint(const CRxGePoint3d&  pt);

	bool leaderLine() const;
	CDraft::ErrorStatus   setLeaderLine(bool value);

	CDraft::ErrorStatus   setPaperScale(double i_dPaperScale);
};

#pragma pack(pop)

#endif