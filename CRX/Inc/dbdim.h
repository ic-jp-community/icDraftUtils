#ifndef CRX_DBDIM_H
#define CRX_DBDIM_H
//
//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//
//  DESCRIPTION: Exported dimension classes
//
//  CrxRxObject
//    CrxDbObject
//      CrxDbEntity
//        CrxDbDimension
//          CrxDbOrdinateDimension
//          CrxDbAlignedDimension
//          CrxDbRotatedDimension
//          CrxDb3PointAngularDimension
//          CrxDb2LineAngularDimension
//          CrxDbRadialDimension
//          CrxDbDiametricDimension
//          CrxDbArcDimension
//          CrxDbRadialDimensionLarge
//
//  The CRxDmUtil dimstyle utility function namespace is also here.
//
#include "dbmain.h"
#include "dbmtext.h"
#include "dbsymtb.h"
#include "gemat3d.h"

#pragma pack(push, 8)

//  ----------- Utility functions for dimensioning api: -------------------
//
namespace CRxDmUtil
{
    // Return R14 dimvar value given new dimvar values:
    //
    int dimfit  (int dimatfit, int dimtmove);
    int dimunit (int dimlunit, int dimfrac );

    // Return R15 dimvar value, given old dimvar value:
    //
    int dimatfit(int dimfit);
    int dimtmove(int dimfit);
    int dimlunit(int dimunit);
    int dimfrac (int dimunit);


    // -------  Arrowhead management utilities:  ---------

    // All functions will take either local or global name as input.

    // Arrow name utilities:
    // - All four name functions return the same name for user-defined
    //   arrowheads -- the name of the block in the CrxDbBlockTable.
    // - All four name functions return NULL if the input is not a valid
    //   arrowhead name or block Id.
    // Caller is responsible for freeing the memory which is passed back.
    //
    // Given the name (or objectId) of an arrowhead, return the
    // globally invariant name:
    const CxCHAR * globalArrowName(const CxCHAR * pName);
    const CxCHAR * globalArrowName(CRxDbObjectId blockId);
    //
    // Given the name (or objectId) of an arrowhead, return the
    // local name:
    const CxCHAR * arrowName(const CxCHAR * pName);
    const CxCHAR * arrowName(CRxDbObjectId blockId);

    // Is this the local or global name of a built-in (pre-defined) arrowhead?
    bool isBuiltInArrow(const CxCHAR * pName);

    // Is this the local or global name of a "no length" arrowhead?
    bool isZeroLengthArrow(const CxCHAR * pName);

    // Both of these look up pName in the CrxDbBlockTable and return the id 
    //  of the CRxDbBlockTableRecord if found.
    //
    // findArrowId() returns eKeyNotFound if the block is not present:
    CDraft::ErrorStatus findArrowId(const CxCHAR * pName, 
                                  CRxDbObjectId& blockId, 
                                  CRxDbDatabase* pDb = 0);
    //
    // getArrowId() will create the block if pName is a built-in arrowhead name:
    CDraft::ErrorStatus getArrowId(const CxCHAR * pName, 
                                 CRxDbObjectId& blockId, 
                                 CRxDbDatabase* pDb = 0);
};


class CRXDB_API CCxDbDimensionTolerance
{
protected:
	CCxDbDimensionTolerance();
	virtual ~CCxDbDimensionTolerance();

public:
	//输出形式
	// 0: 代号； 1:偏差; 2:（偏差）；3：代号（偏差） 4:极限尺寸
	short					outFormat() const;
	CDraft::ErrorStatus		setOutFormat(short);

	//公差是否为用户输入
	CAXA::Boolean			isUserTolerance() const;
	CDraft::ErrorStatus		setUserTolerance(CAXA::Boolean);
	
	//尺寸公差类型
	//		0: CCxDbDimDeviationTolerance
	//		1: CCxDbDimSymbolTolerance
	//		2: CCxDbDimAssemblyTolerance
	//		3: CCxDbDimAngleTol
	virtual	long			toleranceType() const = 0;

protected:
	short			mOutFormat;
	CAXA::Boolean	mIsUserTolerance;
};

// 
class CRXDB_API CCxDbDimDeviationToleranceBase : public CCxDbDimensionTolerance
{
protected:
	CCxDbDimDeviationToleranceBase();

public:
	//基本尺寸值
	double					baseValue() const;
	CDraft::ErrorStatus		setBaseValue(double);

	//上偏差
	double					upTolerance() const;
	CDraft::ErrorStatus		setUpTolerance(double);

	//下偏差
	double					downTolerance() const;
	CDraft::ErrorStatus		setDownTolerance(double);

protected:
	double		mBaseValue, mUpTolerance, mDownTolerance;
};

// 尺寸公差
class CRXDB_API CCxDbDimDeviationTolerance : public CCxDbDimDeviationToleranceBase
{
public:
	CCxDbDimDeviationTolerance(double baseValue, double upTolerance, double downTolerance, short outFormat );
	virtual ~CCxDbDimDeviationTolerance();

	//尺寸公差类型
	virtual	long			toleranceType() const;
};

// 符号公差
class CRXDB_API CCxDbDimSymbolTolerance : public CCxDbDimDeviationToleranceBase
{
public:
	CCxDbDimSymbolTolerance(double baseValue, CxCHAR* symbol, 
		double upTolerance, double downTolerance, short outFormat);
	virtual ~CCxDbDimSymbolTolerance();

public:
	//尺寸公差类型
	virtual	long			toleranceType() const;

	//符号
	CxCHAR*					symbol() const;
	CDraft::ErrorStatus		setSymbol(const CxCHAR *);


protected:
	CxCHAR*			mSymbol;
};

// 配合公差
class CRXDB_API CCxDbDimAssemblyTolerance : public CCxDbDimensionTolerance
{
public:
	CCxDbDimAssemblyTolerance(double baseValue, short norm, CxCHAR* holeSymbol, 
		 CxCHAR* axisSymbol, short assemblyType);
	virtual ~CCxDbDimAssemblyTolerance();

public:
	//尺寸公差类型
	virtual	long			toleranceType() const;

	//基本尺寸值
	double					baseValue() const;
	CDraft::ErrorStatus		setBaseValue(double);

	//基准
	short					norm() const;
	CDraft::ErrorStatus		setNorm(short);

	//孔代号
	CxCHAR *				holeSymbol() const;
	CDraft::ErrorStatus		setHoleSymbol(const CxCHAR *);

	//轴代号
	CxCHAR *				axisSymbol() const;
	CDraft::ErrorStatus		setAxisSymbol(const CxCHAR *);


	//配合类型
	short					assemblyType() const;
	CDraft::ErrorStatus		setAssemblyType(short);

protected:
	double		mBaseValue;
	short		mNorm;
	CxCHAR*		mHoleSymbol;
	CxCHAR*		mAxisSymbol;
	short		mAssemblyType;
};

// 角度公差
class CRXDB_API CCxDbDimAngleTol : public CCxDbDimensionTolerance
{
public:
	CCxDbDimAngleTol(short upDegree, short upMinute, short upSecond, 
		short downDegree, short downMinute, short downSecond );
	virtual ~CCxDbDimAngleTol();

public:
	//尺寸公差类型
	virtual	long			toleranceType() const;

	//上偏差：度
	short					upDegree() const;
	CDraft::ErrorStatus		setUpDegree(short);

	//上偏差：分
	short					upMinute() const;
	CDraft::ErrorStatus		setUpMinute(short);

	//上偏差：秒
	short					upSecond() const;
	CDraft::ErrorStatus		setUpSecond(short);

	//下偏差：度
	short					downDegree() const;
	CDraft::ErrorStatus		setDownDegree(short);

	//下偏差：分
	short					downMinute() const;
	CDraft::ErrorStatus		setDownMinute(short);

	//下偏差：秒
	short					downSecond() const;
	CDraft::ErrorStatus		setDownSecond(short);

protected:
	short	mUpDegree, mUpMinute, mUpSecond;
	short	mDownDegree, mDownMinute, mDownSecond;
};

CRX_DEFINE_NULL_CLSID(CRxDbDimension)
class CRXDB_API CRxDbDimension: public CRxDbEntity
{
protected:
    CRxDbDimension(ICxCrxObject *i_pCrxObject = NULL);
public:
    ~CRxDbDimension();
public:
	CRX_DECLARE_DYNAMIC(CRxDbDimension);

	CRxGePoint3d         textPosition() const;
    CDraft::ErrorStatus   setTextPosition(const CRxGePoint3d&);

    CAXA::Boolean      isUsingDefaultTextPosition() const;
    CDraft::ErrorStatus   useSetTextPosition();
    CDraft::ErrorStatus   useDefaultTextPosition();

    CRxGeVector3d        normal() const;
    CDraft::ErrorStatus   setNormal(const CRxGeVector3d&);

//     virtual CAXA::Boolean    isPlanar() const { return true; }
//     virtual CDraft::ErrorStatus getPlane(CRxGePlane&, CRxDb::Planarity&) const;

    double              elevation() const;
    CDraft::ErrorStatus   setElevation(double);

    CxCHAR *             dimensionText() const;
    CDraft::ErrorStatus   setDimensionText(const CxCHAR *);

	CxCHAR *             dimensionPrefix() const; //前缀
	CDraft::ErrorStatus   setDimensionPrefix(const CxCHAR *);

	CxCHAR *             dimensionPostfix() const; //后缀
	CDraft::ErrorStatus   setDimensionPostfix(const CxCHAR *);

	CxCHAR *             dimensionNoteText() const; //附注
	CDraft::ErrorStatus   setDimensionNoteText(const CxCHAR *);

	CCxDbDimensionTolerance*	dimensionTolerance() const; //公差
	CDraft::ErrorStatus   setDimensionTolerance(const CCxDbDimensionTolerance*);



    double              textRotation() const;
    CDraft::ErrorStatus   setTextRotation(double);

    CRxDbObjectId        dimensionStyle() const;
    CDraft::ErrorStatus   setDimensionStyle(CRxDbObjectId);

    CRxDbMText::AttachmentPoint textAttachment() const;
    CDraft::ErrorStatus   setTextAttachment(CRxDbMText::AttachmentPoint eAtt);

    CRxDb::LineSpacingStyle textLineSpacingStyle() const;
    CDraft::ErrorStatus   setTextLineSpacingStyle(CRxDb::LineSpacingStyle eStyle);

    double              textLineSpacingFactor() const;
    CDraft::ErrorStatus   setTextLineSpacingFactor(double dFactor);

    CDraft::ErrorStatus   getDimstyleData(CRxDbDimStyleTableRecord*& pRecord) const;
    CDraft::ErrorStatus   setDimstyleData(CRxDbDimStyleTableRecord* pNewData);
    CDraft::ErrorStatus   setDimstyleData(CRxDbObjectId newDataId);

    // Note: this erased() method doesn't actually get called!  The
    // dbObj arg is not const, so it is not really overriding the
    // reactor's base class method.
    //
    virtual void        erased(CRxDbObject* dbObj, CAXA::Boolean bErasing);

    virtual void        objectClosed(const CRxDbObjectId dbObj);

    double              horizontalRotation() const;
    CDraft::ErrorStatus   setHorizontalRotation(double newVal);

    // Functions for accessing the Dimension's defining block
    //
    CRxDbObjectId        dimBlockId() const;
    CDraft::ErrorStatus   setDimBlockId(const CRxDbObjectId&);
    CRxGePoint3d         dimBlockPosition() const;
	CDraft::ErrorStatus   setDimBlockPosition(const CRxGePoint3d&);
    CDraft::ErrorStatus   recomputeDimBlock(bool forceUpdate = true);
    CDraft::ErrorStatus   generateLayout();
    CDraft::ErrorStatus   measurement(double &val);
    CDraft::ErrorStatus   formatMeasurement(CxCHAR *MTextContentBuffer,
                                          double measurement,
                                          CxCHAR *dimensionText);
// 
//     // Functions for Dynamic Dimensions control
//     //
    bool                isDynamicDimension() const;
    CDraft::ErrorStatus   setDynamicDimension(bool newVal);
// 
//     //new getOsnapPoints API
//     CDraft::ErrorStatus getOsnapPoints(CRxDb::OsnapMode osnapMode,
//                                      const CrxDbFullSubentPath& subentId,
//                                      const CRxGePoint3d&  pickPoint,
//                                      const CRxGePoint3d&  lastPoint,
//                                      const CRxGeMatrix3d& viewXform,
//                                      CrxGePoint3dArray&   snapPoints,
//                                      CRxDbIntArray &   geomIds) const;
//                                      
//     // Old OSNAP API, for dimensions it is unavailable.
//     CDraft::ErrorStatus   getOsnapPoints(CRxDb::OsnapMode     osnapMode,
//                                        CAXA::GsMarker     gsSelectionMark,
//                                        const CRxGePoint3d&  pickPoint,
//                                        const CRxGePoint3d&  lastPoint,
//                                        const CRxGeMatrix3d& viewXform,
//                                        CrxGePoint3dArray&   snapPoints,
//                                        CRxDbIntArray &   geomIds) const;                                     
   
    CRxDbObjectId dimLineLinetype() const;
    CDraft::ErrorStatus setDimLineLinetype(const CRxDbObjectId linetype);
    CRxDbObjectId dimExt1Linetype() const;
    CDraft::ErrorStatus setDimExt1Linetype(const CRxDbObjectId linetype);
    CRxDbObjectId dimExt2Linetype() const;
    CDraft::ErrorStatus setDimExt2Linetype(const CRxDbObjectId linetype);

    CDraft::ErrorStatus   removeTextField();
    CDraft::ErrorStatus   fieldToMText(CRxDbMText* pDimMText);
    CDraft::ErrorStatus   fieldFromMText(CRxDbMText* pDimMText);

    // Dimension variable api:
    //
    #undef DBDIMVAR_H                   // force the file to get read again
    #include "dbdimvar.h"
    // DEPRECATED METHODS!
    // These are supported but will be removed in future releases:
    //
    int dimfit() const;
    int dimunit() const;

    CDraft::ErrorStatus setDimfit (int );
    CDraft::ErrorStatus setDimunit(int );
    //
    // end DEPRECATED METHODS!
    
    // Functions for internal use only
    //
    bool                isHorizontalRefTextRotation() const;
    CDraft::ErrorStatus   setHorizontalRefTextRotation(bool newVal);

    // Dimension Flip Arrow Support
    bool getArrowFirstIsFlipped() const;
    bool getArrowSecondIsFlipped() const;
    CDraft::ErrorStatus setArrowFirstIsFlipped(bool bIsFlipped);
    CDraft::ErrorStatus setArrowSecondIsFlipped(bool bIsFlipped);

    virtual bool castShadows() const;
    virtual void setCastShadows(bool newVal);
    virtual bool receiveShadows() const;
    virtual void setReceiveShadows(bool newVal);

    CRxGeMatrix3d blockTransform() const;

    // Spago inspection dimension enhancement
    enum DimInspect {
        kShapeRemove  = 0,     // Not displayed
        kShapeRound   = 1,     // Rounded end (default)
        kShapeAngular = 2,     // Angular end
        kShapeNone    = 4,     // No bounding shape
        kShapeLabel   = 0x10,  // Label seperator and alpha field displayed
        kShapeRate    = 0x20,  // Shape seperator and alpha field displayed
    };
    bool inspection() const;
    CDraft::ErrorStatus setInspection(bool val);

    int inspectionFrame() const;
    CDraft::ErrorStatus setInspectionFrame(int frame);

    const CxCHAR* inspectionLabel() const;
    CDraft::ErrorStatus setInspectionLabel(const CxCHAR* label);

    const CxCHAR* inspectionRate() const;
    CDraft::ErrorStatus setInspectionRate(const CxCHAR* label);

	long                  DimTextPositionMethod() const; 
	CDraft::ErrorStatus   setDimTextPositionMethod(long newVal);

	CRxGePoint3d         IntLPoint() const;
	CRxGePoint3d         IntRPoint() const;


	CRxGePoint3d         dimPosition() const;
	CDraft::ErrorStatus   setDimPosition(const CRxGePoint3d&);

	bool txtFrame();
	CDraft::ErrorStatus setTxtFrame(bool i_bDrawTxtFrame);
	
};

CRX_DEFINE_CLSID(B0449DCD-3D88-4A88-931A-D2BF00216E37,CRxDbOrdinateDimension)
class CRXDB_API CRxDbOrdinateDimension: public CRxDbDimension
{
public:
    CRxDbOrdinateDimension(ICxCrxObject *i_pCrxObject = NULL);
    CRxDbOrdinateDimension(
        CAXA::Boolean     useXAxis,
        const CRxGePoint3d& definingPoint,
        const CRxGePoint3d& leaderEndPoint,
        const CxCHAR *      dimText = NULL,
        CRxDbObjectId       dimStyle  = CRxDbObjectId::kNull);
    ~CRxDbOrdinateDimension();
	CRX_DECLARE_DYNCREATE(CRxDbOrdinateDimension);

    CAXA::Boolean      isUsingXAxis() const;
    CAXA::Boolean      isUsingYAxis() const;
    CDraft::ErrorStatus   useXAxis();
    CDraft::ErrorStatus   useYAxis();

    CRxGePoint3d         origin() const;
    CDraft::ErrorStatus   setOrigin(const CRxGePoint3d&);

    CRxGePoint3d         definingPoint() const;
    CDraft::ErrorStatus   setDefiningPoint(const CRxGePoint3d&);

    CRxGePoint3d         leaderEndPoint() const;
    CDraft::ErrorStatus   setLeaderEndPoint(const CRxGePoint3d&);

    // Get corresponding COM wrapper class ID
    //
//     virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;
};

CRX_DEFINE_CLSID(1DA848B5-8C84-4C11-80D6-45CF9B26AA48,CRxDbAlignedDimension)
class CRXDB_API CRxDbAlignedDimension: public CRxDbDimension
{
public:
    CRxDbAlignedDimension(ICxCrxObject *i_pCrxObject = NULL);
    CRxDbAlignedDimension(
        const CRxGePoint3d& xLine1Point,
        const CRxGePoint3d& xLine2Point,
        const CRxGePoint3d& dimLinePoint,
        const CxCHAR *      dimText = NULL,
        CRxDbObjectId       dimStyle = CRxDbObjectId::kNull);
    ~CRxDbAlignedDimension();
    CRX_DECLARE_DYNCREATE(CRxDbAlignedDimension);

    CRxGePoint3d         xLine1Point() const;
    CDraft::ErrorStatus   setXLine1Point(const CRxGePoint3d&);

    CRxGePoint3d         xLine2Point() const;
    CDraft::ErrorStatus   setXLine2Point(const CRxGePoint3d&);

    CRxGePoint3d         dimLinePoint() const;
    CDraft::ErrorStatus   setDimLinePoint(const CRxGePoint3d&);

    double              oblique() const;
    CDraft::ErrorStatus   setOblique(double);

    // Get corresponding COM wrapper class ID
    //
//     virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;

    // Aligned dimension Jog symbol
    bool jogSymbolOn() const;
    CDraft::ErrorStatus setJogSymbolOn(bool value);

    CRxGePoint3d jogSymbolPosition() const;
    CDraft::ErrorStatus setJogSymbolPosition(const CRxGePoint3d& pt);

	CDraft::ErrorStatus   setPaperScale(double dPaperScale);
};

CRX_DEFINE_CLSID(1DA848B5-8C84-4C11-80D6-45CF9B26AA48,CRxDbRotatedDimension)
class CRXDB_API CRxDbRotatedDimension: public CRxDbDimension
{
public:
    CRxDbRotatedDimension(ICxCrxObject *i_pCrxObject = NULL);
    CRxDbRotatedDimension(
        double             rotation,
        const CRxGePoint3d& xLine1Point,
        const CRxGePoint3d& xLine2Point,
        const CRxGePoint3d& dimLinePoint,
        const CxCHAR *      dimText = NULL,
        CRxDbObjectId       dimStyle = CRxDbObjectId::kNull);
    ~CRxDbRotatedDimension();
    CRX_DECLARE_DYNCREATE(CRxDbRotatedDimension);

    CRxGePoint3d         xLine1Point() const;
    CDraft::ErrorStatus   setXLine1Point(const CRxGePoint3d&);

    CRxGePoint3d         xLine2Point() const;
    CDraft::ErrorStatus   setXLine2Point(const CRxGePoint3d&);

    CRxGePoint3d         dimLinePoint() const;
    CDraft::ErrorStatus   setDimLinePoint(const CRxGePoint3d&);

    double              oblique() const;
    CDraft::ErrorStatus   setOblique(double);

    double              rotation() const;
    CDraft::ErrorStatus   setRotation(double);

    // Get corresponding COM wrapper class ID
    //
//     virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;

    // Rotated dimension Jog symbol
    bool jogSymbolOn() const;
    CDraft::ErrorStatus setJogSymbolOn(bool value);

    CRxGePoint3d jogSymbolPosition() const;
    CDraft::ErrorStatus setJogSymbolPosition(const CRxGePoint3d& pt);

	CDraft::ErrorStatus   setPaperScale(double i_dPaperScale);
	
};

CRX_DEFINE_CLSID(D0E58C76-F166-4241-9943-62E6113A9DA4,CRxDb3PointAngularDimension)
class CRXDB_API CRxDb3PointAngularDimension: public CRxDbDimension
{
public:
    CRxDb3PointAngularDimension(ICxCrxObject *i_pCrxObject = NULL);
    CRxDb3PointAngularDimension(
        const CRxGePoint3d& centerPoint,
        const CRxGePoint3d& xLine1Point,
        const CRxGePoint3d& xLine2Point,
        const CRxGePoint3d& arcPoint,
        const CxCHAR *      dimText = NULL,
        CRxDbObjectId       dimStyle = CRxDbObjectId::kNull);
    ~CRxDb3PointAngularDimension();
    CRX_DECLARE_DYNCREATE(CRxDb3PointAngularDimension);

    CRxGePoint3d         arcPoint() const;
    CDraft::ErrorStatus   setArcPoint(const CRxGePoint3d&);

    CRxGePoint3d         xLine1Point() const;
    CDraft::ErrorStatus   setXLine1Point(const CRxGePoint3d&);

    CRxGePoint3d         xLine2Point() const;
    CDraft::ErrorStatus   setXLine2Point(const CRxGePoint3d&);

    CRxGePoint3d         centerPoint() const;
    CDraft::ErrorStatus   setCenterPoint(const CRxGePoint3d&);

    // Get corresponding COM wrapper class ID
    //
//     virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;

    // Angular dimension extension arc for quadrant
    bool extArcOn() const;
    CDraft::ErrorStatus setExtArcOn(bool value);
};

CRX_DEFINE_CLSID(5F9490D4-B797-4119-90B1-93668E2DB71A,CRxDb2LineAngularDimension)
class CRXDB_API CRxDb2LineAngularDimension: public CRxDbDimension
{
public:
    CRxDb2LineAngularDimension(ICxCrxObject *i_pCrxObject = NULL);
    CRxDb2LineAngularDimension(
        const CRxGePoint3d& xLine1Start,
        const CRxGePoint3d& xLine1End,
        const CRxGePoint3d& xLine2Start,
        const CRxGePoint3d& xLine2End,
        const CRxGePoint3d& arcPoint,
        const CxCHAR *      dimText = NULL,
        CRxDbObjectId       dimStyle = CRxDbObjectId::kNull);
    ~CRxDb2LineAngularDimension();
    CRX_DECLARE_DYNCREATE(CRxDb2LineAngularDimension);

    CRxGePoint3d         arcPoint() const;
    CDraft::ErrorStatus   setArcPoint(const CRxGePoint3d&);

    CRxGePoint3d         xLine1Start() const;
    CDraft::ErrorStatus   setXLine1Start(const CRxGePoint3d&);

    CRxGePoint3d         xLine1End() const;
    CDraft::ErrorStatus   setXLine1End(const CRxGePoint3d&);

    CRxGePoint3d         xLine2Start() const;
    CDraft::ErrorStatus   setXLine2Start(const CRxGePoint3d&);

    CRxGePoint3d         xLine2End() const;
    CDraft::ErrorStatus   setXLine2End(const CRxGePoint3d&);

    // Get corresponding COM wrapper class ID
    //
//     virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;

    // Angular dimension extension arc for quadrant
    bool extArcOn() const;
    CDraft::ErrorStatus setExtArcOn(bool value);

	CDraft::ErrorStatus   setPaperScale(double dPaperScale);
};

CRX_DEFINE_CLSID(ABA4BD1E-D922-4B4D-931E-7F4C9D6919E7,CRxDbRadialDimension)
class CRXDB_API CRxDbRadialDimension: public CRxDbDimension
{
public:
    CRxDbRadialDimension(ICxCrxObject *i_pCrxObject = NULL);
    CRxDbRadialDimension(
        const CRxGePoint3d& center,
        const CRxGePoint3d& chordPoint,
        double             leaderLength,
        const CxCHAR *      dimText = NULL,
        CRxDbObjectId       dimStyle = CRxDbObjectId::kNull);
    ~CRxDbRadialDimension();
    CRX_DECLARE_DYNCREATE(CRxDbRadialDimension);

    double              leaderLength() const;
    CDraft::ErrorStatus   setLeaderLength(double);

    CRxGePoint3d         center() const;
    CDraft::ErrorStatus   setCenter(const CRxGePoint3d&);

    CRxGePoint3d         chordPoint() const;
    CDraft::ErrorStatus   setChordPoint(const CRxGePoint3d&);

    // Get corresponding COM wrapper class ID
    //
//     virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;

    // Radial dimension extension arc
    double extArcStartAngle() const;
    CDraft::ErrorStatus setExtArcStartAngle(double newAngle);

    double extArcEndAngle() const;
    CDraft::ErrorStatus setExtArcEndAngle(double newAngle);

	CDraft::ErrorStatus   setPaperScale(double i_dPaperScale);
};

CRX_DEFINE_CLSID(F391CB78-240A-4FBD-9E3F-4F19572391FC,CRxDbDiametricDimension)
class CRXDB_API CRxDbDiametricDimension: public CRxDbDimension
{
public:
    CRxDbDiametricDimension(ICxCrxObject *i_pCrxObject = NULL);
    CRxDbDiametricDimension(
        const CRxGePoint3d& chordPoint,
        const CRxGePoint3d& farChordPoint,
        double             leaderLength,
        const CxCHAR *      dimText = NULL,
        CRxDbObjectId       dimStyle = CRxDbObjectId::kNull);
    ~CRxDbDiametricDimension();
    CRX_DECLARE_DYNCREATE(CRxDbDiametricDimension);

    double              leaderLength() const;
    CDraft::ErrorStatus   setLeaderLength(double);

    CRxGePoint3d         chordPoint() const;
    CDraft::ErrorStatus   setChordPoint(const CRxGePoint3d&);

    CRxGePoint3d         farChordPoint() const;
    CDraft::ErrorStatus   setFarChordPoint(const CRxGePoint3d&);

    // Get corresponding COM wrapper class ID
    //
//     virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;

    // Diametric dimension extension arc
    double extArcStartAngle() const;
    CDraft::ErrorStatus setExtArcStartAngle(double newAngle);

    double extArcEndAngle() const;
    CDraft::ErrorStatus setExtArcEndAngle(double newAngle);

	CDraft::ErrorStatus   setPaperScale(double i_dPaperScale);
};

// Arc length dimension class
CRX_DEFINE_CLSID(9EA8F853-FF24-41B9-A1F7-900C725BD212,CRxDbArcDimension)
class CRXDB_API CRxDbArcDimension: public CRxDbDimension
{
public:
    // Default constructor
    CRxDbArcDimension(ICxCrxObject *i_pCrxObject = NULL);
    // Primary constructor
    CRxDbArcDimension(
        const CRxGePoint3d& centerPoint,
        const CRxGePoint3d& xLine1Point,
        const CRxGePoint3d& xLine2Point,
        const CRxGePoint3d& arcPoint,
        const CxCHAR * dimText = NULL,
        CRxDbObjectId dimStyle = CRxDbObjectId::kNull);
    // Default destructor
    ~CRxDbArcDimension();
    CRX_DECLARE_DYNCREATE(CRxDbArcDimension);

    // Query method which returns a point on the arc length dimension's dimension arc.
    CRxGePoint3d         arcPoint() const;
    // Set method to set the point which the arc length dimension's dimension arc passes through.
    CDraft::ErrorStatus   setArcPoint(const CRxGePoint3d & arcPt);

    // Query method which returns the start point for the arc length dimension's first extension line.
    CRxGePoint3d         xLine1Point() const;
    // Set method which sets the start point for the arc length dimension's first extension line.        
    CDraft::ErrorStatus   setXLine1Point(const CRxGePoint3d & xLine1Pt);

    // Query method which returns the start point for the arc length dimension's second extension line.
    CRxGePoint3d         xLine2Point() const;
    // Set method which sets the start point for the arc length dimension's second extension line.    
    CDraft::ErrorStatus   setXLine2Point(const CRxGePoint3d & xLine2Pt);

    // Query method which returns the center point of the arc dimensioned by the arc length dimension.
    CRxGePoint3d         centerPoint() const;
    // Set method which sets the center point of the arc dimensioned by the arc length dimension.    
    CDraft::ErrorStatus   setCenterPoint(const CRxGePoint3d & ctrPt);

    // Query method which returns true if this arc length dimension was specified using two points along the arc, 
    // false if the arc length dimension dimensions the entire arc segment.
    bool                isPartial() const;
    // Set method if passed true, the arc length dimension was specified using the entire arc segment, 
    // if passed false the arc length dimension arc length dimension was specified using two points along the arc.
    CDraft::ErrorStatus   setIsPartial(const bool & partial);

    // Query method which returns the parameter of the arc being dimensioned cooresponding to the arc length dimension's first definiton point.
    double              arcStartParam() const;
    // Set method which sets the parameter of the arc being dimensioned cooresponding to the arc length dimension's first definiton point.        
    CDraft::ErrorStatus   setArcStartParam(const double & arcParam);

    // Query method which returns the parameter of the arc being dimensioned cooresponding to the arc length dimension's second definiton point.
    double              arcEndParam() const;
    // Set method which sets the parameter of the arc being dimensioned cooresponding to the arc length dimension's second definiton point.    
    CDraft::ErrorStatus   setArcEndParam(const double & arcParam);

    // Query method which returns true if this arc length dimension has an extra leader drawn to resolve ambiguity, false if the arc length dimension has no extra leader drawn.
    bool                hasLeader() const;
    // Set method if passed true, the arc length dimension has an extra leader drawn to resolve ambiguity, if passed false the arc length dimension has no extra leader drawn.    
    CDraft::ErrorStatus   setHasLeader(const bool & leaderVal);

    // Query method which returns the start point for the arc length dimension's extra leader, if drawn.
    CRxGePoint3d         leader1Point() const;
    // Set method which sets the start point for the arc length dimension's extra leader, if drawn.        
    CDraft::ErrorStatus   setLeader1Point(const CRxGePoint3d & ldr1Pt);

    // Query method which returns the end point for the arc length dimension's extra leader, if drawn.
    CRxGePoint3d         leader2Point() const;
    // Set method which sets the end point for the arc length dimension's extra leader, if drawn.    
    CDraft::ErrorStatus   setLeader2Point(const CRxGePoint3d & ldr2Pt);
    
    // Query method which returns the type of symbol used within the arc length dimension's text string:
    // 0 - Arc symbol precedes text, 1 - Arc symbol is above text, 2 - No arc symbol is used.
    int arcSymbolType() const;
    // Set method which sets the type of symbol to use within the arc length dimension's text string:
    // 0 - Arc symbol precedes text, 1 - Arc symbol is above text, 2 - No arc symbol is used.
    // This overrides the setting of this value in the dimension's style.
    CDraft::ErrorStatus setArcSymbolType(const int symbol);

    // Get corresponding COM wrapper class ID
//     virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;
};

CRX_DEFINE_CLSID(5744B3D8-69BD-417F-9EA1-9E818DD7C25F,CRxDbRadialDimensionLarge)
class CRXDB_API CRxDbRadialDimensionLarge: public CRxDbDimension
{
public:
    // Default constructor
    CRxDbRadialDimensionLarge(ICxCrxObject *i_pCrxObject = NULL);
    // Primary constructor
    CRxDbRadialDimensionLarge(
        const CRxGePoint3d& center,
        const CRxGePoint3d& chordPoint,
        const CRxGePoint3d& overrideCenter,
        const CRxGePoint3d& jogPoint,
        double             jogAngle,
        const CxCHAR *      dimText = NULL,
        CRxDbObjectId       dimStyle = CRxDbObjectId::kNull);
    // Default destructor
    ~CRxDbRadialDimensionLarge();
    CRX_DECLARE_DYNCREATE(CRxDbRadialDimensionLarge);


    // Query method which returns the center point of the arc dimensioned by the jogged radius dimension.    
    CRxGePoint3d         center() const;
    // Set method which sets the center point of the arc dimensioned by the jogged radius dimension.        
    CDraft::ErrorStatus   setCenter(const CRxGePoint3d & centerPoint);

    // Query method which returns the chord point on the arc dimensioned by the jogged radius dimension.    
    CRxGePoint3d         chordPoint() const;
    // Set method which sets the chord point on the arc dimensioned by the jogged radius dimension.        
    CDraft::ErrorStatus   setChordPoint(const CRxGePoint3d & chordPoint);

    // Query method which returns the overidden center point used by the jogged radius dimension.    
    CRxGePoint3d         overrideCenter() const;
    // Set method which sets the overidden center point to use for the jogged radius dimension.        
    CDraft::ErrorStatus   setOverrideCenter(const CRxGePoint3d & overrideCenterPoint);

    // Query method which returns the jog point used by the jogged radius dimension.    
    CRxGePoint3d         jogPoint() const;
    // Set method which sets the jog point used by the jogged radius dimension.        
    CDraft::ErrorStatus   setJogPoint(const CRxGePoint3d & jogPoint);

    // Query method which returns the jog angle used by the jogged radius dimension.    
    double              jogAngle() const;
    // Set method which sets the jog angle used by the jogged radius dimension.        
    CDraft::ErrorStatus   setJogAngle(double jogAngle);

    // Used exclusively by property palette
    // This function is required because once the jogged radius dimension's defining points are updated, all the other defining points need to be updated too.
    CDraft::ErrorStatus   setOverrideCenterPP(const CRxGePoint3d & overrideCenterPointPP);
    // Used exclusively by property palette
    // This function is required because once the jogged radius dimension's defining points are updated, all the other defining points need to be updated too.    
    CDraft::ErrorStatus   setJogPointPP(const CRxGePoint3d & jogPointPP);
    // Used exclusively by property palette
    // This function is required because once the jogged radius dimension's defining points are updated, all the other defining points need to be updated too.    
    CDraft::ErrorStatus   setTextPositionPP(const CRxGePoint3d & textPointPP);

    // Get corresponding COM wrapper class ID
//     virtual CDraft::ErrorStatus   getClassID(CLSID * pClsid) const;

    // Radial large dimension extension arc
    double extArcStartAngle() const;
    CDraft::ErrorStatus setExtArcStartAngle(double newAngle);

    double extArcEndAngle() const;
    CDraft::ErrorStatus setExtArcEndAngle(double newAngle);

	CDraft::ErrorStatus   setPaperScale(double i_dPaperScale);
};

#include "dbDimRay.h"
#include "dbDimTaper.h"
#include "dbDimPitch.h"
#include "dbDimHalf.h"
#include "dbDimOrigin.h"
#include "dbDimChamfer.h"
#include "dbDimLeader.h"
#include "dbDimRough.h"
#include "dbDimDatum.h"
#include "dbDimCuts.h"
#include "dbDimCenterHole.h"
#include "dbDimHolePos.h"
#include "dbDimCrdList.h"
#include "dbDimCoord.h"
#include "dbDimWeld.h"
#include "dbDimGeoTol.h"
#pragma pack(pop)

#endif
