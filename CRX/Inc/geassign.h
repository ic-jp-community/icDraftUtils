#ifndef CRX_GEASSIGN_H
#define CRX_GEASSIGN_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

//
#pragma pack (push, 8)
class CRxGePoint2d;
class CRxGeVector2d;
class CRxGePoint3d;
class CRxGeVector3d;

inline CRxGePoint2d&
asPnt2d(const double* pnt)
{
    return *((CRxGePoint2d*)pnt);
}

inline CRxGeVector2d&
asVec2d(const double* vec)
{
    return *((CRxGeVector2d*)vec);
}

inline double*
asDblArray(const CRxGePoint2d& pnt)
{
    return (double*)&pnt;
}

inline double*
asDblArray(const CRxGeVector2d& vec)
{
    return (double*)&vec;
}

inline CRxGePoint3d&
asPnt3d(const double* pnt)
{
    return *((CRxGePoint3d*)pnt);
}

inline CRxGeVector3d&
asVec3d(const double* vec)
{
    return *((CRxGeVector3d*)vec);
}

inline double*
asDblArray(const CRxGePoint3d& pnt)
{
    return (double*)&pnt;
}

inline double*
asDblArray(const CRxGeVector3d& vec)
{
    return (double*)&vec;
}

#pragma pack (pop)
#endif
