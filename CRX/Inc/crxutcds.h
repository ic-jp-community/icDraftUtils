//£®C£©Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ∞Ê»®À˘”–£®C£©±±æ© ˝¬ÅEÛ∑Ωø∆ººπ…∑›”–œﬁπ´Àæ
//  ◊˚Ú’”√ªß π”√±æ»˙ÿ˛±ÿ–ÅEÒ ÿ°∂CAXA◊˚Ú’”√ªß–˙€… π”√–≠“È°∑
//

#ifndef _crxutilads_h
#define _crxutilads_h 1

// Ensure that C++ modules use the right linking conventions when calling
// functions contained in C.

#ifdef __cplusplus
    extern "C" {
#endif

#include "cdsdef.h"
#include "crxChar.h"
#include "CrxCx.h"

#pragma pack (push, 8)

void           cdraft__assert(const CxCHAR *, const CxCHAR *, int);

int            crxutCvUnit (crx_real value, const CxCHAR *oldunit,
                             const CxCHAR *newunit, crx_real *result);
int            crxutWcMatch (const CxCHAR *string, const CxCHAR *pattern);

CRXDB_API
int            crxutPrintf (const CxCHAR *format, ...);

int            crxutSPrintf (CxCHAR *buffer, const CxCHAR *format, ...);

CRXDB_API
struct resbuf *crxutNewRb (int v);

CRXDB_API
int            crxutRelRb (struct resbuf *rb);

CRXDB_API
struct resbuf *crxutBuildList (int rtype, ...);


CRXDB_API
crx_real       crxutAngle (const crx_point pt1, const crx_point pt2);

CRXDB_API
crx_real       crxutDistance (const crx_point pt1, const crx_point pt2);

CRXDB_API
void           crxutPolar (const crx_point pt, crx_real angle,
                            crx_real dist, crx_point ptres);

int            crxutIsAlpha (int c);
int            crxutIsUpper (int c);
int            crxutIsLower (int c);
int            crxutIsDigit (int c);
int            crxutIsXDigit (int c);
int            crxutIsSpace (int c);
int            crxutIsPunct (int c);
int            crxutIsAlNum (int c);
int            crxutIsPrint (int c);
int            crxutIsGraph (int c);
int            crxutIsCntrl (int c);
int            crxutToUpper (int c);
int            crxutToLower (int c);

#pragma pack (pop)

#ifdef __cplusplus
    }
#endif

#endif // !crxutilads.h
