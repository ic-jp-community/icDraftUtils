#ifndef _CODEPGID_H
#define _CODEPGID_H
//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//	End-users must also comply with the terms and conditions 
//	in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//	版权所有（C）北京数码大方科技股份有限公司
//	最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
// 

#pragma pack (push, 8)

/* This list contains identifiers for all of the code pages used with
   CDraft.  You can add entries (before the CODE_PAGE_CNT item), but
   don't ever delete one.
*/
typedef enum {
    CODE_PAGE_UNDEFINED = 0,
    CODE_PAGE_ASCII,
    CODE_PAGE_8859_1,
    CODE_PAGE_8859_2,
    CODE_PAGE_8859_3,
    CODE_PAGE_8859_4,
    CODE_PAGE_8859_5,
    CODE_PAGE_8859_6,
    CODE_PAGE_8859_7,
    CODE_PAGE_8859_8,
    CODE_PAGE_8859_9,
    CODE_PAGE_DOS437,
    CODE_PAGE_DOS850,
    CODE_PAGE_DOS852,
    CODE_PAGE_DOS855,
    CODE_PAGE_DOS857,
    CODE_PAGE_DOS860,
    CODE_PAGE_DOS861,
    CODE_PAGE_DOS863,
    CODE_PAGE_DOS864,
    CODE_PAGE_DOS865,
    CODE_PAGE_DOS869,
    CODE_PAGE_DOS932,
    CODE_PAGE_MACINTOSH,
    CODE_PAGE_BIG5,
    CODE_PAGE_KSC5601,
    CODE_PAGE_JOHAB,
    CODE_PAGE_DOS866,
    CODE_PAGE_ANSI_1250,
    CODE_PAGE_ANSI_1251,
    CODE_PAGE_ANSI_1252,
    CODE_PAGE_GB2312,
    CODE_PAGE_ANSI_1253,
    CODE_PAGE_ANSI_1254,
    CODE_PAGE_ANSI_1255,
    CODE_PAGE_ANSI_1256,
    CODE_PAGE_ANSI_1257,
    CODE_PAGE_ANSI_874,
    CODE_PAGE_ANSI_932,
    CODE_PAGE_ANSI_936,
    CODE_PAGE_ANSI_949,
    CODE_PAGE_ANSI_950,
    CODE_PAGE_ANSI_1361,
    CODE_PAGE_ANSI_1200,
    CODE_PAGE_ANSI_1258,
    CODE_PAGE_CNT
} code_page_id;

#pragma pack (pop)

inline bool
isValidCodePageId(code_page_id value)
{
    return ((int)value >= 0) && ((int)value < CODE_PAGE_CNT);
}

#endif // CODEPGID_H_
