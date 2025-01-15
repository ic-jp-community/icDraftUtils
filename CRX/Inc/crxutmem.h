#ifndef _CRXUTMEM_H
#define _CRXCUTMEM_H
//
//
//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//

#include "crxcdstrc.h"   // CDraft::ErrorStatus
#include "crxChar.h"    // CxCHAR
#include "CrxEdApiCx.h"

#pragma pack (push, 8)

CRXEDAPI_API
CDraft::ErrorStatus crxutNewBuffer(void *&pOutput, size_t size);
CDraft::ErrorStatus crxutNewString(CxCHAR *&pOutput, int nNumChars);
CDraft::ErrorStatus crxutNewString(const CxCHAR* pInput, CxCHAR*& pOutput);
CDraft::ErrorStatus crxutUpdString(const CxCHAR* pInput, CxCHAR*& pOutput);
CRXEDAPI_API
void crxutDelBuffer(void *& pBuffer);

inline CDraft::ErrorStatus crxutNewBuffer(char *&pOutput, size_t size)
{
    return ::crxutNewBuffer((void * &)pOutput, size);
}

inline void crxutDelBuffer(char *& pString)
{
    ::crxutDelBuffer((void * &)pString);
}

inline void crxutDelString(char *& pString)
{
    ::crxutDelBuffer((void * &)pString);
}

inline void crxutDelString(wchar_t *& pString)
{
    ::crxutDelBuffer((void * &)pString);
}

#pragma pack (pop)
#endif // _CRXUTMEM_H
