#ifndef __CRXDBSYMTB_H_
#define __CRXDBSYMTB_H_

//
//£®C£©Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ∞Ê»®À˘”–£®C£©±±æ© ˝¬ÅEÛ∑Ωø∆ººπ…∑›”–œﬁπ´Àæ
//  ◊˚Ú’”√ªß π”√±æ»˙ÿ˛±ÿ–ÅEÒ ÿ°∂CAXA◊˚Ú’”√ªß–˙€… π”√–≠“È°∑
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

//class CRxDbSortentsTable;
class CRxDbSymbolTableIterator;
class CRxDbSymbolTableRecord;
class CRxDbAttributeDefinition;
//class CRxDbAnnotationScale;
//class CRxGsView;
//class CRxString;

CRX_DEFINE_CLSID(38083A18-C6A9-4CB1-A106-71BD42038A90,CRxDbSymbolTable)
class CRXDB_CLASS CRxDbSymbolTable: public CRxDbObject
{
public:
    CRX_DECLARE_DYNCREATE(CRxDbSymbolTable);

    typedef CRxDbSymbolTableRecord RecordType;

    //CDraft::ErrorStatus getAt (const CxCHAR* entryName,
    //                         CRxDbSymbolTableRecord*& pRec,
    //                         CRxDb::OpenMode openMode,
    //                         bool openErasedRec = false) const;
    //CDraft::ErrorStatus getAt (const CxCHAR* entryName,
    //                         CrxDbObjectId& recordId,
    //                         bool getErasedRecord = false) const;
    //bool              has(const CxCHAR* name) const;
    bool              has(CRxDbObjectId id) const;
    CDraft::ErrorStatus newIterator(CRxDbSymbolTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    CDraft::ErrorStatus add(CRxDbSymbolTableRecord* pRecord);
    CDraft::ErrorStatus add(CRxDbObjectId& recordId, CRxDbSymbolTableRecord* pRecord);

protected:
	CRxDbSymbolTable();
};

class CRxDbBlockTableRecord;
class CRxDbBlockTableIterator;

CRX_DEFINE_CLSID(02EA2C4D-3925-4D2B-85E6-5B4DF7330D84,CRxDbBlockTable)
class CRXDB_CLASS CRxDbBlockTable: public CRxDbSymbolTable
{
public:
    CRX_DECLARE_DYNCREATE(CRxDbBlockTable);
    CRxDbBlockTable(ICxCrxObject *i_pCrxObject = NULL);
//  virtual ~CRxDbBlockTable();
    typedef CRxDbBlockTableRecord RecordType;

    CDraft::ErrorStatus getAt (const CxCHAR* entryName,
                             CRxDbBlockTableRecord*& pRec,
                             CRxDb::OpenMode openMode,
                             bool openErasedRec = false) const;
    CDraft::ErrorStatus getAt (const CxCHAR* entryName,
                             CRxDbObjectId& recordId,
                             bool getErasedRec = false) const;
    bool              has   (const CxCHAR* name) const;
    bool              has   (CRxDbObjectId id) const;
    CDraft::ErrorStatus newIterator(CRxDbBlockTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    CDraft::ErrorStatus add   (CRxDbBlockTableRecord* pRecord);
    CDraft::ErrorStatus add   (CRxDbObjectId& recordId, CRxDbBlockTableRecord* pRecord);
	virtual CRxObject* clone() const;

//    virtual CDraft::ErrorStatus getClassID(CLSID* pClsid) const;
};
//
class CRxDbLayerTableRecord;
class CRxDbLayerTableIterator;
//

CRX_DEFINE_CLSID(36E1DCCD-333C-4007-B0FB-49BC6329205C,CRxDbLayerTable)
class CRXDB_CLASS CRxDbLayerTable: public CRxDbSymbolTable
{
public:
    CRX_DECLARE_DYNCREATE(CRxDbLayerTable);

	CRxDbLayerTable(ICxCrxObject *i_pCrxObject=NULL);
	//virtual ~CRxDbLayerTable();

    typedef CRxDbLayerTableRecord RecordType;

    CDraft::ErrorStatus getAt(const CxCHAR* entryName,
                            CRxDbLayerTableRecord*& pRec,
                            CRxDb::OpenMode openMode,
                            bool openErasedRec = false) const;
    CDraft::ErrorStatus getAt(const CxCHAR* entryName,
                            CRxDbObjectId& recordId,
                            bool getErasedRecord = false) const;
    bool              has  (const CxCHAR* name) const;
    bool              has  (CRxDbObjectId id) const;
    CDraft::ErrorStatus newIterator(CRxDbLayerTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    CDraft::ErrorStatus add (CRxDbLayerTableRecord* pRecord);
    CDraft::ErrorStatus add (CRxDbObjectId& recordId, CRxDbLayerTableRecord* pRecord);

	virtual CRxObject* clone() const;
    //void generateUsageData();

    //bool hasUnreconciledLayers() const;
    //CDraft::ErrorStatus getUnreconciledLayers(CRxDbObjectIdArray& idArray) const;
};
//
class CRxDbTextStyleTableRecord;
class CRxDbTextStyleTableIterator;
//
CRX_DEFINE_CLSID(2EACF156-507A-45D7-8AD9-618B08D63DBC,	CRxDbTextStyleTable)
class CRXDB_CLASS CRxDbTextStyleTable: public CRxDbSymbolTable
{
public:
     CRX_DECLARE_DYNCREATE(CRxDbTextStyleTable);
    CRxDbTextStyleTable(ICxCrxObject *i_pCrxObject=NULL);
  //  virtual ~CRxDbTextStyleTable();
//
    typedef CRxDbTextStyleTableRecord RecordType;
//
    CDraft::ErrorStatus getAt(const CxCHAR* entryName,
                            CRxDbTextStyleTableRecord*& pRec,
                            CRxDb::OpenMode openMode,
                            bool openErasedRec = false) const;
    CDraft::ErrorStatus getAt (const CxCHAR* entryName,
                             CRxDbObjectId& recordId,
                             bool getErasedRecord = false) const;
    bool              has   (const CxCHAR* name) const;
    bool              has   (CRxDbObjectId id) const;
    CDraft::ErrorStatus newIterator(CRxDbTextStyleTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    CDraft::ErrorStatus add   (CRxDbTextStyleTableRecord* pRecord);
    CDraft::ErrorStatus add   (CRxDbObjectId&  recordId,
        CRxDbTextStyleTableRecord* pRecord);
	
	virtual CRxObject* clone() const;

//
//    virtual CDraft::ErrorStatus getClassID(CLSID* pClsid) const;
};
//
class CRxDbLinetypeTableRecord;
class CRxDbLinetypeTableIterator;
//
CRX_DEFINE_CLSID(C3C14722-1319-4C35-86BD-7A8B6AC22A0B,CRxDbLinetypeTable)
class CRXDB_CLASS CRxDbLinetypeTable: public CRxDbSymbolTable
{
public:
    CRX_DECLARE_DYNCREATE(CRxDbLinetypeTable);
    CRxDbLinetypeTable(ICxCrxObject *i_pCrxObject = NULL);
    //virtual ~CRxDbLinetypeTable();
//
    typedef CRxDbLinetypeTableRecord RecordType;
//
    CDraft::ErrorStatus getAt(const CxCHAR* entryName,
                            CRxDbLinetypeTableRecord*& pRec,
                            CRxDb::OpenMode openMode,
                            bool openErasedRec = false) const;
    CDraft::ErrorStatus getAt(const CxCHAR* entryName,
                            CRxDbObjectId& recordId,
                            bool getErasedRec = false) const;
    bool              has  (const CxCHAR* name) const;
    bool              has  (CRxDbObjectId id) const;
    CDraft::ErrorStatus newIterator(CRxDbLinetypeTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    CDraft::ErrorStatus add  (CRxDbLinetypeTableRecord* pRecord);
    CDraft::ErrorStatus add  (CRxDbObjectId& recordId,
        CRxDbLinetypeTableRecord* pRecord);

	virtual CRxObject* clone() const;
//
//    virtual CDraft::ErrorStatus getClassID(CLSID* pClsid) const;
};
//
//class CRxDbAbstractViewTableRecord;
//class CRxDbAbstractViewTableIterator;
//
//class CAXA_NO_VTABLE CRxDbAbstractViewTable: public CRxDbSymbolTable
//{
//public:
//    CRX_DECLARE_DYNCREATE(CRxDbAbstractViewTable);
//    CRxDbAbstractViewTable();
//    virtual ~CRxDbAbstractViewTable();
//    CDraft::ErrorStatus getAt(const CxCHAR* entryName,
//                            CRxDbAbstractViewTableRecord*& pRec,
//                            CRxDb::OpenMode openMode,
//                            bool openErasedRec = false) const;
//    CDraft::ErrorStatus getAt(const CxCHAR* entryName,
//                            CrxDbObjectId& recordId,
//                            bool getErasedRecord = false) const;
//    bool              has  (const CxCHAR* name) const;
//    bool              has  (CrxDbObjectId id) const;
//    CDraft::ErrorStatus newIterator(CRxDbAbstractViewTableIterator*& pIterator,
//                                  bool atBeginning = true,
//                                  bool skipDeleted = true) const;
//    CDraft::ErrorStatus add  (CRxDbAbstractViewTableRecord* pRecord);
//    CDraft::ErrorStatus add  (CrxDbObjectId&  recordId,
//        CRxDbAbstractViewTableRecord* pRecord);
//};
//
//class CRxDbViewTableRecord;
//class CRxDbViewTableIterator;
//
//class CRxDbViewTable: public CRxDbAbstractViewTable
//{
//public:
//    CRX_DECLARE_DYNCREATE(CRxDbViewTable);
//    CRxDbViewTable();
//    virtual ~CRxDbViewTable();
//
//    typedef CRxDbViewTableRecord RecordType;
//
//    CDraft::ErrorStatus getAt(const CxCHAR* entryName,
//                            CRxDbViewTableRecord*& pRec,
//                            CRxDb::OpenMode openMode,
//                            bool openErasedRec = false) const;
//    CDraft::ErrorStatus getAt(const CxCHAR* entryName,
//                            CrxDbObjectId& recordId,
//                            bool getErasedRec = false) const;
//    bool              has  (const CxCHAR* name) const;
//    bool              has  (CrxDbObjectId id) const;
//    CDraft::ErrorStatus newIterator(CRxDbViewTableIterator*& pIterator,
//                                  bool atBeginning = true,
//                                  bool skipDeleted = true) const;
//    CDraft::ErrorStatus add  (CRxDbViewTableRecord* pRecord);
//    CDraft::ErrorStatus add  (CrxDbObjectId&  recordId,
//        CRxDbViewTableRecord* pRecord);
//
//    virtual CDraft::ErrorStatus getClassID(CLSID* pClsid) const;
//};
//
class CRxDbUCSTableRecord;
class CRxDbUCSTableIterator;
//
CRX_DEFINE_CLSID(38083A18-C6A9-4CB1-A106-71BD42038A90,	CRxDbUCSTable)
class CRXDB_API CRxDbUCSTable: public CRxDbSymbolTable
{
public:
    CRX_DECLARE_DYNCREATE(CRxDbUCSTable);
    CRxDbUCSTable(ICxCrxObject *i_pCrxObject=NULL);
//    virtual ~CRxDbUCSTable();
//
    typedef CRxDbUCSTableRecord RecordType;
//
    CDraft::ErrorStatus getAt(const CxCHAR* entryName,
                            CRxDbUCSTableRecord*& pRec,
                            CRxDb::OpenMode openMode,
                            bool openErasedRec = false) const;
    CDraft::ErrorStatus getAt(const CxCHAR* entryName,
                            CRxDbObjectId& recordId,
                            bool getErasedRecord = false) const;
    bool              has  (const CxCHAR* name) const;
    bool              has  (CRxDbObjectId id) const;
    CDraft::ErrorStatus newIterator(CRxDbUCSTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    CDraft::ErrorStatus add  (CRxDbUCSTableRecord* pRecord);
    CDraft::ErrorStatus add  (CRxDbObjectId&  recordId,
        CRxDbUCSTableRecord* pRecord);

	virtual CRxObject* clone() const;
//    virtual CDraft::ErrorStatus getClassID(CLSID* pClsid) const;
};
//
//class CRxDbViewportTableRecord;
//class CRxDbViewportTableIterator;
//
//class CRxDbViewportTable: public CRxDbAbstractViewTable
//{
//public:
//    CRX_DECLARE_DYNCREATE(CRxDbViewportTable);
//    CRxDbViewportTable();
//    virtual ~CRxDbViewportTable();
//
//    typedef CRxDbViewportTableRecord RecordType;
//
//    CDraft::ErrorStatus getAt(const CxCHAR* entryName,
//                            CRxDbViewportTableRecord*& pRec,
//                            CRxDb::OpenMode openMode,
//                            bool openErasedRec = false) const;
//    CDraft::ErrorStatus getAt(const CxCHAR* entryName,
//                            CrxDbObjectId& recordId,
//                            bool getErasedRecord = false) const;
//    bool              has  (const CxCHAR* name) const;
//    bool              has  (CrxDbObjectId id) const;
//    CDraft::ErrorStatus newIterator(CRxDbViewportTableIterator*& pIterator,
//                                  bool atBeginning = true,
//                                  bool skipDeleted = true) const;
//    CDraft::ErrorStatus add  (CRxDbViewportTableRecord* pRecord);
//    CDraft::ErrorStatus add  (CrxDbObjectId& recordId,
//        CRxDbViewportTableRecord* pRecord);
//
//    virtual CDraft::ErrorStatus getClassID(CLSID* pClsid) const;
//};
//
class CRxDbRegAppTableRecord;
class CRxDbRegAppTableIterator;
//
CRX_DEFINE_CLSID(38083A18-C6A9-4CB1-A106-71BD42038A90,CRxDbRegAppTable)
class CRXDB_API CRxDbRegAppTable: public CRxDbSymbolTable
{
public:
    CRX_DECLARE_DYNCREATE(CRxDbRegAppTable);
    CRxDbRegAppTable(ICxCrxObject *i_pCrxObject=NULL);
//    virtual ~CrxDbRegAppTable();
//
    typedef CRxDbRegAppTableRecord RecordType;
//
    CDraft::ErrorStatus getAt(const CxCHAR* entryName,
                            CRxDbRegAppTableRecord*& pRec,
                            CRxDb::OpenMode openMode,
                            bool openErasedRec = false) const;
    CDraft::ErrorStatus getAt(const CxCHAR* entryName,
                            CRxDbObjectId& recordId,
                            bool getErasedRec = false) const;
    bool              has  (const CxCHAR* name) const;
    bool              has  (CRxDbObjectId id) const;
    CDraft::ErrorStatus newIterator(CRxDbRegAppTableIterator*& pIterator,
                                  bool atBeginning = true,
                                  bool skipDeleted = true) const;
    CDraft::ErrorStatus   add     (CRxDbRegAppTableRecord* pRecord);
    CDraft::ErrorStatus   add     (CRxDbObjectId&  recordId,
        CRxDbRegAppTableRecord* pRecord);

	virtual CRxObject* clone() const;
//
//    virtual CDraft::ErrorStatus getClassID(CLSID* pClsid) const;
};
//
class CRxDbDimStyleTableRecord;
class CRxDbDimStyleTableIterator;
//
CRX_DEFINE_CLSID(2EACF156-507A-45D7-8AD9-618B08D63DBC,CRxDbDimStyleTable)
class CRXDB_API CRxDbDimStyleTable: public CRxDbSymbolTable
{
public:
    CRX_DECLARE_DYNCREATE(CRxDbDimStyleTable);
    CRxDbDimStyleTable(ICxCrxObject *i_pCrxObject=NULL);
 //   virtual ~CrxDbDimStyleTable();
//
    typedef CRxDbDimStyleTableRecord RecordType;
//
    CDraft::ErrorStatus   getAt   (const CxCHAR* entryName,
                                 CRxDbDimStyleTableRecord*& pRec,
                                 CRxDb::OpenMode openMode,
                                 bool openErasedRec = false) const;
    CDraft::ErrorStatus   getAt   (const CxCHAR* entryName,
                                 CRxDbObjectId& recordId,
                                 bool getErasedRec = false) const;
    bool                has     (const CxCHAR* name) const;
    bool                has     (CRxDbObjectId id) const;
    CDraft::ErrorStatus   newIterator(CRxDbDimStyleTableIterator*& pIterator,
                                    bool atBeginning = true,
                                    bool skipDeleted = true) const;
    CDraft::ErrorStatus   add     (CRxDbDimStyleTableRecord* pRecord);
    CDraft::ErrorStatus   add     (CRxDbObjectId&  recordId,
        CRxDbDimStyleTableRecord* pRecord);

	virtual CRxObject* clone() const;
//
//    virtual CDraft::ErrorStatus getClassID(CLSID* pClsid) const;
};
//
///// CrxDbSymbolTableIterator
//
// This class is responsible for iterating over the records in a symbol
// table.
//
// This is a completely "generic" symbol table iterator in that it can 
// be used to iterate over the contents of any CRxDbSymbolTable subclass.
// However, symbol table specific iterators are defined below.
//
// One major item of note.  The creation of one of these iterators
// requires the opening (for read) of the table being iterated over.
// This read stays in effect until the iterator is destroyed.
//
class CRXDB_API CRxDbSymbolTableIterator
	{
public:
    virtual ~CRxDbSymbolTableIterator();

    void                start   (bool atBeginning = true,
                                 bool skipDeleted = true);

    bool                done    () const;


    CDraft::ErrorStatus   getRecordId(CRxDbObjectId& id) const;

    CDraft::ErrorStatus   getRecord(CRxDbSymbolTableRecord*& pRecord,
                                 CRxDb::OpenMode openMode,
                                 bool openErasedRec = false) const;

    void                step    (bool forward = true,
                                 bool skipDeleted = true);

    CDraft::ErrorStatus   seek    (CRxDbObjectId id);
    CDraft::ErrorStatus   seek    (const CRxDbSymbolTableRecord* pRecord);

protected:
	LONG_PTR			m_lpPos;
    void				*mpImp;
	ICxCrxObject		*m_pCurObj;

    CRxDbSymbolTableIterator();
    friend CRxDbSymbolTable;
};

class CRXDB_API CRxDbBlockTableIterator : public CRxDbSymbolTableIterator
{
public:
    CDraft::ErrorStatus getRecord(CRxDbBlockTableRecord*& pRecord,
								CRxDb::OpenMode openMode, bool openErasedRec = false) const;
    CDraft::ErrorStatus seek(CRxDbObjectId id);
    CDraft::ErrorStatus seek(const CRxDbBlockTableRecord* pRecord);

protected:
    CRxDbBlockTableIterator();
    friend class CRxDbBlockTable;
};

class  CRXDB_API CRxDbLayerTableIterator : public CRxDbSymbolTableIterator
{
public:
    CDraft::ErrorStatus getRecord(CRxDbLayerTableRecord*& pRecord,
								CRxDb::OpenMode openMode, bool openErasedRec = false) const;

    CDraft::ErrorStatus seek(const CRxDbLayerTableRecord* pRecord);

    //bool getSkipHidden() const;
    //void setSkipHidden(bool value);
    //bool getSkipReconciled() const;
    //void setSkipReconciled(bool value);
protected:
    CRxDbLayerTableIterator();
    friend class CRxDbLayerTable;
};


class CRXDB_API CRxDbTextStyleTableIterator : public CRxDbSymbolTableIterator
{
public:
    CDraft::ErrorStatus getRecord(CRxDbTextStyleTableRecord*& pRecord,
        CRxDb::OpenMode openMode, bool openErasedRec = false) const;
    CDraft::ErrorStatus seek(CRxDbObjectId id);
    CDraft::ErrorStatus seek(const CRxDbTextStyleTableRecord* pRecord);
//
protected:
    CRxDbTextStyleTableIterator();
    friend class CRxDbTextStyleTable;
};
//
class CRXDB_API CRxDbLinetypeTableIterator : public CRxDbSymbolTableIterator
{
public:
    CDraft::ErrorStatus getRecord(CRxDbLinetypeTableRecord*& pRecord,
        CRxDb::OpenMode openMode, bool openErasedRec = false) const;
    CDraft::ErrorStatus seek(CRxDbObjectId id);
    CDraft::ErrorStatus seek(const CRxDbLinetypeTableRecord* pRecord);

protected:
    CRxDbLinetypeTableIterator();
    friend class CRxDbLinetypeTable;
};
//
//class CRxDbAbstractViewTableIterator: public CRxDbSymbolTableIterator
//{
//public:
//    CDraft::ErrorStatus getRecord(CRxDbAbstractViewTableRecord*& pRecord,
//        CRxDb::OpenMode openMode, bool openErasedRec = false) const;
//    CDraft::ErrorStatus seek(CrxDbObjectId id);
//    CDraft::ErrorStatus seek(const CRxDbAbstractViewTableRecord* pRecord);
//
//protected:
//    CRxDbAbstractViewTableIterator();
//    friend class CRxDbAbstractViewTable;
//};
//
//class CRxDbViewTableIterator : public CRxDbAbstractViewTableIterator
//{
//public:
//    CDraft::ErrorStatus getRecord(CRxDbViewTableRecord*& pRecord,
//        CRxDb::OpenMode openMode, bool openErasedRec = false) const;
//    CDraft::ErrorStatus seek(CrxDbObjectId id);
//    CDraft::ErrorStatus seek(const CRxDbViewTableRecord* pRecord);
//
//protected:
//    CRxDbViewTableIterator();
//    friend class CRxDbViewTable;
//};
//
class CRXDB_API CRxDbUCSTableIterator : public CRxDbSymbolTableIterator
{
public:
    CDraft::ErrorStatus getRecord(CRxDbUCSTableRecord*& pRecord,
        CRxDb::OpenMode openMode, bool openErasedRec = false) const;
    CDraft::ErrorStatus seek(CRxDbObjectId id);
    CDraft::ErrorStatus seek(const CRxDbUCSTableRecord* pRecord);

protected:
    CRxDbUCSTableIterator();
    friend class CRxDbUCSTable;
};
//
//class CRxDbViewportTableIterator : public CRxDbAbstractViewTableIterator
//{
//public:
//    CDraft::ErrorStatus getRecord(CRxDbViewportTableRecord*& pRecord,
//        CRxDb::OpenMode openMode, bool openErasedRec = false) const;
//    CDraft::ErrorStatus seek(CrxDbObjectId id);
//    CDraft::ErrorStatus seek(const CRxDbViewportTableRecord* pRecord);
//
//protected:
//    CRxDbViewportTableIterator();
//    friend class CRxDbViewportTable;
//};
//
class CRXDB_API CRxDbRegAppTableIterator : public CRxDbSymbolTableIterator
{
public:
    CDraft::ErrorStatus getRecord(CRxDbRegAppTableRecord*& pRecord,
        CRxDb::OpenMode openMode, bool openErasedRec = false) const;
    CDraft::ErrorStatus seek(CRxDbObjectId id);
    CDraft::ErrorStatus seek(const CRxDbRegAppTableRecord* pRecord);

protected:
    CRxDbRegAppTableIterator();
    friend class CRxDbRegAppTable;
};

class CRXDB_API CRxDbDimStyleTableIterator : public CRxDbSymbolTableIterator
{
public:
    CDraft::ErrorStatus getRecord(CRxDbDimStyleTableRecord*& pRecord,
        CRxDb::OpenMode openMode, bool openErasedRec = false) const;
    CDraft::ErrorStatus seek(CRxDbObjectId id);
    CDraft::ErrorStatus seek(const CRxDbDimStyleTableRecord* pRecord);

protected:
    CRxDbDimStyleTableIterator();
    friend class CRxDbDimStyleTable;
};

CRX_DEFINE_NULL_CLSID(CRxDbSymbolTableRecord)
class CRXDB_API CRxDbSymbolTableRecord: public CRxDbObject
{
public:
    CRX_DECLARE_DYNAMIC(CRxDbSymbolTableRecord);
	
    virtual ~CRxDbSymbolTableRecord();

    typedef CRxDbSymbolTable TableType;

    virtual CDraft::ErrorStatus getName(CxCHAR*& pName) const;
    //CDraft::ErrorStatus getName(CRxString & sName) const;
   // CDraft::ErrorStatus getName(const CxCHAR*& pName) const;
    virtual CDraft::ErrorStatus setName(const CxCHAR* pName);

    bool isDependent() const;
    bool isResolved() const;
	
protected:
	CRxDbSymbolTableRecord();
};


class CRXDB_API CRxDbBlockTableRecordIterator
{
public:
	virtual ~CRxDbBlockTableRecordIterator();

    void              start (bool atBeginning = true,
                             bool skipDeleted = true);

    bool              done  () const;

    CDraft::ErrorStatus getEntityId (CRxDbObjectId& entityId) const;

    CDraft::ErrorStatus getEntity(CRxDbEntity*& pEntity, CRxDb::OpenMode openMode,
                                bool openErasedEntity = false) const;	

	CRxDbBlockTableRecord* blockTableRecord() const;

    void              step (bool forward = true,
                            bool skipDeleted = true);

	CDraft::ErrorStatus seek (CRxDbObjectId id);

	CDraft::ErrorStatus seek (const CRxDbEntity* pEntity);
//
//protected:
  //  class CRxDbImpBlockTableRecordIterator* mpImp;
private:
	CRxDbBlockTableRecordIterator();
	friend class CRxDbBlockTableRecord;

public:
	LONG_PTR			m_lpPos;
	void				*mpImp;
	ICxCrxObject		*m_pCurObj;
};

//// This class will be removed in the next release.   Instead, use
//// CRxDbBlockTableRecord::getBlockReferenceIds().
////
//class CRxDbBlockReferenceIdIterator
//{
//public:
//    ~CRxDbBlockReferenceIdIterator();
//
//    void              start () { mPos = 0; }
//        
//    bool              done  () const { return mPos >= mAry.length(); }
//
//    CDraft::ErrorStatus getBlockReferenceId (CrxDbObjectId& id) const;
//
//    CDraft::ErrorStatus getDatabase (CrxDbDatabase*& pDb) const;
//
//    CDraft::ErrorStatus getBlockReference(CrxDbBlockReference*& pBlkRef,
//                        CRxDb::OpenMode openMode, bool openErasedEntity = false) const;
//
//    void              step () { mPos++; }
//
//    CDraft::ErrorStatus seek (CrxDbObjectId id);
//
//private:
//    CRxDbBlockReferenceIdIterator();
//    friend class CRxDbBlockTableRecord;
//
//    int               mPos;
//    CRxDbObjectIdArray mAry;
//};
//
CRX_DEFINE_CLSID(B65F3081-5C0E-4D00-97B4-0C5231051AF1,CRxDbBlockTableRecord)
class CRXDB_API CRxDbBlockTableRecord: public  CRxDbSymbolTableRecord
{
public:
    CRX_DECLARE_DYNCREATE(CRxDbBlockTableRecord);

    CRxDbBlockTableRecord(ICxCrxObject *i_pCrxObject = NULL);
//    virtual ~CRxDbBlockTableRecord();
//
    typedef CRxDbBlockTable TableType;
//    typedef CRxArray<CAXA::UInt8> PreviewIcon;
//
//    virtual CDraft::ErrorStatus dwgOutFields(CRxDbDwgFiler* filer) const;
//    virtual CDraft::ErrorStatus dxfOutFields(CRxDbDxfFiler* filer) const;
//
    CDraft::ErrorStatus appendAcDbEntity(CRxDbEntity* pEntity);

    CDraft::ErrorStatus appendAcDbEntity(CRxDbObjectId& pOutputId,
        CRxDbEntity* pEntity);

    CDraft::ErrorStatus newIterator(
        CRxDbBlockTableRecordIterator*& pIterator,
        bool atBeginning = true,
        bool skipDeleted = true) const;
//
//    CDraft::ErrorStatus comments(CxCHAR*& pString) const;
//    CDraft::ErrorStatus comments(const CxCHAR*& pString) const;
//    CDraft::ErrorStatus setComments(const CxCHAR* pString);
//
//    CDraft::ErrorStatus pathName(CxCHAR*& pPath) const;
//    CDraft::ErrorStatus pathName(const CxCHAR*& pPath) const;
//    CDraft::ErrorStatus setPathName(const CxCHAR* pathStr);
 
    CRxGePoint3d       origin() const;
    CDraft::ErrorStatus setOrigin(const CRxGePoint3d& pt);
//
//    CDraft::ErrorStatus openBlockBegin(CRxDbBlockBegin*& pBlockBegin,
//                                     CRxDb::OpenMode   openMode);
// 
//    CDraft::ErrorStatus openBlockEnd(CRxDbBlockEnd*& pBlockEnd,
//                                   CRxDb::OpenMode openMode);
//
//    bool              hasAttributeDefinitions() const;
//
//    bool              hasPreviewIcon() const;
//    CDraft::ErrorStatus getPreviewIcon(PreviewIcon &previewIcon) const;
//    CDraft::ErrorStatus setPreviewIcon(const PreviewIcon &previewIcon);
//
//    bool              isAnonymous() const;
//
//    bool              isFromExternalReference() const;
//
//    bool              isFromOverlayReference() const;
//
	bool              isLayout() const;

	CRxDbObjectId      getLayoutId() const;
//    CDraft::ErrorStatus setLayoutId(CrxDbObjectId);
//
//
//    CDraft::ErrorStatus newBlockReferenceIdIterator(
//        CRxDbBlockReferenceIdIterator*& pIter) const;
//
//    // CRxDbBlockReferenceIdIterator will be going away. 
//    // Use getBlockReferenceIds() instead.
//    //
//    CDraft::ErrorStatus getBlockReferenceIds(CRxDbObjectIdArray& ids,
//                                           bool bDirectOnly = true,
//                                           bool bForceValidity = false) const; 
//
//    CDraft::ErrorStatus getErasedBlockReferenceIds(CRxDbObjectIdArray&);
//
//    // getSortentsTable 
//    //
//    // Returns the sortents table opened as requested, sparing the caller
//    // the work of getting the extension dictionary and looking the sortents
//    // table up in it.
//    // If the dictionary is successfully opened and returned, it is the
//    // caller's responsibility to close it.
//    //
//    // ErrorStatus returns errors if the sortents dictionary cannot be opened,
//    //             doesn't exist, and createIfNecessary
//    //             is false, or if createIfNecessary is true, but
//    //             the BTR is not open for write, or if its
//    //             extension dictionary could not be created or
//    //             opened.
//    //                            
//    CDraft::ErrorStatus
//    getSortentsTable(CRxDbSortentsTable*& pSortents,
//                     CRxDb::OpenMode openMode,
//                     bool createIfNecessary=false);
//
//    CrxDbDatabase*     xrefDatabase(bool incUnres = false) const;
//
//    bool              isUnloaded() const;
//    CDraft::ErrorStatus setIsUnloaded(bool isUnloaded);
//
//    CRxDb::XrefStatus  xrefStatus() const;
//
//    // Drawable API
//    //
//    CRxGiDrawable*     drawable();
//    CAXA::UInt32     setAttributes(CRxGiDrawableTraits* pTraits);
//    CAXA::Boolean    worldDraw(CRxGiWorldDraw* pWd);
//    void              viewportDraw(CRxGiViewportDraw* pVd);
//    void              setGsNode(AcGsNode* pNode);
//    AcGsNode*         gsNode() const;
//
//    virtual CDraft::ErrorStatus decomposeForSave(CRxDb::CRxDbDwgVersion ver,
//                                               CrxDbObject*& replaceObj,
//                                               CrxDbObjectId& replaceId,
//                                               CAXA::Boolean& exchangeXData);
//    virtual CDraft::ErrorStatus getClassID(CLSID* pClsid) const;
//
//    virtual CDraft::ErrorStatus assumeOwnershipOf(CRxArray <CrxDbObjectId> entitiesToMove);
//
//    // Block scaling and exploding control
//
//    enum BlockScaling {
//        kAny,
//        kUniform
    //};
//
//
//    CRxDbBlockTableRecord::BlockScaling blockScaling () const;
//    CDraft::ErrorStatus  setBlockScaling (
//                        CRxDbBlockTableRecord::BlockScaling blockScaling);
//
//    CDraft::ErrorStatus setExplodable (bool bExplodable);
//    bool              explodable () const;
//
//    CDraft::ErrorStatus setBlockInsertUnits(CRxDb::UnitsValue insunits);
//    CRxDb::UnitsValue blockInsertUnits() const;
//
//    CDraft::ErrorStatus postProcessAnnotativeBTR(int& stripCnt, const bool bqueryOnly = false,
//                                               const bool bScale = true);
//    CDraft::ErrorStatus addAnnoScalestoBlkRefs(const bool bScale = false);
//
	virtual CDraft::ErrorStatus getName(CxCHAR*& pName) const;
	virtual CDraft::ErrorStatus setName(const CxCHAR* pName);
};
//
//

CRX_DEFINE_CLSID(6D0AE65F-A804-4CF3-9D92-07831C336A7A,CRxDbLayerTableRecord)
class CRXDB_API CRxDbLayerTableRecord: public CRxDbSymbolTableRecord
{
public:
	CRX_DECLARE_DYNCREATE(CRxDbLayerTableRecord);

	CRxDbLayerTableRecord(ICxCrxObject *i_pCrxObject = NULL);
	virtual ~CRxDbLayerTableRecord();

    typedef CRxDbLayerTable TableType;

    bool              isFrozen() const;
    CDraft::ErrorStatus setIsFrozen(bool frozen);

    bool              isOff() const;
    void              setIsOff(bool off);

	bool              VPDFLT() const;
    void              setVPDFLT(bool frozen);

    bool              isLocked() const;
    void              setIsLocked(bool locked);
//
    CRxCmColor         color() const;
    void              setColor(const CRxCmColor &color);
    CRxCmEntityColor   entityColor(void) const;
//
//    AcCmTransparency  transparency(void) const;
//    CDraft::ErrorStatus setTransparency(const AcCmTransparency& trans);
//
    CRxDbObjectId      linetypeObjectId() const;
    void              setLinetypeObjectId(CRxDbObjectId id);
//
//    CrxDbObjectId      materialId() const;
//    CDraft::ErrorStatus setMaterialId(CrxDbObjectId id);
//
//    enum { kDxfLayerPlotBit = CRxDb::kDxfBool };
//    bool              isPlottable() const;
//    CDraft::ErrorStatus setIsPlottable(bool plot);
//
    CRxDb::LineWeight  lineWeight() const;
    CDraft::ErrorStatus setLineWeight(CRxDb::LineWeight weight);
//
//    CxCHAR*            plotStyleName() const;
//    CrxDbObjectId      plotStyleNameId() const;
//    CDraft::ErrorStatus setPlotStyleName(const CxCHAR* newName);
//    CDraft::ErrorStatus setPlotStyleName(const CrxDbObjectId& newId);
//
//    // Drawable API
//    //
//    CRxGiDrawable*     drawable();
//    CAXA::UInt32     setAttributes(CRxGiDrawableTraits* pTraits);
//    CAXA::Boolean    worldDraw(CRxGiWorldDraw* pWd);
//    void              viewportDraw(CRxGiViewportDraw* pVd);
//    void              setGsNode(AcGsNode* pNode);
//    AcGsNode*         gsNode() const;
//
//    virtual CDraft::ErrorStatus getClassID(CLSID* pClsid) const;
//
   // bool              isInUse() const;
    CxCHAR*            description() const;
    CDraft::ErrorStatus setDescription(const CxCHAR* description);
//
    bool              isHidden() const;
    CDraft::ErrorStatus setIsHidden(bool on);
    static bool isHidden(CRxDbObjectId);
//
//    // Property override API
//    //
//    CrxCmColor         color(const CrxDbObjectId& viewportId, bool& isOverride) const;
//    CDraft::ErrorStatus setColor(const CrxCmColor& color, 
//                               const CrxDbObjectId& viewportId);
//
//    CrxDbObjectId      linetypeObjectId(const CrxDbObjectId& viewportId, bool& isOverride) const;
//    CDraft::ErrorStatus setLinetypeObjectId(const CrxDbObjectId& id, 
//                                          const CrxDbObjectId& viewportId);
//
//    CRxDb::LineWeight  lineWeight(const CrxDbObjectId& viewportId, bool& isOverride) const;
//    CDraft::ErrorStatus setLineWeight(CRxDb::LineWeight weight, 
//                                    const CrxDbObjectId& viewportId);
//
//    CxCHAR*            plotStyleName(const CrxDbObjectId& viewportId, bool& isOverride) const;
//    CrxDbObjectId      plotStyleNameId(const CrxDbObjectId& viewportId, bool& isOverride) const;
//    CDraft::ErrorStatus setPlotStyleName(const CxCHAR* newName, 
//                                       const CrxDbObjectId& viewportId);
//    CDraft::ErrorStatus setPlotStyleName(const CrxDbObjectId& newId, 
//                                       const CrxDbObjectId& viewportId);
//
//    CDraft::ErrorStatus removeColorOverride(const CrxDbObjectId& viewportId);
//    CDraft::ErrorStatus removeLinetypeOverride(const CrxDbObjectId& viewportId);
//    CDraft::ErrorStatus removeLineWeightOverride(const CrxDbObjectId& viewportId);
//    CDraft::ErrorStatus removePlotStyleOverride(const CrxDbObjectId& viewportId);
//    CDraft::ErrorStatus removeViewportOverrides(const CrxDbObjectId& viewportId);
//    CDraft::ErrorStatus removeAllOverrides();
//
//    bool              hasOverrides(const CrxDbObjectId& viewportId) const;
//    bool              hasAnyOverrides() const;
//
//    bool              isReconciled() const;
//    CDraft::ErrorStatus setIsReconciled(bool bReconcile = true);
//    static bool       isReconciled(const CrxDbObjectId& id);
	virtual CDraft::ErrorStatus getName(CxCHAR*& pName) const;
	virtual CDraft::ErrorStatus setName(const CxCHAR* pName);
};
//
//// Utility for changing Layer Table Records in the Current Drawing
//CDraft::ErrorStatus applyCurDwgLayerTableChanges();
//
//// CRxDbTextStyleTableRecord:
//
CRX_DEFINE_CLSID(B9BD09D2-0EAA-4FE7-9FF6-A23F19FE8954,CRxDbTextStyleTableRecord)
class CRXDB_API CRxDbTextStyleTableRecord: public  CRxDbSymbolTableRecord
{
public:
    CRX_DECLARE_DYNCREATE(CRxDbTextStyleTableRecord);

    CRxDbTextStyleTableRecord(ICxCrxObject *i_pCrxObject = NULL);
//    virtual ~CrxDbTextStyleTableRecord();
//
    typedef CRxDbTextStyleTable TableType;
//
//    CAXA::Boolean isShapeFile() const;
//    void setIsShapeFile(CAXA::Boolean shape);
//
    CAXA::Boolean isVertical() const;
//    void setIsVertical(CAXA::Boolean vertical);
//
    double textSize() const;
    CDraft::ErrorStatus setTextSize(double size);
//
//    double xScale() const;
//    CDraft::ErrorStatus setXScale(double xScale);
//
    double obliquingAngle() const;
    CDraft::ErrorStatus setObliquingAngle(double obliquingAngle);
//
//    CAXA::UInt8 flagBits() const;
//    void setFlagBits(CAXA::UInt8 flagBits);
//
//    double priorSize() const;
//    CDraft::ErrorStatus setPriorSize(double priorSize);

//     CDraft::ErrorStatus fileName(CxCHAR*& fileName) const;
//     CDraft::ErrorStatus fileName(const CxCHAR*& fileName) const;
//     CDraft::ErrorStatus setFileName(const CxCHAR* fileName);
// 
//     CDraft::ErrorStatus bigFontFileName(CxCHAR*& fileName) const;
//     CDraft::ErrorStatus bigFontFileName(const CxCHAR*& fileName) const;
//     CDraft::ErrorStatus setBigFontFileName(const CxCHAR* fileName);

    CDraft::ErrorStatus setFont(const CxCHAR* pTypeface, CAXA::Boolean bold, 
        CAXA::Boolean italic, int charset, int pitchAndFamily);
//     CDraft::ErrorStatus font   (CxCHAR*& pTypeface, CAXA::Boolean& bold, CAXA::Boolean& italic,
//                               int& charset, int& pitchAndFamily) const;
//    virtual CDraft::ErrorStatus getClassID(CLSID* pClsid) const;
	virtual CDraft::ErrorStatus getName(CxCHAR*& pName) const;
	virtual CDraft::ErrorStatus setName(const CxCHAR* pName);

	// Get/Set China Font
	CDraft::ErrorStatus setCFont( const CxCHAR* pCFontName);
	CDraft::ErrorStatus cfont( const CxCHAR*& pCFontName) const;

	// Get/Set English Font
	CDraft::ErrorStatus setEFont( const CxCHAR* pEFontName);
	CDraft::ErrorStatus efont( const CxCHAR*& pEFontName) const;

	//Get/Set China/West width factor
	double xScaleChina() const;
	CDraft::ErrorStatus setXScaleChina(double xScale);
	double xScaleWest() const;
	CDraft::ErrorStatus setXScaleWest(double xScale);

	//Get/Set char space factor
	double xIntFac() const;
	CDraft::ErrorStatus setXIntFac(double xIntFac);

	//Get/Set line space factor
	double yIntFac() const;
	CDraft::ErrorStatus setYIntFac(double yIntFac);	
};
//
CRX_DEFINE_CLSID(C8F1FF60-A882-4639-93CB-87921B4F5D0B,CRxDbLinetypeTableRecord)
class CRXDB_API CRxDbLinetypeTableRecord: public  CRxDbSymbolTableRecord
{
public:
    CRX_DECLARE_DYNCREATE(CRxDbLinetypeTableRecord);

    CRxDbLinetypeTableRecord(ICxCrxObject *i_pCrxObject = NULL);

    typedef CRxDbLinetypeTable TableType;

    CDraft::ErrorStatus comments(CxCHAR*& pString) const;
    CDraft::ErrorStatus comments(const CxCHAR*& pString) const;
    CDraft::ErrorStatus setComments(const CxCHAR* pString);

    CDraft::ErrorStatus asciiDescription(CxCHAR*& pString) const
                      { return comments(pString); }
    CDraft::ErrorStatus asciiDescription(const CxCHAR*& pString) const
                      { return comments(pString); }
    CDraft::ErrorStatus setAsciiDescription(const CxCHAR* pString)
                      { return setComments(pString); }

    double patternLength() const;
    void   setPatternLength(double patternLength);

    int    numDashes() const;
    void   setNumDashes(int count);

    double dashLengthAt(int index) const;
    void   setDashLengthAt(int index , double value);
//
//    CrxDbObjectId shapeStyleAt(int index) const;
//    void         setShapeStyleAt(int index, CrxDbObjectId id);
//
//    int    shapeNumberAt(int index) const;
//    void   setShapeNumberAt(int index, int shapeNumber);
//
//    CRxGeVector2d shapeOffsetAt(int index) const;
//    void         setShapeOffsetAt(int index, const CRxGeVector2d& offset);
//
//    double shapeScaleAt(int index) const;
//    void   setShapeScaleAt(int index, double scale);
//
//    bool isScaledToFit() const;
//    void           setIsScaledToFit(bool scaledToFit);
//
//    bool shapeIsUcsOrientedAt(int index) const;
//    void           setShapeIsUcsOrientedAt(int index, bool isUcsOriented);
//
//    double         shapeRotationAt(int index) const;
//    void           setShapeRotationAt(int index, double rotation);
//
//    CDraft::ErrorStatus textAt(int index, CxCHAR*& text) const;
//    CDraft::ErrorStatus textAt(int index, const CxCHAR*& text) const;
//    CDraft::ErrorStatus setTextAt(int index, const CxCHAR* text);
//
//    // Drawable API
//    //
//    CRxGiDrawable*     drawable();
//    CAXA::UInt32     setAttributes(CRxGiDrawableTraits* pTraits);
//    CAXA::Boolean    worldDraw(CRxGiWorldDraw* pWd);
//    void              viewportDraw(CRxGiViewportDraw* pVd);
//    void              setGsNode(AcGsNode* pNode);
//    AcGsNode*         gsNode() const;

	virtual CDraft::ErrorStatus getName(CxCHAR*& pName) const;
	virtual CDraft::ErrorStatus setName(const CxCHAR* pName);
};
//
//class CAXA_NO_VTABLE CRxDbAbstractViewTableRecord: public  CrxDbSymbolTableRecord
//{
//public:
//    CRX_DECLARE_DYNCREATE(CRxDbAbstractViewTableRecord);
//
//    CRxDbAbstractViewTableRecord();
//    virtual ~CRxDbAbstractViewTableRecord();
//
//    enum RenderMode {
//        k2DOptimized,
//        kWireframe,
//        kHiddenLine,
//        kFlatShaded,
//        kGouraudShaded,
//        kFlatShadedWithWireframe,
//        kGouraudShadedWithWireframe
//    };
//
//    CRxGePoint2d    centerPoint() const;
//    void           setCenterPoint(const CRxGePoint2d&);
//
//    double         height() const;
//    void           setHeight(double height);
//
//    double         width() const;
//    void           setWidth(double width);
//
//    CRxGePoint3d    target() const;
//    void           setTarget(const CRxGePoint3d& target);
//
//    CRxGeVector3d   viewDirection() const;
//    void           setViewDirection(const CRxGeVector3d& viewDirection);
//
//    double         viewTwist() const;
//    void           setViewTwist(double angle);
//
//    double         lensLength() const;
//    void           setLensLength(double length);
//
//    double         frontClipDistance() const;
//    void           setFrontClipDistance(double distance);
//
//    double         backClipDistance() const;
//    void           setBackClipDistance(double distance);
//
//    bool           perspectiveEnabled() const;
//    void           setPerspectiveEnabled(bool enabled);
//
//    bool           frontClipEnabled() const;
//    void           setFrontClipEnabled(bool enabled);
//
//    bool           backClipEnabled() const;
//    void           setBackClipEnabled(bool enabled);
//
//    bool           frontClipAtEye() const;
//    void           setFrontClipAtEye(bool atEye);
//
//    void           setRenderMode(RenderMode mode);
//    RenderMode     renderMode() const;
//
//    // Background
//    const CrxDbObjectId&  background() const;
//    CrxDbObjectId&       background();
//    CDraft::ErrorStatus   setBackground(const CrxDbObjectId& backgroundId);
//
//   // VisualStyle
//    CrxDbObjectId visualStyle() const;
//    CDraft::ErrorStatus   setVisualStyle(const CrxDbObjectId& visualStyleId);           
//
//    // Viewport Lighting
//    //
//    bool                isDefaultLightingOn() const;
//    CDraft::ErrorStatus   setDefaultLightingOn(bool on);
//    CRxGiViewportTraits::DefaultLightingType defaultLightingType() const;
//    CDraft::ErrorStatus   setDefaultLightingType(CRxGiViewportTraits::DefaultLightingType typ);
//
//    // Brightness controls the relative intensity of lights.
//    double              brightness() const;
//    CDraft::ErrorStatus   setBrightness(double);
//    // Contrast controls intensity of ambient light, relative to other lights.
//    double              contrast() const;
//    CDraft::ErrorStatus   setContrast(double);
//
//    CrxCmColor           ambientLightColor() const;
//    CDraft::ErrorStatus   setAmbientLightColor(const CrxCmColor& clr);
//
//    // A single sun (distant light) can be associated with each viewport.
//    CrxDbObjectId        sunId() const;
//    CDraft::ErrorStatus   setSun(CrxDbObjectId &retId, CrxDbObject *pSun);
//    CDraft::ErrorStatus   setSun(CrxDbObjectId &retId, CrxDbObject *pSun, bool eraseOldSun);
//
//    // Tone operator parameters
//    CDraft::ErrorStatus toneOperatorParameters(AcGiToneOperatorParameters& params) const;
//    CDraft::ErrorStatus setToneOperatorParameters(const AcGiToneOperatorParameters& params);
//
//    // UCS query methods.
//    //
//    CDraft::ErrorStatus getUcs            ( CRxGePoint3d& origin,
//                                          CRxGeVector3d& xAxis,
//                                          CRxGeVector3d& yAxis ) const;
//    bool              isUcsOrthographic ( CRxDb::OrthographicView& view ) const;
//    CrxDbObjectId      ucsName           () const;
//    double            elevation         () const;
//
//    // UCS set methods.
//    //
//    CDraft::ErrorStatus setUcs        ( const CRxGePoint3d& origin,
//                                      const CRxGeVector3d& xAxis,
//                                      const CRxGeVector3d& yAxis );
//    CDraft::ErrorStatus setUcs        ( CRxDb::OrthographicView view );
//    CDraft::ErrorStatus setUcs        ( const CrxDbObjectId& ucsId );
//    CDraft::ErrorStatus setUcsToWorld ();
//    CDraft::ErrorStatus setElevation  ( double elev );
// 
//    // Orthographic view methods.
//    //
//    bool              isViewOrthographic ( CRxDb::OrthographicView& view ) const;
//    CDraft::ErrorStatus setViewDirection   ( CRxDb::OrthographicView view );
//};
//
//class CRxDbViewTableRecord: public  CRxDbAbstractViewTableRecord
//{
//public:
//    CRX_DECLARE_DYNCREATE(CRxDbViewTableRecord);
//
//    CRxDbViewTableRecord();
//    virtual ~CRxDbViewTableRecord();
//
//    typedef CRxDbViewTable TableType;
//
//    CDraft::ErrorStatus setParametersFromViewport(CrxDbObjectId objId);
//
//    bool isPaperspaceView() const;
//    void setIsPaperspaceView(bool pspace);
//    
//    bool    isUcsAssociatedToView   () const;
//    CDraft::ErrorStatus disassociateUcsFromView ();
//
//    virtual CDraft::ErrorStatus getClassID(CLSID* pClsid) const;
//
//    CDraft::ErrorStatus getCategoryName(CxCHAR *& categoryName) const;
//    CDraft::ErrorStatus setCategoryName(const CxCHAR * categoryName);
//
//    CDraft::ErrorStatus getLayerState(CxCHAR*& layerStateName) const;
//    CDraft::ErrorStatus setLayerState(const CxCHAR *layerStateName);
// 
//    CDraft::ErrorStatus getLayout (CrxDbObjectId& layoutId) const;
//    CDraft::ErrorStatus setLayout(CrxDbObjectId layoutId);
//
//    bool              isViewAssociatedToViewport () const;
//    CDraft::ErrorStatus setViewAssociatedToViewport (bool bVPflag);
//
//    bool              isCameraPlottable () const;
//    CDraft::ErrorStatus setIsCameraPlottable (bool plottable);
//
//    // Live Section
//    CrxDbObjectId      liveSection() const;
//    CDraft::ErrorStatus setLiveSection(const CrxDbObjectId& liveSectionId);           
//   
//#ifdef _WINDOWS_
//    CDraft::ErrorStatus getThumbnail (BITMAPINFO*& thumbnail) const;
//    CDraft::ErrorStatus setThumbnail(const BITMAPINFO * thumbnail);
//#endif
//
//    // Camera methods
//    CrxDbObjectId      camera          () const;
//    CDraft::ErrorStatus setCamera(CrxDbObjectId cameraId);
//
//    // Annotation scaling methods
//    // Caller of this method will have to delete the CRxDbAnnotationScale object
//    // that is returned
//    CRxDbAnnotationScale* annotationScale() const;
//    CDraft::ErrorStatus setAnnotationScale(const CRxDbAnnotationScale* pScaleObj);
//
//    // A single sun (distant light) can be associated with each view.
//    CrxDbObjectId      sunId() const;
//    CDraft::ErrorStatus setSun(CrxDbObjectId &retId, CrxDbObject *pSun);
//    CDraft::ErrorStatus setSun(CrxDbObjectId &retId, CrxDbObject *pSun, bool eraseOldSun);
//};
//
CRX_DEFINE_CLSID(F284EAB1-3EE0-4B16-9B7A-9E10350567E2,CRxDbUCSTableRecord)
class CRXDB_API CRxDbUCSTableRecord: public  CRxDbSymbolTableRecord
{
public:
    CRX_DECLARE_DYNCREATE(CRxDbUCSTableRecord);

    CRxDbUCSTableRecord(ICxCrxObject *i_pCrxObject = NULL);
//    virtual ~CrxDbUCSTableRecord();
//
    typedef CRxDbUCSTable TableType;

    CRxGePoint3d  origin() const;
    void         setOrigin(const CRxGePoint3d& newOrigin);

    CRxGeVector3d xAxis() const;
    void         setXAxis(const CRxGeVector3d& xAxis);

    CRxGeVector3d yAxis() const;
    void         setYAxis(const CRxGeVector3d& yAxis);

  //  CRxGePoint3d       ucsBaseOrigin    ( CRxDb::OrthographicView view ) const;
  //  CDraft::ErrorStatus setUcsBaseOrigin ( const CRxGePoint3d& origin,
   //                                      CRxDb::OrthographicView view );
//    virtual CDraft::ErrorStatus getClassID(CLSID* pClsid) const;
};
//
//class CRxDbViewportTableRecord: public  CRxDbAbstractViewTableRecord
//{
//public:
//    CRX_DECLARE_DYNCREATE(CRxDbViewportTableRecord);
//
//    CRxDbViewportTableRecord();
//    virtual ~CRxDbViewportTableRecord();
//
//    typedef CRxDbViewportTable TableType;
//
//    CAXA::Int16   number()  const;
//
//    CRxGePoint2d    lowerLeftCorner() const;
//    void           setLowerLeftCorner(const CRxGePoint2d& pt);
//
//    CRxGePoint2d    upperRightCorner() const;
//    void           setUpperRightCorner(const CRxGePoint2d& pt);
//
//    bool           ucsFollowMode() const;
//    void           setUcsFollowMode(bool enabled);
//
//    CAXA::UInt16  circleSides() const;
//    void           setCircleSides(CAXA::UInt16 circleSides);
//
//    bool           fastZoomsEnabled() const { return true; }
//    void           setFastZoomsEnabled(bool enabled) { }
//
//    bool           iconEnabled() const;
//    void           setIconEnabled(bool enabled);
//
//    bool           iconAtOrigin() const;
//    void           setIconAtOrigin(bool atOrigin);
//
//    bool           gridEnabled() const;
//    void           setGridEnabled(bool enabled);
//
//    CRxGePoint2d    gridIncrements() const;
//    void           setGridIncrements(const CRxGePoint2d& base);
//
//    bool           snapEnabled() const;
//    void           setSnapEnabled(bool enabled);
//
//    bool           isometricSnapEnabled() const;
//    void           setIsometricSnapEnabled(bool enabled);
//
//    CAXA::Int16   snapPair() const;
//    void           setSnapPair(CAXA::Int16 pairType);
//
//    double         snapAngle() const;
//    void           setSnapAngle(double angle);
//
//    CRxGePoint2d    snapBase() const;
//    void           setSnapBase(const CRxGePoint2d& base);
//
//    CRxGePoint2d    snapIncrements() const;
//    void           setSnapIncrements(const CRxGePoint2d& base);
//
//    void           setGsView(CRxGsView* pView);
//    CRxGsView*      gsView() const;
//
//    bool           isUcsSavedWithViewport () const;
//    void           setUcsPerViewport ( bool ucsvp );
//
//    // GridDisplay
//    bool           isGridBoundToLimits() const;
//    void           setGridBoundToLimits(bool enabled);
//                  
//    bool           isGridAdaptive() const;
//    void           setGridAdaptive(bool enabled);
//                  
//    bool           isGridSubdivisionRestricted() const;
//    void           setGridSubdivisionRestricted(bool enabled);
//                  
//    bool           isGridFollow() const;
//    void           setGridFollow(bool enabled);
//
//    CAXA::Int16   gridMajor() const;
//    void           setGridMajor(CAXA::Int16 value);
//
//    // Background
//    CDraft::ErrorStatus   setBackground(const CrxDbObjectId& backgroundId);
//    CrxDbObjectId        previousBackground(CRxGiDrawable::DrawableType type
//                                           = CRxGiDrawable::kGeometry) const;
//    CDraft::ErrorStatus   setPreviousBackground(CrxDbObjectId backgroundId,
//                                              CRxGiDrawable::DrawableType type
//                                              = CRxGiDrawable::kGeometry);
//    CDraft::ErrorStatus   setPreviousBackground(CrxDbObjectId backgroundId,
//                                              CRxGiDrawable::DrawableType type,
//                                              bool bForcedSwitch);
//    bool                previousBackgroundForcedSwitch (void) const;
//    
//    // Drawable API
//    //
//    CRxGiDrawable*  drawable();
//    CAXA::UInt32  setAttributes(CRxGiDrawableTraits* pTraits);
//    CAXA::Boolean worldDraw(CRxGiWorldDraw* pWd);     
//    void           setGsNode(CRxGsNode* pNode);
//    CRxGsNode*      gsNode() const;
//
//    virtual CDraft::ErrorStatus getClassID(CLSID* pClsid) const;
//};
//
CRX_DEFINE_CLSID(8C80CFF9-27B6-428E-9A3D-5EAF4E1CBA51,CRxDbRegAppTableRecord)
class CRXDB_API CRxDbRegAppTableRecord: public  CRxDbSymbolTableRecord
{
public:
    CRX_DECLARE_DYNCREATE(CRxDbRegAppTableRecord);
//
    CRxDbRegAppTableRecord(ICxCrxObject *i_pCrxObject = NULL);
//    virtual ~CrxDbRegAppTableRecord();
//
    typedef CRxDbRegAppTable TableType;
//
//    virtual CDraft::ErrorStatus getClassID(CLSID* pClsid) const;
};
//
CRX_DEFINE_CLSID(5CCBF74A-358C-4FD1-B99A-7185DD522D7D,CRxDbDimStyleTableRecord)
class CRXDB_API CRxDbDimStyleTableRecord: public  CRxDbSymbolTableRecord
{
public:
    CRX_DECLARE_DYNCREATE(CRxDbDimStyleTableRecord);

    CRxDbDimStyleTableRecord(ICxCrxObject *i_pCrxObject = NULL);
//    virtual ~CrxDbDimStyleTableRecord();
//
    typedef CRxDbDimStyleTable TableType;
//
//    // Dimension variable api:
//    //
	
    #undef DBDIMVAR_H         // force the file to get read again
    #include "dbdimvar.h"
//
//
//    CrxDbObjectId      arrowId(CRxDb::DimArrowFlags whichArrow) const;
//
//
//    // DEPRECATED METHODS!
//    // These are supported but will be removed in future releases:
//    //
//    CDraft::ErrorStatus getDimpost(CxCHAR*& pOutput) const;
//    CDraft::ErrorStatus getDimapost(CxCHAR*& pOutput) const;
//    CDraft::ErrorStatus getDimblk(CxCHAR*& pOutput) const;
//    CDraft::ErrorStatus getDimblk1(CxCHAR*& pOutput) const;
//    CDraft::ErrorStatus getDimblk2(CxCHAR*& pOutput) const;
//
//    int dimfit() const;
//    int dimunit() const;
//
//    CDraft::ErrorStatus setDimfit(int fit);
//    CDraft::ErrorStatus setDimunit(int unit);
//    //
//    // end DEPRECATED METHODS!
//
//    virtual CDraft::ErrorStatus getClassID(CLSID* pClsid) const;
//    bool isModifiedForRecompute() const;    
	virtual CDraft::ErrorStatus getName(CxCHAR*& pName) const;
	virtual CDraft::ErrorStatus setName(const CxCHAR* pName);
};


class CRxDbRoughStyleTableRecord;
class CRxDbRoughStyleTableIterator;

CRX_DEFINE_CLSID(2EACF156-507A-45D7-8AD9-618B08D63DBC,CRxDbRoughStyleTable)
class CRXDB_API CRxDbRoughStyleTable: public CRxDbSymbolTable
{
public:
	CRX_DECLARE_DYNCREATE(CRxDbRoughStyleTable);
	CRxDbRoughStyleTable(ICxCrxObject *i_pCrxObject=NULL);
	
	typedef CRxDbRoughStyleTableRecord RecordType;
	
	CDraft::ErrorStatus   getAt(const CxCHAR* entryName,
								CRxDbRoughStyleTableRecord*& pRec,
								CRxDb::OpenMode openMode,
								bool openErasedRec = false) const;
	CDraft::ErrorStatus   getAt(const CxCHAR* entryName,
								CRxDbObjectId& recordId,
								bool getErasedRec = false) const;
	
	virtual CRxObject* clone() const;
};

class CRXDB_API CRxDbRoughStyleTableIterator : public CRxDbSymbolTableIterator
{
public:
	CDraft::ErrorStatus getRecord(CRxDbRoughStyleTableRecord*& pRecord,
		CRxDb::OpenMode openMode, bool openErasedRec = false) const;
	CDraft::ErrorStatus seek(CRxDbObjectId id);
	CDraft::ErrorStatus seek(const CRxDbRoughStyleTableRecord* pRecord);

protected:
	CRxDbRoughStyleTableIterator();
	friend class CRxDbRoughStyleTable;
};

CRX_DEFINE_CLSID(F90A6C40-FA1D-438C-B899-A98A2D6FD6B7,CRxDbRoughStyleTableRecord)
class CRXDB_API CRxDbRoughStyleTableRecord: public  CRxDbSymbolTableRecord
{
public:
	CRX_DECLARE_DYNCREATE(CRxDbRoughStyleTableRecord);

	CRxDbRoughStyleTableRecord(ICxCrxObject *i_pCrxObject = NULL);
	
	typedef CRxDbRoughStyleTable TableType;
	virtual CDraft::ErrorStatus getName(CxCHAR*& pName) const;
	virtual CDraft::ErrorStatus setName(const CxCHAR* pName);

};

class CRxDbDatumStyleTableRecord;
class CRxDbDatumStyleTableIterator;

CRX_DEFINE_CLSID(2EACF156-507A-45D7-8AD9-618B08D63DBC,CRxDbDatumStyleTable)
class CRXDB_API CRxDbDatumStyleTable: public CRxDbSymbolTable
{
public:
	CRX_DECLARE_DYNCREATE(CRxDbDatumStyleTable);
	CRxDbDatumStyleTable(ICxCrxObject *i_pCrxObject=NULL);
	
	typedef CRxDbDatumStyleTableRecord RecordType;
	//
	CDraft::ErrorStatus   getAt(const CxCHAR* entryName,
								CRxDbDatumStyleTableRecord*& pRec,
								CRxDb::OpenMode openMode,
								bool openErasedRec = false) const;
	CDraft::ErrorStatus   getAt(const CxCHAR* entryName,
								CRxDbObjectId& recordId,
								bool getErasedRec = false) const;
	
	virtual CRxObject* clone() const;
};

class CRXDB_API CRxDbDatumStyleTableIterator : public CRxDbSymbolTableIterator
{
public:
	CDraft::ErrorStatus getRecord(CRxDbDatumStyleTableRecord*& pRecord,
		CRxDb::OpenMode openMode, bool openErasedRec = false) const;
	CDraft::ErrorStatus seek(CRxDbObjectId id);
	CDraft::ErrorStatus seek(const CRxDbDatumStyleTableRecord* pRecord);

protected:
	CRxDbDatumStyleTableIterator();
	friend class CRxDbDatumStyleTable;
};

CRX_DEFINE_CLSID(96FEFF0F-CAC9-4FCE-AC15-D80DC8BFB8DE,CRxDbDatumStyleTableRecord)
class CRXDB_API CRxDbDatumStyleTableRecord: public  CRxDbSymbolTableRecord
{
public:
	CRX_DECLARE_DYNCREATE(CRxDbDatumStyleTableRecord);

	CRxDbDatumStyleTableRecord(ICxCrxObject *i_pCrxObject = NULL);
	
	typedef CRxDbDatumStyleTable TableType;
	virtual CDraft::ErrorStatus getName(CxCHAR*& pName) const;
	virtual CDraft::ErrorStatus setName(const CxCHAR* pName);

};

class CRxDbGeoTolStyleTableRecord;
class CRxDbGeoTolStyleTableIterator;

CRX_DEFINE_CLSID(2EACF156-507A-45D7-8AD9-618B08D63DBC,CRxDbGeoTolStyleTable)
class CRXDB_API CRxDbGeoTolStyleTable: public CRxDbSymbolTable
{
public:
	CRX_DECLARE_DYNCREATE(CRxDbGeoTolStyleTable);
	CRxDbGeoTolStyleTable(ICxCrxObject *i_pCrxObject=NULL);

	typedef CRxDbGeoTolStyleTableRecord RecordType;
	//
	CDraft::ErrorStatus   getAt(const CxCHAR* entryName,
		CRxDbGeoTolStyleTableRecord*& pRec,
		CRxDb::OpenMode openMode,
		bool openErasedRec = false) const;
	CDraft::ErrorStatus   getAt(const CxCHAR* entryName,
		CRxDbObjectId& recordId,
		bool getErasedRec = false) const;

	virtual CRxObject* clone() const;
};

class CRXDB_API CRxDbGeoTolStyleTableIterator : public CRxDbSymbolTableIterator
{
public:
	CDraft::ErrorStatus getRecord(CRxDbGeoTolStyleTableRecord*& pRecord,
		CRxDb::OpenMode openMode, bool openErasedRec = false) const;
	CDraft::ErrorStatus seek(CRxDbObjectId id);
	CDraft::ErrorStatus seek(const CRxDbGeoTolStyleTableRecord* pRecord);

protected:
	CRxDbGeoTolStyleTableIterator();
	friend class CRxDbGeoTolStyleTable;
};

CRX_DEFINE_CLSID(D597A38C-016F-425E-9C4D-A7DC77A8D3A6,CRxDbGeoTolStyleTableRecord)
class CRXDB_API CRxDbGeoTolStyleTableRecord: public  CRxDbSymbolTableRecord
{
public:
	CRX_DECLARE_DYNCREATE(CRxDbGeoTolStyleTableRecord);

	CRxDbGeoTolStyleTableRecord(ICxCrxObject *i_pCrxObject = NULL);

	typedef CRxDbGeoTolStyleTable TableType;
	virtual CDraft::ErrorStatus getName(CxCHAR*& pName) const;
	virtual CDraft::ErrorStatus setName(const CxCHAR* pName);

};


class CRxDbWeldStyleTableRecord;
class CRxDbWeldStyleTableIterator;

CRX_DEFINE_CLSID(2EACF156-507A-45D7-8AD9-618B08D63DBC,CRxDbWeldStyleTable)
class CRXDB_API CRxDbWeldStyleTable: public CRxDbSymbolTable
{
public:
	CRX_DECLARE_DYNCREATE(CRxDbWeldStyleTable);
	CRxDbWeldStyleTable(ICxCrxObject *i_pCrxObject=NULL);

	typedef CRxDbWeldStyleTableRecord RecordType;
	//
	CDraft::ErrorStatus   getAt(const CxCHAR* entryName,
		CRxDbWeldStyleTableRecord*& pRec,
		CRxDb::OpenMode openMode,
		bool openErasedRec = false) const;
	CDraft::ErrorStatus   getAt(const CxCHAR* entryName,
		CRxDbObjectId& recordId,
		bool getErasedRec = false) const;

	virtual CRxObject* clone() const;
};

class CRXDB_API CRxDbWeldStyleTableIterator : public CRxDbSymbolTableIterator
{
public:
	CDraft::ErrorStatus getRecord(CRxDbWeldStyleTableRecord*& pRecord,
		CRxDb::OpenMode openMode, bool openErasedRec = false) const;
	CDraft::ErrorStatus seek(CRxDbObjectId id);
	CDraft::ErrorStatus seek(const CRxDbWeldStyleTableRecord* pRecord);

protected:
	CRxDbWeldStyleTableIterator();
	friend class CRxDbWeldStyleTable;
};

CRX_DEFINE_CLSID(07E0B92B-F65B-400A-A364-58BC8EAB1EFE,CRxDbWeldStyleTableRecord)
class CRXDB_API CRxDbWeldStyleTableRecord: public  CRxDbSymbolTableRecord
{
public:
	CRX_DECLARE_DYNCREATE(CRxDbWeldStyleTableRecord);

	CRxDbWeldStyleTableRecord(ICxCrxObject *i_pCrxObject = NULL);

	typedef CRxDbWeldStyleTable TableType;
	virtual CDraft::ErrorStatus getName(CxCHAR*& pName) const;
	virtual CDraft::ErrorStatus setName(const CxCHAR* pName);

};

class CRxDbCutsStyleTableRecord;
class CRxDbCutsStyleTableIterator;

CRX_DEFINE_CLSID(2EACF156-507A-45D7-8AD9-618B08D63DBC,CRxDbCutsStyleTable)
class CRXDB_API CRxDbCutsStyleTable: public CRxDbSymbolTable
{
public:
	CRX_DECLARE_DYNCREATE(CRxDbCutsStyleTable);
	CRxDbCutsStyleTable(ICxCrxObject *i_pCrxObject=NULL);

	typedef CRxDbCutsStyleTableRecord RecordType;
	//
	CDraft::ErrorStatus   getAt(const CxCHAR* entryName,
		CRxDbCutsStyleTableRecord*& pRec,
		CRxDb::OpenMode openMode,
		bool openErasedRec = false) const;
	CDraft::ErrorStatus   getAt(const CxCHAR* entryName,
		CRxDbObjectId& recordId,
		bool getErasedRec = false) const;

	virtual CRxObject* clone() const;
};

class CRXDB_API CRxDbCutsStyleTableIterator : public CRxDbSymbolTableIterator
{
public:
	CDraft::ErrorStatus getRecord(CRxDbCutsStyleTableRecord*& pRecord,
		CRxDb::OpenMode openMode, bool openErasedRec = false) const;
	CDraft::ErrorStatus seek(CRxDbObjectId id);
	CDraft::ErrorStatus seek(const CRxDbCutsStyleTableRecord* pRecord);

protected:
	CRxDbCutsStyleTableIterator();
	friend class CRxDbCutsStyleTable;
};

CRX_DEFINE_CLSID(A88CBE34-ACB2-47F4-ABAE-FC7E078ADB93,CRxDbCutsStyleTableRecord)
class CRXDB_API CRxDbCutsStyleTableRecord: public  CRxDbSymbolTableRecord
{
public:
	CRX_DECLARE_DYNCREATE(CRxDbCutsStyleTableRecord);

	CRxDbCutsStyleTableRecord(ICxCrxObject *i_pCrxObject = NULL);

	typedef CRxDbCutsStyleTable TableType;
	virtual CDraft::ErrorStatus getName(CxCHAR*& pName) const;
	virtual CDraft::ErrorStatus setName(const CxCHAR* pName);

};

class CRXDB_CLASS CRxAttCollInfoObject
{
public:
	CRxAttCollInfoObject(){};
	~CRxAttCollInfoObject(){};
public:
	virtual void init(){};
	virtual int getAttributesCount(){return 0;};
	virtual void getAttributeName(CxCHAR*& pAttName,int iIndex){};
	virtual void getAttributeValue(CxCHAR*& pAttValue,const CxCHAR* pAttName){};
	virtual void setAttributeValue(const CxCHAR* pAttValue,int iIndex){};
};

class CRXDB_CLASS CRxTableInfoObject
{
public:
	CRxTableInfoObject(){};
	~CRxTableInfoObject(){};

public:
	virtual void init(){};
	virtual int getRowCount(){return 0;};
	virtual int getColCount(){return 0;};
	virtual void getBomHeaderAt(int iColIndex,CxCHAR*& pHeader){};
	virtual void getBomItemAt(int iRowIndex,int iColIndex,CxCHAR*& pItem){};
	virtual void setBomItemAt(int iRowIndex,int iColIndex,const CxCHAR*  pItem){};  //–ﬁ∏ƒ
	virtual int addBomRow(){return 0;};                                             //Ã˙ÿ”(ΩˆœﬁNEBŒƒº˛¿‡–Õ) 
	virtual void delBomRowAt(int iRowIndex){};                                      //…æ≥˝(ΩˆœﬁNEBŒƒº˛¿‡–Õ)
};

class CRxDbPaperTableRecord;
CRX_DEFINE_CLSID(611180B4-0E2D-4848-A63E-BACB8A983D19,CRxDbPaperTable)//8B7C3D5A-D1DF-47bf-A16F-E8B028F386C9
class CRXDB_CLASS CRxDbPaperTable: public CRxDbSymbolTable
{
public:
	CRX_DECLARE_DYNCREATE(CRxDbPaperTable);
	CRxDbPaperTable(ICxCrxObject *i_pCrxObject = NULL);
	typedef CRxDbPaperTableRecord RecordType;

	CDraft::ErrorStatus getAt (const CxCHAR* entryName,CRxDbPaperTableRecord*& pRec,CRxDb::OpenMode openMode,bool openErasedRec = false) const;
	CDraft::ErrorStatus getAt (const CxCHAR* entryName,CRxDbObjectId& recordId,bool getErasedRec = false) const;
	bool              has   (const CxCHAR* name) const;
	bool              has   (CRxDbObjectId id) const;

	int getPaperCount();
	CDraft::ErrorStatus getPaperNameByIndex(int iIndex,CxCHAR*& pName);

	CRxDbObjectId CurrentPaperId();
	CRxDbPaperTableRecord* CurrentPaper();
	CDraft::ErrorStatus setCurrentPaperId(CRxDbObjectId pRecordId);
	CDraft::ErrorStatus setCurrentPaper(CRxDbPaperTableRecord* pRecord);

	CDraft::ErrorStatus add   (CRxDbPaperTableRecord* pRecord);
	CDraft::ErrorStatus add   (CRxDbObjectId& recordId, CRxDbPaperTableRecord* pRecord);

	virtual CRxObject* clone() const;
};

CRX_DEFINE_CLSID(979F2FD6-CA62-42B8-9CB8-D47716DD1DD7,CRxDbPaperTableRecord)//7176EFFC-529A-463c-826C-9187ECB18E02
class CRXDB_API CRxDbPaperTableRecord: public   CRxDbBlockTableRecord
{
public:
	CRX_DECLARE_DYNCREATE(CRxDbPaperTableRecord);

	CRxDbPaperTableRecord(ICxCrxObject *i_pCrxObject = NULL);
	~CRxDbPaperTableRecord();

	typedef CRxDbPaperTable TableType;

	//ƒ£∞ÅE
	void setTemplateFile(const CxCHAR* pFilePath,CDraft::Template_For_PaperInfo TempleType);

	//Õº÷Ω∑˘√Ê–≈œ¢
	void getPaperSize(DOUBLE& dPaperWidth,DOUBLE& dPaperHeight);

	void getPaperScale(DOUBLE& dPaperScale);
	void setPaperScale(DOUBLE dPaperScale);

	void getPaperDirection(CDraft::Paper_Direction& eDir);
	void setPaperDirection(CDraft::Paper_Direction eDir);

	void getPaperLongerQuot(LONG& lLongQuot);
	void setPaperLongerQuot(LONG lLongQuot);

	void getPaperSizeDescription(CDraft::PaperSizeDescription& eSizeDescription);
	void setPaperSizeDescription(CDraft::PaperSizeDescription eSizeDescription);

	void getIsUpdateDimAndTxtByScale(BOOL& bIsUpdateDT);
	void setIsUpdateDimAndTxtByScale(BOOL bIsUpdateDT);

	//ÕºøÚ°¢±ÅE‚¿∏°¢√˜œ∏±ÅE
	void getFrameInfo(CRxAttCollInfoObject** i_pCrxFrameInfoObj);
	CDraft::ErrorStatus setFrameInfo(const CRxAttCollInfoObject* pCrxFrameInfoObj);

	void getTitleInfo(CRxAttCollInfoObject** i_pCrxTitleInfoObj);
	CDraft::ErrorStatus setTitleInfo(const CRxAttCollInfoObject* pCrxTitleInfoObj);
	void getTitleAttributeDefineByName(const CxCHAR* cAttributeName,CRxDbAttributeDefinition* pAttributeDefine);
	void setTitleAttributeDefineByName(const CxCHAR* cAttributeName,CRxDbAttributeDefinition& CrxAttributeDefine);

	void getParaTableInfoAt(int iIndex,CRxAttCollInfoObject** i_pCrxParaTblInfoObj);
	CDraft::ErrorStatus setParaTableInfoAt(int iIndex,const CRxAttCollInfoObject* pCrxParaTblInfoObj);
	int getParaTableCount();

	void getBomInfo(CRxTableInfoObject** i_pBomTableInfoObj);
	CDraft::ErrorStatus setBomInfo(const CRxTableInfoObject* pCrxBomTableInfoObj);

	CDraft::ErrorStatus setFrameByFile(const CxCHAR* cfmFilePath);
	CDraft::ErrorStatus setTitleByFile(const CxCHAR* chdFilePath);
	CDraft::ErrorStatus setParaTableByFile(CRxGePoint3d& ptLoc,const CxCHAR* cptFilePath);

	//–Ú∫≈
	CDraft::ErrorStatus genPartNoByCurrentStyle(const CxCHAR* cPartnoTxt,CRxGePoint3d& ptStart,CRxGePoint3d& ptTurning);

	void ReleaseAttCollInfoObject(CRxAttCollInfoObject* pAttCollInfoObj);
	void ReleaseTableInfoObject(CRxTableInfoObject* pTableInfoObj);

public:
	BOOL m_bHasChanged;
	CDraft::Template_For_PaperInfo m_TempleType;

private:
	BOOL m_bGotPaper;
	BOOL m_bGotPaperInfo;
	int m_iParaTableCount;
	DOUBLE m_dPaperScale;

	void getCurrentPaper();
	void getCurrentPaperInfo();
	void getTemplateFileInfo(const CxCHAR* cFilePath);
};

class CRxDbLeaderStyleTableRecord;
class CRxDbLeaderStyleTableIterator;

CRX_DEFINE_CLSID(2EACF156-507A-45D7-8AD9-618B08D63DBC,CRxDbLeaderStyleTable)
class CRXDB_API CRxDbLeaderStyleTable: public CRxDbSymbolTable
{
public:
	CRX_DECLARE_DYNCREATE(CRxDbLeaderStyleTable);
	CRxDbLeaderStyleTable(ICxCrxObject *i_pCrxObject=NULL);

	typedef CRxDbLeaderStyleTableRecord RecordType;
	//
	CDraft::ErrorStatus   getAt(const CxCHAR* entryName,
		CRxDbLeaderStyleTableRecord*& pRec,
		CRxDb::OpenMode openMode,
		bool openErasedRec = false) const;
	CDraft::ErrorStatus   getAt(const CxCHAR* entryName,
		CRxDbObjectId& recordId,
		bool getErasedRec = false) const;

	virtual CRxObject* clone() const;
};

class CRXDB_API CRxDbLeaderStyleTableIterator : public CRxDbSymbolTableIterator
{
public:
	CDraft::ErrorStatus getRecord(CRxDbLeaderStyleTableRecord*& pRecord,
		CRxDb::OpenMode openMode, bool openErasedRec = false) const;
	CDraft::ErrorStatus seek(CRxDbObjectId id);
	CDraft::ErrorStatus seek(const CRxDbLeaderStyleTableRecord* pRecord);

protected:
	CRxDbLeaderStyleTableIterator();
	friend class CRxDbLeaderStyleTable;
};

CRX_DEFINE_CLSID(CF537287-481B-4A61-9CA5-6D420816AE17,CRxDbLeaderStyleTableRecord)
class CRXDB_API CRxDbLeaderStyleTableRecord: public  CRxDbSymbolTableRecord
{
public:
	CRX_DECLARE_DYNCREATE(CRxDbLeaderStyleTableRecord);

	CRxDbLeaderStyleTableRecord(ICxCrxObject *i_pCrxObject = NULL);

	typedef CRxDbLeaderStyleTable TableType;
	virtual CDraft::ErrorStatus getName(CxCHAR*& pName) const;
	virtual CDraft::ErrorStatus setName(const CxCHAR* pName);

};


#pragma pack(pop)

#endif
