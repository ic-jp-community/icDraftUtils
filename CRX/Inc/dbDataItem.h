#ifndef __CRXDBDATAITEM_H_
#define __CRXDBDATAITEM_H_

//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//

#include "dbmain.h"
#pragma pack(push, 8)

/*------------------------------------------------------------------------------
// CrxDbDataItem : ��ϸ������ݱ��һ��������
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(38C95F9B-4CCF-44BB-AD94-FAD4B5944AE9,CRxDbDataItem)
class CRXDB_API CRxDbDataItem: public CRxDbObject
{
public:
	CRxDbDataItem(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbDataItem)

	//�����ݱ���ʱ��Ψһ����
	SIZE_T GetIndex() const;
	CDraft::ErrorStatus SetIndex(SIZE_T lVal);

	//�Ƿ�����ϸ������ʾ
	LONG GetHideItemFlag() const;
	CDraft::ErrorStatus SetHideItemFlag(LONG lVal);

	//�ǲ��Ǳ��ϲ���
	LONG GetMergeItemFlag() const;
	CDraft::ErrorStatus SetMergeItemFlag(LONG lVal);

	//���ݳ���
	SIZE_T GetSize() const;
	//�������ݳ���
	CDraft::ErrorStatus ResetSize(SIZE_T i_lSize);

	CxCHAR* GetAt(SIZE_T i_lPos) const;
	CDraft::ErrorStatus SetAt(SIZE_T i_lPos, const CxCHAR* i_cxVal);
};

#pragma pack(pop)

#endif