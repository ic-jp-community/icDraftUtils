#ifndef _ACGIUTIL_H
#define _ACGIUTIL_H 1
//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//	End-users must also comply with the terms and conditions 
//	in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//	版权所有（C）北京数码大方科技股份有限公司
//	最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
// 

#include "dbid.h"
#include "crxgi.h"

#pragma pack (push, 8)

CDraft::ErrorStatus fromAcDbTextStyle(CRxGiTextStyle&,
                              const CRxDbObjectId& AcDbStyleId);
CDraft::ErrorStatus fromAcDbTextStyle(CRxGiTextStyle&, const CxCHAR * AcDbStyleName);

// This version of toAcDbTextStyle will use the styleName of the
// CRxGiTextStyle as the name of the AcDbTextStyle to write to.  If
// the CRxGiTextStyle's styleName == NULL, then a random name will
// be generated and used for the AcDbTextStyle and the CRxGiTextStyle's
// styleName will be set to the random name as well.
CDraft::ErrorStatus toAcDbTextStyle(CRxGiTextStyle&);

// This version of toAcDbTextStyle will use the styleName of the
// CRxGiTextStyle as the name of the AcDbTextStyle to write to.  If
// the CRxGiTextStyle's styleName == NULL, then a random name will
// be generated and used for the AcDbTextStyle and the CRxGiTextStyle's
// styleName will be set to the random name as well.
//
// AcDbStyleId is set to the objectId of the AcDbTextStyleTableRecord
// object that maps to the CRxGiTextStyle's name.
//
CDraft::ErrorStatus toAcDbTextStyle(CRxGiTextStyle&,
                                  CRxDbObjectId& AcDbStyleId);

// Agruments reversed to avoid ambiguious function overloading. In
// this version,  the CRxDbObjectId is the Id of the AcDbTextStyleTableRecord
// to write.
//
CDraft::ErrorStatus toAcDbTextStyle(const CRxDbObjectId AcDbStyleId,
                                  CRxGiTextStyle&);

CDraft::ErrorStatus toAcDbTextStyle(CRxGiTextStyle&, const CxCHAR * AcDbStyleName);

// AcDbStyleId is set to the objectId of the AcDbTextStyleTableRecord
// object that maps to the CRxGiTextStyle's name.
//
CDraft::ErrorStatus toAcDbTextStyle(CRxGiTextStyle&, const CxCHAR * AcDbStyleName,
                                  CRxDbObjectId& AcDbStyleId);


#pragma pack (pop)

#endif // ACGIUTIL_H
