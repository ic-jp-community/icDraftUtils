#ifndef CRX_GEELL2D_H
#define CRX_GEELL2D_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

//

#include "gecurv2d.h"
#include "gevec2d.h"
#include "gepnt2d.h"
//#include "geponc2d.h"
//#include "geintrvl.h"
#pragma pack (push, 8)

class CRxGeCircArc2d;
class CRxGePlanarEnt;
class CRxGeEllipArc2d;
class CRxGeLinearEnt2d;


class
GE_DLLEXPIMPORT
CRxGeEllipArc2d : public CRxGeCurve2d
{
public:
    CRxGeEllipArc2d();
    CRxGeEllipArc2d(const CRxGeEllipArc2d& ell);
    CRxGeEllipArc2d(const CRxGeCircArc2d& arc);
    CRxGeEllipArc2d(const CRxGePoint2d& cent, const CRxGeVector2d& majorAxis,
                   const CRxGeVector2d& minorAxis, double majorRadius,
                   double minorRadius);
    CRxGeEllipArc2d(const CRxGePoint2d& cent, const CRxGeVector2d& majorAxis,
                   const CRxGeVector2d& minorAxis, double majorRadius,
                   double minorRadius, double startAngle, double endAngle);

    // Intersection with other geometric objects.
    //
    CAXA::Boolean intersectWith (const CRxGeLinearEnt2d& line, int& intn,
                                  CRxGePoint2d& p1, CRxGePoint2d& p2,
                                  const CRxGeTol& tol = CrxGeContext::gTol) const;
    // Inquiry Methods
    //
    CAXA::Boolean isCircular    (const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Test if point is inside full ellipse
    //
    CAXA::Boolean isInside      (const CRxGePoint2d& pnt,
                                  const CRxGeTol& tol = CrxGeContext::gTol) const;


    // Definition of ellipse
    //
    CRxGePoint2d    center        () const;
    double         minorRadius   () const;
    double         majorRadius   () const;
    CRxGeVector2d   minorAxis     () const;
    CRxGeVector2d   majorAxis     () const;
    double         startAng      () const;
    double         endAng        () const;
    CRxGePoint2d    startPoint    () const;
    CRxGePoint2d    endPoint      () const;
    CAXA::Boolean isClockWise   () const;

    CRxGeEllipArc2d& setCenter     (const CRxGePoint2d& cent);
    CRxGeEllipArc2d& setMinorRadius(double rad);
    CRxGeEllipArc2d& setMajorRadius(double rad);
    CRxGeEllipArc2d& setAxes       (const CRxGeVector2d& majorAxis, const CRxGeVector2d& minorAxis);
    CRxGeEllipArc2d& setAngles     (double startAngle, double endAngle);
    CRxGeEllipArc2d& set           (const CRxGePoint2d& cent,
                                   const CRxGeVector2d& majorAxis,
                                   const CRxGeVector2d& minorAxis,
                                   double majorRadius, double minorRadius);
    CRxGeEllipArc2d& set           (const CRxGePoint2d& cent,
                                   const CRxGeVector2d& majorAxis,
                                   const CRxGeVector2d& minorAxis,
                                   double majorRadius, double minorRadius,
                                   double startAngle, double endAngle);
    CRxGeEllipArc2d& set           (const CRxGeCircArc2d& arc);

    // Assignment operator.
    //
    CRxGeEllipArc2d& operator =    (const CRxGeEllipArc2d& ell);

	CRxGe::EntityId   type        () const;//overload

	// Make a copy of the entity.
	//
	CRxGeEntity2d*  copy        () const;//overload
};

#pragma pack (pop)
#endif

