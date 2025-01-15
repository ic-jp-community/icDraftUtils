#ifndef __CRXDBDIMCOORD_H_
#define __CRXDBDIMCOORD_H_

//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//

#include "dbmain.h"
#include "dbdim.h"
#pragma pack(push, 8)

/*------------------------------------------------------------------------------
// CrxDbDimCoord : ���ٱ�ע
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(5C8A71DF-BBDE-4A0C-9ACF-F581874E33C3,CRxDbDimCoord)
class CRXDB_API CRxDbDimCoord: public CRxDbDimension
{
public:
	CRxDbDimCoord(ICxCrxObject *i_pCrxObject = NULL);
	CRxDbDimCoord(const CRxGePoint3d& originPoint,
		const CRxGePoint3d& startPoint,
		const CRxGePoint3d& locPoint,
		LONG				direction,
		LONG				signFlag,
		LONG				drawArrow,
		const CxCHAR *      dimText = NULL,
		CRxDbObjectId       dimStyle = CRxDbObjectId::kNull);
	CRX_DECLARE_DYNCREATE(CRxDbDimCoord)

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