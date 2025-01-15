//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//
// CrxGiStyleAttributes interface

#ifndef __CRxGiStyleAttributes_H_Defined__
#define __CRxGiStyleAttributes_H_Defined__

#include "CrxGiLineAttributes.h"

typedef enum {
    kNothing                                = 0x00,
    kColor                                  = 0x01,
    kLine                                   = 0x02,
    kLineType                               = 0x04,
    kPlotStyle                              = 0x08,
    kEverything                             = 0x0F
} CRxGiAttributeFlags; 

class CAXA_NO_VTABLE CRxGiStyleAttributes
{
public:

    // Ctor/dtor/copy
    CRxGiStyleAttributes()   { }
    CRxGiStyleAttributes(const CRxGiStyleAttributes& source);
    virtual ~CRxGiStyleAttributes()  { }

    // Member data access
    // Color
    CRxCmEntityColor& getColorAttribute();
    const CRxCmEntityColor& getColorAttribute() const;
    void setColorAttribute(const CRxCmEntityColor& color);

    // Complex line type
    CRxDbObjectId linetypeObjectId() const;
    void setLinetypeObjectId(const CRxDbObjectId& newId);

    // Plot style
    CRxDbObjectId plotStyleNameId() const;
    void setPlotStyleName(const CRxDbObjectId& newId);

    // Interface methods - Other line attributes
    virtual CRxGiLineAttributes* getLineAttribute()                              = 0;
    virtual const CRxGiLineAttributes* getLineAttribute() const                  = 0;
    virtual void setLineAttribute(const CRxGiLineAttributes* pLineAttributes)    = 0;

    virtual void EnsureColorVisibility (CRxCmEntityColor& color)                 = 0;    

protected:
    /* The style engine will resolve the color, taking into account color
        policy, dither, specified color, assigned pen number, and dimming.
        If m_colorAttribute.isByColor() then use
        getColorAttribute().color();
        if m_colorAttribute.isByPen() then use
        getColorAttribute().penIndex()
    */
    CRxCmEntityColor m_colorAttribute;

    CRxDbObjectId    m_idLinetype;
    CRxDbObjectId    m_idPlotstyle;
};

inline
CRxGiStyleAttributes::CRxGiStyleAttributes(
    const CRxGiStyleAttributes& source) 
{
    m_colorAttribute = source.getColorAttribute();
    m_idLinetype = source.linetypeObjectId();
    m_idPlotstyle = source.plotStyleNameId();
}

inline
CRxCmEntityColor& 
CRxGiStyleAttributes::getColorAttribute()
{ 
    return m_colorAttribute; 
}

inline
const CRxCmEntityColor& 
CRxGiStyleAttributes::getColorAttribute() const
{ 
    return m_colorAttribute; 
}

inline 
void    
CRxGiStyleAttributes::setColorAttribute (
    const CRxCmEntityColor& color) 
{
    m_colorAttribute = color; 
}

inline
CRxDbObjectId
CRxGiStyleAttributes::linetypeObjectId() const
{
    return m_idLinetype;
}

inline
void 
CRxGiStyleAttributes::setLinetypeObjectId(const CRxDbObjectId& newId)
{
    m_idLinetype = newId;
}

inline
CRxDbObjectId
CRxGiStyleAttributes::plotStyleNameId() const
{
    return m_idPlotstyle;
}

inline
void
CRxGiStyleAttributes::setPlotStyleName(const CRxDbObjectId& newId)
{
    m_idPlotstyle = newId;
}

#endif // #ifndef __CrxGiStyleAttributes_H_Defined__