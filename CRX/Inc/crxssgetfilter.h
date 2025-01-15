//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#ifndef _SSGETFILTER_H
#define _SSGETFILTER_H


class CRxApDocument;


class CRxEdSelectionSetService
{
public:

    virtual CDraft::ErrorStatus ssNameX(
        bool bIsSubSelectionIndex,
        int index,
        resbuf*& result) = 0;
    
    virtual CDraft::ErrorStatus ssNameSubentityX(
        bool bIsSubSelectionIndex,
        int index,
        int subentityIndex,
        resbuf*& result) = 0;

    virtual CDraft::ErrorStatus ssNameSubentities(
        bool bIsSubSelectionIndex,
        int index,
        CRxDbFullSubentPathArray& subEntities) = 0;
        
    virtual CDraft::ErrorStatus add(
        resbuf *ssnameXList,
        const CRxDbFullSubentPath *pPath = NULL,
        const CRxDbObjectId* pEntselSubent = NULL) = 0;

    virtual CDraft::ErrorStatus addSubentity(
        resbuf *ssnameXList,
        const CRxDbFullSubentPath& subEntity) = 0;

    virtual CDraft::ErrorStatus remove(
        int index) = 0;

    virtual CDraft::ErrorStatus removeSubentity(
        int entityIndex,
        int subEntityIndex) = 0; 

    virtual CDraft::ErrorStatus highlight(
        int subSelectionIndex,
        const CRxDbFullSubentPath& path) = 0;

    virtual int subSelectionMode() = 0;

    virtual CDraft::ErrorStatus getSubSelectionPoints(
        CRxGePoint3dArray& points) = 0;

    virtual CDraft::ErrorStatus add(
        const CRxArray<resbuf *>& ssnameXList,
        const CRxArray<CRxDbFullSubentPath *> *pPath,
        bool bAddsAreUnique) = 0;

    virtual CDraft::ErrorStatus addSubentities(
        resbuf * ssnameXList,
        const CRxArray<CRxDbFullSubentPath>& subEntities,
        bool bAddsAreUnique) = 0;

    virtual CDraft::ErrorStatus remove(
        const CRxArray<int>& indices) = 0;

    virtual CDraft::ErrorStatus removeSubentities(
        int entityIndex,
        const CRxArray<int>& subEntityIndices) = 0;
};

typedef CRxArray<CRxDbIntArray, CRxArrayObjectCopyReallocator<CRxDbIntArray> > 
    CRxDbArrayIntArray;

class CRxEdSSGetFilter: public CRxEdInputContextReactor
{
public:

    virtual void
    ssgetAddFilter(
        int ssgetFlags,
        CRxEdSelectionSetService &service,
        const CRxDbObjectIdArray& selectionSet,
        const CRxDbObjectIdArray& subSelectionSet)
    {  }

    virtual void
    ssgetRemoveFilter(
        int ssgetFlags,
        CRxEdSelectionSetService &service,
        const CRxDbObjectIdArray& selectionSet,
        const CRxDbObjectIdArray& subSelectionSet,
        CRxDbIntArray& removeIndexes,
        CRxDbArrayIntArray& removeSubentIndexes)
    {  }

    virtual void
    ssgetAddFailed(
        int ssgetFlags,
        int ssgetMode,
        CRxEdSelectionSetService &service,
        const CRxDbObjectIdArray& selectionSet,
        resbuf *rbPoints)
    {  }

    virtual void
    ssgetRemoveFailed(
        int ssgetFlags,
        int ssgetMode,
        CRxEdSelectionSetService &service,
        const CRxDbObjectIdArray& selectionSet,
        resbuf *rbPoints,
        CRxDbIntArray& removeIndexes,
        CRxDbArrayIntArray& removeSubentIndexes)
    {  }

    virtual void
    endSSGet(
        CDraft::PromptStatus returnStatus,
        int ssgetFlags,
        CRxEdSelectionSetService &service,
        const CRxDbObjectIdArray& selectionSet)
    {  }

    virtual void
    endEntsel(
        CDraft::PromptStatus       returnStatus,
        const CRxDbObjectId&      pickedEntity,
        const CRxGePoint3d&       pickedPoint,
        CRxEdSelectionSetService& service)
    { } 
};


CDraft::ErrorStatus addSSgetFilterInputContextReactor(
                       CRxApDocument *pDoc, CRxEdSSGetFilter *pFilter);

CDraft::ErrorStatus removeSSgetFilterInputContextReactor(
                        CRxApDocument *pDoc, CRxEdSSGetFilter *pFilter);

CDraft::ErrorStatus setAllowDuplicateSelection(
                        CRxApDocument *pDoc, boolean flag);

bool              duplicateSelectionsAllowed(CRxApDocument *pDoc);


namespace CRxEdSSGet {

enum CRxEdSSGetFlags {
    kNormal         =   0,
    kPickPoints     =   1,
    kDuplicates     =   2,
    kNestedEntities =   4,
    kSubEntities    =   8,
    kSinglePick     =  16,
    kPickfirstSet   =  32,
    kPreviousSet    =  64,
    kSubSelection   = 128,
    kUndo           = 256,
    kFailedPickAuto = 512
};

enum CRxEdSSGetModes {
    kWin = 1,   //  (Window spec)
    kCross,     //  (Crossing spec)
    kBox,       //  (Box spec)
    kLast,      //  (Last)
    kEntity,    //  (Explicit entity name)
    kAll,       //  (Select all)
    kFence,     //  (Fence Selection)
    kCPoly,     //  (Crossing Poly)
    kWPoly,     //  (Window Poly)
    kPick,      //  (Single pick)
    kEvery,     //  (every entity on single pick)
    kXten,      //  (ssget "X")
    kGroup,     //  (selection set from "group" specification)
    kPrevious   //  (previous selectionset)
};

};

class CRxEdSSGetFilter2 : public CRxEdSSGetFilter
{
public:

    virtual void
    ssgetRolloverFilter(
        const CRxDbFullSubentPath &subEntityPath, 
        CRxDbFullSubentPath &highlightPath)
    {  }
};

CDraft::ErrorStatus addSSgetFilterInputContextReactor(
                        CRxApDocument *pDoc, CRxEdSSGetFilter2 *pFilter);

CDraft::ErrorStatus removeSSgetFilterInputContextReactor(
                        CRxApDocument *pDoc, CRxEdSSGetFilter2 *pFilter);

class CrxEdSSGetFilter3 : public CRxEdSSGetFilter
{
public:

    virtual void
    ssgetRolloverFilter(
        const CRxDbFullSubentPath &subEntityPath, 
        CRxDbFullSubentPathArray &highlightPaths)
    {  }
};

CDraft::ErrorStatus addSSgetFilterInputContextReactor(
    CRxApDocument *pDoc, CrxEdSSGetFilter3 *pFilter);
CDraft::ErrorStatus removeSSgetFilterInputContextReactor(
    CRxApDocument *pDoc, CrxEdSSGetFilter3 *pFilter);


class CRxEdSSGetFilter4 : public CRxEdSSGetFilter
{
public:
   virtual void
    endNEntsel(
        CDraft::PromptStatus       returnStatus,
        const CRxDbObjectId&      pickedEntity,
        const CRxGePoint3d&       pickedPoint,
        crx_point                xformres[4], 
        struct resbuf **         refstkres,
        CRxEdSelectionSetService& service)
    { }

   virtual void beginSSGetCustomKeywordCallback(const CxCHAR* pKeyword) {};
   virtual void endSSGetCustomKeywordCallback(const CxCHAR* pKeyword) {};

};

CDraft::ErrorStatus addSSgetFilterInputContextReactor(
    CRxApDocument *pDoc, CRxEdSSGetFilter4 *pFilter);
CDraft::ErrorStatus removeSSgetFilterInputContextReactor(
    CRxApDocument *pDoc, CRxEdSSGetFilter4 *pFilter);


class CRxEdSubSelectFilterService
{
public:

    virtual CDraft::ErrorStatus ssNameX(
        bool bIsSubSelectionIndex,
        int index,
        resbuf*& result) = 0;
    
    virtual CDraft::ErrorStatus add(
        resbuf *ssnameXList,
        const CRxDbFullSubentPath& path) = 0;

    virtual CDraft::ErrorStatus remove(
        bool bIsSubSelectionIndex,
        int index) = 0;
};

class CRxEdSSGetSubSelectFilter : public CRxEdInputContextReactor
{
public:

    virtual CDraft::ErrorStatus 
        getSubentPathsAtGsMarker(
            CRxDbEntity*                    pEnt, 
            bool                           bAdding,
            const CRxDbFullSubentPathArray& selectedPaths,
            CRxDb::SubentType               type,
            CAXA::GsMarker                gsMark, 
            const CRxGePoint3d&             pickPoint,
            const CRxGeMatrix3d&            viewXForm,
            int&                           numPaths,
            CRxDbFullSubentPath*&           subentPaths,
            int                            numInserts,
            CRxDbObjectId*                  entAndInsertStack) = 0;
    
    virtual CDraft::ErrorStatus 
        subSelectClassList(CRxArray<CRxClass*>& classes) = 0;

    virtual void
        ssgetAddFilter(
            int                            ssgetFlags,
            CRxEdSubSelectFilterService&    service,
            const CRxDbObjectId&            object,
            const CRxDbFullSubentPathArray& selectedPaths,
            const CRxDbFullSubentPathArray& addedPaths) = 0;

    virtual void
        ssgetRemoveFilter(
            int                            ssgetFlags, 
            CRxEdSubSelectFilterService&    service,
            const CRxDbObjectId&            object,
            const CRxDbFullSubentPathArray& selectedPaths,
            const CRxDbFullSubentPathArray& removedPaths) = 0;
};

CDraft::ErrorStatus addSSgetFilterInputContextReactor(
                        CRxApDocument             *pDoc, 
                        CRxEdSSGetSubSelectFilter *pFilter);

CDraft::ErrorStatus removeSSgetFilterInputContextReactor(
                        CRxApDocument             *pDoc, 
                        CRxEdSSGetSubSelectFilter *pFilter);

#endif  // _SSGETFILTER_H

