//
//£®C£©Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ∞Ê»®À˘”–£®C£©±±æ© ˝¬ÅEÛ∑Ωø∆ººπ…∑›”–œﬁπ´Àæ
//  ◊˚Ú’”√ªß π”√±æ»˙ÿ˛±ÿ–ÅEÒ ÿ°∂CAXA◊˚Ú’”√ªß–˙€… π”√–≠“È°∑
//
//

#ifndef   _RXOBJECT_H
#define   _RXOBJECT_H

#include "CrxCx.h"
#include "rxclass.h"
#include "cdraft.h"
#include "rxdefs.h"

struct CRxClass;
struct ICxCrxObject;

class CRX_API CRxObject
{
public:
	CRxObject(ICxCrxObject *pCrxObject = NULL);
	virtual ~CRxObject();

public:
	void SetCrxObject(ICxCrxObject *i_pCrxObject);
	void GetCrxObject(ICxCrxObject **o_ppCrxObject);
	void GetOriginObject(ICxCrxObject **o_ppOriginObject);
	void SetOriginObject(ICxCrxObject *i_pOriginObject);

public:
	// RTTI
	static  CRxClass	*gpDesc;
	static  CRxClass	*desc();				
	virtual CRxClass	*isA() const;			
	static	CRxObject	*cast(const CRxObject* inPtr); 
	inline  bool isKindOf(const CRxClass *pClass) const;
	CRxObject *queryX(CRxClass* protocolClass) const;
	
	static void  rxInit();

	// Object Id
	virtual CDraft::ErrorStatus getClassID(CLSID *o_pClsid) const;
	virtual void getModuleClassID(CLSID *o_pClsid);

	virtual CRxObject*       clone() const;
	virtual CDraft::ErrorStatus copyFrom(const CRxObject* other);

	virtual CAXA::Boolean    isEqualTo(const CRxObject * other) const;
	virtual CxRx::Ordering    comparedTo(const CRxObject * other) const;

public:
	ICxCrxObject *m_pCrxObject;
	ICxCrxObject *m_pOriginObject;
};

#endif

