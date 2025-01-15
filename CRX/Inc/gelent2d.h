#ifndef CRX_GELENT2D_H
#define CRX_GELENT2D_H
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
#pragma pack (push, 8)

class CRxGeCircArc2d;
class CRxGeLine2d;

class
GE_DLLEXPIMPORT
CRxGeLinearEnt2d : public CRxGeCurve2d
{
public:
    // Intersection with other geometric objects.
    //
    CAXA::Boolean   intersectWith  (const CRxGeLinearEnt2d& line, CRxGePoint2d& intPnt,
                                     const CRxGeTol& tol = CrxGeContext::gTol) const;

    // Find the overlap with other CRxGeLinearEnt object
    //
   // CAXA::Boolean   overlap        (const CRxGeLinearEnt2d& line,
                                    // CRxGeLinearEnt2d*& overlap,
                                    // const CRxGeTol& tol = CrxGeContext::gTol) const;
    // Direction tests.
    //
    CAXA::Boolean   isParallelTo   (const CRxGeLinearEnt2d& line,
                                     const CRxGeTol& tol = CrxGeContext::gTol) const;
    CAXA::Boolean   isPerpendicularTo(const CRxGeLinearEnt2d& line,
                                      const CRxGeTol& tol = CrxGeContext::gTol) const;
    // Test if two lines are colinear.
    //
    CAXA::Boolean   isColinearTo   (const CRxGeLinearEnt2d& line,
                                     const CRxGeTol& tol = CrxGeContext::gTol) const;
    // Perpendicular through a given point
    //
    void             getPerpLine    (const CRxGePoint2d& pnt, CRxGeLine2d& perpLine) const;

    // Definition of line.
    //
    CRxGePoint2d      pointOnLine    () const;
    CRxGeVector2d     direction      () const;
    void             getLine        (CRxGeLine2d& line) const;

    // Assignment operator.
    //
    CRxGeLinearEnt2d& operator =     (const CRxGeLinearEnt2d& line);

	 CRxGePoint2d        getPerpPt   (const CRxGePoint2d& pnt) const;


	 CAXA::Boolean isOn(const CRxGePoint2d& pnt,
		 const CRxGeTol& tol = CrxGeContext::gTol) const;

	 

protected:
    CRxGeLinearEnt2d ();
    CRxGeLinearEnt2d (const CRxGeLinearEnt2d& lnentity);
};

#pragma pack (pop)
#endif
