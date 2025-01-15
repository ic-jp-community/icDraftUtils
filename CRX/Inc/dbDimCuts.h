#ifndef __CRXDBDIMCUTS_H_
#define __CRXDBDIMCUTS_H_

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#include "dbmain.h"
#pragma pack(push, 8)

/*------------------------------------------------------------------------------
// CrxDbDimCuts : 剖切线
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(4B35DD46-6DDB-4B03-B233-51C18F214CF1,CRxDbDimCuts)
class CRXDB_API CRxDbDimCuts: public CRxDbEntity
{
public:
	CRxDbDimCuts(ICxCrxObject *i_pCrxObject = NULL);
	CRxDbDimCuts(
				const CRxGePoint3dArray& cutsPoints,
				const CRxGePoint3dArray& textPoints,
				const CxCHAR *      viewName = NULL,
				short               arrowDirection = 0,
				CRxDbObjectId       dimStyle = CRxDbObjectId::kNull);
	CRX_DECLARE_DYNCREATE(CRxDbDimCuts)

	CRxGePoint3dArray cutsPoints() const;
	CDraft::ErrorStatus   setCutsPoints(const CRxGePoint3dArray& pts);

	CDraft::ErrorStatus   addCutsPoint(const CRxGePoint3d& pt);
	CRxGePoint3d   cutsPoint(unsigned int index) const;

	CDraft::ErrorStatus   setCutsText(const CxCHAR * value ,const CRxGePoint3d& pt );
	CxCHAR * cutsText(size_t index) const;

	CDraft::ErrorStatus   setArrowDir(short value );
	short arrowDir() const;

	CRxGePoint3d   startArrowPoint() const;
	CDraft::ErrorStatus   setStartArrowPoint(const CRxGePoint3d& pt);

	CRxGePoint3d   endArrowPoint() const;
	CDraft::ErrorStatus   setEndArrowPoint(const CRxGePoint3d& pt);

	CRxDbObjectId  style() const;
	CDraft::ErrorStatus   setStyle(const CRxDbObjectId& id );

	long   type() const;
	CDraft::ErrorStatus   setType(long value);

	double   rotateAngle() const;
	CDraft::ErrorStatus   setRotateAngle(double value);

	CDraft::ErrorStatus   setPaperScale(double i_dPaperScale);
};

#pragma pack(pop)

#endif