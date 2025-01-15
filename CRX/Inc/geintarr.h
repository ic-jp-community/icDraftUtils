#ifndef CRX_GEINTARR_H
#define CRX_GEINTARR_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

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
