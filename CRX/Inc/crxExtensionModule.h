//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//
//
// DESCRIPTION
//
//  This file provides two useful classes for developers of MFC extensions
// to eb(CRX applications in particular). There is no source file
// correponding to this file; the classes should be implemented in the DLL
// that includes this file (a task simplified by using the provided macros).
//
//////////////////////////////////////////////////////////////////////////////

#ifndef _CrxExtensionModule_h
#define _CrxExtensionModule_h

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

//#include "crxdocman.h"

/////////////////////////////////////////////////////////////////////////////
// CAcExtensionModule - MFC Extension Module and Resource Manager
//
//   This class serves two purposes - it provides a placeholder for an
// AFX_EXTENSION_MODULE structure (normally used to initialize or terminate
// an MFC extension DLL) and tracks two resource providers for the DLL.
//   The resource providers are the module's resources (normally the DLL
// itself, but may be set to some other module) and the default resources
// (normally the host application, actually the provider currently active
// when AttachInstance() is called). CAcExtensionModule tracks these to
// simplify switching MFC's resource lookup between the default and the
// module's.
//   A DLL should create exactly one instance of this class and provide the
// implementation for the class (use the macros included in this file and
// refer to the given example).

class CCrxExtensionModule {
public:
                CCrxExtensionModule ();
                ~CCrxExtensionModule ();

protected:
        BOOL    m_bAttached;
        HINSTANCE m_hDefaultResource;
        HINSTANCE m_hModuleResource;
        AFX_EXTENSION_MODULE m_module;

public:
        BOOL    Attached ();
        HINSTANCE DefaultResourceInstance ();
        HINSTANCE ModuleResourceInstance ();

        // Attaches the Extension DLL to MFC and updates the member
        // resource handles. Pass hInst as the module's resources.
        // Returns TRUE on success and FALSE otherwise. 
        // On success a corresponding call to DetachInstance() is
        // required before the DLL terminates.
        BOOL    AttachInstance (HINSTANCE hInst);

        // Detaches the Extension DLL from MFC.
        void    DetachInstance ();
};

inline CCrxExtensionModule::CCrxExtensionModule () :
    m_bAttached(FALSE),
    m_hDefaultResource(NULL),
    m_hModuleResource(NULL)
{
    m_module.bInitialized = FALSE;
    m_module.hModule = NULL;
    m_module.hResource = NULL;
    m_module.pFirstSharedClass = NULL;
    m_module.pFirstSharedFactory = NULL;
}

inline CCrxExtensionModule::~CCrxExtensionModule ()
{
}

inline BOOL CCrxExtensionModule::Attached ()
{
    return m_bAttached;
}

inline BOOL CCrxExtensionModule::AttachInstance (HINSTANCE hInst)
{
    if (m_bAttached)
        return FALSE;
    m_bAttached = AfxInitExtensionModule(m_module, hInst);
    if (m_bAttached) {
        m_hDefaultResource = AfxGetResourceHandle();
        m_hModuleResource = hInst;
        new CDynLinkLibrary(m_module);
    }
    return m_bAttached;
}

inline HINSTANCE CCrxExtensionModule::DefaultResourceInstance ()
{
    return m_hDefaultResource;
}

inline void CCrxExtensionModule::DetachInstance ()
{
    if (m_bAttached) {
        AfxTermExtensionModule(m_module);
        m_bAttached = FALSE;
    }
}

inline HINSTANCE CCrxExtensionModule::ModuleResourceInstance ()
{
    return m_hModuleResource;
}

/////////////////////////////////////////////////////////////////////////////
// CAcModuleResourceOverride - Switch between default and module's resources
//
//   Use an instance of this class to switch between resource providers. When
// the object is constructed a new resource provider will get switched in.
// Upon destruction the original resource provider will be restored. For
// example:
//
//      void MyFunc ()
//      {
//          CAcModuleResourceOverride myResources;
//              .
//              .
//      }
//
// Upon entry to this function the module's resources will be selected. When
// the function returns the default resources will be restored.
//   A resource override can be used in any of three ways:
//
//  o   Use the default constructor (no arguments) to switch to the module's
//      resources. The default resources will be restored by the destructor.
//      The module/default resources are those maintained by the DLL's
//      CAcExtensionModule.
//
//  o   Pass NULL (or 0) to the constructor. The DLL's resources will be
//      selected and the resources that were in effect will be restored when
//      the override object is destroyed.
//
//  o   Pass a non-NULL handle to the constructor. The associated module's
//      resources will be and the resources that were in effect will be
//      restored when the override object is destroyed.

class CCrxModuleResourceOverride {
public:
                    CCrxModuleResourceOverride ();
                    CCrxModuleResourceOverride (HINSTANCE hInst);
                    ~CCrxModuleResourceOverride ();

private:
HINSTANCE m_hResOrgMFC;
static  CCrxExtensionModule& m_extensionModule;
};

inline CCrxModuleResourceOverride::CCrxModuleResourceOverride ()
{
	m_hResOrgMFC = AfxGetResourceHandle();
	AfxSetResourceHandle( _AtlBaseModule.m_hInst );
    //crxDocManager->pushResourceHandle(m_extensionModule.ModuleResourceInstance());
}

inline CCrxModuleResourceOverride::CCrxModuleResourceOverride (HINSTANCE hInst)
{
   //crxDocManager->pushResourceHandle(hInst ? hInst : 
   //                               m_extensionModule.ModuleResourceInstance());
	m_hResOrgMFC = AfxGetResourceHandle();
	AfxSetResourceHandle( hInst ? hInst : _AtlBaseModule.m_hInst );
}

inline CCrxModuleResourceOverride::~CCrxModuleResourceOverride ()
{
		AfxSetResourceHandle( m_hResOrgMFC );
    //crxDocManager->popResourceHandle();
}

/////////////////////////////////////////////////////////////////////////////
// Extension Module Decalaration and Implementation Macros
//
//  Instatiate an extension module once in a single source file in your DLL
// project. If you want to access the extension module object from other
// source files in your project then use the declaration macro as well
// (usually in an include file). For example, an ARX application's main DLL
// source file might contain:
//
//      AC_IMPLEMENT_EXTENSION_MODULE(myDLL)
//
//      extern "C" int APIENTRY
//      DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
//      {
//	        // Remove this if you use lpReserved
//	        UNREFERENCED_PARAMETER(lpReserved);
//
//	        if (dwReason == DLL_PROCESS_ATTACH)
//	        {
//               theArxDLL.AttachInstance(hInstance);
//	        }
//	        else if (dwReason == DLL_PROCESS_DETACH)
//	        {
//               theArxDLL.DetachInstance();  
//	        }
//	        return 1;   // ok
//      }
//
//
// To publicize the extension module in this example to other source files
// add the following to the module's main include file:
//
//      AC_DECLARE_EXTENSION_MODULE(myDLL)

#define CRX_DECLARE_EXTENSION_MODULE(exm)        \
    extern CCrxExtensionModule exm;

#define CRX_IMPLEMENT_EXTENSION_MODULE(exm)      \
    CCrxExtensionModule exm;                     \
    CCrxExtensionModule& CCrxModuleResourceOverride::m_extensionModule = exm;

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif
