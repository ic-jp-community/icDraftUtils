// (C) Copyright 2009 by CAXA, Inc. 
//


//-----------------------------------------------------------------------------
//- HelloRibbonBar.cpp : Initialization functions
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "resource.h"

#include <afxdllx.h>

//-----------------------------------------------------------------------------
//- Define the sole extension module object.

AC_IMPLEMENT_EXTENSION_MODULE(HelloRibbonBarDLL)
//- Please do not remove the 3 following lines. These are here to make .NET MFC Wizards
//- running properly. The object will not compile but is require by .NET to recognize
//- this project as being an MFC project
#ifdef NEVER
AFX_EXTENSION_MODULE HelloRibbonBarExtDLL ={ NULL, NULL } ;
#endif

//-----------------------------------------------------------------------------
//- DLL Entry Point
extern "C"
BOOL WINAPI DllMain (HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved) {
	//- Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved) ;

	if ( dwReason == DLL_PROCESS_ATTACH ) {
        _hdllInstance =hInstance ;
	HelloRibbonBarDLL.AttachInstance (hInstance) ;

// 		InitAcUiDLL () ;
	} else if ( dwReason == DLL_PROCESS_DETACH ) {
		HelloRibbonBarDLL.DetachInstance () ;
	}
	return (TRUE) ;
}
