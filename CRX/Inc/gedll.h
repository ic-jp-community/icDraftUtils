#ifndef CRX_GEDLL_H
#define CRX_GEDLL_H
//

//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾

//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷

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
