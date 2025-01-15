
#ifndef CRX_GETOL_H
#define CRX_GETOL_H
//

//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾

//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷

//

#ifndef unix
#include <stdlib.h>
#endif
#include "gedll.h"
//#include "gedblar.h"
#pragma pack (push, 8)

class
	GE_DLLEXPIMPORT
	CRxGeTol {
public:
	CRxGeTol();

	// Inquiry functions.
	//
	double  equalPoint          () const;
	double  equalVector         () const;

	// Set functions.
	//
	void    setEqualPoint       ( double val );
	void    setEqualVector      ( double val );

private:
	//double				mTolArr[5];
	double				mTolArr[2];
	int                 mAbs;

	friend class CRxGeTolA;
};

// Inlines for CRxGeTol
//

/*__forceinline void CRxGeTol::setEqualVector( double val )
{ mTolArr[1] = val; }

__forceinline double CRxGeTol::equalVector() const
{ return mTolArr[1]; }

__forceinline void CRxGeTol::setEqualPoint( double val )
{ mTolArr[0] = val; }

__forceinline double CRxGeTol::equalPoint() const
{ return mTolArr[0]; }
*/
#pragma pack (pop)
#endif