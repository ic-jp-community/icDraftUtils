#ifndef __CRXDBDATAITEM_H_
#define __CRXDBDATAITEM_H_

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
// CrxDbDataItem : 明细表的数据表的一行数据项
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(38C95F9B-4CCF-44BB-AD94-FAD4B5944AE9,CRxDbDataItem)
class CRXDB_API CRxDbDataItem: public CRxDbObject
{
public:
	CRxDbDataItem(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbDataItem)

	//在数据表中时的唯一索引
	SIZE_T GetIndex() const;
	CDraft::ErrorStatus SetIndex(SIZE_T lVal);

	//是否在明细表中显示
	LONG GetHideItemFlag() const;
	CDraft::ErrorStatus SetHideItemFlag(LONG lVal);

	//是不是被合并项
	LONG GetMergeItemFlag() const;
	CDraft::ErrorStatus SetMergeItemFlag(LONG lVal);

	//数据长度
	SIZE_T GetSize() const;
	//设置数据长度
	CDraft::ErrorStatus ResetSize(SIZE_T i_lSize);

	CxCHAR* GetAt(SIZE_T i_lPos) const;
	CDraft::ErrorStatus SetAt(SIZE_T i_lPos, const CxCHAR* i_cxVal);
};

#pragma pack(pop)

#endif