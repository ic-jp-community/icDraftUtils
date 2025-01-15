//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#ifndef CRX_DBCURVE_H
#define CRX_DBCURVE_H

// DESCRIPTION: API Abstract class for "Curve" entities.

#include "dbmain.h"
#include "gept3dar.h"
#include "gedblar.h"
#include "geplane.h"
#include "dbptrar.h"

class CRxDbSpline;
class CRxDbEntity;

#pragma pack(push, 8)

CRX_DEFINE_NULL_CLSID(CRxDbCurve)
class CRXDB_API CRxDbCurve: public CRxDbEntity
{
public:
    CRX_DECLARE_DYNAMIC(CRxDbCurve);

    virtual ~CRxDbCurve();

    // Curve property tests.
    //
    virtual CAXA::Boolean    isClosed     () const;      
    virtual CAXA::Boolean    isPeriodic   () const;      

    // Get planar and start/end geometric properties.
    //
    virtual CDraft::ErrorStatus getStartParam(double& o_dPara) const;
    virtual CDraft::ErrorStatus getEndParam  (double& o_dPara) const;
    virtual CDraft::ErrorStatus getStartPoint(CRxGePoint3d& o_startpt) const;
    virtual CDraft::ErrorStatus getEndPoint  (CRxGePoint3d& o_endpt) const;

    // Conversions to/from parametric/world/distance.
    //
    virtual CDraft::ErrorStatus getPointAtParam(double dPara, CRxGePoint3d& o_pt) const;
    virtual CDraft::ErrorStatus getParamAtPoint(const CRxGePoint3d& pt, double& o_dPara)const;
    virtual CDraft::ErrorStatus getDistAtParam (double param, double& dist) const;
    virtual CDraft::ErrorStatus getParamAtDist (double dist, double& param) const;
    virtual CDraft::ErrorStatus getDistAtPoint (const CRxGePoint3d& pt, double& dist)const;
    virtual CDraft::ErrorStatus getPointAtDist (double dist, CRxGePoint3d& o_pt) const;

    // Derivative information.
    //
    virtual CDraft::ErrorStatus getFirstDeriv  (double param,
                                              CRxGeVector3d& firstDeriv) const;
    virtual CDraft::ErrorStatus getFirstDeriv  (const CRxGePoint3d& pt,
                                              CRxGeVector3d& firstDeriv) const;
    virtual CDraft::ErrorStatus getSecondDeriv (double param,
                                              CRxGeVector3d& secDeriv) const;
    virtual CDraft::ErrorStatus getSecondDeriv (const CRxGePoint3d& pt,
                                              CRxGeVector3d& secDeriv) const;

    // Closest point on curve.
    //
    virtual CDraft::ErrorStatus getClosestPointTo(const CRxGePoint3d& givenPnt,
                                                CRxGePoint3d& pointOnCurve,
                                                CAXA::Boolean extend
                                                = CAXA::kFalse) const;
    virtual CDraft::ErrorStatus getClosestPointTo(const CRxGePoint3d& givenPnt,
                                                const CRxGeVector3d& direction,
                                                CRxGePoint3d& pointOnCurve,
                                                CAXA::Boolean extend
                                                = CAXA::kFalse) const;

    // Get a projected copy of the curve.
    //
    virtual CDraft::ErrorStatus getOrthoProjectedCurve(const CRxGePlane&,
                                                CRxDbCurve*& projCrv) const;
    virtual CDraft::ErrorStatus getProjectedCurve(const CRxGePlane&,
                                                const CRxGeVector3d& projDir,
                                                CRxDbCurve*& projCrv) const;

    // Get offset, spline and split copies of the curve.
    //
    virtual CDraft::ErrorStatus getOffsetCurves(double offsetDist,
                                          CRxDbVoidPtrArray& offsetCurves) const;
    virtual CDraft::ErrorStatus getOffsetCurvesGivenPlaneNormal(
        const CRxGeVector3d& normal, double offsetDist,
        CRxDbVoidPtrArray& offsetCurves) const;
    virtual CDraft::ErrorStatus getSpline      (CRxDbSpline*& spline) const;
    virtual CDraft::ErrorStatus getSplitCurves (const CRxGeDoubleArray& params,
                                         CRxDbVoidPtrArray& curveSegments) const;
    virtual CDraft::ErrorStatus getSplitCurves (const CRxGePoint3dArray& points,
                                         CRxDbVoidPtrArray& curveSegments) const;

    // Extend the curve.
    //
    virtual CDraft::ErrorStatus extend(double newParam);
    virtual CDraft::ErrorStatus extend(CAXA::Boolean extendStart,
                                     const CRxGePoint3d& toPoint);

    // Area calculation.
    //
    virtual CDraft::ErrorStatus getArea(double& o_dArea) const;

	virtual  CDraft::ErrorStatus intersectWith(const CRxDbEntity* pEnt,
												CRxDb::Intersect intType, 
												CRxGePoint3dArray& points,
												CAXA::GsMarker thisGsMarker = 0, 
												CAXA::GsMarker otherGsMarker = 0) const;

protected:
    CRxDbCurve();
};

// Protocols of CrxDbCurve available in macro from.

#define DBCURVE_METHODS \
virtual CAXA::Boolean isClosed() const; \
virtual CAXA::Boolean isPeriodic() const; \
virtual CAXA::Boolean isPlanar() const; \
virtual CDraft::ErrorStatus getStartParam(double&) const; \
virtual CDraft::ErrorStatus getEndParam(double&) const; \
virtual CDraft::ErrorStatus getStartPoint(CRxGePoint3d&) const; \
virtual CDraft::ErrorStatus getEndPoint(CRxGePoint3d&) const; \
virtual CDraft::ErrorStatus getPointAtParam(double, CRxGePoint3d&) const; \
virtual CDraft::ErrorStatus getParamAtPoint(const CRxGePoint3d&, double&) const; \
virtual CDraft::ErrorStatus getDistAtParam(double, double&) const; \
virtual CDraft::ErrorStatus getParamAtDist(double, double&) const; \
virtual CDraft::ErrorStatus getDistAtPoint(const CRxGePoint3d&, double&) const; \
virtual CDraft::ErrorStatus getPointAtDist(double, CRxGePoint3d&) const; \
virtual CDraft::ErrorStatus getFirstDeriv(double, CRxGeVector3d&) const; \
virtual CDraft::ErrorStatus getFirstDeriv(const CRxGePoint3d&,CRxGeVector3d&)const;\
virtual CDraft::ErrorStatus getSecondDeriv(double, CRxGeVector3d&) const; \
virtual CDraft::ErrorStatus getSecondDeriv(const CRxGePoint3d&, \
                              CRxGeVector3d&) const; 
//virtual CDraft::ErrorStatus getSpline(CrxDbSpline*&) const; 
//virtual CDraft::ErrorStatus extend(double)\; 
//virtual CDraft::ErrorStatus getClosestPointTo(const CRxGePoint3d&, CRxGePoint3d&, \
//											CAXA::Boolean = CAXA::kFalse) const; \
//virtual CDraft::ErrorStatus getPlane(CRxGePlane&, CRxDb::Planarity&) const; \
//virtual CDraft::ErrorStatus getClosestPointTo(const CRxGePoint3d&, \
//                            const CRxGeVector3d&, CRxGePoint3d&, \
//                          CAXA::Boolean = CAXA::kFalse) const; \
//virtual CDraft::ErrorStatus getOrthoProjectedCurve(const CRxGePlane&, \
//                            CrxDbCurve*&) const; \
//virtual CDraft::ErrorStatus getProjectedCurve(const CRxGePlane&, \
//                            const CRxGeVector3d&, CrxDbCurve*&) const; \
//virtual CDraft::ErrorStatus getOffsetCurves(double, AcDbVoidPtrArray&) const; \

//virtual CDraft::ErrorStatus getSplitCurves(const CRxGeDoubleArray&, \
//                            AcDbVoidPtrArray& curveSegments) const; \
//virtual CDraft::ErrorStatus getSplitCurves(const CrxGePoint3dArray&, \
//                            AcDbVoidPtrArray&) const; \

//virtual CDraft::ErrorStatus extend(CAXA::Boolean, const CRxGePoint3d&); \
//virtual CDraft::ErrorStatus getArea(double&) const;

#pragma pack(pop)

#endif
//Others Curve virtual Method 
