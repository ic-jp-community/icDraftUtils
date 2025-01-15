//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#ifndef CRX_DBMTEXT_H
#define CRX_DBMTEXT_H
//
//
//  dbmtext.h - multi-line text entity

#include "dbmain.h"
#include "gepnt2d.h"
#include "gept3dar.h"

#pragma pack(push, 8)

//  This structure is used to describe a fragment of text as 
//  extracted by the explodeFragments() member function.  Each 
//  fragment consists of a piece of text with a unique 
//  combination of style information (font, size, color, etc.)
//
struct CRxDbMTextFragment
{
    //  position data
    //
    CRxGePoint3d  location;
    CRxGeVector3d normal;
    CRxGeVector3d direction;

    //  text characters
    //
    CxCHAR*        text;

    //  font names
    //
    CxCHAR*        font;
    CxCHAR*        bigfont;

    //  metrics
    //
    CRxGePoint2d  extents;
    double       capsHeight;
    double       widthFactor;
    double       obliqueAngle;
    double       trackingFactor;
    CRxCmEntityColor color;

    //  stack flags
    //
    unsigned stackTop:1;
    unsigned stackBottom:1;

    //  underline/overline data
    //
    unsigned    underlined:1;
    unsigned    overlined:1;
    CRxGePoint3d underPoints[2];
    CRxGePoint3d overPoints[2];

    //  true type font data
    //
    CxCHAR *  fontname;
    bool    bold;
    bool    italic;

};

//  Fragment Enumerator Callback Function Prototype
//
//  A pointer to a function of this type is expected by the explodeFragments() 
//  member function.  The elaboration function is called once for each 
//  fragment. 'frag' points to the relevant fragment structure. 'param' 
//  contains the value of the 'param' argument given to the explodeFragments()
//   member function. The elaboration function must return 1 to continue the 
//  elaboration operation, or 0 to terminate the operation.
//
typedef int (*CRxDbMTextEnum)(CRxDbMTextFragment *, void *);

class CRxDbText;

CRX_DEFINE_CLSID(76D76221-4358-465D-BC53-4449B3004657,CRxDbMText)
class CRXDB_API CRxDbMText: public  CRxDbEntity
{
public:
	CRxDbMText(ICxCrxObject *i_pCrxObject = NULL);
    ~CRxDbMText();

	CRX_DECLARE_DYNCREATE(CRxDbMText)
// 
//     //  Insertion point
//     //
    CRxGePoint3d     location() const;
    CDraft::ErrorStatus   setLocation(const CRxGePoint3d&);
// 
//     //  Normal vector
//     // 
//     CRxGeVector3d    normal() const;
//     CDraft::ErrorStatus   setNormal(const CRxGeVector3d&);
// 
//     //  Direction vector
//     //
//     CRxGeVector3d    direction() const;
//     CDraft::ErrorStatus   setDirection(const CRxGeVector3d&);
// 
//     //  Rotation angle (radians)
//     // 
    double      rotation() const;
    CDraft::ErrorStatus   setRotation(double);
// 
//     //  Entity width (constraining value)
//     // 
    double      width() const;
    CDraft::ErrorStatus   setWidth(double);
// 
//     //  Descent/Ascent
//     // 
//     double      ascent() const;
//     double      descent() const;
// 
//     //  Text Style (sets initial font)
//     //
    CRxDbObjectId        textStyle() const;
    CDraft::ErrorStatus   setTextStyle(CRxDbObjectId);
// 
//     //  Initial text height (caps height)
//     //
    double      textHeight() const;
    CDraft::ErrorStatus   setTextHeight(double);
// 
    enum AttachmentPoint {
    kTopLeft    = 1,
    kTopCenter  = 2,
    kTopRight   = 3,
    kMiddleLeft = 4,
    kMiddleCenter   = 5,
    kMiddleRight    = 6,
    kBottomLeft = 7,
    kBottomCenter   = 8,
    kBottomRight    = 9,
    kBaseLeft       = 10,   // Reserved for future use
    kBaseCenter     = 11,   // Reserved for future use
    kBaseRight      = 12,   // Reserved for future use
    kBaseAlign      = 13,   // Reserved for future use
    kBottomAlign    = 14,   // Reserved for future use
    kMiddleAlign    = 15,   // Reserved for future use
    kTopAlign       = 16,   // Reserved for future use
    kBaseFit        = 17,   // Reserved for future use
    kBottomFit      = 18,   // Reserved for future use
    kMiddleFit      = 19,   // Reserved for future use
    kTopFit         = 20,   // Reserved for future use
    kBaseMid        = 21,   // Reserved for future use
    kBottomMid      = 22,   // Reserved for future use
    kMiddleMid      = 23,   // Reserved for future use
    kTopMid         = 24,   // Reserved for future use
    };
    AttachmentPoint attachment() const;
    CDraft::ErrorStatus   setAttachment(AttachmentPoint);
    CDraft::ErrorStatus   setAttachmentMovingLocation(AttachmentPoint);
    // This latter method will implicitly setLocation based on the
    // relationship of current and new attachment values in order
    // to keep the extents of the MText object constant.

//     //  Text flow direction
//     //
//     enum FlowDirection {
//     kLtoR       = 1,
//     kRtoL       = 2,    //  not currently supported
//     kTtoB       = 3,
//     kBtoT       = 4,    //  not currently supported
//     kByStyle    = 5
//     };
//     FlowDirection   flowDirection() const;
//     CDraft::ErrorStatus   setFlowDirection(FlowDirection);
// 
//     //  Text contents
//     //
    CxCHAR        *contents() const;
    int         setContents(const CxCHAR *);
//     int         setContentsRTF(const CxCHAR *);
// 
    CxCHAR        *text() const;
// 
//     //  Actual extents
//     //
//     double      actualHeight(CRxGiWorldDraw *ctxt = NULL) const;
//     double      actualWidth() const;
// 
//     int         correctSpelling();
// 
//     //  Return points marking text box
//     //
     void        getBoundingPoints(CRxGePoint3dArray&) const;
// 
//     //  Explode text fragments
//     //
//     void        explodeFragments(CRxDbMTextEnum, void *, CRxGiWorldDraw *ctxt = NULL) const;
// 
//     //  These strings can be used instead of sprinkling your code 
//     //  with string constants.
//     static const CxCHAR* const nonBreakSpace();   //  \~
//     static const CxCHAR* const overlineOn();  //  \O
//     static const CxCHAR* const overlineOff(); //  \o
//     static const CxCHAR* const underlineOn(); //  \L
//     static const CxCHAR* const underlineOff();    //  \l
//     static const CxCHAR* const colorChange(); //  \C
//     static const CxCHAR* const fontChange();  //  \F
//     static const CxCHAR* const heightChange();    //  \H
//     static const CxCHAR* const widthChange(); //  \W
//     static const CxCHAR* const obliqueChange();   //  \Q
//     static const CxCHAR* const trackChange(); //  \T
//     static const CxCHAR* const lineBreak();   //  \p
//     static const CxCHAR* const paragraphBreak();  //  \P
//     static const CxCHAR* const stackStart();  //  \S
//     static const CxCHAR* const alignChange(); //  \A
//     static const CxCHAR* const blockBegin();  //  {
//     static const CxCHAR* const blockEnd();    //  }
// 
     CDraft::ErrorStatus   setLineSpacingStyle(CRxDb::LineSpacingStyle eStyle);
     CRxDb::LineSpacingStyle lineSpacingStyle() const;
// 
//     // 1.0 = single spaced (default), 2.0 = double-spaced, etc.
     CDraft::ErrorStatus   setLineSpacingFactor(double dFactor);
     double              lineSpacingFactor() const;
//     
//     void                getEcs(CRxGeMatrix3d& retVal) const;
// 
//     virtual CDraft::ErrorStatus getClassID(CLSID* pClsid) const;
 
	 bool backgroundFillOn() const;
	 CDraft::ErrorStatus setBackgroundFill(bool enable);
// 
//     CDraft::ErrorStatus getBackgroundFillColor(CrxCmColor& color) const;
//     CDraft::ErrorStatus setBackgroundFillColor(const CrxCmColor& color);
// 
//     CDraft::ErrorStatus getBackgroundScaleFactor(double& scale) const;
//     CDraft::ErrorStatus setBackgroundScaleFactor(const double scale);
// 
//     CDraft::ErrorStatus getBackgroundTransparency(AcCmTransparency& transp) const;
//     CDraft::ErrorStatus setBackgroundTransparency(const AcCmTransparency& transp);
// 
//     bool useBackgroundColorOn() const;
//     CDraft::ErrorStatus setUseBackgroundColor(bool enable);
//     
//     CDraft::ErrorStatus   setField(const CxCHAR* pszPropName, AcDbField* pField,
//                                  CrxDbObjectId& fieldId);
// 
//     CDraft::ErrorStatus   removeField(CrxDbObjectId fieldId);
//     CDraft::ErrorStatus   removeField(const CxCHAR* pszPropName, CrxDbObjectId& returnId);
//     CDraft::ErrorStatus   removeField(const CxCHAR* pszPropName);
// 
//     CDraft::ErrorStatus   convertFieldToText();
// 
//     enum ColumnType {
//         kNoColumns,
//         kStaticColumns,
//         kDynamicColumns,
//     };
// 
//     CDraft::ErrorStatus setDynamicColumns(double width, double gutter, bool auto_height);
//     CDraft::ErrorStatus setStaticColumns(double width, double gutter, int count);
//     CDraft::ErrorStatus getColumnType(ColumnType&) const;
//     CDraft::ErrorStatus setColumnType(ColumnType);
//     CDraft::ErrorStatus getColumnAutoHeight(bool&) const;
//     CDraft::ErrorStatus setColumnAutoHeight(bool);
//     CDraft::ErrorStatus getColumnCount(int&) const;
//     CDraft::ErrorStatus setColumnCount(int);
//     CDraft::ErrorStatus getColumnWidth(double&) const;
//     CDraft::ErrorStatus setColumnWidth(double);
//     CDraft::ErrorStatus getColumnGutterWidth(double&) const;
//     CDraft::ErrorStatus setColumnGutterWidth(double);
//     CDraft::ErrorStatus getColumnFlowReversed(bool&) const;
//     CDraft::ErrorStatus setColumnFlowReversed(bool);
//     CDraft::ErrorStatus getColumnHeight(int, double&) const;
//     CDraft::ErrorStatus setColumnHeight(int, double);
// 
//     // FOR INTERNAL USE ONLY
//     CDraft::ErrorStatus   setUseWordBreak(bool bEnable);
//     bool useWordBreak() const;
//     // FOR INTERNAL USE ONLY
//     
     // FOR INTERNAL USE ONLY
     //  Entity height (constraining value)
      
     double      height() const;
     CDraft::ErrorStatus   setHeight(double);
	 virtual CDraft::ErrorStatus explodeToOwnerSpace();
	 CDraft::ErrorStatus   setTxtMode(CRxDb::TextHorzMode mHor,
		 CRxDb::TextVertMode mVer);

     // FOR INTERNAL USE ONLY
};

#pragma pack(pop)

#endif
