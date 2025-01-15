#ifndef CRX_GEPONC2D_H
#define CRX_GEPONC2D_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

//

#include "gepent2d.h"
#pragma pack (push, 8)

class CRxGeCurve2d;

class
GE_DLLEXPIMPORT
CRxGePointOnCurve2d : public CRxGePointEnt2d
{
public:
    CRxGePointOnCurve2d  ();
    CRxGePointOnCurve2d  (const CRxGeCurve2d& crv);
    CRxGePointOnCurve2d  (const CRxGeCurve2d& crv, double param);
    CRxGePointOnCurve2d  (const CRxGePointOnCurve2d& src);

    // Assignment operator.
    //
    CRxGePointOnCurve2d& operator =     (const CRxGePointOnCurve2d& src);

    // Query functions.
    //
    const CRxGeCurve2d*  curve          () const;
    double              parameter      () const;

    // Functions to evaluate a point.
    //
    CRxGePoint2d         point          () const;
    CRxGePoint2d         point          (double param);
    CRxGePoint2d         point          (const CRxGeCurve2d& crv, double param);

    // Functions to evaluate the derivatives.
    //
    CRxGeVector2d        deriv          (int order) const;
    CRxGeVector2d        deriv          (int order, double param);
    CRxGeVector2d        deriv          (int order, const CRxGeCurve2d& crv,
                                        double param);
    // Singularity
    //
    CAXA::Boolean      isSingular     (const CRxGeTol&  tol =
                                        CrxGeContext::gTol) const;
    CAXA::Boolean      curvature      (double& res);
    CAXA::Boolean      curvature      (double param, double& res);
    // Set functions.
    //
    CRxGePointOnCurve2d& setCurve       (const CRxGeCurve2d& crv);
    CRxGePointOnCurve2d& setParameter   (double param);
};

#pragma pack (pop)
#endif

