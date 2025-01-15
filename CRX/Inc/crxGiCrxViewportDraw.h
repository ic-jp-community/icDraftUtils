//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#include "crxgi.h"

#ifndef __CRxGiCrxViewportDraw_H_
#define __CRxGiCrxViewportDraw_H_

CRX_DEFINE_NULL_CLSID(CRxGiCrxViewportDraw)
class CRXGI_CLASS CRxGiCrxViewportDraw : public CRxGiViewportDraw
{
public:
	CRX_DECLARE_DYNAMIC(CRxGiCrxViewportDraw)

public:
	CRxGiCrxViewportDraw();
	~CRxGiCrxViewportDraw();

public:
	virtual CRxGiViewport&        viewport() const = 0;
	virtual CRxGiViewportGeometry& geometry() const = 0;
	virtual CAXA::UInt32        sequenceNumber() const = 0;

	virtual CAXA::Boolean       isValidId(const CAXA::ULongPtr acgiId) const =0;
	virtual CRxDbObjectId         viewportObjectId() const = 0;

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
	CRxGiViewportGeometry   *m_pAcGiViewportGeometry;
	CRxGiContext			*m_pAcGiContext;
	CRxGiViewport			*m_pAcGiViewport;
};

#endif