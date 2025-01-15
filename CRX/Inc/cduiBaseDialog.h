//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//	End-users must also comply with the terms and conditions 
//	in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//	版权所有（C）北京数码大方科技股份有限公司
//	最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
// 

#ifndef _cduiBaseDialog_h
#define _cduiBaseDialog_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "CrxUICx.h"

typedef enum {
	// Nothing: implies notification wasn't processed.
	kAdUiReply_Nothing,

	// Ok: implies notification has been handled.
	kAdUiReply_Ok,

	// NotValid:
	//  Recipient of a Validate request replies that (some) content is
	// not valid.
	kAdUiReply_NotValid,

	// Valid:
	//  Recipient of a Validate request replies that all content is either
	// valid or in an indeterminate state (assumed to be valid). In other
	// words, there is no content that is definitely "not valid" (yeech).
	kAdUiReply_Valid,

	// TextTip:
	//  Recipient of a GetTipSupport request replies that a standard text-tip
	// should be displayed. The sender will issue a GetTipRect to position a
	// text tip and then send GetTipText to obtain the tip text. DrawTipText
	// will be sent to prepare a DC and optionally draw the tip text.
	kAdUiReply_TextTip,

	// ToolTip:
	//  Recipient of a GetTipSupport request replies that a standard tool-tip
	// should be displayed. The sender will issue a GetTipText request to
	// obtain the tip text.
	kAdUiReply_ToolTip,

	// DrawTip:
	//  Recipient of a GetTipSupport request replies that an owner-drawn tip
	// should be displayed. The sender will issue a GetTipRect to position a
	// text tip and then send DrawTip to render the tip.
	kAdUiReply_DrawTip,

} CRxUI_REPLY;

typedef enum {
	// Nothing: never sent, ignore it, it's a rogue notification.
	kAdUiNotify_Nothing,

	// Generic: provided to support application-specific messaging.
	//  Expects to process generic wParam, lParam and reply, as described above.
	kAdUiNotify_Generic,

	// Application's Main Window:
	//  lParam points to a CWnd pointer that will receive the application's
	// main window.
	kAdUiNotify_AppMainWindow,

	// Application's Resource Instance:
	//  lParam points to an HINSTANCE that will receive the handle of the
	// module containing the application's resources.
	kAdUiNotify_AppResourceInstance,

	// AutoLoad or Reload:
	//  For Reload lParam is an LPCTSTR identifying a resource, for AutoLoad
	//  lParam is 0. Reply Ok if the control is sucessfully initialized (or
	//  re-initialized).
	kAdUiNotify_AutoLoad,
	kAdUiNotify_Reload,

	// GetTipSupport: request for tool-tip support.
	//  A control receives this request to determine what kind of tool tip
	//  should be displayed. If processed, the control responds with an
	//  appropriate ADUI_REPLY code. lParam is a pointer to a CPoint
	//  containing the cursor's current position on the display.
	kAdUiNotify_GetTipSupport,

	// GetTipText: request for tool-tip text.
	//  lParam is a pointer to a CString to receive the text, initially
	//  empty. Reply Ok, optionally setting the text. If the returned
	//  text is empty the message is deemed to be handled and the tool
	//  tip will be suppressed. A dialog usually sends this to a control
	//  and if ignored, attempts to process it itself.
	kAdUiNotify_GetTipText,

	// Get Tip Placement:
	//  lParam is a pointer to a CRect to receive display co-ordinates for
	//  a tool-tip. Set the rectangle and reply Ok to have the control
	//  receive DrawTip.
	kAdUiNotify_GetTipRect,

	// Query if in item rectangle related to Tip:
	//  lParam is a pointer to a CPoint containing the cursor's current
	//  position on the display, usually within a tip window. Return Ok if
	//  the position is still within the visible part of the item related
	//  to the tip. Otherwise, the sender assumes the tip can be removed.
	kAdUiNotify_HitTipRect,

	// Draw Tip:
	//  lParam is a pointer to a CDC. The control should render tip data in
	// the DC.
	kAdUiNotify_DrawTip,

	// Draw Tip Text:
	//  lParam is a pointer to a CAdUiDrawTipText. The control should set up
	// the DC passed in the object and possibly render the text. Returning
	// Ok indicates the request was fully handled, otherwise the caller
	// (usually a tip window) will draw the text.
	kAdUiNotify_DrawTipText,

	// Update Tip:
	//  A control may send this to its container when the pointer moves over
	// the control. The container may respond by sending GetTipSupport or by
	// executing its normal tool-tip processing. lParam should be a pointer
	// to the control's CWnd.
	kAdUiNotify_UpdateTip,

	// Hide or Show window:
	//  Sent to a dialog to hide or restore the window and it's parents.
	kAdUiNotify_HideWindow,
	kAdUiNotify_ShowWindow,

	// Restore focus:
	//  wParam LOWORD is a control ID. "Smart" controls often validate their
	//  contents on WM_KILLFOCUS. If not valid the control may want to keep
	//  focus. Problem is that WM_KILLFOCUS is usually sent after focus has
	//  been scheduled for some other window. A control may post this to its
	//  container which should respond by setting focus back to the control
	//  (assuming the container is still active).
	kAdUiNotify_RestoreFocus,

	// Content changed:
	//  A control send this notification to its container when the control's
	// content has changed. The container is free to handle this as it sees
	// fit. The reply is usually ignored.
	kAdUiNotify_Change,

	// NotValid content:
	//  A control send this notification to its container upon determining
	// that it contains non-valid data. The container is free to handle this
	// as it sees fit, possibly by disabling other controls (ex. OK button).
	// The reply is ignored.
	kAdUiNotify_NotValid,

	// Valid content:
	//  A control send this notification to its container upon determining
	// that it contains valid data. The container is free to handle this as
	// it sees fit, possibly by enabling other controls. The reply is ignored.
	kAdUiNotify_Valid,

	// Validate: request to validate content.
	//  A control that receives this notification should determine if it
	// contains valid data. If so it replies Valid, otherwise NotValid.
	// A container that processes this notification will usually inspect
	// each control. If any replies NotValid the container should reply
	// NotValid, and valid otherwise. Controls that handle this message do
	// not need to notify Valid/NotValid during processing (the reply code
	// is sufficient).
	kAdUiNotify_Validate,

	// Command state:
	//  LParam is a ADUI_COMMAND_STATE code. This notification is passed to
	// a dialog and it's parents to inform about the state of a command in
	// progress in the drawing editor.
	kAdUiNotify_CommandState,

} CRxUI_NOTIFY;

typedef enum {
	// Cancelled: notes that a command in the drawing editor was cancelled.
	kAdUiCommand_Cancelled = -1,

	// Completed: notes that a command in the drawing editor finished OK.
	//  This also represents a default state (i.e. when no commands have been
	// issued, aka kAdUiCommand_None).
	kAdUiCommand_Completed,

	// Begun: notes that a command in the drawing editor has started.
	kAdUiCommand_Begun,

} CRxUI_COMMAND_STATE;

#ifndef kDialogOptionNone
#define kDialogOptionNone       0
#endif

#ifndef kDialogOptionUseTips
#define kDialogOptionUseTips       1
#endif

#ifndef kDialogOptionUseTipsForContextHelp
#define kDialogOptionUseTipsForContextHelp       2
#endif

//////////////////////////////////////////////////////////////////////////////
#pragma warning(push)
#pragma warning(disable : 4275)
class CRXUI_CLASS  CCRxUiBaseDialog : public CDialog 
{
    DECLARE_DYNAMIC(CCRxUiBaseDialog);

public:
                CCRxUiBaseDialog (
                    UINT idd,
                    CWnd *pParent=NULL,
                    HINSTANCE hDialogResource=NULL
                );
virtual         ~CCRxUiBaseDialog ();

// AdUi message handlers
protected:
virtual CRxUI_REPLY DoAdUiMessage (
                    CRxUI_NOTIFY notifyCode, UINT controlId, LPARAM lParam
                );
virtual CRxUI_REPLY OnNotifyControlChange (UINT controlId, LPARAM lParam);
virtual CRxUI_REPLY OnNotifyControlValid (UINT controlId, BOOL isValid);
virtual CRxUI_REPLY OnNotifyGeneric (UINT controlId, LPARAM lParam);
virtual CRxUI_REPLY OnNotifyUpdateTip (CWnd *control);

// Drawing Editor Interaction
private:
        HINSTANCE m_commandResourceInstance;
        BOOL    m_commandWindowWasEnabled;
        HWND    m_commandWindowWithFocus;

protected:
        CRxUI_COMMAND_STATE m_commandState;

        void    BeginEditorCommand ();
        void    CancelEditorCommand ();
        void    CompleteEditorCommand (BOOL restoreDialogs=TRUE);
        void    MakeDialogsVisible (BOOL visible);
public:
        BOOL    EditorCommandCancelled ();

// Context help
protected:
        CString m_contextHelpFileName;
        CString m_contextHelpFullPathName;
        CString m_contextHelpPrefix;    // Must be 4 ASCII characters.

virtual BOOL    FindContextHelpFullPath (LPCTSTR fileName, CString& fullPath);
public:
        LPCTSTR GetContextHelpFileName ();    
        void    SetContextHelpFileName (LPCTSTR pFileName);
        LPCTSTR GetContextHelpFullPathName ();    
        void    SetContextHelpFullPathName (LPCTSTR pFullPathName);
        LPCTSTR GetContextHelpPrefix ();   
        void    SetContextHelpPrefix (LPCTSTR pPrefix);

        CToolTipCtrl* GetToolTipCtrl();        
// Misc.
private:
        BOOL    m_bRunningModal;
        HINSTANCE m_hDialogResourceSaved;

        // Substitute font used when charset isn't supported in the default font
        CFont   m_substFont;

protected:
        int    m_bUseTips;
        HINSTANCE m_hDialogResource;
        HICON   m_hIcon;
//        CAdUiTextTip *m_pTextTip;
//        CToolTipCtrl *m_pToolTip;
        CString m_rootKey;

        friend class CAdUiAssist;
        static CAdUiAssist* m_pUIAssist;

protected:
virtual void    OnInitDialogBegin ();
virtual void    OnInitDialogFinish ();
public:
virtual CWnd    *AppMainWindow ();
virtual HINSTANCE AppResourceInstance ();
virtual LPCTSTR AppRootKey ();
        void    SetAppRootKey (LPCTSTR key);

        // Modeless dialogs should be created using one of the following
        // Create() methods (as per the MFC documentation). These are
        // provided to handle resource switching (like the new DoModal()).
        // ** Note: These methods are NOT declared virtual, yet duplicate
        //          the signature of the inherited methods.
        BOOL Create (LPCTSTR lpszTemplateName, CWnd* pParentWnd=NULL);
        BOOL Create (UINT nIDTemplate, CWnd* pParentWnd=NULL);

virtual void    EnableFloatingWindows (BOOL allow);     // INTERNAL USE ONLY
virtual int IsMultiDocumentActivationEnabled();         // INTERNAL USE ONLY
virtual int EnableMultiDocumentActivation(BOOL bEnable);// INTERNAL USE ONLY
virtual BOOL DoDialogHelp();                            // INTERNAL USE ONLY


        int    GetUseTips ();
        void    SetUseTips (int useTips);

        HICON   GetDialogIcon();
        void    SetDialogIcon(HICON hIcon);        

// Data Exchange methods
public:
        BOOL    DisplayData ();
virtual BOOL    ExchangeData (BOOL bSaveAndValidate);
        BOOL    ValidateData ();

// ClassWizard-controlled
public:
    //{{AFX_DATA(CAdUiBaseDialog)
    enum { IDD = 0 };
    //}}AFX_DATA

    //{{AFX_VIRTUAL(CAdUiBaseDialog)
public:
    virtual BOOL PreTranslateMessage(MSG* pMsg);        // INTERNAL USE ONLY
    virtual INT_PTR DoModal();                          // INTERNAL USE ONLY
protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    virtual void PostNcDestroy();                       // INTERNAL USE ONLY
    virtual BOOL PreCreateWindow(CREATESTRUCT& cs);     // INTERNAL USE ONLY
    //}}AFX_VIRTUAL

protected:
    //{{AFX_MSG(CAdUiBaseDialog)
    virtual BOOL OnInitDialog();
    afx_msg LRESULT OnAdUiMessage (WPARAM wParam, LPARAM lParam);
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);// INTERNAL USE ONLY
    afx_msg BOOL OnHelpInfo(HELPINFO* lpHelpInfo);
    afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
    afx_msg void OnAdUiTimer(UINT_PTR nIDEvent);
    //}}AFX_MSG
    afx_msg BOOL OnNotify_ToolTipText(UINT id, NMHDR *pNMHDR, LRESULT *pResult);
     DECLARE_MESSAGE_MAP()
};
#pragma warning(pop)
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#pragma pack (pop)
#endif

/////////////////////////////////////////////////////////////////////////////
