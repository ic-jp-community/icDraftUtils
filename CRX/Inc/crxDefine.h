#ifndef __CRXDEFINE_H_
#define __CRXDEFINE_H_
#pragma once 

//
//£®C£©Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//	End-users must also comply with the terms and conditions 
//	in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//	∞Ê»®À˘”–£®C£©±±æ© ˝¬ÅEÛ∑Ωø∆ººπ…∑›”–œﬁπ´Àæ
//	◊˚Ú’”√ªß π”√±æ»˙ÿ˛±ÿ–ÅEÒ ÿ°∂CAXA◊˚Ú’”√ªß–˙€… π”√–≠“È°∑
//
// 

/********************************************************************
	created:	2009/07/31
	filename: 	n:\workspace\CrxInc\CRxDefine.h
	file path:	n:\workspace\CrxInc
	file base:	CRxDefine
	file ext:		h
	author:		
	
	purpose:	∑Ω±„CRX¥˙¬ÅE®“∆£¨‘⁄CRxDefine.h÷–◊™∂®“ÂCRX÷–œ‡πÿ¿‡£¨∫Ø ˝£¨Ω·ππ£¨√∂æŸ
*********************************************************************/

//////////////////////////////////////////////////////////////////////////
/// <summary> 
/// Global & Support
/// </summary>
//////////////////////////////////////////////////////////////////////////
//	API
#define		ads_real					crx_real
#define		ads_point					crx_point
#define		ads_name					crx_name
#define		ads_nameep					crx_namep
#define		ads_matrix					crx_matrix
#define		ads_pointp					crx_pointp
#define		ads_binary					crx_binary
#define		ads_u_val					crx_u_val
#define		ads_name_set			cds_name_set
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
/// <summary> 
/// CrxEntryPoint & CrxApp
/// </summary>
//////////////////////////////////////////////////////////////////////////
//Macro
#define ACRX_DECLARE_MEMBERS(c)						 CRX_DECLARE_DYNAMIC(c)
#define IMPLEMENT_ARX_ENTRYPOINT_COM(classname,x)	 IMPLEMENT_CRX_ENTRYPOINT_COM(classname,x)
#define IMPLEMENT_ARX_ENTRYPOINT_STD(classname)		 IMPLEMENT_CRX_ENTRYPOINT_STD(classname)
#define IMPLEMENT_ARX_ENTRYPOINT_CLR(classname)		 IMPLEMENT_CRX_ENTRYPOINT_CLR(classname)
#define IMPLEMENT_ARX_ENTRYPOINT(classname)			 IMPLEMENT_CRX_ENTRYPOINT(classname) 
#define ACED_ARXCOMMAND_ENTRY_AUTO(classname, group, globCmd, locCmd, cmdFlags, UIContext) \
	CRXED_CRXCOMMAND_ENTRY_AUTO(classname, group, globCmd, locCmd, cmdFlags, UIContext)
#define ACED_ARXCOMMAND_ENTRYBYID_AUTO(classname, group, globCmd, locCmdId, cmdFlags, UIContext) \
	CRXED_CRXXCOMMAND_ENTRYBYID_AUTO(classname, group, globCmd, locCmdId, cmdFlags, UIContext)
#define ACED_ARXCOMMAND_ENTRY_PRAGMA(group,globCmd)  CRXED_CRXCOMMAND_ENTRY_PRAGMA(group,globCmd)
#define ACDB_REGISTER_OBJECT_ENTRY_AUTO(classname)   CRXDB_REGISTER_OBJECT_ENTRY_AUTO(classname)
#define ACDB_REGISTER_OBJECT_ENTRY_PRAGMA(classname) CRXDB_REGISTER_OBJECT_ENTRY_PRAGMA(classname)

//Class
#define AcRxDbxApp					CRxDbxApp
#define AcRxArxApp					CRxCrxApp
#define AcadApp						CDraftApp

//API
#define acrxGetApp					crxrxGetApp
#define acrxEntryPoint				crxrxEntryPoint

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
#define Adesk CAXA	
#define ADESK_NO_VTABLE	CAXA_NO_VTABLE
#define ADESK_STDCALL CAXA_STDCALL
#define ADESK_DEPRECATED	CAXA_DEPRECATED
#define WM_ACAD_KEEPFOCUS	WM_CDRAFT_KEEPFOCUS
#define Acad	CDraft
#define AC_ARRAY_ASSERT	CRX_ARRAY_ASSERT
#define ACARRAY_GROWTH_THRESHOLD	CRXARRAY_GROWTH_THRESHOLD
#define AcArrayMemCopyReallocator	CRxArrayMemCopyReallocator
#define AcArrayObjectCopyReallocator	CRxArrayObjectCopyReallocator
#define AcArray	CRxArray
#define ACHAR	CxCHAR
#define ACDB_SERVICES	CRXDB_SERVICES
#define ACDB_MODEL_SPACE	CRXDB_MODEL_SPACE               
#define ACDB_PAPER_SPACE CRXDB_PAPER_SPACE
#define ACDB_NULL_HANDLE  CRXDB_NULL_HANDLE
#define ACDB_BROKEN_HANDLE CRXDB_BROKEN_HANDLE
#define ACDB_OPEN_BRACE_STR  CRXDB_OPEN_BRACE_STR
#define ACDB_OPEN_BRACE_CHAR  CRXDB_OPEN_BRACE_CHAR
#define ACDB_CLOSE_BRACE_STR   CRXDB_CLOSE_BRACE_STR
#define ACDB_CLOSE_BRACE_CHAR  CRXDB_CLOSE_BRACE_CHAR
#define ACDB_GROUP_DICTIONARY   CRXDB_GROUP_DICTIONARY
#define ACDB_MLINESTYLE_DICTIONARY  CRXDB_MLINESTYLE_DICTIONARY
#define ACDB_LAYOUT_DICTIONARY   CRXDB_LAYOUT_DICTIONARY
#define ACDB_PLOTSETTINGS_DICTIONARY   CRXDB_PLOTSETTINGS_DICTIONARY
#define ACDB_PLOTSTYLENAME_DICTIONARY  CRXDB_PLOTSTYLENAME_DICTIONARY
#define ACDB_MATERIAL_DICTIONARY       CRXDB_MATERIAL_DICTIONARY
#define ACDB_VISUALSTYLE_DICTIONARY    CRXDB_VISUALSTYLE_DICTIONARY
#define ACDB_COLOR_DICTIONARY    CRXDB_COLOR_DICTIONARY
#define ACDB_TABLESTYLE_DICTIONARY     CRXDB_TABLESTYLE_DICTIONARY
#define ACDB_EMBEDDED_OBJECT_STR      CRXDB_EMBEDDED_OBJECT_STR
#define ACDB_LAYERSTATES_DICTIONARY   CRXDB_LAYERSTATES_DICTIONARY
#define ACDB_FIELD_DICTIONARY     CRXDB_FIELD_DICTIONARY
#define ACDB_FIELDLIST  CRXDB_FIELDLIST
#define ACDB_ENHANCED_BLOCK  CRXDB_ENHANCED_BLOCK
#define ACDB_ENHANCED_BLOCK_EVALKEY    CRXDB_ENHANCED_BLOCK_EVALKEY
#define ACDB_ENHANCED_BLOCK_REF   CRXDB_ENHANCED_BLOCK_REF
#define ACDB_SECTION_MANAGER    CRXDB_SECTION_MANAGER
#define ACDB_DATALINK    CRXDB_DATALINK
#define ACDB_ANNOTATIONSCALES_COLLECTION CRXDB_ANNOTATIONSCALES_COLLECTION
#define ACDB_MLEADERSTYLE_DICTIONARY   CRXDB_MLEADERSTYLE_DICTIONARY
#define AcDb	CRxDb
#define acdbNameSet	crxdbNameSet
#define acdbPointSet	crxdbPointSet
#define AcFileSelectFlags	CRxFileSelectFlags
#define acrx_abort crx_abort	
#define acedGetAppName	crxedGetAppName
#define acedUpdate	crxedUpdate
#define adsw_acadDocWnd		adsw_cdraftDocWnd
#define acedRegFunc	crxedRegFunc
#define acedUsrBrk	crxedUsrBrk
#define acedDefun	crxedDefun
#define acedSetFunHelp	crxedSetFunHelp
#define acedUndef	crxedUndef
#define acedGetFunCode	crxedGetFunCode
#define acedGetArgs	crxedGetArgs
#define acedRetList	crxedRetList
#define acedRetVal	crxedRetVal
#define acedRetPoint	crxedRetPoint
#define acedRetStr	crxedRetStr
#define acedRetName	crxedRetName
#define acedRetInt	crxedRetInt
#define acedRetReal	crxedRetReal
#define acedRetT	crxedRetT
#define acedRetNil	crxedRetNil
#define acedRetVoid	crxedRetVoid
#define acedSSGetFirst	crxedSSGetFirst
#define acedSSSetFirst	crxedSSSetFirst
#define acedSSGetKwordCallbackPtr	crxedSSGetKwordCallbackPtr
#define acedSSSetKwordCallbackPtr	crxedSSSetKwordCallbackPtr
#define acedSSGetOtherCallbackPtr		crxedSSGetOtherCallbackPtr
#define acedSSSetOtherCallbackPtr		crxedSSSetOtherCallbackPtr
#define acedSetVar	crxedSetVar
#define	acedGetSym	crxedGetSym
#define acedPutSym	crxedPutSym
#define acedHelp	crxedHelp
#define acedHelpForExternal	crxedHelpForExternal
#define acedFNSplit	crxedFNSplit
#define acedArxLoaded	crxedCrxLoaded
#define acedArxUnload	crxedCrxUnload
#define acedInvoke	crxedInvoke
#define acedFindFile	crxedFindFile
#define acedSetEnv	crxedSetEnv
#define acedGetEnv	crxedGetEnv
#define acedGetCfg	crxedGetCfg
#define acedSetCfg	crxedSetCfg
#define acedMenuCmd	crxedMenuCmd
#define acedPrompt	crxedPrompt
#define acedTextScr	crxedTextScr
#define acedGraphScr crxedGraphScr 
#define acedTextPage crxedTextPage 
#define acedRedraw crxedRedraw
#define acedOsnap	crxedOsnap 
#define acedGrRead crxedGrRead 
#define acedGrText crxedGrText 
#define acedGrDraw crxedGrDraw 
#define acedGrVecs crxedGrVecs 
#define acedXformSS	crxedXformSS
#define acedDragGen	crxedDragGen
#define acedSetView		crxedSetView
#define acedGetFileD crxedGetFileD
#define acedGetFileNavDialog	crxedGetFileNavDialog
#define acedTextBox crxedTextBox 
#define acedTablet crxedTablet 
#define acedGetCName crxedGetCName 
#define acedEatCommandThroat	crxedEatCommandThroat
#define acdbEntDel	crxdbEntDel
#define acdbEntLast crxdbEntLast 
#define acdbEntNext	crxdbEntNext
#define acdbEntUpd	crxdbEntUpd 
#define acdbEntMod	crxdbEntMod
#define acdbEntMake	crxdbEntMake
#define acdbEntMakeX	crxdbEntMakeX
#define acdbTblN	crxdbTblN
#define acdbTblS	crxdbTblS
#define acdbNamedO	crxdbNamedO
#define acdbDict	crxdbDict
#define acdbDict	crxdbDict
#define acdbDictRen	crxdbDictRen
#define acdbDictRem	crxdbDictRem
#define acdbDictAdd	crxdbDictAdd
#define acdbTblObjName	crxdbTblObjName
#define acdbAngToS crxdbAngToS 
#define acdbRawAngToS	crxdbRawAngToS
#define acdbRToS	crxdbRToS
#define acdbAngToF	crxdbAngToF
#define acdbRawAngToF	crxdbRawAngToF
#define acdbDisToF	crxdbDisToF
#define acdbInters	crxdbInters
#define acdbSNValid	crxdbSNValid
#define ads_queueexpr	cds_queueexpr
#define acedGetFullInput	crxedGetFullInput
#define acedGetFullKword	crxedGetFullKword
#define acedGetFullString	crxedGetFullString
#define acedSSNameXEx crxedSSNameXEx 
#define AcDbCustomOsnapMode	CRxDbCustomOsnapMode
#define AcRxFunctionPtr		CRxFunctionPtr
#define AcRx	CxRx
#define AcGiRegenType	CRxGiRegenType
#define AcGiFillType	CRxGiFillType
#define AcGiVisibility	CRxGiVisibility
#define AcGiArcType	CRxGiArcType
#define AcGiOrientationType	CRxGiOrientationType
#define  AcGiDeviationType	CRxGiDeviationType
#define AcGiImageOrg	CRxGiImageOrg
#define AcGiImageOrient	CRxGiImageOrient
#define AcGiScaleFilterType	CRxGiScaleFilterType
#define AcGiRotationFilterType	CRxGiRotationFilterType
#define AcGiScaleType	CRxGiScaleType
#define AcGiSymbolType	CRxGiSymbolType
#define AcGiEdgeStyleMask	CRxGiEdgeStyleMask
#define AcGiSentScanLines	CRxGiSentScanLines
#define AcGiRequestScanLines	CRxGiRequestScanLines
#define AcGiClipBoundary	CRxGiClipBoundary
#define AcGiColorIntensity	CRxGiColorIntensity
#define acgiIsValidClipBoundary	crxgiIsValidClipBoundary
#define acgiGetRegenBlockRefStack	crxgiGetRegenBlockRefStack
#define AcGiTextHook	CRxGiTextHook
#define AcDbImpText		CRxDbImpText
#define AcGiViewport	CRxGiViewport
#define AcGiScaleTransformBehavior	CRxGiScaleTransformBehavior
#define AcGiLineType	CRxGiLineType
#define AcGiLineJoinStyle	CRxGiLineJoinStyle
#define AcGiLineEndStyle	CRxGiLineEndStyle
#define AcGiLineFillStyle	CRxGiLineFillStyle
#define AcGiLineAttributes	CRxGiLineAttributes
#define AcGiLineAttrUtils	CRxGiLineAttrUtils
#define acgiLineWeightToIndex	crxgiLineWeightToIndex
#define acgiIndexToLineWeight	crxgiIndexToLineWeight
#define AcGiAttributeFlags	CRxGiAttributeFlags
#define AcGiStyleAttributes	CRxGiStyleAttributes
#define AcHeapOperators	CRxHeapOperators
#define AcDbArrayIntArray	CRxDbArrayIntArray
#define AcString	CRxString
#define AcStringImp	CRxStringImp
#define acTransactionManagerPtr	crxTransactionManagerPtr
#define acad__assert	cdraft__assert
#define acutCvUnit		crxutCvUnit
#define acutWcMatch	crxutWcMatch
#define acutSPrintf	crxutSPrintf
#define acutAngle	crxutAngle
#define acutDistance	crxutDistance
#define acutPolar	crxutPolar
#define acutIsAlpha	crxutIsAlpha
#define acutIsUpper	crxutIsUpper
#define acutIsLower	crxutIsLower
#define acutIsDigit	crxutIsDigit
#define acutIsXDigit	crxutIsXDigit
#define acutIsSpace	crxutIsSpace
#define acutIsPunct	crxutIsPunct
#define acutIsAlNum crxutIsAlNum
#define acutIsPrint crxutIsPrint
#define acutIsGraph  crxutIsGraph
#define acutIsCntrl crxutIsCntrl
#define acutToUpper  crxutToUpper
#define acutToLower  crxutToLower
#define acutDelString	crxutDelString
#define AcDbAuditInfo	CRxDbAuditInfo
#define AcDbUndoController	CRxDbUndoController
#define AcDbAbstractClipBoundaryDefinition	CRxDbAbstractClipBoundaryDefinition
#define AcDbPlotSettingsValidator	CRxDbPlotSettingsValidator
#define AcDbLayoutManager	CRxDbLayoutManager
#define AcPwdCache	CRxPwdCache
#define AcSDIValues	CRxSDIValues
#define acdbHostAppMinorVersion	crxdbHostAppMinorVersion
#define AcDbHostApplicationProgressMeter	CRxDbHostApplicationProgressMeter
#define acadInternalGetvar	crxadInternalGetvar
#define acadInternalSetvar crxadInternalSetvar
#define acdbSendInitialDwgFileOpenComplete	crxdbSendInitialDwgFileOpenComplete
#define acdbTriggerAcadOctTreeReclassification	crxdbTriggerAcadOctTreeReclassification
#define acdbSetBreak3dQueueForRegen	crxdbSetBreak3dQueueForRegen
#define AcDbPasswordedFile	CRxDbPasswordedFile
#define AcDbSystemInternals	CRxDbSystemInternals
#define AcCm CRxCm	
#define AcDbImpDictionary	CRxDbImpDictionary
#define AcDmUtil	CRxDmUtil
#define AcDbR13ObjectId	CRxDbR13ObjectId
#define AcDbIntArray	CRxDbIntArray
#define AcDbIntPtrArray	CRxDbIntPtrArray
#define AcDbGripData	CRxDbGripData
#define acdbGetAdsName	crxdbGetAdsName
#define acdbGetObjectId	crxdbGetObjectId
#define acdbOpenAcDbObject	crxdbOpenCRxDbObject
#define acdbOpenAcDbEntity	crxdbOpenCRxDbEntity
#define acdbOpenObject 	crxdbOpenObject
#define AcDbMTextFragment	CRxDbMTextFragment
#define AcDbMText	CRxDbMText
#define AcGeDoubleArray	CRxGeDoubleArray
#define AcGe	CRxGe
#define	AcGeDoubleArray	CRxGeDoubleArray
#define AcGeXConfig	CRxGeXConfig
#define AcGeIntersectError	CRxGeIntersectError
#define AcGeIntArray	CRxGeIntArray
#define AcGeIntPtrArray	CRxGeIntPtrArray
#define AcColorSettings	CRxColorSettings
#define acdbFail crxdbFail
#define acdbXdRoom crxdbXdRoom 
#define acdbXdSize crxdbXdSize
#define acdbXStrSave crxdbXStrSave
#define acdbXStrCase crxdbXStrCase
#define acdbNameClear crxdbNameClear
#define acdbNameNil crxdbNameNil
#define acdbNameEqual crxdbNameEqual

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
/// <summary> 
/// MFC Extensions
/// </summary>
//////////////////////////////////////////////////////////////////////////
//Macro
#define AC_DECLARE_EXTENSION_MODULE(exm)	CRX_DECLARE_EXTENSION_MODULE(exm)
#define AC_IMPLEMENT_EXTENSION_MODULE(exm)  CRX_IMPLEMENT_EXTENSION_MODULE(exm)

//Class
#define CAcExtensionModule			CCrxExtensionModule
#define CAcModuleResourceOverride   CCrxModuleResourceOverride

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
/// <summary> 
/// CRxEd ---- AcEd
/// </summary>
//////////////////////////////////////////////////////////////////////////
//API
#define 	acedInitGet				crxedInitGet
#define 	acedGetAngle			crxedGetAngle 
#define 	acedGetCorner			crxedGetCorner
#define 	acedGetDist				crxedGetDist 
#define 	acedGetOrient			crxedGetOrient 
#define 	acedGetPoint			crxedGetPoint 
#define 	acedGetInt				crxedGetInt 
#define 	acedGetKword			crxedGetKword 
#define 	acedGetReal				crxedGetReal 
#define 	acedGetInput			crxedGetInput 
#define 	acedVports				crxedVports
#define		acedTrans				crxedTrans
#define 	acedEntSel				crxedEntSel 
#define 	acedNEntSel				crxedNEntSel 
#define 	acedNEntSelP			crxedNEntSelP 
#define 	acedSSGet				crxedSSGet 
#define 	acedSSFree				crxedSSFree
#define 	acedSSLength			crxedSSLength 
#define 	acedSSAdd				crxedSSAdd 
#define 	acedSSDel				crxedSSDel 
#define 	acedSSMemb				crxedSSMemb 
#define 	acedSSName				crxedSSName 
#define 	acedSSNameX				crxedSSNameX 
#define 	acedGetString			crxedGetString 
#define 	acedGetStringB			crxedGetStringB
#define		acedCommand				crxedCommand
#define		acedCmd					crxedCmd
#define		acutPrintf				crxutPrintf
#define		acutNewRb				crxutNewRb
#define		acutRelRb				crxutRelRb
#define		acutBuildList			crxutBuildList
#define		acedUpgradeDocOpen		crxedUpgradeDocOpen
#define		acedDowngradeDocOpen	crxedDowngradeDocOpen
#define		adsw_acadMainWnd		crxMainWnd
#define		adsw_acadMainThreadId	crxMainThreadId
#define		acutNewBuffer	crxutNewBuffer
#define		acutUpdString	crxutUpdString
#define		acutDelBuffer	crxutDelBuffer
#define		acedAlert		crxedAlert
#define		acedGetVar	crxedGetVar
#define		acedGetCurrentColors	crxedGetCurrentColors
#define		acedDwgPoint crxedDwgPoint
#define		acedCoordFromWorldToPixel crxedCoordFromWorldToPixel
#define		acedCoordFromPixelToWorld crxedCoordFromPixelToWorld
#define		AcadInet	CDraftInet
#define		acdbRegApp	crxdbRegApp
#define		actrTransactionManager	crxtrTransactionManager
#define		acedUpdateDisplay	crxedUpdateDisplay
#define 	acedGetChain			crxedGetChain 
//Class 
#define		AcEdJig					CRxEdJig
#define		AcEdCommand				CRxEdCommand
#define		AcEdCommandStruc		CRxEdCommandStruc
#define		AcEdCommandIterator		CRxEdCommandIterator
#define		AcEdCommandStack		CRxEdCommandStack
#define		AcEditorReactor			CRxEditorReactor
#define		AcEditorReactor2		CRxEditorReactor2
#define		AcEditorReactor3		CRxEditorReactor3
#define		AcEditor				CRxEditor
#define		AcEdSelectionSetService	CRxEdSelectionSetService
#define		AcEdSSGetFilter			CRxEdSSGetFilter
#define		AcEdSSGetFilter2		CRxEdSSGetFilter2
#define		AcEdSSGetFilter3		CrxEdSSGetFilter3
#define		AcEdSSGetFilter4		CRxEdSSGetFilter4
#define		AcEdSubSelectFilterService	CRxEdSubSelectFilterService
#define		AcEdSSGetSubSelectFilter	CRxEdSSGetSubSelectFilter
#define		AcEdInputContextReactor	CRxEdInputContextReactor
#define		AcEdSSGet				CRxEdSSGet
#define		AcEdSSGetFlags			CRxEdSSGetFlags
#define		AcEdSSGetModes			CRxEdSSGetModes
#define		AcLispAppInfo			CRxLispAppInfo
#define		AcEdSubSelectFilter		CRxEdSubSelectFilter
#define		AcEdInputPointFilter	CRxEdInputPointFilter
#define		AcEdInputPointMonitor	CRxEdInputPointMonitor
#define		AcEdInputContextReactor	CRxEdInputContextReactor


//Marco
//ED
#define acedRegCmds					crxedRegCmds
#define acedEditor					crxedEditor
#define ACED_EDITOR_OBJ				CRXED_EDITOR_OBJ
#define adsw_hwndAcad				crx_hwndCrx
#define AcXrefSubCommand		CRxXrefSubCommand
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
/// <summary> 
/// CrxAp ---- AcAp
/// </summary>
//////////////////////////////////////////////////////////////////////////
//API
#define		acDocManagerPtr				crxDocManagerPtr
#define		acProfileManagerPtr			crxProfileManagerPtr

//Marco
#define		acDocManager				crxDocManager
#define		acProfileManager			crxProfileManager
#define		AC_DOCUMENT_MANAGER_OBJ		CRX_DOCUMENT_MANAGER_OBJ

//Class
#define		AcAp					CRxAp
#define		AcApDocManagerReactor	CRxApDocManagerReactor
#define		AcApDocumentIterator	CRxApDocumentIterator
#define		AcApDocument			CRxApDocument
#define		AcApDocManager			CRxApDocManager
#define		AcApProfileStorage		CRxApProfileStorage
#define		AcApProfileManagerReactor	CRxApProfileManagerReactor
#define		AcApProfileManager			CRxApProfileManager
#define		AcApProfileNameArray	CRxApProfileNameArray
#define		AcDbAppSystemVariables	CRxDbAppSystemVariables
#define		AcApLongTransactionReactorCRxApLongTransactionReactor
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
/// <summary> 
/// CRx ---- AcRx
/// </summary>
//////////////////////////////////////////////////////////////////////////
//API
#define		acrxSysRegistry				crxSysRegistry

//Macro
#define		acrxEvent					crxEvent
#define		acrxClassDictionary			crxClassDictionary
#define		acrxServiceDictionary		crxServiceDictionary
#define		ACRX_EVENT_OBJ			    CRX_EVENT_OBJ
#define		_ACRX_T(x)				    _CRX_T(x)
#define		ACRX_T(x)					CRX_T(x)
#define		ACRX_CLASS_DICTIONARY       CRX_CLASS_DICTIONARY
#define		ACRX_DYNAMIC_LINKER			CRX_DYNAMIC_LINKER
#define		ACRX_SERVICE_DICTIONARY     CRX_SERVICE_DICTIONARY
#define		ACRX_KERNEL_SERVICES        CRX_KERNEL_SERVICES
#define		ACRX_PROTOCOL_REACTOR_MANAGER CRX_PROTOCOL_REACTOR_MANAGER

#define		ACRX_CMD_MODAL              CRX_CMD_MODAL
#define		ACRX_CMD_TRANSPARENT        CRX_CMD_TRANSPARENT
#define		ACRX_CMD_USEPICKSET         CRX_CMD_USEPICKSET
#define		ACRX_CMD_REDRAW	            CRX_CMD_REDRAW
#define	    ACRX_CMD_NOPERSPECTIVE		CRX_CMD_NOPERSPECTIVE /* NOT allowed in perspective 
views */
#define		ACRX_CMD_NOMULTIPLE         CRX_CMD_NOMULTIPLE
#define		ACRX_CMD_NOTILEMODE         CRX_CMD_NOTILEMODE // NOT allowed with TILEMODE == 1
#define	    ACRX_CMD_NOPAPERSPACE       CRX_CMD_NOPAPERSPACE // NOT allowed in Paperspace
#define		ACRX_CMD_PLOTONLY           CRX_CMD_PLOTONLY // Allowed in plot-only state
#define		ACRX_CMD_NOOEM              CRX_CMD_NOOEM
#define		ACRX_CMD_UNDEFINED          CRX_CMD_UNDEFINED
#define		ACRX_CMD_INPROGRESS         CRX_CMD_INPROGRESS
#define		ACRX_CMD_DEFUN              CRX_CMD_DEFUN
#define		ACRX_CMD_LISPASCMD          CRX_CMD_LISPASCMD // For Internal use only
#define		ACRX_CMD_NONEWSTACK         CRX_CMD_NONEWSTACK // For internal use only
#define		ACRX_CMD_NOINTERNALLOCK     CRX_CMD_NOINTERNALLOCK
#define		ACRX_CMD_DOCREADLOCK        CRX_CMD_DOCREADLOCK // not set = DOCWRITELOCK
#define		ACRX_CMD_DOCEXCLUSIVELOCK   CRX_CMD_DOCEXCLUSIVELOCK // not set = DOCSHAREDLOCK
#define		ACRX_CMD_SESSION            CRX_CMD_SESSION /* Run cmd handler in the session
fiber */
#define		ACRX_CMD_INTERRUPTIBLE      CRX_CMD_INTERRUPTIBLE // Supports OPM display of command
// properties
#define		ACRX_CMD_NOHISTORY          CRX_CMD_NOHISTORY // Command does not become default
#define		ACRX_CMD_NO_UNDO_MARKER     CRX_CMD_NO_UNDO_MARKER // No Undo or Repeat presence.
#define		ACRX_CMD_NOBEDIT            CRX_CMD_NOBEDIT // blocked during a bedit session
#define		ACRX_CMD_NOACTIONRECORDING  CRX_CMD_NOACTIONRECORDING // Disallow Action Recording
#define		ACRX_CMD_ACTIONMACRO        CRX_CMD_ACTIONMACRO // Action Macro command
#define		ACRX_CMD_RELAXASSOC         CRX_CMD_RELAXASSOC /* Allow relaxed network evaluation
during drag operation */

#define		ACRX_MAX_CMDNAME_LEN		CRX_MAX_CMDNAME_LEN
#define		ACRX_COMMAND_DOCK			CRX_COMMAND_DOCK

//Class
#define		AcRxClass					CRxClass
#define		AcRxObject                  CRxObject

#define		AcXrefSubCommand			CRxXrefSubCommand
#define		AcRxEventReactor			CRxEventReactor
#define		AcRxEvent					CRxEvent
#define		AcRxIterator				CRxIterator
#define		AcRxDictionaryIterator		CRxDictionaryIterator
#define		AcRxDictionary				CRxDictionary

//API
#define     deleteAcRxClass					deleteCrxRxClass
#define		acrxBuildClassHierarchy			CrxrxBuildClassHierarchy

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
/// <summary> 
/// CrxDb ---- CRxDb
/// </summary>
//////////////////////////////////////////////////////////////////////////
//API
#define		acdbSetHostApplicationServices				crxdbSetHostApplicationServices
#define		acdbHostApplicationServices					crxdbHostApplicationServices

//Class
#define		AcDbObject                  CRxDbObject
#define		AcDbEntity				    CRxDbEntity
#define		AcDbSymbolTable			    CRxDbSymbolTable
#define		AcDbBlockTable			    CRxDbBlockTable
#define	    AcDbLayerTable              CRxDbLayerTable
#define		AcDbLinetypeTable           CRxDbLinetypeTable
#define		AcDbTextStyleTable          CRxDbTextStyleTable
#define		AcDbDimStyleTable           CRxDbDimStyleTable
#define	    AcDbRegAppTable             CRxDbRegAppTable
#define		AcDbUCSTable           CRxDbUCSTable
#define		AcDbXObject             CRxDbXObject
#define		AcCmColor                CRxCmColor
#define		AcCmComplexColor    CRxCmComplexColor
#define		AcGeFastTransform    CRxGeFastTransform
#define		AcDbDictionary          CRxDbDictionary
#define		AcCmEntityColor        CRxCmEntityColor
#define		AcCmColorBase         CRxCmColorBase
#define	    AcCmTransparency    CRxCmTransparency
#define	    AcCmDialogColor     CRxCmDialogColor
#define     AcDbCurve              CRxDbCurve
#define     AcDbText                CRxDbText
#define	    AcDbAttribute         CRxDbAttribute
#define		AcDbAttributeDefinition  CRxDbAttributeDefinition
#define	    AcDbSymbolTable CRxDbSymbolTable
#define		AcDbSymbolTableRecord CRxDbSymbolTableRecord
#define		AcDbSymbolTableIterator CRxDbSymbolTableIterator
#define     AcDbDimStyleTableRecord CRxDbDimStyleTableRecord
#define		AcDbLayerTableRecord CRxDbLayerTableRecord
#define		AcDbLayerTableIterator CRxDbLayerTableIterator
#define		AcDbLayerTable CRxDbLayerTable
#define		AcDbBlockTableRecord CRxDbBlockTableRecord
#define		AcDbBlockTableIterator CRxDbBlockTableIterator
#define		AcDbBlockTableRecordIterator CRxDbBlockTableRecordIterator
#define		AcDbTextStyleTableRecord  CRxDbTextStyleTableRecord 
#define		AcDbTextStyleTableIterator CRxDbTextStyleTableIterator
#define	    AcDbTextStyleTable CRxDbTextStyleTable
#define	    AcDbLinetypeTableRecord CRxDbLinetypeTableRecord
#define	    AcDbLinetypeTableIterator CRxDbLinetypeTableIterator
#define     AcDbLinetypeTable CRxDbLinetypeTable
#define		AcDbUCSTableRecord CRxDbUCSTableRecord
#define		AcDbUCSTableIterator CRxDbUCSTableIterator
#define		AcDbUCSTable CRxDbUCSTable
#define		AcDbRegAppTableRecord CRxDbRegAppTableRecord
#define		AcDbRegAppTableIterator CRxDbRegAppTableIterator
#define		AcDbRegAppTable CRxDbRegAppTable
#define		AcDbDimStyleTableRecord CRxDbDimStyleTableRecord
#define		AcDbDimStyleTableIterator CRxDbDimStyleTableIterator
#define		AcDbDimStyleTable CRxDbDimStyleTable
#define		AcDbSymbolTableIterator CRxDbSymbolTableIterator
#define		AcDbDatabase CRxDbDatabase
#define		AcDbPoint CRxDbPoint
#define		AcDbLine CRxDbLine
#define		AcDbBlockReference CRxDbBlockReference
#define		AcDbCircle CRxDbCircle
#define		AcDbArc		CRxDbArc
#define		AcDbExtents		CRxDbExtents
#define		AcDbRoughStyleTable CRxDbRoughStyleTable
#define		AcDbDatumStyleTable CRxDbDatumStyleTable
#define		AcDbCutsStyleTable CRxDbCutsStyleTable
#define		AcDbWeldStyleTable CRxDbWeldStyleTable
#define		AcDbGeoTolStyleTable CRxDbGeoTolStyleTable
#define     AcDbPdfReference CRxDbPdfReference
#define     AcDbPdfDefinition CRxDbPdfDefinition

// ≈˙¡øÃ˙ÿ”
#define		AcDbSolid					CRxDbSolid
#define		AcDbHatch					CRxDbHatch
#define		AcDbImageRef				CRxDbImageRef
#define		AcDbOleObject				CRxDbOleObject
#define		AcDbDimHalf					CRxDbDimHalf
#define		AcDbDimRay					CRxDbDimRay
#define		AcDbDimTaper				CRxDbDimTaper
#define		AcDbDimPitch				CRxDbDimPitch
#define		AcDbDimCuts					CRxDbDimCuts
#define		AcDbDimChamfer				CRxDbDimChamfer
#define		AcDbDimLeader				CRxDbDimLeader
#define		AcDbDimCenterHole			CRxDbDimCenterHole
#define		AcDbDimOrigin				CRxDbDimOrigin
#define		AcDbDimCoord				CRxDbDimCoord
#define		AcDbDimOriAlgn				CRxDbDimOriAlign
#define		AcDbDimHolePos				CRxDbDimHolePos
#define		AcDbDimCrdList				CRxDbDimCrdList
#define		AcDbDimGeoTol				CRxDbDimGeoTol
#define		AcDbDimRough				CRxDbDimRough
#define		AcDbDimWeld					CRxDbDimWeld
#define		AcDbDimDatum				CRxDbDimDatum
#define		AcDbPartNo					CRxDbPartNo
#define		AcDbBomTable				CRxDbBomTable
#define		AcDbView2D					CRxDbView2D
#define		AcDbView3D					CRxDbView3D

#define		AcDbDimension	CRxDbDimension
#define		AcDbOrdinateDimension	CRxDbOrdinateDimension
#define		AcDbAlignedDimension	CRxDbAlignedDimension
#define		AcDbRotatedDimension	CRxDbRotatedDimension
#define		AcDb3PointAngularDimension	CRxDb3PointAngularDimension
#define		AcDb2LineAngularDimension	CRxDb2LineAngularDimension
#define		AcDbRadialDimension	CRxDbRadialDimension
#define		AcDbDiametricDimension	CRxDbDiametricDimension
#define		AcDbArcDimension	CRxDbArcDimension
#define		AcDbRadialDimensionLarge	CRxDbRadialDimensionLarge


#define		AcDbHostApplicationServices					CRxDbHostApplicationServices
#define		AcDbGlobals									CrxDbGlobals
#define		AcadInternalServices						CrxInternalServices
#define     AcGePoint3d    CRxGePoint3d 
#define     AcGePoint2d    CRxGePoint2d
#define     AcGeVector2d    CRxGeVector2d
#define     AcGeVector3d    CRxGeVector3d
#define     AcGeMatrix2d    CRxGeMatrix2d
#define     AcGeMatrix3d    CRxGeMatrix3d
#define     AcGeScale3d     CRxGeScale3d
#define     AcGeScale2d     CRxGeScale2d

#define    AcGeCircArc2d                  CRxGeCircArc2d
#define    AcGeCircArc3d                  CRxGeCircArc3d
#define     AcGeBoundBlock2d                 CRxGeBoundBlock2d
#define     AcGeBoundBlock3d                  CRxGeBoundBlock3d
#define     AcGeCurve2d                  CRxGeCurve2d
#define     AcGeCurve3d                    CRxGeCurve3d
#define      AcGeEllipArc2d                  CRxGeEllipArc2d
#define     AcGeEntity2d                  CRxGeEntity2d
#define     AcGeEntity3d                  CRxGeEntity3d
#define     AcGeTol                  CRxGeTol
#define     AcGeInterval                   CRxGeInterval
#define     AcGeLinearEnt2d                    CRxGeLinearEnt2d
#define     AcGeLinearEnt3d                   CRxGeLinearEnt3d
#define    AcGeLine2d                    CRxGeLine2d
#define     AcGeLine3d                   CRxGeLine3d
#define    AcGeLineSeg2d                    CRxGeLineSeg2d
#define    AcGeLineSeg3d                    CRxGeLineSeg3d
#define     AcGePointEnt2d                   CRxGePointEnt2d
#define     AcGePlanarEnt                   CRxGePlanarEnt
#define     AcGePlane                    CRxGePlane
#define    AcGePointOnCurve2d                    CRxGePointOnCurve2d
#define    AcGeSurface                    CRxGeSurface
#define		AcGePoint3dArray			CRxGePoint3dArray
#define		AcGePoint2dArray			CRxGePoint2dArray
#define		AcGeVector2dArray			CRxGeVector2dArray
#define		AcGeVector3dArray			CRxGeVector3dArray
#define		AcGeBoundedPlane			CRxGeBoundedPlane
#define		AcDbVoidPtrArray			CRxDbVoidPtrArray
#define		AcGeError	CRxGeError
#define		AcGeVoidPointerArray	CRxGeVoidPointerArray

#define		acdbHandEnt									crxdbHandEnt
#define		AcDbDatabaseReactor									CRxDbDatabaseReactor
#define		AcDbEllipse									CRxDbEllipse
#define		AcDbEntityAdapter									CRxDbEntityAdapter
#define		AcDbFullSubentPath									CRxDbFullSubentPath
#define		AcDbObjAdapter									CRxDbObjAdapter
#define		AcDbObjectId									CRxDbObjectId
#define		AcDbObjectIterator									CRxDbObjectIterator
#define		AcDbObjectReactor									CRxDbObjectReactor
#define		AcDbObjectIdArray									CRxDbObjectIdArray
#define		AcDbPolyline									CRxDbPolyline
#define		AcDbProxyEntity									CRxDbProxyEntity
#define		AcDbProxyObject									CRxDbProxyObject
#define		AcDbSpline									CRxDbSpline
#define		AcDbCrxTransactionManager									CRxDbCrxTransactionManager
#define		AcDbXObject									CRxDbXObject
#define		AcDbXrecord									CRxDbXrecord
#define		AcDbHandle									CRxDbHandle
#define		acad_malloc									crx_malloc
#define		acad_free									crx_free
#define		acad__msize									crx__msize
#define		acad_realloc									crx_realloc
#define		acad_calloc									crx_calloc
#define		acad__strdup									crx__strdup
#define		AcDbIdMapping								CRxDbIdMapping

// GI
#define		AcGiColorRGB				CRxGiColorRGB
#define		AcGiColorRGBA				CRxGiColorRGBA
#define		AcGiPixelBGRA32				CRxGiPixelBGRA32
#define		AcGiImageBGRA32				CRxGiImageBGRA32
#define		AcGiContext				CRxGiContext
#define		AcGiCommonDraw				CRxGiCommonDraw
#define		AcGiWorldDraw				CRxGiWorldDraw
#define		AcGiSubEntityTraits				CRxGiSubEntityTraits
#define		AcGiGeometry				CRxGiGeometry
#define		AcGiWorldGeometry				CRxGiWorldGeometry
#define		AcGiWorldGeometry2				CRxGiWorldGeometry2
#define		AcGiFaceData				CRxGiFaceData
#define		AcGiVertexData				CRxGiVertexData
#define		AcGiTextStyle				CRxGiTextStyle
#define		AcGiDrawableTraits				CRxGiDrawableTraits
#define		AcGiVisualStyle		CRxGiVisualStyle
#define		AcGiContextualColors		CRxGiContextualColors
#define		AcGiViewportDraw		CRxGiViewportDraw
#define		AcGiViewport		CRxGiViewport
#define		AcGiViewportGeometry		CRxGiViewportGeometry

// Macro
#define ACGI_SERVICES CRxGI_SERVICES

// GS
#define     AcGsNode				CRxGsNode
#define     AcGsView				CRxGsView

#define		AcGiDrawable		CRxGiDrawable
#define		AcGeMatrix3d		CRxGeMatrix3d
#define		AcGePoint3d		CRxGePoint3d
#define		AcGeVector3d		CRxGeVector3d
#define		AcGePoint2d		CRxGePoint2d
#define		AcGsModel		CRxGsModel
#define		AcGsDevice		CRxGsDevice
#define		AcGsConfig		CRxGsConfig
#define		AcGsReactor		CRxGsReactor
#define		AcGsClassFactory		CRxGsClassFactory
#define		AcGsDCRect		CRxGsDCRect 
#define		AcGsManager		CRxGsManager 
#define     acgsGetGsManager crxgsGetGsManager
#define		acgsGetDisplayInfo	crxgsGetDisplayInfo
#define		acgsGetViewportInfo	crxgsGetViewportInfo
#define		AcGsScreenShot	CRxGsScreenShot
#define		acgsGetScreenShot	crxgsGetScreenShot
#define		acgsSetViewportRenderFlag	crxgsSetViewportRenderFlag
#define		acgsDisplayImage	crxgsDisplayImage
#define		acgsRemoveAnonymousGraphics	crxgsRemoveAnonymousGraphics
#define		acgsCustomUpdateMethod	crxgsCustomUpdateMethod
#define		acgsSetCustomUpdateMethod	crxgsSetCustomUpdateMethod
#define		acgsRedrawShortTermGraphics	crxgsRedrawShortTermGraphics
#define		AcGs	CRxGs
#define		acgsSetHighlightColor	crxgsSetHighlightColor
#define		acgsGetHighlightColor	crxgsGetHighlightColor
#define		acgsSetHighlightLinePattern	crxgsSetHighlightLinePattern
#define		acgsGetHighlightLinePattern	crxgsGetHighlightLinePattern
#define		acgsSetHighlightLineWeight	crxgsSetHighlightLineWeight
#define		acgsGetHighlightLineWeight	crxgsGetHighlightLineWeight
#define		AcGsView	CRxGsView
#define		AcGsManager	CRxGsManager
#define		acgsSetViewParameters	crxgsSetViewParameters         
#define		acgsGetViewParameters	crxgsGetViewParameters         
#define		acgsSetLensLength	crxgsSetLensLength
#define		acgsGetLensLength	crxgsGetLensLength
#define		acgsWriteViewToUndoController crxgsWriteViewToUndoController 
#define		acgsSetView2D	crxgsSetView2D
#define		acgsGetGsView	crxgsGetGsView
#define		acgsGetOrthoViewParameters	crxgsGetOrthoViewParameters
#define		AcGs2DViewLimitManager	CRxGs2DViewLimitManager
#define		acgsCreate2DViewLimitManager	crxgsCreate2DViewLimitManager
#define		acgsDestroy2DViewLimitManager	crxgsDestroy2DViewLimitManager
//Maroc

//////////////////////////////////////////////////////////////////////////
/// <summary> 
/// CrxUI ---- AcUI
/// </summary>
//////////////////////////////////////////////////////////////////////////
//TODO
#define AdUI_REPLY CRxUI_REPLY
#define ADUI_NOTIFY CRxUI_NOTIFY
#define ADUI_COMMAND_STATE CRxUI_COMMAND_STATE

//class
#define CAdUiBaseDialog CCRxUiBaseDialog
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
/// <summary> 
/// CrxGe ---- AcGe
/// </summary>
//////////////////////////////////////////////////////////////////////////
//TODO
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
/// <summary> 
/// CrxGi ---- AcGi
/// </summary>
//////////////////////////////////////////////////////////////////////////
//TODO
//////////////////////////////////////////////////////////////////////////

#endif