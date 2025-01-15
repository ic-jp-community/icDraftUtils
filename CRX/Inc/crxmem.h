#ifndef _CRXMEM_H
#define _CRXMEM_H
//
//
//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//
//
//  DESCRIPTION:
//
//  This header file contains general-purpose memory allocation
//  functions.  They are deprecated in favor of newBuffer, freeBuffer,
//  etc. declared in acutmem.h.

#include <stddef.h>
#include "crxChar.h"
#include "CrxCx.h"

#pragma pack (push, 8)

#ifdef __cplusplus
extern "C" {
#endif

void  CRXDB_API *crx_malloc  (size_t size);
void  CRXDB_API crx_free    (void *p);
size_t CRXDB_API crx__msize  (void *p);
void  CRXDB_API *crx_realloc (void *p, size_t size);
void  CRXDB_API *crx_calloc  (size_t num, size_t size);
CxCHAR CRXDB_API *crx__strdup (const CxCHAR *p);

#ifdef __cplusplus
} // "C"
#endif

#pragma pack (pop)
#endif // _CRXMEM_H
