//
#ifndef CRX_GEPNT3D_H
#define CRX_GEPNT3D_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

//

#include "gevec3d.h"

#include "getol.h"
#include "gegbl.h"
#include "gedll.h"

#pragma pack (push, 8)

class CRxGeMatrix3d;
class CRxGeLinearEnt3d;
//class CRxGePlane;
//class CRxGePlanarEnt;
class CRxGeVector3d;
class CRxGePoint2d;

class
	GE_DLLEXPIMPORT
	CRxGePoint3d
{
public:
	CRxGePoint3d();
	CRxGePoint3d(const CRxGePoint3d& pnt);
	CRxGePoint3d(double x, double y, double z);
	//CRxGePoint3d(const CRxGePlanarEnt& pln, const CRxGePoint2d& pnt2d);

	// The origin, or (0, 0, 0).
	//
	static const   CRxGePoint3d    kOrigin;

	// Matrix multiplication.
	//
	friend
		GE_DLLEXPIMPORT
		CRxGePoint3d    operator *  (const CRxGeMatrix3d& mat, const CRxGePoint3d& pnt);
	CRxGePoint3d&   setToProduct(const CRxGeMatrix3d& mat, const CRxGePoint3d& pnt);

	CRxGePoint3d&   transformBy (const CRxGeMatrix3d& leftSide);
	CRxGePoint3d&   rotateBy    (double angle, const CRxGeVector3d& vec,
		const CRxGePoint3d& wrtPoint = CRxGePoint3d::kOrigin);
	//CRxGePoint3d&   mirror      (const CRxGePlane& pln);
	CRxGePoint3d&   scaleBy     (double scaleFactor, const CRxGePoint3d&
		wrtPoint = CRxGePoint3d::kOrigin);
	//CRxGePoint2d    convert2d   (const CRxGePlanarEnt& pln) const;

	// Scale multiplication.
	//
	CRxGePoint3d    operator *  (double scl) const;
	friend
		CRxGePoint3d    operator *  (double scl, const CRxGePoint3d& pnt);
	CRxGePoint3d&   operator *= (double scl);
	CRxGePoint3d    operator /  (double scl) const;
	CRxGePoint3d&   operator /= (double scl);

	// Translation by a vector.
	//
	CRxGePoint3d    operator +  (const CRxGeVector3d& vec) const;
	CRxGePoint3d&   operator += (const CRxGeVector3d& vec);
	CRxGePoint3d    operator -  (const CRxGeVector3d& vec) const;
	CRxGePoint3d&   operator -= (const CRxGeVector3d& vec);
	CRxGePoint3d&   setToSum    (const CRxGePoint3d& pnt, const CRxGeVector3d& vec);

	// Get the vector between two points.
	//
	CRxGeVector3d   operator -  (const CRxGePoint3d& pnt) const;
	CRxGeVector3d   asVector    () const;

	// Distance to other geometric objects.
	//
	double         distanceTo       (const CRxGePoint3d& pnt) const;

	// Projection on plane
	//
	//CRxGePoint3d    project       (const CRxGePlane& pln, const CRxGeVector3d& vec) const;
	//CRxGePoint3d    orthoProject  (const CRxGePlane& pln) const;

	// Tests for equivalence using the Euclidean norm.
	//
	bool operator == (const CRxGePoint3d& pnt) const;
	bool operator != (const CRxGePoint3d& pnt) const;
	bool isEqualTo   (const CRxGePoint3d& pnt,
		const CRxGeTol& tol = CrxGeContext::gTol) const;

	// For convenient access to the data.
	//
	double         operator [] (unsigned int i) const;
	double&        operator [] (unsigned int idx);
	CRxGePoint3d&   set         (double x, double y, double z);
	//CRxGePoint3d&   set         (const CRxGePlanarEnt& pln, const CRxGePoint2d& pnt);

	// The co-ordinates of the point.
	//
	double         x, y, z;
};

// Creates a point at the origin.
//
__forceinline
CRxGePoint3d::CRxGePoint3d() : x(0.0), y(0.0), z(0.0)
{
}

// Creates a point with the same values as `src'.
//
__forceinline
CRxGePoint3d::CRxGePoint3d(const CRxGePoint3d& src) : x(src.x), y(src.y), z(src.z)
{
}

// Creates a point intialized to ( xx, yy, zz ).
//
__forceinline
CRxGePoint3d::CRxGePoint3d(double xx, double yy, double zz) : x(xx), y(yy), z(zz)
{
}

__forceinline bool
CRxGePoint3d::operator == (const CRxGePoint3d& p) const
{
	return this->isEqualTo(p);
}

// This operator is the logical negation of the `==' operator.
//
__forceinline bool
CRxGePoint3d::operator != (const CRxGePoint3d& p) const
{
	return !this->isEqualTo(p);
}

// Returns a point such that each of the coordinates of this point
// have been multiplied by val.
//
__forceinline CRxGePoint3d
CRxGePoint3d::operator * (double val) const
{
	return CRxGePoint3d(x*val, y*val, z*val);
}

// Returns a point such that each of the coordinates of this point
// have been multiplied by val.
//
__forceinline CRxGePoint3d
operator * (double val, const CRxGePoint3d& p)
{
	return CRxGePoint3d(p.x*val, p.y*val, p.z*val);
}

// This is equivalent to the statement `p = p * val;'
// Each coordinate of this point is multiplied by val.
//
__forceinline CRxGePoint3d&
CRxGePoint3d::operator *= (double val)
{
	x *= val;
	y *= val;
	z *= val;
	return *this;
}

// Returns a point such that each of the coordinates of this point
// have been divided by val.
//
__forceinline CRxGePoint3d
CRxGePoint3d::operator / (double val) const
{
	return CRxGePoint3d (x/val, y/val, z/val);
}

// This is equivalent to the statement `p = p / val;'
// Each coordinate of this point is divided by val.
//
__forceinline CRxGePoint3d&
CRxGePoint3d::operator /= (double val)
{
	x /= val;
	y /= val;
	z /= val;
	return *this;
}

// Returns a point that is equivalent to the result of translating
// this point by the vector `v'.  (It yields the same result as if
// the vector had been cast to a translation matrix and then
// multiplied with the point.)
//
__forceinline CRxGePoint3d
CRxGePoint3d::operator + (const CRxGeVector3d& v) const
{
	return CRxGePoint3d (x + v.x, y + v.y, z + v.z);
}

// This is equivalent to the statement `p = p + v;'
//
__forceinline CRxGePoint3d&
CRxGePoint3d::operator += (const CRxGeVector3d& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

// This is equivalent to the statement `p + (-v);'
//
__forceinline CRxGePoint3d
CRxGePoint3d::operator - (const CRxGeVector3d& v) const
{
	return CRxGePoint3d (x - v.x, y - v.y, z - v.z);
}

// This is equivalent to the statement `p = p - v;'
//
__forceinline CRxGePoint3d&
CRxGePoint3d::operator -= (const CRxGeVector3d& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

// This operator returns a vector such that if `v = p1 - p0',
// then, `v' is equivalent to the translation that takes
// `p0' to `p1'.  (This point is `p1').
//
__forceinline CRxGeVector3d
CRxGePoint3d::operator - (const CRxGePoint3d& p) const
{
	return CRxGeVector3d (x - p.x, y - p.y, z - p.z);
}

// This operator returns the vector that would have resulted
// from the operation `p1 - CRxGePoint3d::kOrigin', which is
// a common operation to perform.
//
__forceinline CRxGeVector3d
CRxGePoint3d::asVector() const
{
	return CRxGeVector3d(x, y, z);
}

// Sets the point to ( xx, yy, zz ).
//
__forceinline CRxGePoint3d&
CRxGePoint3d::set(double xx, double yy, double zz)
{
	x = xx;
	y = yy;
	z = zz;
	return *this;
}

// Indexes the point as if it were an array.  `x' is index `0',
// `y' is index `1', `z' is index `2'.
//
__forceinline double
CRxGePoint3d::operator [] (unsigned int i) const
{
	return *(&x+i);
}

__forceinline double&
CRxGePoint3d::operator [] (unsigned int i)
{
	return *(&x+i);
}

#pragma pack (pop)
#endif
