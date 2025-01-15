#ifndef __CRXDBHATCH_H_
#define __CRXDBHATCH_H_

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#include "dbmain.h"
#pragma pack(push, 8)

/*------------------------------------------------------------------------------
// CrxDbHatch : 填充
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(79B9B625-EE7F-4FC9-B9A6-39036A219CF7,CRxDbHatch)
class CRXDB_API CRxDbHatch: public CRxDbEntity
{
public:

	// Enum Definition
	//

	enum HatchObjectType {
		kHatchObject      = 0,
		kGradientObject   = 1
	};

	enum HatchLoopType {
		kDefault             = 0,
		kExternal            = 1,
		kPolyline            = 2,
		kDerived             = 4,
		kTextbox             = 8,
		kOutermost           = 0x10,
		kNotClosed           = 0x20,
		kSelfIntersecting    = 0x40,
		kTextIsland          = 0x80,
		kDuplicate           = 0x100,
		kIsAnnotative        = 0x200,
		kDoesNotSupportScale = 0x400,
		kForceAnnoAllVisible = 0x800,
		kOrientToPaper       = 0x1000,
		kIsAnnotativeBlock   = 0x2000
	};

	enum HatchEdgeType {
		kLine             = 1,
		kCirArc           = 2,
		kEllArc           = 3,
		kSpline           = 4 
	};

	enum HatchPatternType {
		kUserDefined      = 0,
		kPreDefined       = 1,
		kCustomDefined    = 2 
	};

	enum HatchStyle {
		kNormal           = 0,
		kOuter            = 1,
		kIgnore           = 2 
	};

	//enum GradientPatternType {
	//	kPreDefinedGradient     = 0,
	//	kUserDefinedGradient    = 1
	//};

	CRxDbHatch(ICxCrxObject *i_pCrxObject = NULL);

	//i_iType==0表示创建hatch，i_itype==1表示创建solid
	CRxDbHatch(ICxCrxObject *i_pCrxObject, int i_iType);

	//virtual ~CRxDbHatch();
	CRX_DECLARE_DYNCREATE(CRxDbHatch);

	// Hatch Plane Methods
	//
	double elevation() const;
	CDraft::ErrorStatus setElevation(double elevation);

	CRxGeVector3d normal() const;
	CDraft::ErrorStatus setNormal(const CRxGeVector3d& normal);

	//virtual CAXA::Boolean isPlanar() const { return true; }
	//virtual CDraft::ErrorStatus getPlane(CRxGePlane&, CRxDb::Planarity&) const;

	// Hatch Background Color
	//
	//CRxCmColor backgroundColor() const;
	//CDraft::ErrorStatus setBackgroundColor(const CRxCmColor& color);

	// Hatch Boundary Methods
	//
	int numLoops() const;

// 	CAXA::Int32 loopTypeAt(int loopIndex) const;
// 
// 	CDraft::ErrorStatus getLoopAt(int loopIndex,
// 		CAXA::Int32& loopType,
// 		CRxGeVoidPointerArray& edgePtrs,
// 		CRxGeIntArray&  edgeTypes) const;
// 
// 	CDraft::ErrorStatus getLoopAt(int loopIndex,
// 		CAXA::Int32& loopType,
// 		CRxGePoint2dArray& vertices,
// 		CRxGeDoubleArray& bulges) const;
// 
// 	CDraft::ErrorStatus appendLoop(CAXA::Int32 loopType,
// 		const CRxGeVoidPointerArray& edgePtrs,
// 		const CRxGeIntArray&  edgeTypes);
// 
// 	CDraft::ErrorStatus appendLoop(CAXA::Int32 loopType,
// 		const CRxGePoint2dArray& vertices,
// 		const CRxGeDoubleArray& bulges);
// 
//  	CDraft::ErrorStatus insertLoopAt(int loopIndex,
//  		CAXA::Int32 loopType,
//  		const CRxGeVoidPointerArray& edgePtrs,
//  		const CRxGeIntArray&  edgeTypes);
//  
//  	CDraft::ErrorStatus insertLoopAt(int loopIndex,
//  		CAXA::Int32 loopType,
//  		const CRxGePoint2dArray& vertices,
//  		const CRxGeDoubleArray& bulges);

//	CDraft::ErrorStatus removeLoopAt(int loopIndex);


	// Hatch Association Methods 
	//
	bool associative() const;
	CDraft::ErrorStatus setAssociative(bool isAssociative);

	CDraft::ErrorStatus appendLoop(CAXA::Int32 loopType,
		const CRxDbObjectIdArray& dbObjIds);

// 	CDraft::ErrorStatus insertLoopAt(int loopIndex,
// 		CAXA::Int32 loopType,
// 		const CRxDbObjectIdArray& dbObjIds);
// 
// 	CDraft::ErrorStatus getAssocObjIdsAt(int loopIndex,
// 		CRxDbObjectIdArray& dbObjIds) const;
// 
// 	CDraft::ErrorStatus getAssocObjIds(CRxDbObjectIdArray& dbObjIds) const;
// 
// 	CDraft::ErrorStatus removeAssocObjIds();


	// determines Hatch or Gradient object type
	//
	//CRxDbHatch::HatchObjectType hatchObjectType() const;
	//CDraft::ErrorStatus setHatchObjectType(CRxDbHatch::HatchObjectType type);

	//virtual CAXA::Boolean isGradient() const;
	virtual CAXA::Boolean isHatch() const;

	// Gradient Style Methods
	//
	//CRxDbHatch::GradientPatternType gradientType() const;

	//const CxCHAR* gradientName() const;

	//CDraft::ErrorStatus setGradient(CRxDbHatch::GradientPatternType gradType,
	//	const CxCHAR* gradName);

	//double gradientAngle() const;
	//CDraft::ErrorStatus setGradientAngle(double angle);

	//CDraft::ErrorStatus getGradientColors( unsigned int& count, 
	//	CRxCmColor*& colors,
	//	float*& values );

// 	CDraft::ErrorStatus setGradientColors( unsigned int count, 
// 		CRxCmColor* colors,
// 		float* values );
// 
// 	CAXA::Boolean getGradientOneColorMode() const;
// 	CDraft::ErrorStatus setGradientOneColorMode( CAXA::Boolean oneColorMode );
// 
// 	float getShadeTintValue() const;
// 	CDraft::ErrorStatus setShadeTintValue( float value );
// 	CDraft::ErrorStatus setShadeTintValueAndColor2( float value );
// 
// 	float gradientShift() const;
// 	CDraft::ErrorStatus setGradientShift( float shiftValue );
// 
// 	CDraft::ErrorStatus evaluateGradientColorAt( float value,
// 		CRxCmColor& color );

	// Hatch Pattern Methods
	//
	CRxDbHatch::HatchPatternType patternType() const;

	const CxCHAR* patternName() const;

	CDraft::ErrorStatus  setPattern(CRxDbHatch::HatchPatternType patType,
		const CxCHAR* patName);

	double patternAngle() const;//rad
	CDraft::ErrorStatus setPatternAngle(double angle);//rad

	//double patternSpace() const;
	//CDraft::ErrorStatus setPatternSpace(double space);

	double patternScale() const;
	CDraft::ErrorStatus setPatternScale(double scale);

	//bool patternDouble() const;
	//CDraft::ErrorStatus setPatternDouble(bool isDouble);

// 	int numPatternDefinitions() const;
// 	CDraft::ErrorStatus  getPatternDefinitionAt(int index, 
// 		double& angle,
// 		double& baseX,
// 		double& baseY,
// 		double& offsetX,
// 		double& offsetY,
// 		CRxGeDoubleArray& dashes)
// 		const;


	// Hatch Style Methods
	//
	CRxDbHatch::HatchStyle hatchStyle() const;
	CDraft::ErrorStatus setHatchStyle(CRxDbHatch::HatchStyle hstyle);

	// Hatch Graphics Display Control Methods
	//
	CDraft::ErrorStatus  evaluateHatch(bool bUnderestimateNumLines = false);
	//CDraft::ErrorStatus  evaluateHatchAllScales(bool bUnderestimateNumLines = false);
	//bool               lineGenerationEnabled() const;
	//bool               setLineGenerationEnabled(bool bEnable);

//	int numHatchLines() const;

	bool isSolidFill() const;

// 	CDraft::ErrorStatus  getHatchLineDataAt(int index, 
// 		CRxGePoint2d& startPt,
// 		CRxGePoint2d& endPt) const;
// 
// 	CDraft::ErrorStatus  getHatchLinesData(CRxGePoint2dArray& startPts,
// 		CRxGePoint2dArray& endPts) const;

	// Reactor Methods
	//

	//virtual void modifiedGraphics(const CRxDbEntity* pObj);


	// Overridden CRxDbObject Methods
	//
// 	virtual CDraft::ErrorStatus subSwapIdWith(CRxDbObjectId otherId,
// 		CAXA::Boolean swapXdata = false,
// 		CAXA::Boolean swapExtDict = false);


	// Used in conjunction with swapIdWith to swap reference definitions
	// as well.
	//
	//virtual CDraft::ErrorStatus  swapReferences(const CRxDbIdMapping& idMap);

//	CDraft::ErrorStatus getArea(double& a) const;

//	CDraft::ErrorStatus setOriginPoint(const CRxGePoint2d& pt);
//	CRxGePoint2d originPoint() const;

	//CRxDbRegion* getRegionArea() const;

//	void removeHatchLines();

//	protected:
// 	virtual CDraft::ErrorStatus  subGetClassID(CLSID* pClsid) const;

	//////////////////////////////////////////////////////////////////////////
	//caxa add. from teigha method

	CDraft::ErrorStatus GetPickPt(CRxGePoint3d* o_pPickPt);//获取单一情况下的pick点
	CDraft::ErrorStatus SetPickPt(CRxGePoint3d  i_pPickPt);//单一情况下的pick点
	CDraft::ErrorStatus AddPickPt(CRxGePoint3d  i_pPickPt);//用于往内部pickptarray中添加pick点，此种情况下需要保证SetPickPt方法中添加的点与此array中添加的第一个点大小相等
	CDraft::ErrorStatus GetPickPts(CRxGePoint3dArray& o_PickPts);//获取内部pickptarray中的点

};


#pragma pack(pop)

#endif