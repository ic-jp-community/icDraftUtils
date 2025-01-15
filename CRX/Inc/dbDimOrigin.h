#ifndef __CRXDBDIMORIGIN_H_
#define __CRXDBDIMORIGIN_H_

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
// CrxDbDimOrigin : 原点标注
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(0BDF94E2-0699-4CE6-94F8-DEE137AE16B4,CRxDbDimOrigin)
class CRXDB_API CRxDbDimOrigin: public CRxDbDimension
{
public:
	CRxDbDimOrigin(ICxCrxObject *i_pCrxObject = NULL);
	CRxDbDimOrigin::CRxDbDimOrigin(
		const CRxGePoint3d& definingPoint,
		const CRxGePoint3d& locPoint,
		const CRxGePoint3d& ucsOriginPoint,
		int					horOrVer,
		long                bidirectionalText,//文字单向/双向
		long                bidirectionalDimLn,//尺寸线单向/双向
		double              xAxisOff,
		double              yAxisOff,
		const CxCHAR *      dimText = NULL ,
		CRxDbObjectId       dimStyle =  CRxDbObjectId::kNull );
	CRX_DECLARE_DYNCREATE(CRxDbDimOrigin)


	CRxGePoint3d  startPoint() const;  
	CDraft::ErrorStatus   setStartPoint(const CRxGePoint3d& pt);

	CRxGePoint3d  ucsOrign() const;  
	CDraft::ErrorStatus   setUcsOrign(const CRxGePoint3d& pt);

	CRxGePoint3d  locPoint() const;  
	CDraft::ErrorStatus   setLocPoint(const CRxGePoint3d& pt);

	double ucsAngle() const;  
	CDraft::ErrorStatus   setUcsAngle(double value);

	long direction() const;  
	CDraft::ErrorStatus   setDirection(long value);

	long signFlag() const;  
	CDraft::ErrorStatus   setSignFlag(long value);

	long  orignArrow() const;  
	CDraft::ErrorStatus   setOrignArrow(long value);

	bool  drawOrignPoint() const;  
	CDraft::ErrorStatus   setDrawOrignPoint(bool value);

	bool bidirectionalText() const;
	CDraft::ErrorStatus   setBidirectionalText(bool value);

};

#pragma pack(pop)

#endif