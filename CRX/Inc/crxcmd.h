#ifndef   _CRXCMD_H
#define   _CRXCMD_H
//
//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//

#include "crxChar.h"
#include "CrxEdApiCx.h"

#define CRX_CMD_MODAL              0x00000000
#define CRX_CMD_TRANSPARENT        0x00000001
#define CRX_CMD_USEPICKSET         0x00000002
#define CRX_CMD_REDRAW	           0x00000004
#define CRX_CMD_NOPERSPECTIVE      0x00000008  
#define CRX_CMD_NOMULTIPLE         0x00000010
#define CRX_CMD_NOTILEMODE         0x00000020 
#define CRX_CMD_NOPAPERSPACE       0x00000040 
#define CRX_CMD_PLOTONLY           0x00000080 
#define CRX_CMD_NOOEM              0x00000100
#define CRX_CMD_UNDEFINED          0x00000200
#define CRX_CMD_INPROGRESS         0x00000400
#define CRX_CMD_DEFUN              0x00000800
#define CRX_CMD_LISPASCMD          0x00001000 
#define CRX_CMD_NONEWSTACK         0x00010000 
#define CRX_CMD_NOINTERNALLOCK     0x00020000
#define CRX_CMD_DOCREADLOCK        0x00080000 
#define CRX_CMD_DOCEXCLUSIVELOCK   0x00100000 
#define CRX_CMD_SESSION            0x00200000                                              
#define CRX_CMD_INTERRUPTIBLE      0x00400000                                              
#define CRX_CMD_NOHISTORY          0x00800000 
#define CRX_CMD_NO_UNDO_MARKER     0x01000000
#define CRX_CMD_NOBEDIT            0x02000000 
#define CRX_CMD_NOACTIONRECORDING  0x04000000 
#define CRX_CMD_ACTIONMACRO        0x08000000 
#define CRX_CMD_RELAXASSOC         0x10000000 
#define CRX_CMD_NOBEIDTINPLACE     0x20000000 
#define CRX_CMD_NOVIEWBEIDT        0x40000000 
#define CRX_CMD_NOVIEWBEIDTINPLACE 0x80000000 


#define CRX_MAX_CMDNAME_LEN  	64

#define CRX_COMMAND_DOCK  	CRX_T("CRX_REGISTERED_COMMANDS")

typedef void (*CRxFunctionPtr) ();

#include <wtypes.h>      
#pragma pack (push, 8)
class CRxEdCommand;

struct CRxEdCommandStruc {
    CRxFunctionPtr fcnAddr;
    long            flags;
    void	        *app;
    HINSTANCE       hResHandle;
	CRxEdCommand	*cmd;
};
#pragma pack (pop)

#if defined(__cplusplus)

#include "dbmain.h"
#include "rxobject.h"

class CRxDictionary;
class CRxEdUIContext;

#pragma pack (push, 8)
CRX_DEFINE_NULL_CLSID(CRxEdCommand)
class CRXEDAPI_CLASS CRxEdCommand: public CRxObject 
{ 
public:
    CRX_DECLARE_DYNAMIC(CRxEdCommand);

    virtual void            commandUndef(bool undefIt) = 0;
    virtual CAXA::Int32    commandFlags() const = 0;
    virtual CRxFunctionPtr functionAddr() const = 0;
    virtual void            functionAddr(CRxFunctionPtr fhdl) = 0;
    virtual void            *commandApp() const = 0;
    virtual CRxEdUIContext   *UIContext() const = 0;
    virtual int             functionCode() const = 0;
    virtual void            functionCode(int fcode) = 0;

    virtual const CxCHAR *   globalName() const = 0;
    virtual const CxCHAR *   localName() const = 0;

    virtual const HINSTANCE resourceHandle() const = 0;

};
CRX_DEFINE_NULL_CLSID(CRxEdCommandIterator)
class CRXEDAPI_CLASS CRxEdCommandIterator: public CRxObject 
{ 
public:
    CRX_DECLARE_DYNAMIC(CRxEdCommandIterator);

    virtual bool               done() const = 0;
    virtual bool               next() = 0;
    virtual const CRxEdCommand* command() const = 0;
    virtual const CxCHAR *      commandGroup() const = 0;
};

#define crxedRegCmds \
CRxEdCommandStack::cast(crxSysRegistry()->at(CRX_COMMAND_DOCK))

CRX_DEFINE_NULL_CLSID(CRxEdCommandStack)
class CRXEDAPI_CLASS CRxEdCommandStack: public CRxObject 
{ 
public:
    CRX_DECLARE_DYNAMIC(CRxEdCommandStack);

    virtual bool              atPut(const CxCHAR * cmdGroupName,
                                    CRxDictionary*& cmdsGlobal,
                                    CRxDictionary*& cmdsLocal) = 0;

    virtual CDraft::ErrorStatus addCommand(const CxCHAR * cmdGroupName,
                                         const CxCHAR * cmdGlobalName,
                                         const CxCHAR * cmdLocalName,
                                         CAXA::Int32 commandFlags,
                                         CRxFunctionPtr FunctionAddr,
                                         CRxEdUIContext *UIContext=NULL,
                                         int fcode=-1,
                                         HINSTANCE hResourceHandle=NULL,
                                         CRxEdCommand** cmdPtrRet=NULL) = 0;

    virtual CRxEdCommandIterator* iterator() = 0;

    virtual CRxEdCommand* lookupGlobalCmd(const CxCHAR * cmdName) = 0;
    virtual CRxEdCommand* lookupLocalCmd(const CxCHAR * cmdName) = 0;
    virtual CRxEdCommand* lookupCmd(const CxCHAR * cmdName,
                                   bool globalFlag) = 0;
    virtual CRxEdCommand* lookupCmd(const CxCHAR * cmdName,
                                   bool globalFlag,
                                   bool allGroupsFlag) = 0;
    virtual CRxEdCommand* lookupCmd(const CxCHAR * cmdName,
                                   bool globalFlag,
                                   bool allGroupsFlag,
                                   bool skipUndefed) = 0;
    virtual CRxEdCommand* lookupCmd2(const CxCHAR * cmdName,
                                   bool globalFlag,
                                   bool allGroupsFlag,
                                   int skipFlags,
                                   bool match = false) = 0;

    virtual CDraft::ErrorStatus popGroupToTop(const CxCHAR * cmdGroupName) = 0;

    virtual CDraft::ErrorStatus removeCmd(const CxCHAR * cmdGroupName,
                                        const CxCHAR * cmdGlobalName) = 0;

    virtual CDraft::ErrorStatus removeGroup(const CxCHAR * groupName) = 0;

};

#pragma pack (pop)
#endif // cplusplus
#endif
