#ifndef __CRXDBPAPER_H_
#define __CRXDBPAPER_H_

//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//

#include "dbmain.h"
#include "dbsymtb.h"
#include <vector>
#include <map>

#pragma pack(push, 8)

#ifdef target
#undef target 
#endif

class CRXMECHANIC_CLASS CRxFTInfoObject
{
public:
	CRxFTInfoObject();
	~CRxFTInfoObject();

public:
	void Init();
	int GetAttributesCount();
	void GetAttributeName(CxCHAR*& pAttName,int iIndex);
	void GetAttributeValue(CxCHAR*& pAttValue,const CxCHAR* pAttName);
	void SetAttributeValue(const CxCHAR* pAttValue,int iIndex);

private:
	BOOL m_bHasModified;
	int  m_iCurrentType;//0,未设定；1,标题栏；2,图框
	CDraft::Template_For_PaperInfo m_TempleType;

	std::vector<CString> m_VectorAttName;
	std::vector<CString> m_VectorAttValue;
	std::vector<CString> m_VectorAttPos;

	void SetAttributeName(const CxCHAR* pAttName,int iIndex);

	void SetTemplateType(CDraft::Template_For_PaperInfo TempleType);
	void GetAttributePos(CString& strPos,int iIndex);
	void SetAttributePos(CString strPos,int iIndex);

	void SetCurrentType(int iType);

	friend class CRxDbPaperTableRecord;
};

class CRXMECHANIC_CLASS CRxBomInfoObject
{
public:
	CRxBomInfoObject();
	~CRxBomInfoObject();

public:
	void Init();
	int GetRowCount();
	int GetColCount();
	void GetBomHeaderAt(int iColIndex,CxCHAR*& pHeader);
	void GetBomItemAt(int iRowIndex,int iColIndex,CxCHAR*& pItem);
	void SetBomItemAt(int iRowIndex,int iColIndex,const CxCHAR*  pItem);   //修改

	int AddBomRow();                                                      //添加(仅限NEB文件类型) 
	void DelBomRowAt(int iRowIndex);                                       //删除(仅限NEB文件类型)

private:
	BOOL m_bGetBomInfo;
	BOOL m_bHasModified;
	std::vector<int> m_VectorAddRow;
	std::vector<int> m_VectorDelRow;
	std::vector<CString> m_VectorHeader;
	std::map<int,std::vector<CString> > m_BomMap;

	CDraft::Template_For_PaperInfo m_TempleType;
	void GetTemplateType(CDraft::Template_For_PaperInfo& TempleType);
	void SetTemplateType(CDraft::Template_For_PaperInfo TempleType);

	void SetBomHeaderAt(int iColIndex,const CxCHAR* pHeader);

	friend class CRxDbPaperTableRecord;
};

class CRxDbPaperTableRecord;
CRX_DEFINE_CLSID(8B7C3D5A-D1DF-47bf-A16F-E8B028F386C9,CRxDbPaperTable)
class CRXMECHANIC_API CRxDbPaperTable: public CRxDbSymbolTable
{
public:
	CRX_DECLARE_DYNCREATE(CRxDbPaperTable);
	CRxDbPaperTable(ICxCrxObject *i_pCrxObject = NULL);
	//  virtual ~CRxDbBlockTable();
	typedef CRxDbPaperTableRecord RecordType;

	CDraft::ErrorStatus getAt (const CxCHAR* entryName,CRxDbPaperTableRecord*& pRec,CRxDb::OpenMode openMode,bool openErasedRec = false) const;
	CDraft::ErrorStatus getAt (const CxCHAR* entryName,CRxDbObjectId& recordId,bool getErasedRec = false) const;
	bool              has   (const CxCHAR* name) const;
	bool              has   (CRxDbObjectId id) const;

	int GetPaperCount();
	CDraft::ErrorStatus GetPaperNameByIndex(int iIndex,CxCHAR*& pName);

	CDraft::ErrorStatus add   (CRxDbPaperTableRecord* pRecord);
	CDraft::ErrorStatus add   (CRxDbObjectId& recordId, CRxDbPaperTableRecord* pRecord);
};

CRX_DEFINE_CLSID(7176EFFC-529A-463c-826C-9187ECB18E02,CRxDbPaperTableRecord)
class CRXMECHANIC_API CRxDbPaperTableRecord: public   CRxDbSymbolTableRecord
{
public:
	CRX_DECLARE_DYNCREATE(CRxDbPaperTableRecord);

	CRxDbPaperTableRecord(ICxCrxObject *i_pCrxObject = NULL);


	typedef CRxDbPaperTable TableType;

	//模板
	void SetTemplateFile(const CxCHAR* pFilePath,CDraft::Template_For_PaperInfo TempleType);

	//图纸幅面信息
	void GetPaperSize(DOUBLE& dPaperWidth,DOUBLE& dPaperHeight);

	void GetPaperScale(DOUBLE& dPaperScale);
	void SetPaperScale(DOUBLE dPaperScale);

	void GetPaperDirection(CDraft::Paper_Direction& eDir);
	void SetPaperDirection(CDraft::Paper_Direction eDir);

	void GetPaperLongerQuot(LONG& lLongQuot);
	void SetPaperLongerQuot(LONG lLongQuot);

	void GetPaperSizeDescription(CDraft::PaperSizeDescription& eSizeDescription);
	void SetPaperSizeDescription(CDraft::PaperSizeDescription eSizeDescription);

	void GetIsUpdateDimAndTxtByScale(BOOL& bIsUpdateDT);
	void SetIsUpdateDimAndTxtByScale(BOOL bIsUpdateDT);

	//图框、标题栏、明细表
	void GetFrameInfo(CRxFTInfoObject* pCrxFrameInfoObj);
	CDraft::ErrorStatus SetFrameInfo(CRxFTInfoObject& CrxFrameInfoObj);

	void GetTitleInfo(CRxFTInfoObject* pCrxTitleInfoObj);
	CDraft::ErrorStatus SetTitleInfo(CRxFTInfoObject& CrxTitleInfoObj);

	void GetBomInfo(CRxBomInfoObject* pBomInfoObj);
	CDraft::ErrorStatus SetBomInfo(CRxBomInfoObject& CrxBomInfoObj);

	CDraft::ErrorStatus SetFrameByFile(const CxCHAR* cfmFilePath);
	CDraft::ErrorStatus SetTitleByFile(const CxCHAR* chdFilePath);

	//序号
	CDraft::ErrorStatus GenPartNoByCurrentStyle(const CxCHAR* cPartnoTxt,CRxGePoint3d& ptStart,CRxGePoint3d& ptTurning);

public:
	BOOL m_bHasChanged;
	CDraft::Template_For_PaperInfo m_TempleType;

private:
	BOOL m_bGotPaper;
	BOOL m_bGotPaperInfo;

	DOUBLE m_dPaperScale;

	void GetCurrentPaper();
	void GetCurrentPaperInfo();
	void GetTemplateFileInfo(CString strFilePath);
};

#pragma pack(pop)

#endif