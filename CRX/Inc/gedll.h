#ifndef CRX_GEDLL_H
#define CRX_GEDLL_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

//

#pragma warning(disable:4251)
#pragma warning(disable:4273)
#pragma warning(disable:4275)
#ifdef  CRXGE_INTERNAL
#define GE_DLLEXPIMPORT __declspec(dllexport)
#else
#define GE_DLLEXPIMPORT __declspec(dllimport)
#endif

#ifdef  CRXGE_INTERNAL
#define GX_DLLEXPIMPORT __declspec(dllexport)
#else
#define GX_DLLEXPIMPORT __declspec(dllimport)
#endif

#ifdef CRXGE_INTERNAL
#ifndef GELIB_REGRESS
//#include "crxmemdebug.h"
#endif
#endif

#endif // AC_GEDLL_H
