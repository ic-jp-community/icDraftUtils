#ifndef __CRXDBDIMHALF_H_
#define __CRXDBDIMHALF_H_

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
// CrxDbDimHalf : ���ע
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(76D19095-DB03-4734-8A2E-178E1E7EC320,CRxDbDimHalf)
class CRXDB_API CRxDbDimHalf: public CRxDbDimension
{
public:
	CRxDbDimHalf(ICxCrxObject *i_pCrxObject = NULL);
	CRxDbDimHalf::CRxDbDimHalf(
		const CRxGePoint3d& leftPoint,
		const CRxGePoint3d& rightPoint,
		const CRxGePoint3d& LocPoint,
		const CxCHAR *      dimText = NULL,
		CRxDbObjectId       dimStyle  = CRxDbObjectId::kNull );
	CRX_DECLARE_DYNCREATE(CRxDbDimHalf)

	CDraft::ErrorStatus   setRightPoint(const CRxGePoint3d& pt);
	double extLenght() const;
	CDraft::ErrorStatus   setExtLenght(double extLenght);

	CDraft::ErrorStatus   setPaperScale(double i_dPaperScale);
};

#pragma pack(pop)

#endif