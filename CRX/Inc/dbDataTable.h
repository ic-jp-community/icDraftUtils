#ifndef __CRXDBDATATABLE_H_
#define __CRXDBDATATABLE_H_

//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//

#include "dbmain.h"
#pragma pack(push, 8)

#include "dbDataItem.h"
#include "dbsymtb.h"

/*------------------------------------------------------------------------------
// CrxDbDataTable : ��ϸ������ݱ�
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(38C95F9B-4CCF-44BB-AD94-FAD4B5944AE9,CRxDbDataTable)
class CRXDB_API CRxDbDataTable: public CRxDbObject
{
public:
	CRxDbDataTable(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbDataTable)

	CRxDbObjectId       GetReltnBomStyle() const;
	CDraft::ErrorStatus SetReltnBomStyle(CRxDbObjectId);

	//���������
	CDraft::ErrorStatus AddItem(CRxDbDataItem* pDI);
	//����������
	CDraft::ErrorStatus InsertItem(SIZE_T i_lPos, CRxDbDataItem* pDI);
	//ɾ��ָ��������
	CDraft::ErrorStatus RemoveItem(CRxDbDataItem* pDI, VARIANT_BOOL i_bDecGreaterPartno, VARIANT_BOOL i_bHideObj, LONG_PTR* o_ppLstDelIndex);
	//��������ֵɾ��ָ��������
	CDraft::ErrorStatus RemoveItemByIndex(SIZE_T i_lIndex, VARIANT_BOOL i_bDecGreaterPartno, VARIANT_BOOL i_bHideObj, LONG_PTR* o_ppLstDelIndex);
	//ɾ��ȫ�������ͬʱҲҪ��պϲ���¼���Լ�����3D�����¼
	CDraft::ErrorStatus RemoveAllItems();

	//���������
	CDraft::ErrorStatus InsertItemToDefaultPos(CRxDbDataItem* pDI, BSTR i_bsPrefix, LONG i_lPartnoVal, VARIANT_BOOL i_bIncGreaterPartno);

	//�õ�����������
	SIZE_T GetItemCount() const;

	//����λ�õõ�ָ��������
	CDraft::ErrorStatus GetItemAt(SIZE_T i_lPos, CRxDbDataItem*& pCrxDI) const;
	//��������ֵ�õ�ָ��������
	CDraft::ErrorStatus GetItemByIndex(SIZE_T i_lIndex, CRxDbDataItem*& pCrxDI) const;

	//��ʾ���õ�������ʾ������������
	SIZE_T GetVisualItemCount() const;
	//��ʾ������λ�õõ�ָ���Ŀ�����ʾ��������
	CDraft::ErrorStatus GetVisualItemAt(SIZE_T i_lPos, CRxDbDataItem*& pCrxDI) const;

	//��д���õ�������д������������
	SIZE_T GetFillinItemCount() const;
	//��д������λ�õõ�ָ���Ŀ�����д��������
	CDraft::ErrorStatus GetFillinItemAt(SIZE_T i_lPos, CRxDbDataItem*& pCrxDI) const;

	//��һ����ͬǰ׺�����ֵ��(��Ҫ���������ָ���������lPnColumn)
	CDraft::ErrorStatus GetNextPartNoValue(CxCHAR* i_cxPrefix, LONG i_lPnColumn, LONG& o_lVal) const;

	//�õ�����ǰ׺�����ŵ������Сֵ
	CDraft::ErrorStatus GetPartMinMaxValue(CxCHAR* i_cxPrefix, LONG i_lPnColumn, LONG& o_lMin, LONG& o_lMax) const;

	//���������
	CDraft::ErrorStatus AddItem_RealTime(CRxDbDataItem* pDI);
	//ɾ��ȫ�������ͬʱҲҪ��պϲ���¼���Լ�����3D�����¼
	CDraft::ErrorStatus RemoveAllItems_RealTime();

};

#pragma pack(pop)

#endif