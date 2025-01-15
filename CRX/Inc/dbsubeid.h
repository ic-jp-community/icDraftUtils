#ifndef GEOMENT_DBSUBEID_H
#define GEOMENT_DBSUBEID_H
//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//

#include "crxdb.h"
#include "dbidar.h"

#pragma pack (push, 8)

class CRXDB_CLASS CRxDbSubentId
{
public:
    CRxDbSubentId();
    CRxDbSubentId(CRxDb::SubentType type, CAXA::GsMarker index);
    CRxDbSubentId(CRxClass* pTypeClass, CAXA::GsMarker index);

    bool               operator ==(const CRxDbSubentId& id) const;
    bool               operator !=(const CRxDbSubentId& id) const;

    CRxDb::SubentType   type () const;
    void               setType(CRxDb::SubentType);
    CRxClass*         typeClass () const;
    void               setTypeClass(CRxClass* pClass);
    CAXA::GsMarker    index() const;
    void               setIndex(CAXA::GsMarker);
    
private:
    CRxDb::SubentType mType;
    CAXA::GsMarker  mIndex;
    CRxClass*       mpTypeClass;
};

extern const CRxDbSubentId kNullSubentId;

const CAXA::GsMarker kNullSubentIndex = 0;

class CRXDB_CLASS CRxDbFullSubentPath
{
public:
    CRxDbFullSubentPath();
    CRxDbFullSubentPath(CRxDb::SubentType type, CAXA::GsMarker index);
    CRxDbFullSubentPath(CRxDbObjectId entId, CRxDb::SubentType type, CAXA::GsMarker index);
    CRxDbFullSubentPath(CRxDbObjectId entId, CRxDbSubentId subId);
    CRxDbFullSubentPath(CRxDbObjectIdArray objectIds, CRxDbSubentId subId);
    CRxDbFullSubentPath(const CRxDbFullSubentPath&);
	~CRxDbFullSubentPath(){};

    CRxDbFullSubentPath&     operator =  (const CRxDbFullSubentPath&);


    bool           operator ==(const CRxDbFullSubentPath& id) const;
    bool           operator !=(const CRxDbFullSubentPath& id) const;

    void                objectIds(CRxDbObjectIdArray& objectIds) const;
    CRxDbObjectIdArray&  objectIds();
    const CRxDbObjectIdArray&  objectIds() const;
    const CRxDbSubentId  subentId () const;
    CRxDbSubentId&       subentId ();
    
private:                            
    CRxDbObjectIdArray mObjectIds;
    CRxDbSubentId      mSubentId;
};

// inlines

inline CRxDb::SubentType
CRxDbSubentId::type () const
{
    return mType;
}

inline void
CRxDbSubentId::setType(CRxDb::SubentType type)
{
    mType = type;
    if (mType != CRxDb::kClassSubentType)
        mpTypeClass = NULL;
}

inline CAXA::GsMarker
CRxDbSubentId::index() const
{
    return mIndex;
}

inline void  
CRxDbSubentId::setIndex(CAXA::GsMarker index)
{
    mIndex = index;
}

inline CRxClass* 
CRxDbSubentId::typeClass() const
{
    return mpTypeClass;
}

inline void
CRxDbSubentId::setTypeClass(CRxClass* pTypeClass)
{
    mpTypeClass = pTypeClass;
    if (mpTypeClass != NULL)
        mType = CRxDb::kClassSubentType;
}

inline
CRxDbSubentId::CRxDbSubentId() 
    : mType(CRxDb::kNullSubentType), mIndex(kNullSubentIndex), mpTypeClass(NULL)
{
}

inline
CRxDbSubentId::CRxDbSubentId(CRxDb::SubentType t, CAXA::GsMarker i) 
    : mType(t), mIndex(i), mpTypeClass(NULL)
{
}

inline
CRxDbSubentId::CRxDbSubentId(CRxClass* pTypeClass, CAXA::GsMarker i) 
    : mType(CRxDb::kClassSubentType), mIndex(i), mpTypeClass(pTypeClass)
{
}

inline bool
CRxDbSubentId::operator ==(const CRxDbSubentId& id) const
{
    return ((mIndex == id.mIndex) 
            && (mType == id.mType) 
            && (mpTypeClass == id.mpTypeClass));
}


inline bool
CRxDbSubentId::operator !=(const CRxDbSubentId& id) const
{
    return ((mIndex != id.mIndex) 
            || (mType != id.mType)
            || (mpTypeClass != id.mpTypeClass));
}

inline
CRxDbFullSubentPath::CRxDbFullSubentPath() 
{
}

inline
CRxDbFullSubentPath::CRxDbFullSubentPath(CRxDb::SubentType type,
                                       CAXA::GsMarker index)
    : mSubentId(type, index)
{
}

inline void
CRxDbFullSubentPath::objectIds(CRxDbObjectIdArray& objectIds) const
{
    objectIds = mObjectIds;
}

inline CRxDbObjectIdArray&
CRxDbFullSubentPath::objectIds()
{
    return mObjectIds;
}

inline const CRxDbObjectIdArray&
CRxDbFullSubentPath::objectIds() const
{
    return mObjectIds;
}

inline const CRxDbSubentId
CRxDbFullSubentPath::subentId () const
{
    return mSubentId;
}

inline CRxDbSubentId&
CRxDbFullSubentPath::subentId ()
{
    return mSubentId;
}

#pragma pack (pop)

#endif

