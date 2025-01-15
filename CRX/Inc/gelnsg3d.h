#ifndef CRX_GELNSG3D_H
#define CRX_GELNSG3D_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

//

#include "geline3d.h"
//#include "geplane.h"
#pragma pack (push, 8)

class CRxGeLineSeg2d;

class 
GE_DLLEXPIMPORT
CRxGeLineSeg3d : public CRxGeLinearEnt3d
{
public:
    CRxGeLineSeg3d();
    CRxGeLineSeg3d(const CRxGeLineSeg3d& line);
    CRxGeLineSeg3d(const CRxGePoint3d& pnt, const CRxGeVector3d& vec);
    CRxGeLineSeg3d(const CRxGePoint3d& pnt1, const CRxGePoint3d& pnt2);

    // Bisector.
    //
   // void           getBisector  (CRxGePlane& plane) const;

    // Barycentric combination of end points.
    //
    CRxGePoint3d    baryComb     (double blendCoeff) const;

    // Definition of linear segment
    //
    CRxGePoint3d    startPoint   () const;
    CRxGePoint3d    midPoint     () const;
    CRxGePoint3d    endPoint     () const;
    double         length       () const;
    double         length       (double fromParam, double toParam,
                                 double tol = CrxGeContext::gTol.equalPoint()) const;
    // Set methods.
    //
    CRxGeLineSeg3d& set          (const CRxGePoint3d& pnt, const CRxGeVector3d& vec);
    CRxGeLineSeg3d& set          (const CRxGePoint3d& pnt1, const CRxGePoint3d& pnt2);
   	CRxGeLineSeg3d& set          (const CRxGeCurve3d& curve1,
                                 const CRxGeCurve3d& curve2,
                                 double& param1, double& param2,
                                 CAXA::Boolean& success);
  	CRxGeLineSeg3d& set          (const CRxGeCurve3d& curve,
                                 const CRxGePoint3d& point, double& param,
                                 CAXA::Boolean& success);


    // Assignment operator.
    //
    CRxGeLineSeg3d& operator =   (const CRxGeLineSeg3d& line);
};

#pragma pack (pop)
#endif
