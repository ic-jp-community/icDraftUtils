//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//

#ifndef _rxdlinkr_h
#define _rxdlinkr_h 1

class CRxDLinkerReactor;
class CRxService;

#include "rxobject.h"
#include "crxChar.h"
#pragma pack (push, 8)

struct CDraftApp
{
    enum LoadReasons {
        kOnProxyDetection       = 0x01,
        kOnCaxaDraftStartup       = 0x02,
        kOnCommandInvocation    = 0x04,
        kOnLoadRequest          = 0x08,
        kLoadDisabled           = 0x10,
        kTransparentlyLoadable  = 0x20,
        kOnIdleLoad             = 0x40
    };

    enum ErrorStatus {
        eOk             = 0,
        eInvalidKey     = 1,
        eInvalidSubKey  = 2,
        eKeyNotFound    = 3,
        eOutOfMemory    = 4,
        eInvalidValue   = 5,
        eValueNotFound  = 6,
        eKeyExists      = 7,
        eRegAccessDenied= 8,
        eRejected       = 9,
        eUnknownError   = 10
    };
};





class CAXA_NO_VTABLE CRxDynamicLinker: public CRxObject
{
public:
    CRX_DECLARE_DYNAMIC(CRxDynamicLinker);

    virtual void*          getSymbolAddress (const CxCHAR * serviceName,
                                             const char * symbol) const = 0;
#ifdef AD_UNICODE
    // Overload it for convenience of callers that want to
    // put _T() around all literals.
    virtual void*          getSymbolAddress (const CxCHAR * serviceName,
                                             const CxCHAR * symbol) const = 0;
#endif

    virtual bool           initListedModules(const CxCHAR * fileName) = 0;

    virtual bool           loadModule       (const CxCHAR * fileName, 
                                             bool printit,
                                             bool asCmd=false) = 0;
    virtual bool           loadApp          (const CxCHAR  * appName,
                                             CDraftApp::LoadReasons al,
                                             bool printit,
                                             bool asCmd=false) = 0;

    virtual CRxObject*    registerService  (const CxCHAR * serviceName,
                                             CRxService* serviceObj) = 0;

    virtual bool           unloadModule     (const CxCHAR * fileName,
                                            bool asCmd=false) = 0;
    virtual bool           unloadApp        (const CxCHAR * appName,
                                            bool asCmd=false) = 0;

    virtual void           addReactor       (CRxDLinkerReactor* newReactor) =0;

    virtual void           removeReactor    (CRxDLinkerReactor* oldReactor) =0;

    virtual bool           isApplicationLocked(const CxCHAR * modulename) const =0;
    virtual bool           lockApplication  (void* appId) const = 0;
    virtual bool           unlockApplication(void* appId) const = 0;

    virtual bool           isAppMDIAware(const CxCHAR * modulename) const =0;
    virtual bool           registerAppMDIAware(void* appId) const =0;
    virtual bool           registerAppNotMDIAware(void* appId) const =0;
 
    virtual bool           isAppBusy(const CxCHAR * modulename) const =0;
    virtual void           setAppBusy(const CxCHAR * modulename, bool bBusyFlag) const =0;

    virtual const CxCHAR    *ProductKey      () const = 0;
    virtual CAXA::UInt32  ProductLcid() const =0;

};


//  The kernel creates the one and only dynamic linker, at
//
#define CRxDynamicLinker                                               \
CRxDynamicLinker::cast(crxSysRegistry()->at(CRX_DYNAMIC_LINKER))

class CAXA_NO_VTABLE CRxDLinkerReactor: public CRxObject
//
// Class defining notification events from the dynamic linker,
// specifically the loading and unloading of Crx applications.
//
// Recipients of these calls can and should also
// check the registered services, class and objects to find out
// what happened to logical elements of the system, rather
// than be bound to file name.
//
{
  public:
    CRX_DECLARE_DYNAMIC(CRxDLinkerReactor);

    virtual void rxAppWillBeLoaded(const CxCHAR  * moduleName);
    virtual void rxAppLoaded(const CxCHAR  * moduleName);
    virtual void rxAppLoadAborted(const CxCHAR  * moduleName);

    virtual void rxAppWillBeUnloaded(const CxCHAR  * moduleName);
    virtual void rxAppUnloaded(const CxCHAR  * moduleName);
    virtual void rxAppUnloadAborted(const CxCHAR  * moduleName);
};


#pragma pack (pop)
#endif
