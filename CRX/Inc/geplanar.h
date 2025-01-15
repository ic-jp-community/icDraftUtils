#ifndef CRX_GEPLANAR_H
#define CRX_GEPLANAR_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

//

#include "gesurf.h"
#include "gevec3d.h"
#include "cdraft.h"
#include "gedll.h"
#pragma pack (push, 8)

class CRxGeLineSeg3d;
class CRxGeLinearEnt3d;
class CRxGeCircArc3d;

class
GE_DLLEXPIMPORT
CRxGePlanarEnt : public CRxGeSurface
{
public:
    // Intersection
    //
    CAXA::Boolean  intersectWith    (const CRxGeLinearEnt3d& linEnt, CRxGePoint3d& pnt,
                                      const CRxGeTol& tol = CrxGeContext::gTol) const;
    // Closest point
    //
    CRxGePoint3d     closestPointToLinearEnt (const CRxGeLinearEnt3d& line,
                                             CRxGePoint3d& pointOnLine,
                                             const CRxGeTol& tol
                                               = CrxGeContext::gTol) const;
    CRxGePoint3d     closestPointToPlanarEnt (const CRxGePlanarEnt& otherPln,
                                             CRxGePoint3d& pointOnOtherPln,
                                             const CRxGeTol& tol
                                               = CrxGeContext::gTol) const;
    // Direction tests.
    //
    CAXA::Boolean isParallelTo      (const CRxGeLinearEnt3d& linEnt,
                                      const CRxGeTol& tol = CrxGeContext::gTol) const;
    CAXA::Boolean isParallelTo      (const CRxGePlanarEnt& otherPlnEnt,
                                      const CRxGeTol& tol = CrxGeContext::gTol) const;
    CAXA::Boolean isPerpendicularTo (const CRxGeLinearEnt3d& linEnt,
                                      const CRxGeTol& tol = CrxGeContext::gTol) const;
    CAXA::Boolean isPerpendicularTo (const CRxGePlanarEnt& linEnt,
                                      const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Point set equality.
    //
    CAXA::Boolean isCoplanarTo      (const CRxGePlanarEnt& otherPlnEnt,
                                      const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Get methods.
    //
    void              get            (CRxGePoint3d&, CRxGeVector3d& uVec,
                                      CRxGeVector3d& vVec) const;
    void              get            (CRxGePoint3d&, CRxGePoint3d& origin,
                                      CRxGePoint3d&) const;

    // Geometric properties.
    //
    CRxGePoint3d    pointOnPlane      () const;
    CRxGeVector3d   normal            () const;
    void           getCoefficients(double& a, double& b, double& c, double& d) const;
    void           getCoordSystem(CRxGePoint3d& origin, CRxGeVector3d& axis1,
                                  CRxGeVector3d& axis2) const;
    // Assignment operator.
    //
    CRxGePlanarEnt& operator =        (const CRxGePlanarEnt& src);

protected:
    CRxGePlanarEnt ();
    CRxGePlanarEnt (const CRxGePlanarEnt&);
};

#pragma pack (pop)
#endif
