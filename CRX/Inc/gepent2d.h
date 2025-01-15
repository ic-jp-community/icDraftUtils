#ifndef CRX_GEPENT2D_H
#define CRX_GEPENT2D_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

//

#include "cdraft.h"
#include "geent2d.h"
#include "gepnt2d.h"
#pragma pack (push, 8)

class 
GE_DLLEXPIMPORT
CRxGePointEnt2d : public CRxGeEntity2d
{
public:

    // Return point coordinates.
    //
    CRxGePoint2d     point2d     () const;

    // Conversion operator to convert to CRxGePoint2d.
    //
    //operator        CRxGePoint2d () const;
    
    // Assignment operator.
    //
    CRxGePointEnt2d& operator =  (const CRxGePointEnt2d& pnt);

protected:

    // Private constructors so that no object of this class can be instantiated.
    CRxGePointEnt2d ();
    CRxGePointEnt2d (const CRxGePointEnt2d&);
};

#pragma pack (pop)
#endif
