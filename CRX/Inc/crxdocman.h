//£¨C£©Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  °æÈ¨ËùÓĞ£¨C£©±±¾©ÊıÂEó·½¿Æ¼¼¹É·İÓĞÏŞ¹«Ë¾
//  ×ûòÕÓÃ»§Ê¹ÓÃ±¾ÈúØş±ØĞEñÊØ¡¶CAXA×ûòÕÓÃ»§ĞúÛÉÊ¹ÓÃĞ­Òé¡·
//

//////////////////////////////////////////////////////////////////////////////
//
//  DESCRIPTION:  Header for Document and Document Manager Classes.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef CRXDOCMAN_H
#define CRXDOCMAN_H

#include <wtypes.h>  // for HINSTANCE

#include "crxDb.h"
#include "CrxEdApiCx.h"
#pragma pack (push, 8)

class CRxTransactionManager;
class CRxDbDatabase;
class CDocument;
class CRxEdInputPointManager;
class CRxApStatusBar;
class CRxApPlotReactor;
class CRxIterator;

struct IDispatch;

// Name of Registered Service Object for constructing CaxaDraft-specific
// instances.
//
#define CRX_DOCUMENT_MANAGER_OBJ _T("CRxApDocManager")

struct CRxAp {

    // The value order of this enum is important - and determines
    // the level of locking.  Also, kWrite and kProtectedAutoWrite
    // share a common bit - so that (mode & kWrite) will be true
    // for either lock mode.
    //
    enum DocLockMode   {   kNone               = 0x00,
                           kAutoWrite          = 0x01,
                           kNotLocked          = 0x02,
                           kWrite              = 0x04,
                           kProtectedAutoWrite = 0x14,
                           kRead               = 0x20,
                           kXWrite             = 0x40  };
};

class CRxLispAppInfo
{
public:
    CxCHAR appFileName[_MAX_PATH];
    bool bUnloadable;
};

CRX_DEFINE_NULL_CLSID(CRxApDocument)
class CRXEDAPI_CLASS CAXA_NO_VTABLE CRxApDocument : public CRxObject
{
public:
    CRX_DECLARE_DYNAMIC(CRxApDocument);

    // Returns the full path and filename of the database
    //
    virtual const CxCHAR*       fileName() const = 0;

    // Returns the associated MFC CDocument object 
    //
    virtual CDocument* cDoc() const = 0;

    virtual CRxTransactionManager* transactionManager() const = 0;

    virtual CRxDbDatabase*     database() const = 0;

    // These enum numbers are not random, but correspond to the
    // following formula:
    // enum value = (Release # - 12) * 4 + (0 for dwg, 1 for dxf, 2 for dwt,
    // 3 for dws, 4 for xml).  (and xml is obsolete)
    //
     enum SaveFormat {
        kUnknown = -1,      // Invalid format
        kR12_dxf = 1,       // CaxaDraft R12/LT2 DXF (*.dxf)

        kR13_dwg = 4,       // CaxaDraft R13/LT95 Drawing (*.dwg)
        kR13_dxf = 5,       // CaxaDraft R13/LT95 DXF (*.dxf)

        kR14_dwg = 8,       // CaxaDraft R14/LT97 Drawing (*.dwg)
        kR14_dxf = 9,       // CaxaDraft R14/LT97 DXF (*.dxf)

        k2000_dwg = 12,      // CaxaDraft 2000 Drawing (*.dwg)
        k2000_dxf = 13,      // CaxaDraft 2000 DXF (*.dxf)
        k2000_Template = 14, // 2000 Drawing Template File (*.dwt)
        k2000_Standard = 15, // 2000(+) Drawing Standard File (*.dws)
        k2000_xml = 16,      // 2000(+) = DesignXML v1.0 File (*.xml)

        k2004_dwg = 24,      // CaxaDraft 2004 Drawing (*.dwg)
        k2004_dxf = 25,      // CaxaDraft 2004 DXF (*.dxf)
        k2004_Template = 26, // CaxaDraft 2004 Template File (*.dwt)
        k2004_Standard = 27, // 2004 Drawing Standard File (*.dws)

        k2007_dwg =36,       // Under development
        k2007_dxf =37,       // Under development
        k2007_Template = 38, // Under development
        k2007_Standard = 39, // Under development

        kNative = k2007_dwg, // Current dwg version is 2007

        // Aliases.  These are deprecated and will be removed in a
        // future release.  Please use k2000_* and k2004_* instead.
        kR15_dwg = k2000_dwg,
        kR15_dxf = k2000_dxf,
        kR15_Template = k2000_Template,
        kR15_Standard = k2000_Standard,
        kR15_xml = k2000_xml,

        kR18_dwg = k2004_dwg,
        kR18_dxf = k2004_dxf,
        kR18_Template = k2004_Template,
        kR18_Standard = k2004_Standard
     };

    virtual SaveFormat formatForSave() const = 0;

    virtual CRxAp::DocLockMode lockMode(bool bIncludeMyLocks =
                                           false) const = 0;
    virtual CRxAp::DocLockMode myLockMode() const = 0;

    // Is there a command, lisp, script, or CRX command active 
    virtual bool    isQuiescent() const = 0;

    // Return the document's context pointer 
    virtual void * contextPtr() const = 0;

    // Return the document's input point manager
    virtual CRxEdInputPointManager* inputPointManager() = 0;

    // Return the documents Window title
    virtual const CxCHAR * docTitle() const = 0;

    // Returns a pointer to the IDispatch object associated with the CDocument object
    virtual IDispatch * GetIDispatch(bool bAddRef) = 0;

    // Return TRUE if the document is read only else false
    virtual bool isReadOnly() const = 0;

    // Access to the list of loaded Lisp applications
    virtual int GetCountOfLispList() const = 0;
    virtual CRxLispAppInfo* GetItemOfLispList(int nIndex) const = 0;

    // Return the drawing status bar
    virtual CRxApStatusBar* drawingStatusBar() const = 0;

    // Push/pop the current value of $DBMOD.  Non-virtual is intentional.
    void              pushDbmod();
    CDraft::ErrorStatus popDbmod();

    // Convert the document status from read only to write if possible.
    //
    CDraft::ErrorStatus upgradeDocOpen();

    // Convert the document status from writeable to read only.
    // If bPromptForSave is true - and the drawing is modified (based on dbmod)
    // the user is prompted to save the drawing. If bPromptForSave is
    // false and the drawing has been modified, an error is returned.
    //
    CDraft::ErrorStatus downgradeDocOpen(bool bPromptForSave);
};

// These two functions are to be deprecated
CDraft::ErrorStatus crxedUpgradeDocOpen();
CDraft::ErrorStatus crxedDowngradeDocOpen(bool bPromptForSave);

CRX_DEFINE_NULL_CLSID(CRxApDocManagerReactor)
class CRXEDAPI_CLASS CAXA_NO_VTABLE CRxApDocManagerReactor : public CRxObject
{
public:
    CRX_DECLARE_DYNAMIC(CRxApDocManagerReactor);

    // Fired when a document is first instantiated no database is available.
    virtual void              documentCreateStarted(CRxApDocument* pDocCreating);
    // Fired when a document has been successfully created replaces kLoadDwgMsg.
    virtual void              documentCreated(CRxApDocument* pDocCreating);
    // Fired when a document is about to be destroyed replaces kUnloadDwgMsg
    virtual void              documentToBeDestroyed(CRxApDocument* pDocToDestroy);
    // Fired when a document is completely destroyed
    virtual void              documentDestroyed(const CxCHAR* fileName);
    // Fired when a user action has cancelled a documents creation.
    // Only fired in MDI mode and after a documentCreateStarted
    virtual void              documentCreateCanceled(CRxApDocument* pDocCreateCancelled);


    virtual void              documentLockModeWillChange(CRxApDocument* ,
                                         CRxAp::DocLockMode myCurrentMode,
                                         CRxAp::DocLockMode myNewMode,
                                         CRxAp::DocLockMode currentMode,
                                         const CxCHAR* pGlobalCmdName);
    virtual void              documentLockModeChangeVetoed(CRxApDocument* ,
                                         const CxCHAR* pGlobalCmdName);
    virtual void              documentLockModeChanged(CRxApDocument* ,
                                         CRxAp::DocLockMode myPreviousMode,
                                         CRxAp::DocLockMode myCurrentMode,
                                         CRxAp::DocLockMode currentMode,
                                         const CxCHAR* pGlobalCmdName);

    virtual void              documentBecameCurrent(CRxApDocument* );
 
    // This reactor is fired PRIOR to a document becoming activated NOTE: The document
    // context will not be set yet see also documentActivated()
    virtual void              documentToBeActivated(CRxApDocument* pActivatingDoc );
    // Parallel to documentToBeActivated
    virtual void              documentToBeDeactivated(CRxApDocument* pDeActivatedDoc );

    // Notify  of changes caused by disableDocumentActivation() or enableDocumentActivation().
    // bActivation == TRUE when document activation is enabled FALSE when disabled.
    virtual void              documentActivationModified(bool bActivation);

    // This reactor is fired once a document has been activated and its context
    // successfully switched. NOTE: There are situations where document is
    // "activated" outside the normal UI user interaction. See also documentToBeActivated
    virtual void              documentActivated(CRxApDocument* pActivatedDoc);
protected:
    CRxApDocManagerReactor() : mVeto(0) {}
    CDraft::ErrorStatus         veto();

private:
    CAXA::Int8               mVeto;

friend class CrxApDocImpManager;
};

CRX_DEFINE_NULL_CLSID(CRxApDocumentIterator)
class CRXEDAPI_CLASS CAXA_NO_VTABLE CRxApDocumentIterator : public CRxObject
{
public:
    CRX_DECLARE_DYNAMIC(CRxApDocumentIterator);

    virtual bool    done() const = 0;
    virtual void              step() = 0;
    virtual CRxApDocument*       document() = 0;
};

CRX_DEFINE_NULL_CLSID(CRxApDocManager)
class CRXEDAPI_CLASS CAXA_NO_VTABLE CRxApDocManager : public CRxObject
{
public:
    CRX_DECLARE_DYNAMIC(CRxApDocManager);

    // curDocument() returns the document having current context.
    // mdiActiveDocument() returns the MDI active document.
    // curDocument() and mdiActiveDocument() can be different.
    // You can call curDocument() to make a document "current" 
    // without actually activating it. After finish your CrxDbDatabase
    // operation under the temporary current document, call
    // setCurDocument(crxDocManager->mdiActiveDocument())
    // to reset the MDI active document as the current document.
    virtual CRxApDocument*       curDocument() const = 0;
    virtual CRxApDocument*       mdiActiveDocument() const = 0;

    virtual bool    isApplicationContext() const = 0;

    virtual CRxApDocument*       document(const CRxDbDatabase* ) const = 0;

    virtual CDraft::ErrorStatus lockDocument(CRxApDocument* pDoc,
                                   CRxAp::DocLockMode = CRxAp::kWrite,
                                   const CxCHAR* pGlobalCmdName = NULL,
                                   const CxCHAR* pLocalCmdName = NULL,
                                   bool prompt = true) = 0;
    virtual CDraft::ErrorStatus unlockDocument(CRxApDocument* pDoc) = 0;

    virtual CRxApDocumentIterator* newAcApDocumentIterator() = 0;

    virtual void              addReactor(CRxApDocManagerReactor* ) = 0;
    virtual void              removeReactor(CRxApDocManagerReactor* ) = 0;

    virtual CDraft::ErrorStatus setDefaultFormatForSave(
                                CRxApDocument::SaveFormat format) = 0;

    //          Allows an external application running under the Application context
    //          to make a document "current" without actually activating it.
    //          This current state is only valid during the context of the function
    //          calling this API. This enables safe manipulation of a documents
    //          data without the document actually being the top most or
    //          active document. 
    //          The default parameters "mode" and "activate" allow document locking
    //          and activation to occur. These are shortcuts to allow several
    //          steps to be accomplished with a single API and can also
    //          be accomplished with the individual API calls.  
    virtual CDraft::ErrorStatus setCurDocument(CRxApDocument* pDoc,
                                   CRxAp::DocLockMode = CRxAp::kNone,
                                   bool activate = false) = 0;
    // Activate target document
    virtual CDraft::ErrorStatus activateDocument(CRxApDocument* pAcTargetDocument,
                                               bool bPassScript = false) = 0;

    // Send string to target document to execute by default
    // activate document. Allow the string to be executed as soon as
    // possible if "bActivate" is false" and "bWrapUpInactiveDoc" is true.
    // "bEchoString" determines whether the sent string is echoed on the
    // command line.
    virtual CDraft::ErrorStatus sendStringToExecute(CRxApDocument* pAcTargetDocument,
                                       const CxCHAR * pszExecute,
                                       bool bActivate = true,
                                       bool bWrapUpInactiveDoc = false,
                                       bool bEchoString = true) = 0;    

    // These two member functions allow synchronous access to NEW OPEN
    // They may only be called from the application context 
    // See also executeInApplicationContext() These APIs only
    // function in MDI mode.
    virtual CDraft::ErrorStatus appContextNewDocument(const CxCHAR *pszTemplateName) = 0;
    virtual CDraft::ErrorStatus appContextOpenDocument(const CxCHAR *pszDrawingName) = 0;

    // Open a drawing and switch to the layout or view specified, if any.
    // This will become a pure virtual method in a future release.
    struct DocOpenParams {
        union { // drawing file name
            const CxCHAR * mpszFileName;
            const wchar_t * mpwszFileName;
        };
        union { // layout or view name, or handle string
            const CxCHAR * mpszViewName;
            const wchar_t * mpwszViewName;
            const double * mpCoords;    // or world coords to zoom to
        };
        enum {kUnknown = 0,             // not used
              kDefaultView = 1,         // open in last saved view
              kLayoutName = 2,          // specify layout by name
              kViewName = 3,            // specify view by name
              kLayoutHandle = 4,        // specify layout by acdb handle
              kViewHandle = 5,          // specify view by acdb handle
              kViewWorldCoords = 6};
        BYTE mnInitialViewType;
        enum {  kDisallowReadOnly       = 0x01,
                kRequireReadOnly        = 0x02,
                kFileNameArgIsUnicode   = 0x04,
                kViewNameArgIsUnicode   = 0x08,
                kUseUIOnErrors          = 0x10};
        int  mnFlags;       // open it as readonly, etc
        const wchar_t * mpwszPassword;
        void  * mpUnused;
        int  mnUnused;
    };
    // This will be enabled in the next release where we can change
    // the application binary compatibility.
    // virtual CDraft::ErrorStatus appContextOpenDocument(
    //                 const DocOpenParams *pParams);

    // These three member functions provide standard, full user interaction,
    // to the NEW OPEN and CLOSE commands. They are asynchronous so if called
    // from a document context they will suspend the currently executing routine
    // until the orginal document context is re-activated. 
    virtual CDraft::ErrorStatus newDocument() = 0;
    virtual CDraft::ErrorStatus openDocument() = 0;
    virtual CDraft::ErrorStatus closeDocument(CRxApDocument* pAcTargetDocument) = 0;

    // Return the state of the documents input buffer in characters pending.
    // A return value of zero indicates the document is not "currently"
    // processing. Used only in conjunction with sendStringToExecute()
    // for automated testing purposes. Return -1 if error
    virtual int    inputPending(CRxApDocument* pAcTargetDocument) = 0;

    // APIs to allow control of whether a user can activate another
    // document. May be used by commands that process for long periods of time
    // and wish to allow special cancelation checking without the chance
    // the user might be able to activate another document.
    // Aplications MUST be sure to restore activation when complete.
    // Attempts to disable or enable when already in the requested state
    // will return an error
    virtual CDraft::ErrorStatus disableDocumentActivation() = 0;
    virtual CDraft::ErrorStatus enableDocumentActivation() = 0;
    virtual bool isDocumentActivationEnabled() = 0;

    // Allows a void function() to be called from the application context
    virtual void executeInApplicationContext(void (*procAddr)(void *), void *pData ) const = 0;

    // Return the number of currently open documents
    virtual int documentCount() const = 0;

    // Handle setting/saving/restoring of resouce file handles
    // pushResouceHandle pushes the current resource handle onto the
    // current document's resource handle stack and makes the specified
    // handle current.  pushAcadResourceHandle pushes the current resource
    // handle onto the current document's resource handle stack and makes
    // CaxaDraft's resource file current.  popResourceHandle makes the
    // resource file handle on top of the stack current and removes it from
    // the stack.


    virtual void pushResourceHandle( HINSTANCE hNewResourceHandle) = 0;
    virtual void pushAcadResourceHandle() = 0;
    virtual void popResourceHandle() = 0;
    // Causes a document waiting for input to return to the caller 
    virtual CDraft::ErrorStatus sendModelessInterrupt(CRxApDocument* pAcTargetDocument) = 0;
};



CRXEDAPI_API CRxApDocManager* crxDocManagerPtr();
#define crxDocManager crxDocManagerPtr()

inline CRxApDocument* curDoc() { return ::crxDocManager->curDocument(); }

#pragma pack (pop)
#endif // CRXDOCMAND_H

