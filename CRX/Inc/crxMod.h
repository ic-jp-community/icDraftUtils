//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
//
#ifndef _crxmod_h
#define _crxmod_h 1

// Ensure that C++ modules use the right linking conventions when calling
// functions contained in C.

#ifdef __cplusplus
extern "C" {
#endif

#include "cdsdef.h"
#include "crxmem.h"
#include "crxChar.h"
#include "CrxEdApiCx.h"

#pragma pack (push, 8) /* !_acedads_h */

CRXEDAPI_API
	BOOL ModLongByStr(CxCHAR* i_pszCaption, LONG* i_plValue, LONG i_lMin, LONG i_lMax);
CRXEDAPI_API
BOOL	ModInit();			//	��ʼ��
CRXEDAPI_API
BOOL	ModRefresh();		//	ˢ��
CRXEDAPI_API
BOOL	ModUpdateMenuItemByL( LONG* i_piValue, BOOL i_bSetReadOnly = FALSE );	//	����ָ���˵��ĵ�ǰ���� 
CRXEDAPI_API
BOOL	ModUpdateMenuItemByD( DOUBLE* i_pdValue, BOOL i_bSetReadOnly = FALSE, void* i_pdSourceMenuID = NULL );
CRXEDAPI_API
BOOL	ModUpdateMenuItemByStr( CAtlString* i_pszValue, BOOL i_bSetReadOnly = FALSE);
CRXEDAPI_API
BOOL	ModUpdateMenuChoiceByL( LONG* i_plChoice );
CRXEDAPI_API
BOOL	ModLongByN( UINT i_idCaption, LONG* i_plValue, LONG i_lMin, LONG i_lMax );
CRXEDAPI_API
BOOL	ModDoubleByStr( CxCHAR* i_pszCaption, DOUBLE* i_pdValue, DOUBLE i_dMin, DOUBLE i_dMax );
CRXEDAPI_API
BOOL	ModDoubleByN( UINT i_idCaption, DOUBLE* i_pdValue, DOUBLE i_dMin, DOUBLE i_dMax );
CRXEDAPI_API
BOOL	ModStringByStr( CxCHAR* i_pszCaption, CAtlString* i_psValue, LONG i_lMaxLen );
CRXEDAPI_API
BOOL	ModStringByN( UINT i_idCaption, CAtlString* i_psValue, LONG i_lMaxLen );
CRXEDAPI_API
BOOL	ModChoiceByStr( CxCHAR* i_pszContent, LONG* i_plChoice );
CRXEDAPI_API
BOOL	ModChoiceByN (UINT i_idCaption, LONG* i_plChoice );
CRXEDAPI_API
BOOL	ModSizeByStr( CxCHAR* i_pszCaption, SIZE_T* i_piValue, SIZE_T i_iMin, SIZE_T i_iMax );
CRXEDAPI_API
BOOL	ModSizeByN( UINT i_idCaption, SIZE_T* i_piValue, SIZE_T i_iMin, SIZE_T i_iMax );

CRXEDAPI_API
BOOL	ModExclusiveChoiceByStr( CxCHAR* i_pszContent, LONG* i_plChoice );
CRXEDAPI_API
BOOL	ModExclusiveChoiceByN( UINT i_idCaption, LONG* i_plChoice );
CRXEDAPI_API
BOOL	ModLongConditionByStr( CxCHAR* i_pszCaption, LONG* i_piValue, LONG i_lMin, LONG i_lMax, LONG* i_plCondition, LONG i_lConditionValue );
CRXEDAPI_API
BOOL	ModLongConditionByN( UINT i_idCaption, LONG* i_piValue, LONG i_lMin, LONG i_lMax, LONG* i_plCondition, LONG i_lConditionValue );
CRXEDAPI_API
BOOL	ModDoubleConditionByStr( CxCHAR* i_pszCaption, DOUBLE* i_pdValue, DOUBLE i_dMin, DOUBLE i_dMax, LONG* i_plCondition, LONG i_lConditionValue );
CRXEDAPI_API
BOOL	ModDoubleConditionByN( UINT i_idCaption, DOUBLE* i_pdValue, DOUBLE i_dMin, DOUBLE i_dMax, LONG* i_plCondition, LONG i_lConditionValue );
CRXEDAPI_API
BOOL	ModStringConditionByStr( CxCHAR* i_pszCaption, CAtlString* i_psValue, LONG i_lMaxLen, LONG* i_plCondition, LONG i_lConditionValue );
CRXEDAPI_API
BOOL	ModStringConditionByN( UINT i_idCaption, CAtlString* i_psValue, LONG i_lMaxLen, LONG* i_plCondition, LONG i_lConditionValue );
CRXEDAPI_API
BOOL	ModChoiceConditionByStr( CxCHAR* i_pszContent, LONG* i_plChoice, LONG* i_plCondition, LONG i_lConditionValue );
CRXEDAPI_API
BOOL	ModChoiceConditionByN( UINT i_idCaption, LONG* i_plChoice, LONG* i_plCondition, LONG i_lConditionValue );
CRXEDAPI_API
BOOL	ModSizeConditionByStr( CxCHAR* i_pszCaption, SIZE_T* i_piValue, SIZE_T i_iMin, SIZE_T i_iMax, LONG* i_piCondition, LONG i_iConditionValue );
CRXEDAPI_API
BOOL	ModSizeConditionByN( UINT i_idCaption, SIZE_T* i_piValue, SIZE_T i_iMin, SIZE_T i_iMax, LONG* i_piCondition, LONG i_iConditionValue );
CRXEDAPI_API
BOOL	ModExclusiveChoiceConditionByStr( CxCHAR* i_pszContent, LONG* i_plChoice, LONG* i_plCondition, LONG i_lConditionValue );
CRXEDAPI_API
BOOL	ModExclusiveChoiceConditionByN( UINT i_idCaption, LONG* i_plChoice, LONG* i_plCondition, LONG i_lConditionValue );

#pragma pack (pop)

#ifdef __cplusplus
    }
#endif /* __cplusplus */



#endif