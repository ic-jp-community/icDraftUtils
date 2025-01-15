#ifndef __CRXDBDIMORIALIGN_H_
#define __CRXDBDIMORIALIGN_H_

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
// CrxDbDimOriAlign : 对齐标注
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(AAEA3E06-24AB-42B8-B915-18EB2F843F03,CRxDbDimOriAlign)
class CRXDB_API CRxDbDimOriAlign: public CRxDbDimension
{
public:
	CRxDbDimOriAlign(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbDimOriAlign)

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

	CRxGePoint3d  alignPoint() const;  
	CDraft::ErrorStatus   setAlignPoint(const CRxGePoint3d& pt);

	long  dimLineOn() const;  
	CDraft::ErrorStatus   setDimLineOn(long value);

	long  arrowOn() const;  
	CDraft::ErrorStatus   setArrowOn(long value);


};
#pragma pack(pop)

#endif