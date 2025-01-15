//
#ifndef CRX_GEVEC2D_H
#define CRX_GEVEC2D_H
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
#include "gegblge.h"
#include "gegblabb.h"
#include "gedll.h"


#pragma pack (push, 8)

class CRxGeMatrix2d;

class 
	GE_DLLEXPIMPORT
	CRxGeVector2d
{
public:
	CRxGeVector2d();
	CRxGeVector2d(const CRxGeVector2d& vec);
	CRxGeVector2d(double x, double y);

	// The additive identity, x-axis, and y-axis.
	//
	static const   CRxGeVector2d kIdentity;
	static const   CRxGeVector2d kXAxis;
	static const   CRxGeVector2d kYAxis;

	// Matrix multiplication.
	//
	friend
		GE_DLLEXPIMPORT
	CRxGeVector2d   operator *  (const CRxGeMatrix2d& mat, const CRxGeVector2d& vec);
	CRxGeVector2d&  setToProduct(const CRxGeMatrix2d& mat, const CRxGeVector2d& vec);
	CRxGeVector2d&  transformBy (const CRxGeMatrix2d& leftSide);
	CRxGeVector2d&  rotateBy    (double angle);
	CRxGeVector2d&  mirror      (const CRxGeVector2d& line );


	// Scale multiplication.
	//
	CRxGeVector2d   operator *  (double scl) const;
	friend
		GE_DLLEXPIMPORT
		CRxGeVector2d   operator *  (double scl, const CRxGeVector2d& vec);
	CRxGeVector2d&  operator *= (double scl);
	CRxGeVector2d&  setToProduct(const CRxGeVector2d& vec, double scl);
	CRxGeVector2d   operator /  (double scl) const;
	CRxGeVector2d&  operator /= (double scl);

	// Addition and subtraction of vectors.
	//
	CRxGeVector2d   operator +  (const CRxGeVector2d& vec) const;
	CRxGeVector2d&  operator += (const CRxGeVector2d& vec);
	CRxGeVector2d   operator -  (const CRxGeVector2d& vec) const;
	CRxGeVector2d&  operator -= (const CRxGeVector2d& vec);
	CRxGeVector2d&  setToSum    (const CRxGeVector2d& vec1, const CRxGeVector2d& vec2);
	CRxGeVector2d   operator -  () const;
	CRxGeVector2d&  negate      ();

	// Perpendicular vector
	//
	CRxGeVector2d   perpVector  () const;

	// Angle argument.
	//
	double         angle       () const;
	double         angleTo     (const CRxGeVector2d& vec) const;

	// Vector length operations.
	//
	CRxGeVector2d   normal      (const CRxGeTol& tol = CrxGeContext::gTol) const;
	CRxGeVector2d&  normalize   (const CRxGeTol& tol = CrxGeContext::gTol);
	CRxGeVector2d&  normalize   (const CRxGeTol& tol, CRxGeError& flag);
	// Possible errors:  k0This.  Returns object unchanged on error. 
	double         length      () const;
	double         lengthSqrd  () const;
	CAXA::Boolean isUnitLength(const CRxGeTol& tol = CrxGeContext::gTol) const;
	CAXA::Boolean isZeroLength(const CRxGeTol& tol = CrxGeContext::gTol) const;

	// Direction tests.
	//
	CAXA::Boolean isParallelTo(const CRxGeVector2d& vec,
		const CRxGeTol& tol = CrxGeContext::gTol) const;
	CAXA::Boolean isParallelTo(const CRxGeVector2d& vec,
		const CRxGeTol& tol, CRxGeError& flag) const;
	// Possible errors:  k0This, k0Arg1. 
	// Returns kFalse on error.
	CAXA::Boolean isCodirectionalTo(const CRxGeVector2d& vec,
		const CRxGeTol& tol = CrxGeContext::gTol) const;
	CAXA::Boolean isCodirectionalTo(const CRxGeVector2d& vec,
		const CRxGeTol& tol, CRxGeError& flag) const;
	// Possible errors:  k0This, k0Arg1. 
	// Returns kFalse on error.
	CAXA::Boolean isPerpendicularTo(const CRxGeVector2d& vec,
		const CRxGeTol& tol = CrxGeContext::gTol) const;
	CAXA::Boolean isPerpendicularTo(const CRxGeVector2d& vec,
		const CRxGeTol& tol, CRxGeError& flag) const;
	// Possible errors:  k0This, k0Arg1. 
	// Returns kFalse on error.

	// Dot product.
	//
	double         dotProduct  (const CRxGeVector2d& vec) const;

	// Tests for equivalence using the Euclidean norm.
	//
	bool operator == (const CRxGeVector2d& vec) const;
	bool operator != (const CRxGeVector2d& vec) const;
	bool isEqualTo   (const CRxGeVector2d& vec,
		const CRxGeTol& tol = CrxGeContext::gTol) const;

	// For convenient access to the data.
	//
	double         operator [] (unsigned int i) const;
	double&        operator [] (unsigned int i) ;
	CRxGeVector2d&  set         (double x, double y);

	// Convert to/from matrix form.
	//
	operator       CRxGeMatrix2d() const;

	// Co-ordinates.
	//
	double         x, y;
};

// Creates the identity translation vector.
//
__forceinline
CRxGeVector2d::CRxGeVector2d() : x(0.0), y(0.0)
{
}

__forceinline
CRxGeVector2d::CRxGeVector2d(const CRxGeVector2d& src) : x(src.x), y(src.y)
{
}

// Creates a vector intialized to ( xx, yy ).
//
__forceinline
CRxGeVector2d::CRxGeVector2d(double xx, double yy) : x(xx), y(yy)
{
}

__forceinline bool
CRxGeVector2d::operator == (const CRxGeVector2d& v) const
{
	return this->isEqualTo(v);
}

// This operator is the logical negation of the `==' operator.
//
__forceinline bool
CRxGeVector2d::operator != (const CRxGeVector2d& v) const
{
	return !this->isEqualTo(v);
}

// This operator returns a vector that is the scalar product of
// `s' and this vector.
//
__forceinline CRxGeVector2d
CRxGeVector2d::operator * (double s) const
{
	return CRxGeVector2d (x * s, y * s);
}

// This is equivalent to the statement `v = v * s'.
//
__forceinline CRxGeVector2d&
CRxGeVector2d::operator *= (double s)
{
	x *= s;
	y *= s;
	return *this;
}

__forceinline CRxGeVector2d&
CRxGeVector2d::setToProduct(const CRxGeVector2d& v, double s)
{
	x = s * v.x;
	y = s * v.y;
	return *this;
}

// Returns a vector such that each of the coordinates of this vector
// have been divided by val.
//
__forceinline CRxGeVector2d
CRxGeVector2d::operator / (double val) const
{
	return CRxGeVector2d (x/val, y/val);
}

// This is equivalent to the statement `v = v / val;'
// Each coordinate of this vector is divided by val.
//
__forceinline CRxGeVector2d&
CRxGeVector2d::operator /= (double val)
{
	x /= val;
	y /= val;
	return *this;
}

// Returns a vector that is formed from adding the components of
// this vector with `v'.
//
__forceinline CRxGeVector2d
CRxGeVector2d::operator + (const CRxGeVector2d& v) const
{
	return CRxGeVector2d (x + v.x, y + v.y);
}

// This is equivalent to the statement `thisVec = thisVec + v;'
//
__forceinline CRxGeVector2d&
CRxGeVector2d::operator += (const CRxGeVector2d& v)
{
	x += v.x;
	y += v.y;
	return *this;
}

// Using this operator is equivalent to using `thisVec + (-v);'
//
__forceinline CRxGeVector2d
CRxGeVector2d::operator - (const CRxGeVector2d& v) const
{
	return CRxGeVector2d (x - v.x, y - v.y);
}

// This is equivalent to the statement `thisVec = thisVec - v;'
//
__forceinline CRxGeVector2d&
CRxGeVector2d::operator -= (const CRxGeVector2d& v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}

__forceinline CRxGeVector2d&
CRxGeVector2d::setToSum(const CRxGeVector2d& v1, const CRxGeVector2d& v2)
{
	x = v1.x + v2.x;
	y = v1.y + v2.y;
	return *this;
}

// Returns a vector that is formed by negating each of the components
// of this vector.
//
__forceinline CRxGeVector2d
CRxGeVector2d::operator - () const
{
	return CRxGeVector2d (-x, -y);
}

// `v.negate()' is equivalent to the statement `v = -v;'
//
__forceinline CRxGeVector2d&
CRxGeVector2d::negate()
{
	x = -x;
	y = -y;
	return *this;
}

// Returns a vector orthogonal to this vector.
//
__forceinline CRxGeVector2d
CRxGeVector2d::perpVector() const
{
	return CRxGeVector2d (-y, x);
}

// Returns the square of the Euclidean length of this vector.
//
__forceinline double
CRxGeVector2d::lengthSqrd() const
{
	return x*x + y*y;
}

// Returns the dot product of this vector and `v'.
//
__forceinline double
CRxGeVector2d::dotProduct(const CRxGeVector2d& v) const
{
	return x * v.x + y * v.y;
}

// Sets the vector to ( xx, yy ).
//
__forceinline CRxGeVector2d&
CRxGeVector2d::set(double xx, double yy)
{
	x = xx;
	y = yy;
	return *this;
}

// Indexes the vector as if it were an array.  `x' is index `0',
// `y' is index `1'.
//
__forceinline double
CRxGeVector2d::operator [] (unsigned int i) const
{
	return *(&x+i);
}

__forceinline double&
CRxGeVector2d::operator [] (unsigned int i)
{
	return *(&x+i);
}

#pragma pack (pop)
#endif


