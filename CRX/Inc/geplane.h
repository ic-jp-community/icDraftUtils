#ifndef CRX_GEPLANE_H
#define CRX_GEPLANE_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

//
#include "geplanar.h"
#include "cdraft.h"
#include "gedll.h"
#pragma pack (push, 8)

class CRxGeBoundedPlane;
class CRxGeLine3d;

class
GE_DLLEXPIMPORT
CRxGePlane : public CRxGePlanarEnt
{
public:
    // Global plane objects.
    //
    static const CRxGePlane kXYPlane;
    static const CRxGePlane kYZPlane;
    static const CRxGePlane kZXPlane;

    CRxGePlane();
    CRxGePlane(const CRxGePlane& src);
    CRxGePlane(const CRxGePoint3d& origin, const CRxGeVector3d& normal);
    CRxGePlane(const CRxGePoint3d& pntU, const CRxGePoint3d& or, const CRxGePoint3d& pntV);
    CRxGePlane(const CRxGePoint3d& or, const CRxGeVector3d& uAxis,
              const CRxGeVector3d& vAxis);
    CRxGePlane(double a, double b, double c, double d);

    // Signed distance from a point to a plane.
    //
    double         signedDistanceTo (const CRxGePoint3d& pnt) const;

    // Intersection
    //
    CAXA::Boolean intersectWith    (const CRxGeLinearEnt3d& linEnt, CRxGePoint3d& resultPnt,
                                     const CRxGeTol& tol = CrxGeContext::gTol) const;
    CAXA::Boolean intersectWith    (const CRxGePlane& otherPln, CRxGeLine3d& resultLine,
                                     const CRxGeTol& tol = CrxGeContext::gTol) const;
    CAXA::Boolean intersectWith    (const CRxGeBoundedPlane& bndPln, CRxGeLineSeg3d& resultLineSeg,
                                     const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Geometry redefinition.
    //
    CRxGePlane&     set              (const CRxGePoint3d& pnt, const CRxGeVector3d& normal);
    CRxGePlane&     set              (const CRxGePoint3d& pntU, const CRxGePoint3d& or,
                                     const CRxGePoint3d& pntV);
    CRxGePlane&     set              (double a, double b, double c, double d);
    CRxGePlane&     set              (const CRxGePoint3d& or,
                                     const CRxGeVector3d& uAxis,
                                     const CRxGeVector3d& vAxis);
    // Assignment operator.
    //
    CRxGePlane&     operator =       (const CRxGePlane& src);
};

#pragma pack (pop)
#endif
