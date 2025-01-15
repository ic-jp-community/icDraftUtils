//��C��Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ��Ȩ���У�C����������󷽿Ƽ��ɷ����޹�˾
//  �����û�ʹ�ñ�����������ء�CAXA�����û����ʹ��Э�顷
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
