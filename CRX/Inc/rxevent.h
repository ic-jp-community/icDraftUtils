#ifndef   _CRX_EVENT_H__
#define   _CRX_EVENT_H__
//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//


#include "crxArray.h"
#include "rxobject.h"
#include "crxChar.h"
#include "CrxEdApiCx.h"
#pragma pack (push, 8)

#define CRX_EVENT_OBJ CRX_T("CRxEvent")

class CRxDbDatabase;
class CRxGeMatrix3d;
class CRxDbIdMapping;
class CRxGePoint3d;
class CRxDbObjectId;
    
enum CRxXrefSubCommand {
    kAttach = 0,
    kBind = 1,
    kDetach = 2,
    kOverlay = 3,
    kPath = 4,
    kReload = 5,
    kResolve = 6,
    kUnload = 7,
    kXBind = 8
};

CRX_DEFINE_NULL_CLSID(CRxEventReactor)
class CRXEDAPI_CLASS CRxEventReactor: public CRxObject 
{ 
public:

    CRX_DECLARE_DYNAMIC(CRxEventReactor);

    // DWG/Save Events.
    //
    virtual void dwgFileOpened(CRxDbDatabase*, CxCHAR * fileName);
    virtual void initialDwgFileOpenComplete(CRxDbDatabase*);
    virtual void databaseConstructed(CRxDbDatabase*);
    virtual void databaseToBeDestroyed(CRxDbDatabase*);

    virtual void beginSave    (CRxDbDatabase*, const CxCHAR * pIntendedName);
    virtual void saveComplete (CRxDbDatabase*, const CxCHAR * pActualName);
    virtual void abortSave    (CRxDbDatabase*);

    // DXF In/Out Events.
    //
    virtual void beginDxfIn      (CRxDbDatabase*);
    virtual void abortDxfIn      (CRxDbDatabase*);
    virtual void dxfInComplete   (CRxDbDatabase*);
    //
    virtual void beginDxfOut     (CRxDbDatabase*);
    virtual void abortDxfOut     (CRxDbDatabase*);
    virtual void dxfOutComplete  (CRxDbDatabase*);
    
    // Insert Events.
    //
    virtual void beginInsert(CRxDbDatabase* pTo, const CxCHAR * pBlockName,
                             CRxDbDatabase* pFrom);
    virtual void beginInsert(CRxDbDatabase* pTo, const CRxGeMatrix3d& xform,
                             CRxDbDatabase* pFrom);
    virtual void otherInsert(CRxDbDatabase* pTo, CRxDbIdMapping& idMap,
                             CRxDbDatabase* pFrom);
    virtual void abortInsert(CRxDbDatabase* pTo);
    virtual void endInsert  (CRxDbDatabase* pTo);

    // Wblock Events.
    //
    virtual void wblockNotice(CRxDbDatabase* pDb);
    virtual void beginWblock(CRxDbDatabase* pTo, CRxDbDatabase* pFrom,
                             const CRxGePoint3d*& insertionPoint);
    virtual void beginWblock(CRxDbDatabase* pTo, CRxDbDatabase* pFrom,
                             CRxDbObjectId blockId);
    virtual void beginWblock(CRxDbDatabase* pTo, CRxDbDatabase* pFrom); 
    virtual void otherWblock(CRxDbDatabase* pTo, CRxDbIdMapping&,
                             CRxDbDatabase* pFrom);
    virtual void abortWblock(CRxDbDatabase* pTo);
    virtual void endWblock  (CRxDbDatabase* pTo);
    virtual void beginWblockObjects(CRxDbDatabase*, CRxDbIdMapping&);

    // Deep Clone Events.
    //
    virtual void beginDeepClone       (CRxDbDatabase* pTo, CRxDbIdMapping&);
    virtual void beginDeepCloneXlation(CRxDbIdMapping&, CDraft::ErrorStatus*);
    virtual void abortDeepClone       (CRxDbIdMapping&);
    virtual void endDeepClone         (CRxDbIdMapping&);

    // Partial Open Events.
    //
    virtual void partialOpenNotice  (CRxDbDatabase* pDb);

    // XREF-related Events
    //
    virtual void beginAttach (CRxDbDatabase* pTo, const CxCHAR *,
                              CRxDbDatabase* pFrom);
    virtual void otherAttach (CRxDbDatabase* pTo, CRxDbDatabase* pFrom);
    virtual void abortAttach (CRxDbDatabase* pFrom);
    virtual void endAttach   (CRxDbDatabase* pTo);
    virtual void redirected  (CRxDbObjectId  newId, CRxDbObjectId oldId);
    virtual void comandeered (CRxDbDatabase* pTo, CRxDbObjectId id,
                              CRxDbDatabase* pFrom);
    virtual void beginRestore(CRxDbDatabase* pTo, const CxCHAR *,
                              CRxDbDatabase* pFrom);
    virtual void abortRestore(CRxDbDatabase* pTo);
    virtual void endRestore  (CRxDbDatabase* pTo);

    virtual void xrefSubCommandStart(CRxDbDatabase* pHostDb,
            CRxXrefSubCommand op, const CRxArray<CRxDbObjectId>& ids,
            const CxCHAR* const* btrNames, 
            const CxCHAR* const* paths, bool& vetoOp); 

    virtual void xrefSubCommandAborted(CRxDbDatabase* pHostDb,
            CRxXrefSubCommand op, const CRxArray<CRxDbObjectId>& ids,
            const CxCHAR* const* btrNames, 
            const CxCHAR* const* paths); 

    virtual void preXrefLockFile(CRxDbDatabase* pDb,
            CRxDbObjectId btrId);
};

#define crxEvent CRxEvent::cast(crxSysRegistry()->at(CRX_EVENT_OBJ))

CRX_DEFINE_NULL_CLSID(CRxEvent)
class CRXEDAPI_CLASS CRxEvent: public CRxObject 
{ 
public:
    CRX_DECLARE_DYNAMIC(CRxEvent);
    virtual void addReactor   (CRxEventReactor * newObj) = 0;
    virtual void removeReactor(CRxEventReactor * delObj) = 0;
};

#pragma pack (pop)
#endif
