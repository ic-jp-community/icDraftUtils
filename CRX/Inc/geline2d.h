#ifndef CRX_GELINE2D_H
#define CRX_GELINE2D_H
//

//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾

//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷

//

#include "gelent2d.h"
#include "gedll.h"
#pragma pack (push, 8)

class
GE_DLLEXPIMPORT
CRxGeLine2d : public CRxGeLinearEnt2d
{
public:
    CRxGeLine2d();
    CRxGeLine2d(const CRxGeLine2d& line);
    CRxGeLine2d(const CRxGePoint2d& pnt, const CRxGeVector2d& vec);
    CRxGeLine2d(const CRxGePoint2d& pnt1, const CRxGePoint2d& pnt2);

    // The x-axis and y-axis lines.
    //
    static const CRxGeLine2d kXAxis;
    static const CRxGeLine2d kYAxis;

    // Set methods.
    //
    CRxGeLine2d& set (const CRxGePoint2d& pnt, const CRxGeVector2d& vec);
    CRxGeLine2d& set (const CRxGePoint2d& pnt1, const CRxGePoint2d& pnt2);

    // Assignment operator.
    //
    CRxGeLine2d& operator = (const CRxGeLine2d& line);

	


	CRxGe::EntityId   type        () const;//overload
	

	// Make a copy of the entity.
	//
	CRxGeEntity2d*    copy        () const;//overload
};

#pragma pack (pop)
#endif
