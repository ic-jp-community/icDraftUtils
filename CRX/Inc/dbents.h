//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//
//  DESCRIPTION: Exported pre-R13 Entity classes
//
//  CrxRxObject
//    CrxDbObject
//      *CrxDbEntity
//        CrxDbText
//          CRxDbAttribute
//          CRxDbAttributeDefinition
//        CRxDbBlockBegin
//        CRxDbBlockEnd
//        CRxDbSequenceEnd
//        CrxDbBlockReference
//          CRxDbMInsertBlock
//        CRxDbVertex
//          CRxDb2dVertex
//          CRxDb3dPolylineVertex
//          CRxDbPolygonMeshVertex
//          CRxDbPolyFaceMeshVertex
//          CRxDbFaceRecord
//        CrxDbCurve
//          CRxDb2dPolyline
//          CRxDb3dPolyline
//          CrxDbArc
//          CrxDbCircle
//          CrxDbLine
//        CrxDbPoint
//        CRxDbFace
//        CRxDbPolyFaceMesh
//        CRxDbPolygonMesh
//        CRxDbTrace
//        CRxDbSolid
//        CRxDbShape
//        CRxDbViewport
//

#ifndef __CRXDBENTS_H_
#define __CRXDBENTS_H_



#include "dbmain.h"
#include "dbcurve.h"
#include "gescl3d.h"
#include "gepnt2d.h"
//#include "dbmtext.h"
//#include "dbbackground.h"
//#include "dbdim.h"
//#include "gept2dar.h"
//#include "gedblar.h"
#include "dbsymtb.h"
//#include "gemat3d.h"
//#include "crxdbxref.h"
//#include "crxgi.h"
//#include "crxgiviewport.h"
//#include "crxgivisualstyle.h"
#include "dbImageRef.h"



#pragma pack(push, 8)

class CRxDbAttribute;
//class CRxDbSequenceEnd;
//class CRxDb3dPolylineVertex;
//class CRxDb2dVertex;
//class CRxDbMText;
//class CRxDbAnnotationScale;


/*------------------------------------------------------------------------------
// CrxDbLine : 直线
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(17ECF72D-C046-4E9A-8416-FD8220FD33B5,CRxDbLine)
class CRXDB_API CRxDbLine: public CRxDbCurve
{
public:
	CRxDbLine(ICxCrxObject *i_pCrxObject = NULL);
	CRxDbLine(const CRxGePoint3d& start, const CRxGePoint3d& end);
	//~CrxDbLine();
	CRX_DECLARE_DYNCREATE(CRxDbLine)

	DBCURVE_METHODS

	//	CDraft::ErrorStatus getTransformedCopy(
	//	const CRxGeMatrix3d& xform, 
	//	CrxDbEntity*& ent) const;

	//CDraft::ErrorStatus getOffsetCurvesGivenPlaneNormal(
	//	const CRxGeVector3d& normal, double offsetDist,
		//CRxDbVoidPtrArray& offsetCurves) const;

	CRxGePoint3d         startPoint() const;
	CDraft::ErrorStatus   setStartPoint(const CRxGePoint3d&); 

	CRxGePoint3d         endPoint() const;
	CDraft::ErrorStatus   setEndPoint(const CRxGePoint3d&); 

	CDraft::ErrorStatus getOffsetCurves(double offsetDist,
		                                         CRxDbVoidPtrArray& offsetCurves) const;

	virtual CDraft::ErrorStatus   extend(CAXA::Boolean extendStart,const CRxGePoint3d& toPoint); 

	//double              thickness() const;
	//CDraft::ErrorStatus   setThickness(double);

//	CRxGeVector3d        normal() const;
	//CDraft::ErrorStatus   setNormal(const CRxGeVector3d&);

	//virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;
	//virtual void gripStatus(const CRxDb::GripStat status);
	//virtual CDraft::ErrorStatus   getGripPoints(
	//	CrxGePoint3dArray&  gripPoints,
	//	CRxDbIntArray&  osnapModes,
	//	CRxDbIntArray &  geomIds) const;
	//virtual CDraft::ErrorStatus   getGripPoints(CRxDbGripDataPtrArray& grips,
	//	const double curViewUnitSize, const int gripSize, 
	//	const CRxGeVector3d& curViewDir, const int bitflags) const;

	//virtual bool castShadows() const;
	//virtual bool receiveShadows() const;
};

inline CAXA::Boolean CRxDbLine::isClosed() const
{
	return CAXA::kFalse;
}

inline CAXA::Boolean CRxDbLine::isPeriodic() const
{
	return CAXA::kFalse;
}

inline CAXA::Boolean CRxDbLine::isPlanar() const
{
	return CAXA::kTrue;
}

inline CDraft::ErrorStatus CRxDbLine::getStartParam(double& v1) const
{
	v1 = 0.0;
	return CDraft::eOk;
}

//inline CDraft::ErrorStatus CrxDbLine::getSpline(CrxDbSpline*&) const 
//{
//	return CDraft::eNotApplicable;
//}


/*------------------------------------------------------------------------------
// CrxDbArc : 圆弧
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(91D6556B-0FB8-4E13-998F-BDACBFD31025,CRxDbArc)
class CRXDB_API CRxDbArc: public CRxDbCurve
{
public:
	CRxDbArc(ICxCrxObject *i_pCrxObject = NULL);
	CRxDbArc(const CRxGePoint3d& center, double radius,
		     double startAngle, double endAngle);
	CRxDbArc( const CRxGePoint3d& center, const CRxGeVector3d& normal,double radius,
		      double startAngle, double endAngle);
	
		
	//~CrxDbArc();
	CRX_DECLARE_DYNCREATE(CRxDbArc)

	DBCURVE_METHODS

		//CDraft::ErrorStatus getTransformedCopy(
	//	const CRxGeMatrix3d& xform, 
	//	CrxDbEntity*& ent) const;

	CRxGePoint3d         center() const;
	CDraft::ErrorStatus   setCenter(const CRxGePoint3d&); 

	double              radius() const;
	CDraft::ErrorStatus   setRadius(double);

	double              startAngle() const;
	CDraft::ErrorStatus   setStartAngle(double dAng);

	double              endAngle() const;
	CDraft::ErrorStatus   setEndAngle(double dAng);

//	double              thickness() const;
	//CDraft::ErrorStatus   setThickness(double);

	CRxGeVector3d        normal() const;
//	CDraft::ErrorStatus   setNormal(const CRxGeVector3d&);

//	virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;
	//virtual void gripStatus(const CRxDb::GripStat status);
	//virtual CDraft::ErrorStatus   getGripPoints(
	//	CrxGePoint3dArray&  gripPoints,
//		CRxDbIntArray&  osnapModes,
	//	CRxDbIntArray &  geomIds) const;
	//virtual CDraft::ErrorStatus   getGripPoints(CRxDbGripDataPtrArray& grips,
//		const double curViewUnitSize, const int gripSize, 
	//	const CRxGeVector3d& curViewDir, const int bitflags) const;

//	virtual bool        castShadows() const;
//	virtual bool        receiveShadows() const;

	virtual CDraft::ErrorStatus   extend(CAXA::Boolean extendStart,const CRxGePoint3d& toPoint); 
};

inline CAXA::Boolean CRxDbArc::isClosed() const
{
	return CAXA::kFalse;
}
inline CAXA::Boolean CRxDbArc::isPeriodic() const
{
	return CAXA::kFalse;
}
inline CAXA::Boolean CRxDbArc::isPlanar() const
{
	return CAXA::kTrue;
}

CRX_DEFINE_CLSID(76D76221-4358-465D-BC53-4449B3004657,CRxDbText)
class CRXDB_API CRxDbText: public CRxDbEntity
{
public:
	CRxDbText(ICxCrxObject *i_pCrxObject = NULL);
	CRxDbText(
		const CRxGePoint3d&  position,
		const CxCHAR*        text,
		CRxDbObjectId        style = CRxDbObjectId::kNull,
		double              height = 0,
		double              rotation = 0);
//	~CrxDbText();
	CRX_DECLARE_DYNCREATE(CRxDbText);
//
	CRxGePoint3d         position() const;
	CDraft::ErrorStatus   setPosition(const CRxGePoint3d&);
//
	CRxGePoint3d         alignmentPoint() const;
	CDraft::ErrorStatus   setAlignmentPoint(const CRxGePoint3d&);
//	CAXA::Boolean      isDefaultAlignment() const;
//
//	CRxGeVector3d        normal() const;
//	CDraft::ErrorStatus   setNormal(const CRxGeVector3d&);
//
//	virtual CAXA::Boolean    isPlanar() const { return CAXA::kTrue; }
//	virtual CDraft::ErrorStatus getPlane(CRxGePlane&, CRxDb::Planarity&) const;
//
//	double              thickness() const;
//	CDraft::ErrorStatus   setThickness(double);
//
	double              oblique() const;
	CDraft::ErrorStatus   setOblique(double);

	double              rotation() const; 
	CDraft::ErrorStatus   setRotation(double);

	double              height() const; 
	CDraft::ErrorStatus   setHeight(double);

	double              widthFactor() const; 
	CDraft::ErrorStatus   setWidthFactor(double);

	CxCHAR*              textString() const;
//	const CxCHAR*        textStringConst() const;
	CDraft::ErrorStatus   setTextString(const CxCHAR*);
//
	CRxDbObjectId        textStyle() const;
	CDraft::ErrorStatus   setTextStyle(CRxDbObjectId);
//
//	CAXA::Boolean      isMirroredInX() const;
//	CDraft::ErrorStatus   mirrorInX(CAXA::Boolean);
//
//	CAXA::Boolean      isMirroredInY() const;
//	CDraft::ErrorStatus   mirrorInY(CAXA::Boolean);
//
	CRxDb::TextHorzMode  horizontalMode() const;
	CDraft::ErrorStatus   setHorizontalMode(CRxDb::TextHorzMode);

	CRxDb::TextVertMode  verticalMode() const;
	CDraft::ErrorStatus   setVerticalMode(CRxDb::TextVertMode);

//	int                 correctSpelling();
//	virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;
//	virtual CAXA::UInt32       setAttributes(CRxGiDrawableTraits* pTraits);
//
//	virtual CDraft::ErrorStatus   adjustAlignment(
//		const CrxDbDatabase* pDb = NULL);
//
//	CDraft::ErrorStatus   setField(const CxCHAR* pszPropName, CRxDbField* pField,
//		CrxDbObjectId& fieldId);
//
//	CDraft::ErrorStatus   removeField(CrxDbObjectId fieldId);
//	CDraft::ErrorStatus   removeField(const CxCHAR* pszPropName, CrxDbObjectId& returnId);
//	CDraft::ErrorStatus   removeField(const CxCHAR* pszPropName);
//
//	CDraft::ErrorStatus   convertFieldToText();
//
//	virtual bool        castShadows() const;
//	virtual bool        receiveShadows() const;

	CDraft::ErrorStatus   setTxtMode(CRxDb::TextHorzMode mHor,CRxDb::TextVertMode mVer);
};
CRX_DEFINE_CLSID(49C3031E-DECE-4313-85F3-496BC8C488AD,CRxDbCurveText)
class CRXDB_API CRxDbCurveText: public CRxDbEntity
{
public:
	CRxDbCurveText(ICxCrxObject *i_pCrxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbCurveText);

    //  Text Style (sets initial font)
    //
	CRxDbObjectId        textStyle() const;
	CDraft::ErrorStatus   setTextStyle(CRxDbObjectId);

	// Referenced Curve
	//
	CRxDbObjectId        referencedCurve() const;
	CDraft::ErrorStatus   setReferencedCurve(CRxDbObjectId);

	// Referenced Point
	//
	CRxDbObjectId        referencedPoint() const;
	CDraft::ErrorStatus   setReferencedPoint(CRxDbObjectId);

	//  Initial text height (caps height)
	//
	double      textHeight() const;
	CDraft::ErrorStatus   setTextHeight(double);
	// 

	//  Text contents
	//
	CxCHAR        *contents() const;
	CDraft::ErrorStatus         setContents(const CxCHAR *);

	//  Start Para
	//
	double      startPara() const;
	CDraft::ErrorStatus   setStartPara(double);
	// 

	//  Middle Para
	//
	double      middlePara() const;
	CDraft::ErrorStatus   setMiddlePara(double);
	// 

	//  End Para
	//
	double      endPara() const;
	CDraft::ErrorStatus   setEndPara(double);
	// 

	// Align Mode 
	SHORT   alignMode() const;
	CDraft::ErrorStatus   setAlignMode(SHORT);

	//  Offset Dist
	//
	double      offsetDist() const;
	CDraft::ErrorStatus   setOffsetDist(double);
	// 

	//  Space Factor
	//
	double      spaceFactor() const;
	CDraft::ErrorStatus   setSpaceFactor(double);
	// 

	// Reverse Char
	bool	reverseChar() const;
	CDraft::ErrorStatus setReverseChar(bool);

	// Convex Dir
	SHORT convexDir() const;
	CDraft::ErrorStatus setConvexDir(SHORT);

	// Text Dir
	SHORT textDir() const;
	CDraft::ErrorStatus setTextDir(SHORT);

};
//
CRX_DEFINE_CLSID(E218226D-DD73-4A9D-AA95-764B4D3BC072,CRxDbAttributeDefinition)
class CRXDB_API CRxDbAttributeDefinition: public CRxDbText
{
public:
	CRxDbAttributeDefinition(ICxCrxObject *i_pCrxObject = NULL);
	CRxDbAttributeDefinition(
		const CRxGePoint3d& position,
		const CxCHAR*       text,
		const CxCHAR*       tag,
		const CxCHAR*       prompt,
		CRxDbObjectId       style = CRxDbObjectId::kNull);
//	~CrxDbAttributeDefinition();
	CRX_DECLARE_DYNCREATE(CRxDbAttributeDefinition);
//
	CxCHAR*              prompt() const;
//	const CxCHAR*        promptConst() const;
	CDraft::ErrorStatus   setPrompt(const CxCHAR*);
//
	CxCHAR*              tag() const;
//	const CxCHAR*        tagConst() const;
	CDraft::ErrorStatus   setTag(const CxCHAR*);
//
	CAXA::Boolean      isInvisible() const;
	CDraft::ErrorStatus   setInvisible(CAXA::Boolean);

	CAXA::Boolean      isConstant() const;
//	CDraft::ErrorStatus   setConstant(CAXA::Boolean);
//
//	CAXA::Boolean      isVerifiable() const;
//	CDraft::ErrorStatus   setVerifiable(CAXA::Boolean);
//
//	CAXA::Boolean      isPreset() const;
//	CDraft::ErrorStatus   setPreset(CAXA::Boolean);
//
//	CAXA::UInt16       fieldLength() const;
//	CDraft::ErrorStatus   setFieldLength(CAXA::UInt16);
//
//	virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;
//
//	virtual CDraft::ErrorStatus   adjustAlignment(
//		const CrxDbDatabase* pDb = NULL);

	bool lockPositionInBlock() const;
	CDraft::ErrorStatus setLockPositionInBlock(bool bValue);

//	// multiline attribute definition support
//	bool              isMTextAttributeDefinition          () const;
//	CRxDbMText *       getMTextAttributeDefinition         () const;
//	const CRxDbMText * getMTextAttributeDefinitionConst    () const;
//	CDraft::ErrorStatus setMTextAttributeDefinition         (CRxDbMText*);
//	CDraft::ErrorStatus convertIntoMTextAttributeDefinition (CAXA::Boolean val = CAXA::kTrue);
//	CDraft::ErrorStatus updateMTextAttributeDefinition      ();
};
//
CRX_DEFINE_CLSID(60D85BAF-4D2E-4000-84F0-E77D42FB999C,CRxDbAttribute)
class CRXDB_API CRxDbAttribute: public CRxDbText
{
public:
	CRxDbAttribute(ICxCrxObject *i_pCrxObject = NULL);
	CRxDbAttribute(
		const CRxGePoint3d& position,
		const CxCHAR*       text,
		const CxCHAR*       tag,
		CRxDbObjectId       style = CRxDbObjectId::kNull);
//	~CRxDbAttribute();
	CRX_DECLARE_DYNCREATE(CRxDbAttribute);
//
	CxCHAR*              tag() const;
//	const CxCHAR*        tagConst() const;
	CDraft::ErrorStatus   setTag(const CxCHAR* newTag);
	CDraft::ErrorStatus   setTextString(const CxCHAR*);

	CAXA::Boolean      isInvisible() const;
	CDraft::ErrorStatus   setInvisible(CAXA::Boolean);

//	CAXA::Boolean      isConstant() const;
//	CAXA::Boolean      isVerifiable() const;
//	CAXA::Boolean      isPreset() const;
//
//	CAXA::UInt16       fieldLength() const;
//	CDraft::ErrorStatus   setFieldLength(CAXA::UInt16);
//
//	CDraft::ErrorStatus setAttributeFromBlock(const CRxGeMatrix3d& blkXform);
//	CDraft::ErrorStatus setAttributeFromBlock(
//		const CRxDbAttributeDefinition *pAttdef,
//		const CRxGeMatrix3d& blkXform);
//
//	virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;
	bool lockPositionInBlock() const;
	CDraft::ErrorStatus setLockPositionInBlock(bool bValue);
//
//	// multiline attribute support
//	bool              isMTextAttribute          ()                        const;
//	CRxDbMText *       getMTextAttribute         ()                        const;
//	const CRxDbMText * getMTextAttributeConst    ()                        const;
//	CDraft::ErrorStatus setMTextAttribute         (CRxDbMText *);
//	CDraft::ErrorStatus convertIntoMTextAttribute (CAXA::Boolean val = CAXA::kTrue);
//	CDraft::ErrorStatus updateMTextAttribute      ();
//	bool              isReallyLocked            ()                        const;
	CDraft::ErrorStatus   setTextString_RealTime(const CxCHAR*);
};
//
CRX_DEFINE_CLSID(D38B4EBA-A81F-4B28-AA19-71A60D884004,CRxDbBlockReference)
class CRXDB_API CRxDbBlockReference: public CRxDbEntity
{
public:
	CRxDbBlockReference(ICxCrxObject *i_pCrxObject = NULL);
//	CrxDbBlockReference(const CRxGePoint3d&  position,
//		CrxDbObjectId  blockTableRec);
//	~CrxDbBlockReference();
	CRX_DECLARE_DYNCREATE(CRxDbBlockReference)
//
	CRxDbObjectId      blockTableRecord() const;
	virtual CDraft::ErrorStatus setBlockTableRecord(CRxDbObjectId);
//
	CRxGePoint3d       position() const;
	virtual CDraft::ErrorStatus setPosition(const CRxGePoint3d&);
//
	CRxGeScale3d       scaleFactors() const;
//	CRxGeScale3d       nonAnnotationScaleFactors() const;
	virtual CDraft::ErrorStatus setScaleFactors(const CRxGeScale3d& scale);
//
	double            rotation() const;
	virtual CDraft::ErrorStatus setRotation(double newVal);
//
	CRxGeVector3d      normal() const;
//	virtual CDraft::ErrorStatus setNormal(const CRxGeVector3d& newVal);
//
	virtual CAXA::Boolean    isPlanar() const { return CAXA::kTrue; }
//	virtual CDraft::ErrorStatus getPlane(CRxGePlane&, CRxDb::Planarity&) const;
//
	//CRxGeMatrix3d      blockTransform() const;
//	CRxGeMatrix3d      nonAnnotationBlockTransform() const;
//	virtual CDraft::ErrorStatus setBlockTransform(const CRxGeMatrix3d&);
//
	CDraft::ErrorStatus appendAttribute(CRxDbAttribute*);
	CDraft::ErrorStatus appendAttribute(CRxDbObjectId&, CRxDbAttribute*);
//
//	CDraft::ErrorStatus openAttribute(CRxDbAttribute*&, CrxDbObjectId,
//		CRxDb::OpenMode,
//		bool openErasedOne = false);
//
//	CDraft::ErrorStatus openSequenceEnd(CRxDbSequenceEnd*&, CRxDb::OpenMode);
//
	CRxDbObjectIterator*  attributeIterator();
//
//	virtual CAXA::Boolean    treatAsCRxDbBlockRefForExplode() const;
//
//	// Subentity acquisition.
//	//
//	virtual  CDraft::ErrorStatus getSubentPathsAtGsMarker(
//		CRxDb::SubentType,
//		CAXA::GsMarker       gsMark,
//		const CRxGePoint3d&    pickPoint,
//		const CRxGeMatrix3d&   viewXform,
//		int&                  numPaths,
//		CrxDbFullSubentPath*&  subentPaths,
//		int                   numInserts = 0,
//		CrxDbObjectId*         entAndInsertStack = NULL) const;
//
//	virtual  CDraft::ErrorStatus getGsMarkersAtSubentPath(
//		const CrxDbFullSubentPath& subPath,
//		CRxArray<CAXA::GsMarker>& gsMarkers) const;
//
//	virtual CDraft::ErrorStatus highlight  (const CrxDbFullSubentPath&
//		= kNullSubent, const CAXA::Boolean highlightAll = CAXA::kFalse) const;
//
//	virtual CDraft::ErrorStatus unhighlight(const CrxDbFullSubentPath&
//		= kNullSubent, const CAXA::Boolean highlightAll = CAXA::kFalse) const;
//
//	virtual CrxDbEntity*       subentPtr  (const CrxDbFullSubentPath&) const;
//
//	virtual CAXA::Boolean    worldDraw(CRxGiWorldDraw* mode);
//	virtual void              viewportDraw(CRxGiViewportDraw* mode);
//
//	CDraft::ErrorStatus geomExtentsBestFit( 
//		CRxDbExtents& extents, 
//		const CRxGeMatrix3d& parentXform = 
//		CRxGeMatrix3d::kIdentity) const;
//
	virtual CDraft::ErrorStatus explodeToOwnerSpace();
//
//	virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;
//	virtual void gripStatus(const CRxDb::GripStat status);

	//立即修改当前对象
	CRxDbObjectIterator*  attributeIterator_RealTime();

};
//
//class CRxDbMInsertBlock: public CrxDbBlockReference
//{
//public:
//	CRxDbMInsertBlock();
//	CRxDbMInsertBlock(
//		const CRxGePoint3d&  position,
//		CrxDbObjectId        blockTableRec,
//		CAXA::UInt16       columns,
//		CAXA::UInt16       rows,
//		double              colSpacing,
//		double              rowSpacing);
//	~CRxDbMInsertBlock();
//	CRXDB_DECLARE_MEMBERS(CRxDbMInsertBlock);
//
//	CAXA::UInt16      columns() const;
//	CDraft::ErrorStatus  setColumns(CAXA::UInt16);
//
//	CAXA::UInt16      rows() const;
//	CDraft::ErrorStatus  setRows(CAXA::UInt16);
//
//	double             columnSpacing() const;
//	CDraft::ErrorStatus  setColumnSpacing(double);
//
//	double             rowSpacing() const;
//	CDraft::ErrorStatus  setRowSpacing(double);
//
//	virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;
//};
//
//class CRxDbBlockBegin: public CrxDbEntity
//{
//public:
//	CRxDbBlockBegin();
//	~CRxDbBlockBegin();
//	CRXDB_DECLARE_MEMBERS(CRxDbBlockBegin);
//
//	virtual bool castShadows() const;
//	virtual void setCastShadows(bool newVal);
//	virtual bool receiveShadows() const;
//	virtual void setReceiveShadows(bool newVal);
//};
//
//class CRxDbBlockEnd: public CrxDbEntity
//{
//public:
//	CRxDbBlockEnd();
//	~CRxDbBlockEnd();
//	CRXDB_DECLARE_MEMBERS(CRxDbBlockEnd);
//
//	virtual bool castShadows() const;
//	virtual void setCastShadows(bool newVal);
//	virtual bool receiveShadows() const;
//	virtual void setReceiveShadows(bool newVal);
//};
//
//class CRxDbSequenceEnd: public CrxDbEntity
//{
//public:
//	CRxDbSequenceEnd();
//	~CRxDbSequenceEnd();
//	CRXDB_DECLARE_MEMBERS(CRxDbSequenceEnd);
//
//	virtual bool castShadows() const;
//	virtual void setCastShadows(bool newVal);
//	virtual bool receiveShadows() const;
//	virtual void setReceiveShadows(bool newVal);
//};
//
//class CRxDbVertex: public CrxDbEntity
//{
//public:
//	CRxDbVertex();
//	~CRxDbVertex();
//	CRXDB_DECLARE_MEMBERS(CRxDbVertex);
//};
//
//// Inline for performance, because derived classes' dtors
//// call this explicitly.
////
//inline CRxDbVertex::~CRxDbVertex()
//{
//}

//class CRxDb2dVertex: public CRxDbVertex
//{
//public:
//	CRxDb2dVertex();
//	~CRxDb2dVertex();
//	CRXDB_DECLARE_MEMBERS(CRxDb2dVertex);
//	CRxDb2dVertex(
//		const CRxGePoint3d&  position,
//		double   bulge      = 0,
//		double   startWidth = 0,
//		double   endWidth   = 0,
//		double   tangent    = 0);

//	CRxDb::Vertex2dType vertexType() const;
//
//
//	// This method accesses the position in ECS.  See CRxDb2dPolyline for WCS.
//	//
	//CRxGePoint3d         position() const;
	//CDraft::ErrorStatus   setPosition(const CRxGePoint3d&); 

	//double              startWidth() const; 
	//CDraft::ErrorStatus   setStartWidth(double newVal);

	//double              endWidth() const; 
	//CDraft::ErrorStatus   setEndWidth(double newVal);

	//double              bulge() const; 
	//CDraft::ErrorStatus   setBulge(double newVal);
//
//	CAXA::Boolean      isTangentUsed() const;
//	CDraft::ErrorStatus   useTangent();
//	CDraft::ErrorStatus   ignoreTangent();
//
//	double              tangent() const; 
//	CDraft::ErrorStatus   setTangent(double newVal);
//
//};
//
//class CRxDb3dPolylineVertex: public CRxDbVertex
//{
//public:
//	CRxDb3dPolylineVertex();
//	~CRxDb3dPolylineVertex();
//	CRXDB_DECLARE_MEMBERS(CRxDb3dPolylineVertex);
//	CRxDb3dPolylineVertex(const CRxGePoint3d&);
//
//	CRxDb::Vertex3dType vertexType() const;
//
//
//	CRxGePoint3d         position() const;
//	CDraft::ErrorStatus   setPosition(const CRxGePoint3d&); 
//
//};
//
//class CRxDbPolygonMeshVertex: public CRxDbVertex
//{
//public:
//	CRxDbPolygonMeshVertex();
//	CRxDbPolygonMeshVertex(const CRxGePoint3d&  position);
//	~CRxDbPolygonMeshVertex();
//	CRXDB_DECLARE_MEMBERS(CRxDbPolygonMeshVertex);
//
//	CRxDb::Vertex3dType vertexType() const;
//
//	CRxGePoint3d         position() const;
//	CDraft::ErrorStatus   setPosition(const CRxGePoint3d&); 
//
//};
//
//class CRxDbPolyFaceMeshVertex: public CRxDbVertex
//{
//public:
//	CRxDbPolyFaceMeshVertex();
//	CRxDbPolyFaceMeshVertex(const CRxGePoint3d&  position);
//	~CRxDbPolyFaceMeshVertex();
//	CRXDB_DECLARE_MEMBERS(CRxDbPolyFaceMeshVertex);
//
//	CRxGePoint3d         position() const;
//	CDraft::ErrorStatus   setPosition(const CRxGePoint3d&); 
//
//};
//
//class CRxDbFaceRecord: public CRxDbVertex
//{
//public:
//	CRxDbFaceRecord();
//	// Use negative values to indicate invisible faces
//	CRxDbFaceRecord(CAXA::Int16 vtx0, CAXA::Int16 vtx1,
//		CAXA::Int16 vtx2, CAXA::Int16 vtx3);
//	~CRxDbFaceRecord();
//	CRXDB_DECLARE_MEMBERS(CRxDbFaceRecord);
//
//	// Input index must be 0-3.
//	//
//	CDraft::ErrorStatus getVertexAt(CAXA::UInt16 faceIdx,
//		CAXA::Int16& vtxIdx) const;
//	CDraft::ErrorStatus setVertexAt(CAXA::UInt16 faceIdx,
//		CAXA::Int16  vtxIdx);
//
//	CDraft::ErrorStatus isEdgeVisibleAt(CAXA::UInt16 faceIndex,
//		CAXA::Boolean& visible) const;
//
//	CDraft::ErrorStatus makeEdgeVisibleAt(CAXA::UInt16 faceIndex);
//	CDraft::ErrorStatus makeEdgeInvisibleAt(CAXA::UInt16 faceIndex);
//};
//

//class  CRxDb2dPolyline: public CrxDbCurve
//{
//public:
//	CRxDb2dPolyline();
//	~CRxDb2dPolyline();
//	CRXDB_DECLARE_MEMBERS(CRxDb2dPolyline);
//	CRxDb2dPolyline (
//		CRxDb::Poly2dType  type,
//		CrxGePoint3dArray& vertices,
//		double            elevation     = 0,
//		CAXA::Boolean    closed        = CAXA::kFalse,
//		double            defStartWidth = 0,
//		double            defEndWidth   = 0,
//		CRxGeDoubleArray*  bulges        = NULL);
//
//	DBCURVE_METHODS

//
//		CRxDb::Poly2dType    polyType() const;
//	CDraft::ErrorStatus   setPolyType(CRxDb::Poly2dType);
//	CDraft::ErrorStatus   convertToPolyType(CRxDb::Poly2dType newVal);
//
//	CDraft::ErrorStatus   makeClosed();
//	CDraft::ErrorStatus   makeOpen();
//
//	double              defaultStartWidth() const;
//	CDraft::ErrorStatus   setDefaultStartWidth(double);
//
//	double              defaultEndWidth() const;
//	CDraft::ErrorStatus   setDefaultEndWidth(double);
//
	//double              thickness() const;
	//CDraft::ErrorStatus   setThickness(double);
//
//	CRxGeVector3d        normal() const;
//	CDraft::ErrorStatus   setNormal(const CRxGeVector3d&);
//
//	double              elevation() const;
//	CDraft::ErrorStatus   setElevation(double);
//
//	CAXA::Boolean      isLinetypeGenerationOn() const;
//	CDraft::ErrorStatus   setLinetypeGenerationOn();
//	CDraft::ErrorStatus   setLinetypeGenerationOff();
//
//	CDraft::ErrorStatus   straighten();
//	CDraft::ErrorStatus   splineFit();
//	CDraft::ErrorStatus   splineFit(CRxDb::Poly2dType splineType,
//		CAXA::Int16   splineSegs);
//	CDraft::ErrorStatus   curveFit();
//
//	// Vertex access
//	//
	//CDraft::ErrorStatus appendVertex(CRxDb2dVertex*);
//	CDraft::ErrorStatus appendVertex(CrxDbObjectId& objId, CRxDb2dVertex*);
//
//	CDraft::ErrorStatus insertVertexAt(const CRxDb2dVertex* pIndexVert,
//		CRxDb2dVertex* pNewVertex); 
//	CDraft::ErrorStatus insertVertexAt(CrxDbObjectId& newVertId,
//		const CrxDbObjectId& indexVertId, CRxDb2dVertex* pNewVertex);
//
//	CDraft::ErrorStatus openVertex(CRxDb2dVertex*&, CrxDbObjectId    vertId,
//		CRxDb::OpenMode,
//		bool openErasedOne = false) const;
//	CDraft::ErrorStatus openSequenceEnd(CRxDbSequenceEnd*&, CRxDb::OpenMode);
//
//	CrxDbObjectIterator*  vertexIterator() const;
//
//	// Vertex position in WCS
//	//
//	CRxGePoint3d       vertexPosition(const CRxDb2dVertex& vert) const;
//
//	// CrxDbEntity overrides
//	virtual CAXA::Boolean    worldDraw   (CRxGiWorldDraw* pWd);
//
//	virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;

	
//};
//
//inline CAXA::Boolean CRxDb2dPolyline::isPeriodic() const
//{
//	return CAXA::kFalse;
//}
//
//
//inline CAXA::Boolean CRxDb2dPolyline::isPlanar() const
//{
//	return CAXA::kTrue;
//}
//
//inline CDraft::ErrorStatus CRxDb2dPolyline::getStartParam(double& param) const
//{
//	param = 0.0;
//	return CDraft::eOk;
//}

//inline CDraft::ErrorStatus CRxDb2dPolyline::extend (double param)
//{
//	return CDraft::eNotApplicable;
//}
//
//
//class CRxDb3dPolyline: public CrxDbCurve
//{
//public:
//	CRxDb3dPolyline();
//	~CRxDb3dPolyline();
//	CRXDB_DECLARE_MEMBERS(CRxDb3dPolyline);
//	CRxDb3dPolyline(CRxDb::Poly3dType, CrxGePoint3dArray& vertices,
//		CAXA::Boolean closed = CAXA::kFalse);
//
//	DBCURVE_METHODS
//
//		CDraft::ErrorStatus   makeClosed();
//	CDraft::ErrorStatus   makeOpen();
//
//	CRxDb::Poly3dType    polyType() const;
//	CDraft::ErrorStatus   setPolyType(CRxDb::Poly3dType);
//	CDraft::ErrorStatus   convertToPolyType(CRxDb::Poly3dType newVal);
//
//	CDraft::ErrorStatus   straighten();
//	CDraft::ErrorStatus   splineFit();
//	CDraft::ErrorStatus   splineFit(CRxDb::Poly3dType splineType,
//		CAXA::Int16   splineSegs);
//
//	// Vertex access
//	//
//	CDraft::ErrorStatus appendVertex(CRxDb3dPolylineVertex*);
//	CDraft::ErrorStatus appendVertex(CrxDbObjectId& objId, CRxDb3dPolylineVertex*);
//
//	CDraft::ErrorStatus insertVertexAt(const CRxDb3dPolylineVertex* pIndexVert,
//		CRxDb3dPolylineVertex* pNewVertex); 
//	CDraft::ErrorStatus insertVertexAt(CrxDbObjectId& newVertId,
//		const CrxDbObjectId& indexVertId, CRxDb3dPolylineVertex* pNewVertex);
//
//	CDraft::ErrorStatus openVertex(CRxDb3dPolylineVertex*&, CrxDbObjectId vertId,
//		CRxDb::OpenMode,
//		bool openErasedOne = false);
//
//	CDraft::ErrorStatus openSequenceEnd(CRxDbSequenceEnd*&, CRxDb::OpenMode);
//
//	CrxDbObjectIterator* vertexIterator() const;
//
//	// CrxDbEntity overrides
//	virtual CAXA::Boolean    worldDraw   (CRxGiWorldDraw* pWd);
//
//	virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;
//};
//
//
//inline CAXA::Boolean    CRxDb3dPolyline::isPeriodic   () const
//{
//	return CAXA::kFalse;
//}
//
//inline CDraft::ErrorStatus CRxDb3dPolyline::getStartParam(double& param) const
//{
//	param = 0.0;
//	return CDraft::eOk;
//}
//
//inline CDraft::ErrorStatus CRxDb3dPolyline::extend(double newparam)
//{
//	// extending a pline based on a parameter is not supported.
//	return CDraft::eNotApplicable;
//}
//
//
//
CRX_DEFINE_CLSID(7587733C-3DF6-4C9D-8B08-20AEFFE18291,CRxDbCircle)
class CRXDB_API CRxDbCircle: public CRxDbCurve
{
public:
	CRxDbCircle(ICxCrxObject *i_pCrxObject = NULL);
	CRxDbCircle(const CRxGePoint3d& cntr, const CRxGeVector3d& nrm, double radius);
//	~CrxDbCircle();
	CRX_DECLARE_DYNCREATE(CRxDbCircle);
//
	DBCURVE_METHODS
//
//		CDraft::ErrorStatus getTransformedCopy(
//		const CRxGeMatrix3d& xform, 
//		CrxDbEntity*& ent) const;
//
	CRxGePoint3d         center() const;
	CDraft::ErrorStatus   setCenter(const CRxGePoint3d&); 
//
	double              radius() const;
	CDraft::ErrorStatus   setRadius(double);
//
//	double              thickness() const;
//	CDraft::ErrorStatus   setThickness(double);
//
//	CRxGeVector3d        normal() const;
//	CDraft::ErrorStatus   setNormal(const CRxGeVector3d&);
//
//	virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;
//	virtual void        gripStatus(const CRxDb::GripStat status);
//	virtual CDraft::ErrorStatus   getGripPoints(
//		CrxGePoint3dArray&  gripPoints,
//		CRxDbIntArray&  osnapModes,
//		CRxDbIntArray &  geomIds) const;
//	virtual CDraft::ErrorStatus   getGripPoints(CRxDbGripDataPtrArray& grips,
//		const double curViewUnitSize, const int gripSize, 
//		const CRxGeVector3d& curViewDir, const int bitflags) const;
//
//	virtual bool        castShadows() const;
//	virtual bool        receiveShadows() const;

	virtual CDraft::ErrorStatus   extend(CAXA::Boolean extendStart,const CRxGePoint3d& toPoint); 

	// CDraft::ErrorStatus getSplitCurves (const CRxGePoint3dArray& points,
		//CRxDbVoidPtrArray& curveSegments) const;
};

inline CAXA::Boolean CRxDbCircle::isClosed() const      
{
	return CAXA::kTrue;
}

inline CAXA::Boolean CRxDbCircle::isPeriodic() const      
{
	return CAXA::kTrue;
}

inline CAXA::Boolean CRxDbCircle::isPlanar () const
{
	return CAXA::kTrue;
}
//
inline CDraft::ErrorStatus CRxDbCircle::getStartParam(double& p) const
{
	p = 0.0;
	return CDraft::eOk;
}

//inline CDraft::ErrorStatus CrxDbCircle::extend(double)
//{
//	return CDraft::eNotApplicable;
//}
//
//inline CDraft::ErrorStatus CrxDbCircle::extend(CAXA::Boolean, const CRxGePoint3d&)
//{
//	return CDraft::eNotApplicable;
//}
//
//
//
//
//
//
CRX_DEFINE_CLSID(D6DA372E-0F4F-4BFB-9E92-3B3363AC6C22,CRxDbPoint)
class CRXDB_API CRxDbPoint: public CRxDbEntity
{
public:
	CRxDbPoint(ICxCrxObject *i_pCrxObject = NULL);
	CRxDbPoint(const CRxGePoint3d&   position);
//	~CrxDbPoint();
	CRX_DECLARE_DYNCREATE(CRxDbPoint);
//
	CRxGePoint3d         position() const;
	CDraft::ErrorStatus   setPosition(const CRxGePoint3d&);
//
//	double              thickness() const;
//	CDraft::ErrorStatus   setThickness(double);
//
//	CRxGeVector3d        normal() const;
//	CDraft::ErrorStatus   setNormal(const CRxGeVector3d&);
//
//	double              ecsRotation() const;
//	CDraft::ErrorStatus   setEcsRotation(double);
//
//	// CrxDbEntity overrides
	virtual CAXA::Boolean    isPlanar() const { return CAXA::kTrue; }
//	virtual CDraft::ErrorStatus getPlane(CRxGePlane&, CRxDb::Planarity&) const;
//
//	virtual CAXA::UInt32     setAttributes(CRxGiDrawableTraits* pTraits);
//	virtual CAXA::Boolean worldDraw(CRxGiWorldDraw* mode);
//	virtual void viewportDraw(CRxGiViewportDraw* pVpDraw);
//
//	virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;
//
//	virtual bool castShadows() const;
//	virtual bool receiveShadows() const;
};
//
//class CRxDbFace: public CrxDbEntity
//{
//public:                
//	CRxDbFace();
//	CRxDbFace(const CRxGePoint3d&   pt0,
//		const CRxGePoint3d&   pt1,
//		const CRxGePoint3d&   pt2,
//		const CRxGePoint3d&   pt3,
//		CAXA::Boolean e0vis = CAXA::kTrue,
//		CAXA::Boolean e1vis = CAXA::kTrue,
//		CAXA::Boolean e2vis = CAXA::kTrue,
//		CAXA::Boolean e3vis = CAXA::kTrue);
//	CRxDbFace(const CRxGePoint3d&   pt0,
//		const CRxGePoint3d&   pt1,
//		const CRxGePoint3d&   pt2,
//		CAXA::Boolean e0vis = CAXA::kTrue,
//		CAXA::Boolean e1vis = CAXA::kTrue,
//		CAXA::Boolean e2vis = CAXA::kTrue,
//		CAXA::Boolean e3vis = CAXA::kTrue);
//	~CRxDbFace();
//	CRXDB_DECLARE_MEMBERS(CRxDbFace);
//
//	CDraft::ErrorStatus getVertexAt(CAXA::UInt16, CRxGePoint3d&) const;
//	CDraft::ErrorStatus setVertexAt(CAXA::UInt16, const CRxGePoint3d&);
//
//	CDraft::ErrorStatus isEdgeVisibleAt(CAXA::UInt16, CAXA::Boolean&) const;
//	CDraft::ErrorStatus makeEdgeVisibleAt(CAXA::UInt16);
//	CDraft::ErrorStatus makeEdgeInvisibleAt(CAXA::UInt16);
//
//	virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;
//};
//
//class CRxDbPolyFaceMesh: public CrxDbEntity
//{
//public:
//	CRxDbPolyFaceMesh();
//	~CRxDbPolyFaceMesh();
//	CRXDB_DECLARE_MEMBERS(CRxDbPolyFaceMesh);
//
//	CAXA::Int16 numVertices() const;
//	CAXA::Int16 numFaces() const;
//
//	CDraft::ErrorStatus appendVertex(CRxDbPolyFaceMeshVertex*);
//	CDraft::ErrorStatus appendVertex(CrxDbObjectId& objId, CRxDbPolyFaceMeshVertex*);
//
//	CDraft::ErrorStatus appendFaceRecord(CRxDbFaceRecord*);
//	CDraft::ErrorStatus appendFaceRecord(CrxDbObjectId&, CRxDbFaceRecord*);
//
//	CDraft::ErrorStatus openVertex(CRxDbVertex*&, CrxDbObjectId subObjId,
//		CRxDb::OpenMode,
//		bool openErasedOne = false);
//
//	CDraft::ErrorStatus openSequenceEnd(CRxDbSequenceEnd*&, CRxDb::OpenMode);
//
//	CrxDbObjectIterator*  vertexIterator() const;
//
//	virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;
//};
//
//class CRxDbPolygonMesh: public CrxDbEntity
//{
//public:
//	CRxDbPolygonMesh();
//	CRxDbPolygonMesh(CRxDb::PolyMeshType pType,
//		CAXA::Int16       mSize,
//		CAXA::Int16       nSize,
//		const CrxGePoint3dArray& vertices,
//		CAXA::Boolean     mClosed = CAXA::kTrue,
//		CAXA::Boolean     nClosed = CAXA::kTrue);
//	~CRxDbPolygonMesh();
//	CRXDB_DECLARE_MEMBERS(CRxDbPolygonMesh);
//
//	CRxDb::PolyMeshType  polyMeshType() const;
//	CDraft::ErrorStatus   setPolyMeshType(CRxDb::PolyMeshType);
//	CDraft::ErrorStatus   convertToPolyMeshType(CRxDb::PolyMeshType newVal);
//
//	CAXA::Int16        mSize() const;
//	CDraft::ErrorStatus   setMSize(CAXA::Int16);
//
//	CAXA::Int16        nSize() const;
//	CDraft::ErrorStatus   setNSize(CAXA::Int16);
//
//	CAXA::Boolean      isMClosed() const;
//	CDraft::ErrorStatus   makeMClosed();
//	CDraft::ErrorStatus   makeMOpen();
//
//	CAXA::Boolean      isNClosed() const;
//	CDraft::ErrorStatus   makeNClosed();
//	CDraft::ErrorStatus   makeNOpen();
//
//	CAXA::Int16        mSurfaceDensity() const;
//	CDraft::ErrorStatus   setMSurfaceDensity(CAXA::Int16);
//
//	CAXA::Int16        nSurfaceDensity() const;
//	CDraft::ErrorStatus   setNSurfaceDensity(CAXA::Int16);
//
//	CDraft::ErrorStatus   straighten();
//	CDraft::ErrorStatus   surfaceFit();
//	CDraft::ErrorStatus   surfaceFit(CRxDb::PolyMeshType surfType,
//		CAXA::Int16 surfu, CAXA::Int16 surfv);
//
//	// Vertex access
//	//
//	CDraft::ErrorStatus appendVertex(CRxDbPolygonMeshVertex*);
//	CDraft::ErrorStatus appendVertex(CrxDbObjectId& objId, CRxDbPolygonMeshVertex*);
//
//	CDraft::ErrorStatus openVertex(CRxDbPolygonMeshVertex*&, CrxDbObjectId vertId,
//		CRxDb::OpenMode,
//		bool openErasedOne = false);
//
//	CDraft::ErrorStatus openSequenceEnd(CRxDbSequenceEnd*&, CRxDb::OpenMode);
//
//	CrxDbObjectIterator*  vertexIterator() const;
//
//	virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;
//};
//
//class CRxDbSolid: public CrxDbEntity
//{
//public:
//	CRxDbSolid();
//	CRxDbSolid(const CRxGePoint3d&    pt0,
//		const CRxGePoint3d&    pt1,
//		const CRxGePoint3d&    pt2,
//		const CRxGePoint3d&    pt3);
//	CRxDbSolid(const CRxGePoint3d&    pt0,
//		const CRxGePoint3d&    pt1,
//		const CRxGePoint3d&    pt2);
//	~CRxDbSolid();
//	CRXDB_DECLARE_MEMBERS(CRxDbSolid);
//
//	CDraft::ErrorStatus transformBy(const CRxGeMatrix3d& pXform);
//	CDraft::ErrorStatus getTransformedCopy(
//		const CRxGeMatrix3d& xform,
//		CrxDbEntity*&  pEnt) const;
//
//	CDraft::ErrorStatus getPointAt(CAXA::UInt16 idx, CRxGePoint3d& pntRes) const;
//	CDraft::ErrorStatus setPointAt(CAXA::UInt16 idx, const CRxGePoint3d&);
//
//	double              thickness() const;
//	CDraft::ErrorStatus   setThickness(double);
//
//	CRxGeVector3d        normal() const;
//	CDraft::ErrorStatus   setNormal(const CRxGeVector3d&);
//
//	virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;
//};
//
//class CRxDbTrace: public CrxDbEntity
//{
//public:
//	CRxDbTrace();
//	CRxDbTrace(const CRxGePoint3d&    pt0,
//		const CRxGePoint3d&    pt1,
//		const CRxGePoint3d&    pt2,
//		const CRxGePoint3d&    pt3);
//	~CRxDbTrace();
//	CRXDB_DECLARE_MEMBERS(CRxDbTrace);
//
//	// returns eInvalidIndex if index is out of range
//	CDraft::ErrorStatus getPointAt(CAXA::UInt16 idx, CRxGePoint3d& PntRes) const;
//	CDraft::ErrorStatus setPointAt(CAXA::UInt16 idx, const CRxGePoint3d&);
//
//	double              thickness() const;
//	CDraft::ErrorStatus   setThickness(double);
//
//	CRxGeVector3d        normal() const;
//	CDraft::ErrorStatus   setNormal(const CRxGeVector3d&);
//
//	virtual CAXA::Boolean    isPlanar() const { return CAXA::kTrue; }
//	virtual CDraft::ErrorStatus getPlane(CRxGePlane&, CRxDb::Planarity&) const;
//
//	virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;
//
//	virtual bool        castShadows() const;
//	virtual bool        receiveShadows() const;
//};
//
//class CRxDbShape: public CrxDbEntity
//{
//public:
//	CRxDbShape();
//	CRxDbShape(const CRxGePoint3d&  position,
//		double        size,
//		double        rotation    = 0,
//		double        widthFactor = 0);
//	~CRxDbShape();
//	CRXDB_DECLARE_MEMBERS(CRxDbShape);
//
//	CRxGePoint3d         position() const;
//	CDraft::ErrorStatus   setPosition(const CRxGePoint3d&); 
//
//	double              size() const;
//	CDraft::ErrorStatus   setSize(double);
//
//	CxCHAR*              name() const;
//	CDraft::ErrorStatus   setName(const CxCHAR*); 
//
//	double              rotation() const;
//	CDraft::ErrorStatus   setRotation(double);
//
//	double              widthFactor() const;
//	CDraft::ErrorStatus   setWidthFactor(double);
//
//	double              oblique() const;
//	CDraft::ErrorStatus   setOblique(double);
//
//	double              thickness() const;
//	CDraft::ErrorStatus   setThickness(double);
//
//	CRxGeVector3d        normal() const;
//	CDraft::ErrorStatus   setNormal(const CRxGeVector3d&);
//
//	virtual CAXA::Boolean    isPlanar() const { return CAXA::kTrue; }
//	virtual CDraft::ErrorStatus getPlane(CRxGePlane&, CRxDb::Planarity&) const;
//
//	CAXA::Int16      shapeNumber() const;
//	CDraft::ErrorStatus setShapeNumber(CAXA::Int16);
//
//	CrxDbObjectId        styleId() const;
//	CDraft::ErrorStatus   setStyleId(CrxDbObjectId id);
//
//	// Obsolete names for the "shape style id" get/set methods:
//	CrxDbObjectId        shapeIndex() const { return this->styleId(); }
//	CDraft::ErrorStatus   setShapeIndex(CrxDbObjectId id)
//	{ return this->setStyleId(id); }
//
//	virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;
//};
//
//class CRxDbViewport: public CrxDbEntity
//{
//public:
//	CRxDbViewport();
//	~CRxDbViewport();
//	CRXDB_DECLARE_MEMBERS(CRxDbViewport);
//
//	// view association
//
//	CDraft::ErrorStatus setModelView      (const CRxDbXrefObjectId &xrefObjId);
//	CDraft::ErrorStatus getModelView      (CRxDbXrefObjectId &xrefObjId) const;
//	CDraft::ErrorStatus removeModelView   (void);
//
//	CDraft::ErrorStatus setSheetView      (CrxDbObjectId objId);
//	CDraft::ErrorStatus getSheetView      (CrxDbObjectId &objId)const;
//	CDraft::ErrorStatus removeSheetView   (void);
//
//	CDraft::ErrorStatus setLabelBlock     (CrxDbObjectId objId);
//	CDraft::ErrorStatus getLabelBlock     (CrxDbObjectId &objId)const;
//	CDraft::ErrorStatus removeLabelBlock  (void);
//
//	CDraft::ErrorStatus syncModelView     (void);
//
//	// Thumbnails
//
//#ifdef _WINDOWS_
//	CDraft::ErrorStatus getThumbnail (BITMAPINFO*& thumbnail) const;
//	CDraft::ErrorStatus setThumbnail(const BITMAPINFO * thumbnail);
//#endif
//
//	// Set methods will return eCannotChangeActiveViewport if called
//	// when the Viewport is currently active.  
//
//	double            height() const;
//	CDraft::ErrorStatus setHeight(double);
//
//	double            width() const;
//	CDraft::ErrorStatus setWidth(double);
//
//	CRxGePoint3d       centerPoint() const;
//	CDraft::ErrorStatus setCenterPoint(const CRxGePoint3d&);
//
//	CAXA::Int16      number() const;
//
//	bool              isOn() const;
//	CDraft::ErrorStatus setOn();
//	CDraft::ErrorStatus setOff();
//
//	CRxGePoint3d       viewTarget() const;
//	CDraft::ErrorStatus setViewTarget(const CRxGePoint3d&); 
//
//	CRxGeVector3d      viewDirection() const;
//	CDraft::ErrorStatus setViewDirection(const CRxGeVector3d&);
//
//	// Model Space height, and center in Display coordinates
//	//
//	double            viewHeight() const;
//	CDraft::ErrorStatus setViewHeight(double ht);
//
//	CRxGePoint2d       viewCenter() const;
//	CDraft::ErrorStatus setViewCenter(const CRxGePoint2d& pt);
//
//	double            twistAngle() const;
//	CDraft::ErrorStatus setTwistAngle(double);
//
//	double            lensLength() const;
//	CDraft::ErrorStatus setLensLength(double);
//
//	bool              isFrontClipOn() const;
//	CDraft::ErrorStatus setFrontClipOn();
//	CDraft::ErrorStatus setFrontClipOff();
//
//	bool              isBackClipOn() const;
//	CDraft::ErrorStatus setBackClipOn();
//	CDraft::ErrorStatus setBackClipOff();
//
//	bool              isFrontClipAtEyeOn() const;
//	CDraft::ErrorStatus setFrontClipAtEyeOn();
//	CDraft::ErrorStatus setFrontClipAtEyeOff();
//
//	// FrontZ 
//	double            frontClipDistance() const;
//	CDraft::ErrorStatus setFrontClipDistance(double newVal);
//
//	// BackZ 
//	double            backClipDistance() const;
//	CDraft::ErrorStatus setBackClipDistance(double newVal);
//
//	bool              isPerspectiveOn() const;
//	CDraft::ErrorStatus setPerspectiveOn();
//	CDraft::ErrorStatus setPerspectiveOff();
//
//	bool              isUcsFollowModeOn() const;
//	CDraft::ErrorStatus setUcsFollowModeOn();
//	CDraft::ErrorStatus setUcsFollowModeOff();
//
//	bool              isUcsIconVisible() const;
//	CDraft::ErrorStatus setUcsIconVisible();
//	CDraft::ErrorStatus setUcsIconInvisible();
//
//	bool              isUcsIconAtOrigin() const;
//	CDraft::ErrorStatus setUcsIconAtOrigin();
//	CDraft::ErrorStatus setUcsIconAtCorner();
//
//	bool              isFastZoomOn() const { return true; }
//	CDraft::ErrorStatus setFastZoomOn() { return CDraft::eOk; }
//	CDraft::ErrorStatus setFastZoomOff() { return CDraft::eOk; }
//
//	CAXA::UInt16     circleSides() const;
//	CDraft::ErrorStatus setCircleSides(CAXA::UInt16);
//
//	bool              isSnapOn() const;
//	CDraft::ErrorStatus setSnapOn();
//	CDraft::ErrorStatus setSnapOff();
//
//	bool              isSnapIsometric() const;
//	CDraft::ErrorStatus setSnapIsometric();
//	CDraft::ErrorStatus setSnapStandard();
//
//	double            snapAngle() const;
//	CDraft::ErrorStatus setSnapAngle(double);
//
//	CRxGePoint2d       snapBasePoint() const;
//	CDraft::ErrorStatus setSnapBasePoint(const CRxGePoint2d&); 
//
//	CRxGeVector2d      snapIncrement() const;
//	CDraft::ErrorStatus setSnapIncrement(const CRxGeVector2d&);
//
//	CAXA::UInt16     snapIsoPair() const;
//	CDraft::ErrorStatus setSnapIsoPair(CAXA::UInt16);
//
//	bool              isGridOn() const;
//	CDraft::ErrorStatus setGridOn();
//	CDraft::ErrorStatus setGridOff();
//
//	bool              isGridBoundToLimits() const;
//	CDraft::ErrorStatus setGridBoundToLimits(bool bNewVal);
//
//	bool              isGridAdaptive() const;
//	CDraft::ErrorStatus setGridAdaptive(bool bNewVal);
//
//	bool              isGridSubdivisionRestricted() const;
//	CDraft::ErrorStatus setGridSubdivisionRestricted(bool bNewVal);
//
//	bool              isGridFollow() const;
//	CDraft::ErrorStatus setGridFollow(bool bNewVal);
//
//	CAXA::UInt16     gridMajor() const;
//	CDraft::ErrorStatus setGridMajor(CAXA::UInt16);
//
//	CRxGeVector2d      gridIncrement() const;
//	CDraft::ErrorStatus setGridIncrement(const CRxGeVector2d&);
//
//	bool              hiddenLinesRemoved() const;
//	CDraft::ErrorStatus showHiddenLines();
//	CDraft::ErrorStatus removeHiddenLines();
//
//	CDraft::ErrorStatus freezeLayersInViewport(const CRxDbObjectIdArray&);
//	CDraft::ErrorStatus thawLayersInViewport(const CRxDbObjectIdArray&);
//	CDraft::ErrorStatus thawAllLayersInViewport();
//	bool              isLayerFrozenInViewport(const CrxDbObjectId& layerId) const;
//	CDraft::ErrorStatus getFrozenLayerList(CRxDbObjectIdArray& ids) const;
//
//	CDraft::ErrorStatus updateDisplay() const;
//
//	CrxDbObjectId       background() const;
//	CDraft::ErrorStatus  setBackground(CrxDbObjectId backgroundId);           
//	CrxDbObjectId       previousBackground(CRxGiDrawable::DrawableType type
//		= CRxGiDrawable::kGeometry) const;
//	CDraft::ErrorStatus  setPreviousBackground(CrxDbObjectId backgroundId,
//		CRxGiDrawable::DrawableType type
//		= CRxGiDrawable::kGeometry);
//	CDraft::ErrorStatus   setPreviousBackground(CrxDbObjectId backgroundId,
//		CRxGiDrawable::DrawableType type,
//		bool bForcedSwitch);
//	bool                previousBackgroundForcedSwitch (void) const;
//
//	// Visual Styles
//	CrxDbObjectId      visualStyle() const;
//	CDraft::ErrorStatus setVisualStyle(const CrxDbObjectId oidVisualStyle);
//
//	// Viewport Lighting
//	//
//	bool                isDefaultLightingOn() const;
//	CDraft::ErrorStatus   setDefaultLightingOn(bool on);
//	CRxGiViewportTraits::DefaultLightingType defaultLightingType() const;
//	CDraft::ErrorStatus   setDefaultLightingType(CRxGiViewportTraits::DefaultLightingType typ);
//
//	// Brightness controls the relative intensity of lights.
//	double              brightness() const;
//	CDraft::ErrorStatus   setBrightness(double);
//	// Contrast controls intensity of ambient light, relative to other lights.
//	double              contrast() const;
//	CDraft::ErrorStatus   setContrast(double);
//
//	CrxCmColor           ambientLightColor() const;
//	CDraft::ErrorStatus   setAmbientLightColor(const CrxCmColor& clr);
//
//	// A single sun (distant light) can be associated with each viewport.
//	CrxDbObjectId        sunId() const;
//	CDraft::ErrorStatus   setSun(CrxDbObjectId &retId, CrxDbObject *pSun);
//	CDraft::ErrorStatus   setSun(CrxDbObjectId &retId, CrxDbObject *pSun, bool eraseOldSun);
//
//	// CrxDbEntity overrides
//	//
//	virtual CAXA::UInt32     setAttributes(CRxGiDrawableTraits*);
//	virtual CAXA::Boolean    worldDraw   (CRxGiWorldDraw* pWd);
//
//	bool              isLocked() const;
//	CDraft::ErrorStatus setLocked();
//	CDraft::ErrorStatus setUnlocked();
//
//	CDraft::ErrorStatus setAnnotationScale(const CRxDbAnnotationScale *pScaleObj);
//	// get current annotation scale, return a pointer to CRxDbAnnotationScale, 
//	// caller is responsible for releasing the memory later
//	CRxDbAnnotationScale* annotationScale() const;
//
//	bool              isTransparent() const;
//	CDraft::ErrorStatus setTransparent();
//	CDraft::ErrorStatus setOpaque();
//
//	enum StandardScaleType {
//		kScaleToFit,        // Scaled to Fit
//		kCustomScale,       // Scale is not a standard scale
//		k1_1,               // 1:1
//		k1_2,               // 1:2
//		k1_4,               // 1:4
//		k1_8,               // 1:8
//		k1_10,              // 1:10
//		k1_16,              // 1:16
//		k1_20,              // 1:20
//		k1_30,              // 1:30
//		k1_40,              // 1:40
//		k1_50,              // 1:50
//		k1_100,             // 1:100
//		k2_1,               // 2:1
//		k4_1,               // 4:1
//		k8_1,               // 8:1
//		k10_1,              // 10:1
//		k100_1,             // 100:1
//		k1_128in_1ft,       // 1/128"= 1'
//		k1_64in_1ft,        // 1/64"= 1'
//		k1_32in_1ft,        // 1/32"= 1'
//		k1_16in_1ft,        // 1/16"= 1'
//		k3_32in_1ft,        // 3/32"= 1'
//		k1_8in_1ft,         // 1/8" = 1'
//		k3_16in_1ft,        // 3/16"= 1'
//		k1_4in_1ft,         // 1/4" = 1'
//		k3_8in_1ft,         // 3/8" = 1'
//		k1_2in_1ft,         // 1/2" = 1'
//		k3_4in_1ft,         // 3/4" = 1'
//		k1in_1ft,           // 1"= 1'
//		k1and1_2in_1ft,     // 1 1/2"= 1'
//		k3in_1ft,           // 3"= 1'
//		k6in_1ft,           // 6"= 1'
//		k1ft_1ft            // 1'= 1'
//	};
//
//	double            customScale() const;
//	CDraft::ErrorStatus setCustomScale(double);
//
//	StandardScaleType standardScale() const;
//	CDraft::ErrorStatus setStandardScale(const StandardScaleType);
//
//	CDraft::ErrorStatus plotStyleSheet(CxCHAR *&) const;
//	CDraft::ErrorStatus plotStyleSheet(const CxCHAR *&) const;
//	CDraft::ErrorStatus effectivePlotStyleSheet(const CxCHAR *&);
//	CDraft::ErrorStatus setPlotStyleSheet(const CxCHAR *);
//
//	bool              isNonRectClipOn() const;
//	CDraft::ErrorStatus setNonRectClipOn();
//	CDraft::ErrorStatus setNonRectClipOff();
//
//	CrxDbObjectId      nonRectClipEntityId() const;
//	CDraft::ErrorStatus setNonRectClipEntityId(CrxDbObjectId);
//
//	virtual void      erased(const CrxDbObject* , CAXA::Boolean);
//	virtual void      modified(const CrxDbObject *);
//	virtual void      copied(const CrxDbObject* pDbObj,const CrxDbObject* pNewObj);
//	virtual void      subObjModified(const CrxDbObject* pDbObj, 
//		const CrxDbObject* pSubObj);
//
//	// UCS query methods.
//	//
//	CDraft::ErrorStatus getUcs (CRxGePoint3d& origin,
//		CRxGeVector3d& xAxis,
//		CRxGeVector3d& yAxis ) const;
//	bool              isUcsOrthographic(CRxDb::OrthographicView& view) const;
//	CrxDbObjectId      ucsName           () const;
//	double            elevation         () const;
//
//	// UCS set methods.
//	//
//	CDraft::ErrorStatus setUcs(const CRxGePoint3d& origin,
//		const CRxGeVector3d& xAxis,
//		const CRxGeVector3d& yAxis);
//	CDraft::ErrorStatus setUcs(CRxDb::OrthographicView view);
//	CDraft::ErrorStatus setUcs(const CrxDbObjectId& ucsId);
//	CDraft::ErrorStatus setUcsToWorld();
//	CDraft::ErrorStatus setElevation(double elev );
//
//	// Orthographic view methods.
//	//
//	bool           isViewOrthographic(CRxDb::OrthographicView& view ) const;
//	CDraft::ErrorStatus setViewDirection(CRxDb::OrthographicView view );
//
//	// Methods to get/set UCSVP for viewport.
//	//
//	bool           isUcsSavedWithViewport () const;
//	void           setUcsPerViewport ( bool ucsvp );
//
//	// RenderMode methods
//	void setRenderMode(CRxDbAbstractViewTableRecord::RenderMode mode);
//	CRxDbAbstractViewTableRecord::RenderMode renderMode() const;
//
//	virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;
//
//	// ShadePlot enum and get/set methods
//	enum ShadePlotType {
//		kAsDisplayed    = 0,
//		kWireframe      = 1,
//		kHidden         = 2,
//		kRendered       = 3,
//		kVisualStyle    = 4,
//		kRenderPreset   = 5
//	};
//
//	ShadePlotType     shadePlot() const;
//	CDraft::ErrorStatus setShadePlot(const ShadePlotType);
//
//	CrxDbObjectId      shadePlotId() const;
//	CDraft::ErrorStatus setShadePlot(const ShadePlotType type,
//		const CrxDbObjectId shadePlotId);
//
//	bool              plotWireframe() const;
//	bool              plotAsRaster()  const;
//
//	CDraft::ErrorStatus toneOperatorParameters(AcGiToneOperatorParameters& params) const;
//	CDraft::ErrorStatus setToneOperatorParameters(const AcGiToneOperatorParameters& params);
//};

/*------------------------------------------------------------------------------
// CRxDbSolid : Solid
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(D7676D4E-B9E0-46C3-894D-E9EF7FB66FB2,CRxDbSolid)
class CRXDB_API CRxDbSolid: public CRxDbEntity
{
public:
	CRxDbSolid(ICxCrxObject *i_pCRxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbSolid)
};

/*------------------------------------------------------------------------------
// CRxDbViewPort : ViewPort
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(257D27F1-F719-424a-BCD0-4F1BD6540B14,CRxDbViewPort)
class CRXDB_API CRxDbViewPort: public CRxDbEntity
{
public:
	CRxDbViewPort(ICxCrxObject *i_pCRxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbViewPort)
};

/*------------------------------------------------------------------------------
// CRxDbShape : Shape
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(470C28BD-1F29-4B73-BB95-5F888F7A2256,CRxDbShape)
class CRXDB_API CRxDbShape: public CRxDbEntity
{
public:
	CRxDbShape(ICxCrxObject *i_pCRxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbShape)
};


/*------------------------------------------------------------------------------
// CRxDbHelix : Helix
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(F81D86C6-79F8-4879-B093-9F21AB3D3C12,CRxDbHelix)
class CRXDB_API CRxDbHelix: public CRxDbCurve
{
public:
	CRxDbHelix(ICxCrxObject *i_pCRxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbHelix)
};

/*------------------------------------------------------------------------------
// CRxDbMLine : MLine
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(50292D25-4622-45d6-A121-90BDAE65AD7A,CRxDbMline)
class CRXDB_API CRxDbMline: public CRxDbCurve
{
public:
	CRxDbMline(ICxCrxObject *i_pCRxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbMline)
};

/*------------------------------------------------------------------------------
// CRxDbAcSolid : AcSolid
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(D7676D4E-B9E0-46C3-894D-E9EF7FB66FB2,CRxDbAcSolid)
class CRXDB_API CRxDbAcSolid: public CRxDbCurve
{
public:
	CRxDbAcSolid(ICxCrxObject *i_pCRxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbAcSolid)
};

/*------------------------------------------------------------------------------
// CRxDbTrace : Trace
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(C7985F53-C6C1-40b6-A7D3-3FA537DB55D5,CRxDbTrace)
class CRXDB_API CRxDbTrace: public CRxDbEntity
{
public:
	CRxDbTrace(ICxCrxObject *i_pCRxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbTrace)
};

/*------------------------------------------------------------------------------
// CRxDbWipeout : Wipeout
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(A843A444-3017-45ca-83E8-E581368B51A1,CRxDbWipeout)
class CRXDB_API CRxDbWipeout: public CRxDbImageRef
{
public:
	CRxDbWipeout(ICxCrxObject *i_pCRxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbWipeout)
};

/*------------------------------------------------------------------------------
// CRxDbMInsertBlock : MInsertBlock
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(912CCBC8-F300-4447-842C-6661747754B3,CRxDbMInsertBlock)
class CRXDB_API CRxDbMInsertBlock: public CRxDbBlockReference
{
public:
	CRxDbMInsertBlock(ICxCrxObject *i_pCRxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbMInsertBlock)
};

/*------------------------------------------------------------------------------
// CRxDbRay : Ray
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(DB8A11CE-FCC8-4097-8291-F1924CB55AC9,CRxDbRay)
class CRXDB_API CRxDbRay: public CRxDbCurve
{
public:
	CRxDbRay(ICxCrxObject *i_pCRxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbRay)

	virtual CDraft::ErrorStatus getSplitCurves (const CRxGePoint3dArray& points,
                                                CRxDbVoidPtrArray& curveSegments) const;
	
	CRxGePoint3d  basePoint() const;
	void         setBasePoint(const CRxGePoint3d& pt); 

	CRxGeVector3d unitDir() const;
	void         setUnitDir(const CRxGeVector3d& vec);

};

/*------------------------------------------------------------------------------
// CRxDbXline : Xline
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(3D98EAC3-4CF1-444a-8204-FB392CCD23C8,CRxDbXline)
class CRXDB_API CRxDbXline: public CRxDbCurve
{
public:
	CRxDbXline(ICxCrxObject *i_pCRxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDbXline)

	virtual CDraft::ErrorStatus getSplitCurves (const CRxGePoint3dArray& points,
		CRxDbVoidPtrArray& curveSegments) const;

	CRxGePoint3d  basePoint() const;
	void         setBasePoint(const CRxGePoint3d& pt); 

	CRxGeVector3d unitDir() const;
	void         setUnitDir(const CRxGeVector3d& vec);
};

/*------------------------------------------------------------------------------
// CRxDb3DPolyline : 3DPolyline
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(D5CEE002-6408-4d9b-BE79-6C4CF4EFE4D6,CRxDb3DPolyline)
class CRXDB_API CRxDb3DPolyline: public CRxDbCurve
{
public:
	CRxDb3DPolyline(ICxCrxObject *i_pCRxObject = NULL);
	CRX_DECLARE_DYNCREATE(CRxDb3DPolyline)
};


#pragma pack(pop)

#endif

