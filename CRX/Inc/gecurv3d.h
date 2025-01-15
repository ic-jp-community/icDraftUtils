#ifndef CRX_GECURV3D_H
#define CRX_GECURV3D_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

//

#include "cdraft.h"
#include "geent3d.h"
//#include "geponc3d.h"
#include "gept3dar.h"
#include "gevc3dar.h"
#include "gedblar.h"
#include "gevptar.h"
#include "geintarr.h"
#pragma pack (push, 8)

class CRxGeCurve2d;
//class CRxGeSurface;
class CRxGePoint3d;
//class CRxGePlane;
class CRxGeVector3d;
//class CRxGeLinearEnt3d;
//class CRxGeLine3d;
//class CRxGePointOnCurve3d;
//class CRxGePointOnSurface;
//class CRxGeInterval;
class CRxGeMatrix3d;
//class CRxGePointOnCurve3dData;
//class CRxGeBoundBlock3d;

class
GE_DLLEXPIMPORT
CRxGeCurve3d : public CRxGeEntity3d
{

	

protected:
	LONG* m_pImpl;

public:

	~CRxGeCurve3d();

    // Parametrization.
    //
	/*
    void           getInterval(CRxGeInterval& intrvl) const;
    void           getInterval(CRxGeInterval& intrvl, CRxGePoint3d& start,
                               CRxGePoint3d& end) const;
	*/
    CRxGeCurve3d&   reverseParam();
	CRxGeCurve3d&   setInterval();
	//CAXA::Boolean setInterval(const CRxGeInterval& intrvl);

    // Distance to other geometric objects.
    //
    double       distanceTo(const CRxGePoint3d& pnt,
                            const CRxGeTol& tol = CrxGeContext::gTol) const;
    double       distanceTo(const CRxGeCurve3d& curve,
                            const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Return the point on this object that is closest to the other object.
    // These methods return point on this curve as a simple 3d point.
    //
    CRxGePoint3d closestPointTo(const CRxGePoint3d& pnt,
                               const CRxGeTol& tol = CrxGeContext::gTol) const;
    CRxGePoint3d closestPointTo(const CRxGeCurve3d& curve3d,
                               CRxGePoint3d& pntOnOtherCrv,
                               const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Alternate signatures for above functions.  These methods return point
    // on this curve as an CRxGePointOnCurve3d.
    //
/*
    void getClosestPointTo(const CRxGePoint3d& pnt, CRxGePointOnCurve3d& pntOnCrv,
                           const CRxGeTol& tol = CrxGeContext::gTol) const;


    void getClosestPointTo(const CRxGeCurve3d& curve3d,
                           CRxGePointOnCurve3d& pntOnThisCrv,
                           CRxGePointOnCurve3d& pntOnOtherCrv,
                           const CRxGeTol& tol = CrxGeContext::gTol) const;
*/

    // Return closest points when projected in a given direction.
    // These methods return point on this curve as a simple 3d point.
    //
    CRxGePoint3d projClosestPointTo(const CRxGePoint3d& pnt,
                                   const CRxGeVector3d& projectDirection,
                                   const CRxGeTol& tol = CrxGeContext::gTol) const;

    CRxGePoint3d projClosestPointTo(const CRxGeCurve3d& curve3d,
                                   const CRxGeVector3d& projectDirection,
                                   CRxGePoint3d& pntOnOtherCrv,
                                   const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Alternate signatures for above functions.  These methods return point
    // on this curve as an CRxGePointOnCurve3d.
    //
/*
    void getProjClosestPointTo(const CRxGePoint3d& pnt,
                               const CRxGeVector3d& projectDirection,
                               CRxGePointOnCurve3d& pntOnCrv,
                               const CRxGeTol& tol = CrxGeContext::gTol) const;
    void getProjClosestPointTo(const CRxGeCurve3d& curve3d,
                               const CRxGeVector3d& projectDirection,
                               CRxGePointOnCurve3d& pntOnThisCrv,
                               CRxGePointOnCurve3d& pntOnOtherCrv,
                               const CRxGeTol& tol = CrxGeContext::gTol) const;
 */

    // Return point on curve whose normal vector passes thru input point.
    // Second parameter contains initial guess value and also 
    // contains output point.

	// Returns true or false depending on whether a normal point was found.
        //

	/*CAXA::Boolean getNormalPoint(const CRxGePoint3d& pnt,
	                              CRxGePointOnCurve3d& pntOnCrv,
                                      const CRxGeTol& tol = CrxGeContext::gTol) const;*/

    // Return oriented bounding box of curve.
    //

	/*
    CRxGeBoundBlock3d  boundBlock() const;
    CRxGeBoundBlock3d  boundBlock(const CRxGeInterval& range) const;

    // Return bounding box whose sides are parallel to coordinate axes.
    //
    CRxGeBoundBlock3d  orthoBoundBlock() const;
    CRxGeBoundBlock3d  orthoBoundBlock(const CRxGeInterval& range) const;
	*/

    // Project methods.
    //

	/*
    CRxGeEntity3d*  project(const CRxGePlane& projectionPlane,
                           const CRxGeVector3d& projectDirection,
                           const CRxGeTol& tol = CrxGeContext::gTol) const;
    CRxGeEntity3d*  orthoProject(const CRxGePlane& projectionPlane,
                                const CRxGeTol& tol = CrxGeContext::gTol) const;
	*/

    // Tests if point is on curve.
    //
    CAXA::Boolean isOn(const CRxGePoint3d& pnt,
                        const CRxGeTol& tol = CrxGeContext::gTol) const;
    CAXA::Boolean isOn(const CRxGePoint3d& pnt, double& param,
                        const CRxGeTol& tol = CrxGeContext::gTol) const;
    CAXA::Boolean isOn(double param,
                        const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Parameter of the point on curve.  Contract: point IS on curve
    //
    double paramOf(const CRxGePoint3d& pnt, const CRxGeTol& tol = CrxGeContext::gTol)const;

	// Return the offset of the curve.
	//
	void getTrimmedOffset(double distance,
		              const CRxGeVector3d& planeNormal,
			      CRxGeVoidPointerArray& offsetCurveList,
			      CRxGe::OffsetCrvExtType extensionType = CRxGe::kFillet,
                              const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Geometric inquiry methods.
    //

	/*
    CAXA::Boolean isClosed      (const CRxGeTol& tol = CrxGeContext::gTol) const;
    CAXA::Boolean isPlanar      (CRxGePlane& plane,
                                  const CRxGeTol& tol = CrxGeContext::gTol) const;
    CAXA::Boolean isLinear      (CRxGeLine3d& line,
                                  const CRxGeTol& tol = CrxGeContext::gTol) const;
    CAXA::Boolean isCoplanarWith(const CRxGeCurve3d& curve3d,
                                  CRxGePlane& plane,
                                  const CRxGeTol& tol = CrxGeContext::gTol) const;
    CAXA::Boolean isPeriodic    (double& period) const;
	*/

    // Length based methods.
    //
    double         length       (double fromParam, double toParam,
                                 double tol = CrxGeContext::gTol.equalPoint()) const;
    double         paramAtLength(double datumParam, double length,
                                 CAXA::Boolean posParamDir = CAXA::kTrue,
                                 double tol = CrxGeContext::gTol.equalPoint()) const;
    CAXA::Boolean area         (double startParam, double endParam,
                                 double& value,
                                 const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Degeneracy.
    //
    CAXA::Boolean isDegenerate(CRxGe::EntityId& degenerateType,
                                const CRxGeTol& tol = CrxGeContext::gTol) const;
    CAXA::Boolean isDegenerate(CRxGeEntity3d*& pConvertedEntity,
                                const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Modify methods.
    //
    void getSplitCurves(double param, CRxGeCurve3d* & piece1,
                        CRxGeCurve3d* & piece2) const;

	// Explode curve into its component sub-curves.
	//


	/*CAXA::Boolean explode       (CRxGeVoidPointerArray& explodedCurves,
	                              CRxGeIntArray& newExplodedCurves,
				      const CRxGeInterval* intrvl = NULL ) const;*/

    // Local closest points
    //


   /* void getLocalClosestPoints(const CRxGePoint3d& point,
                               CRxGePointOnCurve3d& approxPnt,
                               const CRxGeInterval* nbhd = 0,
                               const CRxGeTol& tol = CrxGeContext::gTol) const;
    void getLocalClosestPoints(const CRxGeCurve3d& otherCurve,
                               CRxGePointOnCurve3d& approxPntOnThisCrv,
                               CRxGePointOnCurve3d& approxPntOnOtherCrv,
                               const CRxGeInterval* nbhd1 = 0,
                               const CRxGeInterval* nbhd2 = 0,
                               const CRxGeTol& tol = CrxGeContext::gTol) const;*/

    // Return start and end points.
    //
    CAXA::Boolean hasStartPoint(CRxGePoint3d& startPnt) const;
    CAXA::Boolean hasEndPoint  (CRxGePoint3d& endPnt) const;

    // Evaluate methods.
    //
    CRxGePoint3d    evalPoint(double param) const;
    CRxGePoint3d    evalPoint(double param, int numDeriv,
                             CRxGeVector3dArray& derivArray) const;

    // Polygonize curve to within a specified tolerance.
    //
    void           getSamplePoints(double fromParam, double toParam,
                                   double approxEps, CRxGePoint3dArray& 
 		                   pointArray, CRxGeDoubleArray& paramArray) const;
    void           getSamplePoints(int numSample, CRxGePoint3dArray& pointArray) const;

    // Assignment operator.
    //
    CRxGeCurve3d&   operator =  (const CRxGeCurve3d& curve);

	//crx
	void             getCxGeCurve(LONG_PTR* o_lppCur)const;

protected:

    // Private constructors so that no object of this class can be instantiated.
    CRxGeCurve3d();
    CRxGeCurve3d(const CRxGeCurve3d&);
};

#pragma pack (pop)
#endif
