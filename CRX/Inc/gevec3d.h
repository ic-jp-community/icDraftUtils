//
#ifndef CRX_GEVEC3D_H
#define CRX_GEVEC3D_H
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
#include "gegblge.h"
#include "gegblabb.h"
#pragma pack (push, 8)

class CRxGeMatrix3d;
class CRxGeVector2d;
//class CRxGePlane;
//class CRxGePlanarEnt;

class 
	GE_DLLEXPIMPORT
	CRxGeVector3d
{
public:
	CRxGeVector3d();
	CRxGeVector3d(const CRxGeVector3d& vec);
	CRxGeVector3d(double x, double y, double z);
	//CRxGeVector3d(const CRxGePlanarEnt&, const CRxGeVector2d&);

	// The additive identity, x-axis, y-axis, and z-axis.
	//
	static const   CRxGeVector3d kIdentity;
	static const   CRxGeVector3d kXAxis;
	static const   CRxGeVector3d kYAxis;
	static const   CRxGeVector3d kZAxis;

	// Multiplication with matrices.
	//
	friend
		GE_DLLEXPIMPORT
		CRxGeVector3d   operator *  (const CRxGeMatrix3d& mat, const CRxGeVector3d& vec);
	CRxGeVector3d&  setToProduct(const CRxGeMatrix3d& mat, const CRxGeVector3d& vec);

	CRxGeVector3d&  transformBy (const CRxGeMatrix3d& leftSide);
	CRxGeVector3d&  rotateBy    (double ang , const CRxGeVector3d& axis );
	CRxGeVector3d&  mirror      (const CRxGeVector3d& normalToPlane);
	//CRxGeVector2d   convert2d   (const CRxGePlanarEnt& pln) const;

	// Multiplication by scalar.
	//
	CRxGeVector3d   operator *  (double scl) const;
	friend
		GE_DLLEXPIMPORT
		CRxGeVector3d   operator *  (double scl, const CRxGeVector3d& vec);
	CRxGeVector3d&  operator *= (double scl);
	CRxGeVector3d&  setToProduct(const CRxGeVector3d& vec, double scl);
	CRxGeVector3d   operator /  (double scl) const;
	CRxGeVector3d&  operator /= (double scl);

	// Addition and subtraction of vectors.
	//
	CRxGeVector3d   operator +  (const CRxGeVector3d& vec) const;
	CRxGeVector3d&  operator += (const CRxGeVector3d& vec);
	CRxGeVector3d   operator -  (const CRxGeVector3d& vec) const;
	CRxGeVector3d&  operator -= (const CRxGeVector3d& vec);
	CRxGeVector3d&  setToSum    (const CRxGeVector3d& vec1, const CRxGeVector3d& vec2);
	CRxGeVector3d   operator -  () const;
	CRxGeVector3d&  negate      ();

	// Perpendicular vector
	//
	CRxGeVector3d   perpVector  () const;

	// Angle argument.
	//
	double         angleTo     (const CRxGeVector3d& vec) const;
	double         angleTo     (const CRxGeVector3d& vec,
		                        const CRxGeVector3d& refVec) const;
	//double         angleOnPlane(const CRxGePlanarEnt& pln) const;

	// Vector length operations.
	//
	CRxGeVector3d   normal      (const CRxGeTol& tol = CrxGeContext::gTol) const;
	CRxGeVector3d&  normalize   (const CRxGeTol& tol = CrxGeContext::gTol);
	CRxGeVector3d&  normalize   (const CRxGeTol& tol, CRxGeError& flag);
	// Possible errors:  k0This.  Returns object unchanged on error. 
	double         length      () const;
	double         lengthSqrd  () const;
	CAXA::Boolean isUnitLength(const CRxGeTol& tol = CrxGeContext::gTol) const;
	CAXA::Boolean isZeroLength(const CRxGeTol& tol = CrxGeContext::gTol) const;

	// Direction tests.
	//
	CAXA::Boolean isParallelTo(const CRxGeVector3d& vec,
		const CRxGeTol& tol = CrxGeContext::gTol) const;
	CAXA::Boolean isParallelTo(const CRxGeVector3d& vec,
		                        const CRxGeTol& tol, CRxGeError& flag) const;
	// Possible errors:  k0This, k0Arg1. 
	// Returns kFalse on error.
	CAXA::Boolean isCodirectionalTo(const CRxGeVector3d& vec,
		const CRxGeTol& tol = CrxGeContext::gTol) const;
	CAXA::Boolean isCodirectionalTo(const CRxGeVector3d& vec,
		                             const CRxGeTol& tol, CRxGeError& flag) const;
	// Possible errors: k0Arg1, k0Arg2, kPerpendicularArg1Arg2. 
	// Returns copy of unchanged object on error.
	CAXA::Boolean isPerpendicularTo(const CRxGeVector3d& vec,
		const CRxGeTol& tol = CrxGeContext::gTol) const;
	CAXA::Boolean isPerpendicularTo(const CRxGeVector3d& vec,
		                             const CRxGeTol& tol, CRxGeError& flag) const;
	// Possible errors: k0Arg1, k0Arg2, kPerpendicularArg1Arg2. 
	// Returns copy of unchanged object on error.

	// Dot and Cross product.
	//
	double         dotProduct  (const CRxGeVector3d& vec) const;
	CRxGeVector3d   crossProduct(const CRxGeVector3d& vec) const;

	// Calculate rotation.
	//
	CRxGeMatrix3d   rotateTo    (const CRxGeVector3d& vec, const CRxGeVector3d& axis
		= CRxGeVector3d::kIdentity) const;

	// Projection on plane
	//
	CRxGeVector3d   project      (const CRxGeVector3d& planeNormal,
		                         const CRxGeVector3d& projectDirection) const;

	/*CRxGeVector3d   project      (const CRxGeVector3d& planeNormal,
		                         const CRxGeVector3d& projectDirection,  
		                         const CRxGeTol& tol, CRxGeError& flag) const;*/

	// Possible errors: k0Arg1, k0Arg2, kPerpendicularArg1Arg2. 
	// Returns copy of unchanged object on error.
	/*CRxGeVector3d   orthoProject (const CRxGeVector3d& planeNormal) const;
	CRxGeVector3d   orthoProject (const CRxGeVector3d& planeNormal, 
		                         const CRxGeTol& tol, CRxGeError& flag) const;*/
	// Possible errors:  k0Arg1.
	// Returns a copy of unchanged object on error. 

	// Tests for equivalence using the Euclidean norm.
	//
	bool operator == (const CRxGeVector3d& vec) const;
	bool operator != (const CRxGeVector3d& vec) const;
	bool isEqualTo   (const CRxGeVector3d& vec,
		const CRxGeTol& tol = CrxGeContext::gTol) const;

	// For convenient access to the data.
	//
	double         operator [] (unsigned int i) const;
	double&        operator [] (unsigned int i);
	unsigned int   largestElement() const;
	CRxGeVector3d&  set         (double x, double y, double z);
	//CRxGeVector3d&  set         (const CRxGePlanarEnt& pln, const CRxGeVector2d& vec);

	// Convert to the matrix of translation.
	//
	//operator       CRxGeMatrix3d() const;

	// Co-ordinates.
	//
	double         x, y, z;
};

// Creates the identity vector.
//
__forceinline
CRxGeVector3d::CRxGeVector3d() : x(0.0), y(0.0), z(0.0)
{
}

__forceinline
CRxGeVector3d::CRxGeVector3d(const CRxGeVector3d& src) : x(src.x),y(src.y),z(src.z)
{
}

// Creates a vector intialized to ( xx, yy, zz ).
//
__forceinline
CRxGeVector3d::CRxGeVector3d(double xx, double yy, double zz) : x(xx),y(yy),z(zz)
{
}

__forceinline bool
CRxGeVector3d::operator == (const CRxGeVector3d& v) const
{
	return this->isEqualTo(v);
}

// This operator is the logical negation of the `==' operator.
//
__forceinline bool
CRxGeVector3d::operator != (const CRxGeVector3d& v) const
{
	return !this->isEqualTo(v);
}

// Returns a vector that is formed from adding the components of
// this vector with `v'.
//
__forceinline CRxGeVector3d
CRxGeVector3d::operator + (const CRxGeVector3d& v) const
{
	return CRxGeVector3d (x + v.x, y + v.y, z + v.z);
}

// This is equivalent to the statement `thisVec = thisVec + v;'
//
__forceinline CRxGeVector3d&
CRxGeVector3d::operator += (const CRxGeVector3d& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

// Using this operator is equivalent to using `thisVec + (-v);'
//
__forceinline CRxGeVector3d
CRxGeVector3d::operator - (const CRxGeVector3d& v) const
{
	return CRxGeVector3d (x - v.x, y - v.y, z - v.z);
}

// This is equivalent to the statement `thisVec = thisVec - v;'
//
__forceinline CRxGeVector3d&
CRxGeVector3d::operator -= (const CRxGeVector3d& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

__forceinline CRxGeVector3d&
CRxGeVector3d::setToSum(const CRxGeVector3d& v1, const CRxGeVector3d& v2)
{
	x = v1.x + v2.x;
	y = v1.y + v2.y;
	z = v1.z + v2.z;
	return *this;
}

// Returns a vector that is formed by negating each of the components
// of this vector.
//
__forceinline CRxGeVector3d
CRxGeVector3d::operator - () const
{
	return CRxGeVector3d (-x, -y, -z);
}

// `v.negate()' is equivalent to the statement `v = -v;'
//
__forceinline CRxGeVector3d&
CRxGeVector3d::negate()
{
	x = -x;
	y = -y;
	z = -z;
	return *this;
}

// This operator returns a vector that is the scalar product of
// `s' and this vector.
//
__forceinline CRxGeVector3d
CRxGeVector3d::operator * (double s) const
{
	return CRxGeVector3d (x * s, y * s, z * s);
}

// This is equivalent to the statement `v = v * s'.
//
__forceinline CRxGeVector3d&
CRxGeVector3d::operator *= (double s)
{
	x *= s;
	y *= s;
	z *= s;
	return *this;
}

__forceinline CRxGeVector3d&
CRxGeVector3d::setToProduct(const CRxGeVector3d& v, double s)
{
	x = s * v.x;
	y = s * v.y;
	z = s * v.z;
	return *this;
}

// Returns a vector such that each of the coordinates of this vector
// have been divided by val.
//
__forceinline CRxGeVector3d
CRxGeVector3d::operator / (double val) const
{
	return CRxGeVector3d (x/val, y/val, z/val);
}

// This is equivalent to the statement `v = v / val;'
// Each coordinate of this vector is divided by val.
//
__forceinline CRxGeVector3d&
CRxGeVector3d::operator /= (double val)
{
	x /= val;
	y /= val;
	z /= val;
	return *this;
}

// Returns the square of the Euclidean length of this vector.
//
__forceinline double
CRxGeVector3d::lengthSqrd() const
{
	return x*x + y*y + z*z;
}

// Returns the dot product of this vector and `v'.
//
__forceinline double
CRxGeVector3d::dotProduct(const CRxGeVector3d& v) const
{
	return x * v.x + y * v.y + z * v.z;
}

// Sets the vector to ( xx, yy, zz ).
//
__forceinline CRxGeVector3d&
CRxGeVector3d::set(double xx, double yy, double zz)
{
	x = xx;
	y = yy;
	z = zz;
	return *this;
}

// Indexes the vector as if it were an array.  `x' is index `0',
// `y' is index `1' and `z' is index `2'.
//
__forceinline double
CRxGeVector3d::operator [] (unsigned int i) const
{
	return *(&x+i);
}

__forceinline double& CRxGeVector3d::operator [] (unsigned int i)
{
	return *(&x+i);
}

#pragma pack (pop)
#endif
