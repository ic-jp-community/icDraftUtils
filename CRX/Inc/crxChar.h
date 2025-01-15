//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

//

//
//              crxChar.h
//
// Define the CxCHAR type and CRX_T() macro for use in CRX/DBX headers.
//
#pragma once

// The API is always Unicode now, so we always define AD_UNICODE
#define AD_UNICODE 1

// Crx APIs expect clients to be building with "native" wchar_t type.
#if defined(__cplusplus) && !defined(_NATIVE_WCHAR_T_DEFINED)
#error Please use native wchar_t type (/Zc:wchar_t)
#endif

typedef wchar_t CxCHAR;

// Same mechanism as tchar.h's _T() macro.  We redirect this to a
// second macro, so that other macros can be passed as the x arg,
// as in CRX_T(__FILE__)
//
#define _CRX_T(x)      L ## x
#define CRX_T(x)      _CRX_T(x)

