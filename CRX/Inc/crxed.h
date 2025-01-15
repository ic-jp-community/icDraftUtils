//
#ifndef   _CRXED_H
#define   _CRXED_H
//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
#pragma once

#include "cdraft.h"
#include "rxnames.h"
#include "rxevent.h"
#include "CrxEdApiCx.h"
#include "dbptrar.h"
#include "dbidar.h"
#include "dbintar.h"
#include "gept3dar.h"
#include "dbents.h"
#include "dbptrar.h"
#include "gept3dar.h"
#include "dbmain.h"
#include "crxDefine.h"

#pragma pack (push, 8)

struct IDispatch;

/* Name of Registered Service Object for constructing CaxaDraft-specific
   instances.
*/
#define CRXED_EDITOR_OBJ CRX_T("CRxEditor")

class CRxDbDatabase;

CRX_DEFINE_NULL_CLSID(CRxEditorReactor)
class CRXEDAPI_CLASS CRxEditorReactor: public CRxEventReactor 
{ 
public:
    CRX_DECLARE_DYNAMIC(CRxEditorReactor);
    CRxEditorReactor() : mVeto(0) {}

    // Command Events
    //
    virtual void unknownCommand  (const CxCHAR* cmdStr, CRxDbVoidPtrArray *al);
    virtual void commandWillStart(const CxCHAR* cmdStr);
    virtual void commandEnded    (const CxCHAR* cmdStr);
    virtual void commandCancelled(const CxCHAR* cmdStr);
    virtual void commandFailed   (const CxCHAR* cmdStr);
 
    // Lisp Events
    //
    virtual void lispWillStart   (const CxCHAR* firstLine);
    virtual void lispEnded       ();
    virtual void lispCancelled   ();

    CAXA_DEPRECATED virtual void beginClose(CRxDbDatabase* pDwg);

    // DXF In/Out Events.
    //
    virtual void beginDxfIn      (CRxDbDatabase*);
    virtual void abortDxfIn      (CRxDbDatabase*);
    virtual void dxfInComplete   (CRxDbDatabase*);
    //
    virtual void beginDxfOut     (CRxDbDatabase*);
    virtual void abortDxfOut     (CRxDbDatabase*);
    virtual void dxfOutComplete  (CRxDbDatabase*);

    // DWG Open Events.
    //
    virtual void beginDwgOpen    (CxCHAR* filename);
    virtual void endDwgOpen      (const CxCHAR* filename, CRxDbDatabase* pDb);
    virtual void initialDwgFileOpenComplete(CRxDbDatabase* pDwg);

    // DWG/Save Events.
    //
    virtual void dwgFileOpened(CRxDbDatabase*, CxCHAR* fileName);
    virtual void databaseConstructed(CRxDbDatabase*);
    virtual void databaseToBeDestroyed(CRxDbDatabase*);
    virtual void beginSave    (CRxDbDatabase*, const CxCHAR* pIntendedName);
    virtual void saveComplete (CRxDbDatabase*, const CxCHAR* pActualName);
    virtual void abortSave    (CRxDbDatabase*); 

    // Insert Events.
    //
    virtual void beginInsert(CRxDbDatabase* pTo, const CxCHAR* pBlockName,
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

    // Deep Clone Events.
    //
    virtual void beginDeepClone       (CRxDbDatabase* pTo, CRxDbIdMapping&);
    virtual void beginDeepCloneXlation(CRxDbIdMapping&, CDraft::ErrorStatus*);
    virtual void abortDeepClone       (CRxDbIdMapping&);
    virtual void endDeepClone         (CRxDbIdMapping&);

    // Sys Var Events.
    //
    virtual void sysVarChanged        (const CxCHAR* varName, CAXA::Boolean success);
    virtual void sysVarWillChange     (const CxCHAR* varName);
 
    // XREF-related Events
    //
    virtual void beginAttach (CRxDbDatabase* pTo, const CxCHAR*,
                              CRxDbDatabase* pFrom);
    virtual void otherAttach (CRxDbDatabase* pTo, CRxDbDatabase* pFrom);
    virtual void abortAttach (CRxDbDatabase* pFrom);
    virtual void endAttach   (CRxDbDatabase* pTo);
    virtual void redirected  (CRxDbObjectId  newId, CRxDbObjectId oldId);
    virtual void comandeered (CRxDbDatabase* pTo, CRxDbObjectId id,
                              CRxDbDatabase* pFrom);
    virtual void beginRestore(CRxDbDatabase* pTo, const CxCHAR*,
                              CRxDbDatabase* pFrom);
    virtual void abortRestore(CRxDbDatabase* pTo);
    virtual void endRestore  (CRxDbDatabase* pTo);

    // More XREF related Events
    // 
    virtual void xrefSubcommandBindItem   (CRxDbDatabase* pHost, int activity, CRxDbObjectId blockId);
    virtual void xrefSubcommandAttachItem (CRxDbDatabase* pHost, int activity, const CxCHAR* pPath);
    virtual void xrefSubcommandOverlayItem(CRxDbDatabase* pHost, int activity, const CxCHAR* pPath);
    virtual void xrefSubcommandDetachItem (CRxDbDatabase* pHost, int activity, CRxDbObjectId blockId);
    virtual void xrefSubcommandPathItem   (int activity, CRxDbObjectId blockId, 
                                           const CxCHAR* pNewPath);
    virtual void xrefSubcommandReloadItem (CRxDbDatabase* pHost, int activity, CRxDbObjectId blockId);
    virtual void xrefSubcommandUnloadItem (CRxDbDatabase* pHost, int activity, CRxDbObjectId blockId);

    // UNDO Events 
    //
    virtual void undoSubcommandAuto       (int activity, CAXA::Boolean state);
    virtual void undoSubcommandControl    (int activity, int option);
    virtual void undoSubcommandBegin      (int activity);
    virtual void undoSubcommandEnd        (int activity);
    virtual void undoSubcommandMark       (int activity);
    virtual void undoSubcommandBack       (int activity);
    virtual void undoSubcommandNumber     (int activity, int num);

    virtual void pickfirstModified();
    virtual void layoutSwitched(const CxCHAR* newLayoutName);

    //window messages
    virtual void docFrameMovedOrResized(CAXA::LongPtr hwndDocFrame, bool bMoved);
    virtual void mainFrameMovedOrResized(CAXA::LongPtr hwndMainFrame, bool bMoved);

    //Mouse events
    virtual void beginDoubleClick(const CRxGePoint3d& clickPoint);
    virtual void beginRightClick(const CRxGePoint3d& clickPoint);

    // Toolbar Size changes
    virtual void toolbarBitmapSizeWillChange(CAXA::Boolean bLarge);
    virtual void toolbarBitmapSizeChanged(CAXA::Boolean bLarge);

    // WblockObjects - begin new pFrom database
    virtual void beginWblockObjects (CRxDbDatabase* pFrom, CRxDbIdMapping& );

    // Partial Open Events
    //
    virtual void partialOpenNotice(CRxDbDatabase* pDb);
    virtual void objectsLazyLoaded(const CRxDbObjectIdArray& idArray);

    // Quit Events
    virtual void beginQuit();
    virtual void quitAborted();
    virtual void quitWillStart();

    virtual void modelessOperationWillStart(const CxCHAR* contextStr);
    virtual void modelessOperationEnded(const CxCHAR* contextStr);

    virtual void cmdIUnkModified(const CxCHAR* strCommand);


    /// <summary>
    ///
    ///  Sends notification on the start of an xref subcommand. The xref
    ///  subcommands are the ones in the following enum (crxed.h):
    ///  
    ///     enum AcXrefSubCommand {
    ///                  kAttach,
    ///                  kBind,
    ///                  kDetach,
    ///                  kOverlay,
    ///                  kPath,
    ///                  kReload,
    ///                  kResolve,
    ///                  kUnload,
    ///                  kXBind
    ///     };
    ///
    ///   An application can veto the operation by returning a bad status,
    ///   e.g. CDraft::eVetoed.
    ///
    ///   There are multiple output arguments, based on the subcommand.
    ///   Subcommands like attach have all the arguments provided.
    ///   Subcommands like Bind only supply the btrids.
    ///   
    ///   The rule for checking the output arguments is: Use the BtrIds first.
    ///   The other two arguments may be empty.
    ///   In subcommands like Path - the path in the Block Table Record could
    ///   differ from the one in the paths argument - in which case - both
    ///   could be used.
    ///
    /// </summary>
    ///
    /// <param name="subcmd">
    /// The subcommand which is about to start.
    /// </param>
    ///
    /// <param name="btrIds">
    /// The xref block table record ids. The primary output argument.
    /// </param>
    ///
    /// <param name="btrNames">
    ///  Xref Block Table Record names.
    /// </param>
    ///
    /// <param name="paths">
    /// The path strings for the subcommand, if applicable.
    /// </param>
    ///
    /// <returns>
    /// Returns CDraft::eOk if successful. If the application return an
    /// error status, the subcommand will be vetoed.
    /// </returns>
    ///
    /// <remarks>
    ///  Though the btr names and path arguments seem redundant at times,
    ///  they can help applications avoid open for write/open for read conflicts
    ///  in case the subcommand already has the Block Table Record open.
    /// </remarks>
    ///
    virtual CDraft::ErrorStatus xrefSubCommandStart(
            CRxXrefSubCommand subcmd, 
            const CRxDbObjectIdArray& btrIds,
            const CxCHAR* const * btrNames,
            const CxCHAR* const * paths);


    /// <summary>
    /// Notification just before an Xref is locked via 
    /// AcEdXrefFileLock::lockFile().
    /// </summary>
    ///
    /// <param name = "btrId">
    /// The xref block table record id that is to be locked.
    /// </param>
    ///
    virtual void preXrefLockFile(CRxDbObjectId btrId);

    virtual void viewChanged();

protected:
    CDraft::ErrorStatus veto();

private:
    CAXA::UInt8 mVeto;

friend class CrxEditorImp;
};

CRX_DEFINE_NULL_CLSID(CRxEditorReactor2)
class CRXEDAPI_CLASS CRxEditorReactor2 : public CRxEditorReactor
{
public:
    CRX_DECLARE_DYNAMIC(CRxEditorReactor2);

    // One can call veto() during this notifcation to stop
    // CaxaDraft from shutting down the document
    // This notification is fired *before* the legacy beginClose event
    virtual void beginDocClose(CRxDbDatabase* pExb) {}

    // docCloseAborted is fired to all reactors that received
    // the beginDocClose event when the last reactor vetos the close
    virtual void docCloseAborted(CRxDbDatabase* pExb) {}

    // This notification is fired at the same time as the legacy beginClose event
    virtual void docCloseWillStart(CRxDbDatabase* pExb) {}

    // Layout switch is about to occur
    virtual void layoutToBeSwitched (const CxCHAR *oldLayoutName, const CxCHAR *newLayoutName) {}

    // Drawing area has moved or resized
    virtual void dwgViewResized (CAXA::LongPtr hwndDwgView) {}


};


class CAdUiPathname;

CRX_DEFINE_NULL_CLSID(CRxEditorReactor3)
class CRXEDAPI_CLASS CRxEditorReactor3 : public CRxEditorReactor2
{
public:
    CRX_DECLARE_DYNAMIC(CRxEditorReactor3);

    // triggered at the end of drsubs.cpp, fullregen()
    virtual void fullRegenEnded(CRxDbDatabase*  pDb, 
            const CRxDbIntArray & regenedViewports) {}

    // Notify about upgrade and downgrade open. Currently upublished
    // apis.
    virtual void curDocOpenUpgraded(CRxDbDatabase* pDb, 
            const CAdUiPathname& filename)
    {}

    virtual void curDocOpenDowngraded(CRxDbDatabase* pDb, 
            const CAdUiPathname& filename)
    {}
};

#define crxedEditor CRxEditor::cast(crxSysRegistry()->at(CRXED_EDITOR_OBJ))

CRX_DEFINE_NULL_CLSID(CRxEditor)
class CRXEDAPI_CLASS CRxEditor: public CRxEvent 
{ 
public:
    CRX_DECLARE_DYNAMIC(CRxEditor);
    virtual void addReactor   (CRxEventReactor * newObj) = 0;
    virtual void removeReactor(CRxEventReactor * delObj) = 0;
};

// API
CRXEDAPI_CLASS void crxedUpdateDisplay();

//////////////////////////////////////////////////////////////////////////
//放大并剪裁包围内的2D图形元素spObj。
/*****************************************************************************
* 函数说明：用圆来剪裁一个几何对象
* 函数定义：void crxedCut2DNodeByCircle()
* 参数说明：
*			pCircleEdge	剪裁边界
*			pEnt		被剪裁对象
*			NewEnts		新对象加入到的集合
* 撰写人：王宏磊
* 时间：2012-6-4
****************************************************************************/
CRXEDAPI_CLASS int crxedCut2DNodeByCircle(AcDbCircle* pCircleEdge, AcDbEntity* pEnt, AcDbVoidPtrArray& NewEnts);
//////////////////////////////////////////////////////////////////////////

/*****************************************************************************
* 函数说明：通过点方式在传入数据库的当前paper中生成一个剖面线
* 函数定义：void crxedCreateHatchByPoints()
* 参数说明：
*			pickPtArray			pickPts
*			pDb					数据库
*			bAddToDbDirectly	是否将新生成的剖面线对象直接添加到i_pDb中
*			pPatternName		剖面线图案名称
*			i_dScale			剖面线比例
*			i_dAng				剖面线角度
*			i_dDiff				剖面线间距错开
*			newHatchId			生成的剖面线对象
* 撰写人：王宏磊
* 时间：2012-6-7
****************************************************************************/
CRXEDAPI_CLASS int crxedCreateHatchByPoints(AcGePoint3dArray& pickPtArray, AcDbDatabase* pDb, bool bAddToDbDirectly,const CxCHAR* pPatternName,double i_dScale,double i_dAng,double i_dDiff, CRxDbObjectId& newHatchId);
//////////////////////////////////////////////////////////////////////////
/*****************************************************************************
* 函数说明:传入首尾链接的曲线集，来计算该曲线包围的封闭区域的重心
* 函数定义:getLoopCG(const AcDbVoidPtrArray& i_curvearray, crx_point o_result)
* 参数说明：
*               i_curvearray 传入的首尾链接的曲线集合
*			    o_result     计算的重心点的结果
* 返回值说明： 返回true计算出来重心，返回false 传入的曲线集不是首尾链接的封闭环
* 撰写人:zwx
* 时间：2013-10-17
****************************************************************************/
CRXEDAPI_CLASS bool getLoopCG(const AcDbVoidPtrArray& i_curvearray, crx_point o_result);
//////////////////////////////////////////////////////////////////////////

#endif // cplusplus

#pragma pack (pop)
#include "dbjig.h"

