#ifndef CRX_GEPENT2D_H
#define CRX_GEPENT2D_H
//

//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾

//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷

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
