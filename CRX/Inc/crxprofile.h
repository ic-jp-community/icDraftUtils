//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

#ifndef   _CRXPROFILE_H__
#define   _CRXPROFILE_H__

#include "crxArray.h"
#include "crxChar.h"
#include "CrxEdApiCx.h"

#pragma pack (push, 8)

class CRxApProfileStorage;

class CRXEDAPI_CLASS CRxApProfileManagerReactor 
{
public:
    virtual void currentProfileWillChange(const CxCHAR *newProfile);
    virtual void currentProfileChanged(const CxCHAR *newProfile);
    virtual void currentProfileWillBeReset(const CxCHAR *currentProfile);
    virtual void currentProfileReset(const CxCHAR *currentProfile);
    virtual void currentProfileWillBeSaved(const CxCHAR *currentProfile);
    virtual void currentProfileSaved(const CxCHAR *currentProfile);
    virtual void profileWillReset(const CxCHAR *profileName);
    virtual void profileReset(const CxCHAR *profileName);
    virtual void profileWillBeSaved(const CxCHAR *profileName);
    virtual void profileSaved(const CxCHAR *profileName);
    virtual ~CRxApProfileManagerReactor() {}
};

typedef CRxArray<CxCHAR *> CRxApProfileNameArray;

class CRxApProfileManager 
{
    public:

        virtual void ProfileRegistryKey(CxCHAR *& strRegProfileKey,
                                        const CxCHAR * strProfileName)=0;

        virtual CDraft::ErrorStatus ProfileStorage(CRxApProfileStorage*& pStore,
                                        const CxCHAR * strProfileName, 
                                        BOOL bCreateIfNotExists = TRUE)=0;
        virtual CDraft::ErrorStatus FixedProfileStorage(CRxApProfileStorage*& pStore, 
                                        BOOL bCreateIfNotExists = TRUE)=0;

        virtual int ProfileListNames(CRxApProfileNameArray& nameList)=0;

        virtual CDraft::ErrorStatus ProfileExport(const CxCHAR * strProfileName,
                                                const CxCHAR * exportFileName)=0;

        virtual CDraft::ErrorStatus ProfileImport(const CxCHAR * strProfileName,
                                                const CxCHAR * importFileName,
                                                const CxCHAR * profileDescription,
                                                CAXA::Boolean bImportPathInfo)=0; 

        virtual CDraft::ErrorStatus ProfileDelete(const CxCHAR * strProfileName)=0;

        virtual CDraft::ErrorStatus ProfileReset(const CxCHAR * strProfileName)=0;

        virtual CDraft::ErrorStatus ProfileSetCurrent(const CxCHAR * strProfileName)=0;

        virtual CDraft::ErrorStatus ProfileCopy(const CxCHAR * newProfileName,
                                              const CxCHAR * oldProfileName,
                                              const CxCHAR * newProfileDesc)=0;

        virtual CDraft::ErrorStatus ProfileRename(const CxCHAR * newProfileName,
                                                const CxCHAR * oldProfileName,
                                                const CxCHAR * newProfileDesc)=0;

        virtual void addReactor(CRxApProfileManagerReactor* ) = 0;
        virtual void removeReactor(CRxApProfileManagerReactor* ) = 0;

};

CRXEDAPI_API CRxApProfileManager* crxProfileManagerPtr();
#define crxProfileManager crxProfileManagerPtr()

class CRxApProfileStorage
{
    public:
        virtual ~CRxApProfileStorage() {}
        virtual CDraft::ErrorStatus CreateNode(const CxCHAR * pszNodePath, 
            IUnknown*& pUnknown) = 0;
        virtual CDraft::ErrorStatus GetNode(const CxCHAR * pszNodePath, 
            IUnknown*& pUnknown) = 0;
        virtual CDraft::ErrorStatus ReplaceNode(const CxCHAR * pszNodePath, 
            IUnknown* pUnknown) = 0;
        virtual CDraft::ErrorStatus DeleteNode(const CxCHAR * pszNodePath) = 0;
        virtual CDraft::ErrorStatus GetStorageFile(LPTSTR pszFile) = 0;
        virtual CDraft::ErrorStatus Save(void) = 0;
};


#pragma pack (pop)
#endif // _CRXPROFILE_H__
