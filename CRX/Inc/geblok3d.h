#ifndef CRX_GEBLOCK3D_H
#define CRX_GEBLOCK3D_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

//

#include "geent3d.h"
#pragma pack (push, 8)
class CRxGePoint3d;
class CRxGeVector3d;

class 
GE_DLLEXPIMPORT
CRxGeBoundBlock3d : public CRxGeEntity3d
{
public:
                    
	CRxGeBoundBlock3d ();
	CRxGeBoundBlock3d (const CRxGePoint3d& base, const CRxGeVector3d& dir1,
					  const CRxGeVector3d& dir2, const CRxGeVector3d& dir3);
	CRxGeBoundBlock3d (const CRxGeBoundBlock3d& block);
    
	// Access methods.
    //    
    void              getMinMaxPoints  (CRxGePoint3d& point1,
								        CRxGePoint3d& point2) const;
    void              get              (CRxGePoint3d& base,
								        CRxGeVector3d& dir1,
								        CRxGeVector3d& dir2,
								        CRxGeVector3d& dir3) const;
	// Set methods.
    //    
    CRxGeBoundBlock3d& set              (const CRxGePoint3d& point1,
								        const CRxGePoint3d& point2);
    CRxGeBoundBlock3d& set              (const CRxGePoint3d& base,
								        const CRxGeVector3d& dir1,
								        const CRxGeVector3d& dir2,
								        const CRxGeVector3d& dir3);
    // Expand to contain point.
    //
    CRxGeBoundBlock3d& extend           (const CRxGePoint3d& point);
   
	// Expand by a specified distance.
    //
    CRxGeBoundBlock3d& swell            (double distance);

    // Containment and intersection tests
    //
    CAXA::Boolean    contains         (const CRxGePoint3d& point) const;
    CAXA::Boolean    isDisjoint       (const CRxGeBoundBlock3d& block) const;

    // Assignment opearator
    //
    CRxGeBoundBlock3d& operator =       (const CRxGeBoundBlock3d& block);

    CAXA::Boolean     isBox    () const;
    CRxGeBoundBlock3d&  setToBox (CAXA::Boolean bflag);
};


#pragma pack (pop)
#endif
