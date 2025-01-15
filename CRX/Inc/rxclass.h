//
//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
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
* ��  ���� ����Э��
* ��  ʷ�� 2016/4/5  fln create
-----------------------------------------------------------------------------*/
class CrxPE
{
public:
	map<CRxClass*, CRxObject*> m_MapPEClass;
};
/*------------------------------------------------------------------------------
// CrxRxClass : �������ʶ��ڵ�
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
	CLSID				m_clsid;					// ���Clsid
	CLSID				m_clsidModule;				// ģ���Clsid

// CRuntimeClass objects linked together in simple list
	static CRxClass	*g_pDesc;					// ��ͷָ��
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
// ����ת�������ṹ
**----------------------------------------------------------------------------*/
#define CRX_RUNTIME_CLASS(class_name) (&class_name::class##class_name)

/*------------------------------------------------------------------------------
// CRX_DECLARE_DYNAMIC : .h�ļ��� ��������ʶ��ڵ�
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
// _CRX_IMPLEMENT_DYNAMIC : .cpp�ļ��� ʵ������ʶ��ڵ�(չ��)
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
// CRX_IMPLEMENT_DYNAMIC : .cpp�ļ��� ʵ������ʶ��ڵ�(����)
**----------------------------------------------------------------------------*/
#define CRX_IMPLEMENT_DYNAMIC(class_name, base_class_name) \
		_CRX_IMPLEMENT_DYNAMIC(class_name, base_class_name, 0xffff, NULL)

/*------------------------------------------------------------------------------
// CRX_DECLARE_CREATE : .h�ļ��� ��̬�����ڵ�
**----------------------------------------------------------------------------*/
#define CRX_DECLARE_DYNCREATE(class_name) \
		CRX_DECLARE_DYNAMIC(class_name) \
		static CRxObject* PASCAL CreateObject(ICxCrxObject *i_pCrxObject = NULL);

/*------------------------------------------------------------------------------
// CRX_IMPLEMENT_CREATE : .cpp�ļ��� ��̬�����ڵ�
**----------------------------------------------------------------------------*/
#define CRX_IMPLEMENT_DYNCREATE(class_name, base_class_name) \
	CRxObject *PASCAL class_name::CreateObject(ICxCrxObject *i_pCrxObject) { return new class_name(i_pCrxObject); } \
	_CRX_IMPLEMENT_DYNAMIC(class_name, base_class_name, 0xFFFFF, class_name::CreateObject) \

/*------------------------------------------------------------------------------
// CRX_DEFINE_CLSID : ��C++��COM����Ӧ��CLSID
**----------------------------------------------------------------------------*/
#define CRX_DEFINE_CLSID(class_clsid, class_name) \
class __declspec(uuid(#class_clsid)) class_name;

/*------------------------------------------------------------------------------
// CRX_DEFINE_CLSID : ��C++��COM����Ӧ��CLSID
**----------------------------------------------------------------------------*/
#define CRX_DEFINE_NULL_CLSID(class_name) \
class __declspec(uuid("00000000-0000-0000-0000-000000000000")) class_name;

/*------------------------------------------------------------------------------
// CLSID_CRX_MODULE : CRX����ģ��
**----------------------------------------------------------------------------*/
class __declspec(uuid("5417A060-50A8-4260-B3F1-65977B49462B")) CLSID_CRX_MODULE;

/*------------------------------------------------------------------------------
// CAXA_NO_VTABLE : ���麯����
**----------------------------------------------------------------------------*/
#define CAXA_NO_VTABLE __declspec(novtable)

/*------------------------------------------------------------------------------
// DeriveBase : �û��Զ����������󼶱�
**----------------------------------------------------------------------------*/
typedef enum DeriveBase
{
	CRX_DERIVEBASE_OBJECT = 0x0001,//��CRxDbObject����
	CRX_DERIVEBASE_ENTITY = 0x0002//��CRxDbEntity����
}CRXDERIVEBASE;

/*------------------------------------------------------------------------------
// CreateDeriveBaseOject : �����Զ�������������ں˻�������
**----------------------------------------------------------------------------*/
CRX_API void CreateDeriveBaseOject( CRXDERIVEBASE eDeriveBase, ICxCrxObject** o_ippCrxObject );

/*------------------------------------------------------------------------------
// CRX_DECLARE_DERIVECONSTRUCT : ����������ȱʡ���캯��
**----------------------------------------------------------------------------*/
#define CRX_DECLARE_DERIVECONSTRUCT(class_name) \
	class_name( ICxCrxObject* i_pCrxObject );

/*------------------------------------------------------------------------------
// CRX_IMPLEMENT_OBJDERIVECONSTRUCT : ʵ��CRxDbObject��������ȱʡ���캯��
**----------------------------------------------------------------------------*/
#define CRX_IMPLEMENT_OBJDERIVECONSTRUCT(class_name) \
	class_name::class_name(ICxCrxObject* i_pCrxObject)\
{\
	CreateDeriveBaseOject( CRX_DERIVEBASE_OBJECT, &m_pCrxObject );\
	ATLASSERT( m_pCrxObject );\
	m_pCrxObject->SetCrxPtr((ULONG_PTR)this);\
}

/*------------------------------------------------------------------------------
// CRX_IMPLEMENT_ENTDERIVECONSTRUCT : ʵ��CRxDbEntity��������ȱʡ���캯��
**----------------------------------------------------------------------------*/
#define CRX_IMPLEMENT_ENTDERIVECONSTRUCT(class_name) \
	class_name::class_name(ICxCrxObject* i_pCrxObject)\
{\
	CreateDeriveBaseOject( CRX_DERIVEBASE_ENTITY, &m_pCrxObject );\
	ATLASSERT( m_pCrxObject );\
	m_pCrxObject->SetCrxPtr((ULONG_PTR)this);\
}
