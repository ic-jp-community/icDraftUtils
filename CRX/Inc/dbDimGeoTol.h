#ifndef __CRXDBDIMGEOTOL_H_
#define __CRXDBDIMGEOTOL_H_

//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//

#include "dbmain.h"
#pragma pack(push, 8)
typedef struct _TAG_CRXGEOTOLITEM
{
	// �������
	long m_lSymbol;
	// ����1��ֵ
	CxCHAR* m_sToleVal1;
	// ����1ǰ׺
	CxCHAR* m_sTolePrefix1;
	// ����1��׺
	CxCHAR* m_sTolePostfix1;
	// ����2��ֵ
	CxCHAR* m_sToleVal2;
	// ����2ǰ׺
	CxCHAR* m_sTolePrefix2;
	// ����2��׺
	CxCHAR* m_sTolePostfix2;
	// ��׼1
	CxCHAR* m_sDatum1;
	// ��׼2
	CxCHAR* m_sDatum2;
	// ��׼3
	CxCHAR* m_sDatum3;
	_TAG_CRXGEOTOLITEM()
	{

		m_lSymbol = 14;

		m_sToleVal1 = _T("");

		m_sTolePrefix1 = _T("");

		m_sTolePostfix1 = _T("");

		m_sTolePostfix1 = _T("");

		m_sToleVal2 = _T("");

		m_sTolePrefix2 = _T("");

		m_sTolePostfix2 = _T("");

		m_sDatum1 = _T("");

		m_sDatum2 = _T("");

		m_sDatum3 = _T("");

	}
} CRxGeoTolItem;

/*------------------------------------------------------------------------------
// CrxDbDimGeoTol : ��λ����
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(9B79570D-4D57-4286-8105-AB9CE81C7F6C,CRxDbDimGeoTol)
class CRXDB_API CRxDbDimGeoTol: public CRxDbEntity
{
public:
	CRxDbDimGeoTol(ICxCrxObject *i_pCrxObject = NULL);
	CRxDbDimGeoTol(	const CRxGeoTolItem& geoTolItem,
		const CRxGePoint3d& startPoint,
		const CRxGePoint3dArray& leaderPoints,
		short				direction,
		CRxDbObjectId       dimStyle = CRxDbObjectId::kNull);

	CRX_DECLARE_DYNCREATE(CRxDbDimGeoTol)
	CDraft::ErrorStatus   addGeoTolItem( const CRxGeoTolItem& geoTolItem);

	CRxGePoint3dArray leaderPoints() const;
	CDraft::ErrorStatus   setLeaderPoints(const CRxGePoint3dArray& pts);

	CRxGePoint3d   startPoint() const;
	CDraft::ErrorStatus   setStartPoint(const CRxGePoint3d& pt);

	CRxDbObjectId  style() const;
	CDraft::ErrorStatus   setStyle(const CRxDbObjectId&  id);

	short direction() const;
	CDraft::ErrorStatus   setDirection(short value);

	CxCHAR *  topNote() const;
	CDraft::ErrorStatus   setTopNote(const CxCHAR * value );

	CxCHAR *  bottomNote() const;
	CDraft::ErrorStatus   setBottomNote(const CxCHAR * value );

	bool  allRoundSymbol() const;
	CDraft::ErrorStatus   setAllRoundSymbol(bool value);

	CDraft::ErrorStatus   setPaperScale(double i_dPaperScale);
};

#pragma pack(pop)

#endif