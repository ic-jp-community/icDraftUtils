//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
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
	//自定义实体必须重载的函数
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
	//自定义实体成员函数
	typedef enum {UPLEFT,UPRIGHT,DOWNRIGHT,DOWNLEFT} DIRECTION;
	typedef enum {NEB2011R2,NEB2018} CRXOBJVERSION;
	
	void SetDirection(short i_iDir);
	short GetDirection();

	void SetManner(short i_iManner); 
	short GetManner();

	void SetTxtHeight(double i_dTxtHeight);
	double GetTxtHeight();

	void SetTxtColor(const CRxCmColor& i_cmClr);//文本颜色
	CRxCmColor& GetTxtColor();

	void SetSymbolHeight(double i_dSymbolHeight);
	double GetSymbolHeight();

	void SetSymbolColor(const CRxCmColor& i_cmClr);//符号颜色
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


	void CalculatePt();//计算点的位置
	void CalculateAngPt();//计算三角形点的位置
	void CalculateEndPt();//计算标高末点的位置
	void CalculateTxtPt();//计算文本点的位置
	void CalculateValue();//计算文本值
	void AddLnDisp(const AcGePoint3d& i_acStaPt,const AcGePoint3d& i_acEndPt,
					ICxAttribData* i_pAtt,ICxGrpDispData* i_ppDispData);//将以i_acStaPt,i_acEndPt为起点和终点的直线的显示数据添加进去

	void WritePoint(IStream *i_pStm,const AcGePoint3d& i_acgePt);
	void ReadPoint(IStream *i_pStm,AcGePoint3d& i_acgePt);
	void MoveTranslation(const CRxGeVector3d& vec);
	void RoteTranslation(const CRxGeVector3d& vec);
	CDraft::ErrorStatus  ClearDispData();

	void SetPaperScale(double i_dPaperScale); //设置图纸比例
	double GetPaperScale(); //获得图纸比例


	void SetScale(double i_dScale); //设置比例
	double GetScale(); //获得比例

	void AddSolidDisp(const AcGePoint3d& i_acBasePt,const AcGePoint3d& i_acSndPt,const AcGePoint3d& i_acThdPt,ICxAttribData* i_pAtt,ICxGrpDispData* i_ppDispDat);

private:

	//Datas
	short m_iDirection;//方向（4个）

	short m_iManner;//风格

	double m_dTxtHeight;//文本高度

	CRxCmColor m_TxtClr;//文本颜色

	double m_dSymbolHeight;//符号高度

	CRxCmColor m_SymbolClr;//符号颜色

	CString m_strValue;//标高数值
	//double  m_dValue;//标高数值
	short m_iPrec;
	
	double m_dScale;
	double m_dPaperScale; //图纸比例
	bool m_bPaperScaleInitialized; //图纸比例是否被初始化，文件版本升级前临时处理

	AcGePoint3d m_acOriPt;//原点
	AcGePoint3d m_acBasePt;//基点
	AcGePoint3d m_acMidFirPt;//中间第一点
	AcGePoint3d m_acMidSecPt;//中间第二点
	AcGePoint3d m_acEndPt;//终点

	AcGePoint3d m_acMidPt;//第二种形式下的中间点
	AcGePoint3d m_acTxtPt;

	ULONG m_ulVersion;//自定义实体版本


	CRxDbObjectId m_txtStyleObjId;
	bool m_bOverride;



};

CRXDB_API void Real2String(double i_dVal, unsigned long i_ulPrec,char* o_pstrTextBuffer, size_t i_iTextBufferSize);
CString Real2String(double i_dVal, unsigned long i_ulPrec);

#endif
