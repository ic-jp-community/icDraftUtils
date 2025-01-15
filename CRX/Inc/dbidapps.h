#ifndef _CRX_DBID_APPS_H
#define _CRX_DBID_APPS_H 1
//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//
// DESCRIPTION:
//
// This file contains the inlined versions of the comparsion operators
// for the CrxDbObjectId class, that are for use by adjacent applications.
// These operators call out to explicit functions, to allow behavioral
// modification of these operators between c4 and c5.  Presumably, the
// CaxaDraft/adjacent app division of these operators will be collapsed back
// into dbid.h at a future date.
// 
// See dbid.cc for the body of the function calls.
// See dbid.h for further description of the CrxDbObjectId types.

#include "cdraft.h"
#include "dbid.h"
#include "dbid_ops.h"
#pragma pack (push, 8)

//////////////////// CrxDbObjectId inlines ////////////////////

// LHS CrxDbObjectId -- RHS CrxDbObjectId

inline bool
CRxDbObjectId::operator < (const CRxDbObjectId& id) const
{ return c5ObjIdIsLessThan(*this, id); }

inline bool
CRxDbObjectId::operator > (const CRxDbObjectId& id) const
{ return c5ObjIdIsGreaterThan(*this, id); }

inline bool
CRxDbObjectId::operator <= (const CRxDbObjectId& id) const
{ return c5ObjIdLessThanOrEqual(*this, id); }

inline bool
CRxDbObjectId::operator >= (const CRxDbObjectId& id) const
{ return c5ObjIdGreaterThanOrEqual(*this, id); }

inline bool
CRxDbObjectId::operator == (const CRxDbObjectId& id) const
{ return c5ObjIdIsEqualTo(*this, id); }

inline bool
CRxDbObjectId::operator != (const CRxDbObjectId& id) const
{ return !c5ObjIdIsEqualTo(*this, id); }



// LHS CrxDbObjectId -- RHS AcDbStub*

inline bool
CRxDbObjectId::operator < (const CRxDbStub* pStub) const
{ return c5ObjIdIsLessThan(*this, pStub); }

inline bool
CRxDbObjectId::operator > (const CRxDbStub* pStub) const
{ return c5ObjIdIsGreaterThan(*this, pStub); }

inline bool
CRxDbObjectId::operator <= (const CRxDbStub* pStub) const
{ return c5ObjIdLessThanOrEqual(*this, pStub); }

inline bool
CRxDbObjectId::operator >= (const CRxDbStub* pStub) const
{ return c5ObjIdGreaterThanOrEqual(*this, pStub); }

inline bool
CRxDbObjectId::operator == (const CRxDbStub* pStub) const
{ return c5ObjIdIsEqualTo(*this, pStub); }

inline bool
CRxDbObjectId::operator != (const CRxDbStub* pStub) const
{ return !c5ObjIdIsEqualTo(*this, pStub); }


//////////////////// CRxDbR13ObjectId inlines ////////////////////
// The behavior of CrxDbObjectId's in 3rd party applications with
// respect to the boolean operators defined by this class has 
// changed from R13. If applications need to return to the old-style
// behavior for some reason (they shouldn't, but you never know ...)
// they can cast objectIds to this class.

class CRxDbR13ObjectId : public CRxDbObjectId
{

public:

    bool operator < (const CRxDbR13ObjectId& id) const;
    bool operator > (const CRxDbR13ObjectId& id) const;
    bool operator <= (const CRxDbR13ObjectId& id) const;
    bool operator >= (const CRxDbR13ObjectId& id) const;
    bool operator == (const CRxDbR13ObjectId& id) const;
    bool operator != (const CRxDbR13ObjectId& id) const;

    bool operator < (const CRxDbStub* pStub) const;
    bool operator > (const CRxDbStub* pStub) const;
    bool operator <= (const CRxDbStub* pStub) const;
    bool operator >= (const CRxDbStub* pStub) const;
    bool operator == (const CRxDbStub* pStub) const;
    bool operator != (const CRxDbStub* pStub) const;

};

// LHS CrxDbObjectId -- RHS CrxDbObjectId

inline bool
CRxDbR13ObjectId::operator < (const CRxDbR13ObjectId& id) const
{ return c4ObjIdIsLessThan(reinterpret_cast<CAXA::ULongPtr>(mId),
                           reinterpret_cast<CAXA::ULongPtr>(id.mId));
}

inline bool
CRxDbR13ObjectId::operator > (const CRxDbR13ObjectId& id) const
{ return c4ObjIdIsGreaterThan(reinterpret_cast<CAXA::ULongPtr>(mId),
                              reinterpret_cast<CAXA::ULongPtr>(id.mId));
}

inline bool
CRxDbR13ObjectId::operator <= (const CRxDbR13ObjectId& id) const
{ return c4ObjIdLessThanOrEqual(reinterpret_cast<CAXA::ULongPtr>(mId),
                                reinterpret_cast<CAXA::ULongPtr>(id.mId));
}

inline bool
CRxDbR13ObjectId::operator >= (const CRxDbR13ObjectId& id) const
{ return c4ObjIdGreaterThanOrEqual(reinterpret_cast<CAXA::ULongPtr>(mId),
                                   reinterpret_cast<CAXA::ULongPtr>(id.mId));
}

inline bool
CRxDbR13ObjectId::operator == (const CRxDbR13ObjectId& id) const
{ return c4ObjIdIsEqualTo(reinterpret_cast<CAXA::ULongPtr>(mId),
                          reinterpret_cast<CAXA::ULongPtr>(id.mId));
}

inline bool
CRxDbR13ObjectId::operator != (const CRxDbR13ObjectId& id) const
{ return c4ObjIdNotEqualTo(reinterpret_cast<CAXA::ULongPtr>(mId),
                           reinterpret_cast<CAXA::ULongPtr>(id.mId));
}



// LHS CrxDbObjectId -- RHS AcDbStub*

inline bool
CRxDbR13ObjectId::operator < (const CRxDbStub* pStub) const
{ return c4ObjIdIsLessThan(reinterpret_cast<CAXA::ULongPtr>(mId),
                           reinterpret_cast<CAXA::ULongPtr>(pStub)); }

inline bool
CRxDbR13ObjectId::operator > (const CRxDbStub* pStub) const
{ return c4ObjIdIsGreaterThan(reinterpret_cast<CAXA::ULongPtr>(mId),
                              reinterpret_cast<CAXA::ULongPtr>(pStub)); }

inline bool
CRxDbR13ObjectId::operator <= (const CRxDbStub* pStub) const
{ return c4ObjIdLessThanOrEqual(reinterpret_cast<CAXA::ULongPtr>(mId),
                                reinterpret_cast<CAXA::ULongPtr>(pStub)); }

inline bool
CRxDbR13ObjectId::operator >= (const CRxDbStub* pStub) const
{ return c4ObjIdGreaterThanOrEqual(reinterpret_cast<CAXA::ULongPtr>(mId),
                                   reinterpret_cast<CAXA::ULongPtr>(pStub)); }

inline bool
CRxDbR13ObjectId::operator == (const CRxDbStub* pStub) const
{ return c4ObjIdIsEqualTo(reinterpret_cast<CAXA::ULongPtr>(mId),
                          reinterpret_cast<CAXA::ULongPtr>(pStub)); }

inline bool
CRxDbR13ObjectId::operator != (const CRxDbStub* pStub) const
{ return c4ObjIdNotEqualTo(reinterpret_cast<CAXA::ULongPtr>(mId),
                           reinterpret_cast<CAXA::ULongPtr>(pStub)); }

#pragma pack (pop)
#endif // _AD_DBID_APPS_H
