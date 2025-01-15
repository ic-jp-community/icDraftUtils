//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

//  crxedinpt.h - Definition of CRxEdInputPointManager and related stuff

#ifndef _CRXEDINPT_H
#define _CRXEDINPT_H

#include "rxobject.h"
#include "dbmain.h"
#include "gecurv3d.h"

#pragma pack (push, 8)

#pragma warning (disable: 4786)

class CRxEdInputPointFilter;
class CRxEdInputPointMonitor;
class CRxApDocument;
class CRxEdInputContextReactor;
class CRxDbCustomOsnapMode;
class CRxEdSubSelectFilter;

// CRxEdInputPointManager defines the manager object for registered
// custom OSNAP modes, custom AutoSnap callbacks and point filter callbacks.
//
class CRxEdInputPointManager
{
  public:

    // registerPointFilter
    //
    // Invoke to register a point filter.  returns CDraft::eOK if no filter
    // is currently in use, else returns CDraft::eIllegalReplacement.  It's
    // not nice to hog the filter slot!
    //
    virtual CDraft::ErrorStatus     registerPointFilter(CRxEdInputPointFilter* pFilter) = 0;

    // revokePointFilter
    //
    // Used to revoke the current Point Filter.  Returns CDraft::eOk if there
    // was an active point filter, and CDraft::eNullObjectPointer if there wasn't
    // one.  It's not nice to revoke someone else's filter!   If you must
    // do so, find out what it is (see currentPointFilter) and put it back,
    // right quick!
    //
    virtual CDraft::ErrorStatus     revokePointFilter() = 0;

    // currentPointFilter
    //
    // Returns the active point filter, if there is one, and NULL otherwise.
    //
    virtual CRxEdInputPointFilter* currentPointFilter() const = 0;

    // addPointMonitor
    //
    // Used to add a point monitor to the active set.  Adding the same
    // point monitor twice (as compared by address) will cause CDraft::eDuplicateKey
    // to be returned.  Each monitor will be invoked once and only once
    // per input point event. Otherwise, CDraft::eOk will be returned.
    //
    virtual CDraft::ErrorStatus addPointMonitor(CRxEdInputPointMonitor* pMonitor) = 0;

    // removePointMonitor
    //
    // Used in remove a Point Monitor from the active set.
    // Returns CDraft::eOk if the monitor indicated by the input address
    // was in the set, and CDraft::eInvalidKey if it wasn't.
    //
    virtual CDraft::ErrorStatus removePointMonitor(CRxEdInputPointMonitor* pMonitor) = 0;

    // addInputContextReactor
    //
    // Add an input context reactor.  Find out what the user is currently
    // being prompted for via the CaxaDraft Input mechanism (Windows dialogs
    // excluded).  Any number can be added, each reactor can only be added
    // once, same as input point monitors. Adding the same
    // reactor twice (as compared by address) will cause CDraft::eDuplicateKey
    // to be returned. Otherwise, CDraft::eOk will be returned.
    //
    virtual CDraft::ErrorStatus addInputContextReactor(CRxEdInputContextReactor* pReactor) = 0;

    // removeInputContextReactor
    //
    // Used in remove an input context reactor from the active set.
    // Returns CDraft::eOk if the reactor indicated by the input address
    // was in the set, and CDraft::eInvalidKey if it wasn't.
    //
    virtual CDraft::ErrorStatus removeInputContextReactor(CRxEdInputContextReactor* pReact) = 0;

 
    // Enable and disable cursor graphics for the associated document.
    // Intended for use in conjunction with custom cursor graphics.
    // IMPORTANT: This pair of calls operates on an internal counter, so
    // the system can keep track of multiple applications that wish to
    // suppress the system cursor.

    // disableSystemCursorGraphics
    //
    // Will either return CDraft::eOk if it
    // works or CDraft::eInvalidContext if there the cursor cannot be
    // disabled.
    //
    // Currenly CDraft::eOk is always returned.
    //
    virtual CDraft::ErrorStatus disableSystemCursorGraphics() = 0;

    // enableSystemCursorGraphics
    //
    // Returns CDraft::eOk unless the disble count was already 0, in which
    // case CDraft::eInvalidContext is returned.
    //
    virtual CDraft::ErrorStatus enableSystemCursorGraphics() = 0;

    // systemCursorDisableCount
    //
    // Returns the count of callers who have the cursor disabled.
    //
    virtual int systemCursorDisableCount() const = 0;

    // turnOnForcedPick
    //
    // This call causes the CaxaDraft input event mechanism to do a pick under the
    // prevailing pick aperture on all digitizer events, regardless of whether a
    // point is being acquired or whether any OSNAP modes are currently active.
    // If a point is being acquired AND OSNAP is active, the (osnap) $APERTURE
    // dimensions define the pickbox size, otherwise the normal $PICKBOX
    // will be used.  In the CDraft::PointHistory enum, the following enum values
    // are related to this capability, as indicated by their related comments:
    // eForcedPick, ePickMask, eDidNotPick, eUsedPickBox, eUsedOsnapBox.
    //
    // A count is maintained, so that if multiple apps want to force picking,
    // it occurs until they are all done.
    //
    // Currenly CDraft::eOk is always returned.
    //
    virtual CDraft::ErrorStatus turnOnForcedPick() = 0;

    // turnOffForcedPick
    //
    // decrements the forced pick counter, and if the counter hits 0,
    // disables forced picking, which means entity picking occurs in "normal
    // circumstances, such as when input points are being acquired and
    // an OSNAP mode is active, or normal entity selection operations.
    // 
    // Returns CDraft::eOk unless the forced pick count was already 0, in which
    // case CDraft::eInvalidContext is returned.
    //
    virtual CDraft::ErrorStatus turnOffForcedPick() = 0;

    // forcedPickCount
    //
    // Returns the count of callers who have forced picking turned on.
    //
    virtual int forcedPickCount() const = 0;

    virtual int mouseHasMoved() const = 0;

    virtual CDraft::ErrorStatus turnOnSubentityWindowSelection() = 0;
    virtual CDraft::ErrorStatus turnOffSubentityWindowSelection() = 0;

    /**
     * This method registers a sub-selection filter
     *
     *  @param  pSSSubFilter    the sub-selection filter to be registered.
     *  
     *  @returns eSelectFilterError if there is an error when trying to
     *  initialize the filter data, e.g. get a list of CrxRxClass* that this
     *  filter applies to. Otherwise, eOk.
     */
    virtual CDraft::ErrorStatus addSubSelectFilter(
            CRxEdSubSelectFilter* pSSSubFilter) = 0;

    /**
     * This method unregisters a sub-selection filter
     *
     * @param   pSSubFilter   the sub-selection filter to be unregistered.
     *
     * @returns eKeyNotFound if the object does not exist. eOk otherwise.
     */
    virtual CDraft::ErrorStatus removeSubSelectFilter(
            CRxEdSubSelectFilter* pSSSubFilter) = 0;

};


// CRxEdInputPointFilter
//
// This callback protocol defines a combination 
// "Input Point Notification and Input Point filter" mechanism.


class CRxEdInputPointFilter : public CRxObject
{

  public:
    CRX_DECLARE_DYNAMIC(CRxEdInputPointFilter);
   
    // processInputPoint
    //
    // This callback is made every time an input event results in an
    // 3D point in the prevailing geometric space.  Such events include:
    // - digitizer motion with the cursor over the active viewport of the
    //   active document window
    // - digitizer motion in TABLET mode in the active document window,
    // - A string entered representing a point, either interactively, by
    //   script, (command) input, menu macro expansion, and Windows Message
    //   loop stuffing.
    // - A LISP expression that evaluates to be a 2D or 3D point.
    //
    // The callback is made after the CaxaDraft user input complex has
    // fully processed the point except for XYZ coordinate filtering,
    // at which time CaxaDraft will either
    // return the point to a caller, or accept the coordinate(s) being
    // prompted for and return for another point if XYZ coordinage filtering
    // is happening.
    //
    // Output Values
    //
    // The function can return a new "final" point, a new tooltip string, and/or
    // tell the system to reprompt for another point, essentially not returning the
    // the point to the caller.  This reprompting capability can allow things like,
    // say, a polar coordinate filter (first the direction, then the distance).
    //
    // Graphics Output.
    //
    // Graphics output to the current viewport is facilitated by passing in an
    // instance of CRxGiViewportDraw*, the viewport drawing context.  This yields
    // the same graphics capability that CrxDbEntity::viewportDraw() has at its
    // disposal.
    //
    // Input Values
    //
    // A set of arguments that together described the
    // history of the point computed so far for this particular event,
    // which could be either a digitizer motion or string entered by various
    // means.  Each of the arguments is described in comments below, but the
    // key arguments are:
    // - the "pointComputed" bool, which indicates whether points
    // could even be computed at all (they can't be under certain view conditions
    // where forced picking is enabled, and a pick could be made in spite of the
    // view conditions.  Otherwise, pointComputed will return TRUE.
    // - A "history" mask has bits set indicating what actually happened out
    // of the builtin CaxaDraft point processing, plus the point filter, for monitor
    // callbacks.
    // - the point(s) computed by CaxaDraft by various builtin filters
    // - entities under the prevailing cursor aperture, if any.
    // - and there are more arguments, as listed and described below.
    //
    // Return Status:  CDraft::eOk should always be returned.
    //
    virtual CDraft::ErrorStatus processInputPoint(
          // Ouput Values:

          // If changedPoint is kTrue
          // then newPoint has the new point value in it.
          // if pointComputed input was FALSE, then this
          // flag and newPoint are ignored.
          //
          bool&                        changedPoint,
          CRxGePoint3d&                 newPoint,
          bool&                        displayOsnapGlyph,

          // If changedTooltipStr is kTrue
          // then newTooltipString has the new tooltip string in it.
          //
          bool&                        changedTooltipStr,
          CxCHAR*&                       newTooltipString,

          // retry:  Just as coordinate filters and cursor motion be the
          //         only things that go back and re-prompt/track
          //         for another point?  This way, an app can demand
          //         that the user try again also.
          //
          bool&                        retry,

          // Input/Output
          //
          // drawContext:
          // Input view transform, pixel sizes, etc.
          // Output whatever visible graphics you want to display on
          // drawContext, using AcGi library.
          //
          // NOTE: Used in tandem with
          // CRxEdInputPointManager::disableSystemCursorGraphics()
          // and enableSystemCorsorGraphics(), one can effectively draw a
          // custom cursor
          //
//          CRxGiViewportDraw*           drawContext,

          // Input parameters:
          //
          // Basically a cumulative history of what happened on
          // point during the current input throat event, be it
          // digitizer event or mouse click, from raw cursor
          // location (or tablet mode digitizer UCS point)
          // through snap grid, ortho/alignment mode, OSNAP and
          // Autosnap (aka "Alignment")
          //
          // Not all of the interim points may be deemed worth passing back,
          // but whatever ones wind up here appear in the order that they are
          // computed in.  See "finalPoint", etc. for where things end up.

          // document:  the document object that this callback emanates from.
          //            makes it easier to plant one instance on all input point
          //            managers, and determine which one is making the callback.
          //
          CRxApDocument*              document,

          // pointComputed: TRUE if the points below are valid, FALSE if they
          //                are not, in which case forced picking is enabled, and
          //                there may be entities in the pickedEntities argument
          //                below.
          bool                       pointComputed,

          // history:  an integer with bit fields as defined in the
          //           PointHistory enum above.
          //
          int                        history,

          // lastPoint:  valid iff (history & eLastPoint)
          //
          const CRxGePoint3d&               lastPoint,

          // rawPoint: what the point is as tracked by the cursor position
          //           before subsequent filtering,
          //           or as entered in via alternate means, which is subject
          //           to far less filtering. valid if pointComputed above
          //           is TRUE
          //
          const CRxGePoint3d&               rawPoint,

          // grippedPoint: differs from rawPoint if (history & eGripped)
          //
          const CRxGePoint3d&               grippedPoint,

          // cartesianSnappedPoint:  "Old style" snap  differs from grippedPoint
          //                         if (history & eCartSnapped)
          //
          const CRxGePoint3d&               cartesianSnappedPoint,

          // OSNAP Info:  Current OSNAP point and the modes in effect,
          // iff pointComputed is TRUE.  if osnapModes is 0 and customOsnapModes
          // is empty, then OSNAP wasn't done (and since the modes are passed in,
          // a bit in history would be redundant, so there isn't one).
   
          const CRxGePoint3d&               osnappedPoint,
          CRxDb::OsnapMask                  osnapMask,
          const CRxArray<CRxDbCustomOsnapMode*>& customOsnapModes,

          // OSNAP overrides
          //
          CRxDb::OsnapMask                  osnapOverrides,
          const CRxArray<CRxDbCustomOsnapMode*>& customOsnapOverrides,

          // OSNAP or Forced Pick Info: all the entities in the aperture
          // if ((history & ePickMask) != eDidNotPick)
          // { /* then system tried to pick, either because of OSNAP or
          //      forced picking.  Doesn't necessarily imply anything was
          //      actually picked, but if it did, then results will be in next
          //      two arguments */
          // }
          // and the corresponding gsSelectionMark
          //              
          const CRxArray<CRxDbObjectId>&     pickedEntities,
          const CRxArray< CRxDbObjectIdArray, CRxArrayObjectCopyReallocator< CRxDbObjectIdArray > >&
                                           nestedPickedEntities,
          const CRxArray<CAXA::GsMarker>&  gsSelectionMark,

          // AutoSnap Info:
          const CRxArray<CRxDbObjectId>&     keyPointEntities,
          const CRxArray< CRxDbObjectIdArray, CRxArrayObjectCopyReallocator< CRxDbObjectIdArray > >&
                                           nestedKeyPointEntities,
          const CRxArray<CAXA::GsMarker>&  keyPointGsSelectionMark,

          const CRxArray<CRxGeCurve3d*>&       alignmentPaths,

          // computedPoint:
          // This is where the point ends up for CaxaDraft iff pointComputed
          // is TRUE.  It is always set, whether
          // any builtin filters are performed or not.
          // AutoSnap computations could alter it from osnappedPoint.
          // Can be altered by
          // returning new point, as described above.

          const CRxGePoint3d&               computedPoint,

          // tooltipString:
          // the final tooltip string, as determined by CaxaDraft.  Can be altered by
          // returning new string, as described above.
          const CxCHAR*                      tooltipString) = 0;


    // --- end of processInputPoint (big one, eh?)

    // revokeInputFilter
    //
    // This callback is made whenever a filter is revoked.  If another filter
    // has "chained" a registered filter, it should forward this call, and compare
    // the input "revokedFilter" with its own "this" address.  If they match, the
    // filter returns its embedded filter, if there is any, so the calling filter
    // (or CaxaDraft) can update its own filter pointer with it.  If they don't match,
    // the filter should forward the call to its embedded filter, if there is any,
    // and return its "this" pointer, which effectively leaves its nesting status
    // unchanged (Note that this is the default behavior).
    // The net effect is to remove the revoked filter from the chain,
    // and leave the rest of the chain alone.  Of course, if an outer filter
    // detects its immediate nested filter as being changed (i.e. removed), it
    // can query the new filter's class and take whatever action is necessary.
    // which is hopefully nothing, else you have an unstable sequence.
    //
    virtual CRxEdInputPointFilter* revokeInputFilter
        (CRxEdInputPointFilter* revokedFilter)                { return this; }
};

// CRxEdInputPointMonitor
//
// This callback Is like point filter, except it cannot alter the point, tooltip
// string, or ask the system to retry.


class CRxEdInputPointMonitor : public CRxObject
{
    public:
    CRX_DECLARE_DYNAMIC(CRxEdInputPointMonitor);
    // monitorInputPoint
    //
    // This callback is under the exact same conditions as CRxEdInputPointFilter,
    // except that the point filter is invoked first, and can affect the
    // "computed point".
    //
    // The callback is made after the CaxaDraft user input complex has
    // fully processed the point except for XYZ coordinate filtering,
    // AND after an app-defined input point filter has processed the point,
    // if one is registered.  After invoking all registered instances of
    // CRxEdInputPointMonitor, CaxaDraft will either
    // return the point to a caller, or accept the coordinate(s) being
    // prompted for and return for another point if XYZ coordinage filtering
    // is happening.
    //
    // Output Values
    //
    // Unlike CRxEdInpoutPointFilter, this function cannot affect the point or
    // influence the prompting, and therefore has none of the Output Value
    // parameters of CRxEdInputPointFilter.  However, see graphics output, which
    // is the same for monitors as for filters.
    //
    // Graphics Input/Output.
    //
    // Same as CRxEdInputPointFilter
    //
    // Input Values
    //
    // Same as CRxEdInputPointFilter, except where noted.
    //
    // Return Status:  CDraft::eOk should always be returned.
    //
    virtual CDraft::ErrorStatus monitorInputPoint(
 
          // Output
          // If changedTooltipStr is kTrue
          // then newTooltipString has the new tooltip string in it.
          //
          bool&                             appendToTooltipStr,
          CxCHAR*&                            additionalTooltipString,

          // Input/Output
          //
//          CRxGiViewportDraw*                   drawContext,

          // Input parameters:
          //
          CRxApDocument*                       document,
          bool                                pointComputed,
          int                                 history,
          const CRxGePoint3d&                  lastPoint,
          const CRxGePoint3d&                  rawPoint,
          const CRxGePoint3d&                  grippedPoint,
          const CRxGePoint3d&                  cartesianSnappedPoint,
          const CRxGePoint3d&                  osnappedPoint,
          CRxDb::OsnapMask                     osnapMask,
          const CRxArray<CRxDbCustomOsnapMode*>& customOsnapModes,
          CRxDb::OsnapMask                     osnapOverrides,
          const CRxArray<CRxDbCustomOsnapMode*>& customOsnapOverrides,
          const CRxArray<CRxDbObjectId>&        apertureEntities,
          const CRxArray< CRxDbObjectIdArray, CRxArrayObjectCopyReallocator< CRxDbObjectIdArray > >& 
                                              nestedApertureEntities,
          const CRxArray<CAXA::GsMarker>&     gsSelectionMark,
          const CRxArray<CRxDbObjectId>&        keyPointEntities,
          const CRxArray< CRxDbObjectIdArray, CRxArrayObjectCopyReallocator< CRxDbObjectIdArray > >&
                                              nestedKeyPointEntities,
          const CRxArray<CAXA::GsMarker>&     keyPointGsSelectionMark,
          const CRxArray<CRxGeCurve3d*>&        alignmentPaths,
          const CRxGePoint3d&                  computedPoint,
          const CxCHAR*                         tooltipString) = 0;

    virtual bool
        excludeFromOsnapCalculation (const CRxArray<CRxDbObjectId>& nestedEntity,
                                     CAXA::GsMarker gsSelectionMark)
                                    { return false; }
};

class CRxEdInputContextReactor
{

// Notification that user prompts are starting and completing.  
//
// The parameters ALL have the same meaning as the corresponding parameters
// in the corresponding "acedGet*()" functions.  As far as apps are concerned,
// that is exactly what we are monitoring, although internally, the values
// will be taken from the prevailing upkt struct.
//
// Note that the inputs can only be discerned from the "beginGetXxx" callbacks
// and the outputs are returned to the "endGetXxx" callbacks.  This eliminates
// redundancy, and obviously, the timing is right.   Within a given
// document, these callbacks can be nested, but an "endGetXxx" callback will
// always balance with a "beginGetXxx" callback within a document.
//
// Note also that the acedInitGet() parameters are folded into the beginGetXxx
// callbacks, and if a keyword is specified and entered, they PromptStatus
// will be set accordingly and and the pKeyword parameter will point to the
// keyword.
//

public:
    virtual void beginGetPoint(const CRxGePoint3d* pointIn,
                               const CxCHAR* promptString,
                               int   initGetFlags,
                               const CxCHAR* pKeywords) { }

    virtual void endGetPoint(CDraft::PromptStatus returnStatus,
                             const CRxGePoint3d& pointOut,
                             const CxCHAR*& pKeyword) { }

    virtual void beginGetAngle(const CRxGePoint3d* pointIn,
                               const CxCHAR* promptString,
                               int   initGetFlags,
                               const CxCHAR* pKeywords) { }

    virtual void endGetAngle(CDraft::PromptStatus returnStatus,
                             double& angle,
                             const CxCHAR*& pKeyword) { }

    virtual void beginGetDistance(const CRxGePoint3d* pointIn,
                                  const CxCHAR* promptString,
                                  int   initGetFlags,
                                  const CxCHAR* pKeywords) { }

    virtual void endGetDistance(CDraft::PromptStatus returnStatus,
                                double& distance,
                                const CxCHAR*& pKeyword) { }

    virtual void beginGetOrientation(const CRxGePoint3d* pointIn,
                                     const CxCHAR* promptString,
                                     int   initGetFlags,
                                     const CxCHAR* pKeywords) { }

    virtual void endGetOrientation(CDraft::PromptStatus returnStatus,
                                   double& angle,
                                   const CxCHAR*& pKeyword) { }

    virtual void beginGetCorner(const CRxGePoint3d* firstCorner,
                                const CxCHAR* promptString,
                                int   initGetFlags,
                                const CxCHAR* pKeywords) { }
    
    virtual void endGetCorner(CDraft::PromptStatus returnStatus,
                              CRxGePoint3d& secondCorner,
                              const CxCHAR*& pKeyword) { }

    // *ScaleFactor is the same as *Distance, except a negative
    // value can be returned.  There is no exported ADS/LISP/ActiveX equivalent.
    //
    virtual void beginGetScaleFactor(const CRxGePoint3d* pointIn,
                                     const CxCHAR* promptString,
                                     int   initGetFlags,
                                     const CxCHAR* pKeywords) { }

    virtual void endGetScaleFactor(CDraft::PromptStatus returnStatus,
                                   double& distance,
                                   const CxCHAR*& pKeyword) { }

    // Begin Nongeometric value input contexts.
    // Design note:  No mistake, getstring() does NOT do keywords!
    //
    virtual void beginGetString(const CxCHAR* promptString,
                                int   initGetFlags) { }

    virtual void endGetString (CDraft::PromptStatus returnStatus,
                               CxCHAR* pString) { }

    virtual void beginGetKeyword(const CxCHAR* promptString,
                                 int   initGetFlags,
                                 const CxCHAR* pKeywords) { }

    virtual void endGetKeyword (CDraft::PromptStatus returnStatus,
                                const CxCHAR*& pKeyword) { }



    virtual void beginGetInteger(const int* dfault, // NULL implies no default
                                const CxCHAR* promptString,
                                int   initGetFlags,
                                const CxCHAR* pKeywords) { }

    virtual void endGetInteger(CDraft::PromptStatus returnStatus,
                               int& retValue,
                               const CxCHAR*& pKeyword) { }

    // *Color() is effectively a ranged-checked *Integer()
    virtual void beginGetColor(const int* dfault, // NULL implies no default
                               const CxCHAR* promptString,
                               int   initGetFlags,
                               const CxCHAR* pKeywords) { }

    virtual void endGetColor(CDraft::PromptStatus returnStatus,
                             int& retValue,
                             const CxCHAR*& pKeyword) { }

    virtual void beginGetReal(const double* dfault, // NULL implies no default
                              const CxCHAR* promptString,
                              int   initGetFlags,
                              const CxCHAR* pKeywords) { }

    virtual void endGetReal(CDraft::PromptStatus returnStatus,
                            double& returnValue,
                            const CxCHAR*& pKeyword) { }

    virtual void beginEntsel(const CxCHAR* promptString,
                             int   initGetFlags,
                             const CxCHAR* pKeywords) { }

    virtual void endEntsel(CDraft::PromptStatus returnStatus,
                           CRxDbObjectId& entPicked,
                           CRxGePoint3d& pickPoint,
                           const CxCHAR* pKeyword) { }

    // These two callbacks service both CRxedNEntSel() and crxedNEntSelP()
    // calls.  The differences are immaterial with regard to monitoring
    // input.
    //
    virtual void beginNentsel(const CxCHAR*    promptString,
                              CAXA::Boolean pickFlag,
                              int            initGetFlags,
                              const CxCHAR*    pKeywords) { }

    virtual void endNentsel(CDraft::PromptStatus returnStatus,
                            CRxDbObjectId entPicked,
                            const CRxGePoint3d&  pickPoint,
                            const CRxGeMatrix3d& xform,
                            const resbuf* referenceStack,
                            const CxCHAR*   pKeyword) { }

    virtual void beginSSGet(const CxCHAR*  pPrompt,
                            int          initGetFlags,
                            const CxCHAR*  pKeywords,
                            const CxCHAR*  pSSControls, // str in ADS
                            const CRxArray<CRxGePoint3d>& points,
                            const resbuf*               entMask) { }

    virtual void endSSGet(CDraft::PromptStatus returnStatus,
                          const CRxArray<CRxDbObjectId>& ss) { }
                    
    // These two callbacks cover internal CaxaDraft drag sequences, crxedDragGen()
    // and CRxEdJig drag sequences also.
    //
    virtual void beginDragSequence(const CxCHAR*  promptString) { }

    virtual void endDragSequence(CDraft::PromptStatus returnStatus,
                                 CRxGePoint3d&  pickPoint,
                                 CRxGeVector3d& vec) { }

    // Quiescent state begin/end notification
    virtual void beginQuiescentState() { }

    virtual void endQuiescentState() { }
};

#pragma pack (pop)
#endif  // _CRXEDINPT_H
