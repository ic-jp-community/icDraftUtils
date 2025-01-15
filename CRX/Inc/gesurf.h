#ifndef CRX_GESURF_H
#define CRX_GESURF_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

//

#include "geent3d.h"
#include "gevc3dar.h"
#pragma pack (push, 8)

class CRxGePoint2d;
class CRxGeCurve3d;
//class CRxGePointOnCurve3d;
//class CRxGePointOnSurface;
//class CRxGePointOnSurfaceData;
class CRxGeInterval;


class
GE_DLLEXPIMPORT
CRxGeSurface : public CRxGeEntity3d
{
public:
    // Parameter related.
    //
    CRxGePoint2d     paramOf        (const CRxGePoint3d& pnt,
                                    const CRxGeTol& tol = CrxGeContext::gTol) const;
    // Point containment
    //
    CAXA::Boolean  isOn           (const CRxGePoint3d& pnt,
                                    const CRxGeTol& tol = CrxGeContext::gTol) const;
    CAXA::Boolean  isOn           (const CRxGePoint3d& pnt, CRxGePoint2d& paramPoint,
                                    const CRxGeTol& tol = CrxGeContext::gTol ) const;
    // Operations.
    //
    CRxGePoint3d closestPointTo(const CRxGePoint3d& pnt,
                                  const CRxGeTol& tol = CrxGeContext::gTol) const;
/*
    void getClosestPointTo(const CRxGePoint3d& pnt, CRxGePointOnSurface& result,
                           const CRxGeTol& tol = CrxGeContext::gTol) const;
*/	
    double          distanceTo     (const CRxGePoint3d& pnt,
                                    const CRxGeTol& tol = CrxGeContext::gTol) const;

    CAXA::Boolean  isNormalReversed () const;
    CRxGeSurface&    reverseNormal    ();

    // Assignment operator.
    //
    CRxGeSurface&    operator =     (const CRxGeSurface& otherSurface);

    // Bounds in parameter space.
    //
    void   getEnvelope  (CRxGeInterval& intrvlX, CRxGeInterval& intrvlY) const;

    // Geometric inquiry methods.
    //
    CAXA::Boolean isClosedInU       (const CRxGeTol& tol = CrxGeContext::gTol) const;
    CAXA::Boolean isClosedInV       (const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Evaluators.
    // Derivative arrays are indexed partialU, partialV followed by
    // the mixed partial.
    //
    CRxGePoint3d   evalPoint   (const CRxGePoint2d& param) const;
    CRxGePoint3d   evalPoint   (const CRxGePoint2d& param, int derivOrd,
                               CRxGeVector3dArray& derivatives) const;
    CRxGePoint3d   evalPoint   (const CRxGePoint2d& param, int derivOrd,
                               CRxGeVector3dArray& derivatives,
                               CRxGeVector3d& normal) const;
protected:
    CRxGeSurface ();
    CRxGeSurface (const CRxGeSurface&);
};

#pragma pack (pop)
#endif
