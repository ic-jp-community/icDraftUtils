//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//	End-users must also comply with the terms and conditions 
//	in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//	版权所有（C）北京数码大方科技股份有限公司
//	最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
// 

#ifndef _cdsmigr_h
#define _cdsmigr_h 1


#define cds_malloc	crx_malloc
#define cds_free	crx_free
#define cds__msize	crx__msize
#define cds_realloc crx_realloc
#define cds_calloc	crx_calloc
#define cds_strdup	crx__strdup

// crxed related #defines.
//
#define	cds_getappname	crxedGetAppName
#define	cds_update	crxedUpdate
#define	cds_command	crxedCommand
#define	cds_cmd	crxedCmd
#define	cds_regfunc	crxedRegFunc
#define	cds_usrbrk		crxedUsrBrk
#define	cds_defun		crxedDefun
#define	cds_setfunhelp	crxedSetFunHelp
#define	cds_undef	crxedUndef
#define	cds_getfuncode	crxedGetFunCode
#define	cds_getargs	crxedGetArgs
#define	cds_retlist	crxedRetList
#define	cds_retval	crxedRetVal
#define	cds_retpoint	crxedRetPoint
#define	cds_retstr	crxedRetStr
#define	cds_retname	crxedRetName
#define	cds_retint	crxedRetInt
#define	cds_retreal	crxedRetReal
#define	cds_rett crxedRetT
#define	cds_retnil	crxedRetNil
#define	cds_retvoid	crxedRetVoid
#define	cds_entsel	crxedEntSel
#define	cds_nentsel	crxedNEntSel
#define	cds_nentselp	crxedNEntSelP
#define	cds_ssget	crxedSSGet

#define	cds_ssgetfirst	crxedSSGetFirst
#define cds_sssetfirst		crxedSSSetFirst

#define	cds_ssfree	crxedSSFree
#define	cds_sslength	crxedSSLength
#define	cds_ssadd	crxedSSAdd
#define	cds_ssdel	crxedSSDel
#define	cds_ssmemb	crxedSSMemb
#define	cds_ssname	crxedSSName
#define	cds_ssnamex	crxedSSNameX
#define	cds_ssGetKwordCallbackPtr	crxedSSGetKwordCallbackPtr
#define	cds_ssSetKwordCallbackPtr	crxedSSSetKwordCallbackPtr
#define	cds_ssGetOtherCallbackPtr	crxedSSGetOtherCallbackPtr
#define	cds_ssSetOtherCallbackPtr	crxedSSSetOtherCallbackPtr
#define	cds_setvar	crxedSetVar
#define	cds_initget	crxedInitGet
#define	cds_getsym	crxedGetSym
#define	cds_putsym	crxedPutSym
#define	cds_help	crxedHelp
#define	cds_fnsplit	crxedFNSplit
#define	cds_trans	crxedTrans
#define	cds_arxloaded	crxedArxLoaded
#define	cds_arxload	crxedArxLoad
#define	cds_arxunload	crxedArxUnload
#define	cds_invoke	crxedInvoke
#define	cds_getvar		crxedGetVar
#define	cds_findfile	crxedFindFile
#define	cds_agetenv	crxedGetEnv
#define	cds_asetenv	crxedSetEnv
#define	cds_getenv	crxedGetEnv
#define	cds_setenv	crxedSetEnv
#define	cds_agetcfg	crxedGetCfg
#define	cds_asetcfg	crxedSetCfg
#define	cds_getcfg	crxedGetCfg
#define	cds_setcfg	crxedSetCfg
#define	cds_getstring	crxedGetString
#define	cds_getstringb	crxedGetStringB
#define	cds_menucmd	crxedMenuCmd
#define	cds_prompt	crxedPrompt
#define	cds_alert	crxedAlert
#define	cds_getangle	crxedGetAngle
#define	cds_getcorner	crxedGetCorner
#define	cds_getdist	crxedGetDist
#define	cds_getorient		crxedGetOrient
#define	cds_getpoint	crxedGetPoint
#define	cds_getint	crxedGetInt
#define	cds_getkword	crxedGetKword
#define	cds_getreal	crxedGetReal
#define	cds_getinput	crxedGetInput
#define	cds_vports		crxedVports
#define	cds_textscr	crxedTextScr
#define	cds_graphscr	crxedGraphScr
#define	cds_textpage	crxedTextPage
#define	cds_redraw	crxedRedraw
#define	cds_osnap	crxedOsnap
#define	cds_grread	crxedGrRead
#define	cds_grtext	crxedGrText
#define	cds_grdraw	crxedGrDraw
#define	cds_grvecs	crxedGrVecs
#define	cds_xformss	crxedXformSS
#define	cds_draggen	crxedDragGen
#define	cds_setview	crxedSetView
#define	cds_getfiled	crxedGetFileD
#define	cds_textbox	crxedTextBox
#define	cds_tablet	crxedTablet
#define	cds_getcname	crxedGetCName

// CRxDb related #defines that are available to ObjectDBX
// applications.
#define	cds_xdroom	crxdbXdRoom
#define	cds_xdsize	crxdbXdSize

/* NOTE that the result is the SECOND argument,
   consistent with ADS usage.  The standard C ones require <string.h> */
#ifdef __STDC__
#define cds_name_set(from, to)  (memcpy(to, from, sizeof(crx_name)))
#define crx_point_set(from,to)  (memcpy(to, from, sizeof(crx_point)))
#else
#define cds_name_set(from, to)  (*(to)= *(from), (to)[1]=(from)[1])
#define crx_point_set(from, to) (*(to)= *(from), (to)[1]=(from)[1], (to)[2]=(from)[2])
#endif  /* !__STDC__ */

/* Define null value for cds_names.  These values are NOT guaranteed valid;
   that is, there is no actual guarantee (such as C gives with NULL) that the
   system will never under any circumstances generate the values as valid data.
   The correct values will be created as part of the Lisp reinitialization
   project, if we go through with that one, and will then be inserted here.
   */
#define cds_name_clear(name)    name[0] = name[1] = 0
#define cds_name_nil(name)      (name[0] == 0 && name[1] == 0)
#define cds_name_equal(name1, name2)  (name1[0]==name2[0] \
                                       && name1[1]==name2[1])


// CRxDb related #defines that are not currently available
// to ObjectDBX applications.  7/14/98
#define	cds_entdel	crxdbEntDel
#define	cds_entgetx	crxdbEntGetX
#define	cds_entget	crxdbEntGet
#define	cds_entlast	crxdbEntLast
#define	cds_entnext	crxdbEntNext
#define	cds_entupd	crxdbEntUpd
#define	cds_entmod	crxdbEntMod
#define	cds_entmake	crxdbEntMake
#define	cds_entmakex	crxdbEntMakeX
#define	cds_tblnext	crxdbTblNext
#define	cds_tblsearch	crxdbTblSearch
#define	cds_namedobjdict	crxdbNamedObjDict
#define	cds_dictsearch	crxdbDictSearch
#define	cds_dictnext	crxdbDictNext
#define	cds_dictrename	crxdbDictRename
#define	cds_dictremove	crxdbDictRemove
#define	cds_dictadd	crxdbDictAdd
#define	cds_tblobjname	crxdbTblObjName
#define	cds_handent	crxdbHandEnt
#define	cds_inters	crxdbInters
#define	cds_snvalid	crxdbSNValid
#define	cds_xstrsave	crxdbXStrSave
#define	cds_xstrcase	crxdbXStrCase
#define	cds_regapp	crxdbRegApp
#define	cds_fail	crxdbFail
#define	cds_angtos	crxdbAngToS
#define	cds_rangtos	crxdbRawAngToS
#define	cds_rtos	crxdbRToS
#define	cds_angtof	crxdbAngToF
#define	cds_rangtof	crxdbRawAngToF
#define	cds_distof	crxdbDisToF
// Obsolete: we don't save as r12 anymore, so the xsave12 arg
// is ignored.
#define cds_regappx(appname, xsave12)   crxdbRegApp(appname)


// Functions that are now in crxutil dll
#define	cds_printf	crxutPrintf
#define	cds_cvunit	crxutCvUnit
#define	cds_wcmatch	crxutWcMatch
#define	cds_angle	crxutAngle
#define	cds_distance	crxutDistance
#define	cds_polar	crxutPolar
#define	cds_isalpha	crxutIsAlpha
#define	cds_isupper	crxutIsUpper
#define	cds_islower	crxutIsLower
#define	cds_isdigit	crxutIsDigit
#define	cds_isxdigit	crxutIsXDigit
#define	cds_isspace	crxutIsSpace
#define	cds_ispunct	crxutIsPunct
#define	cds_isalnum	crxutIsAlNum
#define	cds_isprint	crxutIsPrint
#define	cds_isgraph	crxutIsGraph
#define	cds_iscntrl	crxutIsCntrl
#define	cds_toupper	crxutToUpper
#define	cds_tolower	crxutToLower
#define	cds_newrb	crxutNewRb
#define	cds_relrb	crxutRelRb
#define	cds_buildlist	crxutBuildList

#endif // !adsmigr_h
