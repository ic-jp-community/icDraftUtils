//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//
#ifndef __DRAWABLE_H
#define __DRAWABLE_H

#include "rxobject.h"
#include "dbid.h"
#pragma pack (push, 8)

#include "CrxCx.h"

class CRxGiDrawableTraits;
class CRxGiWorldDraw;
class CRxGiViewportDraw;
class CRxGsNode;
class CRxDbSubentId;

CRX_DEFINE_NULL_CLSID(CRxGiDrawable)
class CRXDB_CLASS CRxGiDrawable : public CRxObject
{
public:
    CRX_DECLARE_DYNAMIC(CRxGiDrawable);

	CRxGiDrawable();
	virtual ~CRxGiDrawable();

    // Combine these flags in the return value
    // of setAttributes for efficiency of implementation
    // it is vital that if you use certain aspects of the
    // API that the correct flags be used. Otherwise the
    // display system may be incorrectly configured for
    // subsequent graphics. kIsCompoundObject gives
    // full access to the AcGi API, enabling the use
    // of draw() and the AcGi primitives together. Enabling
    // this makes the elaboration of an object marginally 
    // slower. So you should use the lowest value appropriate.
    //
    //
    enum SetAttributesFlags
    {
        // Default drawable, just uses acgi primitives and does not use 
        // nested calls to draw()
        kDrawableNone                           =  0, 

        // CrxDbEntity derived classes (may require some special processing)
        kDrawableIsAnEntity                     =  1,

        // (block table record) Uses nesting but does not send down additional 
        // primitives. It uses draw() exclusively and makes no calls to the 
        // other AcGi primitives such as circle or shell
        kDrawableUsesNesting                    =  2,

        // You MUST specify this value if you nest entities as a block does.
        kDrawableIsCompoundObject               =  4, 
        
        // Drawable specifies when viewportDraw will be called.  Employ 
        // per-Viewport caching of viewportDraw geometry.  As well, this 
        // drawable does not use worldDraw.
        kDrawableViewIndependentViewportDraw    =  8,

        // If this entity is not visible (CrxDbEntity::visibility())
        kDrawableIsInvisible                    =  16,

        // If a compound object has attributes it must specify this value
        kDrawableHasAttributes                  =  32,

        // If the geometry you elaborate is dependent on the regentype; for 
        // instance, if your drawable draws itself as a set of polygons in a 
        // "shaded" regen-mode but as a set of wires in "standard display", 
        // specify this flag
        kDrawableRegenTypeDependantGeometry     =  64,

        // Dimensions receive  special handling, behaving similarly to blocks
        kDrawableIsDimension = (kDrawableIsAnEntity + kDrawableIsCompoundObject + 128),

        // Always regenerate drawable
        kDrawableRegenDraw                      = 256,

        // Drawable has single level of detail for regen type 
        // kAcGiStandardDisplay 
        kDrawableStandardDisplaySingleLOD       = 512,

        // Drawable has single level of detail for regen type 
        // kAcGiShadedDisplay
        kDrawableShadedDisplaySingleLOD         = 1024,

        // Drawable requires viewportDraw be called on every view change.
        kDrawableViewDependentViewportDraw      =  2048,
      
        // Drawable requires unique viewportDraw elaboration for each block path.
        kDrawableBlockDependentViewportDraw     =  4096
    };


    // These are the Drawable types
    //
    enum DrawableType
    {
        kGeometry              = 0, 
        kDistantLight,
        kPointLight,            
        kSpotLight,
        kAmbientLight,
        kSolidBackground,
        kGradientBackground,
        kImageBackground,
        kGroundPlaneBackground,
        kViewport,
        kWebLight,
        kSkyBackground
    };

    // For default attributes
    virtual CAXA::UInt32   setAttributes   (CRxGiDrawableTraits * traits)   ;

    // For geometry shared between multiple viewports
    virtual CAXA::Boolean  worldDraw       (CRxGiWorldDraw * wd)            ;

    // For viewport-specific geometry
    virtual void            viewportDraw    (CRxGiViewportDraw * vd)         ;

    // Persistent/transient
    virtual CAXA::Boolean  isPersistent    (void) const                    ;
    virtual CRxDbObjectId    id              (void) const                    ;

    // Drawable type. 
    virtual DrawableType    drawableType() const { return kGeometry; }

    // Graphics cache
    virtual void            setGsNode       (CRxGsNode * gsnode)             ;
    virtual CRxGsNode*       gsNode          (void) const                    ;

    // For ViewIndependentViewportDraw caching
    // return bitwise combination of SetAttributesFlags
    // for now, 3D GS only investigates kDrawableRegenTypeDependantGeometry
    virtual CAXA::UInt32   viewportDrawLogicalFlags (CRxGiViewportDraw * vd) { return 0; }
    
    // nMouseFlags are identical to the WM_MOUSEMOVE wParam windows message. See MSDN for those flags, they are provided as is.
    // reset is true if rollover is resetting or leaving your object.
    // return true if you want rollover to track your object, false to ignore it.
    virtual  CAXA::Boolean RolloverHit(CAXA::ULongPtr nSubentId,
                                        CAXA::ULongPtr nMouseFlags,
                                        CAXA::Boolean bReset ) {
                        return CAXA::kFalse; }

   
};

#pragma pack (pop)
#endif // __DRAWABLE_H
