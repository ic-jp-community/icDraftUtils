//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
#pragma once

#ifndef CRX_STATIC
	#ifdef CRX_EXPORTS
		#define CRX_API		__declspec(dllexport)
		#define CRX_CLASS	__declspec(dllexport)
	#else
		#define CRX_API		__declspec(dllimport)
		#define CRX_CLASS	__declspec(dllimport)
	#endif
#else // CRX_STATIC
	#define CRX_API
	#define CRX_CLASS
#endif