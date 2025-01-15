//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
#pragma once

#ifndef CRXUI_STATIC
#ifdef CRXUI_EXPORTS
#define CRXUI_API	__declspec(dllexport)
#define CRXUI_CLASS	__declspec(dllexport)
#else
#define CRXUI_API	__declspec(dllimport)
#define CRXUI_CLASS	__declspec(dllimport)
#endif
#else // CRXEDAPI_STATIC
#define CRXUI_API
#define CRXUI_CLASS
#endif