#ifndef __CRXDBBOMSYMTB_H_
#define __CRXDBBOMSYMTB_H_

//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
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

	//明细栏每行高度
	double itemHeight() const;
	void   setItemHeight(double newVal);

	//明细栏竖线颜色
	CDraft::ErrorStatus setVerLnColor(const CRxCmColor& v);
	CRxCmColor   verLnColor() const;

	//明细栏横线颜色
	CDraft::ErrorStatus setHorLnColor(const CRxCmColor& v);
	CRxCmColor   horLnColor() const;

	//明细栏外框线颜色
	CDraft::ErrorStatus setBdOuterLnColor(const CRxCmColor& v);
	CRxCmColor   bdOuterLnColor() const;

	//表头线颜色
	CDraft::ErrorStatus setHeaderLnColor(const CRxCmColor& v);
	CRxCmColor   headerLnColor() const;

	//表头内部纵线颜色
	CDraft::ErrorStatus setHeaderInnerVLnColor(const CRxCmColor& v);
	CRxCmColor   headerInnerVLnColor() const;

	//表头内部横线颜色
	CDraft::ErrorStatus setHeaderInnerHLnColor(const CRxCmColor& v);
	CRxCmColor   headerInnerHLnColor() const;

	//文字颜色
	CDraft::ErrorStatus setTxtColor(const CRxCmColor& v);
	CRxCmColor   txtColor() const;

	//文字高度
	double txtHeight() const;
	void   setTxtHeight(double newVal);

	//相关的文本风格

	//线型
	CRxDbObjectId      linetypeObjectId() const;
	void              setLinetypeObjectId(CRxDbObjectId id);

	//线宽	//表头外框线宽
	CRxDb::LineWeight  HdOuterLnLineWeight() const;
	CDraft::ErrorStatus setHdOuterLnLineWeight(CRxDb::LineWeight weight);

	//线宽	//表头内部竖线线宽
	CRxDb::LineWeight  HdVerLnLineWeight() const;
	CDraft::ErrorStatus setHdVerLnLineWeight(CRxDb::LineWeight weight);

	//线宽	//表头内部横线线宽
	CRxDb::LineWeight  HdHorLnLineWeight() const;
	CDraft::ErrorStatus setHdHorLnLineWeight(CRxDb::LineWeight weight);

	//线宽	//表体外框线宽
	CRxDb::LineWeight  BdOuterLnLineWeight() const;
	CDraft::ErrorStatus setBdOuterLnLineWeight(CRxDb::LineWeight weight);

	//线宽	//表体内部竖线线宽
	CRxDb::LineWeight  BdVerLnLineWeight() const;
	CDraft::ErrorStatus setBdVerLnLineWeight(CRxDb::LineWeight weight);

	//线宽	//表体内部横线线宽
	CRxDb::LineWeight  BdHorLnLineWeight() const;
	CDraft::ErrorStatus setBdHorLnLineWeight(CRxDb::LineWeight weight);

	//计算表头(明细表)的总宽度
	double totalWidth() const;
	//计算表头高度
	double totalHeight() const;

	//获得表头单元的总数
	int headerCellNum() const;
	//获得明细表单元的总数
	int tableCellNum() const;

	//
	CxCHAR* GetTableCellCaptionAt(int iPos) const;

private:
	CRxDb::LineWeight CRxDbBomStyleTableRecord::GetLineWeightEnum(FLOAT fVal) const;
	FLOAT CRxDbBomStyleTableRecord::GetLineWeight(CRxDb::LineWeight weight) const;

};

#pragma pack(pop)

#endif
