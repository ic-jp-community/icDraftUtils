#ifndef CRX_GESCL2D_H
#define CRX_GESCL2D_H
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

class CRxGeMatrix2d;
class CRxGeScale3d;

class 
	GE_DLLEXPIMPORT
	CRxGeScale2d
{
public:
	CRxGeScale2d();
	CRxGeScale2d(const CRxGeScale2d& src);
	CRxGeScale2d(double factor);
	CRxGeScale2d(double xFactor, double yFactor);

	// The identity scaling operation.
	//
	static const   CRxGeScale2d kIdentity;

	// Multiplication.
	//
	CRxGeScale2d    operator *  (const CRxGeScale2d& sclVec) const;
	CRxGeScale2d&   operator *= (const CRxGeScale2d& scl);
	CRxGeScale2d&   preMultBy   (const CRxGeScale2d& leftSide);
	CRxGeScale2d&   postMultBy  (const CRxGeScale2d& rightSide);
	CRxGeScale2d&   setToProduct(const CRxGeScale2d& sclVec1, const CRxGeScale2d& sclVec2);
	CRxGeScale2d    operator *  (double s) const;
	CRxGeScale2d&   operator *= (double s);
	CRxGeScale2d&   setToProduct(const CRxGeScale2d& sclVec, double s);
	friend
		GE_DLLEXPIMPORT
		CRxGeScale2d    operator *  (double s, const CRxGeScale2d& scl);

	// Multiplicative inverse.
	//
	CRxGeScale2d    inverse        () const;
	CRxGeScale2d&   invert         ();

	//CAXA::Boolean isProportional(const CRxGeTol& tol = CrxGeContext::gTol) const;

	// Tests for equivalence using the infinity norm.
	//
	bool operator == (const CRxGeScale2d& sclVec) const;
	bool operator != (const CRxGeScale2d& sclVec) const;
	bool isEqualTo   (const CRxGeScale2d& scaleVec,
		const CRxGeTol& tol = CrxGeContext::gTol) const;

	// For convenient access to the data.
	//
	double         operator [] (unsigned int i) const;
	double&        operator [] (unsigned int i);
	CRxGeScale2d&   set         (double sc0, double sc1);

	// Conversion to/from matrix form.
	//
	//operator       CRxGeMatrix2d   () const;
	void           getMatrix      (CRxGeMatrix2d& mat) const;
	//CRxGeScale2d&   extractScale   ( const CRxGeMatrix2d& mat );
	//CRxGeScale2d&   removeScale    ( CRxGeMatrix2d& mat );

	// Cast up to 3d scale.
	//
	//operator       CRxGeScale3d    () const;

	// The scale components in x and y.
	//
	double         sx, sy;
};

__forceinline double
CRxGeScale2d::operator [] (unsigned int i) const
{
	return *(&sx+i);
}

__forceinline double&
CRxGeScale2d::operator [] (unsigned int i)
{
	return *(&sx+i);
}

__forceinline bool
CRxGeScale2d::operator == (const CRxGeScale2d& s) const
{
	return this->isEqualTo(s);
}

// This operator is the logical negation of the `==' operator.
//
__forceinline bool
CRxGeScale2d::operator != (const CRxGeScale2d& s) const
{
	return !this->isEqualTo(s);
}

#pragma pack (pop)
#endif
