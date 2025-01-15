
#ifndef CRX_GEMAT2D_H
#define CRX_GEMAT2D_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

//
//#include "stdafx.h"

#include "getol.h"
#include "gegbl.h"
#include "gepnt2d.h"
#include "gedll.h"
#pragma pack (push, 8)

class CRxGeVector2d;
class CRxGeLine2d;
//class CRxGePoint2d;
class CRxGeTol;

class 
	GE_DLLEXPIMPORT
	CRxGeMatrix2d
{
public:
	CRxGeMatrix2d();
	CRxGeMatrix2d(const CRxGeMatrix2d& src);

	// The multiplicative identity.
	//
	static const   CRxGeMatrix2d   kIdentity;

	// Reset matrix.
	//
	CRxGeMatrix2d&  setToIdentity();

	
	// Multiplication.
	//
	CRxGeMatrix2d   operator *   (const CRxGeMatrix2d& mat) const;
	CRxGeMatrix2d&  operator *=  (const CRxGeMatrix2d& mat);
	CRxGeMatrix2d&  preMultBy    (const CRxGeMatrix2d& leftSide);
	CRxGeMatrix2d&  postMultBy   (const CRxGeMatrix2d& rightSide);
	CRxGeMatrix2d&  setToProduct (const CRxGeMatrix2d& mat1, const CRxGeMatrix2d& mat2);

	// Multiplicative inverse.
	//
	CRxGeMatrix2d&  invert       ();
	CRxGeMatrix2d   inverse      () const;

	// Test if it is a singular matrix. A singular matrix is not invertable.
	//
	CAXA::Boolean isSingular   (const CRxGeTol& tol = CrxGeContext::gTol) const;

	// Matrix transposition.
	//
	CRxGeMatrix2d&  transposeIt  ();
	CRxGeMatrix2d   transpose    () const;

	// Tests for equivalence using the infinity norm.
	//
	bool operator ==  (const CRxGeMatrix2d& mat) const;
	bool operator !=  (const CRxGeMatrix2d& mat) const;
	bool isEqualTo    (const CRxGeMatrix2d& mat,
		const CRxGeTol& tol = CrxGeContext::gTol) const;

	// Test scaling effects of matrix
	//
	CAXA::Boolean isUniScaledOrtho(const CRxGeTol& tol = CrxGeContext::gTol) const;
	CAXA::Boolean isScaledOrtho(const CRxGeTol& tol = CrxGeContext::gTol) const;
	double		   scale(void);

	// Determinant
	//
	double         det          () const;

	// Set/retrieve translation.
	//
	CRxGeMatrix2d&  setTranslation(const CRxGeVector2d& vec);
	CRxGeVector2d   translation  () const;

	// Retrieve scaling, rotation, mirror components
	//
	//CAXA::Boolean isConformal (double& scale, double& angle,CAXA::Boolean& isMirror, CRxGeVector2d& reflex) const;


	// Set/get coordinate system
	//
	CRxGeMatrix2d&  setCoordSystem(const CRxGePoint2d& origin,
		const CRxGeVector2d& e0,
		const CRxGeVector2d& e1);
	void           getCoordSystem(CRxGePoint2d& origin,
		CRxGeVector2d& e0,
		CRxGeVector2d& e1) const;

	// Set the matrix to be a specified transformation
	//
	CRxGeMatrix2d& setToTranslation(const CRxGeVector2d& vec);
	CRxGeMatrix2d& setToRotation (double angle,
		const CRxGePoint2d& center
		= CRxGePoint2d::kOrigin);
	CRxGeMatrix2d& setToScaling  (double scaleAll,
		const CRxGePoint2d& center
		= CRxGePoint2d::kOrigin);
	CRxGeMatrix2d& setToMirroring(const CRxGePoint2d& pnt);
	CRxGeMatrix2d& setToMirroring(const CRxGeLine2d& line);
	CRxGeMatrix2d& setToAlignCoordSys(const CRxGePoint2d&  fromOrigin,
		const CRxGeVector2d& fromE0,
		const CRxGeVector2d& fromE1,
		const CRxGePoint2d&  toOrigin,
		const CRxGeVector2d& toE0,
		const CRxGeVector2d& toE1);

	// Functions that make a 2d transformation matrix using various approaches
	//
	static
		CRxGeMatrix2d translation    (const CRxGeVector2d& vec);
	static
		CRxGeMatrix2d rotation       (double angle, const CRxGePoint2d& center
		= CRxGePoint2d::kOrigin);
	static
		CRxGeMatrix2d scaling        (double scaleAll, const CRxGePoint2d& center
		= CRxGePoint2d::kOrigin);
	static
		CRxGeMatrix2d mirroring      (const CRxGePoint2d& pnt);
	static
		CRxGeMatrix2d mirroring      (const CRxGeLine2d& line);
	static
		CRxGeMatrix2d alignCoordSys  (const CRxGePoint2d& fromOrigin,
		const CRxGeVector2d& fromE0,
		const CRxGeVector2d& fromE1,
		const CRxGePoint2d&  toOrigin,
		const CRxGeVector2d& toE0,
		const CRxGeVector2d& toE1);

	// For convenient access to the data.
	//
	double         operator ()  (unsigned int, unsigned int) const;
	double&        operator ()  (unsigned int, unsigned int);

	// The components of the matrix.
	//
	double         entry[3][3]; // [row][column]

/*protected:

	void getCxMat(CMatrix& mat)const;
	void getAcMat2d(const CMatrix& i_cxmat,CRxGeMatrix2d& acmat)const;*/
public:

	void set(const CRxGeMatrix2d& src);
	void set(const double a[3][3] );

	
	
};

__forceinline bool
CRxGeMatrix2d::operator == (const CRxGeMatrix2d& otherMatrix) const
{
	return this->isEqualTo(otherMatrix);
}

// This operator is the logical negation of the `==' operator.
//
__forceinline bool
CRxGeMatrix2d::operator != (const CRxGeMatrix2d& otherMatrix) const
{
	return !this->isEqualTo(otherMatrix);
}

// Return a reference to the element in position [row][column]
// of the `entry' array.
//
__forceinline double
CRxGeMatrix2d::operator () (
						   unsigned int row,
						   unsigned int column) const
{
	return entry[row][column];
}

__forceinline double&
CRxGeMatrix2d::operator () (
						   unsigned int row,
						   unsigned int column)
{
	return entry[row][column];
}





#pragma pack (pop)
#endif

