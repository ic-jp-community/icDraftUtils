//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
#pragma once

#ifndef CRXEDAPI_STATIC
#ifdef CRXEDAPI_EXPORTS
#define CRXEDAPI_API	__declspec(dllexport)
#define CRXEDAPI_CLASS	__declspec(dllexport)
#else
#define CRXEDAPI_API	__declspec(dllimport)
#define CRXEDAPI_CLASS	__declspec(dllimport)
#endif
#else // CRXEDAPI_STATIC
#define CRXEDAPI_API
#define CRXEDAPI_CLASS
#endif