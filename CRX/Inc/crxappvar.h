//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//	End-users must also comply with the terms and conditions 
//	in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//	版权所有（C）北京数码大方科技股份有限公司
//	最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
// 

#ifndef CRXAPPVAR_H
#define CRXAPPVAR_H

#include "crxdb.h"
#pragma pack (push, 8)

enum {
    kGroupsOn     = 0x01,
    kHatchAssocOn = 0x02
};

class CRXDB_CLASS CRxDbAppSystemVariables {
public:
    inline CRxDbAppSystemVariables(); 
    inline ~CRxDbAppSystemVariables() {};

    // ATTDIA
    CDraft::ErrorStatus setAttdia(bool value, bool bUndo = false);
    inline bool attdia() const;

    // ATTREQ
    CDraft::ErrorStatus setAttreq(bool, bool bUndo = false);
    inline bool attreq() const;

    // BLIPMODE
    CDraft::ErrorStatus setBlipmode(bool, bool bUndo = false);
    inline bool blipmode() const;

    // COORDS
    CDraft::ErrorStatus setCoords(CAXA::Int16 value, bool bUndo = false);
    inline CAXA::Int16 coords() const;

    // STATUSBAR
    CDraft::ErrorStatus setStatusbar(CAXA::Int16 value, bool bUndo = false);
    inline CAXA::Int16 statusbar() const;

    // MENUBAR
    CDraft::ErrorStatus setMenubar(bool value, bool bUndo = false);
    inline bool menubar() const;

    // APPSTATUSBARUSEICONS
    CDraft::ErrorStatus setAppStatusBarUseIcons(bool value, bool bUndo = false);
    inline bool appstatusbaruseicons() const;

    // DELOBJ
    CDraft::ErrorStatus setDelUsedObj(CAXA::Int16, bool bUndo = false);
    inline CAXA::Int16 delUsedObj() const;

    // DRAGMODE
    CDraft::ErrorStatus setDragmode(CAXA::Int16, bool bUndo = false);
    inline CAXA::Int16 dragmode() const;

    // OSMODE
    CDraft::ErrorStatus setOsmode(CAXA::Int16 value, bool bUndo = false);
    inline CAXA::Int16 osmode() const;

    // PICKSTYLE
    CDraft::ErrorStatus setPickstyle(CAXA::Int16 value, bool bUndo = false);
    inline CAXA::Int16 pickstyle() const;

    // LWDEFAULT 
    CDraft::ErrorStatus setLwdefault(CRxDb::LineWeight value, bool bUndo = false);
    inline CRxDb::LineWeight lwdefault() const;

    // HPASSOC
    CDraft::ErrorStatus setHpassoc(bool value, bool bUndo = false);
    inline bool hpassoc() const;

private:
    bool  m_attdia;                 // ATTDIA
    bool  m_attreq;                 // ATTREQ
    bool  m_blipmode;               // BLIPMODE
    short m_delobj;                 // DELOBJS
    short m_coords;                 // COORDS
    short m_statusbar;              // STATUSBAR
    bool  m_menubar;                // MENUBAR
    bool  m_appstatusbaruseicons;   // APPSTATUSBARUSEICONS
    short m_dragmode;               // DRAGMODE
    short m_osmode;                 // OSMODE
    short m_pkstyle;                // PICKSTYLE
    CRxDb::LineWeight  m_lwdefault;  // LWDEFAULT
    bool  m_hpassoc;                // HPASSOC
};

inline 
CRxDbAppSystemVariables::CRxDbAppSystemVariables()
: m_attdia(false),
  m_attreq(true),
  m_blipmode(false),
  m_delobj(-1),
  m_coords(0),
  m_statusbar(1),
  m_menubar(false),
  m_appstatusbaruseicons(true),
  m_dragmode(2),
  m_osmode(0),
  m_pkstyle(kGroupsOn),
  m_lwdefault(CRxDb::kLnWt025),
  m_hpassoc(1)
{
}

// ATTDIA
inline bool CRxDbAppSystemVariables::attdia() const
{
    return m_attdia;
}

// ATTREQ
inline bool CRxDbAppSystemVariables::attreq() const
{
    return m_attreq;
}

// BLIPMODE
inline bool CRxDbAppSystemVariables::blipmode() const
{
    return m_blipmode;
}

// COORDS
inline CAXA::Int16 CRxDbAppSystemVariables::coords() const
{
    return m_coords;
}

// STATUSBAR
inline CAXA::Int16 CRxDbAppSystemVariables::statusbar() const
{
    return m_statusbar;
}

// MENUBAR
inline bool CRxDbAppSystemVariables::menubar() const
{
    return m_menubar;
}

// APPSTATUSBARUSEICONS
inline bool CRxDbAppSystemVariables::appstatusbaruseicons() const
{
    return m_appstatusbaruseicons;
}

// DELOBJS
inline CAXA::Int16 CRxDbAppSystemVariables::delUsedObj() const
{
    return m_delobj;
}

// DRAGMODE
inline CAXA::Int16 CRxDbAppSystemVariables::dragmode() const
{
    return m_dragmode;
}

// PICKSTYLE
inline CAXA::Int16 CRxDbAppSystemVariables::pickstyle() const
{
    return m_pkstyle;
}

// LWDEFAULT
inline CRxDb::LineWeight CRxDbAppSystemVariables::lwdefault() const
{
    return m_lwdefault;
}

// HPASSOC
inline bool CRxDbAppSystemVariables::hpassoc() const
{
    return m_hpassoc;
}

#pragma pack (pop)
#endif // ACAPPSVAR_H
