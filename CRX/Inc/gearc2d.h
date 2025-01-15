#ifndef CRX_GEARC2D_H
#define CRX_GEARC2D_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

//


#include "gecurv2d.h"
#include "gepnt2d.h"
#include "gevec2d.h"
#include "gegblabb.h"

#pragma pack (push, 8)

class CRxGeLine2d;
class CRxGeLinearEnt2d;

class
GE_DLLEXPIMPORT
CRxGeCircArc2d : public CRxGeCurve2d
{
public:
    CRxGeCircArc2d();
    CRxGeCircArc2d(const CRxGeCircArc2d& arc);
    CRxGeCircArc2d(const CRxGePoint2d& cent, double radius);
    CRxGeCircArc2d(const CRxGePoint2d& cent, double radius,
                  double startAngle, double endAngle,
                  const CRxGeVector2d& refVec = CRxGeVector2d::kXAxis,
                  CAXA::Boolean isClockWise = CAXA::kFalse);
    CRxGeCircArc2d(const CRxGePoint2d& startPoint, const CRxGePoint2d& point, 
                  const CRxGePoint2d& endPoint);

	// If bulgeFlag is kTrue, then bulge is interpreted to be the maximum
	// distance between the arc and the chord between the two input points.
	// If bulgeFlag is kFalse, then bulge is interpreted to be tan(ang/4),
	// where ang is the angle of the arc segment between the two input points.
    CRxGeCircArc2d(const CRxGePoint2d& startPoint, const CRxGePoint2d& endPoint, double bulge, 
                  CAXA::Boolean bulgeFlag = CAXA::kTrue);


    // Intersection with other geometric objects.
    //
    CAXA::Boolean intersectWith  (const CRxGeLinearEnt2d& line, int& intn,
                                   CRxGePoint2d& p1, CRxGePoint2d& p2,
                                   const CRxGeTol& tol = CrxGeContext::gTol) const;
    CAXA::Boolean intersectWith  (const CRxGeCircArc2d& arc, int& intn,
                                   CRxGePoint2d& p1, CRxGePoint2d& p2,
                                   const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Tangent line to the circular arc at given point.
    //
    CAXA::Boolean tangent        (const CRxGePoint2d& pnt, CRxGeLine2d& line,
                                   const CRxGeTol& tol = CrxGeContext::gTol) const;

    CAXA::Boolean tangent        (const CRxGePoint2d& pnt, CRxGeLine2d& line,
                                  const CRxGeTol& tol, CRxGeError& error) const;
		 // Possible error conditions:  kArg1TooBig, kArg1InsideThis, 
		 // kArg1OnThis
     

    // Test if point is inside circle.
    //
    CAXA::Boolean isInside       (const CRxGePoint2d& pnt,
                                   const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Definition of circular arc
    //
    CRxGePoint2d    center         () const;
    double         radius         () const;
    double         startAng       () const;
    double         endAng         () const;
    CAXA::Boolean isClockWise    () const;
    CRxGeVector2d   refVec         () const;
    CRxGePoint2d    startPoint     () const;
    CRxGePoint2d    endPoint       () const;

    CRxGeCircArc2d& setCenter      (const CRxGePoint2d& cent);
    CRxGeCircArc2d& setRadius      (double radius);
    CRxGeCircArc2d& setAngles      (double startAng, double endAng);
    CRxGeCircArc2d& setToComplement();
    CRxGeCircArc2d& setRefVec      (const CRxGeVector2d& vec);
    CRxGeCircArc2d& set            (const CRxGePoint2d& cent, double radius);
    CRxGeCircArc2d& set            (const CRxGePoint2d& cent, double radius,
                                   double ang1, double ang2,
                                   const CRxGeVector2d& refVec =
                                   CRxGeVector2d::kXAxis,
                                   CAXA::Boolean isClockWise = CAXA::kFalse);
    CRxGeCircArc2d& set            (const CRxGePoint2d& startPoint, const CRxGePoint2d& pnt,
                                   const CRxGePoint2d& endPoint);

    CRxGeCircArc2d& set            (const CRxGePoint2d& startPoint, const CRxGePoint2d& pnt,
                                  const CRxGePoint2d& endPoint, CRxGeError& error);

		 // Possible errors:  kEqualArg1Arg2, kEqualArg1Arg3, kEqualArg2Arg3, 
		 // kLinearlyDependentArg1Arg2Arg3.
		 // Degenerate results: none.
		 // On error, the object is unchanged.

	// If bulgeFlag is kTrue, then bulge is interpreted to be the maximum
	// distance between the arc and the chord between the two input points.
	// If bulgeFlag is kFalse, then bulge is interpreted to be tan(ang/4),
	// where ang is the angle of the arc segment between the two input points.
    CRxGeCircArc2d& set            (const CRxGePoint2d& startPoint, 
                                   const CRxGePoint2d& endPoint,
                                   double bulge, CAXA::Boolean bulgeFlag = CAXA::kTrue);
    CRxGeCircArc2d& set            (const CRxGeCurve2d& curve1,
                                   const CRxGeCurve2d& curve2,
                                   double radius, double& param1, double& param2,
								   CAXA::Boolean& success);
		// On success, this arc becomes the fillet of the given radius between the two curves,
	    // whose points of tangency are nearest param1 and param2 respectively.
    CRxGeCircArc2d& set            (const CRxGeCurve2d& curve1,
                                   const CRxGeCurve2d& curve2,
                                   const CRxGeCurve2d& curve3,
                                   double& param1, double& param2, double& param3,
								   CAXA::Boolean& success);
    // Assignment operator.
    //
    CRxGeCircArc2d& operator =     (const CRxGeCircArc2d& arc);

	CRxGe::EntityId   type        () const;//overload
	
	CRxGeEntity2d*    copy        () const;//overload
};

#pragma pack (pop)
#endif
