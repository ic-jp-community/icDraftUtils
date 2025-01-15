#ifndef CRX_GEBLOCK2D_H
#define CRX_GEBLOCK2D_H
//

//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾

//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷

//

#include "geent2d.h"
#pragma pack (push, 8)
class CRxGePoint2d;
class CRxGeVector2d;

class 
GE_DLLEXPIMPORT
CRxGeBoundBlock2d : public CRxGeEntity2d
{
public:
                    
	CRxGeBoundBlock2d ();
	CRxGeBoundBlock2d (const CRxGePoint2d& point1, const CRxGePoint2d& point2);
	CRxGeBoundBlock2d (const CRxGePoint2d& base,
                      const CRxGeVector2d& dir1, const CRxGeVector2d& dir2);
	CRxGeBoundBlock2d (const CRxGeBoundBlock2d& block);
    
	// Access methods.
    //    
    void              getMinMaxPoints  (CRxGePoint2d& point1,
								        CRxGePoint2d& point2) const;
    void              get              (CRxGePoint2d& base,
								        CRxGeVector2d& dir1,
								        CRxGeVector2d& dir2) const;
    
	// Set methods.
    //    
    CRxGeBoundBlock2d& set         (const CRxGePoint2d& point1,
                                   const CRxGePoint2d& point2);
    CRxGeBoundBlock2d& set         (const CRxGePoint2d& base,
                                   const CRxGeVector2d& dir1,
                                   const CRxGeVector2d& dir2);
    // Expand to contain point.
    //
    CRxGeBoundBlock2d& extend      (const CRxGePoint2d& point);
   
	// Expand by a specified distance.
    //
    CRxGeBoundBlock2d& swell       (double distance);

    // Containment and intersection tests
    //
    CAXA::Boolean    contains    (const CRxGePoint2d& point) const;
    CAXA::Boolean    isDisjoint  (const CRxGeBoundBlock2d& block)
                                                 const;
    // Assignment operator
    //
    CRxGeBoundBlock2d& operator =  (const CRxGeBoundBlock2d& block);

	CAXA::Boolean    isBox     () const;
	CRxGeBoundBlock2d& setToBox  (CAXA::Boolean);
};


#pragma pack (pop)
#endif
