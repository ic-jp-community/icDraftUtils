#ifndef __CRXDBDIMWELD_H_
#define __CRXDBDIMWELD_H_

//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//

#include "dbmain.h"
#pragma pack(push, 8)

typedef struct _TAG_CRXWELDITEM
{
	// �ϻ�������
	int m_iUpBasicSymbol;
	// �»�������
	int m_iDownBasicSymbol;
	// �ϸ�������
	int m_iUpAuxiliarySymbol;
	// �¸�������
	int m_iDownAuxiliarySymbol;
	// �������
	int m_iSupplementSymbol;
	// �������
	int m_iSpecialSymbol;
	// ����λ��
	short m_iDotLine;
	// ���ҳߴ�1
	CxCHAR* m_sUpRightText1;
	// ����ߴ�
	CxCHAR* m_sUpLeftText;
	// ����ߴ�
	CxCHAR* m_sDownLeftText;
	// ���ҳߴ�2
	CxCHAR* m_sUpRightText2;
	// ���ҳߴ�1
	CxCHAR* m_sDownRightText1;
	// ���ҳߴ�2
	CxCHAR* m_sDownRightText2;
	// ���гߴ�
	CxCHAR* m_sUpMiddleText;
	// ���гߴ�
	CxCHAR* m_sDownMiddleText;
	// ����˵��
	CxCHAR* m_sCaption;
	// �Ͻ�������
	CxCHAR* m_sUpSpace;
	// �½�������
	CxCHAR* m_sDownSpace;
	// �Ϸ���������
	CxCHAR* m_sUpTextInSymbol;
	// �·���������
	CxCHAR* m_sDownTextInSymbol;
	// ����˵���߿�
	BOOL m_bCaptionFrm;
	// ���ɷ��ŵ�λ��:��/��
	int m_iLocation ;
	_TAG_CRXWELDITEM()
	{
		
		m_iUpBasicSymbol = 15;

		m_iDownBasicSymbol = 15;

		m_iUpAuxiliarySymbol = 7;

		m_iDownAuxiliarySymbol = 7;

		m_iSupplementSymbol = 0;

		m_iSpecialSymbol = -1;

		m_iDotLine = 2;

		m_sUpRightText1 = _T("");

		m_sUpLeftText = _T("");

		m_sDownLeftText = _T("");

		m_sUpRightText2 = _T("");

		m_sDownRightText1 = _T("");

		m_sDownRightText2 = _T("");

		m_sUpMiddleText = _T("");

		m_sDownMiddleText = _T("");

		m_sCaption = _T("");

		m_sUpSpace = _T("");

		m_sDownSpace = _T("");

		m_sUpTextInSymbol = _T("");

		m_sDownTextInSymbol = _T("");

		m_bCaptionFrm = FALSE;

		m_iLocation = 0;
	}
} CRxWeldItem;
/*------------------------------------------------------------------------------
// CrxDbDimWeld : ���ӷ���
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(715D1A14-EE95-44E1-9C8C-354663460573,CRxDbDimWeld)
class CRXDB_API CRxDbDimWeld: public CRxDbEntity
{
public:
	CRxDbDimWeld(ICxCrxObject *i_pCrxObject = NULL);
	CRxDbDimWeld(	CRxWeldItem& weldItem,
					const CRxGePoint3d& startPoint,
					const CRxGePoint3dArray& leaderPoints,
					short				direction,
					CRxDbObjectId       dimStyle);
	CRX_DECLARE_DYNCREATE(CRxDbDimWeld)

	CRxGePoint3dArray leaderPoints() const;
	CDraft::ErrorStatus   setLeaderPoints(const CRxGePoint3dArray& pts);

	CRxGePoint3d   startPoint() const;
	CDraft::ErrorStatus   setStartPoint(const CRxGePoint3d& pt);

	CRxDbObjectId  style() const;
	CDraft::ErrorStatus   setStyle(const CRxDbObjectId&  id);
	
	short direction() const;
	CDraft::ErrorStatus   setDirection(short value);

	CDraft::ErrorStatus   setPaperScale(double i_dPaperScale);
};

#pragma pack(pop)

#endif