#ifndef GEOMENT_DBELIPSE_H
#define GEOMENT_DBELIPSE_H

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

// DESCRIPTION:
//
// The CrxDbEllipse class represents both a full ellipse and an elliptical
// arc. The parametrization of the ellipse is the vector equation
//
//         P(O) = A * cos(O) + B * sin(O)
// 
// where A and B are the semi major and minor axes respectively.

#include "gegbl.h"
#include "dbmain.h"
#include "dbcurve.h"

#pragma pack(push, 8)

CRX_DEFINE_CLSID(85DC7B5D-DAAC-47C8-A126-FFAD50D6CD68,CRxDbEllipse)
class CRXDB_API CRxDbEllipse: public  CRxDbCurve
{
public:
    CRxDbEllipse(ICxCrxObject *i_pCrxObject = NULL);
    CRxDbEllipse(const CRxGePoint3d&  center,
                const CRxGeVector3d& unitNormal,
                const CRxGeVector3d& majorAxis,
                double              radiusRatio,
                double              startAngle = 0.0,
                double              endAngle   = 6.28318530717958647692);
    //virtual ~CrxDbEllipse();
    CRX_DECLARE_DYNCREATE(CRxDbEllipse);

    CRxGePoint3d center() const;
    CDraft::ErrorStatus setCenter(const CRxGePoint3d& center);

    CRxGeVector3d normal() const;
    CRxGeVector3d majorAxis() const;
    CRxGeVector3d minorAxis() const;

    double radiusRatio() const;
    CDraft::ErrorStatus setRadiusRatio(double ratio);

    double startAngle() const;
    CDraft::ErrorStatus setStartAngle(double startAngle);    

    double endAngle() const;
    CDraft::ErrorStatus setEndAngle(double endAngle);

    //CDraft::ErrorStatus setStartParam(double startParam);
    //CDraft::ErrorStatus setEndParam(double endParam);

    //double paramAtAngle(double angle) const;
    //double angleAtParam(double param) const;

    CDraft::ErrorStatus get(CRxGePoint3d& center, CRxGeVector3d& unitNormal,
        CRxGeVector3d& majorAxis, double& radiusRatio, double& startAngle,
        double& endAngle) const;
    CDraft::ErrorStatus set(const CRxGePoint3d& center,
        const CRxGeVector3d& unitNormal, const CRxGeVector3d& majorAxis,
        double radiusRatio, double startAngle = 0.0,
        double endAngle = 6.28318530717958647692);

    //CAXA::Boolean isNull() const;
  
    DBCURVE_METHODS

		CDraft::ErrorStatus getOffsetCurves(double offsetDist,
		                                              CRxDbVoidPtrArray& offsetCurves) const;

    //virtual CDraft::ErrorStatus getGripPoints(CrxGePoint3dArray&    gripPoints,
    //        CRxDbIntArray& osnapMasks, CRxDbIntArray & geomIds) const;

    //virtual  CDraft::ErrorStatus moveGripPointsAt(
    //    const CRxDbIntArray& indices, const CRxGeVector3d& offset);

    //virtual  CDraft::ErrorStatus intersectWith(
    //    const CrxDbEntity* ent, CRxDb::Intersect intType,
    //    CrxGePoint3dArray& points, CAXA::GsMarker thisGsMarker = 0,
    //    CAXA::GsMarker otherGsMarker = 0) const;

    //virtual  CDraft::ErrorStatus intersectWith(
    //    const CrxDbEntity* ent, CRxDb::Intersect intType,
    //    const CRxGePlane& projPlane, CrxGePoint3dArray& points,
    //    CAXA::GsMarker thisGsMarker = 0, CAXA::GsMarker otherGsMarker = 0) const;

    //virtual CDraft::ErrorStatus getTransformedCopy(
    //    const CRxGeMatrix3d& xform, CrxDbEntity*& ent) const;

    //virtual CDraft::ErrorStatus getClassID(CLSID* pClsid) const;
    //virtual void gripStatus(const CRxDb::GripStat status);
    //virtual CDraft::ErrorStatus   getGripPoints(AcDbGripDataPtrArray& grips,
    //    const double curViewUnitSize, const int gripSize, 
    //    const CRxGeVector3d& curViewDir, const int bitflags) const;

    //virtual bool castShadows() const;
    //virtual void setCastShadows(bool newVal);
    //virtual bool receiveShadows() const;
    //virtual void setReceiveShadows(bool newVal);
};

#pragma pack(pop)

#endif
