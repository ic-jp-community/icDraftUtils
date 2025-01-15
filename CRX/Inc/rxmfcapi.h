//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//

#include "crxChar.h"
#include "CrxEdApiCx.h"
#include "atltypes.h"
//#include "CRxStatusBar.h"

#ifndef AD_RXMFCAPI_H
#define AD_RXMFCAPI_H 1
#pragma pack (push, 8)

// CaxaDraft WM_CDRAFT_KEEPFOCUS
// Create custom window message.  This message is used by the OnIdle
// handler to test if a top-level window will relinquish focus.  If
// a window handles this message and does not want to lose focus then
// it should return a TRUE result.
//   lParam & wParam not used
//   Return 1 to maintain focus else 0 if focus can be shifted.
#ifndef WM_CDRAFT_KEEPFOCUS
#define WM_CDRAFT_KEEPFOCUS  (WM_USER+0x6D01)
#endif // WM_CDRAFT_KEEPFOCUS

//class CRxDbDatabase;
//class CRxApStatusBar;
//class CDialogBar;
//class CRxApApplicationFrame;

//////////////////////////
// CaxaDraft Window pointers
//////////////////////////
// The pointer to a window or a frame should be used only when the
// ARX apps share the SAME MFC DLL with CaxaDraft.
// In some cases, when using static MFC or different MFC DLL,
// the window handle should be used instead.
//  instead of using
//      crxedGetAcadDwgView()->UpdateWindow();
//      CMyDialog Mydia(crxedGetAcadFrame());
//  use
//      ::UpdateWindow(crxedGetAcadDwgView()->m_hWnd);
//      CMyDialog Mydia(CWnd::FromHandle(crxedGetAcadFrame()->m_hWnd));
        
///* crxedGetAcadWinApp
// * Returns the pointer to CaxaDraft CWinApp object.
// */
//CWinApp* crxedGetAcadWinApp();
//
///* crxedGetAcadDoc
// * Returns the pointer to CaxaDraft CDocument object
// * There's only one document in CaxaDraft.
// */
//CDocument* crxedGetAcadDoc();
//
///* crxedGetAcadDwgView
// * Returns the pointer to CaxaDraft CView object
// * There's only one Dwg view in CaxaDraft.
// */
//CView* crxedGetAcadDwgView();
//
///* crxedGetAcadFrame
// * Returns the pointer to CaxaDraft CMDIFrameWnd object
// */
//CMDIFrameWnd* crxedGetAcadFrame();
//
///* crxedGetAcadDockCmdLine
// * Returns the pointer to CaxaDraft command line window
// */
//CWnd* crxedGetAcadDockCmdLine();
//
///* crxedGetAcadTextCmdLine
// * Returns the pointer to CaxaDraft Text window.
// */
//CWnd* crxedGetAcadTextCmdLine();
//
///* crxedGetAcadResourceInstance()
// * Returns the Instance of CaxaDraft's resource
// */
//HINSTANCE crxedGetAcadResourceInstance();
//
//
/* crxedDwgPoint
* used in crxedCoordinate function :
*/
typedef double crxedDwgPoint[3];
//
// CaxaDraft coordinates and viewports

/* crxedCoordFromPixelToWorld
* Takes a coordinate in Window's coordinate (mouse coordinate)
* and converts it to current viewport world coordinate
*/
CRXEDAPI_API void crxedCoordFromPixelToWorld(const CPoint &ptIn, crxedDwgPoint ptOut);

/* crxedCoordFromPixelToWorld
* Takes a coordinate in Windows' coordinate (mouse coordinate) and
* a viewport number; and converts it to current viewport world coordinate
*/
CRXEDAPI_API BOOL crxedCoordFromPixelToWorld(int windnum, CPoint ptIn, crxedDwgPoint ptOut);

/* crxedCoordFromWorldToPixel
* Takes a coordinate in CaxaDraft world coordinate and a viewport number; 
* and converts it to Windows' coordinate.
*/
CRXEDAPI_API BOOL crxedCoordFromWorldToPixel(int windnum, const crxedDwgPoint ptIn, CPoint& ptOut);

///* crxedGetWinNum
// * Takes a Windows' client coordinate and return the viewport number where 
// * the point is on
// * Returns 0 for no viewport, 1 if tilemode is off.
// * It's used with crxedCoordFromWorldToPixel/crxedCoordFromPixelToWorld
// */
//int crxedGetWinNum(int ptx, int pty);
//
//// Progress Bar API
//
///* crxedSetStatusBarProgressMeter
// * Creates a progress meter on CaxaDraft status bar.
// * Returns 0 if it successfully creates the label and progress meter. 
// * Otherwise -1
// */
//int crxedSetStatusBarProgressMeter(const CxCHAR* pszLabel, int nMinPos, 
//                                  int nMaxPos);
///* crxedSetStatusBarProgressMeter
// * Call this with a positive value within the range specified to set 
// * the current position of the status bar.  
// * Pass a negative number to add an amount to the current position (relative).
// */
//int crxedSetStatusBarProgressMeterPos(int nPos);
//
///* crxedRestoreStatusBar
// * Resets CaxaDraft status bar
// */
//void crxedRestoreStatusBar();
//
//// Define callback function for apps that want windows messages
//typedef void (* crxedWatchWinMsgFn)(const MSG*);
//typedef BOOL (* crxedFilterWinMsgFn)(MSG*);
//typedef void (* crxedOnIdleMsgFn) ();
//typedef void (* crxedOnModalFn) (bool bModal);
//
//// Windows messages hooks
///* Register a filter message hook into CaxaDraft's Windows message loop.
// * The message passed to your application can be changed and can be blocked out.
// * If the function returns TRUE, the message WON'T be passed to other hook 
// * functions or CaxaDraft at all. The message is terminated.
// * Returns TRUE if successfully registers the hook. Otherwise FALSE.
// */
//BOOL crxedRegisterFilterWinMsg(const crxedFilterWinMsgFn pfn);
//
///* crxedRemoveFilterWinMsg
// * Takes a message hook function pointer and remove it 
// * Returns TRUE if successfully registers the hook. Otherwise FALSE.
// */
//BOOL crxedRemoveFilterWinMsg(const crxedFilterWinMsgFn pfn); 
//
///* crxedRegisterWatchWinMsg
// * Register a hook function into CaxaDraft message loop. 
// * The function can only look up CaxaDraft's Windows message.
// * It can't  change or block message.
// * Returns TRUE if successfully registers the hook. Otherwise FALSE.
// */
//BOOL crxedRegisterWatchWinMsg(const crxedWatchWinMsgFn pfn);
//
///* crxedRemoveWatchWinMsg
// * Takes a message hook function pointer and remove it 
// * Returns TRUE if successfully registers the hook. Otherwise FALSE.
// * 
// */
//BOOL crxedRemoveWatchWinMsg(const crxedWatchWinMsgFn pfn); 
//
///* crxedRegisterOnIdleWinMsg
// * Register a hook function to be notified when CaxaDraft is on idle 
// * Returns TRUE if successfully registers the hook. Otherwise FALSE.
// */
//BOOL crxedRegisterOnIdleWinMsg(const crxedOnIdleMsgFn pfn);
//
///* crxedRemoveOnIdleWinMsg
// * Takes a message on idle hook function pointer and remove it 
// * Returns TRUE if successfully registers the hook. Otherwise FALSE.
// * 
// */
//BOOL crxedRemoveOnIdleWinMsg(const crxedOnIdleMsgFn pfn); 
//
//
///* crxedRegisterOnModal
// * Register a hook function to be notified when CaxaDraft displays a modal dialog.
// * Returns TRUE if successfully registers the hook. Otherwise FALSE.
// */
//BOOL crxedRegisterOnModal(const crxedOnModalFn pfn);
//
///* crxedRemoveOnModal
// * Takes a hook function pointer and removes it
// * Returns TRUE if successfully registers the hook. Otherwise FALSE.
// * 
// */
//BOOL crxedRemoveOnModal(const crxedOnModalFn pfn); 

struct CRxColorSettings {

    /* Solid background color for various contexts */
    DWORD dwGfxModelBkColor;    
    DWORD dwGfxLayoutBkColor;
    DWORD dwParallelBkColor;
    DWORD dwBEditBkColor;
    DWORD dwCmdLineBkColor;
    DWORD dwPlotPrevBkColor;

    /* Background color for 3D perspective projection */
    DWORD dwSkyGradientZenithColor;
    DWORD dwSkyGradientHorizonColor;
    DWORD dwGroundGradientOriginColor;
    DWORD dwGroundGradientHorizonColor;
    DWORD dwEarthGradientAzimuthColor; 
    DWORD dwEarthGradientHorizonColor;

    /* Crosshair color for various contexts */
    DWORD dwModelCrossHairColor;
    DWORD dwLayoutCrossHairColor;
    DWORD dwParallelCrossHairColor;
    DWORD dwPerspectiveCrossHairColor;
    DWORD dwBEditCrossHairColor;

    /* Ground plane grid major lines for various contexts */
    DWORD dwParallelGridMajorLines;
    DWORD dwPerspectiveGridMajorLines;

    /* Ground plane grid minor lines for various contexts */
    DWORD dwParallelGridMinorLines;
    DWORD dwPerspectiveGridMinorLines;

    /* Ground plane grid axis lines for various contexts */
    DWORD dwParallelGridAxisLines;
    DWORD dwPerspectiveGridAxisLines;

    /* Text window color */
    DWORD dwTextForeColor, dwTextBkColor;

    /* Command line text color */
    DWORD dwCmdLineForeColor;

    /* AutoTrack vector color for various contexts */
    // Note: dwAutoTrackingVecColor indicates autotrack vector color in model space.
    // We didn't change its name to dwModelATrackVecColor because that might break
    // existing arx app.
    DWORD dwAutoTrackingVecColor;
    DWORD dwLayoutATrackVecColor;
    DWORD dwParallelATrackVecColor;
    DWORD dwPerspectiveATrackVecColor;
    DWORD dwBEditATrackVecColor;

    /* Autosnap Marker color for various contexts */
    DWORD dwModelASnapMarkerColor;
    DWORD dwLayoutASnapMarkerColor;
    DWORD dwParallelASnapMarkerColor;
    DWORD dwPerspectiveASnapMarkerColor;
    DWORD dwBEditASnapMarkerColor;
    
    /* Drafting Tool tip color for various contexts */
    DWORD dwModelDftingTooltipColor;
    DWORD dwLayoutDftingTooltipColor;
    DWORD dwParallelDftingTooltipColor;
    DWORD dwPerspectiveDftingTooltipColor;
    DWORD dwBEditDftingTooltipColor;
        
    /* Drafting Tool tip background color for various contexts */    
    DWORD dwModelDftingTooltipBkColor;
    DWORD dwLayoutDftingTooltipBkColor;
    DWORD dwParallelDftingTooltipBkColor;
    DWORD dwPerspectiveDftingTooltipBkColor;
    DWORD dwBEditDftingTooltipBkColor;

    /* Light glyphs color for various contexts */
    DWORD dwModelLightGlyphs;
    DWORD dwLayoutLightGlyphs;
    DWORD dwParallelLightGlyphs;
    DWORD dwPerspectiveLightGlyphs;
    DWORD dwBEditLightGlyphs;

    /* Light Hotspot color for various contexts */
    DWORD dwModelLightHotspot;
    DWORD dwLayoutLightHotspot;
    DWORD dwParallelLightHotspot;
    DWORD dwPerspectiveLightHotspot;
    DWORD dwBEditLightHotspot;

    /* Light Falloff color for various contexts */
    DWORD dwModelLightFalloff;
    DWORD dwLayoutLightFalloff;
    DWORD dwParallelLightFalloff;
    DWORD dwPerspectiveLightFalloff;
    DWORD dwBEditLightFalloff;

    /* Light start limit color for various contexts */
    DWORD dwModelLightStartLimit;
    DWORD dwLayoutLightStartLimit;
    DWORD dwParallelLightStartLimit;
    DWORD dwPerspectiveLightStartLimit;
    DWORD dwBEditLightStartLimit;

    /* Light end limit color for various contexts */
    DWORD dwModelLightEndLimit;
    DWORD dwLayoutLightEndLimit;
    DWORD dwParallelLightEndLimit;
    DWORD dwPerspectiveLightEndLimit;
    DWORD dwBEditLightEndLimit;

    /* Camera glyphs color for various contexts */
    DWORD dwModelCameraGlyphs;
    DWORD dwLayoutCameraGlyphs;
    DWORD dwParallelCameraGlyphs;
    DWORD dwPerspectiveCameraGlyphs;

    /* Camera frustrum plane color for various contexts */
    DWORD dwModelCameraFrustrum;
    DWORD dwLayoutCameraFrustrum;
    DWORD dwParallelCameraFrustrum;
    DWORD dwPerspectiveCameraFrustrum;

    /* Camera clipping plane color for various contexts */
    DWORD dwModelCameraClipping;
    DWORD dwLayoutCameraClipping;
    DWORD dwParallelCameraClipping;
    DWORD dwPerspectiveCameraClipping;

    /* Flags - set if true */

    /* Flags for use tint X, Y, Z for crosshair */
    int nModelCrosshairUseTintXYZ;
    int nLayoutCrosshairUseTintXYZ;
    int nParallelCrosshairUseTintXYZ;
    int nPerspectiveCrosshairUseTintXYZ;
    int nBEditCrossHairUseTintXYZ;

    /* Flags for use tint X, Y, Z for AutoTrack Vector */
    int nModelATrackVecUseTintXYZ;
    int nLayoutATrackVecUseTintXYZ;
    int nParallelATrackVecUseTintXYZ;
    int nPerspectiveATrackVecUseTintXYZ;
    int nBEditATrackVecUseTintXYZ;

    /* Flags for use tint X, Y, Z for Drafting Tooltip Bk tint */
    int nModelDftingTooltipBkUseTintXYZ;
    int nLayoutDftingTooltipBkUseTintXYZ;
    int nParallelDftingTooltipBkUseTintXYZ;
    int nPerspectiveDftingTooltipBkUseTintXYZ;
    int nBEditDftingTooltipBkUseTintXYZ;

    /* Flags for use tint X, Y, Z for Ground plane grid major lines */
    int nParallelGridMajorLineTintXYZ;
    int nPerspectiveGridMajorLineTintXYZ;

    /* Flags for use tint X, Y, Z for Ground plane grid minor lines */
    int nParallelGridMinorLineTintXYZ;
    int nPerspectiveGridMinorLineTintXYZ;

    /* Flags for use tint X, Y, Z for Ground plane grid axis lines */
    int nParallelGridAxisLineTintXYZ;
    int nPerspectiveGridAxisLineTintXYZ;
};

// CaxaDraft windows' colors
CRXEDAPI_API BOOL crxedGetCurrentColors(CRxColorSettings* pColorSettings);
//BOOL crxedSetCurrentColors(CRxColorSettings* pColorSettings);
//BOOL crxedGetSystemColors(CRxColorSettings* pColorSettings);
//
//// CaxaDraft MDI Child Window Frame settings
//typedef struct tagChildFrmSettings {
//    // More to come later
//    CRxColorSettings m_ColorSettings;
//    bool m_bShowLayoutBar;
//    bool m_bShowScrollBar;
//    CDialogBar *m_pDialogBar;
//    bool m_bIsBedit;
//} AcChildFrmSettings;
//
//BOOL crxedGetChildFrameSettings(AcChildFrmSettings* pChildFrmSettings,
//    CMDIChildWnd *pWnd);
//BOOL crxedSetChildFrameSettings(AcChildFrmSettings* pChildFrmSettings,
//    CMDIChildWnd *pWnd);
//
//
//// Custom Drag and Drop
//// In order to enable custom drag&drop, you have to 
//// #define _ARX_CUSTOM_DRAG_N_DROP_
//// before including this header file, and you need to include <afxole.h> also.
//#ifdef _ARX_CUSTOM_DRAG_N_DROP_
///* crxedRegisterCustomDropTarget
// * Registers a new IDroptarget to the CaxaDraft's drawing window. 
// * Only one IDropTarget can be registered at one moment.
// * CaxaDraft's default Drag & Drop handling capabilities are not available 
// * until the IDroptarget is revoke.
// * This is replcrxed by crxedStartOverrideDropTarget(). It will be removed
// * in next release.
// */
//BOOL crxedRegisterCustomDropTarget(IDropTarget* pItarget);
//BOOL crxedStartOverrideDropTarget(COleDropTarget* pTarget);
//
///* crxedRevokeCustomDropTarget
// * Revokes the previously set IDroptarget. 
// * The default CaxaDraft's handling of Drag&Drop event is restored.
// * This is replcrxed by crxedRemoveDropTarget(). It will be removed
// * in next release.
// */
//BOOL crxedRevokeCustomDropTarget();
//BOOL crxedEndOverrideDropTarget(COleDropTarget* pTarget);
//
///* crxedAddDropTarget
// * Add a hook to participate in DragDrop Event started not from
// * 3rd party ARX app.
// */
//BOOL crxedAddDropTarget(COleDropTarget* pTarget);
//
///* crxedRemoveDropTarget
// * Remove the hook to CaxaDraft DragDrop event.
// */
//BOOL crxedRemoveDropTarget(COleDropTarget* pTarget);
//
//#endif // _ARX_CUSTOM_DRAG_N_DROP_
//
//// Get Database correpont to on CaxaDraft Drawing Window.
//AcDbDatabase* AcApGetDatabase(CView *pView);
//
//
//// CaxaDraft company name for registry access.  For all except CaxaDraft
//// OEM, this will return "Autodesk".  For CaxaDraft OEM, it is at the
//// discretion of the CaxaDraft OEM developer, via an entry in aoemres2.rc,
//// to specify the company name for use in registry accesses.
//const CString& crxedGetRegistryCompany();
//
//// Register the fact that the application with name "szAppName"
//// may want to add a tab to the tabbed dialog named "szDialogName".
//// This function creates the key necessary to register the added
//// tab(s) if it is not there. Returns TRUE on success.
//BOOL crxedRegisterExtendedTab(LPCTSTR szAppName, LPCTSTR szDialogName);
//
//// Return an HMENU given a .MNU file alias.
//HMENU crxedGetMenu(LPCTSTR pszAlias);
//
//// This routine is exported primarily for use by AcUi. The routine is called
//// from a dialog to determine if input is queued after an interactive command
//// has been cancelled. Generally, if there's no input queued then the dialog
//// will be restored, otherwise the dialog will terminate and allow the queued
//// commands to be processed.
//BOOL crxedIsInputPending ();
//
//BOOL crxedSetIUnknownForCurrentCommand(const LPUNKNOWN);
//BOOL crxedGetIUnknownForCurrentCommand(LPUNKNOWN &pUnk);
//
///* crxedGetApplicationStatusBar
// * Returns the pointer to CaxaDraft Application Status Bar.
// */
//CRxApStatusBar* crxedGetApplicationStatusBar();
//
///* crxedShowDrawingStatusBars
// * Shows or hides the drawing status bars.
// */
//BOOL crxedShowDrawingStatusBars(BOOL bShow = TRUE);
//
///* crxedDrawingStatusBarsVisible
// * Returns TRUE if the drawing status bar are visible
// * in CaxaDraft, otherwise FALSE.
// */
//BOOL crxedDrawingStatusBarsVisible();
//
///* crxedRegisterStatusBarMenuItem
// * Returns TRUE if the status bar item is successfully
// * registered in CaxaDraft, otherwise FALSE.
// */
//BOOL crxedRegisterStatusBarMenuItem(AcStatusBarMenuItem* pItem,
//                                   AcStatusBarMenuItem::AcStatusBarType nType);
//
///* crxedUnregisterStatusBarMenuItem
// * Returns TRUE if the status bar item is successfully
// * unregistered in CaxaDraft, otherwise FALSE.
// */
//BOOL crxedUnregisterStatusBarMenuItem(AcStatusBarMenuItem* pItem,
//                                     AcStatusBarMenuItem::AcStatusBarType nType);
//
///* crxedSetStatusBarPaneId
// * Sets the id of the given status bar pane.  Returns TRUE if
// * successful, otherwise FALSE.
// */
//BOOL crxedSetStatusBarPaneID(AcPane* pPane,
//                            AcStatusBarMenuItem::AcStatusBarType nType,
//                            int nID);
//
//// More color settings.
//struct CRxColorSettingsEx
//{
//    // Light Web color for various contexts 
//    DWORD dwModelLightWeb;
//    DWORD dwLayoutLightWeb;
//    DWORD dwParallelLightWeb;
//    DWORD dwPerspectiveLightWeb;
//    DWORD dwBEditLightWeb;
//
//    // Light Web(missingfile) color for various contexts
//    DWORD dwModelLightWebMissingFile;
//    DWORD dwLayoutLightWebMissingFile;
//    DWORD dwParallelLightWebMissingFile;
//    DWORD dwPerspectiveLightWebMissingFile;
//    DWORD dwBEditLightWebMissingFile;
//
//    // Light Web shape(extend source) color for various contexts
//    DWORD dwModelLightWebShape;
//    DWORD dwLayoutLightWebShape;
//    DWORD dwParallelLightWebShape;
//    DWORD dwPerspectiveLightWebShape;
//    DWORD dwBEditLightWebShape;
//
//    // Light Web lux at distance color for various contexts
//    DWORD dwModelLightWebLuxAtDist;
//    DWORD dwLayoutLightWebLuxAtDist;
//    DWORD dwParallelLightWebLuxAtDist;
//    DWORD dwPerspectiveLightWebLuxAtDist;
//    DWORD dwBEditLightWebLuxAtDist;
//};
//
//// CaxaDraft windows' colors
//BOOL crxedGetCurrentColorsEx(CRxColorSettings* pColorSettings, 
//                           CRxColorSettingsEx* pColorSettingsEx);
//
//BOOL crxedSetCurrentColorsEx(CRxColorSettings* pColorSettings, 
//                           CRxColorSettingsEx* pColorSettingsEx);
//
//BOOL crxedGetSystemColorsEx(CRxColorSettings* pColorSettings, 
//                          CRxColorSettingsEx* pColorSettingsEx);
//
//// Controls whether or not file open adds the filename to the 'File' MRU list.
//void crxedSuppressFileMRU(bool bSuppress);
//
//// crxedGetApplicationFrame
//// Returns the pointer to CaxaDraft Application Frame.
//CRxApApplicationFrame* crxedGetApplicationFrame();

#pragma pack (pop)
#endif // AD_RXMFCAPI_H
