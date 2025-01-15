#ifndef CRX_GEINTARR_H
#define CRX_GEINTARR_H
//

//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾

//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷

//

#ifndef unix
#include <stdlib.h>
#endif
#include "cdraft.h"
#include "assert.h"

#include "crxarray.h"
typedef CRxArray<int> CRxGeIntArray;
typedef CRxArray<CAXA::IntPtr> CRxGeIntPtrArray;

#if GE_LOCATED_NEW
GE_DLLEXPIMPORT
CRxGe::metaTypeIndex CRxGeGetMetaTypeIndex(CRxGeIntArray* pT);
#endif
#endif
