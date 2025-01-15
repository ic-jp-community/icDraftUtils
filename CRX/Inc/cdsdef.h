#ifndef _cdsdef_h
#define _cdsdef_h 1

//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//	End-users must also comply with the terms and conditions 
//	in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//	版权所有（C）北京数码大方科技股份有限公司
//	最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
// 
#include "crxChar.h"

#define TRUE    1
#define FALSE   0
#ifndef EOS
#define EOS     CRX_T('\0')
#endif

#pragma pack(push, 8)

typedef double   crx_real;
typedef crx_real crx_point[3];
#ifndef _WIN64
// We don't use CDraft::IntPtr here because this file is included
// by .c files, and they can't handle the cdraft.h header.
typedef __w64 long crx_name[2];
typedef __w64 long *crx_namep;
#else
typedef __int64 crx_name[2];
typedef __int64 *crx_namep;
#endif
typedef crx_real crx_matrix[4][4];

/* When you want something that's explicitly a pointer type and not an array
   type, use crx_pointp and crx_namep.  Remember that if your function takes an
   *array* of points, it still declares crx_point[] foo; */
typedef crx_real *crx_pointp;

/* To protect macro-redefinition of the X, Y, Z, and T enumerated
   constants by legacy #define's, we remove their definition. */

#ifdef X
#undef X
#endif
#ifdef Y
#undef Y
#endif
#ifdef Z
#undef Z
#endif
#ifdef T
#undef T
#endif

#ifndef _XYZT_DEFINED
#define _XYZT_DEFINED
enum { X = 0, Y = 1, Z = 2 }; /* The coordinates of a point. */
enum { T = 3 };               /* The translation vector of a 3D matrix */
#endif // !_XYZT_DEFINED

/* The PAUSE token for ads_command and ads_cmd
 */
#define PAUSE CRX_T("\\")

/* The CDS_INITGET control bits
 */

enum {
    RSG_NONULL      = 0x01,  // Disallow null input 
    RSG_NOZERO      = 0x02,  // Disallow zero input 
    RSG_NONEG       = 0x04,  // Disallow negative input
    RSG_NOLIM       = 0x08,  // Do not check limits
    RSG_GETZ        = 0x10,  // Get Z coordinate
    RSG_DASH        = 0x20,  // Draw dashed rubber band/box
                             // (not a GEDIT control bit)
    RSG_2D          = 0x40,  // Restrict (getdist) to 2D (causes the
                             // UD_GETZ control bit to be cleared)
    RSG_OTHER       = 0x80,  // Return input string if unknown 
    RSG_DDISTFIRST  = 0x100, // Give DD entry precedence over arbitrary input
    RSG_TRACKUCS    = 0x200, // Allow UCS tracking for faces 
                             // (causes the UD_TRACKUCS control bit to be set)
    RSG_NOORTHOZ    = 0x400, // Disables polar/ortho tracking in the Z direction 
                             // (causes the UD_NOORTHOZ control bit to be set)
    RSG_NOOSNAP     = 0x800  // Disables object snaps
};

/* The following control bits are the old names for the RSG_
   control bits above.  These names are provided for
   backward compatibility.  You should use the RSG_ names
   above.
 */

enum {
    INP_NNULL   = RSG_NONULL,
    INP_NZERO   = RSG_NOZERO,
    INP_NNEG    = RSG_NONEG,
    INP_NLIM    = RSG_NOLIM,
    INP_DASH    = RSG_DASH,
    INP_NZCOORD = RSG_2D
};

enum SelectorType {
    SELECT_TYPE_FREE = 0,
    SELECT_TYPE_PICK,
    SELECT_TYPE_WPOLY,
    SELECT_TYPE_CPOLY,
    SELECT_TYPE_FENCE,
    SELECT_TYPE_SUBENTITY,
    SELECT_TYPE_BAG,
    SELECT_TYPE_LAST,
    SELECT_TYPE_LEAF,
    SELECT_TYPE_GROUP,
    SELECT_TYPE_PASTE,
    SELECT_TYPE_HATCHASC,
    SELECT_TYPE_NRVP,
    SELECT_TYPE_OCCLASS
};

/* Binary data stream structure
 */

struct crx_binary {    // Binary data chunk structure
    short clen;        // length of chunk in bytes (change to int?)
    // Unicode: leaving as char * for now, so that clients doing pointer
    // arithmetic with it will continue to work.  But it really should be 
    // a void *.
    char *buf;         // binary data
};

/*  Union for storing different ADS data types.
 */
 
union crx_u_val {
    crx_real rreal;
    crx_real rpoint[3];
    short rint;
    TCHAR *rstring;
#ifndef _WIN64
    __w64 long  rlname[2];
    __w64 long  mnLongPtr;  // use this instead of rlong for pointers
#else
    __int64     rlname[2];
    __int64     mnLongPtr;  // use this instead of rlong for pointers
#endif
    long rlong;             // a 32-bit integer value
    __int64     mnInt64;    // a 64-bit integer value
    struct crx_binary rbinary;
/* TEMPORARY probably, for internal use only at the moment */
    // Unicode: leave as unsigned char for now
    unsigned char ihandle[8];
}; 
 
/* The following is the structure definition of the general result buffer.
   This is used for both passing back results from functions, as well
   as exotic applications like entity lists, and command function lists.
   It is as close as we come to the AutoLISP node structure.
 */
struct resbuf {                                                  
        struct resbuf *rbnext; // Allows them to be "linked"
        short restype;
        union crx_u_val resval;
};

typedef struct resbuf *pResbuf;
typedef const struct resbuf *kpResbuf;  // for declarations

#pragma pack(pop)

#endif
