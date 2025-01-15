#ifndef __CRXDBDIMDATUM_H_
#define __CRXDBDIMDATUM_H_

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
// CrxDbDimDatum : 基准代号
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(EBE7FAA2-A9DB-4C6D-A156-5BA4ED6DF79A,CRxDbDimDatum)
class CRXDB_API CRxDbDimDatum: public CRxDbEntity
{
public:
	CRxDbDimDatum(ICxCrxObject *i_pCrxObject = NULL);
	CRxDbDimDatum(
				const CRxGePoint3d& locPoint,
				int               Mode,
				double            roteAngle,
				const CxCHAR *      name = NULL,
				CRxDbObjectId       dimStyle = CRxDbObjectId::kNull
				);
	CRxDbDimDatum(
				const CRxGePoint3d& leaderStartPoint,
				const CRxGePoint3d& leaderEndPoint,
				double            roteAngle,
				const CxCHAR *      name = NULL ,
				CRxDbObjectId       dimStyle = CRxDbObjectId::kNull
				);
	CRX_DECLARE_DYNCREATE(CRxDbDimDatum)

	int  datumAim() const;
	CDraft::ErrorStatus   setDatumAim(int value);

	int  datumMode() const;
	CDraft::ErrorStatus   setDatumMode(int value);

	bool leaderLine() const;
	CDraft::ErrorStatus   setLeaderLine(bool value);

	CRxGePoint3dArray leaderPoints() const;
	CDraft::ErrorStatus   setLeaderPoints(const CRxGePoint3dArray& pts);

	CxCHAR *  datumName() const;
	CDraft::ErrorStatus   setDatumName(const CxCHAR * value );

	CRxGePoint3d  locPoint() const;
	CDraft::ErrorStatus   setLocPoint(const CRxGePoint3d& pt);

	CxCHAR *  upCaption() const;
	CDraft::ErrorStatus   setUpCaption(const CxCHAR * value );

	CxCHAR * downCaption() const;
	CDraft::ErrorStatus   setDownCaption(const CxCHAR * value);

	CRxDbObjectId  style() const;
	CDraft::ErrorStatus   setStyle(const CRxDbObjectId& id );

	double   symbolAngle() const;
	CDraft::ErrorStatus   setSymbolAngle(double value);

	CRxGePoint3d   basePoint() const;
	CDraft::ErrorStatus   setBasePoint(const CRxGePoint3d& pt);

	CRxGePoint3d   startPoint() const;
	CDraft::ErrorStatus   setStartPoint(const CRxGePoint3d& pt);

	BYTE hideFlag() const;
	CDraft::ErrorStatus   setHideFlag(BYTE value);

	short leaderStartMode() const;
	CDraft::ErrorStatus   setLeaderStartMode(short value);

	CDraft::ErrorStatus   setPaperScale(double i_dPaperScale);

	//符号形式
	short symbolFrmStyle() const;
	CDraft::ErrorStatus   setSymbolFrmStyle(short value);

	//符号起点形式
	short symbolStaStyle() const;
	CDraft::ErrorStatus   setSymbolStaStyle(short value);
};

#pragma pack(pop)

#endif