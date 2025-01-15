#ifndef __CRXDBBOMTABLE_H_
#define __CRXDBBOMTABLE_H_

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#include "dbmain.h"
#pragma pack(push, 8)

/*------------------------------------------------------------------------------
// CrxBomTable : 明细表
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(B995FCED-A25A-4940-8D79-D92A345F37CE,CRxDbBomTable)
class CRXDB_API CRxDbBomTable: public CRxDbEntity
{
public:
	CRxDbBomTable(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbBomTable)

	CRxDbObjectId         GetReltnBomStyle() const;
	CRxDbObjectId         GetReltnDataTable() const;
	CDraft::ErrorStatus   SetReltnDataTable(CRxDbObjectId);

	//明细表的定位方式
	int                   getRelLocType() const;
	CDraft::ErrorStatus   setRelLocType(int iType);

	//比例
	double                getScale() const;
	CDraft::ErrorStatus   setScale(double dScale);

	//折行方向：左折 1；右折 -1
	int                   getBreakDir() const;
	CDraft::ErrorStatus   setBreakDir(int iDir);

	//定位点
	CRxGePoint3d          getLocPoint() const;
	CDraft::ErrorStatus   setLocPoint(const CRxGePoint3d&);

	//折行点
	CRxGePoint3d          getBreakPoint() const;
	CDraft::ErrorStatus   setBreakPoint(const CRxGePoint3d&);

	//设置折行点（同方向增加，反方向修改或删除）
	CDraft::ErrorStatus   SetBreakLines(LONG i_lBrkPos, SHORT i_iBrkDir);

	//清除所有折行
	CDraft::ErrorStatus   EmptyBreakLines() const;

	//得到折行总数
	LONG                  GetBreakLineSize() const;

	// 获取BomItem数量
	LONG                  GetBomItemCount() const;

	// 获取Bom隐藏状态
	CDraft::ErrorStatus	  GetHideBomTableFlag(LONG* plVal) const;

	// 设置Bom隐藏状态
	CDraft::ErrorStatus   SetHideBomTableFlag(const LONG lVal);
};
#pragma pack(pop)

#endif