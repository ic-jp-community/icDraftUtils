#ifndef CRX_DBPL_H
#define CRX_DBPL_H 1

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

// DESCRIPTION:  Lightweight polyline API header file.
//

#include "dbmain.h"
#include "dbcurve.h"

#include "gelnsg2d.h"
#include "gelnsg3d.h"
#include "gearc2d.h"
#include "gearc3d.h"
#include "gept2dar.h"

#pragma pack(push, 8)

class CRxDb2dPolyline;

CRX_DEFINE_CLSID(56D8E732-AD1F-426D-A4B0-6C5998434583,CRxDbPolyline)
class CRXDB_API CRxDbPolyline : public CRxDbCurve
{

public:
                      CRxDbPolyline(ICxCrxObject *i_pCrxObject = NULL);
                      CRxDbPolyline(unsigned int num_verts);
   //virtual          ~CRxDbPolyline();


    CRX_DECLARE_DYNCREATE(CRxDbPolyline);


    //**********************************************************************
    // CRxDbPolyline methods.
    //**********************************************************************

    //CDraft::ErrorStatus convertFrom(CrxDbEntity*& pPline, 
    //                              CAXA::Boolean transferId = CAXA::kTrue);
    //CDraft::ErrorStatus convertTo(CRxDb2dPolyline*&  pPline,
    //                            CAXA::Boolean transferId = CAXA::kTrue) const;

    CDraft::ErrorStatus getPointAt(unsigned int, CRxGePoint3d& pt) const;

    enum SegType {
        kLine,
        kArc,
        kCoincident,
        kPoint,
        kEmpty
    };

    //SegType           segType           (unsigned int index) const;

	CDraft::ErrorStatus   newVertexs(unsigned int i_iNum);

    CDraft::ErrorStatus getLineSegAt      (unsigned int index,
                                         CRxGeLineSeg2d& ln) const;
    //CDraft::ErrorStatus getLineSegAt      (unsigned int index,
                                        // CRxGeLineSeg3d& ln) const;
    CDraft::ErrorStatus getArcSegAt       (unsigned int index,
                                        CRxGeCircArc2d& arc) const;
   // CDraft::ErrorStatus getArcSegAt       (unsigned int index,
                                       //  CRxGeCircArc3d& arc) const;
    virtual CAXA::Boolean onSegAt      (unsigned int index, const CRxGePoint2d& pt2d,
                                         double& param) const;

    ////**********************************************************************
    //// CRxDbPolyline methods.
    ////**********************************************************************
   
    void              setClosed       (CAXA::Boolean bClosed);
    //void              setPlinegen     (CAXA::Boolean);
    //void              setElevation    (double);
   // CDraft::ErrorStatus setThickness    (double);
    CDraft::ErrorStatus setConstantWidth(double dWidth);
    //CDraft::ErrorStatus setNormal       (const CRxGeVector3d&);

    CAXA::Boolean    isClosed        ()                        const;      
    //CAXA::Boolean    isOnlyLines     ()                        const;
    //CAXA::Boolean    hasPlinegen     ()                        const;
    //double            elevation       ()                        const;
   // double            thickness       ()                        const;
    CDraft::ErrorStatus getConstantWidth(double& dWidth)                 const;
    //CRxGeVector3d      normal          ()                        const;

    CDraft::ErrorStatus addVertexAt     (unsigned int index,
                                       const CRxGePoint2d& pt,
                                       double bulge = 0.,
                                       double startWidth = 0.,
                                       double endWidth = 0.);

    CDraft::ErrorStatus removeVertexAt  (unsigned int index);

    unsigned int      numVerts        ()                        const;

    CDraft::ErrorStatus getPointAt        (unsigned int index,
                                       CRxGePoint2d& pt)         const;
    CDraft::ErrorStatus getBulgeAt      (unsigned int index,
                                       double&      bulge)      const;
    CDraft::ErrorStatus getWidthsAt     (unsigned int index,
                                       double&      startWidth,
                                       double&      endWidth)   const;

    CDraft::ErrorStatus setPointAt      (unsigned int index,
                                       const CRxGePoint2d& pt);
    CDraft::ErrorStatus setBulgeAt      (unsigned int index,
                                       double       bulge);
    CDraft::ErrorStatus setWidthsAt     (unsigned int index,
                                       double       startWidth,
                                       double       endWidth);

    //CDraft::ErrorStatus minimizeMemory  ();
    //CDraft::ErrorStatus maximizeMemory  ();

    void              reset           (CAXA::Boolean reuse,
                                       unsigned int numVerts);


    CAXA::Boolean     hasBulges       ()        const;
    CAXA::Boolean     hasWidth        ()        const;

    ////**********************************************************************
    //// CrxDbCurve methods.
    ////**********************************************************************

    virtual CAXA::Boolean    isPeriodic   () const;      
    virtual CAXA::Boolean    isPlanar     () const;

    //virtual CDraft::ErrorStatus getPlane       (CRxGePlane&         plane, 
    //                                          CRxDb::Planarity&   type) const; 

    virtual CDraft::ErrorStatus getStartParam  (double&      startParam) const;
    virtual CDraft::ErrorStatus getEndParam    (double&      endParam)   const;
    virtual CDraft::ErrorStatus getStartPoint  (CRxGePoint3d& startPoint) const;
    virtual CDraft::ErrorStatus getEndPoint    (CRxGePoint3d& endPoint)   const; 

    virtual CDraft::ErrorStatus getPointAtParam(double             param, 
                                              CRxGePoint3d&       point) const;
    virtual CDraft::ErrorStatus getParamAtPoint(const CRxGePoint3d& point,
                                              double&            param) const;
    virtual CDraft::ErrorStatus getDistAtParam (double             param,
                                              double&            dist)  const;
    virtual CDraft::ErrorStatus getParamAtDist (double             dist,
                                              double&            param) const; 
    virtual CDraft::ErrorStatus getDistAtPoint (const CRxGePoint3d& point,
                                              double&            dist)  const;
    virtual CDraft::ErrorStatus getPointAtDist (double             dist,
                                              CRxGePoint3d&       point) const;


    virtual CDraft::ErrorStatus getFirstDeriv (double             param, 
                                          CRxGeVector3d&      firstDeriv) const;
    virtual CDraft::ErrorStatus getFirstDeriv (const CRxGePoint3d& point, 
                                          CRxGeVector3d&      firstDeriv) const;
    virtual CDraft::ErrorStatus getSecondDeriv(double             param, 
                                          CRxGeVector3d&      secondDeriv)const;
    virtual CDraft::ErrorStatus getSecondDeriv(const CRxGePoint3d& point, 
                                          CRxGeVector3d&      secondDeriv)const;


    virtual CDraft::ErrorStatus getClosestPointTo(const CRxGePoint3d& givenPoint,
                                          CRxGePoint3d&       pointOnCurve,
                                          CAXA::Boolean     extend = 
                                                               CAXA::kFalse) 
                                                               const;

    virtual CDraft::ErrorStatus getClosestPointTo(const CRxGePoint3d&  givenPoint,
                                          const CRxGeVector3d& normal,
                                          CRxGePoint3d&        pointOnCurve,
                                          CAXA::Boolean      extend = 
                                                                CAXA::kFalse) 
                                                                      const;

    //virtual CDraft::ErrorStatus getOrthoProjectedCurve(const CRxGePlane&  plane,
    //                                      CrxDbCurve*&       projectedCurve) 
    //                                                                  const;

    //virtual CDraft::ErrorStatus getProjectedCurve(const CRxGePlane&    plane,
    //                              const CRxGeVector3d& projDir,
    //                              CrxDbCurve*&       projectedCurve) const;

    //virtual CDraft::ErrorStatus getOffsetCurves(double offsetDist,
                                  //CRxDbVoidPtrArray&  offsetCurves)  const;

   virtual CDraft::ErrorStatus getSpline(CRxDbSpline*& spline) const; 

   virtual CDraft::ErrorStatus   extend(CAXA::Boolean extendStart,const CRxGePoint3d& toPoint);

   CAXA::Boolean isOnlyLines() const;

    //virtual CDraft::ErrorStatus getSplitCurves(
    //                              const CRxGeDoubleArray& parameters,
    //                              CRxDbVoidPtrArray&  curveSegments) const;

    //virtual CDraft::ErrorStatus getSplitCurves(
    //                              const CrxGePoint3dArray& points,
    //                              CRxDbVoidPtrArray&       curveSegments) const;

   // virtual CDraft::ErrorStatus extend(double          newParam);

   // virtual CDraft::ErrorStatus extend(CAXA::Boolean     extendStart,
                                    // const CRxGePoint3d& toPoint);

    //virtual CDraft::ErrorStatus getArea(double& area) const; 


    ////*************************************************************************
    //// Overridden methods from CRxDbEntity
    ////*************************************************************************

    //virtual CDraft::ErrorStatus getOsnapPoints(CRxDb::OsnapMode osnapMode,
    //                                         CAXA::GsMarker gsSelectionMark,
    //                                         const CRxGePoint3d&  pickPoint,
    //                                         const CRxGePoint3d&  lastPoint,
    //                                         const CRxGeMatrix3d& viewXform,
    //                                         CrxGePoint3dArray&      snapPoints,
    //                                         CRxDbIntArray &   geomIds)
    //                                         const;

    //virtual CDraft::ErrorStatus getGripPoints(CrxGePoint3dArray&    gripPoints,
    //                                        CRxDbIntArray& osnapMasks,
    //                                        CRxDbIntArray & geomIds)
    //                                        const;

    //virtual CDraft::ErrorStatus moveGripPointsAt(const CRxDbIntArray& indices,  
    //                                           const CRxGeVector3d& offset);

    //virtual CDraft::ErrorStatus intersectWith(const CrxDbEntity* ent,
    //                                        CRxDb::Intersect intType,
    //                                        CrxGePoint3dArray& points,
    //                                        CAXA::GsMarker thisGsMarker  = 0,
    //                                        CAXA::GsMarker otherGsMarker = 0)
    //                                        const;

    //virtual CDraft::ErrorStatus intersectWith(const CrxDbEntity* ent,
    //                                         CRxDb::Intersect intType,
    //                                         const CRxGePlane& projPlane,
    //                                         CrxGePoint3dArray& points,
    //                                         CAXA::GsMarker thisGsMarker  = 0,
    //                                         CAXA::GsMarker otherGsMarker = 0)
    //                                         const;

    //virtual CDraft::ErrorStatus getStretchPoints(CrxGePoint3dArray&  stretchPoints)
    //                                           const;

    //virtual CDraft::ErrorStatus moveStretchPointsAt(const CRxDbIntArray& 
    //                                             indices,
    //                                             const CRxGeVector3d& offset);

    //virtual CDraft::ErrorStatus transformBy(const CRxGeMatrix3d& xform);

    //virtual CDraft::ErrorStatus getTransformedCopy(const CRxGeMatrix3d& xform,
    //                                             CrxDbEntity*& ent) const;

    //virtual void              getEcs(CRxGeMatrix3d& retVal) const;

    //virtual CDraft::ErrorStatus getGeomExtents(CRxDbExtents& extents) const;

    //virtual CrxDbEntity*       subentPtr(const CrxDbFullSubentPath& id) const;
    //virtual CDraft::ErrorStatus getSubentPathsAtGsMarker(
    //                             CRxDb::SubentType     type, 
    //                             CAXA::GsMarker      gsMark,
    //                             const CRxGePoint3d&   pickPoint,
    //                             const CRxGeMatrix3d&  viewXform,
    //                             int&                 numIds, 
    //                             CrxDbFullSubentPath*& subentIds,
    //                             int                  numInserts,
    //                             CrxDbObjectId*        entAndInsertStack)
    //                                                                 const;

    //virtual CDraft::ErrorStatus explode(CRxDbVoidPtrArray& entitySet) const;

    //virtual CAXA::Boolean    worldDraw   (CRxGiWorldDraw* mode);
    //virtual void              viewportDraw(CRxGiViewportDraw* mode);

    //virtual CDraft::ErrorStatus applyPartialUndo(CRxDbDwgFiler* filer,
    //                                           CrxRxClass*    classobj);

    //virtual bool              castShadows() const;
    //virtual bool              receiveShadows() const;

    ////*************************************************************************
    //// Overridden methods from CrxDbObject
    ////*************************************************************************

    //virtual CDraft::ErrorStatus dwgInFields(CRxDbDwgFiler* filer);
    //virtual CDraft::ErrorStatus dwgOutFields(CRxDbDwgFiler* filer) const;
    //virtual CDraft::ErrorStatus dxfInFields(CRxDbDxfFiler* filer);
    //virtual CDraft::ErrorStatus dxfOutFields(CRxDbDxfFiler* filer) const;

    //virtual void              saveAs(CRxGiWorldDraw* mode,
    //                                 CRxDb::SaveType st);

    //virtual CDraft::ErrorStatus getClassID(CLSID* pClsid) const;
    //virtual void gripStatus(const CRxDb::GripStat status);
    //virtual CDraft::ErrorStatus   getGripPoints(CRxDbGripDataPtrArray& grips,
    //    const double curViewUnitSize, const int gripSize, 
    //    const CRxGeVector3d& curViewDir, const int bitflags) const;
};

//
inline CAXA::Boolean CRxDbPolyline::isPlanar() const
{
    return CAXA::kTrue;
}

inline CDraft::ErrorStatus CRxDbPolyline::getStartParam(double& startParam) const
{
    startParam = 0.;
    return CDraft::eOk;
}

inline CDraft::ErrorStatus CRxDbPolyline::getSpline(CRxDbSpline*& spline) const
{
    return CDraft::eNotApplicable;
}

#pragma pack(pop)

#endif /*AD_DBPL_H*/
