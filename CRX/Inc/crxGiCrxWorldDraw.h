//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#include "crxgi.h"

#ifndef __CRxGiCrxWorldDraw_H_
#define __CRxGiCrxWorldDraw_H_

CRX_DEFINE_NULL_CLSID(CRxGiCrxWorldDraw)
class CRXGI_CLASS CRxGiCrxWorldDraw : public CRxGiWorldDraw
{
public:
	CRX_DECLARE_DYNAMIC(CRxGiCrxWorldDraw)

public:
	CRxGiCrxWorldDraw();
	~CRxGiCrxWorldDraw();

public:
	virtual CRxGiRegenType           regenType() const;
	virtual CAXA::Boolean          regenAbort() const;
	virtual CRxGiSubEntityTraits&    subEntityTraits() const;
	virtual CRxGiGeometry *			rawGeometry() const;
	virtual CAXA::Boolean          isDragging() const;

	virtual double					deviation(const CRxGiDeviationType,const CRxGePoint3d&) const;
	virtual CAXA::UInt32           numberOfIsolines() const;

	virtual CRxGiContext *			context();
	virtual CRxGiWorldGeometry&      geometry() const;

public:
	void SetImpG(ULONG_PTR i_pImp);
	void SetImpD(ULONG_PTR i_pImp);

	bool BeginObject();
	bool EndObject();
	bool GetObject(ULONG_PTR* o_ppImpObject);

private:
	ULONG_PTR m_pImpG;
	ULONG_PTR m_pImpD;

	CRxGiSubEntityTraits *m_pAcGiSubEntityTraits;
	CRxGiWorldGeometry   *m_pAcGiWorldGeometry;
	CRxGiContext			*m_pAcGiContext;

	ULONG_PTR m_pImpO;
};

#endif