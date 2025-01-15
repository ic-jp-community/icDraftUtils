#ifndef CRX_GEELL3D_H
#define CRX_GEELL3D_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

//

#include "gecurv3d.h"
#include "gevec3d.h"
#include "gepnt3d.h"
#include "gelent3d.h"
//#include "geintrvl.h"
//#include "geponc3d.h"
//#include "geplane.h"
#pragma pack (push, 8)

class CRxGeEllipArc2d;
class CRxGeCircArc3d;
class CRxGeLineEnt3d;
//class CRxGePlanarEnt;


class
GE_DLLEXPIMPORT
CrxGeEllipArc3d : public CRxGeCurve3d
{
public:

    CrxGeEllipArc3d();
    CrxGeEllipArc3d(const CrxGeEllipArc3d& ell);
    CrxGeEllipArc3d(const CRxGeCircArc3d& arc);
    CrxGeEllipArc3d(const CRxGePoint3d& cent, const CRxGeVector3d& majorAxis,
                   const CRxGeVector3d& minorAxis, double majorRadius,
                   double minorRadius);
    CrxGeEllipArc3d(const CRxGePoint3d& cent, const CRxGeVector3d& majorAxis,
                   const CRxGeVector3d& minorAxis, double majorRadius,
                   double minorRadius, double ang1, double ang2);
                                         
    // Return the point on this object that is closest to the other object.
    //
/*
    CRxGePoint3d    closestPointToPlane(const CRxGePlanarEnt& plane,
                                  CRxGePoint3d& pointOnPlane,
                                const CRxGeTol& = CrxGeContext::gTol) const;
*/ 
    // Intersection with other geometric objects.
    // 
    CAXA::Boolean intersectWith (const CRxGeLinearEnt3d& line, int& intn,
                                  CRxGePoint3d& p1, CRxGePoint3d& p2,
                                  const CRxGeTol& tol = CrxGeContext::gTol) const;  

/*
    CAXA::Boolean intersectWith (const CRxGePlanarEnt& plane, int& numOfIntersect,
                                  CRxGePoint3d& p1, CRxGePoint3d& p2,
                                  const CRxGeTol& tol = CrxGeContext::gTol) const;
 */
    // Projection-intersection with other geometric objects.
    //
    CAXA::Boolean projIntersectWith(const CRxGeLinearEnt3d& line,
                                  const CRxGeVector3d& projDir, int &numInt,
                                  CRxGePoint3d& pntOnEllipse1,
                                  CRxGePoint3d& pntOnEllipse2,
                                  CRxGePoint3d& pntOnLine1,
                                  CRxGePoint3d& pntOnLine2,
                                  const CRxGeTol& tol = CrxGeContext::gTol) const;
    // Plane of the ellipse
    //
/*
    void           getPlane      (CRxGePlane& plane) const;
*/
    // Inquiry Methods
    //
    CAXA::Boolean isCircular    (const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Test if point is inside full ellipse
    //
    CAXA::Boolean isInside      (const CRxGePoint3d& pnt,
                                  const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Definition of ellipse
    //
    CRxGePoint3d    center        () const;
    double         minorRadius   () const;
    double         majorRadius   () const;
    CRxGeVector3d   minorAxis     () const;
    CRxGeVector3d   majorAxis     () const;
    CRxGeVector3d   normal        () const; 
    double         startAng      () const;
    double         endAng        () const;
    CRxGePoint3d    startPoint    () const;
    CRxGePoint3d    endPoint      () const;

    CrxGeEllipArc3d& setCenter     (const CRxGePoint3d& cent);
    CrxGeEllipArc3d& setMinorRadius(double rad);
    CrxGeEllipArc3d& setMajorRadius(double rad);
    CrxGeEllipArc3d& setAxes       (const CRxGeVector3d& majorAxis, const CRxGeVector3d& minorAxis);
    CrxGeEllipArc3d& setAngles     (double startAngle, double endAngle);
    CrxGeEllipArc3d& set           (const CRxGePoint3d& cent,
                                   const CRxGeVector3d& majorAxis,
                                   const CRxGeVector3d& minorAxis,
                                   double majorRadius, double minorRadius);
    CrxGeEllipArc3d& set           (const CRxGePoint3d& cent,
                                   const CRxGeVector3d& majorAxis,
                                   const CRxGeVector3d& minorAxis,
                                   double majorRadius, double minorRadius,
                                   double startAngle, double endAngle);
    CrxGeEllipArc3d& set           (const CRxGeCircArc3d&);

    // Assignment operator.
    //
    CrxGeEllipArc3d& operator =    (const CrxGeEllipArc3d& ell);
};

#pragma pack (pop)
#endif
