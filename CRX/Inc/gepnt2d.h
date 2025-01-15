//
#ifndef CRX_GEPNT2D_H
#define CRX_GEPNT2D_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

//
#include "gevec2d.h"
#include "getol.h"
#include "gegbl.h"
#include "gedll.h"

#pragma pack (push, 8)

class CRxGeMatrix2d;
class CRxGeVector2d;
class CRxGeLinearEnt2d;
class CRxGeLine2d;

class	
	GE_DLLEXPIMPORT
	CRxGePoint2d
{
public:
	CRxGePoint2d();
	CRxGePoint2d(const CRxGePoint2d& pnt);
	CRxGePoint2d(double x, double y);

	// The origin, or (0, 0).
	//
	static const   CRxGePoint2d kOrigin;

	// Matrix multiplication.
	//
	friend
		GE_DLLEXPIMPORT
	CRxGePoint2d    operator *  (const CRxGeMatrix2d& mat, const CRxGePoint2d& pnt);
	CRxGePoint2d&   setToProduct(const CRxGeMatrix2d& mat, const CRxGePoint2d& pnt);
	CRxGePoint2d&   transformBy (const CRxGeMatrix2d& leftSide);
	CRxGePoint2d&   rotateBy    (double angle, const CRxGePoint2d& wrtPoint
		= CRxGePoint2d::kOrigin);
	CRxGePoint2d&   mirror      (const CRxGeLine2d& line);
	CRxGePoint2d&   scaleBy     (double scaleFactor, const CRxGePoint2d& wrtPoint
		= CRxGePoint2d::kOrigin);

	// Scale multiplication.
	//
	CRxGePoint2d    operator *  (double) const;
	friend
		CRxGePoint2d    operator *  (double, const CRxGePoint2d& scl);
	CRxGePoint2d&   operator *= (double scl);
	CRxGePoint2d    operator /  (double scl) const;
	CRxGePoint2d&   operator /= (double scl);

	// Translation by a vector.
	//
	CRxGePoint2d    operator +  (const CRxGeVector2d& vec) const;
	CRxGePoint2d&   operator += (const CRxGeVector2d& vec);
	CRxGePoint2d    operator -  (const CRxGeVector2d& vec) const;
	CRxGePoint2d&   operator -= (const CRxGeVector2d& vec);
	CRxGePoint2d&   setToSum    (const CRxGePoint2d& pnt, const CRxGeVector2d& vec);

	// Get vector between two points.
	//
	CRxGeVector2d   operator -  (const CRxGePoint2d& pnt) const;
	CRxGeVector2d   asVector    () const;

	// Distance to other geometric objects.
	//
	double         distanceTo  (const CRxGePoint2d& pnt) const;

	// Tests for equivalence using the Euclidean norm.
	//
	bool operator == (const CRxGePoint2d& pnt) const;
	bool operator != (const CRxGePoint2d& pnt) const;
	bool isEqualTo   (const CRxGePoint2d& pnt,
		const CRxGeTol& tol = CrxGeContext::gTol) const;

	// For convenient access to the data.
	//
	double         operator [] (unsigned int i) const;
	double&        operator [] (unsigned int idx);
	CRxGePoint2d&   set         (double x, double y);

	// The co-ordinates of the point.
	//
	double         x, y;
};

// Creates a point at the origin.
//
__forceinline
CRxGePoint2d::CRxGePoint2d() : x(0.0), y(0.0)
{
}

__forceinline
CRxGePoint2d::CRxGePoint2d(const CRxGePoint2d& src) : x(src.x), y(src.y)
{
}

// Creates a point intialized to ( xx, yy ).
//
__forceinline
CRxGePoint2d::CRxGePoint2d(double xx, double yy) : x(xx), y(yy)
{
}

__forceinline bool
CRxGePoint2d::operator == (const CRxGePoint2d& p) const
{
	return this->isEqualTo(p);
}

// This operator is the logical negation of the `==' operator.
//
__forceinline bool
CRxGePoint2d::operator != (const CRxGePoint2d& p) const
{
	return !this->isEqualTo(p);
}

// Returns a point such that each of the coordinates of this point
// have been multiplied by val.
//
__forceinline CRxGePoint2d
CRxGePoint2d::operator * (double val) const
{
	return CRxGePoint2d(x*val, y*val);
}

// Returns a point such that each of the coordinates of this point
// have been multiplied by val.
//
__forceinline CRxGePoint2d
operator * (double val, const CRxGePoint2d& p)
{
	return CRxGePoint2d(p.x*val, p.y*val);
}

// This is equivalent to the statement `p = p * val;'
// Each coordinate of this point is multiplied by val.
//
__forceinline CRxGePoint2d&
CRxGePoint2d::operator *= (double val)
{
	x *= val;
	y *= val;
	return *this;
}

// Returns a point such that each of the coordinates of this point
// have been divided by val.
//
__forceinline CRxGePoint2d
CRxGePoint2d::operator / (double val) const
{
	return CRxGePoint2d (x/val, y/val);
}

// This is equivalent to the statement `p = p / val;'
// Each coordinate of this point is divided by val.
//
__forceinline CRxGePoint2d&
CRxGePoint2d::operator /= (double val)
{
	x /= val;
	y /= val;
	return *this;
}

// Returns a point that is equivalent to the result of translating
// this point by the vector `v'.  (It yields the same result as if
// the vector had been cast to a translation matrix and then
// multiplied with the point.)
//
__forceinline CRxGePoint2d
CRxGePoint2d::operator + (const CRxGeVector2d& v) const
{
	return CRxGePoint2d(x + v.x, y + v.y);
}

// This is equivalent to the statement `p = p + v;'
//
__forceinline CRxGePoint2d&
CRxGePoint2d::operator += (const CRxGeVector2d& v)
{
	x += v.x;
	y += v.y;
	return *this;
}

// This is equivalent to the statement `p + (-v);'
//
__forceinline CRxGePoint2d
CRxGePoint2d::operator - (const CRxGeVector2d& v) const
{
	return CRxGePoint2d(x - v.x, y - v.y);
}

// This is equivalent to the statement `p = p - v;'
//
__forceinline CRxGePoint2d&
CRxGePoint2d::operator -= (const CRxGeVector2d& v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}

// This operator returns a vector such that if `v = p1 - p0',
// then, `v' is equivalent to the translation that takes
// `p0' to `p1'.  (This point is `p1').
//
__forceinline CRxGeVector2d
CRxGePoint2d::operator - (const CRxGePoint2d& p) const
{
	return CRxGeVector2d(x - p.x, y - p.y);
}

// This operator returns the vector that would have resulted
// from the operation `p1 - CRxGePoint2d::kOrigin', which is
// a common operation to perform.
//
__forceinline CRxGeVector2d
CRxGePoint2d::asVector() const
{
	return CRxGeVector2d(x, y);
}

// Sets the point to ( xx, yy ).
//
__forceinline CRxGePoint2d&
CRxGePoint2d::set(double xx, double yy)
{
	x = xx;
	y = yy;
	return *this;
}

//     Indexes the point as if it were an array.  `x' is index `0',
//     `y' is index `1'.
//
__forceinline double
CRxGePoint2d::operator [] (unsigned int i) const
{
	return *(&x+i);
}

__forceinline double&
CRxGePoint2d::operator [] (unsigned int i)
{
	return *(&x+i);
}


#pragma pack (pop)
#endif



