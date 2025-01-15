#ifndef __DBXENTRYPONIT_H_
#define __DBXENTRYPONIT_H_
//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//
#pragma once
#include "CRxDefine.h"
#include "rxclass.h"
#include "crxCHAR.h"

//-----------------------------------------------------------------------------
#define _RXST(a) _ACRX_T(a)

//-----------------------------------------------------------------------------

struct _DBX_REGISTER_OBJECT_ENTRY {
	CRxClass* (*desc) () ;
	void (*rxInit) () ;
	bool bRegistered ;
} ;

#pragma section("DBXCUSTOBJ$__a", read, shared)
#pragma section("DBXCUSTOBJ$__z", read, shared)
#pragma section("DBXCUSTOBJ$__m", read, shared)

extern "C" {
	__declspec(selectany) __declspec(allocate("DBXCUSTOBJ$__a")) _DBX_REGISTER_OBJECT_ENTRY* __pDbxCustObjMapEntryFirst =NULL ;
	__declspec(selectany) __declspec(allocate("DBXCUSTOBJ$__z")) _DBX_REGISTER_OBJECT_ENTRY* __pDbxCustObjMapEntryLast =NULL ;
}

#ifdef _WIN64
#define CRXDB_REGISTER_OBJECT_ENTRY_PRAGMA(classname) __pragma(comment(linker, "/include:__pDbxCustObjMap_" #classname)) ;
#else
#define CRXDB_REGISTER_OBJECT_ENTRY_PRAGMA(classname) __pragma(comment(linker, "/include:___pDbxCustObjMap_" #classname)) ;
#endif

#define CRXDB_REGISTER_OBJECT_ENTRY_AUTO(classname) \
	__declspec(selectany) _DBX_REGISTER_OBJECT_ENTRY __DbxCustObjMap_##classname = { classname::desc, classname::rxInit } ; \
	extern "C" __declspec(allocate("DBXCUSTOBJ$__m")) __declspec(selectany) _DBX_REGISTER_OBJECT_ENTRY* const __pDbxCustObjMap_##classname = &__DbxCustObjMap_##classname ; \
	CRXDB_REGISTER_OBJECT_ENTRY_PRAGMA(classname)

//-----------------------------------------------------------------------------
#define DISPATCH_PKTMSG(pktmsg) case CxRx::pktmsg: return (On_ ##pktmsg (pkt))

extern HINSTANCE _hdllInstance ;

//-----------------------------------------------------------------------------

class CRxDbxApp {

protected:
	HINSTANCE m_hdllInstance ;
	bool m_bUnlocked ;
	bool m_bMDIAware ;

public:
	CRxDbxApp () : m_hdllInstance(NULL), m_bUnlocked(true), m_bMDIAware(true) {}
	virtual CxRx::AppRetCode On_kInitAppMsg (void *pkt) {
		//- Save the module instance
		m_hdllInstance =_hdllInstance ;
		//----- Unlock application, so user can unload it
		//		if ( m_bUnlocked == true )
		//			crxDynamicLinker->unlockApplication (pkt) ;
		//----- Register the application as MDI capable in ACAD environment
		//		if ( m_bMDIAware == true )
		//			crxDynamicLinker->registerAppMDIAware (pkt) ;
		//----- Self-register application components such as
		//----- COM server / Custom entity registry information, ...
		RegisterServerComponents () ;
		//----- Register ObjectDBX custom classes
		int nDbxCustObjCount =0 ;
		_DBX_REGISTER_OBJECT_ENTRY **ppDbxCustObjMapEntryFirst =&__pDbxCustObjMapEntryFirst + 1 ;
		_DBX_REGISTER_OBJECT_ENTRY **ppDbxCustObjMapEntryLast =&__pDbxCustObjMapEntryLast ;
		for ( _DBX_REGISTER_OBJECT_ENTRY **ppEntry =ppDbxCustObjMapEntryFirst ; ppEntry < ppDbxCustObjMapEntryLast ; ppEntry++ ) {
			if ( *ppEntry != NULL ) {
				nDbxCustObjCount++ ;
				(*ppEntry)->rxInit () ;
				(*ppEntry)->bRegistered =true ;
			}
		}
		if ( nDbxCustObjCount > 0 )
			CrxrxBuildClassHierarchy () ;
        return (CxRx::kRetOK) ;
	}
	virtual CxRx::AppRetCode On_kUnloadAppMsg (void *pkt) {
		_DBX_REGISTER_OBJECT_ENTRY **ppDbxCustObjMapEntryFirst =&__pDbxCustObjMapEntryFirst + 1 ;
		_DBX_REGISTER_OBJECT_ENTRY **ppDbxCustObjMapEntryLast =&__pDbxCustObjMapEntryLast ;
		for ( _DBX_REGISTER_OBJECT_ENTRY **ppEntry =ppDbxCustObjMapEntryFirst ; ppEntry < ppDbxCustObjMapEntryLast ; ppEntry++ ) {
			if ( *ppEntry != NULL && (*ppEntry)->bRegistered == true )
				DeleteClassAndDescendant (ppEntry) ;
		}
        return (CxRx::kRetOK) ;
    }
    virtual CxRx::AppRetCode On_kLoadDwgMsg (void *pkt) { return (CxRx::kRetOK) ; }
    virtual CxRx::AppRetCode On_kUnloadDwgMsg (void *pkt) { return (CxRx::kRetOK) ; }
    virtual CxRx::AppRetCode On_kInvkSubrMsg (void *pkt) { return (CxRx::kRetOK) ; }
    virtual CxRx::AppRetCode On_kCfgMsg (void *pkt) { return (CxRx::kRetOK) ; }
    virtual CxRx::AppRetCode On_kEndMsg (void *pkt) { return (CxRx::kRetOK) ; }
    virtual CxRx::AppRetCode On_kQuitMsg (void *pkt) { return (CxRx::kRetOK) ; }
    virtual CxRx::AppRetCode On_kSaveMsg (void *pkt) { return (CxRx::kRetOK) ; }
    virtual CxRx::AppRetCode On_kDependencyMsg (void *pkt) { return (CxRx::kRetOK) ; }
    virtual CxRx::AppRetCode On_kNoDependencyMsg (void *pkt) { return (CxRx::kRetOK) ; }
    virtual CxRx::AppRetCode On_kOleUnloadAppMsg (void *pkt) { return (CxRx::kRetOK) ; }
    virtual CxRx::AppRetCode On_kPreQuitMsg (void *pkt) { return (CxRx::kRetOK) ; }
    virtual CxRx::AppRetCode On_kInitDialogMsg (void *pkt) { return (CxRx::kRetOK) ; }
    virtual CxRx::AppRetCode On_kEndDialogMsg (void *pkt) { return (CxRx::kRetOK) ; }
    virtual CxRx::AppRetCode On_kNullMsg (void *pkt) { return (CxRx::kRetOK) ; }

	CxRx::AppRetCode crxrxEntryPoint (CxRx::AppMsgCode msg, void *pkt) {
		switch ( msg ) {
			DISPATCH_PKTMSG (kInitAppMsg) ;
			DISPATCH_PKTMSG (kUnloadAppMsg) ;
			DISPATCH_PKTMSG (kLoadDwgMsg) ;
			DISPATCH_PKTMSG (kUnloadDwgMsg) ;
			DISPATCH_PKTMSG (kInvkSubrMsg) ;
			DISPATCH_PKTMSG (kCfgMsg) ;
			DISPATCH_PKTMSG (kEndMsg) ;
			DISPATCH_PKTMSG (kQuitMsg) ;
			DISPATCH_PKTMSG (kSaveMsg) ;
			DISPATCH_PKTMSG (kDependencyMsg) ;
			DISPATCH_PKTMSG (kNoDependencyMsg) ;
			DISPATCH_PKTMSG (kOleUnloadAppMsg) ;
			DISPATCH_PKTMSG (kPreQuitMsg) ;
			DISPATCH_PKTMSG (kInitDialogMsg) ;
			DISPATCH_PKTMSG (kEndDialogMsg) ;
			DISPATCH_PKTMSG (kNullMsg) ;
		}
        return (CxRx::kRetOK) ;
	}

	virtual void RegisterServerComponents () = 0 ;
	HINSTANCE &GetModuleInstance () { return (m_hdllInstance) ; }

private:
	void DeleteClassAndDescendant (_DBX_REGISTER_OBJECT_ENTRY **ppEntry) {
		_DBX_REGISTER_OBJECT_ENTRY **ppDbxCustObjMapEntryFirst =&__pDbxCustObjMapEntryFirst + 1 ;
		_DBX_REGISTER_OBJECT_ENTRY **ppDbxCustObjMapEntryLast =&__pDbxCustObjMapEntryLast ;
		for ( _DBX_REGISTER_OBJECT_ENTRY **ppEntry2 =ppDbxCustObjMapEntryFirst ; ppEntry2 < ppDbxCustObjMapEntryLast ; ppEntry2++ ) {
			if ( *ppEntry2 != NULL && *ppEntry2 != *ppEntry && (*ppEntry2)->bRegistered == true ) {
				if ( (*ppEntry2)->desc ()->myParent () == (*ppEntry)->desc () )
					DeleteClassAndDescendant (ppEntry2) ;
			}
		}
		deleteCrxRxClass ((*ppEntry)->desc ()) ;
		(*ppEntry)->bRegistered =false ;
	}
};

//-----------------------------------------------------------------------------
CRxDbxApp *crxrxGetApp () ;

#define IMPLEMENT_CRX_ENTRYPOINT_STD(classname) \
	HINSTANCE _hdllInstance =NULL ; \
class classname entryPointObject ; \
	CRxDbxApp *crxrxGetApp () { return (&entryPointObject) ; } \
	extern "C" CxRx::AppRetCode __declspec(dllexport) crxrxEntryPoint (CxRx::AppMsgCode msg, void *pkt) { \
	return (entryPointObject.crxrxEntryPoint (msg, pkt)) ; \
}

//-----------------------------------------------------------------------------
#define IMPLEMENT_CRX_ENTRYPOINT_CLR(classname) IMPLEMENT_CRX_ENTRYPOINT_STD(classname)
#define IMPLEMENT_CRX_ENTRYPOINT(classname) IMPLEMENT_CRX_ENTRYPOINT_STD(classname)

#endif