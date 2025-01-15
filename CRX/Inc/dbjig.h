#ifndef   _DBJIG_H_
#define   _DBJIG_H_ 1
//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//  
// DESCRIPTION:
//      Definition of class AcEdJig, an object onto which you clamp an
//      CrxDbEntity while bending it into shape.  Comes with slots for a
//      few standard dragging attachments and a built-in tool or two.
//  

#if defined(__cplusplus)
#ifndef _AD_CRXDB_H
// #include "crxDb.h"
#endif

// #include "dbdimdata.h"  // for dynamic dimensions
#include "RxObject.h"
#include "dbmain.h"
#include "cdraft.h"
#include "gepnt3d.h"
#include "CrxEdApiCx.h"
#pragma pack (push, 8)

class CCrxEdJigService;

CRX_DEFINE_NULL_CLSID(CRxEdJig)
class CRXEDAPI_CLASS CRxEdJig: public CRxObject
{
public:
  	CRX_DECLARE_DYNAMIC(CRxEdJig)

    typedef enum UserInputControls {
	kGovernedByOrthoMode	    = 0x0001,
	kNullResponseAccepted		= 0x0002,
	kDontEchoCancelForCtrlC		= 0x0004,
	kDontUpdateLastPoint		= 0x0008,
	kNoDwgLimitsChecking		= 0x0010,
	kNoZeroResponseAccepted		= 0x0020,
	kNoNegativeResponseAccepted	= 0x0040,
	kAccept3dCoordinates		= 0x0080,
	kAcceptMouseUpAsPoint		= 0x0100,
	kAnyBlankTerminatesInput	= 0x0200,
	kInitialBlankTerminatesInput	= 0x0400,
	kAcceptOtherInputString		= 0x0800,
    kGovernedByUCSDetect        = 0x1000,
    kNoZDirectionOrtho          = 0x2000
    };

    typedef enum DragStatus {
        kModeless       = -17,
        kNoChange       = -6,
        kCancel         = -4,
        kOther          = -3,
        kNull           = -1,
        kNormal         = 0,
	kKW1,
	kKW2,
	kKW3,
	kKW4,
	kKW5,
	kKW6,
	kKW7,
	kKW8,
	kKW9
    };

    typedef enum CursorType {
	kNoSpecialCursor = -1,           // No Special Cursor Specified
	kCrosshair = 0,                  // Full Screen Cross Hair. 
	kRectCursor,                     // Rectangular cursor. 
	kRubberBand,                     // Rubber band line. 
	kNotRotated,                     // NotRotated Type. 
	kTargetBox,                      // Target Box Type. 
	kRotatedCrosshair,               // Rotated Crosshair w/ rubber band. 
	kCrosshairNoRotate,              // Crosshairs forced non-rotated. 
	kInvisible,                      // Invisible cursor. 
	kEntitySelect,                   // Entity selection target cursor. 
	kParallelogram,                  // Parallelogram cursor. 
	kEntitySelectNoPersp,            // Pickbox, suppressed in persp. 
	kPkfirstOrGrips,                 // Auto-select cursor. 
    kCrosshairDashed                 // 15 dashed style crosshair cursor

    };
	CRxEdJig();
    virtual ~CRxEdJig();

    DragStatus	drag();
    virtual DragStatus	sampler(); 
    virtual CAXA::Boolean  update();
 	CRxDbObjectId append();

	const CxCHAR* keywordList();
	void        setKeywordList(const CxCHAR*);
 
	 const CxCHAR* dispPrompt();
	 void        setDispPrompt(const CxCHAR*, ...);

    DragStatus acquireString(CxCHAR *str);
    DragStatus acquireAngle(double &ang);
    DragStatus acquireAngle(double &ang, const CRxGePoint3d& basePnt);
    DragStatus acquireDist(double &dist);
    DragStatus acquireDist(double &dist, const CRxGePoint3d& basePnt);
    DragStatus acquirePoint(CRxGePoint3d& pnt);
    DragStatus acquirePoint(CRxGePoint3d& pnt, const CRxGePoint3d& basePnt);

	CRxEdJig::CursorType specialCursorType();
	void                setSpecialCursorType(CursorType);

	CRxEdJig::UserInputControls userInputControls();
	void                       setUserInputControls(CRxEdJig::UserInputControls);

    virtual CRxDbEntity* entity() const;
// 	virtual AcDbDimDataPtrArray * dimData(const double dimScale);
// 	virtual CDraft::ErrorStatus setDimValue(const AcDbDimData* dimData,
// 											  const double dimValue); 

private:
    CCrxEdJigService*  mpImpJig;
};

#pragma pack (pop)
#endif // cplusplus
#endif
