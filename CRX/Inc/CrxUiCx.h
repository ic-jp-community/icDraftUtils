//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
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