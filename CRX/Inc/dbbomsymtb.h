#ifndef __CRXDBBOMSYMTB_H_
#define __CRXDBBOMSYMTB_H_

//
//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//
//

#include "dbsymtb.h"

#pragma pack(push, 8)

#ifdef target
#undef target 
#endif


//
//

#include "dbmain.h"
//#include "dbdict.h"
//#include "dbdate.h"
//#include "dbbackground.h"
//#include "gevec2d.h"
//#include "crxgiviewport.h"
//#include "crxgivisualstyle.h"

#pragma pack(push, 8)

#ifdef target
#undef target 
#endif



class CRxDbPartnoStyleTableRecord;
class CRxDbPartnoStyleTableIterator;
//
CRX_DEFINE_CLSID(2EACF156-507A-45D7-8AD9-618B08D63DBC,CRxDbPartnoStyleTable)
class CRXDB_API CRxDbPartnoStyleTable: public CRxDbSymbolTable
{
public:
	CRX_DECLARE_DYNCREATE(CRxDbPartnoStyleTable);
	CRxDbPartnoStyleTable(ICxCrxObject *i_pCrxObject=NULL);
	//   virtual ~CrxDbPartnoStyleTable();
	//
	typedef CRxDbPartnoStyleTableRecord RecordType;
	//
	CDraft::ErrorStatus   getAt   (const CxCHAR* entryName,
		CRxDbPartnoStyleTableRecord*& pRec,
		CRxDb::OpenMode openMode,
		bool openErasedRec = false) const;
	CDraft::ErrorStatus   getAt   (const CxCHAR* entryName,
		CRxDbObjectId& recordId,
		bool getErasedRec = false) const;
	bool                has     (const CxCHAR* name) const;
	bool                has     (CRxDbObjectId id) const;
	CDraft::ErrorStatus   newIterator(CRxDbPartnoStyleTableIterator*& pIterator,
		bool atBeginning = true,
		bool skipDeleted = true) const;
	CDraft::ErrorStatus   add     (CRxDbPartnoStyleTableRecord* pRecord);
	CDraft::ErrorStatus   add     (CRxDbObjectId&  recordId,
		CRxDbPartnoStyleTableRecord* pRecord);

	virtual CRxObject* clone() const;
	//
	//    virtual CDraft::ErrorStatus getClassID(CLSID* pClsid) const;
};

class CRxDbBomStyleTableRecord;
class CRxDbBomStyleTableIterator;
//
CRX_DEFINE_CLSID(2EACF156-507A-45D7-8AD9-618B08D63DBC,CRxDbBomStyleTable)
class CRXDB_API CRxDbBomStyleTable: public CRxDbSymbolTable
{
public:
	CRX_DECLARE_DYNCREATE(CRxDbBomStyleTable);
	CRxDbBomStyleTable(ICxCrxObject *i_pCrxObject=NULL);
	//   virtual ~CrxDbBomStyleTable();
	//
	typedef CRxDbBomStyleTableRecord RecordType;
	//
	CDraft::ErrorStatus   getAt   (const CxCHAR* entryName,
		CRxDbBomStyleTableRecord*& pRec,
		CRxDb::OpenMode openMode,
		bool openErasedRec = false) const;
	CDraft::ErrorStatus   getAt   (const CxCHAR* entryName,
		CRxDbObjectId& recordId,
		bool getErasedRec = false) const;
	bool                has     (const CxCHAR* name) const;
	bool                has     (CRxDbObjectId id) const;
	CDraft::ErrorStatus   newIterator(CRxDbBomStyleTableIterator*& pIterator,
		bool atBeginning = true,
		bool skipDeleted = true) const;
	CDraft::ErrorStatus   add     (CRxDbBomStyleTableRecord* pRecord);
	CDraft::ErrorStatus   add     (CRxDbObjectId&  recordId,
		CRxDbBomStyleTableRecord* pRecord);

	virtual CRxObject* clone() const;
	//
	//    virtual CDraft::ErrorStatus getClassID(CLSID* pClsid) const;
	
};

class CRXDB_API CRxDbPartnoStyleTableIterator : public CRxDbSymbolTableIterator
{
public:
	CDraft::ErrorStatus getRecord(CRxDbPartnoStyleTableRecord*& pRecord,
		CRxDb::OpenMode openMode, bool openErasedRec = false) const;
	CDraft::ErrorStatus seek(CRxDbObjectId id);
	CDraft::ErrorStatus seek(const CRxDbPartnoStyleTableRecord* pRecord);

protected:
	CRxDbPartnoStyleTableIterator();
	friend class CRxDbPartnoStyleTable;
};

class CRXDB_API CRxDbBomStyleTableIterator : public CRxDbSymbolTableIterator
{
public:
	CDraft::ErrorStatus getRecord(CRxDbBomStyleTableRecord*& pRecord,
		CRxDb::OpenMode openMode, bool openErasedRec = false) const;
	CDraft::ErrorStatus seek(CRxDbObjectId id);
	CDraft::ErrorStatus seek(const CRxDbBomStyleTableRecord* pRecord);

protected:
	CRxDbBomStyleTableIterator();
	friend class CRxDbBomStyleTable;
};


CRX_DEFINE_CLSID(5393AF7B-632A-4246-91E1-54CBC07551A4,CRxDbPartnoStyleTableRecord)
class CRXDB_API CRxDbPartnoStyleTableRecord: public  CRxDbSymbolTableRecord
{
public:
    CRX_DECLARE_DYNCREATE(CRxDbPartnoStyleTableRecord);

    CRxDbPartnoStyleTableRecord(ICxCrxObject *i_pCrxObject = NULL);
//    virtual ~CrxDbPartnoStyleTableRecord();
//
    typedef CRxDbPartnoStyleTable TableType;
//
	virtual CDraft::ErrorStatus getName(CxCHAR*& pName) const;
	virtual CDraft::ErrorStatus setName(const CxCHAR* pName);
};

CRX_DEFINE_CLSID(A7B11825-B974-4383-86ED-7CEA3CDF557C,CRxDbBomStyleTableRecord)
class CRXDB_API CRxDbBomStyleTableRecord: public  CRxDbSymbolTableRecord
{
public:
    CRX_DECLARE_DYNCREATE(CRxDbBomStyleTableRecord);

    CRxDbBomStyleTableRecord(ICxCrxObject *i_pCrxObject = NULL);
//    virtual ~CrxDbBomStyleTableRecord();
//
    typedef CRxDbBomStyleTable TableType;
//
	virtual CDraft::ErrorStatus getName(CxCHAR*& pName) const;
	virtual CDraft::ErrorStatus setName(const CxCHAR* pName);

	//��ϸ��ÿ�и߶�
	double itemHeight() const;
	void   setItemHeight(double newVal);

	//��ϸ��������ɫ
	CDraft::ErrorStatus setVerLnColor(const CRxCmColor& v);
	CRxCmColor   verLnColor() const;

	//��ϸ��������ɫ
	CDraft::ErrorStatus setHorLnColor(const CRxCmColor& v);
	CRxCmColor   horLnColor() const;

	//��ϸ���������ɫ
	CDraft::ErrorStatus setBdOuterLnColor(const CRxCmColor& v);
	CRxCmColor   bdOuterLnColor() const;

	//��ͷ����ɫ
	CDraft::ErrorStatus setHeaderLnColor(const CRxCmColor& v);
	CRxCmColor   headerLnColor() const;

	//��ͷ�ڲ�������ɫ
	CDraft::ErrorStatus setHeaderInnerVLnColor(const CRxCmColor& v);
	CRxCmColor   headerInnerVLnColor() const;

	//��ͷ�ڲ�������ɫ
	CDraft::ErrorStatus setHeaderInnerHLnColor(const CRxCmColor& v);
	CRxCmColor   headerInnerHLnColor() const;

	//������ɫ
	CDraft::ErrorStatus setTxtColor(const CRxCmColor& v);
	CRxCmColor   txtColor() const;

	//���ָ߶�
	double txtHeight() const;
	void   setTxtHeight(double newVal);

	//��ص��ı����

	//����
	CRxDbObjectId      linetypeObjectId() const;
	void              setLinetypeObjectId(CRxDbObjectId id);

	//�߿�	//��ͷ����߿�
	CRxDb::LineWeight  HdOuterLnLineWeight() const;
	CDraft::ErrorStatus setHdOuterLnLineWeight(CRxDb::LineWeight weight);

	//�߿�	//��ͷ�ڲ������߿�
	CRxDb::LineWeight  HdVerLnLineWeight() const;
	CDraft::ErrorStatus setHdVerLnLineWeight(CRxDb::LineWeight weight);

	//�߿�	//��ͷ�ڲ������߿�
	CRxDb::LineWeight  HdHorLnLineWeight() const;
	CDraft::ErrorStatus setHdHorLnLineWeight(CRxDb::LineWeight weight);

	//�߿�	//��������߿�
	CRxDb::LineWeight  BdOuterLnLineWeight() const;
	CDraft::ErrorStatus setBdOuterLnLineWeight(CRxDb::LineWeight weight);

	//�߿�	//�����ڲ������߿�
	CRxDb::LineWeight  BdVerLnLineWeight() const;
	CDraft::ErrorStatus setBdVerLnLineWeight(CRxDb::LineWeight weight);

	//�߿�	//�����ڲ������߿�
	CRxDb::LineWeight  BdHorLnLineWeight() const;
	CDraft::ErrorStatus setBdHorLnLineWeight(CRxDb::LineWeight weight);

	//�����ͷ(��ϸ��)���ܿ��
	double totalWidth() const;
	//�����ͷ�߶�
	double totalHeight() const;

	//��ñ�ͷ��Ԫ������
	int headerCellNum() const;
	//�����ϸ��Ԫ������
	int tableCellNum() const;

	//
	CxCHAR* GetTableCellCaptionAt(int iPos) const;

private:
	CRxDb::LineWeight CRxDbBomStyleTableRecord::GetLineWeightEnum(FLOAT fVal) const;
	FLOAT CRxDbBomStyleTableRecord::GetLineWeight(CRxDb::LineWeight weight) const;

};

#pragma pack(pop)

#endif
