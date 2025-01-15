#ifndef CRX_DBIDMAP_H
#define CRX_DBIDMAP_H 1
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
// DESCRIPTION:  Mapping class for object id's.

#include "crxdb.h"
#include "rxobject.h"

#pragma pack (push, 8)

class CRxDbDatabase;

class CRXDB_CLASS CRxDbIdPair
{
public:
    CRxDbIdPair();
    CRxDbIdPair(const CRxDbIdPair&);
    CRxDbIdPair(CRxDbObjectId key, CRxDbObjectId value,
               bool isCloned,
               bool isPrimary = false,
               bool isOwnerXlated = true);

    CRxDbObjectId   key() const;
    CRxDbObjectId   value() const;
    bool           isCloned() const;
    bool           isPrimary() const;
    bool           isOwnerXlated() const;

    void 	   setKey(CRxDbObjectId);
    void	   setValue(CRxDbObjectId);
    void	   setIsCloned(bool isCloned);
    void	   setIsPrimary(bool isPrimary);
    void	   setIsOwnerXlated(bool isOwnerXlated);

private:
    CRxDbObjectId  mKey;
    CRxDbObjectId  mValue;
    bool           mIsCloned : 1;
    bool           mIsPrimary : 1;
    bool           mIsOwnerXlated : 1;
};

class CRxDbIdMappingIter;
class CRxDbImpIdMapping;
class CRxDbImpIdMappingIter;

CRX_DEFINE_NULL_CLSID(CRxDbIdMapping)
class CRXDB_CLASS CRxDbIdMapping: public  CRxObject
{
public:
    CRxDbIdMapping();
    virtual ~CRxDbIdMapping();
    CRX_DECLARE_DYNAMIC(CRxDbIdMapping);

    virtual CDraft::ErrorStatus		assign(const CRxDbIdPair&);
    virtual bool          		compute(CRxDbIdPair&) const;
    virtual bool                        change(const CRxDbIdPair&);
    virtual bool              		del(CRxDbObjectId key);

	    CDraft::ErrorStatus   destDb(CRxDbDatabase*& db) const;
	    CDraft::ErrorStatus   setDestDb(CRxDbDatabase* db);
	    CDraft::ErrorStatus   origDb(CRxDbDatabase*& db) const;

	    CRxDb::DeepCloneType deepCloneContext() const;
        CRxDb::DuplicateRecordCloning duplicateRecordCloning() const;

    virtual CDraft::ErrorStatus   copyFrom(const CRxObject* other);

private:
    friend class CRxDbSystemInternals;
    friend class AcDbImpIdMappingIter;
    CRxDbIdMapping(const CRxDbIdMapping&);
    CRxDbIdMapping& operator= (const CRxDbIdMapping&);
    CRxDbImpIdMapping* mpImp;
};

CRX_DEFINE_NULL_CLSID(CRxDbIdMappingIter)
class CRXDB_CLASS CRxDbIdMappingIter: public  CRxObject
{
public:
    CRX_DECLARE_DYNAMIC(CRxDbIdMappingIter);
    CRxDbIdMappingIter(const CRxDbIdMapping&);
    virtual ~CRxDbIdMappingIter();

    virtual CDraft::ErrorStatus	iterateOn(const CRxDbIdMapping&);

    virtual void		start();
    virtual bool           	getMap(CRxDbIdPair&);
    virtual bool           	next();
    virtual bool          	done();

private:
    friend class		CRxDbSystemInternals;
    CRxDbImpIdMappingIter*	mpImp;
};

inline
CRxDbObjectId CRxDbIdPair::key() const
{ return mKey; }

inline
CRxDbObjectId CRxDbIdPair::value() const
{ return mValue; }

inline
bool CRxDbIdPair::isCloned() const
{ return mIsCloned; }

inline
bool CRxDbIdPair::isPrimary() const
{ return mIsPrimary; }

inline
bool CRxDbIdPair::isOwnerXlated() const
{ return mIsOwnerXlated; }

inline
void CRxDbIdPair::setKey(CRxDbObjectId key)
{ mKey = key; }

inline
void CRxDbIdPair::setValue(CRxDbObjectId value)
{ mValue = value; }

inline
void CRxDbIdPair::setIsCloned(bool isCloned)
{ mIsCloned = isCloned; }

inline
void CRxDbIdPair::setIsPrimary(bool isPrimary)
{ mIsPrimary = isPrimary; }

inline
void CRxDbIdPair::setIsOwnerXlated(bool isOwnerXlated)
{ mIsOwnerXlated = isOwnerXlated; }

#pragma pack (pop)

#endif

