//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
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