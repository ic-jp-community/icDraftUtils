//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
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