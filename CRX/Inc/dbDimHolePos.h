#ifndef __CRXDBDIMHOLEPOS_H_
#define __CRXDBDIMHOLEPOS_H_

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
// CrxDbDimHolePos : 孔位标注
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(01B15578-86A4-4FDA-BD14-FE50BC770905,CRxDbDimHolePos)
class CRXDB_API CRxDbDimHolePos: public CRxDbDimension
{
public:
	CRxDbDimHolePos(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbDimHolePos)
	CRxDbDimHolePos(	const CRxGePoint3d& originPoint,
						const CRxGePoint3d& startPoint,
						double				offset,
						short				direction,
						const CxCHAR *      dimText = NULL,
						CRxDbObjectId       dimStyle = CRxDbObjectId::kNull  );

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


};
#pragma pack(pop)

#endif