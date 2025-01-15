#ifndef CRX_GELENT3D_H
#define CRX_GELENT3D_H
//

//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾

//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷

//

#include "gecurv3d.h"
#include "gevec3d.h"
#include "gepnt3d.h"
#pragma pack (push, 8)

class CRxGeLine3d;
class CRxGeCircArc3d;
//class CRxGePlanarEnt;
class
GE_DLLEXPIMPORT
CRxGeLinearEnt3d : public CRxGeCurve3d
{
public:
    // Intersection with other geometric objects.
    //
    CAXA::Boolean intersectWith (const CRxGeLinearEnt3d& line,
                                  CRxGePoint3d& intPt,
                                  const CRxGeTol& tol = CrxGeContext::gTol) const;

   // CAXA::Boolean intersectWith (const CRxGePlanarEnt& plane, CRxGePoint3d& intPnt,
                                 // const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Projection-intersection with other geometric objects.
    //
    CAXA::Boolean projIntersectWith(const CRxGeLinearEnt3d& line,
                                  const CRxGeVector3d& projDir,
                                  CRxGePoint3d& pntOnThisLine,
                                  CRxGePoint3d& pntOnOtherLine,
                                  const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Find the overlap with other CRxGeLinearEnt object
    //
    CAXA::Boolean overlap       (const CRxGeLinearEnt3d& line,
                                  CRxGeLinearEnt3d*& overlap,
                                  const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Containment tests.
    //
    CAXA::Boolean isOn          (const CRxGePoint3d& pnt,
                                  const CRxGeTol& tol = CrxGeContext::gTol) const;
    CAXA::Boolean isOn          (const CRxGePoint3d& pnt, double& param,
                                  const CRxGeTol& tol = CrxGeContext::gTol) const;
    CAXA::Boolean isOn          (double param,
                                  const CRxGeTol& tol = CrxGeContext::gTol) const;
    //CAXA::Boolean isOn          (const CRxGePlane& plane,
                                 // const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Direction tests.
    //
    CAXA::Boolean isParallelTo  (const CRxGeLinearEnt3d& line,
                                  const CRxGeTol& tol = CrxGeContext::gTol) const;
   // CAXA::Boolean isParallelTo  (const CRxGePlanarEnt& plane,
                                //  const CRxGeTol& tol = CrxGeContext::gTol) const;
    CAXA::Boolean isPerpendicularTo(const CRxGeLinearEnt3d& line,
                                  const CRxGeTol& tol = CrxGeContext::gTol) const;
   // CAXA::Boolean isPerpendicularTo(const CRxGePlanarEnt& plane,
                                 // const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Test if two lines are colinear.
    //
    CAXA::Boolean isColinearTo  (const CRxGeLinearEnt3d& line,
                                  const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Perpendicular through a given point
    //
    //void          getPerpPlane   (const CRxGePoint3d& pnt, CRxGePlane& plane) const;

    // Definition of line.
    //
    CRxGePoint3d    pointOnLine   () const;
    CRxGeVector3d   direction     () const;
    void           getLine       (CRxGeLine3d& o_Line) const;

    // Assignment operator.
    //
    CRxGeLinearEnt3d& operator =  (const CRxGeLinearEnt3d& line);

protected:
    CRxGeLinearEnt3d ();
    CRxGeLinearEnt3d (const CRxGeLinearEnt3d&);
};

#pragma pack (pop)
#endif
