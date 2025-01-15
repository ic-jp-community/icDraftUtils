//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#ifndef _crxdbcds_h
#define _crxdbcds_h 1

#include "cdsdef.h"

#include "crxmem.h"
#include "crxChar.h"

#pragma pack (push, 8)

// Note: some day we may drop .c support and remove extern "C"
#ifdef __cplusplus
extern "C" {
#endif
//void           acdbFail (const CxCHAR *str);
//
//int            acdbXdRoom (const crx_name ent, long *result);
//int            acdbXdSize (const struct resbuf *rb, long *result);

int CRXDB_API crxdbHandEnt (const CxCHAR *handle, crx_name entres);

/* Function to save a string ensuring no buffer overflow if, */
/* when converted, characters expand to \U+ sequences */
//CxCHAR *        acdbXStrSave (CxCHAR *pSource, CxCHAR **pDest);

/* Function to uppercase a table name */
//int            acdbXStrCase (CxCHAR *str);
#ifdef __cplusplus
}
#endif

/* Define macros to copy them.  NOTE that the result is the SECOND argument,
   consistent with ADS usage.  The standard C ones require <string.h> */
#ifdef __STDC__
//#define crxdbNameSet(from, to)  (memcpy(to, from, sizeof(crx_name)))
//#define crxdbPointSet(from,to)  (memcpy(to, from, sizeof(crx_point)))
//#else
//#define crxdbNameSet(from, to)  (*(to)= *(from), (to)[1]=(from)[1])
//#define crxdbPointSet(from, to) (*(to)= *(from), (to)[1]=(from)[1], (to)[2]=(from)[2])
#endif  /* !__STDC__ */

/* Define null value for ads_names.  These values are NOT guaranteed valid;
   that is, there is no actual guarantee (such as C gives with NULL) that the
   system will never under any circumstances generate the values as valid data.
   The correct values will be created as part of the Lisp reinitialization
   project, if we go through with that one, and will then be inserted here.
   */
//#define crxdbNameClear(name)    name[0] = name[1] = 0
//#define crxdbNameNil(name)      (name[0] == 0 && name[1] == 0)
//#define crxdbNameEqual(name1, name2)  (name1[0]==name2[0] \
//                                       && name1[1]==name2[1])
#pragma pack (pop)

#endif // !crxdbcds.h

