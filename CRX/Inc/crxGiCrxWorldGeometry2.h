//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
#ifndef	__CRxGiCrxWorldGeometry2_H_
#define	__CRxGiCrxWorldGeometry2_H_

#include "crxgi.h"

CRX_DEFINE_NULL_CLSID(CRxGiCrxWorldGeometry2)
class CRXGI_CLASS CRxGiCrxWorldGeometry2: public CRxGiWorldGeometry2
{
public:
	CRX_DECLARE_DYNAMIC(CRxGiCrxWorldGeometry2);

public:
	CRxGiCrxWorldGeometry2();
	~CRxGiCrxWorldGeometry2();

public:
	// Coordinate transformations.
	virtual void getModelToWorldTransform(CRxGeMatrix3d&) const;
	virtual void getWorldToModelTransform(CRxGeMatrix3d&) const;

	virtual CAXA::Boolean pushModelTransform(const CRxGeVector3d & vNormal);// Uses arbitrary Axis algorythm
	virtual CAXA::Boolean pushModelTransform(const CRxGeMatrix3d & xMat);
	virtual CAXA::Boolean popModelTransform();

	// For drawing various primitives.
	virtual CAXA::Boolean  circle(const CRxGePoint3d& center,
		const double radius,
		const CRxGeVector3d& normal) const;

	virtual CAXA::Boolean  circle(const CRxGePoint3d&, const CRxGePoint3d&,
		const CRxGePoint3d&) const;

	virtual CAXA::Boolean  circularArc(const CRxGePoint3d& center,
		const double radius,
		const CRxGeVector3d& normal,
		const CRxGeVector3d& startVector,
		const double sweepAngle,
		const CRxGiArcType arcType = kAcGiArcSimple) const;

	virtual CAXA::Boolean  circularArc(const CRxGePoint3d& start,
		const CRxGePoint3d& point,
		const CRxGePoint3d& end,
		const CRxGiArcType arcType = kAcGiArcSimple) const;

	virtual CAXA::Boolean  polyline(const CAXA::UInt32 nbPoints,
		const CRxGePoint3d* pVertexList,
		const CRxGeVector3d* pNormal = NULL,
		CAXA::LongPtr lBaseSubEntMarker = -1) const;

	virtual CAXA::Boolean  polygon(const CAXA::UInt32 nbPoints,
		const CRxGePoint3d* pVertexList) const;

	virtual CAXA::Boolean  mesh(const CAXA::UInt32 rows,
		const CAXA::UInt32 columns,
		const CRxGePoint3d* pVertexList,
		const CRxGiEdgeData* pEdgeData = NULL,
		const CRxGiFaceData* pFaceData = NULL,
		const CRxGiVertexData* pVertexData = NULL,
		const bool bAutoGenerateNormals = true
		) const;

	virtual CAXA::Boolean  shell(const CAXA::UInt32 nbVertex,
		const CRxGePoint3d* pVertexList,
		const CAXA::UInt32 faceListSize,
		const CAXA::Int32* pFaceList,
		const CRxGiEdgeData* pEdgeData = NULL,
		const CRxGiFaceData* pFaceData = NULL,
		const CRxGiVertexData* pVertexData = NULL,
		const struct resbuf* pResBuf = NULL,
		const bool bAutoGenerateNormals = true
		) const;

	virtual CAXA::Boolean  text(const CRxGePoint3d& position,
		const CRxGeVector3d& normal,
		const CRxGeVector3d& direction,
		const double height,
		const double width,
		const double oblique,
		const CxCHAR* pMsg) const;

	virtual CAXA::Boolean  text(const CRxGePoint3d& position,
		const CRxGeVector3d& normal,
		const CRxGeVector3d& direction,
		const CxCHAR* pMsg,
		const CAXA::Int32 length,
		const CAXA::Boolean raw,
		const CRxGiTextStyle &pTextStyle
		) const;

	virtual CAXA::Boolean  xline(const CRxGePoint3d&,
		const CRxGePoint3d&) const;

	virtual CAXA::Boolean  ray(const CRxGePoint3d&,
		const CRxGePoint3d&) const;

	virtual CAXA::Boolean  pline(const CRxDbPolyline& lwBuf,
		CAXA::UInt32 fromIndex,
		CAXA::UInt32 numSegs
		) const;

	virtual CAXA::Boolean  draw(CRxGiDrawable*) const;

	// If you push a clip boundary onto the stack you must pop it;
	//
	virtual CAXA::Boolean          pushClipBoundary(CRxGiClipBoundary * pBoundary);
	virtual void                    popClipBoundary();


	virtual void setExtents(CRxGePoint3d *pNewExtents) const;

	// If this drawable is a block and has AcDbAttributes it must call
	// this method exactly once before sending the attributes to 
	// draw(). Once this is called the object may draw only attributes
	// and no more primitives
	// The attributes must be the last objects rendered
	//
	virtual void startAttributesSegment();

	virtual void pushPositionTransform (CrxGiPositionTransformBehavior behavior, const CRxGePoint2d& offset); 

	virtual void pushScaleTransform(CRxGiScaleTransformBehavior behavior, const CRxGePoint2d& extents); 

	virtual void pushOrientationTransform(CRxGiOrientationTransformBehavior behavior);

	virtual CAXA::Boolean image   (
		const CRxGiImageBGRA32& imageSource,
		const CRxGePoint3d& position,
		const CRxGeVector3d& u, //orientation and magnitude of width
		const CRxGeVector3d& v, //orientation and magnitude of height
		TransparencyMode transparencyMode = kTransparency8Bit
		) const;

	virtual CAXA::Boolean rowOfDots   (
		int count,
		const CRxGePoint3d&     start,
		const CRxGeVector3d&     step
		) const;

	virtual CAXA::Boolean ellipticalArc  (
		const CRxGePoint3d&         center,
		const CRxGeVector3d&        normal,
		double                     majorAxisLength,
		double                     minorAxisLength,
		double                     startDegreeInRads,
		double                     endDegreeInRads,
		double                     tiltDegreeInRads,
		bool                       isPie 
		) const ;

	virtual CAXA::Boolean symbol  (
		CRxGiSymbolType type,
		const CAXA::UInt32 nbPoints,
		const CRxGePoint3d* pPoints,
		const CRxCmEntityColor& outlineColor,
		const CRxCmEntityColor& fillColor
		) const;

public:
	void					SetImp(ULONG_PTR i_pImp);
	void					GetImp(ULONG_PTR *o_ppImp);

	ULONG_PTR				m_pImp;
};

#endif