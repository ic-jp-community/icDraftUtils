#ifndef __CRXDBDIMLEADER_H_
#define __CRXDBDIMLEADER_H_

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
// CrxDbDimLeader : ����˵��
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(CC8682E6-A8CF-4A4F-AA36-C600B07AA69C,CRxDbDimLeader)
class CRXDB_API CRxDbDimLeader: public CRxDbDimension
{
public:
	CRxDbDimLeader(ICxCrxObject *i_pCrxObject = NULL);
	CRxDbDimLeader::CRxDbDimLeader(
									const CRxGePoint3d& leaderStartPoint,
									const CRxGePoint3dArray& leaderPoints,
									const CRxGePoint3d& locPoint,
									const CxCHAR *      upTxt = NULL,
									const CxCHAR *      downTxt = NULL,
									CRxDbObjectId       dimStyle = CRxDbObjectId::kNull);
	CRX_DECLARE_DYNCREATE(CRxDbDimLeader)


	CRxGePoint3d   startPoint() const;
	CDraft::ErrorStatus   setStartPoint(const CRxGePoint3d& pt);

	CRxGePoint3dArray leaderPoints() const;
	CDraft::ErrorStatus   setLeaderPoints(const CRxGePoint3dArray& pts);

	CRxDbObjectId  style() const;
	CDraft::ErrorStatus   setStyle(const CRxDbObjectId&  id);

	CxCHAR *  text() const;
	CDraft::ErrorStatus   setText(const CxCHAR * value );

	CDraft::ErrorStatus   setPaperScale(double i_dPaperScale);
};

#pragma pack(pop)

#endif