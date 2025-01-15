#ifndef CRX_DBDICT_H
#define CRX_DBDICT_H

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#include "dbmain.h"
#include "dbxrecrd.h"

#pragma pack(push, 8)

class CRxDbImpDictionary;
class CRxString;

//CRX_DEFINE_NULL_CLSID(CRxDbDictionaryIterator)
class CRXDB_API CRxDbDictionaryIterator: public CRxObject
//
// This class allows one to sequentially retrieve the objects in
// the dictionary, and keeps track of what the last object retrieved was.
//
// It is similar to CrxRxDictionary Iterator, except the casting
// of returned elements is stronger, and it has a member which
// returns the status of the entry member when the attempt to
// open it was made.  If the status is CDraft::ErrorStatus eOk, then
// CRxDbDictionaryIterator::getValue() will return a non-null
// pointer, otherwise not.
//
{
public:
	//CRX_DECLARE_DYNAMIC(CRxDbDictionaryIterator);
    virtual ~CRxDbDictionaryIterator() {}

    virtual const CxCHAR*      name       () const = 0;

    virtual CDraft::ErrorStatus getObject  (CRxDbObject*&   pObject,
                                          CRxDb::OpenMode mode) = 0;
    virtual CRxDbObjectId      objectId   () const = 0;

    virtual bool              done       () const = 0;
    virtual bool              next       () = 0;
    virtual bool              setPosition(CRxDbObjectId objId) = 0;

protected:
    CRxDbDictionaryIterator() {}
};

CRX_DEFINE_CLSID(7E69E4BC-7E0C-4756-B841-F2D6711AD5BB, CRxDbDictionary)
class CRXDB_API CRxDbDictionary: public CRxDbObject
{
public:
    CRX_DECLARE_DYNCREATE(CRxDbDictionary);
    CRxDbDictionary(ICxCrxObject *i_pCrxObject = NULL);
    //virtual ~CrxDbDictionary();

    // Get an entry by name.
    //
    CDraft::ErrorStatus getAt(const CxCHAR*   entryName,
                            CRxDbObject*&   entryObj,
                            CRxDb::OpenMode mode) const;
    CDraft::ErrorStatus getAt(const CxCHAR*   entryName,
                            CRxDbObjectId&  entryObj) const;

    // Find name corresponding to object id.
    //
    CDraft::ErrorStatus nameAt(CRxDbObjectId objId,
                             CxCHAR*&      name) const;
   // CDraft::ErrorStatus nameAt(CrxDbObjectId objId,
      //                       CRxString &   name) const;
 
    // Query contents of dictionary
    //
    bool              has       (const CxCHAR*  entryName) const;
    bool              has       (CRxDbObjectId objId) const;
    CAXA::UInt32     numEntries() const;

    // Remove entries.
    //
    CDraft::ErrorStatus remove(const CxCHAR *  key);
    CDraft::ErrorStatus remove(const CxCHAR *  key,
                             CRxDbObjectId& returnId);
    CDraft::ErrorStatus remove(CRxDbObjectId  objId);

    // Reset an entry.
    //
    bool              setName(const CxCHAR*   oldName,
                              const CxCHAR*   newName);
    CDraft::ErrorStatus setAt  (const CxCHAR*   srchKey,
                              CRxDbObject*   newValue,
                              CRxDbObjectId& retObjId);

    // Test/Set treatment of elements.
    //
 //   bool              isTreatElementsAsHard () const;
  //  void              setTreatElementsAsHard(bool doIt);

    // Get an iterator for this dictionary.
    //
    CRxDbDictionaryIterator* newIterator() const;

    // CrxDbObject Protocol
    //
 //   virtual CDraft::ErrorStatus subErase     (CAXA::Boolean pErasing
 //                                               = CAXA::kTrue);
   // virtual CDraft::ErrorStatus dwgInFields  (CRxDbDwgFiler* pFiler);
 //   virtual CDraft::ErrorStatus dwgOutFields (CRxDbDwgFiler* pFiler) const;
 //   virtual CDraft::ErrorStatus dxfInFields  (CRxDbDxfFiler* pFiler);
 //   virtual CDraft::ErrorStatus dxfOutFields (CRxDbDxfFiler* pFiler) const;

  //  virtual CRxDb::DuplicateRecordCloning mergeStyle() const;
  //  virtual void  setMergeStyle(CRxDb::DuplicateRecordCloning style);

    // Support for persistant reactor to annotation.
    //
  //  virtual void goodbye(const CrxDbObject* pObject);
  //  virtual void erased (const CrxDbObject* pObject,
    //                     CAXA::Boolean pErasing = CAXA::kTrue);

    // Support for saving to previous releases' formats.
    //
    //virtual CDraft::ErrorStatus decomposeForSave(
   //                               CRxDb::AcDbDwgVersion ver,
   ////                               CrxDbObject*&         replaceObj,
    //                              CrxDbObjectId&        replaceId,
    //                              CAXA::Boolean&      exchangeXData);

   // virtual CDraft::ErrorStatus getClassID(CLSID* pClsid) const;
};

#pragma pack(pop)

#endif
