#ifndef CRX_GEENT3D_H
#define CRX_GEENT3D_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

//
#include "gegbl.h"
#include "gepnt3d.h"
#include "geent2d.h"
#include "gegblge.h"
//#include "geintrvl.h"
//#include "gegblnew.h"

#pragma pack (push, 8)

class
GE_DLLEXPIMPORT
CRxGeEntity3d
{
public:
    ~CRxGeEntity3d();

    // Run time type information.
    //
    CAXA::Boolean   isKindOf    (CRxGe::EntityId entType) const;
    CRxGe::EntityId   type        () const;

    // Make a copy of the entity.
    //
    CRxGeEntity3d*    copy        () const;
    CRxGeEntity3d&    operator =  (const CRxGeEntity3d& entity);

    // Equivalence
    //
    CAXA::Boolean   operator == (const CRxGeEntity3d& entity) const;
    CAXA::Boolean   operator != (const CRxGeEntity3d& entity) const;
    CAXA::Boolean   isEqualTo   (const CRxGeEntity3d& ent,
                                  const CRxGeTol& tol = CrxGeContext::gTol) const;
    // Matrix multiplication
    //
    CRxGeEntity3d&    transformBy (const CRxGeMatrix3d& xfm);
    CRxGeEntity3d&    translateBy (const CRxGeVector3d& translateVec);
    CRxGeEntity3d&    rotateBy    (double angle, const CRxGeVector3d& vec,
                                  const CRxGePoint3d& wrtPoint = CRxGePoint3d::kOrigin);
    //CRxGeEntity3d&    mirror      (const CRxGePlane& plane);
    CRxGeEntity3d&    scaleBy     (double scaleFactor,
                                  const CRxGePoint3d& wrtPoint
                                  = CRxGePoint3d::kOrigin);
    // Point containment
    //
    CAXA::Boolean   isOn        (const CRxGePoint3d& pnt,
                                  const CRxGeTol& tol = CrxGeContext::gTol) const;
/*
protected:
    friend class CRxGeImpEntity3d;
    CRxGeImpEntity3d  *mpImpEnt;
    int              mDelEnt;
    CRxGeEntity3d ();
    CRxGeEntity3d (const CRxGeEntity3d&);
    CRxGeEntity3d (CRxGeImpEntity3d&, int);
    CRxGeEntity3d (CRxGeImpEntity3d*);
    CRxGeEntity2d* newEntity2d (CRxGeImpEntity3d*) const;
    CRxGeEntity2d* newEntity2d (CRxGeImpEntity3d&, int) const;
    CRxGeEntity3d* newEntity3d (CRxGeImpEntity3d*) const;
    CRxGeEntity3d* newEntity3d (CRxGeImpEntity3d&, int) const;
*/
};

/*
__forceinline CRxGeEntity2d*
CRxGeEntity3d::newEntity2d (CRxGeImpEntity3d *impEnt ) const
{
    return GENEWLOC( CRxGeEntity2d, this) ( impEnt );
}

__forceinline CRxGeEntity3d*
CRxGeEntity3d::newEntity3d (CRxGeImpEntity3d *impEnt ) const
{
    return GENEWLOC( CRxGeEntity3d, this) ( impEnt );
}

__forceinline CRxGeEntity3d*
CRxGeEntity3d::newEntity3d(CRxGeImpEntity3d& impEnt, int dummy) const
{
    return GENEWLOC( CRxGeEntity3d, this)(impEnt, dummy);
}

__forceinline CRxGeEntity2d*
CRxGeEntity3d::newEntity2d(CRxGeImpEntity3d& impEnt, int dummy) const
{
    return GENEWLOC( CRxGeEntity2d, this)(impEnt, dummy);
}
*/
#pragma pack (pop)
#endif
