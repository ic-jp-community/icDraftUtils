#ifndef __CRXDBDDIMCHAMFER_H_
#define __CRXDBDDIMCHAMFER_H_

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
// CrxDbDimChamfer : ���Ǳ�ע
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(86E4FACF-EC82-45C2-8C00-C6A37E4E1C77,CRxDbDimChamfer)
class CRXDB_API CRxDbDimChamfer: public CRxDbDimension
{
public:
	CRxDbDimChamfer(ICxCrxObject *i_pCrxObject = NULL);

	CRxDbDimChamfer::CRxDbDimChamfer(
									const CRxGePoint3d& leaderStartPoint,
									const CRxGePoint3d& leaderStat2EndPoint,
									const CRxGePoint3d& leaderEndPoint,
									const CRxGePoint3d& locPoint,
									short				chamfer45Mode,
									bool				LeadLn,
									const CxCHAR *      dimText = NULL,
									CRxDbObjectId       dimStyle  = CRxDbObjectId::kNull);
	CRX_DECLARE_DYNCREATE(CRxDbDimChamfer)

	CRxGePoint3d  locPoint() const;  
	CDraft::ErrorStatus   setLocPoint(const CRxGePoint3d& pt);

	CRxGePoint3d  startPoint() const; 
	CDraft::ErrorStatus   setStartPoint(const CRxGePoint3d& pt);

	double angle() const;
	CDraft::ErrorStatus   setAgnle(double value);

	short chamfer45Mode() const;
	CDraft::ErrorStatus   setChamfer45Mode(short value);

	CDraft::ErrorStatus   setPaperScale(double i_dPaperScale);

	CRxGePoint3d  endPoint() const; 
	CDraft::ErrorStatus   setEndPoint(const CRxGePoint3d& pt);
};

#pragma pack(pop)

#endif