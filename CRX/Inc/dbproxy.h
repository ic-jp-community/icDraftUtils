#ifndef CRX_DBPROXY_H
#define CRX_DBPROXY_H 1
//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#include "dbmain.h"
#include <dbintar.h>

#pragma pack (push, 8)

class ADESK_NO_VTABLE CRxDbProxyObject : public CRxDbObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbProxyObject);
    
    virtual ~AcDbProxyObject() {};
    
    virtual int   proxyFlags() const = 0;
    virtual const ACHAR * originalClassName() const = 0;
    virtual const ACHAR * originalDxfName() const = 0;
    virtual const ACHAR * applicationDescription() const = 0;
    virtual Acad::ErrorStatus getReferences(AcDbObjectIdArray&,
        AcDbIntArray&) const = 0;

    virtual AcDb::DuplicateRecordCloning mergeStyle() const = 0;

    enum {kNoOperation          = 0,
          kEraseAllowed         = 0x01,
          kCloningAllowed       = 0x80,
          kAllButCloningAllowed = 0x01,
          kAllAllowedBits       = 0x81,
          kMergeIgnore          = 0,      // Keep existing (= default)
          kMergeReplace         = 0x100,  // Use clone
          kMergeMangleName      = 0x200,  // anonymous name
          kDisableProxyWarning  = 0x400
           };
};

class ADESK_NO_VTABLE CRxDbProxyEntity : public CRxDbEntity
{
public:
    ACRX_DECLARE_MEMBERS(AcDbProxyEntity);
    
    virtual ~AcDbProxyEntity() {};
    
    virtual int   proxyFlags() const = 0;
    virtual const ACHAR * originalClassName() const = 0;
    virtual const ACHAR * originalDxfName() const = 0;
    virtual const ACHAR * applicationDescription() const = 0;
    virtual Acad::ErrorStatus getReferences(AcDbObjectIdArray&,
        AcDbIntArray&) const = 0;

    enum GraphicsMetafileType {
        kNoMetafile   = 0,
        kBoundingBox  = 1,
        kFullGraphics = 2 };

    virtual AcDbProxyEntity::GraphicsMetafileType graphicsMetafileType()
        const = 0;

    virtual Acad::ErrorStatus   explode(AcDbVoidPtrArray& entitySet) const;
    virtual Acad::ErrorStatus   transformBy(const AcGeMatrix3d& xform);
    virtual Acad::ErrorStatus   getGeomExtents(AcDbExtents& extents) const;

    enum  {kNoOperation                = 0,
           kEraseAllowed               = 0x1,
           kTransformAllowed           = 0x2,
           kColorChangeAllowed         = 0x4,
           kLayerChangeAllowed         = 0x8,
           kLinetypeChangeAllowed      = 0x10,
           kLinetypeScaleChangeAllowed = 0x20,
           kVisibilityChangeAllowed    = 0x40,
           kCloningAllowed             = 0x80,
           kLineWeightChangeAllowed    = 0x100,
           kPlotStyleNameChangeAllowed = 0x200,
           kAllButCloningAllowed       = 0x37F,
           kAllAllowedBits             = 0xBFF,
           kDisableProxyWarning        = 0x400,
           kMaterialChangeAllowed      = 0x800,
            };
};

#pragma pack (pop)

#endif // CRX_DBPROXY_H
