#ifndef CRX_GELINE3D_H
#define CRX_GELINE3D_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

//

#include "gelent3d.h"
#pragma pack (push, 8)

class CRxGeLine2d;

class
GE_DLLEXPIMPORT
CRxGeLine3d : public CRxGeLinearEnt3d
{
public:
    CRxGeLine3d();
    CRxGeLine3d(const CRxGeLine3d& line);
    CRxGeLine3d(const CRxGePoint3d& pnt, const CRxGeVector3d& vec);
    CRxGeLine3d(const CRxGePoint3d& pnt1, const CRxGePoint3d& pnt2);

    // The x-axis, y-axis, and z-axis lines.
    //
    static const CRxGeLine3d kXAxis;
    static const CRxGeLine3d kYAxis;
    static const CRxGeLine3d kZAxis;

    // Set methods.
    //
    CRxGeLine3d& set(const CRxGePoint3d& pnt, const CRxGeVector3d& vec);
    CRxGeLine3d& set(const CRxGePoint3d& pnt1, const CRxGePoint3d& pnt2);

    // Assignment operator.
    //
    CRxGeLine3d& operator = (const CRxGeLine3d& line);
};

#pragma pack (pop)
#endif
