//
#ifndef CRX_GESCL3D_H
#define CRX_GESCL3D_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

//


#include "cdraft.h"
#include "getol.h"
#include "gegbl.h"
#include "gedll.h"
#pragma pack (push, 8)

class CRxGeMatrix3d;

class 
	GE_DLLEXPIMPORT
	CRxGeScale3d
{
public:
	CRxGeScale3d();
	CRxGeScale3d(const CRxGeScale3d& src);
	CRxGeScale3d(double factor);
	CRxGeScale3d(double xFact, double yFact, double zFact);

	// The identity scaling operation.
	//
	static const   CRxGeScale3d kIdentity;

	// Multiplication.
	//
	CRxGeScale3d    operator *  (const CRxGeScale3d& sclVec) const;
	CRxGeScale3d&   operator *= (const CRxGeScale3d& scl);
	CRxGeScale3d&   preMultBy   (const CRxGeScale3d& leftSide);
	CRxGeScale3d&   postMultBy  (const CRxGeScale3d& rightSide);
	CRxGeScale3d&   setToProduct(const CRxGeScale3d& sclVec1, const CRxGeScale3d& sclVec2);
	CRxGeScale3d    operator *  (double s) const;
	CRxGeScale3d&   operator *= (double s);
	CRxGeScale3d&   setToProduct(const CRxGeScale3d& sclVec, double s);
	friend
		GE_DLLEXPIMPORT
		CRxGeScale3d    operator *  (double s, const CRxGeScale3d& scl);

	// Multiplicative inverse.
	//
	CRxGeScale3d    inverse        () const;
	CRxGeScale3d&   invert         ();

	//CAXA::Boolean isProportional(const CRxGeTol& tol = CrxGeContext::gTol) const;

	// Tests for equivalence using the infinity norm.
	//
	bool operator == (const CRxGeScale3d& sclVec) const;
	bool operator != (const CRxGeScale3d& sclVec) const;
	bool isEqualTo   (const CRxGeScale3d& scaleVec,
		const CRxGeTol& tol = CrxGeContext::gTol) const;

	// For convenient access to the data.
	//
	double         operator [] (unsigned int i) const;
	double&        operator [] (unsigned int i);
	CRxGeScale3d&   set         (double sc0, double sc1, double sc2);

	// Conversion to/from matrix form.
	//
	//operator       CRxGeMatrix3d   () const;
	void getMatrix(CRxGeMatrix3d& mat) const;
	//CRxGeScale3d&   extractScale   ( const CRxGeMatrix3d& mat );
	//CRxGeScale3d&   removeScale    ( CRxGeMatrix3d& mat );

	// The scale components in x, y and z.
	//
	double         sx, sy, sz;
};

__forceinline bool
CRxGeScale3d::operator == (const CRxGeScale3d& s) const
{
	return this->isEqualTo(s);
}

// This operator is the logical negation of the `==' operator.
//
__forceinline bool
CRxGeScale3d::operator != (const CRxGeScale3d& s) const
{
	return !(this->isEqualTo(s));
}

// Indexes the scale vector as if it were an array.  `sx' is index `0',
// `sy' is index `1' and `sz' is index `2'.
//
__forceinline double
CRxGeScale3d::operator [] (unsigned int i) const
{
	return *(&sx+i);
}

__forceinline double&
CRxGeScale3d::operator [] (unsigned int i)
{
	return *(&sx+i);
}

#pragma pack (pop)
#endif

