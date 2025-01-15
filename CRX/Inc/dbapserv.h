//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#ifndef CrxDbHostApplicationServices_INC
#define CrxDbHostApplicationServices_INC

#include "cdraft.h"
#include "crxDb.h"
#include "crxArray.h"
#include "codepgid.h"
#include "crxdlflagbits.h"

// Internet-related status codes
#include "inetstrc.h"
#include "rxdlinkr.h"

#pragma pack (push, 8)

class CRxDbAuditInfo;
class CRxDbDatabase;
class CRxDbUndoController;
class CRxDbTransactionManager;
class CRxDbGlobals;
class CRxDbAppSystemVariables;
class COleClientItem;
class CArchive;
class CRxInternalServices;
struct flagmat;

class CRxDbAbstractClipBoundaryDefinition;
class ClipBoundaryArray;

class CRxDbPlotSettingsValidator;
class CRxDbLayoutManager;
class CRxPwdCache;

struct _EXCEPTION_POINTERS;

#ifndef ACUTIL_API
#    ifdef ACUTIL_INTERNAL
#        define ACUTIL_API __declspec(dllexport)
#    else
#        define ACUTIL_API __declspec(dllimport)
#    endif
#endif

typedef unsigned long LCID;

enum  CRxSDIValues {
    kMDIEnabled = 0,
    kSDIUserEnforced,
    kSDIAppEnforced,
    kSDIUserAndAppEnforced
};

enum ProdIdCode {
    kProd_ACAD = 1,
    kProd_LT,
    kProd_OEM,
    kProd_AcDb
};

int crxdbHostAppMinorVersion();

class CRxDbHostApplicationProgressMeter {
public:
    CRxDbHostApplicationProgressMeter();
    virtual ~CRxDbHostApplicationProgressMeter();

    virtual void start(const CxCHAR * displayString = NULL);
    virtual void stop();
    
    virtual void meterProgress();

    virtual void setLimit(int max);

};

typedef CDraft::ErrorStatus (*SELECTFILEPROC )(/*[out]*/ short *userCancel, 
                                             /*[out]*/ CxCHAR *& chosenPath,
                                             void* h, // HWND
                                             const int nFlags,
                                             const CxCHAR * prompt,
                                             const CxCHAR * dir,
                                             const CxCHAR * name,
                                             const CxCHAR * type,
                                             int* pnChoice,
                                             bool* pbReadOnly,
                                             const CxCHAR * pszWSTags,
                                             void* pReserved);

typedef CDraft::ErrorStatus (* REMAPPROC) (/*[out]*/ CxCHAR *& newName,
                                         const CxCHAR * filename,
                                         int context,
                                         void* pReserved);

typedef void (* MAPFILENOTIFYPROC) (const CxCHAR * filename,
                                    const CxCHAR * newName,
                                    int context,
                                    void* pReserved);

CRX_DEFINE_NULL_CLSID(CRxDbHostApplicationServices)
class CRXDB_CLASS CRxDbHostApplicationServices : public CRxObject
{
    friend CRxInternalServices;
public:    
    CRX_DECLARE_DYNAMIC(CRxDbHostApplicationServices);
    CRxDbHostApplicationServices( int createGlobals = 1 );
    virtual ~CRxDbHostApplicationServices();

    enum FindFileHint
    {
        kDefault = 0,
        kFontFile,              // Could be either
        kCompiledShapeFile,     // shx
        kTrueTypeFontFile,      // ttf
        kEmbeddedImageFile,
        kXRefDrawing,
        kPatternFile,
        kARXApplication,
        kFontMapFile,
        kUnderlayFile
    };
    
    enum RemapFileContext
    {
        kDrawingOpen,
        kXrefResolution,
        kRasterResolution,
        kAfterXrefResolution
    };

    // When a file path is required
    //
    virtual CDraft::ErrorStatus findFile(CxCHAR * pcFullPathOut,
                 int   nBufferLength,
                 const CxCHAR * pcFilename,
                 CRxDbDatabase * pDb = NULL, // When this search 
                                            // is related to a db
                 CRxDbHostApplicationServices::FindFileHint hint = kDefault) = 0;

    // These two functions return the full path to the root folder where roamable/local 
    // customizable files were installed. The default implementation is to return the
    // directory where the EXE is located.  These methods can be overridden by DBX
    // applications for their own install structure.  Note that the user may have 
    // reconfigured the location of some of the customizable files using the Options 
    // Dialog, therefore these functions should not be used to locate all customizable 
    // files. To locate customizable files either use the findFile function or the 
    // appropriate system variable for the given file type. 
    //
    virtual CDraft::ErrorStatus getRoamableRootFolder(const CxCHAR *& folder);
    virtual CDraft::ErrorStatus getLocalRootFolder(const CxCHAR *& folder);

    // Select File APIs
    virtual CDraft::ErrorStatus   selectFile(short *userCancel, 
                                           CxCHAR *& chosenPath,
                                           void* h, // HWND
                                           const int nFlags,
                                           const CxCHAR * prompt,
                                           const CxCHAR * dir,
                                           const CxCHAR * name,
                                           const CxCHAR * type,
                                           int* pnChoice,
                                           bool* pbReadOnly,
                                           const CxCHAR * pszWSTags,
                                           void* pReserved) ;
    virtual CDraft::ErrorStatus   registerSelectFileCallback(const CxCHAR * appName,
                                                   SELECTFILEPROC proc, 
                                                   bool unRegister = false, 
                                                   bool asPrimary  = false);
    virtual const CxCHAR *       primaryClientForSelectFileCallback();
    virtual CDraft::ErrorStatus   getRegisteredSelectFileClients(
                                            CRxArray<const CxCHAR *>& clients);

    // File remapping
    virtual CDraft::ErrorStatus   mapFile(/*out*/ CxCHAR *& newName,
                                        const CxCHAR * filename,
                                        int context,
                                        void* pReserved);
    virtual CDraft::ErrorStatus   registerMapFileCallback(const CxCHAR * appName,
                                                REMAPPROC  proc,
                                                bool unRegister = false, 
                                                bool asPrimary  = false);
    virtual const CxCHAR *       primaryClientForMapFileCallback();
    virtual bool                setMapFlag(bool setIt);
    virtual CDraft::ErrorStatus   getRegisteredFileMapClients(
                                            CRxArray<const CxCHAR *>& clients);
    virtual CDraft::ErrorStatus   registerMapFileNotification(const CxCHAR * appName, 
                                                MAPFILENOTIFYPROC,
                                                bool unRegister = false);

    // When a fatal error is encountered this function may be called
    // to notify you.
    //
    virtual void fatalError(const CxCHAR *format, ...);

    // Called when an unhandled exception occurs in an crx command or message.
    // The EXCEPTION_POINTERS pointer is obtained from the win32 api:
    // GetExceptionInformation().
    //
    virtual void reportUnhandledArxException(const _EXCEPTION_POINTERS *pExcPtrs,
                                             const CxCHAR *pAppName);

    // The equivalent of ads_usrbrk()
    //
    virtual CAXA::Boolean userBreak(bool updCtrlsWhenEnteringIdle = true) const;

    virtual void displayChar(CxCHAR c) const;
    virtual void displayString(const CxCHAR* string, int count) const;

    // This function will be called to check if the application
    // wants to show text messages. Default implementation is always 
    // returning true;
    virtual CAXA::Boolean readyToDisplayMessages();

    // This function can be used to used to programmatically change the
    // state of readyToDisplayMessages.  
    virtual void enableMessageDisplay(CAXA::Boolean);

    // Instructs the system to run fulltime CRC checking on database
    // filing operations.
    virtual CAXA::Boolean doFullCRCCheck();

    // Indicates where temporary files are to be located.  See WINSDK 
    // function GetTempPath() for details on the argument and the return
    // value.
    virtual unsigned int getTempPath(CAXA::UInt32 lBufferSize, 
                                                CxCHAR* pcBuffer);

    // gets the value of a command switch, or an environment variable, or
    // registry entry (the search is in that order).  This is the same
    // behavior as the LISP (getenv) function).  Default implementation
    // is to return NULL.
    //
    virtual const CxCHAR* getEnv(const CxCHAR * var);

    // Whenever CRxDb.dll needs to instantiate a progress meter, it will
    // call this method.
    // If you want to create your own progress meter, derive from
    // CRxDbHostApplicationProgressMeter, and override this method to
    // to return a progress meter of your derived type.
    //
    virtual CRxDbHostApplicationProgressMeter* newProgressMeter();

    // In other cases, CRxDb.dll expects to make use of one global
    // instance of a progress meter that is always available.  To
    // set that progress meter to one of your own type, instantiate
    // your meter and pass it to the following function.
    void setWorkingProgressMeter(CRxDbHostApplicationProgressMeter* pNewMeter);

    virtual CRxDbAbstractClipBoundaryDefinition* newClipBoundaryRectangular();
    virtual CRxDbAbstractClipBoundaryDefinition* newClipBoundaryPolygonal();
    virtual ClipBoundaryArray* newClipBoundaryArray();

    // Should point to a viable database.  The application is free to
    // reset this according to its need.  Some entites will require
    // access to information within a database in order to function
    // properly when they are not yet database-resident.
    //
    CRxDbDatabase* workingDatabase() const;
    void setWorkingDatabase(CRxDbDatabase* pDatabase);

    virtual CRxDbUndoController* defaultUndoController();
    void setDefaultUndoController(CRxDbUndoController* pUndoCtrl);

    virtual CRxDbTransactionManager* workingTransactionManager();
    void setWorkingTransactionManager(CRxDbTransactionManager* pTM);

    virtual CRxDbGlobals * createWorkingGlobals();
    CRxDbGlobals * workingGlobals() const;
    void setWorkingGlobals(CRxDbGlobals* pGlobals);
    
    CRxDbAppSystemVariables * workingAppSysvars() const;
    void setWorkingAppSysvars(CRxDbAppSystemVariables* pSysvars);

    virtual const CxCHAR * program ();
    virtual const CxCHAR * product ();
    virtual const CxCHAR * companyName();
    virtual const ProdIdCode prodcode();
    virtual const CxCHAR * releaseMajorMinorString();
    virtual int   releaseMajorVersion();
    virtual int   releaseMinorVersion();
    virtual const CxCHAR * versionString();
    virtual const CxCHAR * getRegistryProductRootKey ();
    virtual LCID  getRegistryProductLCID() ;
    virtual bool  supportsMultiRedo() const { return false; }
    enum ModelerFlavor {kModelerFull=0, kModelerRegionsOnly=1, kModelerObjectsOnly=2};
    virtual ModelerFlavor  getModelerFlavor() const { return CRxDbHostApplicationServices::kModelerFull; }

    code_page_id getSystemCodePage() const;

    // Deprecated: do not use this function!
    void setSystemCodePage(code_page_id);

    virtual CRxInternalServices* acadInternalServices();

    void * crxadInternalGetvar (const CxCHAR *name);

    // BEGIN: Internet-related services

    // Determine whether a given string ('pszURL') is a valid URL.
    //
    virtual CAXA::Boolean isURL(const CxCHAR * pszURL) const;

    // 'isRemoteFile()' is the inverse of 'isURL()'--it provides a mapping
    // from a local file to the corresponding URL that the file was down-
    // loaded from. The URL, if any, is returned via 'pszURL.'
    //
    virtual CAXA::Boolean isRemoteFile(const CxCHAR * pszLocalFile,
                                          CxCHAR * pszURL) const;

    // Download a resource (file) identified by the URL 'pszURL' to a local
    // file, and return its name in the buffer pointed to by 'pszLocalFile.' 
    // The boolean argument 'bIgnoreCache' determines whether the file should 
    // be downloaded even if it has already been transferred earlier in the 
    // session.
    //
    virtual CDraft::ErrorStatus getRemoteFile(const CxCHAR * pszURL,
     CxCHAR * pszLocalFile, CAXA::Boolean bIgnoreCache = CAXA::kFalse) const;

    // Upload a local resource (file) identified by the pathname 'pszLocalFile'
    // to the remote location specified by the URL 'pszURL.'
    //
    virtual CDraft::ErrorStatus putRemoteFile(const CxCHAR * pszURL, 
        const CxCHAR * pszLocalFile) const;

    // Launch the Web Browser dialog that allows the user to navigate to any 
    // site and select a URL. The selected URL is returned in 'pszSelectedURL,' 
    // which must point to a buffer large enough to hold the return value. 
    // 'pszDialogTitle' and 'pszOpenButtonCaption' allow developers to supply 
    // text for the dialog title and the button caption, that is more 
    // meaningful in the context in which the dialog is being invoked. The 
    // parameter 'pszStartURL' is a URL that the Web Browser uses as its start 
    // page. The fifth argument is optional, and identifies the product root 
    // key under which the Web Browser dialog's size and position information 
    // is stored for persistence across sessions.
    // The last parameter determines whether the user can select HTML links
    // in addition to files that are "downloadable."
    //
    virtual CAXA::Boolean launchBrowserDialog(
                 CxCHAR *          pszSelectedURL,
                 const CxCHAR *    pszDialogTitle,
                 const CxCHAR *    pszOpenButtonCaption,
                 const CxCHAR *    pszStartURL, 
                 const CxCHAR *    pszRegistryRootKey = 0,
                 CAXA::Boolean bOpenButtonAlwaysEnabled = CAXA::kFalse) const;

    // OLE Embedded Objects 
    // Draw OLE object using given HDC, objectID and rectangle in screen 
    // coordinate.
    //
    virtual void drawOleOwnerDrawItem(COleClientItem* pItem,
                                      CAXA::LongPtr hdc, 
        long left, long top, long right, long bottom);

    // Get COleClientItem from Host application.
    virtual CDraft::ErrorStatus getNewOleClientItem(COleClientItem*& pItem);

    // Called by AcDb when it needs to translate an OLE embedded object.
    virtual CDraft::ErrorStatus serializeOleItem(COleClientItem* pItem,
        CArchive*);

    // This method is renamed from entToWorldTransform() because it is for
    // Internal Use only and will be removed in future.
    // 
    virtual CAXA::Boolean _entToWorldTransform(double normal[3], 
                                                flagmat *tran);

    virtual void terminateScript(); // end any running scripts

    // get substitute font for unfound font
    virtual CAXA::Boolean getSubstituteFont(CxCHAR **pFileName,
                                             CxCHAR *prompt, 
                                             int type, int fontAlt); 
    virtual void alert(const CxCHAR * string) const;

    virtual void auditPrintReport(CRxDbAuditInfo * pAuditInfo,
                                             const CxCHAR *    line,
                                             int             both) const;

    virtual CxCHAR * getAlternateFontName() const { return CRX_T(""); }

    virtual CxCHAR * getFontMapFileName() const { return CRX_T(""); }

    virtual bool cacheSymbolIndices() const { return false; }

    virtual CRxDbPlotSettingsValidator* plotSettingsValidator() const; 
    virtual CRxDbLayoutManager* layoutManager() const;
    virtual bool loadApp(const CxCHAR * appName, 
                         CDraftApp::LoadReasons why, 
                         bool printit, 
                         bool asCmd);
    virtual void getDefaultPlotCfgInfo(CxCHAR * plotDeviceName,
                                       CxCHAR * plotStyleName); 

    // BEGIN: DWG Security-related services
    virtual CDraft::ErrorStatus signingComplete(CDraft::ErrorStatus es,
                                              const CxCHAR * msg,
                                              bool* result);

    enum PasswordOptions {kPasswordOptionDefault = 0, kPasswordOptionUpperCase =1, kPasswordOptionIsExternalReference = 2};
    virtual bool getPassword(const CxCHAR * dwgName,
                             PasswordOptions options,
                             wchar_t *password, 
                             const size_t bufSize);

    virtual void usedPasswordFromCacheMsg(const CxCHAR *dwgName);
    virtual void missingCryptoProviderMsg();

    virtual const CxCHAR * getColorBookLocation() const { return NULL; }

    CRxPwdCache * getPasswordCache() const;

protected:
    
    // This method is used by the Internet-related methods of all classes that
    // derive from CrxDbHostApplicationServices, to map a status code returned by
    // an Internet operation to an CDraft::ErrorStatus value.
    //
    CDraft::ErrorStatus mapInetStatusToAcadStatus(
        const CDraftInet::Status status) const;

    // END: Internet-related services

protected:

    void * mp_sessionVars;

    void crxadInternalSetvar (const CxCHAR *name, void * var);

private:
    // NOTES:
    // As session-specific globals are gathered up during the CRxDb.DLL and
    // MDI projects, if the DB requires them, they should be contained here,
    // and appropriate get/set methods created above.  References to those 
    // globals should be replaced by references to methods on this class or 
    // a derived class.  This header will ship with Tahoe Unplugged, but not 
    // Tahoe ARX.  These comments to be deleted before FCS.

    CRxDbDatabase* mpWorkingDatabase;
    CRxDbUndoController* mpDefaultUndoController;
    CRxDbTransactionManager* mpWorkingTransactionManager;
    CRxDbGlobals * mpWorkingGlobals;
    CRxDbAppSystemVariables * mpWorkingAppSysvars;

    code_page_id m_eSystemCodePage;
                                // Formerly "system_code_page".
                                // Moved from module xstring.cpp.
    CAXA::Boolean mbDisplayMessages;

    CRxPwdCache * mpPasswordCache;
};

// Use this method to replace the default services, you should do this 
// early on, in the InitInstance of your application for example.
//
CRXDB_API CDraft::ErrorStatus crxdbSetHostApplicationServices(CRxDbHostApplicationServices * pServices);

// Use this method to access the services
//
CRXDB_API CRxDbHostApplicationServices * crxdbHostApplicationServices();

// A host application would use this function to send notification to
// clients, e.g. Object Enablers, when it's done reading the initial
// set of objects from a dwg file. This is different from what 
// readDwgFile() would read. readDwgFile() reads the basic set,
// but a host application would, depending on the functionality it's
// implementing, read some more objects, and let everyone know that
// it's done. 
//
CDraft::ErrorStatus crxdbSendInitialDwgFileOpenComplete(CRxDbDatabase* pDb);

CRXDB_API CRxDbGlobals* getDefaultGlobals();

inline CRxDbGlobals *
CRxDbHostApplicationServices::workingGlobals() const
{
    return mpWorkingGlobals ? mpWorkingGlobals : getDefaultGlobals();
}

inline code_page_id
CRxDbHostApplicationServices::getSystemCodePage() const
{
    return this->m_eSystemCodePage;
}

inline CRxDbUndoController *
CRxDbHostApplicationServices::defaultUndoController()
{
    return mpDefaultUndoController;
}

inline CRxDbTransactionManager *
CRxDbHostApplicationServices::workingTransactionManager()
{
    return mpWorkingTransactionManager;
}

inline CRxDbDatabase *
CRxDbHostApplicationServices::workingDatabase() const
{
    return mpWorkingDatabase;
}

inline CRxDbAppSystemVariables * 
CRxDbHostApplicationServices::workingAppSysvars() const
{
    return mpWorkingAppSysvars;
}

inline void 
CRxDbHostApplicationServices::setWorkingAppSysvars(CRxDbAppSystemVariables* pSysvars)
{
    mpWorkingAppSysvars = pSysvars;
}

inline void 
CRxDbHostApplicationServices::terminateScript()
{
    return;
}

inline void 
CRxDbHostApplicationServices::reportUnhandledArxException(
                    const _EXCEPTION_POINTERS *pExcPtrs,
                    const CxCHAR *pAppName)
{
    return;
}

inline CDraft::ErrorStatus
CRxDbHostApplicationServices::selectFile(/*[out]*/ short *userCancel,
                                        /*[out]*/ CxCHAR *& chosenPath,
                                        void* h, // HWND
                                        const int nFlags,
                                        const CxCHAR * prompt,
                                        const CxCHAR * dir,
                                        const CxCHAR * name,
                                        const CxCHAR * type,
                                        int* pnChoice,
                                        bool* pbReadOnly,
                                        const CxCHAR * pszWSTags,
                                        void* pReserved) 
{ 
    return CDraft::eNotHandled;
}

inline CDraft::ErrorStatus   
CRxDbHostApplicationServices::registerSelectFileCallback(const CxCHAR * appName,
                                                        SELECTFILEPROC proc, 
                                                        bool unRegister, 
                                                        bool asPrimary)
{
    return CDraft::eNotImplemented;
}
inline const CxCHAR *
CRxDbHostApplicationServices::primaryClientForSelectFileCallback() 
{
    return NULL;
}

    // File remapping
inline CDraft::ErrorStatus 
CRxDbHostApplicationServices::mapFile(CxCHAR *& newName,
                                     const CxCHAR * filename,
                                     int context,
                                     void* pReserved) 
{
    return CDraft::eNotHandled;
}
    
inline CDraft::ErrorStatus
CRxDbHostApplicationServices::registerMapFileCallback(const CxCHAR *, REMAPPROC,
                                                     bool unRegister,
                                                     bool asPrimary)
{
    return CDraft::eNotImplemented;
}
    
inline const CxCHAR *
CRxDbHostApplicationServices::primaryClientForMapFileCallback() 
{
    return NULL;
}

inline
CDraft::ErrorStatus
CRxDbHostApplicationServices::getRegisteredSelectFileClients(
                                            CRxArray<const CxCHAR *>& clients)
{
    return CDraft::eNotImplemented;
}

inline
CDraft::ErrorStatus
CRxDbHostApplicationServices::getRegisteredFileMapClients(
                                            CRxArray<const CxCHAR *>& clients)
{
    return CDraft::eNotImplemented;
}

inline CDraft::ErrorStatus
CRxDbHostApplicationServices::registerMapFileNotification(const CxCHAR * appName, 
                                                         MAPFILENOTIFYPROC,
                                                         bool unRegister)
{
    return CDraft::eNotImplemented;
}

inline bool
CRxDbHostApplicationServices::setMapFlag(bool setIt)
{
    return false;
}

inline CRxPwdCache * 
CRxDbHostApplicationServices::getPasswordCache() const
{
    return mpPasswordCache;
}

// crxdbTriggerAcadOctTreeReclassification
//
// *** For Internal Use Only ***
// 
void crxdbTriggerAcadOctTreeReclassification();

// crxdbSetBreak3dQueueForRegen
//
// *** For Internal Use Only ***
// 
CDraft::ErrorStatus crxdbSetBreak3dQueueForRegen(bool);

CRXDB_API void crxdbUpdate3DElement();


//Derived classes are expected to override tryPassword and cache a
//file moniker (file name, file handle etc.) during construction so
//they can try the passwords passed to tryPassword. 
// Here are the possible conditions for wszPassword:
// NULL     = check the password cache first then prompt for password
// "value"  = try the supplied value then the cache but don't prompt for another password if it fails
// ""       = skip the cache and the prompt and just fail if encrypted
class CAXA_NO_VTABLE CRxDbPasswordedFile
{
protected:
    virtual CDraft::ErrorStatus tryPassword(const wchar_t* wzPassword) = 0;
    virtual const CxCHAR* getFullPath() = 0;
public:
    CDraft::ErrorStatus open(const wchar_t* wszPassword, CRxDbHostApplicationServices::PasswordOptions options);
};

#pragma pack (pop)

#endif


