#ifndef __CRXDBDIMRAY_H_
#define __CRXDBDIMRAY_H_

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
// CrxDbDimRay : ���߱�ע
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(6C3F45A2-C70A-44F6-949C-9EFFEA7C0333,CRxDbDimRay)
class CRXDB_API CRxDbDimRay: public CRxDbDimension
{
public:
	CRX_DECLARE_DYNCREATE(CRxDbDimRay)

	CRxDbDimRay::~CRxDbDimRay();

	CRxDbDimRay(ICxCrxObject *i_pCrxObject = NULL);
	CRxDbDimRay(
		const CRxGePoint3d& leftPoint,
		const CRxGePoint3d& rightPoint,
		const CxCHAR *      dimText = NULL ,
		CRxDbObjectId       dimStyle =  CRxDbObjectId::kNull );


	CRxGePoint3d locPoint() const;  
	CDraft::ErrorStatus   setLocPoint(const CRxGePoint3d& pt);

	CRxGePoint3d         xLine1Start() const;
	CDraft::ErrorStatus   setXLine1Start(const CRxGePoint3d& pt);

	CRxGePoint3d         xLine1End() const;
	CDraft::ErrorStatus   setXLine1End(const CRxGePoint3d& pt);

	long        dragTxtLoc() const;
	CDraft::ErrorStatus   setDragTxtLoc(long);

	CDraft::ErrorStatus   setPaperScale(double i_dPaperScale);
	
};

#pragma pack(pop)

#endif