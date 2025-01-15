#ifndef __CRXDBDIMCENTERHOLE_H_
#define __CRXDBDIMCENTERHOLE_H_

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
// CrxDbDimCenterHole : 中心孔标注
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(B9B73A2B-6285-40D2-AD98-E1618318805D,CRxDbDimCenterHole)
class CRXDB_API CRxDbDimCenterHole: public CRxDbDimension
{
public:
	CRxDbDimCenterHole(ICxCrxObject *i_pCrxObject = NULL);
	CRxDbDimCenterHole::CRxDbDimCenterHole( int manner,
											bool drawArrow,
											double angle,
											const CRxGePoint3d& locPt,
											const CxCHAR *      dimText = NULL ,
											CRxDbObjectId       dimStyle = CRxDbObjectId::kNull);
	CRX_DECLARE_DYNCREATE(CRxDbDimCenterHole)

	int  manner() const;
	CDraft::ErrorStatus   setManner(int value);

	bool  drawArrow() const;
	CDraft::ErrorStatus   setDrawArrow(bool value);

	double  angle() const;
	CDraft::ErrorStatus   setAngle(double value);

	CRxGePoint3d   startPoint() const;
	CDraft::ErrorStatus   setStartPoint(const CRxGePoint3d& pt);

	CDraft::ErrorStatus   setText(const CxCHAR *  value);
	CxCHAR * text() const;

	CDraft::ErrorStatus   setPaperScale(double i_dPaperScale);

};

#pragma pack(pop)

#endif