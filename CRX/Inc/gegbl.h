#ifndef AC_GEGBL_H
#define AC_GEGBL_H

//
//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//	End-users must also comply with the terms and conditions 
//	in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//	��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//	�����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//
// 

/*#include <stdlib.h>
#include "gedll.h"
#include "cdraft.h"
#include "getol.h"

#include "gegblge.h"
#pragma pack (push, 8)

class CRxGeVector3d;*/

//#include "stdafx.h"
#include "getol.h"
#include "gedll.h"

struct GE_DLLEXPIMPORT CrxGeContext
{
	// System wide default tolerance.
	//
	static CRxGeTol      gTol;

	/*static void (*gErrorFunc)();

#ifndef GELIB2D
	// Function to calculate a vector which is orthogonal to the given vector.
	//
	static void (*gOrthoVector)(const CRxGeVector3d&,CRxGeVector3d&);
#endif

#ifndef unix
	static void* (*gAllocMem)(size_t);
#ifdef MEM_DEBUG
	// Unicode: leave as char for now
	static void* (*gAllocMemLeak)(size_t, const char *, int);
#endif
	static void  (*gFreeMem)(void*);
#endif
#ifdef GE_LOCATED_NEW
	static void* (*gAllocMemNear) (size_t, CRxGe::metaTypeIndex, const void* );
	static void* (*gAllocMemNearVector) (size_t, CRxGe::metaTypeIndex, unsigned int, const void* );
	static void (*gSetExternalStore) (const void* );
#endif
#ifndef NDEBUG
	static void (*gAssertFunc)(const CxCHAR *condition, const CxCHAR *filename,
		int lineNumber, const CxCHAR *status);
#endif*/
};


//#pragma pack (pop)
#endif // AC_GEGBL_H

