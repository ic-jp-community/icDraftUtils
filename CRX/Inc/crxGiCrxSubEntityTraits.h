//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#include "crxgi.h"
#include "dbid.h"

#ifndef __CRxGiCrxSubEntityTraits_H_
#define __CRxGiCrxSubEntityTraits_H_

CRX_DEFINE_NULL_CLSID(CRxGiCrxSubEntityTraits)
class CRxGiCrxSubEntityTraits : public CRxGiSubEntityTraits
{
public:
	CRX_DECLARE_DYNAMIC(CRxGiCrxSubEntityTraits)

public:
	CRxGiCrxSubEntityTraits();
	~CRxGiCrxSubEntityTraits();
	
public:
	virtual void			  setColor				(const CAXA::UInt16 color);
	virtual void              setTrueColor          (const CRxCmEntityColor& color);
	virtual void              setLayer              (const CRxDbObjectId layerId);
	virtual void              setLineType           (const CRxDbObjectId linetypeId);
	virtual void              setSelectionMarker    (const CAXA::LongPtr markerId);
	virtual void              setFillType           (const CRxGiFillType);
	virtual void              setLineWeight         (const CRxDb::LineWeight lw);
	virtual void              setLineTypeScale      (double dScale = 1.0);
	virtual void              setThickness          (double dThickness);
	virtual void              setVisualStyle        (const CRxDbObjectId visualStyleId);
	virtual CDraft::ErrorStatus setEdgeStyleOverride  (CRxGiEdgeStyleMask mask, const CRxGiEdgeStyle& edgeStyle);
	virtual void              setPlotStyleName      (CRxDb::PlotStyleNameType type, const CRxDbObjectId & id = CRxDbObjectId::kNull);
	virtual void              setMaterial           (const CRxDbObjectId materialId);
	virtual void              setMapper             (const CRxGiMapper * mapper);
	virtual void              setSectionable        (bool bSectionable);
	virtual CDraft::ErrorStatus setDrawFlags          (CAXA::UInt32 flags);
	virtual CDraft::ErrorStatus setShadowFlags        (ShadowFlags flags);
	virtual void              setSelectionGeom      (bool bSelectionflag);

	// Return current settings.
	CAXA::UInt16           color               (void) const;
	CRxCmEntityColor         trueColor           (void) const;
	CRxDbObjectId            layerId             (void) const;
	CRxDbObjectId            lineTypeId          (void) const;
	CRxGiFillType            fillType            (void) const;
	CRxDb::LineWeight        lineWeight          (void) const;
	double                  lineTypeScale       (void) const;
	double                  thickness           (void) const;
	CRxDbObjectId            visualStyle         (void) const;
	CDraft::ErrorStatus       edgeStyleOverride   (CRxGiEdgeStyleMask& mask, CRxGiEdgeStyle& edgeStyle) const;
	CRxDb::PlotStyleNameType getPlotStyleNameId  (CRxDbObjectId& idResult) const;
	CRxDbObjectId            materialId          (void) const;
	const CRxGiMapper *      mapper              (void) const;
	bool                    sectionable         (void) const;
	CAXA::UInt32           drawFlags           (void) const;
	bool                    selectionGeom       (void) const;

public:
	void					SetImpG(ULONG_PTR i_pImp);
	void					SetImpD(ULONG_PTR i_pImp);

private:
	ULONG_PTR				m_pImpG;
	ULONG_PTR				m_pImpD;
	ULONG_PTR				m_pImpL;
};

#endif