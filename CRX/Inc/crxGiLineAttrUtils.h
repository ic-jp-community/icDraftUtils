//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//
// ********************************************************************************
// MODULE:      CrxGiLineAttrUtils.h
// PURPOSE:     Utility functions to convert between different
//                line attributes tables
// HISTORY:     03/17/2002
// ********************************************************************************

#pragma once

#include "crxDb.h"

class CRxGiLineAttrUtils
{
public:
    // Unicode: leave as char for now
    static char __stdcall crxgiLineWeightToIndex(CRxDb::LineWeight lw);
    static CRxDb::LineWeight __stdcall crxgiIndexToLineWeight(char index);
};
