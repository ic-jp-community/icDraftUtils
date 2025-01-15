//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//

#ifndef _ACGS_H
#define _ACGS_H

#include "cdraft.h"
#include "stdlib.h"
#include "crxGsManager.h"
#include "Crxdb.h"

#pragma pack (push, 8)

CAXA::Boolean crxgsGetDisplayInfo           (int & drawingWidth,    
                                             int & drawingHeight,     
                                             int & aspectWidth,
                                             int & aspectHeight);

CAXA::Boolean acgsGetViewportInfo          (int   viewportNumber,
                                             int & left,    
                                             int & bottom,
                                             int & right,    
                                             int & top);    


// This class is returned to the user by acgsGetScreenShot, below.
class CRxGsScreenShot {      // pure virtual, abstract
    public:
    virtual CAXA::Boolean getSize          (int & width,             
                                             int & height,
                                             int & depth) const = 0; 

    virtual CAXA::Boolean getColorMap      (int             index,
                                             CAXA::UInt8 & red,
                                             CAXA::UInt8 & green,
                                             CAXA::UInt8 & blue) const = 0;

    virtual void const * getScanline        (int offsetFromLeft,
                                             int offsetFromTop) const = 0;

#ifdef new
#define DISABLING_LEAK_CHECK
#undef new
#endif
    void * operator new (size_t size); // static

    // Be sure to delete your screen shot when you are through with it.
    void operator delete (void * p);   // static

#ifndef PRODUCTION
        void * operator new (size_t size, const char *, int) { return operator new(size); }
#if _MSC_VER >= 1200
        // vc6 requires matching delete for each new
        void operator delete (void * p, const char *, int) { delete p; }
#endif // vc6
#endif // PRODUCTION

#ifdef DISABLING_LEAK_CHECK
#define new DEBUG_NEW
#undef DISABLING_LEAK_CHECK
#endif

    CRxGsScreenShot();
    virtual ~CRxGsScreenShot () = 0;
};

// Compatibility definition
//
#define ScreenShot CRxGsScreenShot

CRxGsScreenShot * crxgsGetScreenShot          (int          viewportNumber);

void crxgsSetViewportRenderFlag              (int          viewportNumber);

CAXA::Boolean crxgsDisplayImage             (int          viewportNumber,
                                             long         originLeft,    
                                             long         originTop,    
                                             int          imageWidth,    
                                             int          imageHeight,    
                                             void const * imageData,        
                                             int          hasTransparency);

CAXA::Boolean crxgsRemoveAnonymousGraphics  (int viewportNumber);


typedef void (*crxgsCustomUpdateMethod)      (void * pParm, int left, int right, int bottom, int top);
CAXA::Boolean crxgsSetCustomUpdateMethod    (crxgsCustomUpdateMethod custom_update_method, void * pParm);

void crxgsRedrawShortTermGraphics            (short minx, short miny, short maxx, short maxy);


struct CRxGs
{
    enum LinePattern      { eSolid                         = 0,
                            eDashed                        = 1,
                            eDotted                        = 2,
                            eDashDot                       = 3,
                            eShortDash                     = 4,
                            eMediumDash                    = 5,
                            eLongDash                      = 6,
                            eDoubleShortDash               = 7,
                            eDoubleMediumDash              = 8,
                            eDoubleLongDash                = 9,
                            eMediumLongDash                = 10,
                            eMediumDashShortDashShortDash  = 11,
                            eLongDashShortDash             = 12,
                            eLongDashDotDot                = 13,
                            eLongDashDot                   = 14,
                            eMediumDashDotShortDashDot     = 15,
                            eSparseDot                     = 16,
                            eDefaultLinePattern            = eDotted };
};

void              crxgsSetHighlightColor       (CAXA::UInt16 colorIndex);
CAXA::UInt16     crxgsGetHighlightColor       (void);
void              crxgsSetHighlightLinePattern (CRxGs::LinePattern pattern);
CRxGs::LinePattern crxgsGetHighlightLinePattern (void);
void              crxgsSetHighlightLineWeight  (CAXA::UInt16 weight);
CAXA::UInt16     crxgsGetHighlightLineWeight  (void);

class CRxGsView;
class CRxGsManager;

CAXA::Boolean  crxgsSetViewParameters         (int viewportNumber, const CRxGsView * pView,
	bool bRegenRequired, bool bRescaleRequired,
	bool bSyncRequired = false);
CAXA::Boolean  crxgsGetViewParameters         (int viewportNumber, CRxGsView * pView);
CAXA::Boolean  crxgsSetLensLength             (int viewportNumber, const double & lensLength);
CAXA::Boolean  crxgsGetLensLength             (int viewportNumber, double & lensLength);
void            crxgsWriteViewToUndoController (int viewportNumber);
CAXA::Boolean  crxgsSetView2D                 (int viewportNumber);


class CView;

CRxGsView *      crxgsGetGsView               (int viewportNumber, bool bCreateIfNone);

// Pass in NULL to get the AcGsManager associated with the current MDI Client Window;
// otherwise, be sure that the passed in view is really an AutoCAD MDI Client window.
CRXGI_API CRxGsManager *  crxgsGetGsManager            (CView * pView = NULL); 

class CRxGeVector3d;
CAXA::Boolean crxgsGetOrthoViewParameters  (int viewportNumber, 
                                             CRxDb::OrthographicView view,
                                             CRxGeVector3d * pViewDir,
                                             CRxGeVector3d * pUpVector);

// Use acgsCreate2DViewLimitManager and acgsDestroy2DViewLimitManager to
// create and destroy instances of this pure virtual, abstract class
class CRxGs2DViewLimitManager 
{      
public:
    virtual                ~CRxGs2DViewLimitManager  (void) { }
    virtual bool            testView                (CRxGePoint3d const & target,
                                                     double              dFieldHeight)  = 0;
};

CRxGs2DViewLimitManager *    crxgsCreate2DViewLimitManager  (int viewportNumber);
void                        crxgsDestroy2DViewLimitManager (CRxGs2DViewLimitManager * pLimitManager);

#pragma pack (pop)
#endif // _ACGS_H
