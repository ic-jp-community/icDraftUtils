//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#pragma once

#include "dbxEntryPoint.h"

//-----------------------------------------------------------------------------
//模拟crxEntryPoint.h
//-----------------------------------------------------------------------------

typedef void (*CRxFunctionPtr) ();


//-----------------------------------------------------------------------------
struct _CRXCOMMAND_ENTRY {
	const CxCHAR *pszCmdGroupName ;
	const CxCHAR *pszCmdGlobalName ;
	const CxCHAR *pszCmdLocalName ;
	CAXA::Int32 commandFlags ;
	CRxFunctionPtr pCmdFct ;
	CRxEdUIContext *pUIContext ;
	UINT localNameID ;
} ;

#pragma section("CRXCOMMAND$__a", read, shared)
#pragma section("CRXCOMMAND$__z", read, shared)
#pragma section("CRXCOMMAND$__m", read, shared)

extern "C" {
	__declspec(selectany) __declspec(allocate("CRXCOMMAND$__a")) _CRXCOMMAND_ENTRY* __pCrxCmdMapEntryFirst =NULL ;
	__declspec(selectany) __declspec(allocate("CRXCOMMAND$__z")) _CRXCOMMAND_ENTRY* __pCrxCmdMapEntryLast =NULL ;
}

#ifdef _WIN64
#define CRXED_CRXCOMMAND_ENTRY_PRAGMA(group,globCmd) __pragma(comment(linker, "/include:__pCrxCmdMap_" #group #globCmd)) ;
#else
#define CRXED_CRXCOMMAND_ENTRY_PRAGMA(group,globCmd) __pragma(comment(linker, "/include:___pCrxCmdMap_" #group #globCmd)) ;
#endif

#define CRXED_CRXCOMMAND_ENTRY_AUTO(classname, group, globCmd, locCmd, cmdFlags, UIContext) \
	__declspec(selectany) _CRXCOMMAND_ENTRY __CrxCmdMap_##group##globCmd = { _RXST(#group), _RXST(#globCmd), _RXST(#locCmd), cmdFlags, classname::##group ##globCmd, UIContext, -1 } ; \
	extern "C" __declspec(allocate("CRXCOMMAND$__m")) __declspec(selectany) _CRXCOMMAND_ENTRY* const __pCrxCmdMap_##group##globCmd = &__CrxCmdMap_##group##globCmd ; \
	CRXED_CRXCOMMAND_ENTRY_PRAGMA(group, globCmd)

#define CRXED_CRXXCOMMAND_ENTRYBYID_AUTO(classname, group, globCmd, locCmdId, cmdFlags, UIContext) \
	__declspec(selectany) _CRXCOMMAND_ENTRY __CrxCmdMap_##group##globCmd = { _RXST(#group), _RXST(#globCmd), NULL, cmdFlags, classname::##group ##globCmd, UIContext, locCmdId } ; \
	extern "C" __declspec(allocate("CRXCOMMAND$__m")) __declspec(selectany) _CRXCOMMAND_ENTRY* const __pCrxCmdMap_##group##globCmd = &__CrxCmdMap_##group##globCmd ; \
	CRXED_CRXCOMMAND_ENTRY_PRAGMA(group, globCmd)

//-----------------------------------------------------------------------------
struct _ADSSYMBOL_ENTRY {
	const CxCHAR *pszName ;
	int (*fptr) () ;
	bool bRegFunc ;
	UINT nameID ;
} ;

#pragma section("ADSSYMBOL$__a", read, shared)
#pragma section("ADSSYMBOL$__z", read, shared)
#pragma section("ADSSYMBOL$__m", read, shared)

extern "C" {
	__declspec(selectany) __declspec(allocate("ADSSYMBOL$__a")) _ADSSYMBOL_ENTRY* __pCdsSymbolMapEntryFirst =NULL ;
	__declspec(selectany) __declspec(allocate("ADSSYMBOL$__z")) _ADSSYMBOL_ENTRY* __pCdsSymbolMapEntryLast =NULL ;
}

#ifdef _WIN64
#define ACED_ADSSYMBOL_ENTRY_PRAGMA(name) __pragma(comment(linker, "/include:__pAdsSymbolMap_" #name)) ;
#else
#define ACED_ADSSYMBOL_ENTRY_PRAGMA(name) __pragma(comment(linker, "/include:___pAdsSymbolMap_" #name)) ;
#endif

#define ACED_ADSSYMBOL_ENTRY_AUTO(classname, name, regFunc) \
	__declspec(selectany) _ADSSYMBOL_ENTRY __AdsSymbolMap_##name = { _RXST(#name), classname::ads_ ##name, regFunc, -1 } ; \
	extern "C" __declspec(allocate("ADSSYMBOL$__m")) __declspec(selectany) _ADSSYMBOL_ENTRY* const __pAdsSymbolMap_##name = &__AdsSymbolMap_##name ; \
	ACED_ADSSYMBOL_ENTRY_PRAGMA(name)
#define ACED_ADSCOMMAND_ENTRY_AUTO(classname, name, regFunc) \
	__declspec(selectany) _ADSSYMBOL_ENTRY __AdsSymbolMap_##name = { _RXST("c:") _RXST(#name), classname::ads_ ##name, regFunc, -1 } ; \
	extern "C" __declspec(allocate("ADSSYMBOL$__m")) __declspec(selectany) _ADSSYMBOL_ENTRY* const __pAdsSymbolMap_##name = &__AdsSymbolMap_##name ; \
	ACED_ADSSYMBOL_ENTRY_PRAGMA(name)

#define ACED_ADSSYMBOL_ENTRYBYID_AUTO(classname, name, nameId, regFunc) \
	__declspec(selectany) _ADSSYMBOL_ENTRY __AdsSymbolMap_##name = { NULL, classname::ads_ ##name, regFunc, nameId } ; \
	extern "C" __declspec(allocate("ADSSYMBOL$__m")) __declspec(selectany) _ADSSYMBOL_ENTRY* const __pAdsSymbolMap_##name = &__AdsSymbolMap_##name ; \
	ACED_ADSSYMBOL_ENTRY_PRAGMA(name)
#define ACED_ADSCOMMAND_ENTRYBYID_AUTO(classname, name, nameId, regFunc) \
	ACED_ADSSYMBOL_ENTRYBYID_AUTO(classname, name, nameId, regFunc)

class CRxCrxApp : public CRxDbxApp {

public:
	CRxCrxApp () : CRxDbxApp () {}

	virtual  CxRx::AppRetCode On_kInitAppMsg (void *pkt) {
		 CxRx::AppRetCode retCode =CRxDbxApp::On_kInitAppMsg (pkt) ;

		//----- Register CRX comamnds
		_CRXCOMMAND_ENTRY **ppCrxCmdMapEntryFirst =&__pCrxCmdMapEntryFirst + 1 ;
		_CRXCOMMAND_ENTRY **ppCrxCmdMapEntryLast =&__pCrxCmdMapEntryLast ;
		CxCHAR buffer [133] ;
		for ( _CRXCOMMAND_ENTRY **ppEntry =ppCrxCmdMapEntryFirst ; ppEntry < ppCrxCmdMapEntryLast ; ppEntry++ ) {
			if ( *ppEntry != NULL ) {
				if ( (*ppEntry)->pszCmdLocalName == NULL )
					::LoadString (m_hdllInstance, (*ppEntry)->localNameID, buffer, 132) ;
				crxedRegCmds->addCommand (
					(*ppEntry)->pszCmdGroupName,
					(*ppEntry)->pszCmdGlobalName,
					(*ppEntry)->pszCmdLocalName == NULL ? buffer : (*ppEntry)->pszCmdLocalName,
					(*ppEntry)->commandFlags,
					(*ppEntry)->pCmdFct,
					(*ppEntry)->pUIContext,
					-1,
					((*ppEntry)->commandFlags & ACRX_CMD_SESSION) ? NULL : m_hdllInstance,
					NULL
					) ;
			}
		}
		return (retCode) ;
	}

	virtual  CxRx::AppRetCode On_kUnloadAppMsg (void *pkt) {
		 CxRx::AppRetCode retCode =CRxDbxApp::On_kUnloadAppMsg (pkt) ;

		_CRXCOMMAND_ENTRY **ppCrxCmdMapEntryFirst =&__pCrxCmdMapEntryFirst + 1 ;
		_CRXCOMMAND_ENTRY **ppCrxCmdMapEntryLast =&__pCrxCmdMapEntryLast ;
		for ( _CRXCOMMAND_ENTRY **ppEntry =ppCrxCmdMapEntryFirst ; ppEntry < ppCrxCmdMapEntryLast ; ppEntry++ ) {
			if ( *ppEntry != NULL ) {
				crxedRegCmds->removeCmd (
					(*ppEntry)->pszCmdGroupName,
					(*ppEntry)->pszCmdGlobalName
					) ;
			}
		}
		return (retCode) ;
	}

	virtual  CxRx::AppRetCode On_kLoadDwgMsg (void *pkt) {
		 CxRx::AppRetCode retCode =CRxDbxApp::On_kLoadDwgMsg (pkt) ;
		//----- Register ADS Symbols
		_ADSSYMBOL_ENTRY **ppCdsSymbolMapEntryFirst =&__pCdsSymbolMapEntryFirst + 1 ;
		_ADSSYMBOL_ENTRY **ppCdsSymbolMapEntryLast =&__pCdsSymbolMapEntryLast ;
		CxCHAR buffer [133] ;
		int param =0 ;
		for ( _ADSSYMBOL_ENTRY **ppEntry =ppCdsSymbolMapEntryFirst ; ppEntry < ppCdsSymbolMapEntryLast ; ppEntry++ ) {
			if ( *ppEntry != NULL ) {
				if ( (*ppEntry)->pszName == NULL )
					::LoadString (m_hdllInstance, (*ppEntry)->nameID, buffer, 132) ;
// 				crxedDefun (
// 					(*ppEntry)->pszName == NULL ? buffer : (*ppEntry)->pszName,
// 					param
// 					) ;
// 				if ( (*ppEntry)->bRegFunc == true )
// 					crxedRegFunc ((*ppEntry)->fptr, param) ;
				param++ ;
			}
		}
		return (retCode) ;
	}

	virtual  CxRx::AppRetCode On_kUnloadDwgMsg (void *pkt) {
		 CxRx::AppRetCode retCode =CRxDbxApp::On_kUnloadDwgMsg (pkt) ;
		//----- Unregister ADS Symbols
		_ADSSYMBOL_ENTRY **ppCdsSymbolMapEntryFirst =&__pCdsSymbolMapEntryFirst + 1 ;
		_ADSSYMBOL_ENTRY **ppCdsSymbolMapEntryLast =&__pCdsSymbolMapEntryLast ;
		CxCHAR buffer [133] ;
		int param =0 ;
		for ( _ADSSYMBOL_ENTRY **ppEntry =ppCdsSymbolMapEntryFirst ; ppEntry < ppCdsSymbolMapEntryLast ; ppEntry++ ) {
			if ( *ppEntry != NULL ) {
				if ( (*ppEntry)->pszName == NULL )
					::LoadString (m_hdllInstance, (*ppEntry)->nameID, buffer, 132) ;
// 				crxedUndef (
// 					(*ppEntry)->pszName == NULL ? buffer : (*ppEntry)->pszName,
// 					param++
// 					) ;
			}
		}
		return (retCode) ;
	}

	virtual  CxRx::AppRetCode On_kInvkSubrMsg (void *pkt) {
		 CxRx::AppRetCode retCode =CRxDbxApp::On_kInvkSubrMsg (pkt) ;
		//----- Dispatch ADS symbol calls
		//int param = crxedGetFunCode () ;
		int param = 0 ;
		_ADSSYMBOL_ENTRY **ppCdsSymbolMapEntryFirst =&__pCdsSymbolMapEntryFirst + 1 ;
		_ADSSYMBOL_ENTRY **ppCdsSymbolMapEntryLast =&__pCdsSymbolMapEntryLast ;
		int paramIter =0 ;
		for ( _ADSSYMBOL_ENTRY **ppEntry =ppCdsSymbolMapEntryFirst ; ppEntry < ppCdsSymbolMapEntryLast ; ppEntry++ ) {
			if ( *ppEntry != NULL ) {
				if ( paramIter++ == param ) {
					(*((*ppEntry)->fptr)) () ;
					break ;
				}
			}
		}
		return (retCode) ;
	}
};
