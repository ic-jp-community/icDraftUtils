//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//
#pragma once
#ifndef __CRXDBDIMELEVATION_H_
#define __CRXDBDIMELEVATION_H_

#include "ICxGi.h"
#include "ICxDbEntity.h"
//#include "dbents.h"
//#include "crxdbents.h"
#include "dbmain.h"
#include "crxDefine.h"
#include "crxCx.h"

#define PI 3.14159265358979323846

CRX_DEFINE_CLSID(22B7B3CC-882F-4c3d-B506-B624AC881099,CRxDbDimElevation)
class CRXDB_API CRxDbDimElevation: public CRxDbEntity
{
public:
	CRX_DECLARE_DYNCREATE(CRxDbDimElevation);
	//ACRX_DECLARE_MEMBERS(CRxDbDimElevation);
	CRxDbDimElevation(ICxCrxObject *i_pCrxObject = NULL);
	~CRxDbDimElevation();

	
	//
	//�Զ���ʵ��������صĺ���
	//virtual CAXA::Boolean  worldDraw(CRxGiWorldDraw* pWd);
	virtual CDraft::ErrorStatus saveData(CRxDbDatabase* i_pCRxDbDatabase,IStream *i_pStm) ;
	virtual CDraft::ErrorStatus loadData(CRxDbDatabase* i_pCRxDbDatabase,IStream *i_pStm) ;
	virtual CDraft::ErrorStatus updateData();
	virtual CDraft::ErrorStatus updateRelation(CRxDbDatabase* i_pDataBase, ULONG_PTR i_pMapID);

	
	virtual CDraft::ErrorStatus   getGripPoints(CRxGePoint3dArray&  gripPoints,
												CRxDbIntArray &     osnapModes,
												CRxDbIntArray &  geomIds) const;

	virtual  CDraft::ErrorStatus moveGripPointsAt(const CRxDbIntArray & indices,
												  const CRxGeVector3d& offset);
	CDraft::ErrorStatus copyFrom( const  CRxObject* pSrc);
 

	virtual CDraft::ErrorStatus  transformBy(const CRxGeMatrix3d& xform);
	//�Զ���ʵ���Ա����
	typedef enum {UPLEFT,UPRIGHT,DOWNRIGHT,DOWNLEFT} DIRECTION;
	typedef enum {NEB2011R2,NEB2018} CRXOBJVERSION;
	
	void SetDirection(short i_iDir);
	short GetDirection();

	void SetManner(short i_iManner); 
	short GetManner();

	void SetTxtHeight(double i_dTxtHeight);
	double GetTxtHeight();

	void SetTxtColor(const CRxCmColor& i_cmClr);//�ı���ɫ
	CRxCmColor& GetTxtColor();

	void SetSymbolHeight(double i_dSymbolHeight);
	double GetSymbolHeight();

	void SetSymbolColor(const CRxCmColor& i_cmClr);//������ɫ
	CRxCmColor& GetSymbolColor();

	void SetValue(const CxCHAR* i_strValue);
	CxCHAR * GetValue();

	/*void SetValue(double i_dblValue);
	double GetValue();*/

	void SetPrec(short i_iPrec);
	short GetPrec();

	void SetBasePt(AcGePoint3d i_acBasePt);
	AcGePoint3d GetBasePt();

	void SetOriPt(AcGePoint3d i_acOriPt);
	AcGePoint3d GetOriPt();

	void SetTxtStyle(CRxDbObjectId i_txtStyleId);
	CRxDbObjectId GetTxtStyle();

	void SetOverride(bool i_bOverride);
	
	bool IsOverride();


	void CalculatePt();//������λ��
	void CalculateAngPt();//���������ε��λ��
	void CalculateEndPt();//������ĩ���λ��
	void CalculateTxtPt();//�����ı����λ��
	void CalculateValue();//�����ı�ֵ
	void AddLnDisp(const AcGePoint3d& i_acStaPt,const AcGePoint3d& i_acEndPt,
					ICxAttribData* i_pAtt,ICxGrpDispData* i_ppDispData);//����i_acStaPt,i_acEndPtΪ�����յ��ֱ�ߵ���ʾ������ӽ�ȥ

	void WritePoint(IStream *i_pStm,const AcGePoint3d& i_acgePt);
	void ReadPoint(IStream *i_pStm,AcGePoint3d& i_acgePt);
	void MoveTranslation(const CRxGeVector3d& vec);
	void RoteTranslation(const CRxGeVector3d& vec);
	CDraft::ErrorStatus  ClearDispData();

	void SetPaperScale(double i_dPaperScale); //����ͼֽ����
	double GetPaperScale(); //���ͼֽ����


	void SetScale(double i_dScale); //���ñ���
	double GetScale(); //��ñ���

	void AddSolidDisp(const AcGePoint3d& i_acBasePt,const AcGePoint3d& i_acSndPt,const AcGePoint3d& i_acThdPt,ICxAttribData* i_pAtt,ICxGrpDispData* i_ppDispDat);

private:

	//Datas
	short m_iDirection;//����4����

	short m_iManner;//���

	double m_dTxtHeight;//�ı��߶�

	CRxCmColor m_TxtClr;//�ı���ɫ

	double m_dSymbolHeight;//���Ÿ߶�

	CRxCmColor m_SymbolClr;//������ɫ

	CString m_strValue;//�����ֵ
	//double  m_dValue;//�����ֵ
	short m_iPrec;
	
	double m_dScale;
	double m_dPaperScale; //ͼֽ����
	bool m_bPaperScaleInitialized; //ͼֽ�����Ƿ񱻳�ʼ�����ļ��汾����ǰ��ʱ����

	AcGePoint3d m_acOriPt;//ԭ��
	AcGePoint3d m_acBasePt;//����
	AcGePoint3d m_acMidFirPt;//�м��һ��
	AcGePoint3d m_acMidSecPt;//�м�ڶ���
	AcGePoint3d m_acEndPt;//�յ�

	AcGePoint3d m_acMidPt;//�ڶ�����ʽ�µ��м��
	AcGePoint3d m_acTxtPt;

	ULONG m_ulVersion;//�Զ���ʵ��汾


	CRxDbObjectId m_txtStyleObjId;
	bool m_bOverride;



};

CRXDB_API void Real2String(double i_dVal, unsigned long i_ulPrec,char* o_pstrTextBuffer, size_t i_iTextBufferSize);
CString Real2String(double i_dVal, unsigned long i_ulPrec);

#endif
