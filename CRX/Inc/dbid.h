//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

// DESCRIPTION:
//
// This file contains lightweight id classes distinguishing between
// different types of object id's. A distinction is made between an
// owned object and a reference or "pointer to" an object, as well as
// whether the relationship protects the object from purge (hard/soft).
//
// Hard-owner:  
//
// An owned object protected from purge. A layer symbol table and
// layer 0 is an example of a hard-owner relationship.
//
// Soft-owner:
//
// An owned object not protected from purge. All symbol tables own
// their records, but that relationship does not usually protect
// the records from purge.
//
// Hard-pointer:
//
// A reference to an object that is not owned, but protected from
// purge. An entity, for example, does not own the layer it is on
// but its reference to it protects it from purge.
//
// Soft-pointer:
//
// A reference to an object that is not owned, and not protected
// from purge. 

#ifndef _CRX_DBID_H
#define _CRX_DBID_H 1

#include "cdraft.h"
#include "dbhandle.h"
#include "rxclass.h"

#pragma pack(push, 8)

class CRXDB_CLASS CRxDbObjectId 
{
public:
    CRxDbObjectId();
    CRxDbObjectId(const CRxDbStub*);

    static const   CRxDbObjectId  kNull;

    bool           isNull() const;
    void           setNull();

    CAXA::IntDbId     asOldId     () const;
    CRxDbObjectId&  setFromOldId(CAXA::IntDbId oldId);

//#ifdef _WIN64
//  private:
//    // catch attempts to set it from a 32-bit long
//    CRxDbObjectId&  setFromOldId(long);
//
//  public:
//    // need this overload to allow passing of unsigned 64-bit
//    inline CRxDbObjectId&  setFromOldId(CAXA::UIntPtr nUnsignedId)
//    {
//        const CAXA::IntDbId nSignedId =
//                        static_cast<CAXA::IntDbId>(nUnsignedId);
//        return this->setFromOldId(nSignedId);
//    }
//#endif

    bool           isValid() const;

    CRxDbObjectId&  operator =  (const CRxDbObjectId& id);
    CRxDbObjectId&  operator =  (const CRxDbStub*);

    bool           operator <  (const CRxDbObjectId&) const;
    bool           operator >  (const CRxDbObjectId&) const;
    bool           operator >= (const CRxDbObjectId&) const;
    bool           operator <= (const CRxDbObjectId&) const;
    bool           operator == (const CRxDbObjectId&) const;
    bool           operator != (const CRxDbObjectId&) const;

    bool           operator <  (const CRxDbStub*) const;
    bool           operator >  (const CRxDbStub*) const;
    bool           operator >= (const CRxDbStub*) const;
    bool           operator <= (const CRxDbStub*) const;
    bool           operator == (const CRxDbStub*) const;
    bool           operator != (const CRxDbStub*) const;

    operator       CRxDbStub*   () const;

    CRxDbDatabase* database() const;
    //CrxDbDatabase* originalDatabase() const;
    //void          convertToRedirectedId();
    bool          isErased() const;
    bool          isEffectivelyErased() const;
    //bool          isResident() const;
    //bool          objectLeftOnDisk() const;
    CRxDbHandle    handle() const;
    //AcDbHandle    nonForwardedHandle() const;

    CRxClass*    objectClass() const;

protected:
    CRxDbStub*  mId;
};

class CRxDbHardOwnershipId : public CRxDbObjectId
{
public:
    CRxDbHardOwnershipId();
    CRxDbHardOwnershipId(const CRxDbObjectId&);
    CRxDbHardOwnershipId(const CRxDbStub*);

    CRxDbHardOwnershipId& operator =(const CRxDbHardOwnershipId&);
    CRxDbHardOwnershipId& operator =(const CRxDbObjectId&);
    CRxDbHardOwnershipId& operator =(const CRxDbStub*);

    bool           operator != (const CRxDbObjectId&) const;
    bool           operator != (const CRxDbStub*) const;
    bool           operator == (const CRxDbObjectId&) const;
    bool           operator == (const CRxDbStub*) const;

    operator CRxDbStub* () const;
};

class CRxDbSoftOwnershipId : public CRxDbObjectId
{
public:
    CRxDbSoftOwnershipId();
    CRxDbSoftOwnershipId(const CRxDbObjectId&);
    CRxDbSoftOwnershipId(const CRxDbStub*);

    CRxDbSoftOwnershipId& operator =(const CRxDbSoftOwnershipId&);
    CRxDbSoftOwnershipId& operator =(const CRxDbObjectId&);
    CRxDbSoftOwnershipId& operator =(const CRxDbStub*);
    bool           operator != (const CRxDbObjectId&) const;
    bool           operator != (const CRxDbStub*) const;
    bool           operator == (const CRxDbObjectId&) const;
    bool           operator == (const CRxDbStub*) const;

    operator CRxDbStub* () const;
};

class CRxDbHardPointerId : public CRxDbObjectId
{
public:
    CRxDbHardPointerId();
    CRxDbHardPointerId(const CRxDbObjectId&);
    CRxDbHardPointerId(const CRxDbStub*);

    CRxDbHardPointerId& operator =(const CRxDbHardPointerId&);
    CRxDbHardPointerId& operator =(const CRxDbObjectId&);
    CRxDbHardPointerId& operator =(const CRxDbStub*);
    bool           operator != (const CRxDbObjectId&) const;
    bool           operator != (const CRxDbStub*) const;
    bool           operator == (const CRxDbObjectId&) const;
    bool           operator == (const CRxDbStub*) const;

    operator CRxDbStub* () const;
};

class CRxDbSoftPointerId : public CRxDbObjectId
{
public:
    CRxDbSoftPointerId();
    CRxDbSoftPointerId(const CRxDbObjectId&);
    CRxDbSoftPointerId(const CRxDbStub*);

    CRxDbSoftPointerId& operator =(const CRxDbSoftPointerId&);
    CRxDbSoftPointerId& operator =(const CRxDbObjectId&);
    CRxDbSoftPointerId& operator =(const CRxDbStub*);
    bool           operator != (const CRxDbObjectId&) const;
    bool           operator != (const CRxDbStub*) const;
    bool           operator == (const CRxDbObjectId&) const;
    bool           operator == (const CRxDbStub*) const;

    operator CRxDbStub* () const;
};


//////////////////// CRxDbObjectId inlines ////////////////////

inline
CRxDbObjectId::CRxDbObjectId()
{ mId = NULL; }

//inline
//CRxDbObjectId::CRxDbObjectId(const CRxDbObjectId& id)
//{ mId = id.mId; }

inline
CRxDbObjectId::CRxDbObjectId(const CRxDbStub* pStub)
{ mId = const_cast<CRxDbStub*>(pStub); }

inline bool
CRxDbObjectId::isNull() const
{ return mId == NULL; }

inline void
CRxDbObjectId::setNull()
{ mId = NULL; }

inline
CAXA::IntDbId CRxDbObjectId::asOldId() const
{
    return reinterpret_cast<CAXA::IntDbId>(this->mId);
}

inline
CRxDbObjectId& CRxDbObjectId::setFromOldId(CAXA::IntDbId oldId)
{
    this->mId = reinterpret_cast<CRxDbStub*>(oldId);
    return *this;
}

inline 
CRxDbObjectId& CRxDbObjectId::operator = (const CRxDbObjectId& id)
{ mId = id.mId; return *this; }

inline 
CRxDbObjectId& CRxDbObjectId::operator = (const CRxDbStub* pStub)
{ mId = const_cast<CRxDbStub*>(pStub); return *this; }

inline
CRxDbObjectId::operator CRxDbStub* () const
{ return mId; }

////////////////////// AcDbHardOwnershipId inlines ////////////////////

inline
CRxDbHardOwnershipId::CRxDbHardOwnershipId() {}

inline
CRxDbHardOwnershipId::CRxDbHardOwnershipId(const CRxDbObjectId& id)
  : CRxDbObjectId(id) {}

inline
CRxDbHardOwnershipId::CRxDbHardOwnershipId(const CRxDbStub* pStub)
  : CRxDbObjectId(pStub) {}

inline
CRxDbHardOwnershipId& CRxDbHardOwnershipId::operator  = (
    const CRxDbHardOwnershipId& id)
{ CRxDbObjectId::operator=(id); return *this; }

inline
CRxDbHardOwnershipId& CRxDbHardOwnershipId::operator = (const CRxDbObjectId& id)
{ CRxDbObjectId::operator=(id); return *this; }

inline 
CRxDbHardOwnershipId& CRxDbHardOwnershipId::operator = (const CRxDbStub* pStub)
{ mId = const_cast<CRxDbStub*>(pStub); return *this; }

inline 
bool CRxDbHardOwnershipId::operator != (const CRxDbObjectId& id) const
{ return CRxDbObjectId::operator!=(id); }

inline 
bool CRxDbHardOwnershipId::operator != (const CRxDbStub* pStub) const
{ return CRxDbObjectId::operator!=(pStub); }

inline 
bool CRxDbHardOwnershipId::operator == (const CRxDbObjectId& id) const
{ return CRxDbObjectId::operator==(id); }

inline 
bool CRxDbHardOwnershipId::operator == (const CRxDbStub* pStub) const
{ return CRxDbObjectId::operator==(pStub); }

inline
CRxDbHardOwnershipId::operator CRxDbStub* () const
{ return mId; }

//////////////////// CRxDbSoftOwnershipId inlines ////////////////////

inline
CRxDbSoftOwnershipId::CRxDbSoftOwnershipId() {}

inline
CRxDbSoftOwnershipId::CRxDbSoftOwnershipId(const CRxDbObjectId& id)
  : CRxDbObjectId(id) {}

inline
CRxDbSoftOwnershipId::CRxDbSoftOwnershipId(const CRxDbStub* pStub)
  : CRxDbObjectId(pStub) {}

inline
CRxDbSoftOwnershipId& CRxDbSoftOwnershipId::operator = (
    const CRxDbSoftOwnershipId& id)
{ CRxDbObjectId::operator=(id); return *this; }

inline
CRxDbSoftOwnershipId& CRxDbSoftOwnershipId::operator = (const CRxDbObjectId& id)
{ CRxDbObjectId::operator=(id); return *this; }

inline 
CRxDbSoftOwnershipId& CRxDbSoftOwnershipId::operator = (const CRxDbStub* pStub)
{ mId = const_cast<CRxDbStub*>(pStub); return *this; }

inline 
bool CRxDbSoftOwnershipId::operator != (const CRxDbObjectId& id) const
{ return CRxDbObjectId::operator!=(id); }

inline 
bool CRxDbSoftOwnershipId::operator != (const CRxDbStub* pStub) const
{ return CRxDbObjectId::operator!=(pStub); }

inline 
bool CRxDbSoftOwnershipId::operator == (const CRxDbObjectId& id) const
{ return CRxDbObjectId::operator==(id); }

inline 
bool CRxDbSoftOwnershipId::operator == (const CRxDbStub* pStub) const
{ return CRxDbObjectId::operator==(pStub); }

inline
CRxDbSoftOwnershipId::operator CRxDbStub* () const
{ return mId; }

//////////////////// AcDbHardPointerId inlines ////////////////////

inline
CRxDbHardPointerId::CRxDbHardPointerId() {}

inline
CRxDbHardPointerId::CRxDbHardPointerId(const CRxDbObjectId& id)
  : CRxDbObjectId(id) {}

inline
CRxDbHardPointerId::CRxDbHardPointerId(const CRxDbStub* pStub)
  : CRxDbObjectId(pStub) {}

inline
CRxDbHardPointerId& CRxDbHardPointerId::operator = (
    const CRxDbHardPointerId& id)
{ CRxDbObjectId::operator=(id); return *this; }

inline
CRxDbHardPointerId& CRxDbHardPointerId::operator = (const CRxDbObjectId& id)
{ CRxDbObjectId::operator=(id); return *this; }

inline 
CRxDbHardPointerId& CRxDbHardPointerId::operator = (const CRxDbStub* pStub)
{ mId = const_cast<CRxDbStub*>(pStub); return *this; }

inline 
bool CRxDbHardPointerId::operator != (const CRxDbObjectId& id) const
{ return CRxDbObjectId::operator!=(id); }

inline 
bool CRxDbHardPointerId::operator != (const CRxDbStub* pStub) const
{ return CRxDbObjectId::operator!=(pStub); }

inline 
bool CRxDbHardPointerId::operator == (const CRxDbObjectId& id) const
{ return CRxDbObjectId::operator==(id); }

inline 
bool CRxDbHardPointerId::operator == (const CRxDbStub* pStub) const
{ return CRxDbObjectId::operator==(pStub); }

inline
CRxDbHardPointerId::operator CRxDbStub* () const
{ return mId; }

//////////////////// AcDbSoftPointerId inlines ////////////////////

inline
CRxDbSoftPointerId::CRxDbSoftPointerId() {}

inline
CRxDbSoftPointerId::CRxDbSoftPointerId(const CRxDbObjectId& id)
  : CRxDbObjectId(id) {}

inline
CRxDbSoftPointerId::CRxDbSoftPointerId(const CRxDbStub* pStub)
  : CRxDbObjectId(pStub) {}

inline
CRxDbSoftPointerId& CRxDbSoftPointerId::operator = (const CRxDbSoftPointerId& id)
{ CRxDbObjectId::operator=(id); return *this; }

inline
CRxDbSoftPointerId& CRxDbSoftPointerId::operator = (const CRxDbObjectId& id)
{ CRxDbObjectId::operator=(id); return *this; }

inline 
CRxDbSoftPointerId& CRxDbSoftPointerId::operator = (const CRxDbStub* pStub)
{ mId = const_cast<CRxDbStub*>(pStub); return *this; }

inline 
bool CRxDbSoftPointerId::operator != (const CRxDbObjectId& id) const
{ return CRxDbObjectId::operator!=(id); }

inline 
bool CRxDbSoftPointerId::operator != (const CRxDbStub* pStub) const
{ return CRxDbObjectId::operator!=(pStub); }

inline 
bool CRxDbSoftPointerId::operator == (const CRxDbObjectId& id) const
{ return CRxDbObjectId::operator==(id); }

inline 
bool CRxDbSoftPointerId::operator == (const CRxDbStub* pStub) const
{ return CRxDbObjectId::operator==(pStub); }

inline
CRxDbSoftPointerId::operator CRxDbStub* () const
{ return mId; }

#pragma pack(pop)

#endif
