//
#ifndef CRX_GEMAT3D_H
#define CRX_GEMAT3D_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

//

#include "getol.h"
#include "gegbl.h"
#include "gemat2d.h"
#include "gepnt3d.h"
#include "gedll.h"
#pragma pack (push, 8)

class CRxGeLine3d;
class CRxGeVector3d;
class CRxGePlane;
class CRxGeTol;

class 
	GE_DLLEXPIMPORT
	CRxGeMatrix3d
{
public:
	CRxGeMatrix3d();
	CRxGeMatrix3d(const CRxGeMatrix3d& src);

	// The multiplicative identity.
	//
	static const   CRxGeMatrix3d    kIdentity;

	// Reset matrix.
	//
	CRxGeMatrix3d&  setToIdentity();

	// Multiplication.
	//
	CRxGeMatrix3d   operator *      (const CRxGeMatrix3d& mat) const;
	CRxGeMatrix3d&  operator *=     (const CRxGeMatrix3d& mat);
	CRxGeMatrix3d&  preMultBy       (const CRxGeMatrix3d& leftSide);
	CRxGeMatrix3d&  postMultBy      (const CRxGeMatrix3d& rightSide);
	CRxGeMatrix3d&  setToProduct    (const CRxGeMatrix3d& mat1, const CRxGeMatrix3d& mat2);

	// Multiplicative inverse.
	//
	CRxGeMatrix3d&  invert          ();
	CRxGeMatrix3d   inverse         () const;

	// Test if it is a singular matrix.  A singular matrix is not invertable.
	//
	CAXA::Boolean isSingular      (const CRxGeTol& tol = CrxGeContext::gTol) const;

	// Matrix transposition.
	//
	CRxGeMatrix3d&  transposeIt     ();
	CRxGeMatrix3d   transpose       () const;

	// Tests for equivalence using the infinity norm.
	//
	bool operator ==     (const CRxGeMatrix3d& mat) const;
	bool operator !=     (const CRxGeMatrix3d& mat) const;
	bool isEqualTo       (const CRxGeMatrix3d& mat, const CRxGeTol& tol
		                  = CrxGeContext::gTol) const;

	// Test scaling effects of matrix
	//
	CAXA::Boolean isUniScaledOrtho(const CRxGeTol& tol = CrxGeContext::gTol) const;
	CAXA::Boolean isScaledOrtho   (const CRxGeTol& tol = CrxGeContext::gTol) const;

	// Determinant
	//
	double         det             () const;

	// Set/retrieve translation.
	//
	CRxGeMatrix3d&  setTranslation  (const CRxGeVector3d& vec);
	CRxGeVector3d   translation     () const;

	// Set/get coordinate system
	//
	CRxGeMatrix3d&  setCoordSystem  (const CRxGePoint3d& origin,
		const CRxGeVector3d& xAxis,
		const CRxGeVector3d& yAxis,
		const CRxGeVector3d& zAxis);
	void           getCoordSystem  (CRxGePoint3d& origin,
		CRxGeVector3d& xAxis,
		CRxGeVector3d& yAxis,
		CRxGeVector3d& zAxis) const;

	// Set the matrix to be a specified transformation
	//
	CRxGeMatrix3d&  setToTranslation(const CRxGeVector3d& vec);
	CRxGeMatrix3d&  setToRotation   (double angle, const CRxGeVector3d& axis,
		const CRxGePoint3d& center
		= CRxGePoint3d::kOrigin);
	CRxGeMatrix3d&  setToScaling    (double scaleAll, const CRxGePoint3d& center
		= CRxGePoint3d::kOrigin);
	//CRxGeMatrix3d&  setToMirroring  (const CRxGePlane& pln);
	CRxGeMatrix3d&  setToMirroring  (const CRxGePoint3d& pnt);
	CRxGeMatrix3d&  setToMirroring  (const CRxGeLine3d& line);
	/*CRxGeMatrix3d&  setToProjection (const CRxGePlane& projectionPlane,
		                             const CRxGeVector3d& projectDir);*/
	CRxGeMatrix3d&  setToAlignCoordSys(const CRxGePoint3d& fromOrigin,
		const CRxGeVector3d& fromXAxis,
		const CRxGeVector3d& fromYAxis,
		const CRxGeVector3d& fromZAxis,
		const CRxGePoint3d& toOrigin,
		const CRxGeVector3d& toXAxis,
		const CRxGeVector3d& toYAxis,
		const CRxGeVector3d& toZAxis);

	/*CRxGeMatrix3d&  setToWorldToPlane(const CRxGeVector3d& normal);
	CRxGeMatrix3d&  setToWorldToPlane(const CRxGePlane& plane);
	CRxGeMatrix3d&  setToPlaneToWorld(const CRxGeVector3d& normal);
	CRxGeMatrix3d&  setToPlaneToWorld(const CRxGePlane& plane);*/

	// Similar to above, but creates matrix on the stack.
	//
	static
		CRxGeMatrix3d   translation     (const CRxGeVector3d& vec);
	static
		CRxGeMatrix3d   rotation        (double angle, const CRxGeVector3d& axis,
		const CRxGePoint3d& center
		= CRxGePoint3d::kOrigin);
	static
		CRxGeMatrix3d   scaling         (double scaleAll, const CRxGePoint3d& center
		= CRxGePoint3d::kOrigin);
	/*
	static
	CRxGeMatrix3d   mirroring       (const CRxGePlane& pln);*/
	static
	CRxGeMatrix3d   mirroring       (const CRxGePoint3d& pnt);
	static
	CRxGeMatrix3d   mirroring       (const CRxGeLine3d& line);
	/*static
	CRxGeMatrix3d   projection      (const CRxGePlane& projectionPlane,
		                                const CRxGeVector3d& projectDir);*/
	static
	CRxGeMatrix3d   alignCoordSys   (const CRxGePoint3d&  fromOrigin,
		const CRxGeVector3d& fromXAxis,
		const CRxGeVector3d& fromYAxis,
		const CRxGeVector3d& fromZAxis,
		const CRxGePoint3d&  toOrigin,
		const CRxGeVector3d& toXAxis,
		const CRxGeVector3d& toYAxis,
		const CRxGeVector3d& toZAxis);

	/*
	static
	CRxGeMatrix3d   worldToPlane    (const CRxGeVector3d& normal);
	static
	CRxGeMatrix3d   worldToPlane    (const CRxGePlane&);
	static
	CRxGeMatrix3d   planeToWorld    (const CRxGeVector3d& normal);
	static
	CRxGeMatrix3d   planeToWorld    (const CRxGePlane& pln);*/

	// Get the length of the MAXIMUM column of the
	// 3x3 portion of the matrix.
	//
	double scale(void) const;

	double getScale() const;

	double          norm            () const;

	CRxGeMatrix2d convertToLocal     (CRxGeVector3d& normal, double& elev) const;


	// For convenient access to the data.
	//
	double         operator ()     (unsigned int, unsigned int) const;
	double&        operator ()     (unsigned int, unsigned int);

	// The components of the matrix.
	//
	double         entry[4][4];    // [row][column]

	//CAXA::Boolean  inverse(CRxGeMatrix3d& inv, double tol) const;
/*
private:
	void           pivot           (int, CRxGeMatrix3d&);
	int            pivotIndex(int) const;
	void           swapRows        (int, int, CRxGeMatrix3d&);
*/

/*protected:

		void getCxMat(CMatrix& mat)const;
		void getAcMat3d(const CMatrix& i_cxmat,CRxGeMatrix3d& acmat)const;*/
public:

	void set(const CRxGeMatrix3d& src);
	void set(const double a[4][4] );

public:

	bool   m_bMirror;
	double m_dMirrorAngle;


};

__forceinline bool
CRxGeMatrix3d::operator == (const CRxGeMatrix3d& otherMatrix) const
{
	return this->isEqualTo(otherMatrix);
}

// This operator is the logical negation of the `==' operator.
//
__forceinline bool
CRxGeMatrix3d::operator != (const CRxGeMatrix3d& otherMatrix) const
{
	return !this->isEqualTo(otherMatrix);
}

// Return the element in position [row][column] of the `entry' array.
//
__forceinline double
CRxGeMatrix3d::operator () (
						   unsigned int row,
						   unsigned int column) const
{
	return entry[row][column];
}

__forceinline double&
CRxGeMatrix3d::operator () (
						   unsigned int row,
						   unsigned int column)
{
	return entry[row][column];
}

#pragma pack (pop)
#endif
