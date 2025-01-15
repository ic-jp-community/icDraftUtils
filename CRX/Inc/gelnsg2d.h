#ifndef CRX_GELNSG2D_H
#define CRX_GELNSG2D_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

//

#include "geline2d.h"
#pragma pack (push, 8)

class
GE_DLLEXPIMPORT
CRxGeLineSeg2d : public CRxGeLinearEnt2d
{
public:
    CRxGeLineSeg2d();
    CRxGeLineSeg2d(const CRxGeLineSeg2d& line);
    CRxGeLineSeg2d(const CRxGePoint2d& pnt1, const CRxGePoint2d& pnt2);
    CRxGeLineSeg2d(const CRxGePoint2d& pnt, const CRxGeVector2d& vec);

    // Set methods.
    //
    CRxGeLineSeg2d& set(const CRxGePoint2d& pnt, const CRxGeVector2d& vec);
    CRxGeLineSeg2d& set(const CRxGePoint2d& pnt1, const CRxGePoint2d& pnt2);
    CRxGeLineSeg2d& set(const CRxGeCurve2d& curve1,
                       const CRxGeCurve2d& curve2,
                       double& param1, double& param2,
                       CAXA::Boolean& success);
    CRxGeLineSeg2d& set(const CRxGeCurve2d& curve, const CRxGePoint2d& point,
                       double& param, CAXA::Boolean& success);


    // Bisector.
    //
    void           getBisector(CRxGeLine2d& line) const;

    // Barycentric combination of end points.
    //
    CRxGePoint2d    baryComb   (double blendCoeff) const;

    // Definition of linear segment
    //
    CRxGePoint2d    startPoint   () const;
    CRxGePoint2d    midPoint     () const;
    CRxGePoint2d    endPoint     () const;
    double         length       () const;
    double         length       (double fromParam, double toParam,
                                 double tol = CrxGeContext::gTol.equalPoint())const;
    // Assignment operator.
    //
    CRxGeLineSeg2d& operator =  (const CRxGeLineSeg2d& line);

	CRxGe::EntityId   type        () const;//overload

	// Make a copy of the entity.
	//
	CRxGeEntity2d*    copy        () const;
};

#pragma pack (pop)
#endif
