#ifndef __CRXDBDATATABLE_H_
#define __CRXDBDATATABLE_H_

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#include "dbmain.h"
#pragma pack(push, 8)

#include "dbDataItem.h"
#include "dbsymtb.h"

/*------------------------------------------------------------------------------
// CrxDbDataTable : 明细表的数据表
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(38C95F9B-4CCF-44BB-AD94-FAD4B5944AE9,CRxDbDataTable)
class CRXDB_API CRxDbDataTable: public CRxDbObject
{
public:
	CRxDbDataTable(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbDataTable)

	CRxDbObjectId       GetReltnBomStyle() const;
	CDraft::ErrorStatus SetReltnBomStyle(CRxDbObjectId);

	//添加数据项
	CDraft::ErrorStatus AddItem(CRxDbDataItem* pDI);
	//插入数据项
	CDraft::ErrorStatus InsertItem(SIZE_T i_lPos, CRxDbDataItem* pDI);
	//删除指定数据项
	CDraft::ErrorStatus RemoveItem(CRxDbDataItem* pDI, VARIANT_BOOL i_bDecGreaterPartno, VARIANT_BOOL i_bHideObj, LONG_PTR* o_ppLstDelIndex);
	//根据索引值删除指定数据项
	CDraft::ErrorStatus RemoveItemByIndex(SIZE_T i_lIndex, VARIANT_BOOL i_bDecGreaterPartno, VARIANT_BOOL i_bHideObj, LONG_PTR* o_ppLstDelIndex);
	//删除全部数据项。同时也要清空合并记录，以及导入3D零件记录
	CDraft::ErrorStatus RemoveAllItems();

	//添加数据项
	CDraft::ErrorStatus InsertItemToDefaultPos(CRxDbDataItem* pDI, BSTR i_bsPrefix, LONG i_lPartnoVal, VARIANT_BOOL i_bIncGreaterPartno);

	//得到数据项总数
	SIZE_T GetItemCount() const;

	//根据位置得到指定数据项
	CDraft::ErrorStatus GetItemAt(SIZE_T i_lPos, CRxDbDataItem*& pCrxDI) const;
	//根据索引值得到指定数据项
	CDraft::ErrorStatus GetItemByIndex(SIZE_T i_lIndex, CRxDbDataItem*& pCrxDI) const;

	//显示，得到可以显示的数据项总数
	SIZE_T GetVisualItemCount() const;
	//显示，根据位置得到指定的可以显示的数据项
	CDraft::ErrorStatus GetVisualItemAt(SIZE_T i_lPos, CRxDbDataItem*& pCrxDI) const;

	//填写，得到可以填写的数据项总数
	SIZE_T GetFillinItemCount() const;
	//填写，根据位置得到指定的可以填写的数据项
	CDraft::ErrorStatus GetFillinItemAt(SIZE_T i_lPos, CRxDbDataItem*& pCrxDI) const;

	//下一个相同前缀的序号值，(需要给出风格中指定的序号列lPnColumn)
	CDraft::ErrorStatus GetNextPartNoValue(CxCHAR* i_cxPrefix, LONG i_lPnColumn, LONG& o_lVal) const;

	//得到给定前缀零件序号的最大最小值
	CDraft::ErrorStatus GetPartMinMaxValue(CxCHAR* i_cxPrefix, LONG i_lPnColumn, LONG& o_lMin, LONG& o_lMax) const;

	//添加数据项
	CDraft::ErrorStatus AddItem_RealTime(CRxDbDataItem* pDI);
	//删除全部数据项。同时也要清空合并记录，以及导入3D零件记录
	CDraft::ErrorStatus RemoveAllItems_RealTime();

};

#pragma pack(pop)

#endif