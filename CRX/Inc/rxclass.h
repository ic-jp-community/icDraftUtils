//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//

#pragma once

#include "CrxCx.h"
#include "crxstrc.h"
#include "rxobject.h"
#include "crxChar.h"
#include <map>
using namespace std;

class  CRxObject;
struct  CRxClass;
struct ICxCrxObject;

/*----------------------------------------------------------------------------*
* 描  述： 扩充协议
* 历  史： 2016/4/5  fln create
-----------------------------------------------------------------------------*/
class CrxPE
{
public:
	map<CRxClass*, CRxObject*> m_MapPEClass;
};
/*------------------------------------------------------------------------------
// CrxRxClass : 类的类型识别节点
**----------------------------------------------------------------------------*/
struct CRX_API CRxClass
{
public:
// Attributes
	LPCSTR				m_lpszClassName;
	LPCSTR				m_lpszName;
	int					m_nObjectSize;
	unsigned int		m_wSchema;					// schema number of the loaded class
	CRxObject *(PASCAL *m_pfnCreateObject)(ICxCrxObject *i_pCrxObject);		// NULL => abstract class
	CRxClass			*m_pBaseClass;
	CLSID				m_clsid;					// 类的Clsid
	CLSID				m_clsidModule;				// 模块的Clsid

// CRuntimeClass objects linked together in simple list
	static CRxClass	*g_pDesc;					// 链头指针
	CRxClass			*m_pNextClass;				// linked list of registered classes

	static std::map<CRxClass*, CrxPE*> m_MapCls2MapPe;

	CRxClass(LPCSTR lpszClassName, int nObjectSize, unsigned int wSchema,
			  CRxObject *(PASCAL *)(ICxCrxObject *i_pCrxObject), CRxClass* pBaseClass, CLSID _clsid, CLSID _clsidModule, CRxClass* pNextClass);

	bool addX(CRxClass*, CRxObject*);
	bool delX(CRxClass*);
	CRxObject* getX(const CRxClass*);
	bool isDerivedFrom(const CRxClass*) const;
	virtual CRxClass* myParent() const;
	virtual const CxCHAR* name() const;
	virtual void setName( LPCSTR sName );
};

CRX_API void CrxrxBuildClassHierarchy();
CRX_API void deleteCrxRxClass( CRxClass* pClassObj );

/*------------------------------------------------------------------------------
// 类型转换基本结构
**----------------------------------------------------------------------------*/
#define CRX_RUNTIME_CLASS(class_name) (&class_name::class##class_name)

/*------------------------------------------------------------------------------
// CRX_DECLARE_DYNAMIC : .h文件中 声明类型识别节点
**----------------------------------------------------------------------------*/
#define CRX_DECLARE_DYNAMIC(class_name)			\
	public:										\
	static  CRxClass* gpDesc;					\
	static  CRxClass *desc();					\
	virtual CRxClass *isA() const;				\
	virtual CDraft::ErrorStatus getClassID(CLSID *o_pClsid) const;	\
	static void rxInit();						\
	static class_name* class_name::cast(const CRxObject *inPtr)   \
	{													 \
		if (inPtr->isKindOf(desc()) == true)			 \
		{												 \
			return (class_name*)inPtr;					 \
		}												 \
		else											 \
		{												 \
			return NULL;								 \
		}												 \
	}												

/*------------------------------------------------------------------------------
// _CRX_IMPLEMENT_DYNAMIC : .cpp文件中 实现类型识别节点(展开)
**----------------------------------------------------------------------------*/
#define _CRX_IMPLEMENT_DYNAMIC(class_name, base_class_name, wSchema, pfnNew) \
	CRxClass *class_name::gpDesc = NULL;				 \
	static char _lpsz##class_name[] = #class_name;		 \
	CRxClass *class_name::desc()						 \
	{													 \
		return class_name::gpDesc;						 \
	}													 \
	CRxClass *class_name::isA() const					 \
	{													 \
		return class_name::gpDesc;						 \
	}													 \
	CDraft::ErrorStatus class_name::getClassID(CLSID *o_pClsid) const		 \
	{													 \
		ATLASSERT(gpDesc);							     \
		*o_pClsid = class_name::gpDesc->m_clsid;		 \
		return CDraft::eOk;								 \
	}													 \
	void class_name::rxInit()							 \
	{													 \
		if (class_name::gpDesc != NULL)					 \
		{												 \
			return;										 \
		}												 \
		class_name::gpDesc = new CRxClass(_lpsz##class_name,			   \
										   sizeof(class_name),			   \
										   wSchema,						   \
										   pfnNew,						   \
										   base_class_name::gpDesc,		   \
										   __uuidof(class_name), 		   \
										   CLSID_NULL,					   \
										   NULL);\
		gpDesc->m_pNextClass = CRxClass::g_pDesc;\
		CRxClass::g_pDesc = gpDesc;\
	}


/*------------------------------------------------------------------------------
// CRX_IMPLEMENT_DYNAMIC : .cpp文件中 实现类型识别节点(简略)
**----------------------------------------------------------------------------*/
#define CRX_IMPLEMENT_DYNAMIC(class_name, base_class_name) \
		_CRX_IMPLEMENT_DYNAMIC(class_name, base_class_name, 0xffff, NULL)

/*------------------------------------------------------------------------------
// CRX_DECLARE_CREATE : .h文件中 动态创建节点
**----------------------------------------------------------------------------*/
#define CRX_DECLARE_DYNCREATE(class_name) \
		CRX_DECLARE_DYNAMIC(class_name) \
		static CRxObject* PASCAL CreateObject(ICxCrxObject *i_pCrxObject = NULL);

/*------------------------------------------------------------------------------
// CRX_IMPLEMENT_CREATE : .cpp文件中 动态创建节点
**----------------------------------------------------------------------------*/
#define CRX_IMPLEMENT_DYNCREATE(class_name, base_class_name) \
	CRxObject *PASCAL class_name::CreateObject(ICxCrxObject *i_pCrxObject) { return new class_name(i_pCrxObject); } \
	_CRX_IMPLEMENT_DYNAMIC(class_name, base_class_name, 0xFFFFF, class_name::CreateObject) \

/*------------------------------------------------------------------------------
// CRX_DEFINE_CLSID : 绑定C++及COM对象应的CLSID
**----------------------------------------------------------------------------*/
#define CRX_DEFINE_CLSID(class_clsid, class_name) \
class __declspec(uuid(#class_clsid)) class_name;

/*------------------------------------------------------------------------------
// CRX_DEFINE_CLSID : 绑定C++及COM对象应的CLSID
**----------------------------------------------------------------------------*/
#define CRX_DEFINE_NULL_CLSID(class_name) \
class __declspec(uuid("00000000-0000-0000-0000-000000000000")) class_name;

/*------------------------------------------------------------------------------
// CLSID_CRX_MODULE : CRX基本模块
**----------------------------------------------------------------------------*/
class __declspec(uuid("5417A060-50A8-4260-B3F1-65977B49462B")) CLSID_CRX_MODULE;

/*------------------------------------------------------------------------------
// CAXA_NO_VTABLE : 无虚函数表
**----------------------------------------------------------------------------*/
#define CAXA_NO_VTABLE __declspec(novtable)

/*------------------------------------------------------------------------------
// DeriveBase : 用户自定义派生对象级别
**----------------------------------------------------------------------------*/
typedef enum DeriveBase
{
	CRX_DERIVEBASE_OBJECT = 0x0001,//从CRxDbObject派生
	CRX_DERIVEBASE_ENTITY = 0x0002//从CRxDbEntity派生
}CRXDERIVEBASE;

/*------------------------------------------------------------------------------
// CreateDeriveBaseOject : 创建自定义派生对象的内核基本对象
**----------------------------------------------------------------------------*/
CRX_API void CreateDeriveBaseOject( CRXDERIVEBASE eDeriveBase, ICxCrxObject** o_ippCrxObject );

/*------------------------------------------------------------------------------
// CRX_DECLARE_DERIVECONSTRUCT : 声明派生类缺省构造函数
**----------------------------------------------------------------------------*/
#define CRX_DECLARE_DERIVECONSTRUCT(class_name) \
	class_name( ICxCrxObject* i_pCrxObject );

/*------------------------------------------------------------------------------
// CRX_IMPLEMENT_OBJDERIVECONSTRUCT : 实现CRxDbObject派生对象缺省构造函数
**----------------------------------------------------------------------------*/
#define CRX_IMPLEMENT_OBJDERIVECONSTRUCT(class_name) \
	class_name::class_name(ICxCrxObject* i_pCrxObject)\
{\
	CreateDeriveBaseOject( CRX_DERIVEBASE_OBJECT, &m_pCrxObject );\
	ATLASSERT( m_pCrxObject );\
	m_pCrxObject->SetCrxPtr((ULONG_PTR)this);\
}

/*------------------------------------------------------------------------------
// CRX_IMPLEMENT_ENTDERIVECONSTRUCT : 实现CRxDbEntity派生对象缺省构造函数
**----------------------------------------------------------------------------*/
#define CRX_IMPLEMENT_ENTDERIVECONSTRUCT(class_name) \
	class_name::class_name(ICxCrxObject* i_pCrxObject)\
{\
	CreateDeriveBaseOject( CRX_DERIVEBASE_ENTITY, &m_pCrxObject );\
	ATLASSERT( m_pCrxObject );\
	m_pCrxObject->SetCrxPtr((ULONG_PTR)this);\
}
