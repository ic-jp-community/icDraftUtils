//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//
//
//  DESCRIPTION: Exported pre-R13 Entity classes
//
//  CrxRxObject
//    CrxDbObject
//      *CrxDbEntity
//        CrxDbText
//          AcDbAttribute
//          AcDbAttributeDefinition
//        AcDbBlockBegin
//        AcDbBlockEnd
//        AcDbSequenceEnd
//        CrxDbBlockReference
//          AcDbMInsertBlock
//        AcDbVertex
//          AcDb2dVertex
//          AcDb3dPolylineVertex
//          AcDbPolygonMeshVertex
//          AcDbPolyFaceMeshVertex
//          AcDbFaceRecord
//        CrxDbCurve
//          AcDb2dPolyline
//          AcDb3dPolyline
//          AcDbArc
//          CrxDbCircle
//          CrxDbLine
//        CrxDbPoint
//        AcDbFace
//        AcDbPolyFaceMesh
//        AcDbPolygonMesh
//        AcDbTrace
//        AcDbSolid
//        AcDbShape
//        AcDbViewport
//

#ifndef __CRXDBENTS_H_
#define __CRXDBENTS_H_

#include "CrxDbObject.h"


/*------------------------------------------------------------------------------
// CrxDbEntity : ����ʾͼԪ����
**----------------------------------------------------------------------------*/
class CRXDB_API CRxDbEntity : public CRxDbObject
{
	CRX_DECLARE_DYNAMIC(CRxDbEntity)

public:
	virtual void Draw(ICxGiDevice *i_pGiDevice);
};

/*------------------------------------------------------------------------------
// CrxDbLine : ֱ��
**----------------------------------------------------------------------------*/
class __declspec(uuid("17ECF72D-C046-4E9A-8416-FD8220FD33B5")) CRxDbLine;

class CRXDB_API CRxDbLine : public CRxDbEntity
{
	CRX_DECLARE_DYNCREATE(CRxDbLine)

public:
	CRxDbLine(ICxCrxObject *i_pCrxObject = NULL);

	// CrxDbEntity
	void CRxDbLine::Draw(ICxGiDevice *i_pGiDevice);

	// CrxDbLine
	void Set(const double& dStartX, const double& dStartY, const double& dEndX, const double&dEndY);
};

#endif