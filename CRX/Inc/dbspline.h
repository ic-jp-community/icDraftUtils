#ifndef CRXDB_DBSPLINE_H
#define CRXDB_DBSPLINE_H
//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//

//
// DESCRIPTION: Exported class for Spline - CrxDbSpline.

#include "gegbl.h"
#include "dbmain.h"
#include "dbcurve.h"

#pragma pack (push, 8)
CRX_DEFINE_CLSID(838896BE-C069-4566-8991-AFD750B4547C,CRxDbSpline)
class  CRXDB_API CRxDbSpline: public  CRxDbCurve
{
public:
    CRX_DECLARE_DYNCREATE(CRxDbSpline);
    CRxDbSpline(ICxCrxObject *i_pCrxObject = NULL);
    //virtual ~CRxDbSpline();
    CRxDbSpline(
               const CRxGePoint3dArray& points,
	       int                     order = 4, 
	       double                  fitTolerance = 0.0);
    CRxDbSpline(
               const CRxGePoint3dArray& points,
	       const CRxGeVector3d&     startTangent,
	       const CRxGeVector3d&     endTangent,
	       int                     order = 4, 
	       double                  fitTolerance = 0.0);

    //CRxDbSpline(
    //           int                     degree, 
	   //    CAXA::Boolean          rational, 
	   //    CAXA::Boolean          closed, 
	   //    CAXA::Boolean          periodic,
	   //    const CrxGePoint3dArray& controlPoints, 
	   //    const CRxGeDoubleArray&  knots, 
	   //    const CRxGeDoubleArray&  weights,
	   //    double                  controlPtTol = 0.0, 
	   //    double                  knotTol = 0.0);

    //CRxDbSpline(
    //           const CRxGePoint3d&  center,
	   //    const CRxGeVector3d& unitNormal,
	   //    const CRxGeVector3d& majorAxis,
	   //    double              radiusRatio,
	   //    double              startAngle = 0.0,
	   //    double              endAngle = 6.28318530717958647692);

    //CAXA::Boolean          isNull() const;

    //CAXA::Boolean          isRational() const;

    int                     degree() const;
    //CDraft::ErrorStatus       elevateDegree(int newDegree);

    int               numControlPoints() const;
    CDraft::ErrorStatus getControlPointAt(int index, CRxGePoint3d& point) const;
    CDraft::ErrorStatus setControlPointAt(int index, const CRxGePoint3d& point);

    //int               numFitPoints() const;
    //CDraft::ErrorStatus getFitPointAt(int index, CRxGePoint3d& point) const;
    //CDraft::ErrorStatus setFitPointAt(int index, const CRxGePoint3d& point);

    //CDraft::ErrorStatus insertFitPointAt(int index, const CRxGePoint3d& point);
    //CDraft::ErrorStatus removeFitPointAt(int index);

    //double            fitTolerance() const;
    //CDraft::ErrorStatus setFitTol(double tol);

    //CDraft::ErrorStatus getFitTangents(CRxGeVector3d& startTangent, 
	//			     CRxGeVector3d& endTangent) const;
    //CDraft::ErrorStatus setFitTangents(const CRxGeVector3d& startTangent, 
	//			     const CRxGeVector3d& endTangent);

    //CAXA::Boolean    hasFitData() const;

    CDraft::ErrorStatus getFitData(CRxGePoint3dArray&  fitPoints, 
			                      int&               degree, 
				                 double&            fitTolerance, 
				                 CAXA::Boolean&    tangentsExist,
                                 CRxGeVector3d&      startTangent, 
				                 CRxGeVector3d&      endTangent) const;

    CDraft::ErrorStatus setFitData(const CRxGePoint3dArray&  fitPoints, 
				                  int                   degree, 
				                  double                fitTolerance, 
                                  const CRxGeVector3d&   startTangent, 
				                  const CRxGeVector3d&   endTangent);

 //   CDraft::ErrorStatus purgeFitData();
 //   CDraft::ErrorStatus updateFitData();

    CDraft::ErrorStatus getNurbsData(
                                  int&              degree, 
		                  CAXA::Boolean&   rational, 
				  CAXA::Boolean&   closed, 
				  CAXA::Boolean&   periodic,
	                          CRxGePoint3dArray& controlPoints, 
				  CRxGeDoubleArray&  knots, 
				  CRxGeDoubleArray&  weights,
				  double&           controlPtTol,
				  double&           knotTol) const;

    CDraft::ErrorStatus setNurbsData(
                                  int                  degree, 
				  CAXA::Boolean       rational, 
				  CAXA::Boolean       closed, 
				  CAXA::Boolean       periodic,
	                          const CRxGePoint3dArray& controlPoints, 
				  const CRxGeDoubleArray& knots, 
				  const CRxGeDoubleArray& weights,
				  double               controlPtTol,
				  double               knotTol);

    double            weightAt(int index) const;
    CDraft::ErrorStatus setWeightAt(int index, double weight);
    CDraft::ErrorStatus insertKnot(double param);
    CDraft::ErrorStatus reverseCurve();

    DBCURVE_METHODS

    //virtual CDraft::ErrorStatus getClassID(CLSID* pClsid) const;

    //CDraft::ErrorStatus getOffsetCurvesGivenPlaneNormal(
    //    const CRxGeVector3d& normal, double offsetDist,
    //    CRxDbVoidPtrArray& offsetCurves) const;

    //virtual bool castShadows() const;
    //virtual void setCastShadows(bool newVal);
    //virtual bool receiveShadows() const;
    //virtual void setReceiveShadows(bool newVal);
};

#pragma pack (pop)

#endif
