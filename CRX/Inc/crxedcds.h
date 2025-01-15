//£®C£©Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ∞Ê»®À˘”–£®C£©±±æ© ˝¬ÅEÛ∑Ωø∆ººπ…∑›”–œﬁπ´Àæ
//  ◊˚Ú’”√ªß π”√±æ»˙ÿ˛±ÿ–ÅEÒ ÿ°∂CAXA◊˚Ú’”√ªß–˙€… π”√–≠“È°∑
//

#ifndef _crxedads_h
#define _crxedads_h 1

// Ensure that C++ modules use the right linking conventions when calling
// functions contained in C.

#ifdef __cplusplus
    extern "C" {
#endif

#include "cdsdef.h"
#include "crxmem.h"
#include "crxChar.h"
#include "CrxEdApiCx.h"

#pragma pack (push, 8)
/* External function definitions accessible from applications */

void           crx_abort (const CxCHAR * format, ...);
CxCHAR*         crxedGetAppName ();
int            crxedUpdate(int vport, crx_point p1, crx_point p2);

CRXEDAPI_API
HWND           crxMainWnd();
#ifndef crx_hwndCrx
#define crx_hwndCrx crxMainWnd()
#endif

CRXEDAPI_API
DWORD          crxMainThreadId();

/* MFC "Document View" window handle */
HWND           adsw_cdraftDocWnd();

/* The following functions are supported in ObjectARX */
CRXEDAPI_API
int            crxedCommand (int rtype, ...);

CRXEDAPI_API
int            crxedCmd (const struct resbuf *rbp);

/* Register an ADS function handler */
int            crxedRegFunc (int (*fhdl) (void), int fcode);

/* Check for a console break */
int            crxedUsrBrk (void);


/* Define an external subroutine in AutoLISP */
int            crxedDefun (const CxCHAR *sname, short funcno);

/* Define help for that external subroutine */
int            crxedSetFunHelp (const CxCHAR* pszFunctionName, 
                               const CxCHAR* pszHelpfile,
                               const CxCHAR* pszTopic, int iCmd);

/* Undefine an external subroutine in AutoLISP */
int            crxedUndef (const CxCHAR *sname, short funcno);

/* Unitilies for external subroutine interface */
int            crxedGetFunCode (void);
struct resbuf *crxedGetArgs (void);

/* Return the specified type as a result of external subroutine */
int            crxedRetList (const struct resbuf *rbuf);
int            crxedRetVal (const struct resbuf *rbuf);
int            crxedRetPoint (const crx_point pt);
int            crxedRetStr (const CxCHAR *s);
int            crxedRetName (const crx_name aname, int type);
int            crxedRetInt (int ival);
int            crxedRetReal (crx_real rval);
int            crxedRetT (void);
int            crxedRetNil (void);
int            crxedRetVoid (void);

/* CaxaDraft Entity access routines */

//	Õ®π˝Ωªª• ∞»°µ•∏ˆ∂‘œÛ£¨≤ª÷ß≥÷µÅEÅE
CRXEDAPI_API
int            crxedEntSel (const CxCHAR *str, crx_name entres,
							crx_point ptres);
//	Õ®π˝Ωªª•÷∏∂®µ„ªÚ’ﬂ∏¯∂®“ª∏ˆµ„ ∞»°µ•∏ˆ∂‘œÛ£¨‘ –˙—ÅEÅE
CRXEDAPI_API
int            crxedNEntSel (const CxCHAR *str, crx_name entres,
							 crx_point ptres, crx_point xformres[4],
struct resbuf **refstkres);

//	Õ®π˝÷∏∂®µ„ ∞»°µ•∏ˆ∂‘œÛ£¨‘ –˙—ÅEÅE
CRXEDAPI_API
int            crxedNEntSelP (const CxCHAR *str, crx_name entres,
							  crx_point ptres, int pickflag,
							  crx_matrix xformres,
struct resbuf **refstkres);

// Õ®π˝“ª÷÷Ωªª•—°‘Òƒ£ ΩªÒµ√“ª∏ˆ—°‘ÒºØ
CRXEDAPI_API
int            crxedSSGet (const CxCHAR *str, const void *pt1,
						   const void *pt2, const struct resbuf *filter,
						   crx_name ss);

int            crxedSSGetFirst (struct resbuf** gset, struct resbuf** pset);
int            crxedSSSetFirst (const crx_name pset, const crx_name unused);

// Õ∑≈“ª∏ˆ—°‘ÒºØ
CRXEDAPI_API
int            crxedSSFree (/*const */crx_name sname);

//ªÒµ√—°‘ÒºØ≥§∂»£®‘™Àÿ∏ˆ ˝£©
CRXEDAPI_API
int            crxedSSLength (const crx_name sname, long *len);

//œÚ—°‘ÒºØ÷–Ã˙ÿ”“ª∏ˆ∂‘œÅE
CRXEDAPI_API
int            crxedSSAdd (const crx_name ename, const crx_name sname,
						   crx_name result);

//¥”—°‘ÒºØ÷–…æ≥˝“ª∏ˆ∂‘œÅE
CRXEDAPI_API
int            crxedSSDel (const crx_name ename, const crx_name ss);
//≈–∂œ“ª∏ˆ∂‘œÛ «∑Ò‘⁄—°‘ÒºØ÷–
CRXEDAPI_API
int            crxedSSMemb (const crx_name ename, const crx_name ss);

//∏˘æ›À˜“˝µ√µΩ—°‘ÒºØ÷–µƒ∂‘œÅE
CRXEDAPI_API
int            crxedSSName (const crx_name ss, long i, crx_name entres);

CRXEDAPI_API
int            crxedSSNameX (struct resbuf **rbpp, const crx_name ss,
							 const long i);

int            crxedSSGetKwordCallbackPtr(struct resbuf* (**pFunc)(const CxCHAR*));
int            crxedSSSetKwordCallbackPtr(struct resbuf* (*pFunc)(const CxCHAR*));
int            crxedSSGetOtherCallbackPtr(struct resbuf* (**pFunc)(const CxCHAR*));
int            crxedSSSetOtherCallbackPtr(struct resbuf* (*pFunc)(const CxCHAR*));

// 
CRXEDAPI_API
int            crxedTrans (const crx_point pt, const struct resbuf *from,
						   const struct resbuf *to, int disp,
						   crx_point result);

/* General CaxaDraft utility routines */
CRXEDAPI_API 
int            crxedSetVar (const CxCHAR *sym, const struct resbuf *val);

// ≥ı ºªØKWord¡¥±ÅE
CRXEDAPI_API
int            crxedInitGet (int val, const CxCHAR *kwl);

int            crxedGetSym (const CxCHAR *sname, struct resbuf **value);
int            crxedPutSym (const CxCHAR *sname, struct resbuf *value);

int            crxedHelp (const CxCHAR* szFilename, const CxCHAR* szTopic, int iCmd);
int            crxedHelpForExternal (const CxCHAR *pszFunctionName);
int            crxedFNSplit (const CxCHAR *pathToSplit, CxCHAR *prebuf,
                            CxCHAR *namebuf, CxCHAR *extbuf);

/*  These values are identical to those for the WinHelp() call in the 
    Microsoft Windows(tm) SDK.  If you are using crxedHelp() to call CaxaDraft 
    platform-independent Help these are the only values available to you.  
    If you are using crxedHelp() to call WinHelp() you can include the Windows 
    header file winuser.h and use the full WinHelp() API.  */
#define HELP_CONTENTS     0x0003L  /* display first topic */
#define HELP_HELPONHELP   0x0004L  /* Display help on using help */
#define HELP_PARTIALKEY   0x0105L  /* Display Search dialog */

struct resbuf  *crxedCrxLoaded (void);
int            crxedCrxLoad (const CxCHAR *app);
int            crxedCrxUnload (const CxCHAR *app);

int            crxedInvoke (const struct resbuf *args,
                             struct resbuf **result);
/* Functions that get system variables */
CRXEDAPI_API 
int            crxedGetVar (const CxCHAR *sym, struct resbuf *result);
int            crxedFindFile (const CxCHAR *fname, CxCHAR *result);

/* Functions that get/set environment variables */
int            crxedGetEnv (const CxCHAR *sym, CxCHAR  *var);
int            crxedSetEnv (const CxCHAR *sym, const CxCHAR *val);

/* Functions that get/set configurations  variables */
int            crxedGetCfg (const CxCHAR *sym, CxCHAR  *var, int len);
int            crxedSetCfg (const CxCHAR *sym, const CxCHAR *val);

/* Functions that get a string */
//ªÒµ√”√ªß ‰»ÅEƒ◊÷∑˚¥Æ
/*****************************************************************************
* function£∫Get string with user input£ªthis function is not safe, Suggest to use the function----crxedGetStringB
* parameter£∫	
*					int cronly:	whther commit by Space.  0£∫ only commit by Enter; None 0£∫commit by Enter or Space
*					const CxCHAR *prompt	user command promotation
*					CxCHAR *result				string what user input, the space allocated for result must be large than 132
****************************************************************************/
CRXEDAPI_API
int            crxedGetString (int cronly, const CxCHAR *prompt, CxCHAR *result);


/*****************************************************************************
* function explain£∫Get string with user import
* function definition£∫int            crxedGetStringB (int cronly, const CxCHAR *prompt, 
*															CxCHAR *result, int bufsize)
* parameter£∫	
*					int cronly:	whther commit by Space.  0£∫ only commit by Enter; None 0£∫commit by Enter or Space
*					const CxCHAR *prompt	user command promotation
*					CxCHAR *result				string what user input
*					int bufsize					Buffer length of result
****************************************************************************/
CRXEDAPI_API
int            crxedGetStringB (int cronly, const CxCHAR *prompt,
								CxCHAR *result, int bufsize);

/* Functions that pass CaxaDraft a single string  */
int            crxedMenuCmd (const CxCHAR *str);
CRXEDAPI_API
int            crxedPrompt (const CxCHAR *str);

CRXEDAPI_API
int            crxedAlert (const CxCHAR *str);

/* Functions used to get user input  */
//ªÒµ√”√ªß ‰»ÅEƒΩ«∂»
CRXEDAPI_API 
int				crxedGetAngle (const crx_point pt, const CxCHAR *prompt,
							   crx_real *result);
CRXEDAPI_API
int            crxedGetCorner (const crx_point pt, const CxCHAR *prompt,
							   crx_point result);
//ªÒµ√”√ªß ∞»°µƒ¡¥
CRXEDAPI_API
int crxedGetChain (const CxCHAR *prompt,
							 crx_name result,crx_point pt);
//ªÒµ√”√ªß ‰»ÅEƒæ‡¿ÅE
CRXEDAPI_API
int            crxedGetDist (const crx_point pt, const CxCHAR *prompt,
							 crx_real *result);
CRXEDAPI_API
int            crxedGetOrient (const crx_point pt, const CxCHAR *prompt,
							   crx_real *result);
//ªÒµ√”√ªß ‰»ÅEƒµÅE
CRXEDAPI_API
int            crxedGetPoint (const crx_point pt, const CxCHAR *prompt,
							  crx_point result);
//ªÒµ√”√ªß ‰»ÅEƒ’˚ ˝
CRXEDAPI_API
int            crxedGetInt (const CxCHAR *prompt, int *result);

CRXEDAPI_API
int            crxedGetKword (const CxCHAR *prompt, CxCHAR *result);

//ªÒµ√”√ªß ‰»ÅEƒ µ ˝
CRXEDAPI_API
int            crxedGetReal (const CxCHAR *prompt, crx_real *result);

CRXEDAPI_API
int            crxedGetInput (CxCHAR *str);

CRXEDAPI_API
int            crxedVports (struct resbuf **vlist);

/* Functions for screen flipping */
int            crxedTextScr (void);
int            crxedGraphScr (void);
int            crxedTextPage (void);

/* Graphics related functions */
CRXEDAPI_API
int            crxedRedraw (const crx_name ent, int mode);
int            crxedOsnap (const crx_point pt, const CxCHAR *mode,
                            crx_point result);
int            crxedGrRead (int track, int *type, struct resbuf *result);
int            crxedGrText (int box, const CxCHAR *text, int hl);
int            crxedGrDraw (const crx_point from, const crx_point to,
                             int color, int hl);
int            crxedGrVecs (const struct resbuf *vlist, crx_matrix mat);
int            crxedXformSS (const crx_name ssname,
                              crx_matrix genmat);
int            crxedDragGen (const crx_name ss, const CxCHAR *pmt, int cursor,
                              int (*scnf) (crx_point pt, crx_matrix mt),
                              crx_point p);
int            crxedSetView (const struct resbuf *view, int vport);


/* Functions that put up standard dialogs for user input */
int            crxedGetFileD (const CxCHAR *title, const CxCHAR *defawlt,
                               const CxCHAR *ext, int flags,
                               struct resbuf *result);
int            crxedGetFileNavDialog (const CxCHAR *title, const CxCHAR *defawlt,
                             const CxCHAR *ext, const CxCHAR *dlgname, int flags,
                             struct resbuf **result);

int            crxedTextBox (const struct resbuf *args,
                              crx_point pt1, crx_point pt2);

/*  Function to retrieve or establish CaxaDraft's tablet transformation: */
int            crxedTablet  (const struct resbuf *args,
                              struct resbuf **result);

/* Function for retrieving the localized or the language independent
   name of a command. */
int            crxedGetCName (const CxCHAR *cmd, CxCHAR **result);

// Internal use only. 
int           crxedEatCommandThroat(void);

// The following are AcDb related, but were not able to be moved over
// to AcDb at this time.  They will be moved in a future release.  7/14/98

CRXEDAPI_API
int            crxdbEntDel (const crx_name ent);
struct resbuf *crxdbEntGetX (const crx_name ent, const struct resbuf *args);
struct resbuf *crxdbEntGet (const crx_name ent);
CRXEDAPI_API
int            crxdbEntLast (crx_name result);
CRXEDAPI_API
int            crxdbEntNext (const crx_name ent, crx_name result);
int            crxdbEntUpd (const crx_name ent);
int            crxdbEntMod (const struct resbuf *ent);
int            crxdbEntMake (const struct resbuf *ent);
int            crxdbEntMakeX (const struct resbuf *entm, crx_name result);
CRXEDAPI_API
int            crxdbRegApp (const CxCHAR *appname);
struct resbuf *crxdbTblNext (const CxCHAR *tblname, int rewind);
struct resbuf *crxdbTblSearch (const CxCHAR *tblname, const CxCHAR *sym,
                              int setnext);
int            crxdbNamedObjDict (crx_name result);
struct resbuf *crxdbDictSearch (const crx_name dict, const CxCHAR* sym, 
                               int setnext);
struct resbuf *crxdbDictNext (const crx_name dict, int rewind);
int            crxdbDictRename (const crx_name dictname, const CxCHAR* oldsym,
                               const CxCHAR* newsym);
int            crxdbDictRemove (const crx_name dictname, const CxCHAR* symname);
int            crxdbDictAdd (const crx_name dictname, const CxCHAR* symname,
                            const crx_name newobj);

int            crxdbTblObjName (const CxCHAR *tblname, const CxCHAR *sym, 
                               crx_name result);
CRXEDAPI_API
int            crxdbAngToS (crx_real v, int unit, int prec, CxCHAR *str);
CRXEDAPI_API
int            crxdbRawAngToS (crx_real v, int unit, int prec, CxCHAR *str);
CRXEDAPI_API
int            crxdbRToS (crx_real val, int unit, int prec, CxCHAR *str);
CRXEDAPI_API
int            crxdbAngToF (const CxCHAR *str, int unit, crx_real *v);
CRXEDAPI_API
int            crxdbRawAngToF (const CxCHAR *str, int unit, crx_real *v);
CRXEDAPI_API
int            crxdbDisToF (const CxCHAR *str, int unit, crx_real *v);
CRXEDAPI_API
int            crxdbInters (const crx_point from1, const crx_point to1,
                             const crx_point from2, const crx_point to2,
                             int teston, crx_point result);
int            crxdbSNValid (const CxCHAR *tbstr, int pipetest);

int            cds_queueexpr(CxCHAR* expr);

#pragma pack (pop)

#ifdef __cplusplus
    }
#endif  /* __cplusplus */

#pragma pack (push, 8)
#ifdef __cplusplus
extern "C++" {

int            crxedGetFullInput(CxCHAR *&pStr);
int            crxedGetFullKword(const CxCHAR * pString, CxCHAR *&pStr);
int            crxedGetFullString(int cronly, const CxCHAR *pString,
                                 CxCHAR *&pResult);
int            crxedSSNameXEx (struct resbuf **rbpp, const crx_name ss,
                              const long i, unsigned int flags = 0);
}

#endif  /* __cplusplus */

#pragma pack (pop)

#endif  /* !_acedads_h */
 
