#ifndef CRX_GEARC3D_H
#define CRX_GEARC3D_H
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
//#include "geplane.h"
#include "gegblabb.h"
#include "gelent3d.h"

#pragma pack (push, 8)
class CRxGeLine3d;
class CRxGeCircArc2d;
//class CRxGePlanarEnt;

class 
GE_DLLEXPIMPORT
CRxGeCircArc3d : public CRxGeCurve3d
{
public:
    CRxGeCircArc3d();
    CRxGeCircArc3d(const CRxGeCircArc3d& arc);
    CRxGeCircArc3d(const CRxGePoint3d& cent,
                  const CRxGeVector3d& nrm, double radius);
    CRxGeCircArc3d(const CRxGePoint3d& cent, const CRxGeVector3d& nrm,
                  const CRxGeVector3d& refVec, double radius,
                  double startAngle, double endAngle);
    CRxGeCircArc3d(const CRxGePoint3d& startPoint, const CRxGePoint3d& pnt, const CRxGePoint3d& endPoint);
                                            
    // Return the point on this object that is closest to the other object.
    //
	/*
    CRxGePoint3d    closestPointToPlane (const CRxGePlanarEnt& plane,
                                        CRxGePoint3d& pointOnPlane,
                                        const CRxGeTol& tol
                                        = CrxGeContext::gTol) const;
    */

    // Intersection with other geometric objects.
    //
    CAXA::Boolean intersectWith  (const CRxGeLinearEnt3d& line, int& intn,
                                   CRxGePoint3d& p1, CRxGePoint3d& p2,
                                   const CRxGeTol& tol = CrxGeContext::gTol) const;

    CAXA::Boolean intersectWith  (const CRxGeCircArc3d& arc, int& intn,
                                   CRxGePoint3d& p1, CRxGePoint3d& p2,
                                   const CRxGeTol& tol = CrxGeContext::gTol) const;
	/*
    CAXA::Boolean  intersectWith (const CRxGePlanarEnt& plane, int& numOfIntersect,
                                   CRxGePoint3d& p1, CRxGePoint3d& p2,
                                   const CRxGeTol& tol = CrxGeContext::gTol) const;
	*/

    // Projection-intersection with other geometric objects.
    CAXA::Boolean projIntersectWith (const CRxGeLinearEnt3d& line,
                                      const CRxGeVector3d& projDir, int& numInt,
                                      CRxGePoint3d& pntOnArc1,
                                      CRxGePoint3d& pntOnArc2,
                                      CRxGePoint3d& pntOnLine1,
                                      CRxGePoint3d& pntOnLine2,
                                      const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Tangent to the circular arc.
    //
    CAXA::Boolean tangent        (const CRxGePoint3d& pnt, CRxGeLine3d& line,
                                   const CRxGeTol& tol = CrxGeContext::gTol) const;

    CAXA::Boolean tangent        (const CRxGePoint3d& pnt, CRxGeLine3d& line,
                                   const CRxGeTol& tol, CRxGeError& error) const;

		 // Possible error conditions:  kArg1TooBig, kArg1InsideThis, 
		 // kArg1OnThis, kThisIsInfiniteLine

    // Plane of the arc
    //
/*
    void           getPlane       (CRxGePlane& plane) const;
*/

    // Test if point is inside circle.
    //
    CAXA::Boolean isInside       (const CRxGePoint3d& pnt,
                                   const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Definition of circular arc
    //
    CRxGePoint3d    center         () const;
    CRxGeVector3d   normal         () const;
    CRxGeVector3d   refVec         () const;
    double         radius         () const;
    double         startAng       () const;
    double         endAng         () const;
    CRxGePoint3d    startPoint     () const;
    CRxGePoint3d    endPoint       () const;

    CRxGeCircArc3d& setCenter      (const CRxGePoint3d&);
    CRxGeCircArc3d& setAxes        (const CRxGeVector3d& normal,
                                   const CRxGeVector3d& refVec);
    CRxGeCircArc3d& setRadius      (double);
    CRxGeCircArc3d& setAngles      (double startAngle, double endAngle);

    CRxGeCircArc3d& set            (const CRxGePoint3d& cent,
                                   const CRxGeVector3d& nrm, double radius);
    CRxGeCircArc3d& set            (const CRxGePoint3d& cent,
                                   const CRxGeVector3d& nrm,
                                   const CRxGeVector3d& refVec, double radius,
                                   double startAngle, double endAngle);
    CRxGeCircArc3d& set            (const CRxGePoint3d& startPoint, const CRxGePoint3d& pnt,
                                   const CRxGePoint3d& endPoint);


    CRxGeCircArc3d& set            (const CRxGePoint3d& startPoint, const CRxGePoint3d& pnt,
                                   const CRxGePoint3d& endPoint, CRxGeError& error);

			 // Possible errors:  kEqualArg1Arg2, kEqualArg1Arg3, kEqualArg2Arg3, 
			 // kLinearlyDependentArg1Arg2Arg3.
			 // Degenerate results: none.
			 // On error, the object is unchanged.

    CRxGeCircArc3d& set            (const CRxGeCurve3d& curve1,
                                   const CRxGeCurve3d& curve2,
                                   double radius, double& param1, double& param2,
								   CAXA::Boolean& success);
		// On success, this arc becomes the fillet of the given radius between the two curves,
	    // whose points of tangency are nearest param1 and param2 respectively.
    CRxGeCircArc3d& set            (const CRxGeCurve3d& curve1,
                                   const CRxGeCurve3d& curve2,
                                   const CRxGeCurve3d& curve3,
                                   double& param1, double& param2, double& param3,
								   CAXA::Boolean& success);

    // Assignment operator.
    //
    CRxGeCircArc3d& operator =     (const CRxGeCircArc3d& arc);
};

#pragma pack (pop)
#endif
