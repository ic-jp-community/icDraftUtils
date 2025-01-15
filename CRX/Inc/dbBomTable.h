#ifndef __CRXDBBOMTABLE_H_
#define __CRXDBBOMTABLE_H_

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
// CrxBomTable : ��ϸ��
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

	//��ϸ��Ķ�λ��ʽ
	int                   getRelLocType() const;
	CDraft::ErrorStatus   setRelLocType(int iType);

	//����
	double                getScale() const;
	CDraft::ErrorStatus   setScale(double dScale);

	//���з������� 1������ -1
	int                   getBreakDir() const;
	CDraft::ErrorStatus   setBreakDir(int iDir);

	//��λ��
	CRxGePoint3d          getLocPoint() const;
	CDraft::ErrorStatus   setLocPoint(const CRxGePoint3d&);

	//���е�
	CRxGePoint3d          getBreakPoint() const;
	CDraft::ErrorStatus   setBreakPoint(const CRxGePoint3d&);

	//�������е㣨ͬ�������ӣ��������޸Ļ�ɾ����
	CDraft::ErrorStatus   SetBreakLines(LONG i_lBrkPos, SHORT i_iBrkDir);

	//�����������
	CDraft::ErrorStatus   EmptyBreakLines() const;

	//�õ���������
	LONG                  GetBreakLineSize() const;

	// ��ȡBomItem����
	LONG                  GetBomItemCount() const;

	// ��ȡBom����״̬
	CDraft::ErrorStatus	  GetHideBomTableFlag(LONG* plVal) const;

	// ����Bom����״̬
	CDraft::ErrorStatus   SetHideBomTableFlag(const LONG lVal);
};
#pragma pack(pop)

#endif