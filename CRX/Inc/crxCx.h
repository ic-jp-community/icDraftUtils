//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//

#pragma once

#ifdef CRX_EXPORTS
#define CRX_API		__declspec(dllexport)
#define CRX_CLASS	__declspec(dllexport)
#else
#define CRX_API		__declspec(dllimport)
#define CRX_CLASS	__declspec(dllimport)
#endif

#ifdef CRXDB_EXPORTS
#define CRXDB_API	__declspec(dllexport)
#define CRXDB_CLASS	__declspec(dllexport)
#else
#define CRXDB_API	__declspec(dllimport)
#define CRXDB_CLASS	__declspec(dllimport)
#endif

#ifndef CRXSPT_STATIC
#ifdef CRXSPT_EXPORTS
#define CRXSPT_API		__declspec(dllexport)
#define CRXSPT_CLASS	__declspec(dllexport)
#else
#define CRXSPT_API		__declspec(dllimport)
#define CRXSPT_CLASS	__declspec(dllimport)
#endif
#else // CRX_STATIC
#define CRXSPT_API
#define CRXSPT_CLASS
#endif

#ifdef CRXGI_EXPORTS
#define CRXGI_API		__declspec(dllexport)
#define CRXGI_CLASS		__declspec(dllexport)
#else
#define CRXGI_API		__declspec(dllimport)
#define CRXGI_CLASS		__declspec(dllimport)
#endif

