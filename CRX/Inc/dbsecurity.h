#ifndef __CRXDBSECURITY_H_
#define __CRXDBSECURITY_H_

//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//


class CRxDbDate;


//enum
//{
//    SECURITYPARAMS_ENCRYPT_DATA     = 0x00000001,
//    SECURITYPARAMS_ENCRYPT_PROPS    = 0x00000002,
//
//    SECURITYPARAMS_SIGN_DATA        = 0x00000010,
//    SECURITYPARAMS_ADD_TIMESTAMP    = 0x00000020
//};
//
//
//enum
//{
//    SECURITYPARAMS_ALGID_RC4        = 0x00006801
//};


struct SecurityParams
{
    unsigned long   cbSize;
    unsigned long   ulFlags;      


    wchar_t*        wszPassword;
    unsigned long   ulProvType;
    wchar_t*        wszProvName;
    unsigned long   ulAlgId;       
    unsigned long   ulKeyLength;


    wchar_t*        wszCertSubject;
    wchar_t*        wszCertIssuer;
    wchar_t*        wszCertSerialNum;
    wchar_t*        wszComment;
    wchar_t*        wszTimeServer;
};


//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// The following struct is for internal use only.                           //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

struct SignatureInfo
{
    unsigned long   cbSize;

    unsigned long   ulFlags;
    wchar_t*        wszCertSubject;
    wchar_t*        wszCertIssuer;
    wchar_t*        wszSubjectEMail;
    wchar_t*        wszCertSerialNum;
    wchar_t*        wszX500;
    CRxDbDate*       pTimeCertNotBefore;
    CRxDbDate*       pTimeCertNotAfter;
    wchar_t*        wszComment;
    wchar_t*        wszTimeServer;
    CRxDbDate*       pTimestamp;
};


#endif  // __DBSECURITY_H_
