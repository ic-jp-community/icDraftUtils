//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#ifndef __ACGSMANAGER_H__
#define __ACGSMANAGER_H__
#pragma pack (push, 8)

#include "crxgi.h"

class CRxDbViewportTableRecord;
class CRxGiDrawable;
class CRxGsClassFactory;
class CRxGsView;
class CRxGsModel;
class CRxGsDevice;

// ****************************************************************************
// AcGsManager
CRX_DEFINE_NULL_CLSID(CRxGsManager)

class CRXGI_CLASS CRxGsManager
{
public:
	CRX_DECLARE_DYNAMIC(CRxGsManager);

                                CRxGsManager             (void) { }
    virtual                    ~CRxGsManager             (void) { }

    virtual CRxGsModel *         createAutoCADModel      (void)                          = 0;
    virtual CRxGsView *          createAutoCADViewport   (CRxDbViewportTableRecord * vp)  = 0;    // creates a view of {vp, DBmodel}
    virtual CRxGsView *          createAutoCADView       (CRxGiDrawable * drawable)       = 0;    // creates a view with {Drawable, DBModel} 
                                                                                                // pair selected for viewing, connected to
                                                                                                // AutoCAD's GUI Device
    virtual CRxGsDevice *        createAutoCADDevice     (HWND hWnd)                     = 0;
    virtual CRxGsDevice *        createAutoCADOffScreenDevice()                          = 0;

    virtual void                destroyAutoCADModel     (CRxGsModel  * model)            = 0;
    virtual void                destroyAutoCADView      (CRxGsView   * view)             = 0;
    virtual void                destroyAutoCADDevice    (CRxGsDevice * device)           = 0;
    
    virtual CRxGsClassFactory *  getGSClassFactory       (void)                          = 0;
    virtual CRxGsModel        *  getDBModel              (void)                          = 0;
    virtual CRxGsDevice       *  getGUIDevice            (void)                          = 0;
};


#pragma pack (pop)
#endif // __ACGSMANAGER_H__
