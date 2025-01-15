#ifndef CRX_GEENT2D_H
#define CRX_GEENT2D_H
//

//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾

//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷

//

#include "cdraft.h"
#include "getol.h"
#include "gegbl.h"
#include "gepnt2d.h"
#include "gegblge.h"

//#include "geintrvl.h"
//#include "gegblnew.h"

class CRxGeLine2d;
#pragma pack (push, 8)

class
GE_DLLEXPIMPORT
CRxGeEntity2d
{

public:
    ~CRxGeEntity2d();

    // Run time type information.
    //
    CAXA::Boolean   isKindOf    (CRxGe::EntityId entType) const;
    CRxGe::EntityId   type        () const;//overload

    // Make a copy of the entity.
    //
    CRxGeEntity2d*    copy        () const;//overload
    CRxGeEntity2d&    operator =  (const CRxGeEntity2d& entity);

    // Equivalence
    //
    CAXA::Boolean   operator == (const CRxGeEntity2d& entity) const;
    CAXA::Boolean   operator != (const CRxGeEntity2d& entity) const;
    CAXA::Boolean   isEqualTo   (const CRxGeEntity2d& entity,
                                  const CRxGeTol& tol = CrxGeContext::gTol) const;//overload
                                            
    // Matrix multiplication
    //
    CRxGeEntity2d&    transformBy (const CRxGeMatrix2d& xfm);
    CRxGeEntity2d&    translateBy (const CRxGeVector2d& translateVec);
    CRxGeEntity2d&    rotateBy    (double angle, const CRxGePoint2d& wrtPoint
                                  = CRxGePoint2d::kOrigin);      
    CRxGeEntity2d&    mirror      (const CRxGeLine2d& line);
    CRxGeEntity2d&    scaleBy     (double scaleFactor,
                                  const CRxGePoint2d& wrtPoint
                                  = CRxGePoint2d::kOrigin);
    // Point containment
    //
    CAXA::Boolean   isOn        (const CRxGePoint2d& pnt,
                                  const CRxGeTol& tol = CrxGeContext::gTol) const;

/*protected:
    friend class CRxGeEntity3d;
    friend class CRxGeImpEntity3d;
    CRxGeImpEntity3d* mpImpEnt;
    int mDelEnt;
    CRxGeEntity2d ();
    CRxGeEntity2d (const CRxGeEntity2d&);
    CRxGeEntity2d (CRxGeImpEntity3d&, int);
    CRxGeEntity2d (CRxGeImpEntity3d*);
    CRxGeEntity2d*    newEntity2d (CRxGeImpEntity3d*) const;*/
};


/*__forceinline CRxGeEntity2d*   
CRxGeEntity2d::newEntity2d (CRxGeImpEntity3d *impEnt ) const
{
    return GENEWLOC( CRxGeEntity2d, this) ( impEnt );
}*/

#pragma pack (pop)
#endif
