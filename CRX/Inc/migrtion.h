#ifndef DB_MIGRATION_H
#define DB_MIGRATION_H
//
//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
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
