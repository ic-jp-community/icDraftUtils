#ifndef DB_MIGRATION_H
#define DB_MIGRATION_H
//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//


#include "cdsmigr.h"
// #include "crxutmigr.h"

#define crxdbSetCurrentVPort crxedSetCurrentVPort
#define crxdbGetCurrentSelectionSet crxedGetCurrentSelectionSet

// The following macro will require that you #include "dbapserv.h" and
// add CRxDb.lib to the LINK line in your makefile.
//
#define crxdbCurDwg crxdbHostApplicationServices()->workingDatabase

#define  crxdbGetRGB crxedGetRGB

#define crxdbGetCurViewportObjectId crxedGetCurViewportObjectId

#define getCurDwgXrefGraph crxedGetCurDwgXrefGraph

#endif // DB_MIGRATION_H
