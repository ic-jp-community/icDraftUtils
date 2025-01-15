#ifndef __CRXDBDIMWELD_H_
#define __CRXDBDIMWELD_H_

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#include "dbmain.h"
#pragma pack(push, 8)

typedef struct _TAG_CRXWELDITEM
{
	// 上基本符号
	int m_iUpBasicSymbol;
	// 下基本符号
	int m_iDownBasicSymbol;
	// 上辅助符号
	int m_iUpAuxiliarySymbol;
	// 下辅助符号
	int m_iDownAuxiliarySymbol;
	// 补充符号
	int m_iSupplementSymbol;
	// 特殊符号
	int m_iSpecialSymbol;
	// 虚线位置
	short m_iDotLine;
	// 上右尺寸1
	CxCHAR* m_sUpRightText1;
	// 上左尺寸
	CxCHAR* m_sUpLeftText;
	// 下左尺寸
	CxCHAR* m_sDownLeftText;
	// 上右尺寸2
	CxCHAR* m_sUpRightText2;
	// 下右尺寸1
	CxCHAR* m_sDownRightText1;
	// 下右尺寸2
	CxCHAR* m_sDownRightText2;
	// 上中尺寸
	CxCHAR* m_sUpMiddleText;
	// 下中尺寸
	CxCHAR* m_sDownMiddleText;
	// 焊接说明
	CxCHAR* m_sCaption;
	// 上交错焊缝间距
	CxCHAR* m_sUpSpace;
	// 下交错焊缝间距
	CxCHAR* m_sDownSpace;
	// 上符号内文字
	CxCHAR* m_sUpTextInSymbol;
	// 下符号内文字
	CxCHAR* m_sDownTextInSymbol;
	// 焊接说明边框
	BOOL m_bCaptionFrm;
	// 生成符号的位置:上/下
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
// CrxDbDimWeld : 焊接符号
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