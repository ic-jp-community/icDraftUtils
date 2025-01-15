//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

// DESCRIPTION: True Color Definitions


// headers
#ifndef CRX_DBCOLOR_H
#define CRX_DBCOLOR_H 1

#include "cdraft.h"
#include "crxcdstrc.h"
#include <assert.h>

#pragma pack (push, 8)


class CRxCmEntityColor;


// It takes care of the color method, which is one of the following: 
// byBlock, byLayer, or byColor.
// Depending on this color method it stores RGB, ACI, or Layerindex.
//
// Note: To save memory I did the following:
//          It is not deriving from CrxDbXObject. 
//          No virtual methods.
//          Color Method stored in last byte mRGBM.
class CRxCmEntityColor
{
public:
    enum Color { kRed,
                 kGreen,
                 kBlue
    };

    // Color Method.
    enum ColorMethod {   kByLayer =0xC0, 
                         kByBlock,
                         kByColor,
                         kByACI,
                         kByPen,
                         kForeground,
                         kLayerOff,
                         // Run-time states
                         kLayerFrozen,
                         kNone
    };

    enum ACIcolorMethod {kACIbyBlock    = 0,
                         kACIforeground = 7,
                         kACIbyLayer    = 256,
                         // Run-time states
                         kACIclear      = 0,    
                         kACIstandard   = 7,
                         kACImaximum    = 255,
                         kACInone       = 257,
                         kACIminimum    = -255,
                         kACIfrozenLayer= -32700
    };

    // Blue, green, red, and Color Method (byBlock, byLayer, byColor).
    // Is stored that way for better performance. 
    union RGBM {
        CAXA::UInt32    whole;
        CAXA::Int16     indirect;
        struct {
            CAXA::UInt8 blue, 
                         green, 
                         red, 
                         colorMethod;
        };
    };

    CRxCmEntityColor     ();
    CRxCmEntityColor     (const CRxCmEntityColor & color);
    CRxCmEntityColor     (const ColorMethod eColorMethod);
    CRxCmEntityColor     (const CAXA::UInt8 red, 
                         const CAXA::UInt8 green, 
                         const CAXA::UInt8 blue);

    CRxCmEntityColor&    operator =  (const CRxCmEntityColor& color);
    bool                operator == (const CRxCmEntityColor& color) const;
    bool                operator != (const CRxCmEntityColor& color) const;


    // Set/get components
    CDraft::ErrorStatus   setColorMethod  (const ColorMethod eColorMethod);
    ColorMethod         colorMethod     () const;

    CDraft::ErrorStatus   setColor        (const CAXA::UInt32 color);
    CAXA::UInt32       color           () const;   

    CDraft::ErrorStatus   setColorIndex   (const CAXA::Int16 colorIndex);
    CAXA::Int16        colorIndex      () const;

    CDraft::ErrorStatus   setLayerIndex   (const CAXA::Int16 layerIndex);
    CAXA::Int16        layerIndex      () const;   

    CDraft::ErrorStatus   setPenIndex     (const CAXA::UInt16 penIndex);
    CAXA::UInt16       penIndex        () const;   

    // Set/get RGB components
    CDraft::ErrorStatus   setRGB  (const CAXA::UInt8 red, 
                                 const CAXA::UInt8 green, 
                                 const CAXA::UInt8 blue);
    CDraft::ErrorStatus   setRed  (const CAXA::UInt8 red);
    CDraft::ErrorStatus   setGreen(const CAXA::UInt8 green);
    CDraft::ErrorStatus   setBlue (const CAXA::UInt8 blue);
    CAXA::UInt8        red     () const;
    CAXA::UInt8        green   () const;
    CAXA::UInt8        blue    () const;

    // Method check
    bool                isByColor   () const;
    bool                isByLayer   () const;
    bool                isByBlock   () const;
    bool                isByACI     ()   const;
    bool                isByPen     ()  const;
    bool                isForeground() const;
    bool                isLayerOff  () const;
    // Run time states.
    bool                isLayerFrozen() const;
    bool                isNone      ()   const;
    bool                isLayerFrozenOrOff() const;

    // conversion
    CAXA::UInt32       trueColor () const;
    CAXA::UInt8        trueColorMethod () const;
    CDraft::ErrorStatus   setTrueColor ();
    CDraft::ErrorStatus   setTrueColorMethod ();



    // static methods for reuse in other classes.
    static  CDraft::ErrorStatus   setColorMethod(RGBM* rgbm, const ColorMethod eColorMethod);
    static  ColorMethod         colorMethod   (const RGBM* rgbm);

    static  CDraft::ErrorStatus   setColor      (RGBM* rgbm, const CAXA::UInt32 color);
    static  CAXA::UInt32       color         (const RGBM* rgbm);   

    static  CDraft::ErrorStatus   setColorIndex (RGBM* rgbm, const CAXA::Int16 colorIndex);
    static  CAXA::Int16        colorIndex    (const RGBM* rgbm);

    static  CDraft::ErrorStatus   setLayerIndex (RGBM* rgbm, const CAXA::Int16 layerIndex);
    static  CAXA::Int16        layerIndex    (const RGBM* rgbm);   

    static  CDraft::ErrorStatus   setPenIndex   (RGBM* rgbm, const CAXA::UInt16 penIndex);
    static  CAXA::UInt16       penIndex      (const RGBM* rgbm);   

    // Set/get RGB components
    static CDraft::ErrorStatus    setRGB  (RGBM* rgbm,
                                         const CAXA::UInt8 red, 
                                         const CAXA::UInt8 green, 
                                         const CAXA::UInt8 blue);
    static CDraft::ErrorStatus    setRed  (RGBM* rgbm, const CAXA::UInt8 red);
    static CDraft::ErrorStatus    setGreen(RGBM* rgbm, const CAXA::UInt8 green);
    static CDraft::ErrorStatus    setBlue (RGBM* rgbm, const CAXA::UInt8 blue);
    static CAXA::UInt8         red     (const RGBM* rgbm);
    static CAXA::UInt8         green   (const RGBM* rgbm);
    static CAXA::UInt8         blue    (const RGBM* rgbm);

    // Method check
    static  bool                isByColor   (const RGBM* rgbm);
    static  bool                isByLayer   (const RGBM* rgbm);
    static  bool                isByBlock   (const RGBM* rgbm);
    static  bool                isByACI     (const RGBM* rgbm);
    static  bool                isByPen     (const RGBM* rgbm);
    static  bool                isForeground(const RGBM* rgbm);
    static  bool                isLayerOff  (const RGBM* rgbm);
    // Run time states.
    static  bool                isLayerFrozen(const RGBM* rgbm);
    static  bool                isNone      (const RGBM* rgbm);



    // Look up mapping between ACI and RGB.
    static CAXA::UInt32        trueColor       (const RGBM* rgbm);
    static CAXA::UInt8         trueColorMethod (const CAXA::Int16);
    static CDraft::ErrorStatus    setTrueColor    (RGBM* rgbm);
    static CDraft::ErrorStatus    setTrueColorMethod (RGBM* rgbm);

    static CAXA::UInt32        lookUpRGB       (const CAXA::UInt8 colorIndex);
    static CAXA::UInt8         lookUpACI       (const CAXA::UInt8 red,
                                                 const CAXA::UInt8 green,
                                                 const CAXA::UInt8 blue); 

protected:
    CDraft::ErrorStatus           setIndirect (const CAXA::Int16 Indirect);
    CAXA::Int16                indirect() const;   
    RGBM mRGBM;

public:
    // The Look Up Table (LUT) provides a mapping between ACI and RGB 
    // and contains each ACI's representation in RGB.
    static const CAXA::UInt8 mLUT[256][3]; 
};

// AcCmEntityColor inline
//

// Default color method is kByColor.
inline 
CRxCmEntityColor::CRxCmEntityColor()
{
    mRGBM.whole = 0;
    mRGBM.colorMethod = kByColor;
}

inline
CRxCmEntityColor::CRxCmEntityColor (const CRxCmEntityColor & color)
{
    mRGBM.whole = color.mRGBM.whole;
}


// parameter:   eColorMethod    Color method information (byBlock, byLayer, byColor).
inline 
CRxCmEntityColor::CRxCmEntityColor(const ColorMethod eColorMethod)
{
    mRGBM.whole = 0;
    mRGBM.colorMethod = static_cast<CAXA::UInt8>(eColorMethod);
}

// Default color method is kByColor.
// parameter:   red, green, blue
inline  
CRxCmEntityColor::CRxCmEntityColor(const CAXA::UInt8 red, 
                                 const CAXA::UInt8 green, 
                                 const CAXA::UInt8 blue)
{
    mRGBM.red   = red;
    mRGBM.green = green;
    mRGBM.blue  = blue;
    mRGBM.colorMethod = kByColor;
}

inline CRxCmEntityColor& 
CRxCmEntityColor::operator= (const CRxCmEntityColor & color)
{
    mRGBM.whole = color.mRGBM.whole;
    return *this;
}

inline bool
CRxCmEntityColor::operator==(const CRxCmEntityColor& color) const
{
    return mRGBM.whole == color.mRGBM.whole;
}

inline bool
CRxCmEntityColor::operator!=(const CRxCmEntityColor& color) const
{
    return mRGBM.whole != color.mRGBM.whole;
}

// get Color Method
inline CRxCmEntityColor::ColorMethod     
CRxCmEntityColor::colorMethod() const
{
    return (ColorMethod) mRGBM.colorMethod;
}

// get RGB
//
// return value:    Depending on color method (fourth byte):
//                  kByLayer:   Layer index in first and second byte.
//                  kByColor:   RGB and color method.
//                              First byte blue, second byte green and third byte red.
//                              Fourth byte is color method.
//
//                  kByACI:     ACI index in first and second byte.
//
//                  kByBlock,   
//                  kForeground: Only color method (fourth byte) is valid.    
inline CAXA::UInt32    
CRxCmEntityColor::color () const
{
    return mRGBM.whole;
}

// return value:    Layer index.
inline CAXA::Int16
CRxCmEntityColor::layerIndex () const
{
    assert (mRGBM.colorMethod == kByLayer ||
            mRGBM.colorMethod == kLayerOff); 

    return mRGBM.indirect;
}

// return value:    Layer index.
inline CAXA::UInt16
CRxCmEntityColor::penIndex () const
{
    return (CAXA::UInt16) mRGBM.indirect;
}

// get red
inline CAXA::UInt8    
CRxCmEntityColor::red  () const
{
    return mRGBM.red;
}

// get green
inline CAXA::UInt8
CRxCmEntityColor::green() const
{
    return mRGBM.green;
}

// get blue
inline CAXA::UInt8    
CRxCmEntityColor::blue () const
{
    return mRGBM.blue;
}

inline bool
CRxCmEntityColor::isByColor() const
{
    return mRGBM.colorMethod == kByColor; 
}

inline bool
CRxCmEntityColor::isByLayer() const
{
    return (mRGBM.colorMethod  == kByLayer ||
            (mRGBM.colorMethod == kByACI   && 
             mRGBM.indirect    == kACIbyLayer)) ? true : false;    
}

inline bool
CRxCmEntityColor::isByBlock() const
{
    return (mRGBM.colorMethod  == kByBlock ||
            (mRGBM.colorMethod == kByACI   && 
             mRGBM.indirect    == kACIbyBlock)) ? true : false;    
}

inline bool
CRxCmEntityColor::isByACI()   const
{
    return mRGBM.colorMethod == kByACI;
}

inline bool
CRxCmEntityColor::isByPen()   const
{
    return mRGBM.colorMethod == kByPen;
}

inline bool
CRxCmEntityColor::isForeground()   const
{
    return (mRGBM.colorMethod  == kForeground ||
            (mRGBM.colorMethod == kByACI      && 
             mRGBM.indirect    == kACIforeground)) ? true : false;    
}

inline bool
CRxCmEntityColor::isLayerOff() const
{   
    return (mRGBM.colorMethod  == kLayerOff ||
            (mRGBM.colorMethod == kByACI && 
             mRGBM.indirect    <  0      && // layer off for ACI is negative
             mRGBM.indirect    != kACIfrozenLayer)) ? true : false;    
}

inline bool
CRxCmEntityColor::isLayerFrozen() const
{   
    return (mRGBM.colorMethod  == kLayerFrozen ||
            (mRGBM.colorMethod == kByACI       && 
             mRGBM.indirect    == kACIfrozenLayer)) ? true : false;    
}

inline bool
CRxCmEntityColor::isLayerFrozenOrOff() const
{
    return isLayerFrozen() || isLayerOff();
}

inline bool
CRxCmEntityColor::isNone()   const
{
    return (mRGBM.colorMethod  == kNone ||
            (mRGBM.colorMethod == kByACI       && 
             mRGBM.indirect    == kACInone)) ? true : false;    
}

// get indirect
//
// return value:    Indirect can be used for layer index and others.
inline CAXA::Int16    
CRxCmEntityColor::indirect () const
{
    assert (mRGBM.colorMethod != kByColor); 
    return mRGBM.indirect;
}

// set indirect
// 
// parameter:   Indirect can be used for layer index and others.
inline CDraft::ErrorStatus             
CRxCmEntityColor::setIndirect  (const CAXA::Int16 Indirect)
{
    assert (mRGBM.colorMethod != kByColor); 
    mRGBM.indirect = Indirect;
    return CDraft::eOk;
}

#pragma pack (pop)


class CRXDB_API CRxCmColorBase
{
public:

    virtual ~CRxCmColorBase() {}

    virtual CRxCmEntityColor::ColorMethod  colorMethod() const = 0;;
    virtual CDraft::ErrorStatus   setColorMethod(CRxCmEntityColor::ColorMethod eColorMethod) = 0;

    virtual bool                isByColor() const = 0;
    virtual bool                isByLayer() const = 0;
    virtual bool                isByBlock() const = 0;
    virtual bool                isByACI()   const = 0;
    virtual bool                isByPen () const = 0;
    virtual bool                isForeground()   const = 0;

    virtual CAXA::UInt32       color() const = 0;
    virtual CDraft::ErrorStatus   setColor(CAXA::UInt32 color) = 0;

    virtual CDraft::ErrorStatus   setRGB  (CAXA::UInt8 red, 
                                         CAXA::UInt8 green, 
                                         CAXA::UInt8 blue) = 0;
    virtual CDraft::ErrorStatus   setRed  (CAXA::UInt8 red) = 0;
    virtual CDraft::ErrorStatus   setGreen(CAXA::UInt8 green) = 0;
    virtual CDraft::ErrorStatus   setBlue (CAXA::UInt8 blue) = 0;
    virtual CAXA::UInt8        red  () const = 0;
    virtual CAXA::UInt8        green() const = 0;
    virtual CAXA::UInt8        blue () const = 0;

    //virtual CAXA::UInt16       colorIndex() const = 0;
    //virtual CDraft::ErrorStatus   setColorIndex(CAXA::UInt16 colorIndex) = 0;
    //virtual CAXA::UInt16       penIndex() const = 0;
    //virtual CDraft::ErrorStatus   setPenIndex (CAXA::UInt16 penIndex) = 0;

    //virtual CDraft::ErrorStatus   setNames(const CxCHAR *colorName,
    //                                     const CxCHAR *bookName = NULL) = 0;
    //virtual const CxCHAR *       colorName(void) const = 0;
    //virtual const CxCHAR *       bookName(void) const = 0;
    //virtual const CxCHAR *       colorNameForDisplay(void) = 0;
    //virtual bool                hasColorName(void) const = 0;
    //virtual bool                hasBookName(void) const = 0;

};


class CRxCmTransparency {
public:

    enum transparencyMethod {
                kByLayer = 0,
                kByBlock,
                kByAlpha,


                kErrorValue     // must be last in enum
            };

    // Some Transparency constants
    enum {  kTransparencyByLayer    = (unsigned long)kByLayer,
            kTransparencyByBlock    = (unsigned long)kByBlock,
            kTransparencySolid      = ((unsigned long)(kByAlpha | (0xff << 24))),
            kTransparencyClear      = (unsigned long)kByAlpha
    };

    CRxCmTransparency() { mAM.method = kByLayer; }
    CRxCmTransparency(const CRxCmTransparency& other) { mAM.whole = other.mAM.whole; }
    ~CRxCmTransparency() {}

    CRxCmTransparency& operator=(const CRxCmTransparency& other);
    bool operator==(const CRxCmTransparency& other) const;
    bool operator!=(const CRxCmTransparency& other) const;

    void setAlpha(CAXA::UInt8 alpha);
    void setMethod(transparencyMethod method);

    CAXA::UInt8 alpha(void) const;
    bool isByAlpha(void) const { return (mAM.method == kByAlpha); }
    bool isByBlock(void) const { return (mAM.method == kByBlock); }
    bool isByLayer(void) const { return (mAM.method == kByLayer); }
    bool isClear(void) const;
    bool isSolid(void) const;

    CAXA::UInt32   serializeOut(void) const { return mAM.whole; }
    void            serializeIn(CAXA::UInt32);

private: 

    union AM {
        struct {
            CAXA::UInt8    alpha;          // low byte
            CAXA::UInt8    reserved1;    
            CAXA::UInt8    reserved2;
            CAXA::UInt8    method;         // high byte
        };
        CAXA::UInt32       whole;
    };

    AM mAM;
};


class CRxCmDialogColor : public CRxCmColorBase
{
public:

    CRxCmDialogColor();
    CRxCmDialogColor(const CRxCmDialogColor& other);
    CRxCmDialogColor(const CRxCmColorBase& other);
    virtual ~CRxCmDialogColor();

    CRxCmDialogColor& operator=(const CRxCmDialogColor& inputColor);
    CRxCmDialogColor& operator=(const CRxCmColorBase& inputColor);

    bool operator ==(const CRxCmDialogColor& color) const;
    bool operator !=(const CRxCmDialogColor& color) const;
    bool operator ==(const CRxCmColorBase& color) const;
    bool operator !=(const CRxCmColorBase& color) const;

    virtual CRxCmEntityColor::ColorMethod  colorMethod() const;
    virtual CDraft::ErrorStatus   setColorMethod(CRxCmEntityColor::ColorMethod eColorMethod);

    virtual bool                isByColor() const;
    virtual bool                isByLayer() const;
    virtual bool                isByBlock() const;
    virtual bool                isByACI() const;
    virtual bool                isByPen () const;
    virtual bool                isForeground() const;

    virtual CAXA::UInt32       color() const;
    virtual CDraft::ErrorStatus   setColor(CAXA::UInt32 color);

    virtual CDraft::ErrorStatus   setRGB  (CAXA::UInt8 red, 
                                         CAXA::UInt8 green, 
                                         CAXA::UInt8 blue);
    virtual CDraft::ErrorStatus   setRed  (CAXA::UInt8 red);
    virtual CDraft::ErrorStatus   setGreen(CAXA::UInt8 green);
    virtual CDraft::ErrorStatus   setBlue (CAXA::UInt8 blue);
    virtual CAXA::UInt8        red  () const;
    virtual CAXA::UInt8        green() const;
    virtual CAXA::UInt8        blue () const;

    virtual CAXA::UInt16       colorIndex() const;
    virtual CDraft::ErrorStatus   setColorIndex(CAXA::UInt16 colorIndex);
    virtual CAXA::UInt16       penIndex() const;
    virtual CDraft::ErrorStatus   setPenIndex (CAXA::UInt16 penIndex);

    virtual CDraft::ErrorStatus   setNames(const CxCHAR *colorName,
                                         const CxCHAR *bookName = NULL);
    virtual const CxCHAR *       colorName(void) const;
    virtual const CxCHAR *       bookName(void) const;
    virtual const CxCHAR *       colorNameForDisplay(void);
    virtual bool                hasColorName(void) const;
    virtual bool                hasBookName(void) const;


private:

    enum NameFlags {    kNoNames            = 0x00,
                        kHasColorName       = 0x01,
                        kHasBookName        = 0x02
                    };

    CRxCmEntityColor::RGBM   mRGBM;
    CxCHAR *                 mColorName;
    CxCHAR *                 mBookName;
    CAXA::UInt8            mNameFlags;
};

namespace CRxCm
{
    enum DialogTabs
    {   
        //these flags can be OR-ed 
        kACITab = 1,
        kTrueColorTab = 2,
        kColorBookTab = 4,
    };

    enum ACIColors
    {   
        kACIByBlock     = 0,
        kACIRed         = 1,
        kACIYellow      = 2,
        kACIGreen       = 3,
        kACICyan        = 4,
        kACIBlue        = 5,
        kACIMagenta     = 6,
        kACIForeground  = 7,
        kACIByLayer     = 256,
    };
}



#endif // CRX_DBCOLOR_H 
