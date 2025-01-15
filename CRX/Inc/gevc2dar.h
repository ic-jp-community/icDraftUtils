#ifndef CRX_GEVC2DAR_H
#define CRX_GEVC2DAR_H
//

//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾

//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷

//

#include "cdraft.h"
#include "assert.h"
#include "gevec2d.h"

#include "crxarray.h"
typedef CRxArray<CRxGeVector2d> CRxGeVector2dArray;

#if GE_LOCATED_NEW
GE_DLLEXPIMPORT
CRxGe::metaTypeIndex CRxGeGetMetaTypeIndex(CRxGeVector2dArray* pT);
#endif

#endif
