#ifndef CRX_GECURV2D_H
#define CRX_GECURV2D_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

//

#include "cdraft.h"
#include "geent2d.h"
//#include "geponc2d.h"
#include "gept2dar.h"
#include "gevc2dar.h"
#include "gedblar.h"
#include "gevptar.h"
#include "geintarr.h"
#include "gegblge.h"
#include "gemat2d.h"

//#include "SptCxGe.h"

#pragma pack (push, 8)

class CRxGePoint2d;
class CRxGeVector2d;
class CRxGePointOnCurve2d;
class CRxGeInterval;
class CRxGeMatrix2d;
class CRxGeLine2d;
//class CRxGePointOnCurve2dData;
class CRxGeBoundBlock2d;

class
	GE_DLLEXPIMPORT
CRxGeCurve2d : public CRxGeEntity2d
{
protected:
	LONG* m_pImpl;
public:

	~CRxGeCurve2d();

	// Parametrization.
	//
	//void        getInterval(CRxGeInterval& intrvl) const;
	//void        getInterval(CRxGeInterval& intrvl, CRxGePoint2d& start,
	                          // CRxGePoint2d& end) const;
	CRxGeCurve2d&   reverseParam();
	//CRxGeCurve2d&   setInterval();
	//CAXA::Boolean setInterval(const CRxGeInterval& intrvl);

	// Distance to other geometric objects.
	//
	double         distanceTo(const CRxGePoint2d& pnt,
		                      const CRxGeTol& = CrxGeContext::gTol) const;
	//double         distanceTo(const CRxGeCurve2d&,
		                     // const CRxGeTol& tol = CrxGeContext::gTol) const;

	// Return the point on this object that is closest to the other object.
	// These methods return point on this curve as a simple 2d point.
	//
	CRxGePoint2d closestPointTo(const CRxGePoint2d& pnt,
		                       const CRxGeTol& tol = CrxGeContext::gTol) const;

	//CRxGePoint2d closestPointTo(const CRxGeCurve2d& curve2d,
		                     //  CRxGePoint2d& pntOnOtherCrv,
		                     //  const CRxGeTol& tol= CrxGeContext::gTol) const;


	// Alternate signatures for above functions.  These methods return point
	// on this curve as an CRxGePointOnCurve2d.
	//
	// void getClosestPointTo(const CRxGePoint2d& pnt,
	                        //CRxGePointOnCurve2d& pntOnCrv,
	                        //const CRxGeTol& tol = CrxGeContext::gTol) const;

	/*void getClosestPointTo(const CRxGeCurve2d& curve2d,
	                       CRxGePointOnCurve2d& pntOnThisCrv,
	                       CRxGePointOnCurve2d& pntOnOtherCrv,
	                       const CRxGeTol& tol = CrxGeContext::gTol) const;*/

	// Return point on curve whose normal vector passes thru input point.
	// Second parameter contains initial guess value and also contains output point.
	// Returns true or false depending on whether a normal point was found.
	//
	//CAXA::Boolean getNormalPoint (const CRxGePoint2d& pnt,
	                           //    CRxGePointOnCurve2d& pntOnCrv,
	                             //  const CRxGeTol& tol = CrxGeContext::gTol) const;

	// Tests if point is on curve.
	//
	CAXA::Boolean isOn(const CRxGePoint2d& pnt,
		                const CRxGeTol& tol = CrxGeContext::gTol) const;

	CAXA::Boolean isOn(const CRxGePoint2d& pnt, double& param,
		                const CRxGeTol& tol = CrxGeContext::gTol) const;

	//CAXA::Boolean isOn(double param,
		               // const CRxGeTol& tol = CrxGeContext::gTol) const;

	// Parameter of the point on curve.  Contract: point IS on curve
	//
	double         paramOf(const CRxGePoint2d& pnt,
		                   const CRxGeTol& tol = CrxGeContext::gTol) const;

	// Return the offset of the curve.
	//
	void           getTrimmedOffset (double distance,
		                             CRxGeVoidPointerArray& offsetCurveList,
		                             CRxGe::OffsetCrvExtType extensionType = CRxGe::kFillet,
		                             const CRxGeTol& tol = CrxGeContext::gTol) const;

	// Geometric inquiry methods.
	//
	CAXA::Boolean isClosed  (const CRxGeTol& tol = CrxGeContext::gTol) const;
	//CAXA::Boolean isPeriodic(double& period) const;
	CAXA::Boolean isLinear  (CRxGeLine2d& line,
		                      const CRxGeTol& tol = CrxGeContext::gTol) const;

	// Length based methods.
	//
	double         length       (double fromParam, double toParam,
		                         double tol = CrxGeContext::gTol.equalPoint()) const;

	double         paramAtLength(double datumParam, double length,
		                         CAXA::Boolean posParamDir = CAXA::kTrue,
		                         double tol = CrxGeContext::gTol.equalPoint()) const;

	//CAXA::Boolean area         (double startParam, double endParam,
		                        // double& value,
		                        // const CRxGeTol& tol = CrxGeContext::gTol) const;

	// Degeneracy.
	//
	//CAXA::Boolean isDegenerate(CRxGe::EntityId& degenerateType,
		                       // const CRxGeTol& tol = CrxGeContext::gTol) const;

	//CAXA::Boolean isDegenerate(CRxGeEntity2d*& pConvertedEntity,
		                       // const CRxGeTol& tol = CrxGeContext::gTol) const;

	// Modify methods.
	//
	void           getSplitCurves (double param, CRxGeCurve2d* & piece1,
		                           CRxGeCurve2d* & piece2) const;

	// Explode curve into its component sub-curves.
	//
	//CAXA::Boolean explode      (CRxGeVoidPointerArray& explodedCurves,
	                           //  CRxGeIntArray& newExplodedCurve,
	                           //  const CRxGeInterval* intrvl = NULL ) const;

	// Local closest points
	//
	/*void getLocalClosestPoints(const CRxGePoint2d& point,
	                           CRxGePointOnCurve2d& approxPnt,
	                           const CRxGeInterval* nbhd = 0,
	                           const CRxGeTol& = CrxGeContext::gTol) const;

	void getLocalClosestPoints(const CRxGeCurve2d& otherCurve,
	                           CRxGePointOnCurve2d& approxPntOnThisCrv,
	                           CRxGePointOnCurve2d& approxPntOnOtherCrv,
	                           const CRxGeInterval* nbhd1 = 0,
	                           const CRxGeInterval* nbhd2 = 0,
	                           const CRxGeTol& tol = CrxGeContext::gTol) const;*/

	// Return oriented bounding box of curve.
	//
	//CRxGeBoundBlock2d  boundBlock() const;
	//CRxGeBoundBlock2d  boundBlock(const CRxGeInterval& range) const;

	//// Return bounding box whose sides are parallel to coordinate axes.
	////
	//CRxGeBoundBlock2d  orthoBoundBlock() const;
	//CRxGeBoundBlock2d  orthoBoundBlock(const CRxGeInterval& range) const;

	// Return start and end points.
	//
	CAXA::Boolean hasStartPoint(CRxGePoint2d& startPoint) const;
	CAXA::Boolean hasEndPoint  (CRxGePoint2d& endPoint) const;

	// Evaluate methods.
	//
	CRxGePoint2d    evalPoint(double param) const;
	CRxGePoint2d    evalPoint(double param, int numDeriv,
		                     CRxGeVector2dArray& derivArray) const;

	// Polygonize curve to within a specified tolerance.
	//
	/*void     getSamplePoints(double fromParam, double toParam,
		                     double approxEps, CrxGePoint2dArray& pointArray,
		                     CRxGeDoubleArray& paramArray) const;*/

	void     getSamplePoints(int numSample, CRxGePoint2dArray& ptarray) const;

	// Assignment operator.
	//
	CRxGeCurve2d&   operator =  (const CRxGeCurve2d& curve);


	//crx
	void             getCxGeCurve(LONG_PTR* o_lppCur)const;
	
	void             copyfrom(const CRxGeCurve2d& entity);

	
	CRxGeEntity2d&    transformBy (const CRxGeMatrix2d& xfm);
	CRxGeEntity2d&    translateBy (const CRxGeVector2d& translateVec);
	CRxGeEntity2d&    rotateBy    (double angle, const CRxGePoint2d& wrtPoint
		                           = CRxGePoint2d::kOrigin);      
	CRxGeEntity2d&    mirror      (const CRxGeLine2d& line);
	CRxGeEntity2d&    scaleBy     (double scaleFactor,
		                          const CRxGePoint2d& wrtPoint
		                          = CRxGePoint2d::kOrigin);

	//CAXA::Boolean   isEqualTo   (const CRxGeEntity2d& entity,
	//	                          const CRxGeTol& tol = CrxGeContext::gTol) const;//overload
	//crx

protected:

	// Private constructors so that no object of this class can be instantiated.
	CRxGeCurve2d ();
	CRxGeCurve2d (const CRxGeCurve2d& entity);
};

#pragma pack (pop)
#endif
