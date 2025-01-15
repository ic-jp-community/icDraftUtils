#ifndef _CRXGI_H
#define _CRXGI_H 1
//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//
//
// This is the Graphics Interface for view independent and dependent
// elaboration of CRxDb Entities.
//
// The Eb Graphics Interface (CRxGi) is a set of objects comprising 
// an API for elaborating the graphics representation of new Eb
// entitites.  These objects support many geometric primitives, 
// transformation matrix querying, and graphical attributes. 

// Required for RX
//
#define CRxGI_SERVICES  CRX_T(/*MSG0*/"AcGiServices")

// These are the current kinds of viewport regeneration modes.
// This mode is not settable by the user, but it can be queried 
// in case you need to take different actions for different
// regeneration modes.
//
typedef enum {
    eAcGiRegenTypeInvalid = 0,
    kAcGiStandardDisplay = 2,
    kAcGiHideOrShadeCommand,
    kAcGiRenderCommand, // deprecated
    kAcGiShadedDisplay = kAcGiRenderCommand,
    kAcGiForExplode,
    kAcGiSaveWorldDrawForProxy
} CRxGiRegenType;

// No longer supported and will be removed
//
#define kAcGiSaveWorldDrawForR12 kAcGiForExplode 

// These are the current face filling modes
//
typedef enum {
     kAcGiFillAlways = 1,
     kAcGiFillNever
} CRxGiFillType;

// These are the edge visibility types
//
typedef enum {
    kAcGiInvisible = 0,
    kAcGiVisible,
    kAcGiSilhouette
} CRxGiVisibility;

// These are the types of arcs
//
typedef enum {
    kAcGiArcSimple = 0,                 // just the arc (not fillable)
    kAcGiArcSector,                     // area bounded by the arc and its center of curvature
    kAcGiArcChord                       // area bounded by the arc and its end points
} CRxGiArcType;

// These are the possible types of vertex orientation 
// 
typedef enum {
    kAcGiCounterClockwise = -1,
    kAcGiNoOrientation = 0,
    kAcGiClockwise = 1
} CRxGiOrientationType;

// This signifies how to calculate maximum deviation for tesselation
//
typedef enum {
    kAcGiMaxDevForCircle = 0,
    kAcGiMaxDevForCurve,
    kAcGiMaxDevForBoundary,
    kAcGiMaxDevForIsoline,
    kAcGiMaxDevForFacet
} CRxGiDeviationType;

// Raster image organization
//
typedef enum {
    kAcGiBitonal,
    kAcGiPalette,
    kAcGiGray,
    kAcGiRGBA,
    kAcGiBGRA,
    kAcGiARGB,
    kAcGiABGR,
    kAcGiBGR,
    kAcGiRGB                              
} CRxGiImageOrg;

// Raster image orientation
//
typedef enum {
    kAcGiXLeftToRightTopFirst,
    kAcGiXLeftToRightBottomFirst,
    kAcGiXRightToLeftTopFirst,
    kAcGiXRightToLeftBottomFirst,
    kAcGiYTopToBottomLeftFirst,
    kAcGiYTopToBottomRightFirst,
    kAcGiYBottomToTopLeftFirst,
    kAcGiYBottomToTopRightFirst
} CRxGiImageOrient;

// scale filter method to use
typedef enum {
    kDefaultScaleFilter,
    kNearestScaleFilter,
    kBellScaleFilter,
    kMitchellScaleFilter,
    kTriangleScaleFilter,
    kCubicScaleFilter,
    kBsplineScaleFilter,
    kLanczos3ScaleFilter
} CRxGiScaleFilterType;

// rotation filter method to use
typedef enum {
    kDefaultRotationFilter,
    kInterpolatedRotationFilter,
    kNearestRotationFilter,
} CRxGiRotationFilterType;

// how to interpret nRasterRatio
typedef enum {
    kDefaultScale,                  // classic scaling scheme
    kRelativeScale,                 // relative to original image, do rotation
    kUnTransformedScale             // original pixels, unscaled, unrotated
} CRxGiScaleType;

// symbol type for CRxGiGeometry::symbol(..)
typedef enum {
    kAcGiGrip,
} CRxGiSymbolType;

enum CRxGiEdgeStyleMaskValues {
    kAcGiNoEdgeStyleMask = 0,
    kAcGiJitterMask      = 1,
    kAcGiOverhangMask    = 2,
    kAcGiEdgeColorMask   = 4
};
typedef unsigned int CRxGiEdgeStyleMask;

#include "rxobject.h"
#include "crxChar.h"
#include "dbpl.h"
#include "gemat3d.h"
#include "gemat2d.h"
#include "gepnt2d.h"
#include "dbcolor.h"
#include "crxDb.h"
#include "CRxGiStyleAttributes.h"
#include "assert.h"
#include "drawable.h"

#pragma pack (push, 8)

struct CRxGiSentScanLines 
{
    enum IsmRequestStatus {
        eOk,                           // No Failure.
        eInvalidInput,                 // unknown image organization
        eInvalidColorDepth,            // mColorDepth to big or too small for request
        eInvalidPixelRequest,          // IefAffine (matrix scaling) failed for some reason
        eInvalidDeliveryMethod,        // Frame buffer delivery + compression - not valid
        eNoValidCompressors,           // no compressors for image data
        eInsufficientMemory            // low memory conditions.. very bad 
    };

    CAXA::Int8 *    mpPixelBuffer;          // one pointer per scan line
    CAXA::UInt32    mRowBytes;              // number of bytes per scan line
    void *           mpImageId;              // image id ptr
    CAXA::Int16     mIsCancelled;           // boolean: user cancelled
    CAXA::Int16     mHasFailed;             // boolean: request failed
    CAXA::UInt32    mBytes;
    IsmRequestStatus mRequestStatus;

};

struct CRxGiRequestScanLines 
{
    enum IEDitherMethod 
    {
        kIEAnyPalette,
        kCustomDithering,
        kCustomDitheringMethod
    };

    enum IEColorSystem
    {
        kBitonal,
        kCMY,
        kCMYK,
        kRGB
    };

    enum ImagePaletteType
    {
        kFromDevice,
        kFromIeWholeImage
    };

    CRxGiRequestScanLines()
        : mPixelMinX          (0)
        , mPixelMinY          (0)
        , mPixelMaxX          (0)
        , mPixelMaxY          (0)
        , mpImageId           (0)
        , mImageOrg           (kAcGiBitonal)
        , mImageOrient        (kAcGiXLeftToRightTopFirst)
        , mWindowId           (0)
        , mColorDepth         (8)
        , mPaletteIncarnation (0)
        , mpPalette           (0)
        , mIsDisplay          (0)
        , mRasterRatio        (1.0)
        , mPaletteType        (kFromDevice)
        , mpDataBuffer        (0)
        , mRowWidth           (0)
        , mpBoundaryPoints    (0)
        , mnContours          (0)
        , mpCounts            (0)
        , mScalingType        (kDefaultScale)
        , mScaleFilterType    (kDefaultScaleFilter)
        , mRotationFilterType (kDefaultRotationFilter)
        , mnTotalChunks       (0)
        , mnThisChunk         (0)
    {
    }

    CAXA::UInt32       mPixelMinX;             // requested pixel corners
    CAXA::UInt32       mPixelMinY;
    CAXA::UInt32       mPixelMaxX;
    CAXA::UInt32       mPixelMaxY;
    CRxGePoint2d         mLowerLeft;             // requested lower left corner
    CRxGePoint2d         mUpperRight;            // requested upper right corner
    void *              mpImageId;              // image handle
    CRxGiImageOrg        mImageOrg;              // enum type: palette, RGB 
    CRxGiImageOrient     mImageOrient;           // enum type
    CAXA::Int16        mWindowId;              // acad window id
    CAXA::Int16        mColorDepth;            // bits per pixel
    union {
        CAXA::Int16 mBackgroundIndex;
        CAXA::Int8 mBackgroundRGB[3];
    }                   mBackgroundColor;       // current background color
    union {
        CAXA::Int16 mTransparentIndex;
        CAXA::Int8 mTransparentRGB[3];
    } mTransparentColor;                        // current background color
    union {
        CAXA::Int16 mEntityIndex;
        CAXA::Int8 mEntityRGB[3];
    }                   mEntityColor;           // bitonal image foregrnd color
    CAXA::Int32        mPaletteIncarnation;    // unique palette indentifier
    CAXA::Int8 *       mpPalette;              // pointer to 256 RGB triples
    CAXA::Int16        mIsDisplay;             // boolean: TRUE=dsply, FALSE=hrdcpy
    double              mRasterRatio;           // raster resolution
    CRxGeMatrix2d        mPixelToDc;             // source pixel-to-dc transform
    ImagePaletteType    mPaletteType;
    void *              mpDataBuffer;
    CAXA::Int32        mRowWidth;
    CAXA::Int32        mNumRows;
    CAXA::Int32 const *mpBoundaryPoints;        // array of x,y pairs
    CAXA::UInt32       mnContours;              // number of contours 
    CAXA::Int32 const *mpCounts;                // pt count for each contour
    CRxGiScaleType          mScalingType;
    CRxGiScaleFilterType    mScaleFilterType;
    CRxGiRotationFilterType mRotationFilterType;
    short                  mnTotalChunks;       // how many chunks will be requested
    short                  mnThisChunk;         // 1 based count of chunks
};

struct CRxGiClipBoundary
{
    CRxGeVector3d        m_vNormal;
    CRxGePoint3d         m_ptPoint;
    CRxGePoint2dArray    m_aptPoints;    

    CRxGeMatrix3d        m_xToClipSpace;// Transformation from model to clip space
    CRxGeMatrix3d        m_xInverseBlockRefXForm; // Xform from block space to world

    CAXA::Boolean      m_bClippingFront;
    CAXA::Boolean      m_bClippingBack;
    double              m_dFrontClipZ;
    double              m_dBackClipZ;

    CAXA::Boolean      m_bDrawBoundary;
};

class OwnerDraw3d
{
public:
    virtual ~OwnerDraw3d(void) {};
};

// To be removed
typedef enum CRxGiColorIntensity 
{
    kAcGiMinColorIntensity = 0x0,
    kAcGiColorIntensity1   = 0x1,
    kAcGiColorIntensity2   = 0x2,
    kAcGiColorIntensity3   = 0x3,
    kAcGiColorIntensity4   = 0x4,
    kAcGiColorIntensity5   = 0x5,
    kAcGiColorIntensity6   = 0x6,
    kAcGiMaxColorIntensity = 0x7 
};

class CRxGiColorRGB
{
public:
    CRxGiColorRGB (void) 
        : red   (0.0)
        , green (0.0)
        , blue  (0.0)
    { }

    CRxGiColorRGB (double r, double g, double b) 
        : red   (r)
        , green (g)
        , blue  (b)
    { }

    double red;
    double green;
    double blue;
};


inline CRxGiColorRGB operator* (const CRxGiColorRGB& c1, const CRxGiColorRGB& c2)
{
    return CRxGiColorRGB(c1.red   * c2.red, 
                        c1.green * c2.green, 
                        c1.blue  * c2.blue);
}

inline CRxGiColorRGB operator* (const CRxGiColorRGB& c, double s)
{
    return CRxGiColorRGB(s * c.red, 
                        s * c.green, 
                        s * c.blue);
}

inline CRxGiColorRGB operator* (double s, const CRxGiColorRGB& c)
{
    return c * s;
}

inline CRxGiColorRGB operator+ (const CRxGiColorRGB& c1, const CRxGiColorRGB& c2)
{
    return CRxGiColorRGB(c1.red   + c2.red, 
                        c1.green + c2.green, 
                        c1.blue  + c2.blue);
}


class CRxGiColorRGBA
{
public:
    CRxGiColorRGBA (void)
        : red   (0.0)
        , green (0.0)
        , blue  (0.0)
        , alpha (1.0)
    { }

    CRxGiColorRGBA (double r, double g, double b, double a) 
        : red   (r)
        , green (g)
        , blue  (b)
        , alpha (a)
    { }

    double red;
    double green;
    double blue;
    double alpha;
};

inline CRxGiColorRGBA operator* (const CRxGiColorRGBA& c1, const CRxGiColorRGBA& c2)
{
    return CRxGiColorRGBA(c1.red   * c2.red, 
                         c1.green * c2.green, 
                         c1.blue  * c2.blue, 
                         c1.alpha * c2.alpha);
}

inline CRxGiColorRGBA operator*(const CRxGiColorRGBA& c, double s)
{
    return CRxGiColorRGBA(s * c.red, 
                         s * c.green, 
                         s * c.blue, 
                         s * c.alpha);
}

inline CRxGiColorRGBA operator* (double s, const CRxGiColorRGBA& c)
{
    return c * s;
}

inline CRxGiColorRGBA operator+ (const CRxGiColorRGBA& c1, const CRxGiColorRGBA& c2)
{
    return CRxGiColorRGBA(c1.red   + c2.red, 
                         c1.green + c2.green, 
                         c1.blue  + c2.blue, 
                         c1.alpha + c2.alpha);
}

class CRxGiPixelBGRA32
{
public:
    CRxGiPixelBGRA32 ()
    {
        m_bgra.b = 0;
        m_bgra.g = 0;
        m_bgra.r = 0;
        m_bgra.a = 255;
    }

    CRxGiPixelBGRA32(CAXA::UInt32 bgra)
        : m_whole (bgra)
    { }

    CRxGiPixelBGRA32 (CAXA::UInt8 blue,
                     CAXA::UInt8 green,
                     CAXA::UInt8 red,
                     CAXA::UInt8 alpha)
    {
        m_bgra.b = blue;
        m_bgra.g = green;
        m_bgra.r = red;
        m_bgra.a = alpha;
    }

    CAXA::UInt32     getBGRA   () const;
    CAXA::UInt32     getRGBA   () const;
    CAXA::UInt8      blue      () const;
    CAXA::UInt8      green     () const;
    CAXA::UInt8      red       () const;
    CAXA::UInt8      alpha     () const;

    void setBGRA    (CAXA::UInt32 bgra);
    void setBGRA    (CAXA::UInt8 blue, 
                     CAXA::UInt8 green, 
                     CAXA::UInt8 red,
                     CAXA::UInt8 alpha);
    void setRGBA    (CAXA::UInt32 rgba);
    void setRGBA    (CAXA::UInt8 red, 
                     CAXA::UInt8 green, 
                     CAXA::UInt8 blue,
                     CAXA::UInt8 alpha);
    void setBlue    (CAXA::UInt8 blue);
    void setGreen   (CAXA::UInt8 green);
    void setRed     (CAXA::UInt8 red);
    void setAlpha   (CAXA::UInt8 alpha);

private:
    union {
        CAXA::UInt32 m_whole;
        struct PIXEL{
            CAXA::UInt8  b, g, r, a;
        }m_bgra;
    };
};

inline CAXA::UInt32 CRxGiPixelBGRA32::getBGRA() const
{
    return m_whole;
}

inline CAXA::UInt32 CRxGiPixelBGRA32::getRGBA() const
{
    return (CAXA::UInt32)(m_bgra.a)<<24 
           | (CAXA::UInt32)(m_bgra.b)<<16
           | (CAXA::UInt32)(m_bgra.g)<<8 
           | (CAXA::UInt32)(m_bgra.r);
}

inline CAXA::UInt8 CRxGiPixelBGRA32::blue() const
{
    return m_bgra.b;
}

inline CAXA::UInt8 CRxGiPixelBGRA32::green() const
{
    return m_bgra.g;
}

inline CAXA::UInt8 CRxGiPixelBGRA32::red() const
{
    return m_bgra.r;
}

inline CAXA::UInt8 CRxGiPixelBGRA32::alpha() const
{
    return m_bgra.a;
}

inline void CRxGiPixelBGRA32::setBGRA(CAXA::UInt32 bgra)
{
    m_whole = bgra;
}

inline void CRxGiPixelBGRA32::setBGRA(CAXA::UInt8 blue, 
                                     CAXA::UInt8 green, 
                                     CAXA::UInt8 red,
                                     CAXA::UInt8 alpha)
{
    m_bgra.b = blue;
    m_bgra.g = green;
    m_bgra.r = red;
    m_bgra.a = alpha;
}

inline void CRxGiPixelBGRA32::setRGBA(CAXA::UInt32 rgba)
{
    m_bgra.r = (CAXA::UInt8)(rgba & 0x000000FF);
    m_bgra.g = (CAXA::UInt8)((rgba & 0x0000FF00) >> 8);
    m_bgra.b = (CAXA::UInt8)((rgba & 0x00FF0000) >> 16);
    m_bgra.a = (CAXA::UInt8)((rgba & 0xFF000000) >> 24);
}

inline void CRxGiPixelBGRA32::setRGBA(CAXA::UInt8 red, 
                                     CAXA::UInt8 green, 
                                     CAXA::UInt8 blue,
                                     CAXA::UInt8 alpha)
{
    m_bgra.r = red;
    m_bgra.g = green;
    m_bgra.b = blue;
    m_bgra.a = alpha;
}

inline void CRxGiPixelBGRA32::setBlue(CAXA::UInt8 blue)
{
    m_bgra.b = blue;
}

inline void CRxGiPixelBGRA32::setGreen(CAXA::UInt8 green)
{
    m_bgra.g = green;
}

inline void CRxGiPixelBGRA32::setRed(CAXA::UInt8 red)
{
    m_bgra.r = red;
}

inline void CRxGiPixelBGRA32::setAlpha(CAXA::UInt8 alpha)
{
    m_bgra.a = alpha;
}

class CRxGiImageBGRA32
{
public:
    CRxGiImageBGRA32 ()
        : m_nImageWidth  (0)
        , m_nImageHeight (0)
        , m_pImageData   (NULL)
    { }

    CRxGiImageBGRA32 (CAXA::UInt32 imageWidth, 
                     CAXA::UInt32 imageHeight, 
                     CRxGiPixelBGRA32* imageData)
        : m_nImageWidth  (imageWidth)
        , m_nImageHeight (imageHeight)
        , m_pImageData   (imageData)
    { }

    CRxGiPixelBGRA32* image  () const;
    CAXA::UInt32    width  () const;
    CAXA::UInt32    height () const;

    void setImage   (CAXA::UInt32 imageWidth, 
                    CAXA::UInt32 imageHeight, 
                    CRxGiPixelBGRA32* imageData);

private:
    CRxGiPixelBGRA32* m_pImageData;
    CAXA::UInt32 m_nImageWidth;
    CAXA::UInt32 m_nImageHeight;
};

inline CRxGiPixelBGRA32* CRxGiImageBGRA32::image() const
{
    return m_pImageData;
}

inline CAXA::UInt32 CRxGiImageBGRA32::width() const
{
    return m_nImageWidth;
}

inline CAXA::UInt32 CRxGiImageBGRA32::height() const
{
    return m_nImageHeight;
}

inline void CRxGiImageBGRA32::setImage   (CAXA::UInt32 imageWidth, 
                                         CAXA::UInt32 imageHeight, 
                                         CRxGiPixelBGRA32* imageData)
{
    m_nImageWidth   = imageWidth;
    m_nImageHeight  = imageHeight;
    m_pImageData    = imageData;
}

class CRxGiSubEntityTraits;
class CRxGiDrawableTraits;
class CRxGiSubEntityTraitsImp;
class CRxGiWorldGeometry;
class CRxGiViewport;
class CRxGiViewportGeometry;
class CRxGiImpEdgeData;
class CRxGiImpFaceData;
class CRxGiImpVertexData;
class CRxGiImpTextStyle;
class CRxGiTextStyle;
class CRxGiEdgeData;
class CRxGiFaceData;
class CRxGiVertexData;
class OwnerDraw;
class CRxGiImpVariant;
class CRxGiVariant;
class CRxGiContextImp;
class CRxGiContext;
class CRxGiCommonDraw;
class CRxGiGeometry;
class CRxCmEntityColor;
struct TextParams;
struct FontInfo;
class CRxGiMapper;
class CRxGiViewportTraits;
class CRxGiVisualStyleTraits;
class CRxGiEdgeStyle;
class CRxGiContextualColors;

typedef void (*CRxGiWorldSegmentCallback)(const CRxGePoint3d *);

bool crxgiIsValidClipBoundary(const CRxGePoint2dArray& pts);

CDraft::ErrorStatus crxgiGetRegenBlockRefStack(CRxDbObjectIdArray& blkRefs);

//class CRxGiVariant : public CRxObject
////
//// Class for handling variant data
////
//{
//public:
//    ACRX_DECLARE_MEMBERS(CRxGiVariant);
//
//    CRxGiVariant(void);
//    virtual ~CRxGiVariant(void);
//
//    CRxGiVariant             (const CRxGiVariant & value);
//    CRxGiVariant & operator= (const CRxGiVariant & value);
//    virtual bool  operator==(const CRxGiVariant & value) const;
//        // note that a variant copy is a deep copy. If describing a hierarchical
//        // data structure, the entire structure is duplicated
//
//    // CRxObject protocol
//    virtual CDraft::ErrorStatus copyFrom(const CRxObject* other);
//
//
//    enum VariantType
//    {
//        kUndefined = 0,
//        kBoolean,
//        kInt,
//        kDouble,
//        kColor,
//        kString,
//        kTable,
//    };
//
//    CRxGiVariant(bool);
//    CRxGiVariant(long);
//    CRxGiVariant(double);
//    CRxGiVariant(const AcCmColor&); 
//    CRxGiVariant(const CxCHAR *); 
//
//    VariantType type() const;
//
//    void                set(bool);
//    void                set(long);
//    void                set(double);
//    void                set(const AcCmColor&); 
//    void                set(const CxCHAR *); 
//
//    bool                asBoolean() const;
//    int                 asInt() const;
//    double              asDouble() const;
//    AcCmColor           asColor() const;
//    CRxString            asString() const;
//
//    // table access..
//    CDraft::ErrorStatus   getElem(CxCHAR *const, CRxGiVariant & value) const;
//    const CRxGiVariant*  getElem(CxCHAR *const) const;
//    void                setElem(CxCHAR *const, const CRxGiVariant&);
//    void                deleteElem(CxCHAR *const);
//
//    int                 getElemCount() const;
//    CDraft::ErrorStatus   getElemAt(const int, CxCHAR*&, CRxGiVariant &) const; // caller is responsible for deleting returned CxCHAR*
//    CRxGiVariant*        getElemAt(const int, CxCHAR*&) const;                // caller is responsible for deleting returned CxCHAR*
//
//    static bool         isEquivalent(CRxGiVariant*, CRxGiVariant*);
//
//private:
//    CRxGiImpVariant * mpCRxGiImpVariant;
//};


//
// The base class for drawing contexts
//
CRX_DEFINE_NULL_CLSID(CRxGiContext)
class CRXGI_CLASS CRxGiContext : public CRxObject
{
public:
    CRX_DECLARE_DYNAMIC(CRxGiContext);

    virtual CAXA::Boolean          isPsOut() const = 0;
    virtual CAXA::Boolean          isPlotGeneration() const = 0;
    virtual CRxDbDatabase *          database() const = 0;
    virtual bool					isBoundaryClipping() const = 0;

    // If your object requires to be redrawn for translation
    // transforms (MOVE) you can force the system to rerequest 
    // graphics for all objects in the current drag, including
    // yourself. Use this option only if you really need to. 
    // E.g. If your object needs to update for each step in a 
    // MOVE drag
    // 
    virtual void          disableFastMoveDrag() const{};

    // Returns false if this is root level entity, e.g. a line in modelspace
    // and true if the object is contained within another object like a
    // block for example.
    //
    virtual bool isNesting() const { return false; }

    virtual CRxCmEntityColor   effectiveColor() const { return CRxCmEntityColor(); }
    virtual CRxDb::LineWeight  byBlockLineWeight() const { return CRxDb::kLnWt000; }
    virtual CRxDbObjectId      byBlockPlotStyleNameId() const { return NULL; }
    virtual CRxDbObjectId      byBlockMaterialId() const { return CRxDbObjectId::kNull; }

    virtual bool supportsTrueTypeText() { return false; }
    virtual bool supportsOwnerDraw()	{ return false; }
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    // These APIs is provided for internal use only, do not use them
    // in external applications
    //
    virtual CRxGiContextImp * getImpPtr() { return NULL; }
    virtual const CRxGiContextImp * getConstImpPtr() const { return NULL; }
    //
    // End of Internal use only API
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////

protected:

    friend class CRxGiTextHook;
    friend class CShFont;
    friend class CRxDbImpText;

    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
    // These APIs is provided for internal use only, do not use them
    // in external applications
    //
    virtual CRxGiWorldSegmentCallback wSegTaker() const { return NULL; }
    virtual int getTrueTypeBoundingBox(CRxGePoint3d const & location,
                                       const wchar_t * text, 
                                       int length, TextParams const * tp, 
                                       CRxGePoint3d * bbox, float * char_widths)
                                        { return 0; }
    
    virtual int getTrueTypeTextExtents(CxCHAR const *,unsigned int,double,
                                       int,int,
                                       int,short,short,double,double,
                                       CRxGePoint2d &,CRxGePoint2d &) 
                                       { return -1; }

    virtual int setTrueTypeTransform(const CRxGePoint3d &,const CRxGeVector3d &,
                                     double,double,double,bool,bool) 
                                     { return 0; }

    virtual int drawTrueTypeText(const CxCHAR *,double,int,bool,
                                 const TextParams &,unsigned int){ return 0; }
    virtual int restoreTrueTypeTransform() { return 0; }
    virtual void bypassHiddenLineRemoval() { return; }
    virtual int setTextStyle(int);
    virtual CAXA::LongPtr loadTrueTypeFont(const CxCHAR *,
                                            bool,bool,int,int,FontInfo &) { return 0; }
    //
    // End of Internal use only API
    ///////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////
};

//
// The base class for drawing contexts
//
CRX_DEFINE_NULL_CLSID(CRxGiCommonDraw)
class CRXGI_CLASS CRxGiCommonDraw : public CRxObject
{
public:
	CRX_DECLARE_DYNAMIC(CRxGiCommonDraw);

    virtual CRxGiRegenType           regenType() const = 0;
    virtual CAXA::Boolean          regenAbort() const = 0;
    virtual CRxGiSubEntityTraits&    subEntityTraits() const = 0;
    virtual CRxGiGeometry *			rawGeometry() const = 0;
    virtual CAXA::Boolean          isDragging() const = 0;

    // This function operates against the current active viewport
    virtual double					deviation(const CRxGiDeviationType, const CRxGePoint3d&) const = 0;
    virtual CAXA::UInt32           numberOfIsolines() const = 0;
    
    virtual CRxGiContext *			context() = 0;
    virtual bool					secondaryCall() const { return false; }
};

//
// This class provides an API for generating graphics
// in model coordinates.  These graphics cannot be
// controlled by any viewport, as can CRxGiViewportDraw.
CRX_DEFINE_NULL_CLSID(CRxGiWorldDraw)
class CRXGI_CLASS CRxGiWorldDraw: public CRxGiCommonDraw
{
public:
    CRX_DECLARE_DYNAMIC(CRxGiWorldDraw);

    virtual CRxGiWorldGeometry& geometry() const = 0;
};

CRX_DEFINE_NULL_CLSID(CRxGiViewportDraw)
class CRXGI_CLASS CRxGiViewportDraw: public CRxGiCommonDraw 
//
// This class provides an API for generating graphics
// that can be sent to a particular viewport.
//
{ 
public:
    CRX_DECLARE_DYNAMIC(CRxGiViewportDraw);
    virtual CRxGiViewport&        viewport() const = 0;
    virtual CRxGiViewportGeometry& geometry() const = 0;
    virtual CAXA::UInt32        sequenceNumber() const = 0;
    // why is the following method's arg const?
    virtual CAXA::Boolean       isValidId(const CAXA::ULongPtr acgiId) const =0;
    virtual CRxDbObjectId         viewportObjectId() const = 0;
};

CRX_DEFINE_NULL_CLSID(CRxGiViewport)
class CRXGI_CLASS CRxGiViewport: public CRxObject 
//
// This class returns viewport info.
//
{ 
public:
    CRX_DECLARE_DYNAMIC(CRxGiViewport);

    // Get various view transformations.
    //
    virtual void getModelToEyeTransform(CRxGeMatrix3d&) const = 0;
    virtual void getEyeToModelTransform(CRxGeMatrix3d&) const = 0;
    virtual void getWorldToEyeTransform(CRxGeMatrix3d&) const = 0;
    virtual void getEyeToWorldTransform(CRxGeMatrix3d&) const = 0;

    // Perspective information.
    //
    virtual CAXA::Boolean isPerspective() const = 0;
    virtual CAXA::Boolean doPerspective(CRxGePoint3d&) const = 0;
    virtual CAXA::Boolean doInversePerspective(CRxGePoint3d&) const = 0;

    // Pixel information.
    //
    virtual void getNumPixelsInUnitSquare(const CRxGePoint3d& givenWorldpt,
                                  CRxGePoint2d& pixelArea,
                                  bool includePerspective = true) const = 0;

    // Camera information.
    //
    virtual void getCameraLocation(CRxGePoint3d& location) const = 0;
    virtual void getCameraTarget(CRxGePoint3d& target) const = 0;
    virtual void getCameraUpVector(CRxGeVector3d& upVector) const = 0;

    // Viewport information.
    //
    virtual CAXA::ULongPtr viewportId() const = 0;
    virtual CAXA::Int16  acadWindowId() const = 0;
    virtual void getViewportDcCorners(CRxGePoint2d& lower_left,
                                      CRxGePoint2d& upper_right) const = 0;

    // Clipping
    //
    virtual CAXA::Boolean getFrontAndBackClipValues(CAXA::Boolean& clip_front,
                                         CAXA::Boolean& clip_back,
                                         double& front,
                                         double& back) const = 0;

    // The factor returned here affects the linetype scaling in this viewport
    // 1.0 is the default. Returning a value of 2 will ensure
    // that the pattern is twice as big as per default.
    //
    virtual double linetypeScaleMultiplier() const = 0;

    // If the calculated total pattern length of a linetyped object is less
    // than this (value in drawing units). Then a continuous pattern is used
    // instead. Several factors affect the linetype pattern length.
    // linetypeScaleMultiplier() is one of them. Note: If you set this value
    // high you could completely prevent the use of linetypes.
    //
    virtual double linetypeGenerationCriteria() const = 0;

    // Returns true if the layer is not frozen in this viewport and not globally
    // frozen. Indicating that geometry on this layer should be regenerated.
    //
    virtual CAXA::Boolean layerVisible(const CRxDbObjectId & idLayer) const { return CAXA::kTrue; }

    virtual CRxGeVector3d viewDir() const { return CRxGeVector3d::kZAxis; }

    // Provides access to color information that is context-sensitive.
    //
    virtual const CRxGiContextualColors* contextualColors() const { return NULL; }
};
//
//class CRxGiContextualColors : public CRxObject
//{
////
//// This class returns color information for objects that can have different colors
//// in different display contexts.
////
//public:
//    ACRX_DECLARE_MEMBERS(CRxGiContextualColors);
//
//    // Access to colors.
//    virtual CAXA::UInt32 gridMajorLines() const = 0;
//    virtual CAXA::UInt32 gridMinorLines() const = 0;
//    virtual CAXA::UInt32 gridAxisLines() const = 0;
//    virtual int gridMajorLineTintXYZ() const = 0;
//    virtual int gridMinorLineTintXYZ() const = 0;
//    virtual int gridAxisLineTintXYZ() const = 0;
//
//    virtual CAXA::UInt32 lightGlyphs() const = 0;
//    virtual CAXA::UInt32 lightHotspot() const = 0;
//    virtual CAXA::UInt32 lightFalloff() const = 0;
//    virtual CAXA::UInt32 lightStartLimit() const = 0;
//    virtual CAXA::UInt32 lightEndLimit() const = 0;
//
//    virtual CAXA::UInt32 cameraGlyphs() const = 0;
//    virtual CAXA::UInt32 cameraFrustrum() const = 0;
//    virtual CAXA::UInt32 cameraClipping() const = 0;
//
//    // Access to context parameters.
//    virtual void setContextFlags(CAXA::UInt32 flg, bool set = true) = 0;
//    virtual bool flagsSet(CAXA::UInt32 flg) const = 0;
//};
//
//
//class CRxGiContextualColors2 : public CRxGiContextualColors
//{
////
//// This class returns color information for objects that can have different colors
//// in different display contexts.  This class also includes the web mesh color 
//// for photometric lights.
////
//public:
//    ACRX_DECLARE_MEMBERS(CRxGiContextualColors2);
//
//    virtual CRxCmColor     webMeshColor        (void) const = 0;
//    virtual CRxCmColor     webMeshMissingColor (void) const = 0;
//    virtual CRxCmColor     lightShapeColor     (void) const = 0;
//    virtual CRxCmColor     lightDistanceColor  (void) const = 0;
//};
//
//
///* CaxaDraft reserves a block of 64K marker ids for custom use. The range from INT_MIN thu INT_MIN+65535
//   Callers of setSelectionMarker should not use this range except for the values below.
//   The value of 0 has special meaning and indicates no selection marker.
//*/
//#define CRxGiSelectionMarkerCDRAFTReserveStart         (-2147483647 - 1)   // INT_MIN without using limits.h
//#define CRxGiSelectionMarkerCDRAFTReserveEnd           (CRxGiSelectionMarkerCDRAFTReserveStart + 65535)
//
//#define CRxGiSelectionMarkerCDRAFTSelectionPreviewOff  (CRxGiSelectionMarkerCDRAFTReserveStart + 1)   // turn off selection preview display
//#define CRxGiSelectionMarkerCDRAFTSelectionPreviewOn   (CRxGiSelectionMarkerCDRAFTReserveStart + 2)   // turn on selection preview display

//
// This class applies attributes to subsequently drawn CRxGi geometry
// primitives.
//
CRX_DEFINE_NULL_CLSID(CRxGiSubEntityTraits)
class CRXGI_CLASS CRxGiSubEntityTraits: public CRxObject 
{ 
public:
    CRX_DECLARE_DYNAMIC(CRxGiSubEntityTraits);

    enum DrawFlags
    {
        kNoDrawFlags        =   0,
        kDrawBackfaces      =   1,
        kDrawHatchGroup     =   2,
        kDrawFrontfacesOnly =   4,
        kDrawGradientFill   =   8,
        kDrawSolidFill      =   16
    };

    enum ShadowFlags
    {
        kShadowsCastAndReceive  = 0x00,
        kShadowsDoesNotCast     = 0x01,
        kShadowsDoesNotReceive  = 0x02,
        kShadowsIgnore          = kShadowsDoesNotCast | kShadowsDoesNotReceive,
    };

    // Set properties of drawn objects.
    //
    virtual void              setColor              (const CAXA::UInt16 color) = 0;
    virtual void              setTrueColor          (const CRxCmEntityColor& color) = 0;
    virtual void              setLayer              (const CRxDbObjectId layerId) = 0;
    virtual void              setLineType           (const CRxDbObjectId linetypeId) = 0;
    virtual void              setSelectionMarker    (const CAXA::LongPtr markerId) = 0;
    virtual void              setFillType           (const CRxGiFillType) = 0;
    virtual void              setLineWeight         (const CRxDb::LineWeight lw) = 0;
    virtual void              setLineTypeScale      (double dScale = 1.0) = 0;
    virtual void              setThickness          (double dThickness) = 0;
    virtual void              setVisualStyle        (const CRxDbObjectId visualStyleId);
    virtual CDraft::ErrorStatus setEdgeStyleOverride  (CRxGiEdgeStyleMask mask, const CRxGiEdgeStyle& edgeStyle);
    virtual void              setPlotStyleName      (CRxDb::PlotStyleNameType type, const CRxDbObjectId & id = CRxDbObjectId::kNull) {}
    virtual void              setMaterial           (const CRxDbObjectId materialId);
    virtual void              setMapper             (const CRxGiMapper * mapper);
    virtual void              setSectionable        (bool bSectionable);
    virtual CDraft::ErrorStatus setDrawFlags          (CAXA::UInt32 flags);
    virtual CDraft::ErrorStatus setShadowFlags        (ShadowFlags flags);
    virtual void              setSelectionGeom      (bool bSelectionflag);

    // Return current settings.
    //
    virtual CAXA::UInt16           color               (void) const = 0;
    virtual CRxCmEntityColor         trueColor           (void) const = 0;
    virtual CRxDbObjectId            layerId             (void) const = 0;
    virtual CRxDbObjectId            lineTypeId          (void) const = 0;
    virtual CRxGiFillType            fillType            (void) const = 0;
    virtual CRxDb::LineWeight        lineWeight          (void) const = 0;
    virtual double                  lineTypeScale       (void) const = 0;
    virtual double                  thickness           (void) const = 0;
    virtual CRxDbObjectId            visualStyle         (void) const;
    virtual CDraft::ErrorStatus       edgeStyleOverride   (CRxGiEdgeStyleMask& mask, CRxGiEdgeStyle& edgeStyle) const;
    virtual CRxDb::PlotStyleNameType getPlotStyleNameId  (CRxDbObjectId& idResult) const { return CRxDb::kPlotStyleNameByLayer ; }
    virtual CRxDbObjectId            materialId          (void) const;
    virtual const CRxGiMapper *      mapper              (void) const;
    virtual bool                    sectionable         (void) const;
    virtual CAXA::UInt32           drawFlags           (void) const;
    virtual ShadowFlags             shadowFlags         (void) const;
    virtual bool                    selectionGeom       (void) const;
};

inline void 
CRxGiSubEntityTraits::setMaterial(const CRxDbObjectId materialId)
{
}

inline CRxDbObjectId  
CRxGiSubEntityTraits::materialId(void) const
{
    return CRxDbObjectId::kNull;
}

inline
void CRxGiSubEntityTraits::setMapper (const CRxGiMapper * mapper)
{
}

inline const CRxGiMapper * 
CRxGiSubEntityTraits::mapper (void) const
{
    return NULL;
}

inline void 
CRxGiSubEntityTraits::setVisualStyle(CRxDbObjectId visualStyleId)
{
}

inline CRxDbObjectId
CRxGiSubEntityTraits::visualStyle(void) const
{
    return CRxDbObjectId::kNull;
}

inline CDraft::ErrorStatus 
CRxGiSubEntityTraits::setEdgeStyleOverride (CRxGiEdgeStyleMask mask, const CRxGiEdgeStyle& edgeStyle)
{
    return CDraft::eNotImplementedYet;
}

inline CDraft::ErrorStatus 
CRxGiSubEntityTraits::edgeStyleOverride (CRxGiEdgeStyleMask& mask, CRxGiEdgeStyle& edgeStyle) const
{
    return CDraft::eNotImplementedYet;
}

inline void 
CRxGiSubEntityTraits::setSectionable(bool bSectionable)
{
}

inline bool 
CRxGiSubEntityTraits::sectionable(void) const
{
    return false;
}

inline CDraft::ErrorStatus
CRxGiSubEntityTraits::setDrawFlags (CAXA::UInt32 flags)
{
    return CDraft::eNotImplementedYet;
}

inline CAXA::UInt32 
CRxGiSubEntityTraits::drawFlags (void) const
{
    return 0;
}

inline CDraft::ErrorStatus 
CRxGiSubEntityTraits::setShadowFlags (ShadowFlags flags)
{
    return CDraft::eNotImplementedYet;
}

inline CRxGiSubEntityTraits::ShadowFlags
CRxGiSubEntityTraits::shadowFlags (void) const
{
    return kShadowsCastAndReceive;
}

inline void
CRxGiSubEntityTraits::setSelectionGeom ( bool )
{
}

inline bool 
CRxGiSubEntityTraits::selectionGeom ( void ) const
{
    return false;
}


class CRxGiDrawableTraits: public CRxGiSubEntityTraits 
//
// This class applies attributes to all CRxGi geometry primitives
// for this drawable. This class is available to a drawable only during
// the setAttributes() call.
//
{ 
public:

    friend class            CRxDbLayerTableRecord;

    CRX_DECLARE_DYNAMIC(CRxGiDrawableTraits);
    
    // Rather than using individual calls to the settings it is more efficient
    // to make this single call for an entity.
    //
    virtual void setupForEntity(CRxDbEntity * pEntity);

    // Drawables that emit light can add one or more to the model. A unique
    // object id must be used for each light, though an object may pass
    // in its own object id.
    // This implementation ignores light information, so derived classes
    // must override this method in order to collect and use the illumination.
    //
    virtual void addLight(const CRxDbObjectId& lightId);

protected:

    enum LayerFlags {
        kNone       = 0x00,
        kOff        = 0x01,
        kFrozen     = 0x02,
        kZero       = 0x04,
        kLocked     = 0x08
    };

    virtual void    setLayerFlags       (CAXA::UInt8 flags)        { };
};

// Default implementation does nothing with the illumination data.
//
inline void 
CRxGiDrawableTraits::addLight(const CRxDbObjectId& lightId)
{
}
//
//
//class CRxGiNonEntityTraits : public CRxGiDrawableTraits
//// 
//// This class implements empty CRxGiDrawableTraits and CRxGiSubEntityTraits
//// interfaces, to allow non-entity drawables such as materials to elaborate 
//// their unique properties through CRxGiDrawableTraits
////
//{
//public:
//    ACRX_DECLARE_MEMBERS(CRxGiNonEntityTraits);
//
//    // CRxGiDrawableTraits interface
//    virtual void                setupForEntity      (CRxDbEntity* pEntity);
//    virtual void                addLight(const CRxDbObjectId& id);
//
//    // CRxGiSubEntityTraits interface
//    virtual void                setColor            (const CAXA::UInt16 color);
//    virtual CAXA::UInt16       color               (void) const;
//    virtual void                setTrueColor        (const CRxCmEntityColor& color);
//    virtual CRxCmEntityColor     trueColor           (void) const;
//    virtual void                setLayer            (const CRxDbObjectId layerId);
//    virtual CRxDbObjectId        layerId             (void) const;
//    virtual void                setLineType         (const CRxDbObjectId linetypeId);
//    virtual CRxDbObjectId        lineTypeId          (void) const;
//    virtual void                setSelectionMarker  (const CAXA::LongPtr markerId);
//    virtual void                setFillType         (const CRxGiFillType fillType);
//    virtual CRxGiFillType        fillType            (void) const;
//    virtual void                setLineWeight       (const CRxDb::LineWeight lw);
//    virtual CRxDb::LineWeight    lineWeight          (void) const;
//    virtual void                setThickness        (double thickness);
//    virtual double              thickness           (void) const;
//    virtual void                setLineTypeScale    (double dScale);
//    virtual double              lineTypeScale       (void) const;
//    virtual void                setMaterial         (const CRxDbObjectId matId);
//    virtual CRxDbObjectId        materialId          (void) const;
//    virtual void                setSelectionGeom    (bool bSelectionflag);
//    virtual bool                selectionGeom       ( void ) const;
//};
//
//inline void 
//CRxGiNonEntityTraits::setupForEntity (CRxDbEntity* pEntity)
//{
//    assert(false);
//}
//
//inline void 
//CRxGiNonEntityTraits::addLight(const CRxDbObjectId& id)
//{
//    assert(false);
//}
//
//inline void 
//CRxGiNonEntityTraits::setColor (const CAXA::UInt16 color)     
//{
//    assert(false);
//}
//
//inline CAXA::UInt16 
//CRxGiNonEntityTraits::color (void) const      
//{ 
//    assert(false);
//    return 0; 
//}
//
//inline void 
//CRxGiNonEntityTraits::setTrueColor (const CRxCmEntityColor& color)  
//{ 
//    assert(false);
//}
//
//inline CRxCmEntityColor 
//CRxGiNonEntityTraits::trueColor (void) const
//{ 
//    assert(false);
//    return CRxCmEntityColor(); 
//}
//
//inline void 
//CRxGiNonEntityTraits::setLayer (const CRxDbObjectId layerId)    
//{ 
//    assert(false);
//}
//
//inline CRxDbObjectId 
//CRxGiNonEntityTraits::layerId (void) const      
//{ 
//    assert(false);
//    return CRxDbObjectId::kNull; 
//}
//
//inline void 
//CRxGiNonEntityTraits::setLineType (const CRxDbObjectId linetypeId)
//{  
//    assert(false);
//}
//
//inline CRxDbObjectId CRxGiNonEntityTraits::lineTypeId (void) const      
//{ 
//    assert(false);
//    return  CRxDbObjectId::kNull; 
//}
//
//inline void 
//CRxGiNonEntityTraits::setMaterial(const CRxDbObjectId matId)
//{  
//    assert(false);
//}
//
//inline CRxDbObjectId CRxGiNonEntityTraits::materialId (void) const      
//{ 
//    assert(false);
//    return  CRxDbObjectId::kNull; 
//}
//
//inline void 
//CRxGiNonEntityTraits::setSelectionMarker (const CAXA::LongPtr markerId)   
//{ 
//    assert(false);
//}
//
//inline void 
//CRxGiNonEntityTraits::setFillType (const CRxGiFillType fillType)   
//{ 
//    assert(false);
//}
//
//inline CRxGiFillType 
//CRxGiNonEntityTraits::fillType (void) const      
//{ 
//    assert(false);
//    return kAcGiFillAlways;
//}
//
//inline void 
//CRxGiNonEntityTraits::setLineWeight (const CRxDb::LineWeight lw)     
//{ 
//    assert(false);
//}
//
//inline CRxDb::LineWeight 
//CRxGiNonEntityTraits::lineWeight (void) const      
//{ 
//    assert(false);
//    return CRxDb::kLnWt000; 
//}
//
//inline void 
//CRxGiNonEntityTraits::setThickness (double thickness)
//{ 
//    assert(false);
//}
//
//inline double 
//CRxGiNonEntityTraits::thickness (void) const      
//{ 
//    assert(false);
//    return 0.0; 
//}
//
//inline void 
//CRxGiNonEntityTraits::setLineTypeScale (double dScale)   
//{  
//    assert(false);
//}
//
//inline double 
//CRxGiNonEntityTraits::lineTypeScale (void) const      
//{ 
//    assert(false);
//    return 0.0; 
//}
//
//inline void
//CRxGiNonEntityTraits::setSelectionGeom ( bool )
//{
//    assert(false);
//}
//
//inline bool 
//CRxGiNonEntityTraits::selectionGeom ( void ) const
//{
//    assert(false);
//    return false;
//}
//
typedef enum { 
     kAcGiWorldPosition,
     kAcGiViewportPosition,
     kAcGiScreenPosition,
     kAcGiScreenLocalOriginPosition,
     kAcGiWorldWithScreenOffsetPosition
} CrxGiPositionTransformBehavior;

typedef enum { 
     kAcGiWorldScale,
     kAcGiViewportScale,
     kAcGiScreenScale,
     kAcGiViewportLocalOriginScale,
     kAcGiScreenLocalOriginScale
} CRxGiScaleTransformBehavior;

typedef enum { 
     kAcGiWorldOrientation,
     kAcGiScreenOrientation,
     kAcGiZAxisOrientation
} CRxGiOrientationTransformBehavior;

//
// The base class for geometry toolkits
CRX_DEFINE_NULL_CLSID(CRxGiGeometry)
class CRXGI_CLASS CRxGiGeometry: public CRxObject
{
public:
    CRX_DECLARE_DYNAMIC(CRxGiGeometry);

    enum TransparencyMode
    {
        kTransparencyOff,  // pixel alpha ignored, all pixels are opaque
        kTransparency1Bit, // pixel alpha determines transparency on/off,
            // with 0 to 254 completely transparent and 255 completely opaque
        kTransparency8Bit, // pixel alpha determines transparency level,
        // from 0 (completely transparent) to 255 (completely opaque)
    };


    // Coordinate transformations.
    //
    virtual void getModelToWorldTransform(CRxGeMatrix3d&) const = 0;
    virtual void getWorldToModelTransform(CRxGeMatrix3d&) const = 0;

    virtual CAXA::Boolean pushModelTransform(const CRxGeVector3d & vNormal) = 0;// Uses arbitrary Axis algorythm
    virtual CAXA::Boolean pushModelTransform(const CRxGeMatrix3d & xMat) = 0;
    virtual CAXA::Boolean popModelTransform() = 0;


    // For drawing various primitives.
    //
    virtual CAXA::Boolean  circle(const CRxGePoint3d& center,
                                   const double radius,
                                   const CRxGeVector3d& normal) const = 0;

    virtual CAXA::Boolean  circle(const CRxGePoint3d&, const CRxGePoint3d&,
                                   const CRxGePoint3d&) const = 0;

    virtual CAXA::Boolean  circularArc(const CRxGePoint3d& center,
                                   const double radius,
                                   const CRxGeVector3d& normal,
                                   const CRxGeVector3d& startVector,
                                   const double sweepAngle,
                                   const CRxGiArcType arcType = kAcGiArcSimple) const = 0;

    virtual CAXA::Boolean  circularArc(const CRxGePoint3d& start,
                                   const CRxGePoint3d& point,
                                   const CRxGePoint3d& end,
                                   const CRxGiArcType arcType = kAcGiArcSimple) const = 0;
      
    virtual CAXA::Boolean  polyline(const CAXA::UInt32 nbPoints,
                                   const CRxGePoint3d* pVertexList,
                                   const CRxGeVector3d* pNormal = NULL,
                                   CAXA::LongPtr lBaseSubEntMarker = -1) const = 0;
      
    virtual CAXA::Boolean  polygon(const CAXA::UInt32 nbPoints,
                                   const CRxGePoint3d* pVertexList) const = 0;

    virtual CAXA::Boolean  mesh(const CAXA::UInt32 rows,
                                 const CAXA::UInt32 columns,
                                 const CRxGePoint3d* pVertexList,
                                 const CRxGiEdgeData* pEdgeData = NULL,
                                 const CRxGiFaceData* pFaceData = NULL,
                                 const CRxGiVertexData* pVertexData = NULL,
                                 const bool bAutoGenerateNormals = true
                                 ) const = 0;

    virtual CAXA::Boolean  shell(const CAXA::UInt32 nbVertex,
                                 const CRxGePoint3d* pVertexList,
                                 const CAXA::UInt32 faceListSize,
                                 const CAXA::Int32* pFaceList,
                                 const CRxGiEdgeData* pEdgeData = NULL,
                                 const CRxGiFaceData* pFaceData = NULL,
                                 const CRxGiVertexData* pVertexData = NULL,
                                 const struct resbuf* pResBuf = NULL,
                                 const bool bAutoGenerateNormals = true
                                 ) const = 0;
      
    virtual CAXA::Boolean  text(const CRxGePoint3d& position,
                                 const CRxGeVector3d& normal,
                                 const CRxGeVector3d& direction,
                                 const double height,
                                 const double width,
                                 const double oblique,
                                 const CxCHAR* pMsg) const = 0;

    virtual CAXA::Boolean  text(const CRxGePoint3d& position,
                                 const CRxGeVector3d& normal,
                                 const CRxGeVector3d& direction,
                                 const CxCHAR* pMsg,
                                 const CAXA::Int32 length,
                                 const CAXA::Boolean raw,
                                 const CRxGiTextStyle &pTextStyle
                                 ) const = 0;

    virtual CAXA::Boolean  xline(const CRxGePoint3d&,
                                  const CRxGePoint3d&) const = 0;

    virtual CAXA::Boolean  ray(const CRxGePoint3d&,
                                const CRxGePoint3d&) const = 0;

    virtual CAXA::Boolean  pline(const CRxDbPolyline& lwBuf,
                                  CAXA::UInt32 fromIndex = 0,
                                  CAXA::UInt32 numSegs = 0
                                  ) const = 0;

    virtual CAXA::Boolean  draw(CRxGiDrawable*) const = 0;

    // If you push a clip boundary onto the stack you must pop it;
    //
    virtual CAXA::Boolean          pushClipBoundary(CRxGiClipBoundary * pBoundary) = 0;
    virtual void                    popClipBoundary() = 0;
    virtual CAXA::Boolean   worldLine(const CRxGePoint3d pnts[2]) {
                                        CRxGePoint3d polyPnts[2];
                                        CRxGeMatrix3d mat;
                                        getWorldToModelTransform(mat);
                                        polyPnts[0] = mat * pnts[0];
                                        polyPnts[1] = mat * pnts[1];
                                        return polyline(2, polyPnts);
                                    };
    // array of points
    virtual CAXA::Boolean  polypoint( const CAXA::UInt32 nbPoints,
                                       const CRxGePoint3d* pVertexList,
                                       const CRxGeVector3d* pNormal = NULL,
                                       const CAXA::LongPtr *pSubEntMarkers = NULL ) const {
                                           CRxGePoint3d pline[2];
                                           CAXA::Boolean retval = CAXA::kFalse;
                                           for (CAXA::UInt32 i = 0; i < nbPoints; i++) {
                                               pline[1] = pline[0] = pVertexList[i];
                                               retval = polyline(2, pline, pNormal ? &pNormal[i] : NULL, pSubEntMarkers ? pSubEntMarkers[i] : -1);
                                               if (retval)
                                                   return retval;
                                           }
                                           return retval;
                                    };

};

//
// This class contains the view independent, model coordinate,
// 3D geometry methods.
//
CRX_DEFINE_NULL_CLSID(CRxGiWorldGeometry)
class CRXGI_CLASS CRxGiWorldGeometry: public CRxGiGeometry 
{ 
public:
    CRX_DECLARE_DYNAMIC(CRxGiWorldGeometry);

    virtual void setExtents(CRxGePoint3d *pNewExtents) const = 0;

    // If this drawable is a block and has AcDbAttributes it must call
    // this method exactly once before sending the attributes to 
    // draw(). Once this is called the object may draw only attributes
    // and no more primitives
    // The attributes must be the last objects rendered
    //
    virtual void startAttributesSegment() {};
};

CRX_DEFINE_NULL_CLSID(CRxGiWorldGeometry2)
class CRXGI_CLASS CRxGiWorldGeometry2: public CRxGiWorldGeometry
{
public:
    CRX_DECLARE_DYNAMIC(CRxGiWorldGeometry2);

    virtual void pushPositionTransform (CrxGiPositionTransformBehavior behavior, const CRxGePoint2d& offset) = 0; 

    virtual void pushScaleTransform(CRxGiScaleTransformBehavior behavior, const CRxGePoint2d& extents) = 0; 

    virtual void pushOrientationTransform(CRxGiOrientationTransformBehavior behavior) = 0;

    virtual CAXA::Boolean image   (
                const CRxGiImageBGRA32& imageSource,
                const CRxGePoint3d& position,
                const CRxGeVector3d& u, //orientation and magnitude of width
                const CRxGeVector3d& v, //orientation and magnitude of height
                TransparencyMode transparencyMode = kTransparency8Bit
                ) const = 0;

    virtual CAXA::Boolean rowOfDots   (
                int count,
                const CRxGePoint3d&     start,
                const CRxGeVector3d&     step
                ) const = 0;

    virtual CAXA::Boolean ellipticalArc  (
                 const CRxGePoint3d&         center,
                 const CRxGeVector3d&        normal,
                 double                     majorAxisLength,
                 double                     minorAxisLength,
                 double                     startDegreeInRads,
                 double                     endDegreeInRads,
                 double                     tiltDegreeInRads,
                 bool                       isPie 
                 ) const = 0 ;

    virtual CAXA::Boolean symbol  (
                 CRxGiSymbolType type,
                 const CAXA::UInt32 nbPoints,
                 const CRxGePoint3d* pPoints,
                 const CRxCmEntityColor& outlineColor,
                 const CRxCmEntityColor& fillColor
                 ) const = 0;
};

CRX_DEFINE_NULL_CLSID(CRxGiViewportGeometry)
class CRXGI_CLASS CRxGiViewportGeometry: public CRxGiGeometry 
//
// This class contains the view dependent, model and drawing coordinate,
// 3D geometry methods.
//
{ 
public:
    CRX_DECLARE_DYNAMIC(CRxGiViewportGeometry);

    //virtual CAXA::Boolean  polylineEye(const CAXA::UInt32 nbPoints,
    //                            const CRxGePoint3d* pPoints) const = 0;
    //virtual CAXA::Boolean  polygonEye(const CAXA::UInt32 nbPoints,
    //                            const CRxGePoint3d* pPoints) const = 0;

    //virtual CAXA::Boolean  polylineDc(const CAXA::UInt32 nbPoints,
    //                            const CRxGePoint3d* pPoints) const = 0;
    //virtual CAXA::Boolean  polygonDc(const CAXA::UInt32 nbPoints,
    //                            const CRxGePoint3d* pPoints) const = 0;

    //enum ImageSource {
    //    kFromDwg,
    //    kFromOleObject,
    //    kFromRender
    //};

    //virtual CAXA::Boolean  rasterImageDc(
    //            const CRxGePoint3d& origin,
    //            const CRxGeVector3d& u,
    //            const CRxGeVector3d& v,
    //            const CRxGeMatrix2d& pixelToDc,
    //            CRxDbObjectId entityId,
    //            CRxGiImageOrg imageOrg,
    //            CAXA::UInt32 imageWidth,
    //            CAXA::UInt32 imageHeight,
    //            CAXA::Int16 imageColorDepth,
    //            CAXA::Boolean transparency,
    //            ImageSource source,
    //            const CRxGeVector3d& unrotatedU,
    //            const CRxGiImageOrg origionalImageOrg,
    //            const CRxGeMatrix2d& unrotatedPixelToDc,
    //            const CAXA::UInt32 unrotatedImageWidth,
    //            const CAXA::UInt32 unrotatedImageHeight
    //            ) const = 0;

    //virtual CAXA::Boolean  ownerDrawDc(
    //            long                       vpnumber, 
    //            long                       left, 
    //            long                       top, 
    //            long                       right, 
    //            long                       bottom, 
    //            const OwnerDraw*           pOwnerDraw
    //            ) const = 0;

    //virtual CAXA::Boolean  ownerDraw3d(
    //            CRxGePoint3d&               minBounds,
    //            CRxGePoint3d&               maxBounds,
    //            OwnerDraw3d*               pOwnerDraw
    //            ) const  { return CAXA::kFalse; };
};

//class CRxGiViewportGeometry2: public CRxGiViewportGeometry
//{
//public:
//    ACRX_DECLARE_MEMBERS(CRxGiViewportGeometry2);
//
//    virtual CRxGeMatrix3d pushPositionTransform (CrxGiPositionTransformBehavior behavior, const CRxGePoint2d& offset) = 0; 
//
//    virtual CRxGeMatrix3d pushScaleTransform(CRxGiScaleTransformBehavior behavior, const CRxGePoint2d& extents) = 0; 
//
//    virtual CRxGeMatrix3d pushOrientationTransform(CRxGiOrientationTransformBehavior behavior) = 0;
//
//    virtual CAXA::Boolean image   (
//                const CRxGiImageBGRA32& imageSource,
//                const CRxGePoint3d& position,
//                const CRxGeVector3d& u, //orientation and magnitude of width
//                const CRxGeVector3d& v, //orientation and magnitude of height
//                TransparencyMode transparencyMode = kTransparency8Bit
//                ) const = 0;
//
//    virtual CAXA::Boolean rowOfDots   (
//                int count,
//                const CRxGePoint3d&     start,
//                const CRxGeVector3d&     step
//                ) const = 0;
//
//    virtual CAXA::Boolean ellipticalArc  (
//                 const CRxGePoint3d&         center,
//                 const CRxGeVector3d&        normal,
//                 double                     majorAxisLength,
//                 double                     minorAxisLength,
//                 double                     startDegreeInRads,
//                 double                     endDegreeInRads,
//                 double                     tiltDegreeInRads,
//                 bool                       isPie 
//                 ) const = 0 ;
//
//    virtual CAXA::Boolean symbol  (
//                 CRxGiSymbolType type,
//                 const CAXA::UInt32 nbPoints,
//                 const CRxGePoint3d* pPoints,
//                 const CRxCmEntityColor& outlineColor,
//                 const CRxCmEntityColor& fillColor
//                 ) const = 0;
//
//};
//class CRxGiEdgeData: public CRxObject 
////
//// This class contains arrays of edge attributes for meshes and shells.
////
//// NOTE:
////   Setting an 'improper' size array of color, layers, etc.
////   will cause unpredictable or fatal results.
////
//{ 
//public:
//    ACRX_DECLARE_MEMBERS(CRxGiEdgeData);
//
//    ~CRxGiEdgeData();
//    CRxGiEdgeData();
//
//    virtual void            setColors(const short *colors);
//    virtual void            setTrueColors(const CRxCmEntityColor *colors);
//    virtual void            setLayers(const CRxDbObjectId *layers);
//    virtual void            setLineTypes(const CRxDbObjectId *linetypes);
//    virtual void            setSelectionMarkers(const CAXA::LongPtr* pSelectionMarkers);
//    virtual void            setVisibility(const CAXA::UInt8* pVisibility);
//
//    virtual short*          colors() const;
//    virtual CRxCmEntityColor* trueColors() const;
//    virtual CRxDbObjectId*   layerIds() const;
//    virtual CRxDbObjectId*   linetypeIds() const;
//    virtual CAXA::LongPtr* selectionMarkers() const;
//    virtual CAXA::UInt8*   visibility() const;
//
//private:
//    AcGiImpEdgeData *mpAcGiImpEdgeData;
//};

class CRxGiFaceData: public CRxObject 
//
// This class contains arrays of face attributes for meshes and shells.
//
// NOTE:
//   Setting an 'improper' size array of color, layers, etc.
//   will cause unpredictable or fatal results.
//
{ 
public:
    CRX_DECLARE_DYNAMIC(CRxGiFaceData);

    ~CRxGiFaceData();
    CRxGiFaceData();
    virtual void            setColors(const short *colors);
    virtual void            setTrueColors(const CRxCmEntityColor *colors);
    virtual void            setLayers(const CRxDbObjectId *layers);
    virtual void            setSelectionMarkers(const CAXA::LongPtr* pSelectionMarkers);
    virtual void            setNormals(const CRxGeVector3d* pNormals);
    virtual void            setVisibility(const CAXA::UInt8* vis);
    virtual void            setMaterials(const CRxDbObjectId * materials);
    virtual void            setMappers(const CRxGiMapper * mappers);

    virtual short*          colors() const;
    virtual CRxCmEntityColor* trueColors() const;
    virtual CRxDbObjectId*   layerIds() const;
    virtual CAXA::LongPtr* selectionMarkers() const;
    virtual CRxGeVector3d*   normals() const;
    virtual CAXA::UInt8*   visibility() const;
    virtual CRxDbObjectId*   materials() const; // TODO Randy Kintzley 09/27/2005 how is this used? Should it be renamed to materialIds()?
    virtual CRxGiMapper*     mappers() const; 

private:
    CRxGiImpFaceData *mpAcGiImpFaceData;
};

class CRxGiVertexData: public CRxObject 
//
// This class contains arrays of vertex attributes for meshes and shells.
//
// NOTE:
//   Setting an 'improper' size array of color, layers, etc.
//   will cause unpredictable or fatal results.
//
{ 
public:
    enum MapChannel
    {
        kAllChannels,
        kMapChannels
    };

    CRX_DECLARE_DYNAMIC(CRxGiVertexData);

    ~CRxGiVertexData();
    CRxGiVertexData();
    virtual void setNormals(const CRxGeVector3d* pNormals);
    virtual CRxGeVector3d* normals() const;
    virtual void setOrientationFlag(const CRxGiOrientationType oflag); 
    virtual CRxGiOrientationType orientationFlag() const;
    virtual void setTrueColors(const CRxCmEntityColor *colors);
    virtual CRxCmEntityColor* trueColors() const;

    void setMappingCoords (MapChannel mapChannel, const CRxGePoint3d* pCoords);
    CRxGePoint3d* mappingCoords (MapChannel mapChannel) const;

private:
    CRxGiImpVertexData *mpAcGiImpVertexData;
};

class CRxGiTextStyle: public CRxObject 
// 
// This class contains methods to create and modify a text
// style object
//
{ 
public:
    CRX_DECLARE_DYNAMIC(CRxGiTextStyle);

    ~CRxGiTextStyle();
    CRxGiTextStyle();

    CRxGiTextStyle(
        const CxCHAR*  fontName, 
        const CxCHAR*  bigFontName, 
        const double textSize, 
        const double xScale, 
        const double obliqueAngle, 
        const double trPercent,

        const CAXA::Boolean isBackward,
        const CAXA::Boolean isUpsideDown,
        const CAXA::Boolean isVertical, 

        const CAXA::Boolean isOverlined,
        const CAXA::Boolean isUnderlined,
        
        const CxCHAR*          styleName = NULL);

    // Unicode: change from char to int, since in the implementation, the returned
    // result is actually bitmask indicating some status result.
    virtual int loadStyleRec() const;
    virtual void setTextSize(const double size);
    virtual void setXScale(const double xScale);
    virtual void setObliquingAngle(const double obliquingAngle);

    virtual void setTrackingPercent(const double trPercent);

    virtual void setBackward(const CAXA::Boolean isBackward);
    virtual void setUpsideDown(const CAXA::Boolean isUpsideDown);
    virtual void setVertical(const CAXA::Boolean isVertical);

    virtual void setUnderlined(const CAXA::Boolean isUnderlined);
    virtual void setOverlined(const CAXA::Boolean isOverlined);

    virtual void setFileName(const CxCHAR * fontName);
    virtual void setBigFontFileName(const CxCHAR * bigFontFileName);

    virtual double textSize() const;
    virtual double xScale() const;
    virtual double obliquingAngle() const;

    virtual double trackingPercent() const;

    virtual CAXA::Boolean isBackward() const;
    virtual CAXA::Boolean isUpsideDown() const;
    virtual CAXA::Boolean isVertical() const;

    virtual CAXA::Boolean isUnderlined() const;
    virtual CAXA::Boolean isOverlined() const;

    virtual const CxCHAR * fileName() const;
    virtual const CxCHAR * bigFontFileName() const;

    virtual CRxGePoint2d extents(const CxCHAR * pStr, 
                const CAXA::Boolean penups,
                const int len,
                const CAXA::Boolean raw,
                CRxGiWorldDraw *ctxt = NULL) const;

    virtual const CxCHAR * styleName() const;
    virtual CDraft::ErrorStatus setStyleName(const CxCHAR *);
    
    virtual CDraft::ErrorStatus setFont(const CxCHAR * pTypeface,
                                      CAXA::Boolean bold,
                                      CAXA::Boolean italic,
                                      int charset, int pitchAndFamily);
    // Unicode: change pTypeface to CRxString?
    virtual CDraft::ErrorStatus font(CxCHAR *& pTypeface, CAXA::Boolean& bold, 
                CAXA::Boolean& italic, int& charset, int& pitchAndFamily) const;

    virtual CDraft::ErrorStatus  extentsBox(  const CxCHAR * pStr, 
                                            const CAXA::Boolean penups,
                                            const int len,
                                            const CAXA::Boolean raw,
                                            CRxGePoint2d &extMin,
                                            CRxGePoint2d &extMax,
                                            CRxGiWorldDraw *ctxt = NULL) const;

    virtual void setTrackKerning(double trackPercent) const;

    virtual bool preLoaded() const;
    virtual void setPreLoaded(bool);

private:
    CRxGiImpTextStyle *mpAcGiImpTextStyle;
};

#pragma pack (pop)

#endif
