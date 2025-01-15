#ifndef __CRXDBDIMROUGH_H_
#define __CRXDBDIMROUGH_H_

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
// CrxDbDimRough : 粗糙度
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(64E92135-BB0B-4C37-BEE3-E7DCDABF179E,CRxDbDimRough)
class CRXDB_API CRxDbDimRough: public CRxDbEntity
{
public:
	CRxDbDimRough(ICxCrxObject *i_pCrxObject = NULL);
	CRxDbDimRough::CRxDbDimRough(
								const CRxGePoint3d& locPoint,
								short      surfaceTreatment = 0,
								const CxCHAR *      value= NULL ,
								CRxDbObjectId       dimStyle =  CRxDbObjectId::kNull,
								const CxCHAR *      upCaption = NULL,
								const CxCHAR *      downCaption= NULL ,
								const CxCHAR *      upValue= NULL ,
								const CxCHAR *      downValue= NULL ,
								const CxCHAR *      excess= NULL ,
								short               vein = 7);
	CRxDbDimRough::CRxDbDimRough(
								const CRxGePoint3d& leaderStartPoint,
								const CRxGePoint3d& locPoint,
								short      surfaceTreatment = 0,
								const CxCHAR *      value= NULL ,
								CRxDbObjectId       dimStyle =  CRxDbObjectId::kNull,
								const CxCHAR *      upCaption = NULL,
								const CxCHAR *      downCaption= NULL ,
								const CxCHAR *      upValue= NULL ,
								const CxCHAR *      downValue= NULL ,
								const CxCHAR *      excess= NULL ,
								short               vein = 7);
	CRX_DECLARE_DYNCREATE(CRxDbDimRough)


	short symbol() const;
	CDraft::ErrorStatus   setSymbol(short value);

	bool sameReqirement() const;
	CDraft::ErrorStatus   setSameReqirement(bool value);

	short vein() const;
	CDraft::ErrorStatus   setVein(short value);

	CxCHAR *  upValue() const;
	CDraft::ErrorStatus   setUpValue(const CxCHAR * value );

	CxCHAR *  downValue() const;
	CDraft::ErrorStatus   setDownValue(const CxCHAR * value );

	CxCHAR *  upCaption() const;
	CDraft::ErrorStatus   setUpCaption(const CxCHAR * value );

	CxCHAR *  downCaption() const;
	CDraft::ErrorStatus   setDownCaption(const CxCHAR * value);

	CxCHAR *  excess() const;
	CDraft::ErrorStatus   setExcess(const CxCHAR * value );

	CxCHAR *  minRough() const;
	CDraft::ErrorStatus   setMinRough(const CxCHAR * value );

	CRxGePoint3dArray leaderPoints() const;
	CDraft::ErrorStatus   setLeaderPoints(const CRxGePoint3dArray& pts);

	CRxDbObjectId style() const;
	CDraft::ErrorStatus   setStyle(const CRxDbObjectId& );

	CRxGePoint3d   startPoint() const;
	CDraft::ErrorStatus   setStartPoint(const CRxGePoint3d& pt);

	double   angle() const;
	CDraft::ErrorStatus   setAngle(double value);

	CRxGePoint3d  locPoint() const;
	CDraft::ErrorStatus   setLocPoint(const CRxGePoint3d& pt);

	bool leaderLine() const;
	CDraft::ErrorStatus   setLeaderLine(bool value);

	byte hideFlag() const;
	CDraft::ErrorStatus   setHideFlag(byte value);

	short leaderStartMode() const;
	CDraft::ErrorStatus   setLeaderStartMode(short value);

	CDraft::ErrorStatus   setPaperScale(double i_dPaperScale);
};

#pragma pack(pop)

#endif