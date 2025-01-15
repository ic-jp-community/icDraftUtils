#ifndef   _CRXDEFS_H_
#define   _CRXDEFS_H_
//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//


#include "cdraft.h"
#pragma pack (push, 8)

#define NULLFCN static_cast<CAXA::IntPtr>(0)  // A NULL function pointer

#define CRX_ULONG_MAX 0xFFFFFFFF

#define CRX_ASCII_MAX 255  /* Same as UCHAR_MAX in <limits.h> */
#define CRX_EOS 0          /* End of String Indicator */

// CxRx:  typedef and enum namespace scoping struct.

struct CxRx {

    typedef void (*FcnPtr) ();

    enum         DictIterType { kDictSorted   = 0,
                                kDictCollated = 1 };

    enum         Ordering     { kLessThan     = -1,
                                kEqual        = 0,
                                kGreaterThan  = 1,
                                kNotOrderable = 2 };

    enum         AppMsgCode   { kNullMsg         = 0,
                                kInitAppMsg      = 1,
                                kUnloadAppMsg    = 2,
                                kLoadDwgMsg      = 3,
                                kUnloadDwgMsg    = 4,
                                kInvkSubrMsg     = 5,
                                kCfgMsg          = 6,
                                kEndMsg          = 7,
                                kQuitMsg         = 8,
                                kSaveMsg         = 9,
                                kDependencyMsg   = 10,
                                kNoDependencyMsg = 11,
                                kOleUnloadAppMsg = 12,
                                kPreQuitMsg      = 13,
                                kInitDialogMsg   = 14,
                                kEndDialogMsg    = 15,                                
                                kSuspendMsg      = 16,
                                kInitTabGroupMsg = 17,
                                kEndTabGroupMsg  = 18};                                
        

    enum        AppRetCode   { kRetOK          = 0,
                                kRetError       = 3 };
};

/* These messages are replaced by kLoadDwgMsg, and kUnloadDgwMsg.
 */
#ifndef kLoadADSMsg
#define kLoadADSMsg kLoadDwgMsg
#define kUnloadADSMsg kUnloadDwgMsg
#endif

#pragma pack (pop)

#endif
