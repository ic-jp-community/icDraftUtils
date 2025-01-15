//
//（C）Copyright 2009 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//


/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Tue Nov 17 20:14:29 2009
 */
/* Compiler settings for .\ICxMath.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ICxMath_h__
#define __ICxMath_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICxFiler_FWD_DEFINED__
#define __ICxFiler_FWD_DEFINED__
typedef interface ICxFiler ICxFiler;
#endif 	/* __ICxFiler_FWD_DEFINED__ */


#ifndef __IXYZ_FWD_DEFINED__
#define __IXYZ_FWD_DEFINED__
typedef interface IXYZ IXYZ;
#endif 	/* __IXYZ_FWD_DEFINED__ */


#ifndef __IVector_FWD_DEFINED__
#define __IVector_FWD_DEFINED__
typedef interface IVector IVector;
#endif 	/* __IVector_FWD_DEFINED__ */


#ifndef __ILine_FWD_DEFINED__
#define __ILine_FWD_DEFINED__
typedef interface ILine ILine;
#endif 	/* __ILine_FWD_DEFINED__ */


#ifndef __IPlane_FWD_DEFINED__
#define __IPlane_FWD_DEFINED__
typedef interface IPlane IPlane;
#endif 	/* __IPlane_FWD_DEFINED__ */


#ifndef __IMatrix_FWD_DEFINED__
#define __IMatrix_FWD_DEFINED__
typedef interface IMatrix IMatrix;
#endif 	/* __IMatrix_FWD_DEFINED__ */


#ifndef __IBox_FWD_DEFINED__
#define __IBox_FWD_DEFINED__
typedef interface IBox IBox;
#endif 	/* __IBox_FWD_DEFINED__ */


#ifndef __IXYZW_FWD_DEFINED__
#define __IXYZW_FWD_DEFINED__
typedef interface IXYZW IXYZW;
#endif 	/* __IXYZW_FWD_DEFINED__ */


#ifndef __ICoord_FWD_DEFINED__
#define __ICoord_FWD_DEFINED__
typedef interface ICoord ICoord;
#endif 	/* __ICoord_FWD_DEFINED__ */


#ifndef __ICoordColl_FWD_DEFINED__
#define __ICoordColl_FWD_DEFINED__
typedef interface ICoordColl ICoordColl;
#endif 	/* __ICoordColl_FWD_DEFINED__ */


#ifndef __IExpressions_FWD_DEFINED__
#define __IExpressions_FWD_DEFINED__
typedef interface IExpressions IExpressions;
#endif 	/* __IExpressions_FWD_DEFINED__ */


#ifndef __IXYZTs_FWD_DEFINED__
#define __IXYZTs_FWD_DEFINED__
typedef interface IXYZTs IXYZTs;
#endif 	/* __IXYZTs_FWD_DEFINED__ */


#ifndef __IXYZTsArray_FWD_DEFINED__
#define __IXYZTsArray_FWD_DEFINED__
typedef interface IXYZTsArray IXYZTsArray;
#endif 	/* __IXYZTsArray_FWD_DEFINED__ */


#ifndef __IXYZArray_FWD_DEFINED__
#define __IXYZArray_FWD_DEFINED__
typedef interface IXYZArray IXYZArray;
#endif 	/* __IXYZArray_FWD_DEFINED__ */


#ifndef __IXYZWArray_FWD_DEFINED__
#define __IXYZWArray_FWD_DEFINED__
typedef interface IXYZWArray IXYZWArray;
#endif 	/* __IXYZWArray_FWD_DEFINED__ */


#ifndef __IVectorArray_FWD_DEFINED__
#define __IVectorArray_FWD_DEFINED__
typedef interface IVectorArray IVectorArray;
#endif 	/* __IVectorArray_FWD_DEFINED__ */


#ifndef __IMathTool_FWD_DEFINED__
#define __IMathTool_FWD_DEFINED__
typedef interface IMathTool IMathTool;
#endif 	/* __IMathTool_FWD_DEFINED__ */


#ifndef __ITolerance_FWD_DEFINED__
#define __ITolerance_FWD_DEFINED__
typedef interface ITolerance ITolerance;
#endif 	/* __ITolerance_FWD_DEFINED__ */


#ifndef __ICxIXYZColl_FWD_DEFINED__
#define __ICxIXYZColl_FWD_DEFINED__
typedef interface ICxIXYZColl ICxIXYZColl;
#endif 	/* __ICxIXYZColl_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_ICxMath_0000 */
/* [local] */ 


















extern RPC_IF_HANDLE __MIDL_itf_ICxMath_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ICxMath_0000_v0_0_s_ifspec;

#ifndef __ICxFiler_INTERFACE_DEFINED__
#define __ICxFiler_INTERFACE_DEFINED__

/* interface ICxFiler */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICxFiler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2F6DD8D0-4A88-4639-9408-24F7FF44BC3F")
    ICxFiler : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveDouble( 
            /* [in] */ DOUBLE i_dVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveLong( 
            /* [in] */ LONG i_lVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveInt( 
            /* [in] */ INT i_iVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveBuffer( 
            /* [in] */ LONG_PTR i_pBuffer,
            /* [in] */ ULONG i_ulNum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadDouble( 
            /* [retval][out] */ DOUBLE *o_pdVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadLong( 
            /* [retval][out] */ LONG *o_plVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadInt( 
            /* [retval][out] */ INT *o_piVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadBuffer( 
            /* [out] */ LONG_PTR *o_pBuffer,
            /* [in] */ ULONG i_ulNum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Attach( 
            /* [in] */ LONG_PTR i_pUnkown) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Detach( 
            /* [retval][out] */ LONG_PTR *o_ppUnkown) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveString( 
            /* [in] */ BSTR i_bsString) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadString( 
            /* [retval][out] */ BSTR *o_pbsString) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveSIZE_T( 
            /* [in] */ SIZE_T i_sztVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadSIZE_T( 
            /* [retval][out] */ SIZE_T *o_psztVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICxFilerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICxFiler * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICxFiler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICxFiler * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICxFiler * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICxFiler * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICxFiler * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICxFiler * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveDouble )( 
            ICxFiler * This,
            /* [in] */ DOUBLE i_dVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveLong )( 
            ICxFiler * This,
            /* [in] */ LONG i_lVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveInt )( 
            ICxFiler * This,
            /* [in] */ INT i_iVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveBuffer )( 
            ICxFiler * This,
            /* [in] */ LONG_PTR i_pBuffer,
            /* [in] */ ULONG i_ulNum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadDouble )( 
            ICxFiler * This,
            /* [retval][out] */ DOUBLE *o_pdVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadLong )( 
            ICxFiler * This,
            /* [retval][out] */ LONG *o_plVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadInt )( 
            ICxFiler * This,
            /* [retval][out] */ INT *o_piVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadBuffer )( 
            ICxFiler * This,
            /* [out] */ LONG_PTR *o_pBuffer,
            /* [in] */ ULONG i_ulNum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Attach )( 
            ICxFiler * This,
            /* [in] */ LONG_PTR i_pUnkown);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Detach )( 
            ICxFiler * This,
            /* [retval][out] */ LONG_PTR *o_ppUnkown);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveString )( 
            ICxFiler * This,
            /* [in] */ BSTR i_bsString);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadString )( 
            ICxFiler * This,
            /* [retval][out] */ BSTR *o_pbsString);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveSIZE_T )( 
            ICxFiler * This,
            /* [in] */ SIZE_T i_sztVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadSIZE_T )( 
            ICxFiler * This,
            /* [retval][out] */ SIZE_T *o_psztVal);
        
        END_INTERFACE
    } ICxFilerVtbl;

    interface ICxFiler
    {
        CONST_VTBL struct ICxFilerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICxFiler_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICxFiler_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICxFiler_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICxFiler_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICxFiler_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICxFiler_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICxFiler_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICxFiler_SaveDouble(This,i_dVal)	\
    (This)->lpVtbl -> SaveDouble(This,i_dVal)

#define ICxFiler_SaveLong(This,i_lVal)	\
    (This)->lpVtbl -> SaveLong(This,i_lVal)

#define ICxFiler_SaveInt(This,i_iVal)	\
    (This)->lpVtbl -> SaveInt(This,i_iVal)

#define ICxFiler_SaveBuffer(This,i_pBuffer,i_ulNum)	\
    (This)->lpVtbl -> SaveBuffer(This,i_pBuffer,i_ulNum)

#define ICxFiler_LoadDouble(This,o_pdVal)	\
    (This)->lpVtbl -> LoadDouble(This,o_pdVal)

#define ICxFiler_LoadLong(This,o_plVal)	\
    (This)->lpVtbl -> LoadLong(This,o_plVal)

#define ICxFiler_LoadInt(This,o_piVal)	\
    (This)->lpVtbl -> LoadInt(This,o_piVal)

#define ICxFiler_LoadBuffer(This,o_pBuffer,i_ulNum)	\
    (This)->lpVtbl -> LoadBuffer(This,o_pBuffer,i_ulNum)

#define ICxFiler_Attach(This,i_pUnkown)	\
    (This)->lpVtbl -> Attach(This,i_pUnkown)

#define ICxFiler_Detach(This,o_ppUnkown)	\
    (This)->lpVtbl -> Detach(This,o_ppUnkown)

#define ICxFiler_SaveString(This,i_bsString)	\
    (This)->lpVtbl -> SaveString(This,i_bsString)

#define ICxFiler_LoadString(This,o_pbsString)	\
    (This)->lpVtbl -> LoadString(This,o_pbsString)

#define ICxFiler_SaveSIZE_T(This,i_sztVal)	\
    (This)->lpVtbl -> SaveSIZE_T(This,i_sztVal)

#define ICxFiler_LoadSIZE_T(This,o_psztVal)	\
    (This)->lpVtbl -> LoadSIZE_T(This,o_psztVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxFiler_SaveDouble_Proxy( 
    ICxFiler * This,
    /* [in] */ DOUBLE i_dVal);


void __RPC_STUB ICxFiler_SaveDouble_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxFiler_SaveLong_Proxy( 
    ICxFiler * This,
    /* [in] */ LONG i_lVal);


void __RPC_STUB ICxFiler_SaveLong_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxFiler_SaveInt_Proxy( 
    ICxFiler * This,
    /* [in] */ INT i_iVal);


void __RPC_STUB ICxFiler_SaveInt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxFiler_SaveBuffer_Proxy( 
    ICxFiler * This,
    /* [in] */ LONG_PTR i_pBuffer,
    /* [in] */ ULONG i_ulNum);


void __RPC_STUB ICxFiler_SaveBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxFiler_LoadDouble_Proxy( 
    ICxFiler * This,
    /* [retval][out] */ DOUBLE *o_pdVal);


void __RPC_STUB ICxFiler_LoadDouble_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxFiler_LoadLong_Proxy( 
    ICxFiler * This,
    /* [retval][out] */ LONG *o_plVal);


void __RPC_STUB ICxFiler_LoadLong_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxFiler_LoadInt_Proxy( 
    ICxFiler * This,
    /* [retval][out] */ INT *o_piVal);


void __RPC_STUB ICxFiler_LoadInt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxFiler_LoadBuffer_Proxy( 
    ICxFiler * This,
    /* [out] */ LONG_PTR *o_pBuffer,
    /* [in] */ ULONG i_ulNum);


void __RPC_STUB ICxFiler_LoadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxFiler_Attach_Proxy( 
    ICxFiler * This,
    /* [in] */ LONG_PTR i_pUnkown);


void __RPC_STUB ICxFiler_Attach_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxFiler_Detach_Proxy( 
    ICxFiler * This,
    /* [retval][out] */ LONG_PTR *o_ppUnkown);


void __RPC_STUB ICxFiler_Detach_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxFiler_SaveString_Proxy( 
    ICxFiler * This,
    /* [in] */ BSTR i_bsString);


void __RPC_STUB ICxFiler_SaveString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxFiler_LoadString_Proxy( 
    ICxFiler * This,
    /* [retval][out] */ BSTR *o_pbsString);


void __RPC_STUB ICxFiler_LoadString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxFiler_SaveSIZE_T_Proxy( 
    ICxFiler * This,
    /* [in] */ SIZE_T i_sztVal);


void __RPC_STUB ICxFiler_SaveSIZE_T_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxFiler_LoadSIZE_T_Proxy( 
    ICxFiler * This,
    /* [retval][out] */ SIZE_T *o_psztVal);


void __RPC_STUB ICxFiler_LoadSIZE_T_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICxFiler_INTERFACE_DEFINED__ */


#ifndef __IXYZ_INTERFACE_DEFINED__
#define __IXYZ_INTERFACE_DEFINED__

/* interface IXYZ */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IXYZ;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("02598F3C-9D11-47B2-8091-025FD60C77E2")
    IXYZ : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCXYZ( 
            /* [retval][out] */ LONG_PTR *o_pplCXYZAddress) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutIVect( 
            /* [in] */ IVector *i_pVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutIXYZ( 
            /* [in] */ IXYZ *i_pPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetXYZ( 
            /* [out] */ DOUBLE *o_pdX,
            /* [out] */ DOUBLE *o_pdY,
            /* [out] */ DOUBLE *o_pdZ) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutXYZ( 
            /* [in] */ DOUBLE i_dX,
            /* [in] */ DOUBLE i_dY,
            /* [in] */ DOUBLE i_dZ) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsLegal( 
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Init( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Trans( 
            /* [in] */ IMatrix *i_pMat) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Rotate( 
            /* [in] */ DOUBLE i_dRotAng,
            /* [in] */ IVector *i_pVec,
            /* [in] */ IXYZ *i_pDtmPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Scale( 
            /* [in] */ DOUBLE i_dScale,
            /* [in] */ IXYZ *i_pDtmPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDistToPt( 
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ DOUBLE *o_pdDist) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDistToPts( 
            /* [in] */ IXYZArray *i_pPts,
            /* [in] */ LONG i_iNum,
            /* [out] */ DOUBLE *o_pdDist,
            /* [out] */ int *o_iIdx) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetProjPt( 
            /* [in] */ IPlane *i_pProjPln,
            /* [out] */ IXYZ **o_ppPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IfTriPtsColn( 
            /* [in] */ IXYZ *i_pP0,
            /* [in] */ IXYZ *i_pP1,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetIVec( 
            /* [out] */ IVector **o_ppVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsSame( 
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMirrorPt( 
            /* [in] */ IPlane *i_pMirrorPln,
            /* [retval][out] */ IXYZ **o_ppPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TransToMatPln( 
            /* [in] */ IMatrix *i_pPlnMat,
            /* [retval][out] */ IXYZ **o_ppPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TransToWcPln( 
            /* [in] */ IMatrix *i_pPlnMat,
            /* [retval][out] */ IXYZ **o_ppPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TransToMatPlnXYZ( 
            /* [in] */ IMatrix *i_pPlnMat,
            /* [out] */ double *o_dx,
            /* [out] */ double *o_dy,
            /* [out] */ double *o_dz) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ ICxFiler *i_ipFiler) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ ICxFiler *i_ipFiler) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IXYZVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXYZ * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXYZ * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXYZ * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IXYZ * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IXYZ * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IXYZ * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IXYZ * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCXYZ )( 
            IXYZ * This,
            /* [retval][out] */ LONG_PTR *o_pplCXYZAddress);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutIVect )( 
            IXYZ * This,
            /* [in] */ IVector *i_pVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutIXYZ )( 
            IXYZ * This,
            /* [in] */ IXYZ *i_pPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXYZ )( 
            IXYZ * This,
            /* [out] */ DOUBLE *o_pdX,
            /* [out] */ DOUBLE *o_pdY,
            /* [out] */ DOUBLE *o_pdZ);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutXYZ )( 
            IXYZ * This,
            /* [in] */ DOUBLE i_dX,
            /* [in] */ DOUBLE i_dY,
            /* [in] */ DOUBLE i_dZ);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsLegal )( 
            IXYZ * This,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Init )( 
            IXYZ * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Trans )( 
            IXYZ * This,
            /* [in] */ IMatrix *i_pMat);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            IXYZ * This,
            /* [in] */ DOUBLE i_dRotAng,
            /* [in] */ IVector *i_pVec,
            /* [in] */ IXYZ *i_pDtmPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Scale )( 
            IXYZ * This,
            /* [in] */ DOUBLE i_dScale,
            /* [in] */ IXYZ *i_pDtmPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDistToPt )( 
            IXYZ * This,
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ DOUBLE *o_pdDist);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDistToPts )( 
            IXYZ * This,
            /* [in] */ IXYZArray *i_pPts,
            /* [in] */ LONG i_iNum,
            /* [out] */ DOUBLE *o_pdDist,
            /* [out] */ int *o_iIdx);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetProjPt )( 
            IXYZ * This,
            /* [in] */ IPlane *i_pProjPln,
            /* [out] */ IXYZ **o_ppPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IfTriPtsColn )( 
            IXYZ * This,
            /* [in] */ IXYZ *i_pP0,
            /* [in] */ IXYZ *i_pP1,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetIVec )( 
            IXYZ * This,
            /* [out] */ IVector **o_ppVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsSame )( 
            IXYZ * This,
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMirrorPt )( 
            IXYZ * This,
            /* [in] */ IPlane *i_pMirrorPln,
            /* [retval][out] */ IXYZ **o_ppPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransToMatPln )( 
            IXYZ * This,
            /* [in] */ IMatrix *i_pPlnMat,
            /* [retval][out] */ IXYZ **o_ppPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransToWcPln )( 
            IXYZ * This,
            /* [in] */ IMatrix *i_pPlnMat,
            /* [retval][out] */ IXYZ **o_ppPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransToMatPlnXYZ )( 
            IXYZ * This,
            /* [in] */ IMatrix *i_pPlnMat,
            /* [out] */ double *o_dx,
            /* [out] */ double *o_dy,
            /* [out] */ double *o_dz);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IXYZ * This,
            /* [in] */ ICxFiler *i_ipFiler);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IXYZ * This,
            /* [in] */ ICxFiler *i_ipFiler);
        
        END_INTERFACE
    } IXYZVtbl;

    interface IXYZ
    {
        CONST_VTBL struct IXYZVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXYZ_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IXYZ_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IXYZ_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IXYZ_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IXYZ_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IXYZ_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IXYZ_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IXYZ_GetCXYZ(This,o_pplCXYZAddress)	\
    (This)->lpVtbl -> GetCXYZ(This,o_pplCXYZAddress)

#define IXYZ_PutIVect(This,i_pVec)	\
    (This)->lpVtbl -> PutIVect(This,i_pVec)

#define IXYZ_PutIXYZ(This,i_pPt)	\
    (This)->lpVtbl -> PutIXYZ(This,i_pPt)

#define IXYZ_GetXYZ(This,o_pdX,o_pdY,o_pdZ)	\
    (This)->lpVtbl -> GetXYZ(This,o_pdX,o_pdY,o_pdZ)

#define IXYZ_PutXYZ(This,i_dX,i_dY,i_dZ)	\
    (This)->lpVtbl -> PutXYZ(This,i_dX,i_dY,i_dZ)

#define IXYZ_IsLegal(This,o_pbVal)	\
    (This)->lpVtbl -> IsLegal(This,o_pbVal)

#define IXYZ_Init(This)	\
    (This)->lpVtbl -> Init(This)

#define IXYZ_Trans(This,i_pMat)	\
    (This)->lpVtbl -> Trans(This,i_pMat)

#define IXYZ_Rotate(This,i_dRotAng,i_pVec,i_pDtmPt)	\
    (This)->lpVtbl -> Rotate(This,i_dRotAng,i_pVec,i_pDtmPt)

#define IXYZ_Scale(This,i_dScale,i_pDtmPt)	\
    (This)->lpVtbl -> Scale(This,i_dScale,i_pDtmPt)

#define IXYZ_GetDistToPt(This,i_pPt,o_pdDist)	\
    (This)->lpVtbl -> GetDistToPt(This,i_pPt,o_pdDist)

#define IXYZ_GetDistToPts(This,i_pPts,i_iNum,o_pdDist,o_iIdx)	\
    (This)->lpVtbl -> GetDistToPts(This,i_pPts,i_iNum,o_pdDist,o_iIdx)

#define IXYZ_GetProjPt(This,i_pProjPln,o_ppPt)	\
    (This)->lpVtbl -> GetProjPt(This,i_pProjPln,o_ppPt)

#define IXYZ_IfTriPtsColn(This,i_pP0,i_pP1,o_pbVal)	\
    (This)->lpVtbl -> IfTriPtsColn(This,i_pP0,i_pP1,o_pbVal)

#define IXYZ_GetIVec(This,o_ppVec)	\
    (This)->lpVtbl -> GetIVec(This,o_ppVec)

#define IXYZ_IsSame(This,i_pPt,o_pbVal)	\
    (This)->lpVtbl -> IsSame(This,i_pPt,o_pbVal)

#define IXYZ_GetMirrorPt(This,i_pMirrorPln,o_ppPt)	\
    (This)->lpVtbl -> GetMirrorPt(This,i_pMirrorPln,o_ppPt)

#define IXYZ_TransToMatPln(This,i_pPlnMat,o_ppPt)	\
    (This)->lpVtbl -> TransToMatPln(This,i_pPlnMat,o_ppPt)

#define IXYZ_TransToWcPln(This,i_pPlnMat,o_ppPt)	\
    (This)->lpVtbl -> TransToWcPln(This,i_pPlnMat,o_ppPt)

#define IXYZ_TransToMatPlnXYZ(This,i_pPlnMat,o_dx,o_dy,o_dz)	\
    (This)->lpVtbl -> TransToMatPlnXYZ(This,i_pPlnMat,o_dx,o_dy,o_dz)

#define IXYZ_Save(This,i_ipFiler)	\
    (This)->lpVtbl -> Save(This,i_ipFiler)

#define IXYZ_Load(This,i_ipFiler)	\
    (This)->lpVtbl -> Load(This,i_ipFiler)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZ_GetCXYZ_Proxy( 
    IXYZ * This,
    /* [retval][out] */ LONG_PTR *o_pplCXYZAddress);


void __RPC_STUB IXYZ_GetCXYZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZ_PutIVect_Proxy( 
    IXYZ * This,
    /* [in] */ IVector *i_pVec);


void __RPC_STUB IXYZ_PutIVect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZ_PutIXYZ_Proxy( 
    IXYZ * This,
    /* [in] */ IXYZ *i_pPt);


void __RPC_STUB IXYZ_PutIXYZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZ_GetXYZ_Proxy( 
    IXYZ * This,
    /* [out] */ DOUBLE *o_pdX,
    /* [out] */ DOUBLE *o_pdY,
    /* [out] */ DOUBLE *o_pdZ);


void __RPC_STUB IXYZ_GetXYZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZ_PutXYZ_Proxy( 
    IXYZ * This,
    /* [in] */ DOUBLE i_dX,
    /* [in] */ DOUBLE i_dY,
    /* [in] */ DOUBLE i_dZ);


void __RPC_STUB IXYZ_PutXYZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZ_IsLegal_Proxy( 
    IXYZ * This,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IXYZ_IsLegal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZ_Init_Proxy( 
    IXYZ * This);


void __RPC_STUB IXYZ_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZ_Trans_Proxy( 
    IXYZ * This,
    /* [in] */ IMatrix *i_pMat);


void __RPC_STUB IXYZ_Trans_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZ_Rotate_Proxy( 
    IXYZ * This,
    /* [in] */ DOUBLE i_dRotAng,
    /* [in] */ IVector *i_pVec,
    /* [in] */ IXYZ *i_pDtmPt);


void __RPC_STUB IXYZ_Rotate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZ_Scale_Proxy( 
    IXYZ * This,
    /* [in] */ DOUBLE i_dScale,
    /* [in] */ IXYZ *i_pDtmPt);


void __RPC_STUB IXYZ_Scale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZ_GetDistToPt_Proxy( 
    IXYZ * This,
    /* [in] */ IXYZ *i_pPt,
    /* [retval][out] */ DOUBLE *o_pdDist);


void __RPC_STUB IXYZ_GetDistToPt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZ_GetDistToPts_Proxy( 
    IXYZ * This,
    /* [in] */ IXYZArray *i_pPts,
    /* [in] */ LONG i_iNum,
    /* [out] */ DOUBLE *o_pdDist,
    /* [out] */ int *o_iIdx);


void __RPC_STUB IXYZ_GetDistToPts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZ_GetProjPt_Proxy( 
    IXYZ * This,
    /* [in] */ IPlane *i_pProjPln,
    /* [out] */ IXYZ **o_ppPt);


void __RPC_STUB IXYZ_GetProjPt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZ_IfTriPtsColn_Proxy( 
    IXYZ * This,
    /* [in] */ IXYZ *i_pP0,
    /* [in] */ IXYZ *i_pP1,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IXYZ_IfTriPtsColn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZ_GetIVec_Proxy( 
    IXYZ * This,
    /* [out] */ IVector **o_ppVec);


void __RPC_STUB IXYZ_GetIVec_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZ_IsSame_Proxy( 
    IXYZ * This,
    /* [in] */ IXYZ *i_pPt,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IXYZ_IsSame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZ_GetMirrorPt_Proxy( 
    IXYZ * This,
    /* [in] */ IPlane *i_pMirrorPln,
    /* [retval][out] */ IXYZ **o_ppPt);


void __RPC_STUB IXYZ_GetMirrorPt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZ_TransToMatPln_Proxy( 
    IXYZ * This,
    /* [in] */ IMatrix *i_pPlnMat,
    /* [retval][out] */ IXYZ **o_ppPt);


void __RPC_STUB IXYZ_TransToMatPln_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZ_TransToWcPln_Proxy( 
    IXYZ * This,
    /* [in] */ IMatrix *i_pPlnMat,
    /* [retval][out] */ IXYZ **o_ppPt);


void __RPC_STUB IXYZ_TransToWcPln_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZ_TransToMatPlnXYZ_Proxy( 
    IXYZ * This,
    /* [in] */ IMatrix *i_pPlnMat,
    /* [out] */ double *o_dx,
    /* [out] */ double *o_dy,
    /* [out] */ double *o_dz);


void __RPC_STUB IXYZ_TransToMatPlnXYZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZ_Save_Proxy( 
    IXYZ * This,
    /* [in] */ ICxFiler *i_ipFiler);


void __RPC_STUB IXYZ_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZ_Load_Proxy( 
    IXYZ * This,
    /* [in] */ ICxFiler *i_ipFiler);


void __RPC_STUB IXYZ_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IXYZ_INTERFACE_DEFINED__ */


#ifndef __IVector_INTERFACE_DEFINED__
#define __IVector_INTERFACE_DEFINED__

/* interface IVector */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IVector;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2E945919-BDC5-4C08-A11E-A95EB1C57817")
    IVector : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCVector( 
            /* [retval][out] */ LONG_PTR *o_pplCVectorAddress) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutIXYZ( 
            /* [in] */ IXYZ *i_pPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutIVect( 
            /* [in] */ IVector *i_pVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetXYZ( 
            /* [out] */ DOUBLE *o_pX,
            /* [out] */ DOUBLE *o_pY,
            /* [out] */ DOUBLE *o_pZ) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutXYZ( 
            /* [in] */ DOUBLE i_dX,
            /* [in] */ DOUBLE i_dY,
            /* [in] */ DOUBLE i_dZ) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsLegal( 
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Init( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Unit( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Trans( 
            /* [in] */ IMatrix *i_pMat) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TransToMatPln( 
            /* [in] */ IMatrix *i_pPlnMat,
            /* [retval][out] */ IVector **o_ppVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TransToWcPln( 
            /* [in] */ IMatrix *i_pPlnMat,
            /* [retval][out] */ IVector **o_ppVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Scale( 
            /* [in] */ DOUBLE i_dScale,
            /* [in] */ IXYZ *i_pDtmPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsSame( 
            /* [in] */ IVector *i_pVec,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsSameDir( 
            /* [in] */ IVector *i_pVec,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsParl( 
            /* [in] */ IVector *i_pVec,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsPerp( 
            /* [in] */ IVector *i_pVec,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDotProd( 
            /* [in] */ IVector *i_pVec,
            /* [retval][out] */ DOUBLE *o_dProd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAngTo( 
            /* [in] */ IVector *i_pEndVec,
            /* [retval][out] */ DOUBLE *o_dAng) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLength( 
            /* [retval][out] */ DOUBLE *o_dLen) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetHybrdProd( 
            /* [in] */ IVector *i_pVec0,
            /* [in] */ IVector *i_pVec1,
            /* [retval][out] */ DOUBLE *o_dProd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCrossProd( 
            /* [in] */ IVector *i_pVec,
            /* [retval][out] */ IVector **o_ppVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAngToXAx( 
            /* [retval][out] */ DOUBLE *o_dAng) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAngToYAx( 
            /* [retval][out] */ DOUBLE *o_dAng) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAngToZAx( 
            /* [retval][out] */ DOUBLE *o_dAng) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPt( 
            /* [retval][out] */ IXYZ **o_ppPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AntiDir( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetProjVec( 
            /* [in] */ IPlane *i_ProjPln,
            /* [retval][out] */ IVector **o_ppVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Rotate( 
            /* [in] */ DOUBLE i_RotAng,
            /* [in] */ IVector *i_pDirVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Mirror( 
            /* [in] */ IPlane *i_MirrorPln,
            /* [retval][out] */ IVector **o_ppVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutByTwoPt( 
            /* [in] */ IXYZ *i_pSPt,
            /* [in] */ IXYZ *i_pEPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Plus( 
            /* [in] */ IVector *i_pVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Sub( 
            /* [in] */ IVector *i_pVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Multi( 
            /* [in] */ DOUBLE i_dScale) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetLength( 
            /* [in] */ DOUBLE i_dLen) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ ICxFiler *i_ipFiler) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ ICxFiler *i_ipFiler) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVectorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVector * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVector * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVector * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IVector * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IVector * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IVector * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IVector * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCVector )( 
            IVector * This,
            /* [retval][out] */ LONG_PTR *o_pplCVectorAddress);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutIXYZ )( 
            IVector * This,
            /* [in] */ IXYZ *i_pPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutIVect )( 
            IVector * This,
            /* [in] */ IVector *i_pVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXYZ )( 
            IVector * This,
            /* [out] */ DOUBLE *o_pX,
            /* [out] */ DOUBLE *o_pY,
            /* [out] */ DOUBLE *o_pZ);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutXYZ )( 
            IVector * This,
            /* [in] */ DOUBLE i_dX,
            /* [in] */ DOUBLE i_dY,
            /* [in] */ DOUBLE i_dZ);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsLegal )( 
            IVector * This,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Init )( 
            IVector * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Unit )( 
            IVector * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Trans )( 
            IVector * This,
            /* [in] */ IMatrix *i_pMat);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransToMatPln )( 
            IVector * This,
            /* [in] */ IMatrix *i_pPlnMat,
            /* [retval][out] */ IVector **o_ppVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransToWcPln )( 
            IVector * This,
            /* [in] */ IMatrix *i_pPlnMat,
            /* [retval][out] */ IVector **o_ppVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Scale )( 
            IVector * This,
            /* [in] */ DOUBLE i_dScale,
            /* [in] */ IXYZ *i_pDtmPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsSame )( 
            IVector * This,
            /* [in] */ IVector *i_pVec,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsSameDir )( 
            IVector * This,
            /* [in] */ IVector *i_pVec,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsParl )( 
            IVector * This,
            /* [in] */ IVector *i_pVec,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsPerp )( 
            IVector * This,
            /* [in] */ IVector *i_pVec,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDotProd )( 
            IVector * This,
            /* [in] */ IVector *i_pVec,
            /* [retval][out] */ DOUBLE *o_dProd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAngTo )( 
            IVector * This,
            /* [in] */ IVector *i_pEndVec,
            /* [retval][out] */ DOUBLE *o_dAng);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLength )( 
            IVector * This,
            /* [retval][out] */ DOUBLE *o_dLen);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetHybrdProd )( 
            IVector * This,
            /* [in] */ IVector *i_pVec0,
            /* [in] */ IVector *i_pVec1,
            /* [retval][out] */ DOUBLE *o_dProd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCrossProd )( 
            IVector * This,
            /* [in] */ IVector *i_pVec,
            /* [retval][out] */ IVector **o_ppVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAngToXAx )( 
            IVector * This,
            /* [retval][out] */ DOUBLE *o_dAng);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAngToYAx )( 
            IVector * This,
            /* [retval][out] */ DOUBLE *o_dAng);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAngToZAx )( 
            IVector * This,
            /* [retval][out] */ DOUBLE *o_dAng);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPt )( 
            IVector * This,
            /* [retval][out] */ IXYZ **o_ppPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AntiDir )( 
            IVector * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetProjVec )( 
            IVector * This,
            /* [in] */ IPlane *i_ProjPln,
            /* [retval][out] */ IVector **o_ppVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            IVector * This,
            /* [in] */ DOUBLE i_RotAng,
            /* [in] */ IVector *i_pDirVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror )( 
            IVector * This,
            /* [in] */ IPlane *i_MirrorPln,
            /* [retval][out] */ IVector **o_ppVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutByTwoPt )( 
            IVector * This,
            /* [in] */ IXYZ *i_pSPt,
            /* [in] */ IXYZ *i_pEPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Plus )( 
            IVector * This,
            /* [in] */ IVector *i_pVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Sub )( 
            IVector * This,
            /* [in] */ IVector *i_pVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Multi )( 
            IVector * This,
            /* [in] */ DOUBLE i_dScale);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetLength )( 
            IVector * This,
            /* [in] */ DOUBLE i_dLen);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IVector * This,
            /* [in] */ ICxFiler *i_ipFiler);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IVector * This,
            /* [in] */ ICxFiler *i_ipFiler);
        
        END_INTERFACE
    } IVectorVtbl;

    interface IVector
    {
        CONST_VTBL struct IVectorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVector_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVector_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVector_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVector_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IVector_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IVector_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IVector_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IVector_GetCVector(This,o_pplCVectorAddress)	\
    (This)->lpVtbl -> GetCVector(This,o_pplCVectorAddress)

#define IVector_PutIXYZ(This,i_pPt)	\
    (This)->lpVtbl -> PutIXYZ(This,i_pPt)

#define IVector_PutIVect(This,i_pVec)	\
    (This)->lpVtbl -> PutIVect(This,i_pVec)

#define IVector_GetXYZ(This,o_pX,o_pY,o_pZ)	\
    (This)->lpVtbl -> GetXYZ(This,o_pX,o_pY,o_pZ)

#define IVector_PutXYZ(This,i_dX,i_dY,i_dZ)	\
    (This)->lpVtbl -> PutXYZ(This,i_dX,i_dY,i_dZ)

#define IVector_IsLegal(This,o_pbVal)	\
    (This)->lpVtbl -> IsLegal(This,o_pbVal)

#define IVector_Init(This)	\
    (This)->lpVtbl -> Init(This)

#define IVector_Unit(This)	\
    (This)->lpVtbl -> Unit(This)

#define IVector_Trans(This,i_pMat)	\
    (This)->lpVtbl -> Trans(This,i_pMat)

#define IVector_TransToMatPln(This,i_pPlnMat,o_ppVec)	\
    (This)->lpVtbl -> TransToMatPln(This,i_pPlnMat,o_ppVec)

#define IVector_TransToWcPln(This,i_pPlnMat,o_ppVec)	\
    (This)->lpVtbl -> TransToWcPln(This,i_pPlnMat,o_ppVec)

#define IVector_Scale(This,i_dScale,i_pDtmPt)	\
    (This)->lpVtbl -> Scale(This,i_dScale,i_pDtmPt)

#define IVector_IsSame(This,i_pVec,o_pbVal)	\
    (This)->lpVtbl -> IsSame(This,i_pVec,o_pbVal)

#define IVector_IsSameDir(This,i_pVec,o_pbVal)	\
    (This)->lpVtbl -> IsSameDir(This,i_pVec,o_pbVal)

#define IVector_IsParl(This,i_pVec,o_pbVal)	\
    (This)->lpVtbl -> IsParl(This,i_pVec,o_pbVal)

#define IVector_IsPerp(This,i_pVec,o_pbVal)	\
    (This)->lpVtbl -> IsPerp(This,i_pVec,o_pbVal)

#define IVector_GetDotProd(This,i_pVec,o_dProd)	\
    (This)->lpVtbl -> GetDotProd(This,i_pVec,o_dProd)

#define IVector_GetAngTo(This,i_pEndVec,o_dAng)	\
    (This)->lpVtbl -> GetAngTo(This,i_pEndVec,o_dAng)

#define IVector_GetLength(This,o_dLen)	\
    (This)->lpVtbl -> GetLength(This,o_dLen)

#define IVector_GetHybrdProd(This,i_pVec0,i_pVec1,o_dProd)	\
    (This)->lpVtbl -> GetHybrdProd(This,i_pVec0,i_pVec1,o_dProd)

#define IVector_GetCrossProd(This,i_pVec,o_ppVec)	\
    (This)->lpVtbl -> GetCrossProd(This,i_pVec,o_ppVec)

#define IVector_GetAngToXAx(This,o_dAng)	\
    (This)->lpVtbl -> GetAngToXAx(This,o_dAng)

#define IVector_GetAngToYAx(This,o_dAng)	\
    (This)->lpVtbl -> GetAngToYAx(This,o_dAng)

#define IVector_GetAngToZAx(This,o_dAng)	\
    (This)->lpVtbl -> GetAngToZAx(This,o_dAng)

#define IVector_GetPt(This,o_ppPt)	\
    (This)->lpVtbl -> GetPt(This,o_ppPt)

#define IVector_AntiDir(This)	\
    (This)->lpVtbl -> AntiDir(This)

#define IVector_GetProjVec(This,i_ProjPln,o_ppVec)	\
    (This)->lpVtbl -> GetProjVec(This,i_ProjPln,o_ppVec)

#define IVector_Rotate(This,i_RotAng,i_pDirVec)	\
    (This)->lpVtbl -> Rotate(This,i_RotAng,i_pDirVec)

#define IVector_Mirror(This,i_MirrorPln,o_ppVec)	\
    (This)->lpVtbl -> Mirror(This,i_MirrorPln,o_ppVec)

#define IVector_PutByTwoPt(This,i_pSPt,i_pEPt)	\
    (This)->lpVtbl -> PutByTwoPt(This,i_pSPt,i_pEPt)

#define IVector_Plus(This,i_pVec)	\
    (This)->lpVtbl -> Plus(This,i_pVec)

#define IVector_Sub(This,i_pVec)	\
    (This)->lpVtbl -> Sub(This,i_pVec)

#define IVector_Multi(This,i_dScale)	\
    (This)->lpVtbl -> Multi(This,i_dScale)

#define IVector_SetLength(This,i_dLen)	\
    (This)->lpVtbl -> SetLength(This,i_dLen)

#define IVector_Save(This,i_ipFiler)	\
    (This)->lpVtbl -> Save(This,i_ipFiler)

#define IVector_Load(This,i_ipFiler)	\
    (This)->lpVtbl -> Load(This,i_ipFiler)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_GetCVector_Proxy( 
    IVector * This,
    /* [retval][out] */ LONG_PTR *o_pplCVectorAddress);


void __RPC_STUB IVector_GetCVector_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_PutIXYZ_Proxy( 
    IVector * This,
    /* [in] */ IXYZ *i_pPt);


void __RPC_STUB IVector_PutIXYZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_PutIVect_Proxy( 
    IVector * This,
    /* [in] */ IVector *i_pVec);


void __RPC_STUB IVector_PutIVect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_GetXYZ_Proxy( 
    IVector * This,
    /* [out] */ DOUBLE *o_pX,
    /* [out] */ DOUBLE *o_pY,
    /* [out] */ DOUBLE *o_pZ);


void __RPC_STUB IVector_GetXYZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_PutXYZ_Proxy( 
    IVector * This,
    /* [in] */ DOUBLE i_dX,
    /* [in] */ DOUBLE i_dY,
    /* [in] */ DOUBLE i_dZ);


void __RPC_STUB IVector_PutXYZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_IsLegal_Proxy( 
    IVector * This,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IVector_IsLegal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_Init_Proxy( 
    IVector * This);


void __RPC_STUB IVector_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_Unit_Proxy( 
    IVector * This);


void __RPC_STUB IVector_Unit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_Trans_Proxy( 
    IVector * This,
    /* [in] */ IMatrix *i_pMat);


void __RPC_STUB IVector_Trans_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_TransToMatPln_Proxy( 
    IVector * This,
    /* [in] */ IMatrix *i_pPlnMat,
    /* [retval][out] */ IVector **o_ppVec);


void __RPC_STUB IVector_TransToMatPln_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_TransToWcPln_Proxy( 
    IVector * This,
    /* [in] */ IMatrix *i_pPlnMat,
    /* [retval][out] */ IVector **o_ppVec);


void __RPC_STUB IVector_TransToWcPln_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_Scale_Proxy( 
    IVector * This,
    /* [in] */ DOUBLE i_dScale,
    /* [in] */ IXYZ *i_pDtmPt);


void __RPC_STUB IVector_Scale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_IsSame_Proxy( 
    IVector * This,
    /* [in] */ IVector *i_pVec,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IVector_IsSame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_IsSameDir_Proxy( 
    IVector * This,
    /* [in] */ IVector *i_pVec,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IVector_IsSameDir_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_IsParl_Proxy( 
    IVector * This,
    /* [in] */ IVector *i_pVec,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IVector_IsParl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_IsPerp_Proxy( 
    IVector * This,
    /* [in] */ IVector *i_pVec,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IVector_IsPerp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_GetDotProd_Proxy( 
    IVector * This,
    /* [in] */ IVector *i_pVec,
    /* [retval][out] */ DOUBLE *o_dProd);


void __RPC_STUB IVector_GetDotProd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_GetAngTo_Proxy( 
    IVector * This,
    /* [in] */ IVector *i_pEndVec,
    /* [retval][out] */ DOUBLE *o_dAng);


void __RPC_STUB IVector_GetAngTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_GetLength_Proxy( 
    IVector * This,
    /* [retval][out] */ DOUBLE *o_dLen);


void __RPC_STUB IVector_GetLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_GetHybrdProd_Proxy( 
    IVector * This,
    /* [in] */ IVector *i_pVec0,
    /* [in] */ IVector *i_pVec1,
    /* [retval][out] */ DOUBLE *o_dProd);


void __RPC_STUB IVector_GetHybrdProd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_GetCrossProd_Proxy( 
    IVector * This,
    /* [in] */ IVector *i_pVec,
    /* [retval][out] */ IVector **o_ppVec);


void __RPC_STUB IVector_GetCrossProd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_GetAngToXAx_Proxy( 
    IVector * This,
    /* [retval][out] */ DOUBLE *o_dAng);


void __RPC_STUB IVector_GetAngToXAx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_GetAngToYAx_Proxy( 
    IVector * This,
    /* [retval][out] */ DOUBLE *o_dAng);


void __RPC_STUB IVector_GetAngToYAx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_GetAngToZAx_Proxy( 
    IVector * This,
    /* [retval][out] */ DOUBLE *o_dAng);


void __RPC_STUB IVector_GetAngToZAx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_GetPt_Proxy( 
    IVector * This,
    /* [retval][out] */ IXYZ **o_ppPt);


void __RPC_STUB IVector_GetPt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_AntiDir_Proxy( 
    IVector * This);


void __RPC_STUB IVector_AntiDir_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_GetProjVec_Proxy( 
    IVector * This,
    /* [in] */ IPlane *i_ProjPln,
    /* [retval][out] */ IVector **o_ppVec);


void __RPC_STUB IVector_GetProjVec_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_Rotate_Proxy( 
    IVector * This,
    /* [in] */ DOUBLE i_RotAng,
    /* [in] */ IVector *i_pDirVec);


void __RPC_STUB IVector_Rotate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_Mirror_Proxy( 
    IVector * This,
    /* [in] */ IPlane *i_MirrorPln,
    /* [retval][out] */ IVector **o_ppVec);


void __RPC_STUB IVector_Mirror_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_PutByTwoPt_Proxy( 
    IVector * This,
    /* [in] */ IXYZ *i_pSPt,
    /* [in] */ IXYZ *i_pEPt);


void __RPC_STUB IVector_PutByTwoPt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_Plus_Proxy( 
    IVector * This,
    /* [in] */ IVector *i_pVec);


void __RPC_STUB IVector_Plus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_Sub_Proxy( 
    IVector * This,
    /* [in] */ IVector *i_pVec);


void __RPC_STUB IVector_Sub_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_Multi_Proxy( 
    IVector * This,
    /* [in] */ DOUBLE i_dScale);


void __RPC_STUB IVector_Multi_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_SetLength_Proxy( 
    IVector * This,
    /* [in] */ DOUBLE i_dLen);


void __RPC_STUB IVector_SetLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_Save_Proxy( 
    IVector * This,
    /* [in] */ ICxFiler *i_ipFiler);


void __RPC_STUB IVector_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVector_Load_Proxy( 
    IVector * This,
    /* [in] */ ICxFiler *i_ipFiler);


void __RPC_STUB IVector_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVector_INTERFACE_DEFINED__ */


#ifndef __ILine_INTERFACE_DEFINED__
#define __ILine_INTERFACE_DEFINED__

/* interface ILine */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ILine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C1374258-666A-4E28-B3F2-446301A5E8A7")
    ILine : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCLine( 
            /* [retval][out] */ LONG_PTR *o_pplCLineAddress) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Init( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPt( 
            /* [in] */ IXYZ *i_pStartPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDir( 
            /* [in] */ IVector *i_pDirVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPt( 
            /* [retval][out] */ IXYZ **o_ppPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDir( 
            /* [retval][out] */ IVector **o_ppDirVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Trans( 
            /* [in] */ IMatrix *i_pMat) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Rotate( 
            /* [in] */ DOUBLE i_RotAng,
            /* [in] */ IVector *i_pVec,
            /* [in] */ IXYZ *i_pDtmPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Mirror( 
            /* [in] */ IPlane *i_pMirPln,
            /* [retval][out] */ ILine **o_ppLine) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAngTo( 
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ DOUBLE *o_dAng) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsParl( 
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsCopln( 
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsPerp( 
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetParlLn( 
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ ILine **o_ppParlLine) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAngLn( 
            /* [in] */ IXYZ *i_pPt,
            /* [in] */ DOUBLE i_dAng,
            /* [retval][out] */ ILine **o_ppAngLine) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPerpLn( 
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ ILine **i_ppPerpLine) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsOn( 
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetProjLn( 
            /* [in] */ IPlane *i_pProjPln,
            /* [out] */ ILine **o_ppProjLine) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetProjIntPt( 
            /* [in] */ ILine *i_pLine,
            /* [in] */ IPlane *i_pProjPln,
            /* [retval][out] */ IXYZ **o_ppPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetIntPt( 
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ IXYZ **o_ppIntPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsSame( 
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDistToPt( 
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ DOUBLE *o_pDist) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDistToLn( 
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ DOUBLE *o_pDist) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPerpPt( 
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ IXYZ **o_ppIntPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsLegal( 
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutIXYZTwo( 
            /* [in] */ IXYZ *i_pStartPt,
            /* [in] */ IXYZ *i_pEndPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutXYZTwo( 
            /* [in] */ double i_dStax,
            /* [in] */ double i_dStay,
            /* [in] */ double i_dStaz,
            /* [in] */ double i_dEndx,
            /* [in] */ double i_dEndy,
            /* [in] */ double i_dEndz) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutIXYZIVect( 
            /* [in] */ IXYZ *i_pPt,
            /* [in] */ IVector *i_DirVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ ICxFiler *i_ipFiler) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ ICxFiler *i_ipFiler) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILine * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILine * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILine * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILine * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILine * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILine * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCLine )( 
            ILine * This,
            /* [retval][out] */ LONG_PTR *o_pplCLineAddress);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Init )( 
            ILine * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPt )( 
            ILine * This,
            /* [in] */ IXYZ *i_pStartPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDir )( 
            ILine * This,
            /* [in] */ IVector *i_pDirVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPt )( 
            ILine * This,
            /* [retval][out] */ IXYZ **o_ppPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDir )( 
            ILine * This,
            /* [retval][out] */ IVector **o_ppDirVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Trans )( 
            ILine * This,
            /* [in] */ IMatrix *i_pMat);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            ILine * This,
            /* [in] */ DOUBLE i_RotAng,
            /* [in] */ IVector *i_pVec,
            /* [in] */ IXYZ *i_pDtmPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror )( 
            ILine * This,
            /* [in] */ IPlane *i_pMirPln,
            /* [retval][out] */ ILine **o_ppLine);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAngTo )( 
            ILine * This,
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ DOUBLE *o_dAng);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsParl )( 
            ILine * This,
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsCopln )( 
            ILine * This,
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsPerp )( 
            ILine * This,
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetParlLn )( 
            ILine * This,
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ ILine **o_ppParlLine);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAngLn )( 
            ILine * This,
            /* [in] */ IXYZ *i_pPt,
            /* [in] */ DOUBLE i_dAng,
            /* [retval][out] */ ILine **o_ppAngLine);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPerpLn )( 
            ILine * This,
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ ILine **i_ppPerpLine);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsOn )( 
            ILine * This,
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetProjLn )( 
            ILine * This,
            /* [in] */ IPlane *i_pProjPln,
            /* [out] */ ILine **o_ppProjLine);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetProjIntPt )( 
            ILine * This,
            /* [in] */ ILine *i_pLine,
            /* [in] */ IPlane *i_pProjPln,
            /* [retval][out] */ IXYZ **o_ppPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetIntPt )( 
            ILine * This,
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ IXYZ **o_ppIntPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsSame )( 
            ILine * This,
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDistToPt )( 
            ILine * This,
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ DOUBLE *o_pDist);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDistToLn )( 
            ILine * This,
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ DOUBLE *o_pDist);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPerpPt )( 
            ILine * This,
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ IXYZ **o_ppIntPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsLegal )( 
            ILine * This,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutIXYZTwo )( 
            ILine * This,
            /* [in] */ IXYZ *i_pStartPt,
            /* [in] */ IXYZ *i_pEndPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutXYZTwo )( 
            ILine * This,
            /* [in] */ double i_dStax,
            /* [in] */ double i_dStay,
            /* [in] */ double i_dStaz,
            /* [in] */ double i_dEndx,
            /* [in] */ double i_dEndy,
            /* [in] */ double i_dEndz);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutIXYZIVect )( 
            ILine * This,
            /* [in] */ IXYZ *i_pPt,
            /* [in] */ IVector *i_DirVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            ILine * This,
            /* [in] */ ICxFiler *i_ipFiler);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            ILine * This,
            /* [in] */ ICxFiler *i_ipFiler);
        
        END_INTERFACE
    } ILineVtbl;

    interface ILine
    {
        CONST_VTBL struct ILineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILine_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILine_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILine_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILine_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ILine_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ILine_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ILine_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ILine_GetCLine(This,o_pplCLineAddress)	\
    (This)->lpVtbl -> GetCLine(This,o_pplCLineAddress)

#define ILine_Init(This)	\
    (This)->lpVtbl -> Init(This)

#define ILine_SetPt(This,i_pStartPt)	\
    (This)->lpVtbl -> SetPt(This,i_pStartPt)

#define ILine_SetDir(This,i_pDirVec)	\
    (This)->lpVtbl -> SetDir(This,i_pDirVec)

#define ILine_GetPt(This,o_ppPt)	\
    (This)->lpVtbl -> GetPt(This,o_ppPt)

#define ILine_GetDir(This,o_ppDirVec)	\
    (This)->lpVtbl -> GetDir(This,o_ppDirVec)

#define ILine_Trans(This,i_pMat)	\
    (This)->lpVtbl -> Trans(This,i_pMat)

#define ILine_Rotate(This,i_RotAng,i_pVec,i_pDtmPt)	\
    (This)->lpVtbl -> Rotate(This,i_RotAng,i_pVec,i_pDtmPt)

#define ILine_Mirror(This,i_pMirPln,o_ppLine)	\
    (This)->lpVtbl -> Mirror(This,i_pMirPln,o_ppLine)

#define ILine_GetAngTo(This,i_pLine,o_dAng)	\
    (This)->lpVtbl -> GetAngTo(This,i_pLine,o_dAng)

#define ILine_IsParl(This,i_pLine,o_pbVal)	\
    (This)->lpVtbl -> IsParl(This,i_pLine,o_pbVal)

#define ILine_IsCopln(This,i_pLine,o_pbVal)	\
    (This)->lpVtbl -> IsCopln(This,i_pLine,o_pbVal)

#define ILine_IsPerp(This,i_pLine,o_pbVal)	\
    (This)->lpVtbl -> IsPerp(This,i_pLine,o_pbVal)

#define ILine_GetParlLn(This,i_pPt,o_ppParlLine)	\
    (This)->lpVtbl -> GetParlLn(This,i_pPt,o_ppParlLine)

#define ILine_GetAngLn(This,i_pPt,i_dAng,o_ppAngLine)	\
    (This)->lpVtbl -> GetAngLn(This,i_pPt,i_dAng,o_ppAngLine)

#define ILine_GetPerpLn(This,i_pPt,i_ppPerpLine)	\
    (This)->lpVtbl -> GetPerpLn(This,i_pPt,i_ppPerpLine)

#define ILine_IsOn(This,i_pPt,o_pbVal)	\
    (This)->lpVtbl -> IsOn(This,i_pPt,o_pbVal)

#define ILine_GetProjLn(This,i_pProjPln,o_ppProjLine)	\
    (This)->lpVtbl -> GetProjLn(This,i_pProjPln,o_ppProjLine)

#define ILine_GetProjIntPt(This,i_pLine,i_pProjPln,o_ppPt)	\
    (This)->lpVtbl -> GetProjIntPt(This,i_pLine,i_pProjPln,o_ppPt)

#define ILine_GetIntPt(This,i_pLine,o_ppIntPt)	\
    (This)->lpVtbl -> GetIntPt(This,i_pLine,o_ppIntPt)

#define ILine_IsSame(This,i_pLine,o_pbVal)	\
    (This)->lpVtbl -> IsSame(This,i_pLine,o_pbVal)

#define ILine_GetDistToPt(This,i_pPt,o_pDist)	\
    (This)->lpVtbl -> GetDistToPt(This,i_pPt,o_pDist)

#define ILine_GetDistToLn(This,i_pLine,o_pDist)	\
    (This)->lpVtbl -> GetDistToLn(This,i_pLine,o_pDist)

#define ILine_GetPerpPt(This,i_pPt,o_ppIntPt)	\
    (This)->lpVtbl -> GetPerpPt(This,i_pPt,o_ppIntPt)

#define ILine_IsLegal(This,o_pbVal)	\
    (This)->lpVtbl -> IsLegal(This,o_pbVal)

#define ILine_PutIXYZTwo(This,i_pStartPt,i_pEndPt)	\
    (This)->lpVtbl -> PutIXYZTwo(This,i_pStartPt,i_pEndPt)

#define ILine_PutXYZTwo(This,i_dStax,i_dStay,i_dStaz,i_dEndx,i_dEndy,i_dEndz)	\
    (This)->lpVtbl -> PutXYZTwo(This,i_dStax,i_dStay,i_dStaz,i_dEndx,i_dEndy,i_dEndz)

#define ILine_PutIXYZIVect(This,i_pPt,i_DirVec)	\
    (This)->lpVtbl -> PutIXYZIVect(This,i_pPt,i_DirVec)

#define ILine_Save(This,i_ipFiler)	\
    (This)->lpVtbl -> Save(This,i_ipFiler)

#define ILine_Load(This,i_ipFiler)	\
    (This)->lpVtbl -> Load(This,i_ipFiler)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_GetCLine_Proxy( 
    ILine * This,
    /* [retval][out] */ LONG_PTR *o_pplCLineAddress);


void __RPC_STUB ILine_GetCLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_Init_Proxy( 
    ILine * This);


void __RPC_STUB ILine_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_SetPt_Proxy( 
    ILine * This,
    /* [in] */ IXYZ *i_pStartPt);


void __RPC_STUB ILine_SetPt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_SetDir_Proxy( 
    ILine * This,
    /* [in] */ IVector *i_pDirVec);


void __RPC_STUB ILine_SetDir_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_GetPt_Proxy( 
    ILine * This,
    /* [retval][out] */ IXYZ **o_ppPt);


void __RPC_STUB ILine_GetPt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_GetDir_Proxy( 
    ILine * This,
    /* [retval][out] */ IVector **o_ppDirVec);


void __RPC_STUB ILine_GetDir_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_Trans_Proxy( 
    ILine * This,
    /* [in] */ IMatrix *i_pMat);


void __RPC_STUB ILine_Trans_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_Rotate_Proxy( 
    ILine * This,
    /* [in] */ DOUBLE i_RotAng,
    /* [in] */ IVector *i_pVec,
    /* [in] */ IXYZ *i_pDtmPt);


void __RPC_STUB ILine_Rotate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_Mirror_Proxy( 
    ILine * This,
    /* [in] */ IPlane *i_pMirPln,
    /* [retval][out] */ ILine **o_ppLine);


void __RPC_STUB ILine_Mirror_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_GetAngTo_Proxy( 
    ILine * This,
    /* [in] */ ILine *i_pLine,
    /* [retval][out] */ DOUBLE *o_dAng);


void __RPC_STUB ILine_GetAngTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_IsParl_Proxy( 
    ILine * This,
    /* [in] */ ILine *i_pLine,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB ILine_IsParl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_IsCopln_Proxy( 
    ILine * This,
    /* [in] */ ILine *i_pLine,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB ILine_IsCopln_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_IsPerp_Proxy( 
    ILine * This,
    /* [in] */ ILine *i_pLine,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB ILine_IsPerp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_GetParlLn_Proxy( 
    ILine * This,
    /* [in] */ IXYZ *i_pPt,
    /* [retval][out] */ ILine **o_ppParlLine);


void __RPC_STUB ILine_GetParlLn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_GetAngLn_Proxy( 
    ILine * This,
    /* [in] */ IXYZ *i_pPt,
    /* [in] */ DOUBLE i_dAng,
    /* [retval][out] */ ILine **o_ppAngLine);


void __RPC_STUB ILine_GetAngLn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_GetPerpLn_Proxy( 
    ILine * This,
    /* [in] */ IXYZ *i_pPt,
    /* [retval][out] */ ILine **i_ppPerpLine);


void __RPC_STUB ILine_GetPerpLn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_IsOn_Proxy( 
    ILine * This,
    /* [in] */ IXYZ *i_pPt,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB ILine_IsOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_GetProjLn_Proxy( 
    ILine * This,
    /* [in] */ IPlane *i_pProjPln,
    /* [out] */ ILine **o_ppProjLine);


void __RPC_STUB ILine_GetProjLn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_GetProjIntPt_Proxy( 
    ILine * This,
    /* [in] */ ILine *i_pLine,
    /* [in] */ IPlane *i_pProjPln,
    /* [retval][out] */ IXYZ **o_ppPt);


void __RPC_STUB ILine_GetProjIntPt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_GetIntPt_Proxy( 
    ILine * This,
    /* [in] */ ILine *i_pLine,
    /* [retval][out] */ IXYZ **o_ppIntPt);


void __RPC_STUB ILine_GetIntPt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_IsSame_Proxy( 
    ILine * This,
    /* [in] */ ILine *i_pLine,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB ILine_IsSame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_GetDistToPt_Proxy( 
    ILine * This,
    /* [in] */ IXYZ *i_pPt,
    /* [retval][out] */ DOUBLE *o_pDist);


void __RPC_STUB ILine_GetDistToPt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_GetDistToLn_Proxy( 
    ILine * This,
    /* [in] */ ILine *i_pLine,
    /* [retval][out] */ DOUBLE *o_pDist);


void __RPC_STUB ILine_GetDistToLn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_GetPerpPt_Proxy( 
    ILine * This,
    /* [in] */ IXYZ *i_pPt,
    /* [retval][out] */ IXYZ **o_ppIntPt);


void __RPC_STUB ILine_GetPerpPt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_IsLegal_Proxy( 
    ILine * This,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB ILine_IsLegal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_PutIXYZTwo_Proxy( 
    ILine * This,
    /* [in] */ IXYZ *i_pStartPt,
    /* [in] */ IXYZ *i_pEndPt);


void __RPC_STUB ILine_PutIXYZTwo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_PutXYZTwo_Proxy( 
    ILine * This,
    /* [in] */ double i_dStax,
    /* [in] */ double i_dStay,
    /* [in] */ double i_dStaz,
    /* [in] */ double i_dEndx,
    /* [in] */ double i_dEndy,
    /* [in] */ double i_dEndz);


void __RPC_STUB ILine_PutXYZTwo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_PutIXYZIVect_Proxy( 
    ILine * This,
    /* [in] */ IXYZ *i_pPt,
    /* [in] */ IVector *i_DirVec);


void __RPC_STUB ILine_PutIXYZIVect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_Save_Proxy( 
    ILine * This,
    /* [in] */ ICxFiler *i_ipFiler);


void __RPC_STUB ILine_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ILine_Load_Proxy( 
    ILine * This,
    /* [in] */ ICxFiler *i_ipFiler);


void __RPC_STUB ILine_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ILine_INTERFACE_DEFINED__ */


#ifndef __IPlane_INTERFACE_DEFINED__
#define __IPlane_INTERFACE_DEFINED__

/* interface IPlane */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IPlane;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8F20D475-E777-464A-8B7B-EB20C9B6E7BE")
    IPlane : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCPlane( 
            /* [retval][out] */ LONG_PTR *o_pplCPlaneAddress) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPlnCoef( 
            /* [retval][out] */ IXYZW **o_ppParas) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPt( 
            /* [retval][out] */ IXYZ **o_ppPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPt( 
            /* [in] */ IXYZ *i_pPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNorm( 
            /* [retval][out] */ IVector **o_ppVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetNorm( 
            /* [in] */ IVector *i_pVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Set( 
            /* [in] */ IXYZ *i_pPt,
            /* [in] */ IVector *i_pVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsOnXYZ( 
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsOnLine( 
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsParlLine( 
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsParlPlane( 
            /* [in] */ IPlane *i_pPlane,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsPerpPlane( 
            /* [in] */ IPlane *i_pPlane,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsPerpLine( 
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDistToForPt( 
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ DOUBLE *o_dDist) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDistToForLine( 
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ DOUBLE *o_dDist) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDistToForPlane( 
            /* [in] */ IPlane *i_pPlane,
            /* [retval][out] */ DOUBLE *o_dDist) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPerpLn( 
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ ILine **o_ppLine) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPerpPln( 
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ IPlane **o_ppPlane) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetParlPlnForPt( 
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ IPlane **o_ppPlane) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetParlPlnForDis( 
            /* [in] */ DOUBLE i_dDist,
            /* [retval][out] */ IPlane **o_ppPlane) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAngToPln( 
            /* [in] */ IPlane *i_pPlane,
            /* [retval][out] */ DOUBLE *o_dAng) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetInsctPt( 
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ IXYZ **o_ppPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetInsctLn( 
            /* [in] */ IPlane *i_pPlane,
            /* [retval][out] */ ILine **o_ppLine) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsLegal( 
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutIPlane( 
            /* [in] */ IPlane *i_pPln) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutTriPts( 
            /* [in] */ IXYZ *i_pPt1,
            /* [in] */ IXYZ *i_pPt2,
            /* [in] */ IXYZ *i_pPt3) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutByCoef( 
            /* [in] */ DOUBLE i_dA,
            /* [in] */ DOUBLE i_dB,
            /* [in] */ DOUBLE i_dC,
            /* [in] */ DOUBLE i_dD) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutByPtNorm( 
            /* [in] */ IXYZ *i_pPt,
            /* [in] */ IVector *i_pNorm) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ ICxFiler *i_ipFiler) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ ICxFiler *i_ipFiler) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPlaneVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPlane * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPlane * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPlane * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPlane * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPlane * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPlane * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPlane * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCPlane )( 
            IPlane * This,
            /* [retval][out] */ LONG_PTR *o_pplCPlaneAddress);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPlnCoef )( 
            IPlane * This,
            /* [retval][out] */ IXYZW **o_ppParas);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPt )( 
            IPlane * This,
            /* [retval][out] */ IXYZ **o_ppPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPt )( 
            IPlane * This,
            /* [in] */ IXYZ *i_pPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNorm )( 
            IPlane * This,
            /* [retval][out] */ IVector **o_ppVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetNorm )( 
            IPlane * This,
            /* [in] */ IVector *i_pVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Set )( 
            IPlane * This,
            /* [in] */ IXYZ *i_pPt,
            /* [in] */ IVector *i_pVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsOnXYZ )( 
            IPlane * This,
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsOnLine )( 
            IPlane * This,
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsParlLine )( 
            IPlane * This,
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsParlPlane )( 
            IPlane * This,
            /* [in] */ IPlane *i_pPlane,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsPerpPlane )( 
            IPlane * This,
            /* [in] */ IPlane *i_pPlane,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsPerpLine )( 
            IPlane * This,
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDistToForPt )( 
            IPlane * This,
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ DOUBLE *o_dDist);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDistToForLine )( 
            IPlane * This,
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ DOUBLE *o_dDist);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDistToForPlane )( 
            IPlane * This,
            /* [in] */ IPlane *i_pPlane,
            /* [retval][out] */ DOUBLE *o_dDist);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPerpLn )( 
            IPlane * This,
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ ILine **o_ppLine);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPerpPln )( 
            IPlane * This,
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ IPlane **o_ppPlane);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetParlPlnForPt )( 
            IPlane * This,
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ IPlane **o_ppPlane);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetParlPlnForDis )( 
            IPlane * This,
            /* [in] */ DOUBLE i_dDist,
            /* [retval][out] */ IPlane **o_ppPlane);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAngToPln )( 
            IPlane * This,
            /* [in] */ IPlane *i_pPlane,
            /* [retval][out] */ DOUBLE *o_dAng);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetInsctPt )( 
            IPlane * This,
            /* [in] */ ILine *i_pLine,
            /* [retval][out] */ IXYZ **o_ppPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetInsctLn )( 
            IPlane * This,
            /* [in] */ IPlane *i_pPlane,
            /* [retval][out] */ ILine **o_ppLine);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsLegal )( 
            IPlane * This,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutIPlane )( 
            IPlane * This,
            /* [in] */ IPlane *i_pPln);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutTriPts )( 
            IPlane * This,
            /* [in] */ IXYZ *i_pPt1,
            /* [in] */ IXYZ *i_pPt2,
            /* [in] */ IXYZ *i_pPt3);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutByCoef )( 
            IPlane * This,
            /* [in] */ DOUBLE i_dA,
            /* [in] */ DOUBLE i_dB,
            /* [in] */ DOUBLE i_dC,
            /* [in] */ DOUBLE i_dD);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutByPtNorm )( 
            IPlane * This,
            /* [in] */ IXYZ *i_pPt,
            /* [in] */ IVector *i_pNorm);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IPlane * This,
            /* [in] */ ICxFiler *i_ipFiler);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IPlane * This,
            /* [in] */ ICxFiler *i_ipFiler);
        
        END_INTERFACE
    } IPlaneVtbl;

    interface IPlane
    {
        CONST_VTBL struct IPlaneVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPlane_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPlane_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPlane_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPlane_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPlane_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPlane_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPlane_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IPlane_GetCPlane(This,o_pplCPlaneAddress)	\
    (This)->lpVtbl -> GetCPlane(This,o_pplCPlaneAddress)

#define IPlane_GetPlnCoef(This,o_ppParas)	\
    (This)->lpVtbl -> GetPlnCoef(This,o_ppParas)

#define IPlane_GetPt(This,o_ppPt)	\
    (This)->lpVtbl -> GetPt(This,o_ppPt)

#define IPlane_SetPt(This,i_pPt)	\
    (This)->lpVtbl -> SetPt(This,i_pPt)

#define IPlane_GetNorm(This,o_ppVec)	\
    (This)->lpVtbl -> GetNorm(This,o_ppVec)

#define IPlane_SetNorm(This,i_pVec)	\
    (This)->lpVtbl -> SetNorm(This,i_pVec)

#define IPlane_Set(This,i_pPt,i_pVec)	\
    (This)->lpVtbl -> Set(This,i_pPt,i_pVec)

#define IPlane_IsOnXYZ(This,i_pPt,o_pbVal)	\
    (This)->lpVtbl -> IsOnXYZ(This,i_pPt,o_pbVal)

#define IPlane_IsOnLine(This,i_pLine,o_pbVal)	\
    (This)->lpVtbl -> IsOnLine(This,i_pLine,o_pbVal)

#define IPlane_IsParlLine(This,i_pLine,o_pbVal)	\
    (This)->lpVtbl -> IsParlLine(This,i_pLine,o_pbVal)

#define IPlane_IsParlPlane(This,i_pPlane,o_pbVal)	\
    (This)->lpVtbl -> IsParlPlane(This,i_pPlane,o_pbVal)

#define IPlane_IsPerpPlane(This,i_pPlane,o_pbVal)	\
    (This)->lpVtbl -> IsPerpPlane(This,i_pPlane,o_pbVal)

#define IPlane_IsPerpLine(This,i_pLine,o_pbVal)	\
    (This)->lpVtbl -> IsPerpLine(This,i_pLine,o_pbVal)

#define IPlane_GetDistToForPt(This,i_pPt,o_dDist)	\
    (This)->lpVtbl -> GetDistToForPt(This,i_pPt,o_dDist)

#define IPlane_GetDistToForLine(This,i_pLine,o_dDist)	\
    (This)->lpVtbl -> GetDistToForLine(This,i_pLine,o_dDist)

#define IPlane_GetDistToForPlane(This,i_pPlane,o_dDist)	\
    (This)->lpVtbl -> GetDistToForPlane(This,i_pPlane,o_dDist)

#define IPlane_GetPerpLn(This,i_pPt,o_ppLine)	\
    (This)->lpVtbl -> GetPerpLn(This,i_pPt,o_ppLine)

#define IPlane_GetPerpPln(This,i_pLine,o_ppPlane)	\
    (This)->lpVtbl -> GetPerpPln(This,i_pLine,o_ppPlane)

#define IPlane_GetParlPlnForPt(This,i_pPt,o_ppPlane)	\
    (This)->lpVtbl -> GetParlPlnForPt(This,i_pPt,o_ppPlane)

#define IPlane_GetParlPlnForDis(This,i_dDist,o_ppPlane)	\
    (This)->lpVtbl -> GetParlPlnForDis(This,i_dDist,o_ppPlane)

#define IPlane_GetAngToPln(This,i_pPlane,o_dAng)	\
    (This)->lpVtbl -> GetAngToPln(This,i_pPlane,o_dAng)

#define IPlane_GetInsctPt(This,i_pLine,o_ppPt)	\
    (This)->lpVtbl -> GetInsctPt(This,i_pLine,o_ppPt)

#define IPlane_GetInsctLn(This,i_pPlane,o_ppLine)	\
    (This)->lpVtbl -> GetInsctLn(This,i_pPlane,o_ppLine)

#define IPlane_IsLegal(This,o_pbVal)	\
    (This)->lpVtbl -> IsLegal(This,o_pbVal)

#define IPlane_PutIPlane(This,i_pPln)	\
    (This)->lpVtbl -> PutIPlane(This,i_pPln)

#define IPlane_PutTriPts(This,i_pPt1,i_pPt2,i_pPt3)	\
    (This)->lpVtbl -> PutTriPts(This,i_pPt1,i_pPt2,i_pPt3)

#define IPlane_PutByCoef(This,i_dA,i_dB,i_dC,i_dD)	\
    (This)->lpVtbl -> PutByCoef(This,i_dA,i_dB,i_dC,i_dD)

#define IPlane_PutByPtNorm(This,i_pPt,i_pNorm)	\
    (This)->lpVtbl -> PutByPtNorm(This,i_pPt,i_pNorm)

#define IPlane_Save(This,i_ipFiler)	\
    (This)->lpVtbl -> Save(This,i_ipFiler)

#define IPlane_Load(This,i_ipFiler)	\
    (This)->lpVtbl -> Load(This,i_ipFiler)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_GetCPlane_Proxy( 
    IPlane * This,
    /* [retval][out] */ LONG_PTR *o_pplCPlaneAddress);


void __RPC_STUB IPlane_GetCPlane_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_GetPlnCoef_Proxy( 
    IPlane * This,
    /* [retval][out] */ IXYZW **o_ppParas);


void __RPC_STUB IPlane_GetPlnCoef_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_GetPt_Proxy( 
    IPlane * This,
    /* [retval][out] */ IXYZ **o_ppPt);


void __RPC_STUB IPlane_GetPt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_SetPt_Proxy( 
    IPlane * This,
    /* [in] */ IXYZ *i_pPt);


void __RPC_STUB IPlane_SetPt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_GetNorm_Proxy( 
    IPlane * This,
    /* [retval][out] */ IVector **o_ppVec);


void __RPC_STUB IPlane_GetNorm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_SetNorm_Proxy( 
    IPlane * This,
    /* [in] */ IVector *i_pVec);


void __RPC_STUB IPlane_SetNorm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_Set_Proxy( 
    IPlane * This,
    /* [in] */ IXYZ *i_pPt,
    /* [in] */ IVector *i_pVec);


void __RPC_STUB IPlane_Set_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_IsOnXYZ_Proxy( 
    IPlane * This,
    /* [in] */ IXYZ *i_pPt,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IPlane_IsOnXYZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_IsOnLine_Proxy( 
    IPlane * This,
    /* [in] */ ILine *i_pLine,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IPlane_IsOnLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_IsParlLine_Proxy( 
    IPlane * This,
    /* [in] */ ILine *i_pLine,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IPlane_IsParlLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_IsParlPlane_Proxy( 
    IPlane * This,
    /* [in] */ IPlane *i_pPlane,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IPlane_IsParlPlane_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_IsPerpPlane_Proxy( 
    IPlane * This,
    /* [in] */ IPlane *i_pPlane,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IPlane_IsPerpPlane_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_IsPerpLine_Proxy( 
    IPlane * This,
    /* [in] */ ILine *i_pLine,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IPlane_IsPerpLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_GetDistToForPt_Proxy( 
    IPlane * This,
    /* [in] */ IXYZ *i_pPt,
    /* [retval][out] */ DOUBLE *o_dDist);


void __RPC_STUB IPlane_GetDistToForPt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_GetDistToForLine_Proxy( 
    IPlane * This,
    /* [in] */ ILine *i_pLine,
    /* [retval][out] */ DOUBLE *o_dDist);


void __RPC_STUB IPlane_GetDistToForLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_GetDistToForPlane_Proxy( 
    IPlane * This,
    /* [in] */ IPlane *i_pPlane,
    /* [retval][out] */ DOUBLE *o_dDist);


void __RPC_STUB IPlane_GetDistToForPlane_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_GetPerpLn_Proxy( 
    IPlane * This,
    /* [in] */ IXYZ *i_pPt,
    /* [retval][out] */ ILine **o_ppLine);


void __RPC_STUB IPlane_GetPerpLn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_GetPerpPln_Proxy( 
    IPlane * This,
    /* [in] */ ILine *i_pLine,
    /* [retval][out] */ IPlane **o_ppPlane);


void __RPC_STUB IPlane_GetPerpPln_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_GetParlPlnForPt_Proxy( 
    IPlane * This,
    /* [in] */ IXYZ *i_pPt,
    /* [retval][out] */ IPlane **o_ppPlane);


void __RPC_STUB IPlane_GetParlPlnForPt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_GetParlPlnForDis_Proxy( 
    IPlane * This,
    /* [in] */ DOUBLE i_dDist,
    /* [retval][out] */ IPlane **o_ppPlane);


void __RPC_STUB IPlane_GetParlPlnForDis_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_GetAngToPln_Proxy( 
    IPlane * This,
    /* [in] */ IPlane *i_pPlane,
    /* [retval][out] */ DOUBLE *o_dAng);


void __RPC_STUB IPlane_GetAngToPln_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_GetInsctPt_Proxy( 
    IPlane * This,
    /* [in] */ ILine *i_pLine,
    /* [retval][out] */ IXYZ **o_ppPt);


void __RPC_STUB IPlane_GetInsctPt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_GetInsctLn_Proxy( 
    IPlane * This,
    /* [in] */ IPlane *i_pPlane,
    /* [retval][out] */ ILine **o_ppLine);


void __RPC_STUB IPlane_GetInsctLn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_IsLegal_Proxy( 
    IPlane * This,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IPlane_IsLegal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_PutIPlane_Proxy( 
    IPlane * This,
    /* [in] */ IPlane *i_pPln);


void __RPC_STUB IPlane_PutIPlane_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_PutTriPts_Proxy( 
    IPlane * This,
    /* [in] */ IXYZ *i_pPt1,
    /* [in] */ IXYZ *i_pPt2,
    /* [in] */ IXYZ *i_pPt3);


void __RPC_STUB IPlane_PutTriPts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_PutByCoef_Proxy( 
    IPlane * This,
    /* [in] */ DOUBLE i_dA,
    /* [in] */ DOUBLE i_dB,
    /* [in] */ DOUBLE i_dC,
    /* [in] */ DOUBLE i_dD);


void __RPC_STUB IPlane_PutByCoef_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_PutByPtNorm_Proxy( 
    IPlane * This,
    /* [in] */ IXYZ *i_pPt,
    /* [in] */ IVector *i_pNorm);


void __RPC_STUB IPlane_PutByPtNorm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_Save_Proxy( 
    IPlane * This,
    /* [in] */ ICxFiler *i_ipFiler);


void __RPC_STUB IPlane_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IPlane_Load_Proxy( 
    IPlane * This,
    /* [in] */ ICxFiler *i_ipFiler);


void __RPC_STUB IPlane_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPlane_INTERFACE_DEFINED__ */


#ifndef __IMatrix_INTERFACE_DEFINED__
#define __IMatrix_INTERFACE_DEFINED__

/* interface IMatrix */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMatrix;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F54A3035-5903-4D53-A668-A097789BF0F8")
    IMatrix : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCMatrix( 
            /* [retval][out] */ LONG_PTR *o_pplCMatrixAddress) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Put( 
            /* [in] */ SHORT i_iM1,
            /* [in] */ DOUBLE i_Mat[ 4 ][ 4 ]) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutCMatrix( 
            /* [in] */ LONG_PTR i_lCMatrixAddress) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutIMatrix( 
            /* [in] */ IMatrix *i_pMat) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Multi( 
            /* [in] */ IMatrix *i_pMat,
            /* [retval][out] */ IMatrix **o_ppMat) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetOri( 
            /* [in] */ IXYZ *i_pOri) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeXAxTo( 
            /* [in] */ IVector *i_pVecX) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeYAxTo( 
            /* [in] */ IVector *i_pVecY) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeZAxTo( 
            /* [in] */ IVector *i_pVecZ) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPAx( 
            /* [in] */ IVector *i_pVecP) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetScale( 
            /* [in] */ DOUBLE i_dScale) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Get2DArray( 
            /* [retval][out] */ DOUBLE o_dMat[ 4 ][ 4 ]) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetXAx( 
            /* [retval][out] */ IVector **o_ppVecX) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetYAx( 
            /* [retval][out] */ IVector **o_ppVecY) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetZAx( 
            /* [retval][out] */ IVector **o_ppVecZ) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPAx( 
            /* [retval][out] */ IVector **o_ppVecP) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetOri( 
            /* [retval][out] */ IXYZ **o_ppOri) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetScale( 
            /* [retval][out] */ DOUBLE *o_pdScale) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsLegal( 
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Init( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitToXYPlnMat( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitToYZPlnMat( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitToZXPlnMat( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitToVecRotMat( 
            /* [in] */ IVector *i_pStaVec,
            /* [in] */ IVector *i_pEndVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitToCoordPlnMirrorMat( 
            /* [in] */ SHORT i_iXOY,
            /* [in] */ SHORT i_iYOZ,
            /* [in] */ SHORT i_iZOX) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitToPlnMirrorMat( 
            /* [in] */ IPlane *i_pPln) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitToPtMirrorMat( 
            /* [in] */ IXYZ *i_pPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitToScaleMat( 
            /* [in] */ IXYZ *i_pPt,
            /* [in] */ DOUBLE i_dScale) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RotateByAng( 
            /* [in] */ double i_dAngX,
            /* [in] */ double i_dAngY,
            /* [in] */ double i_dAngZ) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Rotate( 
            /* [in] */ double i_dAng,
            /* [in] */ ILine *i_pLine) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitToScaleMatByThreeDir( 
            IXYZ *i_pPt,
            IXYZ *i_pSxyz) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitToTriPtsMat( 
            /* [in] */ IXYZ *i_pP0,
            /* [in] */ IXYZ *i_pP1,
            /* [in] */ IXYZ *i_pP2) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsSame( 
            /* [in] */ IMatrix *i_pMat,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Inverse( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Transpose( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetGlMat( 
            /* [out] */ double *md_pVals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Unit( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetScaleMat( 
            /* [in] */ IXYZ *i_Sxyz) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRotMat( 
            /* [in] */ IXYZ *i_pPt,
            /* [in] */ double i_dRX,
            /* [in] */ double i_dRY,
            /* [in] */ double i_dRZ) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Move( 
            /* [in] */ IXYZ *i_DeltaPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetValue( 
            /* [retval][out] */ double *o_pdVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RotRndX( 
            /* [in] */ double i_dAng) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RotRndY( 
            /* [in] */ double i_dAng) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RotRndZ( 
            /* [in] */ double i_dAng) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutByOriPt( 
            /* [in] */ IXYZ *i_pOriPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutByPtNormVec( 
            /* [in] */ IXYZ *i_pOriPt,
            /* [in] */ IVector *i_pNormVec,
            /* [in] */ LONG i_PlnFlag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutByPtVecXVecZ( 
            /* [in] */ IXYZ *i_pOriPt,
            /* [in] */ IVector *i_pVecX,
            /* [in] */ IVector *i_pVecZ) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ ICxFiler *i_ipFiler) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ ICxFiler *i_ipFiler) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetScaleByPt( 
            /* [in] */ IXYZ *i_pPt,
            /* [in] */ IXYZ *i_pSxyz) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutBy16( 
            /* [in] */ DOUBLE i_Mat[ 16 ]) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRotZAng( 
            /* [out] */ DOUBLE *o_dAng) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMirrorFlag( 
            /* [out] */ VARIANT_BOOL *o_bMirrorFlag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMirrorAngle( 
            /* [out] */ DOUBLE *o_dMirrorAngle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutGiMat( 
            /* [in] */ DOUBLE i_dDisPlayMat[ 16 ]) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetGiMat( 
            /* [out] */ DOUBLE o_dDisPlayMat[ 16 ]) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsUnit( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMatrixVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMatrix * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMatrix * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMatrix * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMatrix * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMatrix * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMatrix * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMatrix * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCMatrix )( 
            IMatrix * This,
            /* [retval][out] */ LONG_PTR *o_pplCMatrixAddress);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Put )( 
            IMatrix * This,
            /* [in] */ SHORT i_iM1,
            /* [in] */ DOUBLE i_Mat[ 4 ][ 4 ]);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutCMatrix )( 
            IMatrix * This,
            /* [in] */ LONG_PTR i_lCMatrixAddress);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutIMatrix )( 
            IMatrix * This,
            /* [in] */ IMatrix *i_pMat);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Multi )( 
            IMatrix * This,
            /* [in] */ IMatrix *i_pMat,
            /* [retval][out] */ IMatrix **o_ppMat);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetOri )( 
            IMatrix * This,
            /* [in] */ IXYZ *i_pOri);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeXAxTo )( 
            IMatrix * This,
            /* [in] */ IVector *i_pVecX);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeYAxTo )( 
            IMatrix * This,
            /* [in] */ IVector *i_pVecY);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeZAxTo )( 
            IMatrix * This,
            /* [in] */ IVector *i_pVecZ);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPAx )( 
            IMatrix * This,
            /* [in] */ IVector *i_pVecP);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetScale )( 
            IMatrix * This,
            /* [in] */ DOUBLE i_dScale);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Get2DArray )( 
            IMatrix * This,
            /* [retval][out] */ DOUBLE o_dMat[ 4 ][ 4 ]);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXAx )( 
            IMatrix * This,
            /* [retval][out] */ IVector **o_ppVecX);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetYAx )( 
            IMatrix * This,
            /* [retval][out] */ IVector **o_ppVecY);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetZAx )( 
            IMatrix * This,
            /* [retval][out] */ IVector **o_ppVecZ);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPAx )( 
            IMatrix * This,
            /* [retval][out] */ IVector **o_ppVecP);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetOri )( 
            IMatrix * This,
            /* [retval][out] */ IXYZ **o_ppOri);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetScale )( 
            IMatrix * This,
            /* [retval][out] */ DOUBLE *o_pdScale);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsLegal )( 
            IMatrix * This,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Init )( 
            IMatrix * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitToXYPlnMat )( 
            IMatrix * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitToYZPlnMat )( 
            IMatrix * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitToZXPlnMat )( 
            IMatrix * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitToVecRotMat )( 
            IMatrix * This,
            /* [in] */ IVector *i_pStaVec,
            /* [in] */ IVector *i_pEndVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitToCoordPlnMirrorMat )( 
            IMatrix * This,
            /* [in] */ SHORT i_iXOY,
            /* [in] */ SHORT i_iYOZ,
            /* [in] */ SHORT i_iZOX);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitToPlnMirrorMat )( 
            IMatrix * This,
            /* [in] */ IPlane *i_pPln);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitToPtMirrorMat )( 
            IMatrix * This,
            /* [in] */ IXYZ *i_pPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitToScaleMat )( 
            IMatrix * This,
            /* [in] */ IXYZ *i_pPt,
            /* [in] */ DOUBLE i_dScale);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RotateByAng )( 
            IMatrix * This,
            /* [in] */ double i_dAngX,
            /* [in] */ double i_dAngY,
            /* [in] */ double i_dAngZ);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            IMatrix * This,
            /* [in] */ double i_dAng,
            /* [in] */ ILine *i_pLine);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitToScaleMatByThreeDir )( 
            IMatrix * This,
            IXYZ *i_pPt,
            IXYZ *i_pSxyz);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitToTriPtsMat )( 
            IMatrix * This,
            /* [in] */ IXYZ *i_pP0,
            /* [in] */ IXYZ *i_pP1,
            /* [in] */ IXYZ *i_pP2);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsSame )( 
            IMatrix * This,
            /* [in] */ IMatrix *i_pMat,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Inverse )( 
            IMatrix * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Transpose )( 
            IMatrix * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetGlMat )( 
            IMatrix * This,
            /* [out] */ double *md_pVals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Unit )( 
            IMatrix * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetScaleMat )( 
            IMatrix * This,
            /* [in] */ IXYZ *i_Sxyz);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetRotMat )( 
            IMatrix * This,
            /* [in] */ IXYZ *i_pPt,
            /* [in] */ double i_dRX,
            /* [in] */ double i_dRY,
            /* [in] */ double i_dRZ);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            IMatrix * This,
            /* [in] */ IXYZ *i_DeltaPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetValue )( 
            IMatrix * This,
            /* [retval][out] */ double *o_pdVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RotRndX )( 
            IMatrix * This,
            /* [in] */ double i_dAng);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RotRndY )( 
            IMatrix * This,
            /* [in] */ double i_dAng);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RotRndZ )( 
            IMatrix * This,
            /* [in] */ double i_dAng);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutByOriPt )( 
            IMatrix * This,
            /* [in] */ IXYZ *i_pOriPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutByPtNormVec )( 
            IMatrix * This,
            /* [in] */ IXYZ *i_pOriPt,
            /* [in] */ IVector *i_pNormVec,
            /* [in] */ LONG i_PlnFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutByPtVecXVecZ )( 
            IMatrix * This,
            /* [in] */ IXYZ *i_pOriPt,
            /* [in] */ IVector *i_pVecX,
            /* [in] */ IVector *i_pVecZ);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IMatrix * This,
            /* [in] */ ICxFiler *i_ipFiler);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IMatrix * This,
            /* [in] */ ICxFiler *i_ipFiler);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetScaleByPt )( 
            IMatrix * This,
            /* [in] */ IXYZ *i_pPt,
            /* [in] */ IXYZ *i_pSxyz);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutBy16 )( 
            IMatrix * This,
            /* [in] */ DOUBLE i_Mat[ 16 ]);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetRotZAng )( 
            IMatrix * This,
            /* [out] */ DOUBLE *o_dAng);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMirrorFlag )( 
            IMatrix * This,
            /* [out] */ VARIANT_BOOL *o_bMirrorFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMirrorAngle )( 
            IMatrix * This,
            /* [out] */ DOUBLE *o_dMirrorAngle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutGiMat )( 
            IMatrix * This,
            /* [in] */ DOUBLE i_dDisPlayMat[ 16 ]);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetGiMat )( 
            IMatrix * This,
            /* [out] */ DOUBLE o_dDisPlayMat[ 16 ]);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsUnit )( 
            IMatrix * This);
        
        END_INTERFACE
    } IMatrixVtbl;

    interface IMatrix
    {
        CONST_VTBL struct IMatrixVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMatrix_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMatrix_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMatrix_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMatrix_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IMatrix_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IMatrix_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IMatrix_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IMatrix_GetCMatrix(This,o_pplCMatrixAddress)	\
    (This)->lpVtbl -> GetCMatrix(This,o_pplCMatrixAddress)

#define IMatrix_Put(This,i_iM1,i_Mat)	\
    (This)->lpVtbl -> Put(This,i_iM1,i_Mat)

#define IMatrix_PutCMatrix(This,i_lCMatrixAddress)	\
    (This)->lpVtbl -> PutCMatrix(This,i_lCMatrixAddress)

#define IMatrix_PutIMatrix(This,i_pMat)	\
    (This)->lpVtbl -> PutIMatrix(This,i_pMat)

#define IMatrix_Multi(This,i_pMat,o_ppMat)	\
    (This)->lpVtbl -> Multi(This,i_pMat,o_ppMat)

#define IMatrix_SetOri(This,i_pOri)	\
    (This)->lpVtbl -> SetOri(This,i_pOri)

#define IMatrix_ChangeXAxTo(This,i_pVecX)	\
    (This)->lpVtbl -> ChangeXAxTo(This,i_pVecX)

#define IMatrix_ChangeYAxTo(This,i_pVecY)	\
    (This)->lpVtbl -> ChangeYAxTo(This,i_pVecY)

#define IMatrix_ChangeZAxTo(This,i_pVecZ)	\
    (This)->lpVtbl -> ChangeZAxTo(This,i_pVecZ)

#define IMatrix_SetPAx(This,i_pVecP)	\
    (This)->lpVtbl -> SetPAx(This,i_pVecP)

#define IMatrix_SetScale(This,i_dScale)	\
    (This)->lpVtbl -> SetScale(This,i_dScale)

#define IMatrix_Get2DArray(This,o_dMat)	\
    (This)->lpVtbl -> Get2DArray(This,o_dMat)

#define IMatrix_GetXAx(This,o_ppVecX)	\
    (This)->lpVtbl -> GetXAx(This,o_ppVecX)

#define IMatrix_GetYAx(This,o_ppVecY)	\
    (This)->lpVtbl -> GetYAx(This,o_ppVecY)

#define IMatrix_GetZAx(This,o_ppVecZ)	\
    (This)->lpVtbl -> GetZAx(This,o_ppVecZ)

#define IMatrix_GetPAx(This,o_ppVecP)	\
    (This)->lpVtbl -> GetPAx(This,o_ppVecP)

#define IMatrix_GetOri(This,o_ppOri)	\
    (This)->lpVtbl -> GetOri(This,o_ppOri)

#define IMatrix_GetScale(This,o_pdScale)	\
    (This)->lpVtbl -> GetScale(This,o_pdScale)

#define IMatrix_IsLegal(This,o_pbVal)	\
    (This)->lpVtbl -> IsLegal(This,o_pbVal)

#define IMatrix_Init(This)	\
    (This)->lpVtbl -> Init(This)

#define IMatrix_InitToXYPlnMat(This)	\
    (This)->lpVtbl -> InitToXYPlnMat(This)

#define IMatrix_InitToYZPlnMat(This)	\
    (This)->lpVtbl -> InitToYZPlnMat(This)

#define IMatrix_InitToZXPlnMat(This)	\
    (This)->lpVtbl -> InitToZXPlnMat(This)

#define IMatrix_InitToVecRotMat(This,i_pStaVec,i_pEndVec)	\
    (This)->lpVtbl -> InitToVecRotMat(This,i_pStaVec,i_pEndVec)

#define IMatrix_InitToCoordPlnMirrorMat(This,i_iXOY,i_iYOZ,i_iZOX)	\
    (This)->lpVtbl -> InitToCoordPlnMirrorMat(This,i_iXOY,i_iYOZ,i_iZOX)

#define IMatrix_InitToPlnMirrorMat(This,i_pPln)	\
    (This)->lpVtbl -> InitToPlnMirrorMat(This,i_pPln)

#define IMatrix_InitToPtMirrorMat(This,i_pPt)	\
    (This)->lpVtbl -> InitToPtMirrorMat(This,i_pPt)

#define IMatrix_InitToScaleMat(This,i_pPt,i_dScale)	\
    (This)->lpVtbl -> InitToScaleMat(This,i_pPt,i_dScale)

#define IMatrix_RotateByAng(This,i_dAngX,i_dAngY,i_dAngZ)	\
    (This)->lpVtbl -> RotateByAng(This,i_dAngX,i_dAngY,i_dAngZ)

#define IMatrix_Rotate(This,i_dAng,i_pLine)	\
    (This)->lpVtbl -> Rotate(This,i_dAng,i_pLine)

#define IMatrix_InitToScaleMatByThreeDir(This,i_pPt,i_pSxyz)	\
    (This)->lpVtbl -> InitToScaleMatByThreeDir(This,i_pPt,i_pSxyz)

#define IMatrix_InitToTriPtsMat(This,i_pP0,i_pP1,i_pP2)	\
    (This)->lpVtbl -> InitToTriPtsMat(This,i_pP0,i_pP1,i_pP2)

#define IMatrix_IsSame(This,i_pMat,o_pbVal)	\
    (This)->lpVtbl -> IsSame(This,i_pMat,o_pbVal)

#define IMatrix_Inverse(This)	\
    (This)->lpVtbl -> Inverse(This)

#define IMatrix_Transpose(This)	\
    (This)->lpVtbl -> Transpose(This)

#define IMatrix_GetGlMat(This,md_pVals)	\
    (This)->lpVtbl -> GetGlMat(This,md_pVals)

#define IMatrix_Unit(This)	\
    (This)->lpVtbl -> Unit(This)

#define IMatrix_GetScaleMat(This,i_Sxyz)	\
    (This)->lpVtbl -> GetScaleMat(This,i_Sxyz)

#define IMatrix_GetRotMat(This,i_pPt,i_dRX,i_dRY,i_dRZ)	\
    (This)->lpVtbl -> GetRotMat(This,i_pPt,i_dRX,i_dRY,i_dRZ)

#define IMatrix_Move(This,i_DeltaPt)	\
    (This)->lpVtbl -> Move(This,i_DeltaPt)

#define IMatrix_GetValue(This,o_pdVal)	\
    (This)->lpVtbl -> GetValue(This,o_pdVal)

#define IMatrix_RotRndX(This,i_dAng)	\
    (This)->lpVtbl -> RotRndX(This,i_dAng)

#define IMatrix_RotRndY(This,i_dAng)	\
    (This)->lpVtbl -> RotRndY(This,i_dAng)

#define IMatrix_RotRndZ(This,i_dAng)	\
    (This)->lpVtbl -> RotRndZ(This,i_dAng)

#define IMatrix_PutByOriPt(This,i_pOriPt)	\
    (This)->lpVtbl -> PutByOriPt(This,i_pOriPt)

#define IMatrix_PutByPtNormVec(This,i_pOriPt,i_pNormVec,i_PlnFlag)	\
    (This)->lpVtbl -> PutByPtNormVec(This,i_pOriPt,i_pNormVec,i_PlnFlag)

#define IMatrix_PutByPtVecXVecZ(This,i_pOriPt,i_pVecX,i_pVecZ)	\
    (This)->lpVtbl -> PutByPtVecXVecZ(This,i_pOriPt,i_pVecX,i_pVecZ)

#define IMatrix_Save(This,i_ipFiler)	\
    (This)->lpVtbl -> Save(This,i_ipFiler)

#define IMatrix_Load(This,i_ipFiler)	\
    (This)->lpVtbl -> Load(This,i_ipFiler)

#define IMatrix_SetScaleByPt(This,i_pPt,i_pSxyz)	\
    (This)->lpVtbl -> SetScaleByPt(This,i_pPt,i_pSxyz)

#define IMatrix_PutBy16(This,i_Mat)	\
    (This)->lpVtbl -> PutBy16(This,i_Mat)

#define IMatrix_GetRotZAng(This,o_dAng)	\
    (This)->lpVtbl -> GetRotZAng(This,o_dAng)

#define IMatrix_GetMirrorFlag(This,o_bMirrorFlag)	\
    (This)->lpVtbl -> GetMirrorFlag(This,o_bMirrorFlag)

#define IMatrix_GetMirrorAngle(This,o_dMirrorAngle)	\
    (This)->lpVtbl -> GetMirrorAngle(This,o_dMirrorAngle)

#define IMatrix_PutGiMat(This,i_dDisPlayMat)	\
    (This)->lpVtbl -> PutGiMat(This,i_dDisPlayMat)

#define IMatrix_GetGiMat(This,o_dDisPlayMat)	\
    (This)->lpVtbl -> GetGiMat(This,o_dDisPlayMat)

#define IMatrix_IsUnit(This)	\
    (This)->lpVtbl -> IsUnit(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_GetCMatrix_Proxy( 
    IMatrix * This,
    /* [retval][out] */ LONG_PTR *o_pplCMatrixAddress);


void __RPC_STUB IMatrix_GetCMatrix_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_Put_Proxy( 
    IMatrix * This,
    /* [in] */ SHORT i_iM1,
    /* [in] */ DOUBLE i_Mat[ 4 ][ 4 ]);


void __RPC_STUB IMatrix_Put_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_PutCMatrix_Proxy( 
    IMatrix * This,
    /* [in] */ LONG_PTR i_lCMatrixAddress);


void __RPC_STUB IMatrix_PutCMatrix_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_PutIMatrix_Proxy( 
    IMatrix * This,
    /* [in] */ IMatrix *i_pMat);


void __RPC_STUB IMatrix_PutIMatrix_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_Multi_Proxy( 
    IMatrix * This,
    /* [in] */ IMatrix *i_pMat,
    /* [retval][out] */ IMatrix **o_ppMat);


void __RPC_STUB IMatrix_Multi_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_SetOri_Proxy( 
    IMatrix * This,
    /* [in] */ IXYZ *i_pOri);


void __RPC_STUB IMatrix_SetOri_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_ChangeXAxTo_Proxy( 
    IMatrix * This,
    /* [in] */ IVector *i_pVecX);


void __RPC_STUB IMatrix_ChangeXAxTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_ChangeYAxTo_Proxy( 
    IMatrix * This,
    /* [in] */ IVector *i_pVecY);


void __RPC_STUB IMatrix_ChangeYAxTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_ChangeZAxTo_Proxy( 
    IMatrix * This,
    /* [in] */ IVector *i_pVecZ);


void __RPC_STUB IMatrix_ChangeZAxTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_SetPAx_Proxy( 
    IMatrix * This,
    /* [in] */ IVector *i_pVecP);


void __RPC_STUB IMatrix_SetPAx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_SetScale_Proxy( 
    IMatrix * This,
    /* [in] */ DOUBLE i_dScale);


void __RPC_STUB IMatrix_SetScale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_Get2DArray_Proxy( 
    IMatrix * This,
    /* [retval][out] */ DOUBLE o_dMat[ 4 ][ 4 ]);


void __RPC_STUB IMatrix_Get2DArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_GetXAx_Proxy( 
    IMatrix * This,
    /* [retval][out] */ IVector **o_ppVecX);


void __RPC_STUB IMatrix_GetXAx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_GetYAx_Proxy( 
    IMatrix * This,
    /* [retval][out] */ IVector **o_ppVecY);


void __RPC_STUB IMatrix_GetYAx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_GetZAx_Proxy( 
    IMatrix * This,
    /* [retval][out] */ IVector **o_ppVecZ);


void __RPC_STUB IMatrix_GetZAx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_GetPAx_Proxy( 
    IMatrix * This,
    /* [retval][out] */ IVector **o_ppVecP);


void __RPC_STUB IMatrix_GetPAx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_GetOri_Proxy( 
    IMatrix * This,
    /* [retval][out] */ IXYZ **o_ppOri);


void __RPC_STUB IMatrix_GetOri_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_GetScale_Proxy( 
    IMatrix * This,
    /* [retval][out] */ DOUBLE *o_pdScale);


void __RPC_STUB IMatrix_GetScale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_IsLegal_Proxy( 
    IMatrix * This,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IMatrix_IsLegal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_Init_Proxy( 
    IMatrix * This);


void __RPC_STUB IMatrix_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_InitToXYPlnMat_Proxy( 
    IMatrix * This);


void __RPC_STUB IMatrix_InitToXYPlnMat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_InitToYZPlnMat_Proxy( 
    IMatrix * This);


void __RPC_STUB IMatrix_InitToYZPlnMat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_InitToZXPlnMat_Proxy( 
    IMatrix * This);


void __RPC_STUB IMatrix_InitToZXPlnMat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_InitToVecRotMat_Proxy( 
    IMatrix * This,
    /* [in] */ IVector *i_pStaVec,
    /* [in] */ IVector *i_pEndVec);


void __RPC_STUB IMatrix_InitToVecRotMat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_InitToCoordPlnMirrorMat_Proxy( 
    IMatrix * This,
    /* [in] */ SHORT i_iXOY,
    /* [in] */ SHORT i_iYOZ,
    /* [in] */ SHORT i_iZOX);


void __RPC_STUB IMatrix_InitToCoordPlnMirrorMat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_InitToPlnMirrorMat_Proxy( 
    IMatrix * This,
    /* [in] */ IPlane *i_pPln);


void __RPC_STUB IMatrix_InitToPlnMirrorMat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_InitToPtMirrorMat_Proxy( 
    IMatrix * This,
    /* [in] */ IXYZ *i_pPt);


void __RPC_STUB IMatrix_InitToPtMirrorMat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_InitToScaleMat_Proxy( 
    IMatrix * This,
    /* [in] */ IXYZ *i_pPt,
    /* [in] */ DOUBLE i_dScale);


void __RPC_STUB IMatrix_InitToScaleMat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_RotateByAng_Proxy( 
    IMatrix * This,
    /* [in] */ double i_dAngX,
    /* [in] */ double i_dAngY,
    /* [in] */ double i_dAngZ);


void __RPC_STUB IMatrix_RotateByAng_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_Rotate_Proxy( 
    IMatrix * This,
    /* [in] */ double i_dAng,
    /* [in] */ ILine *i_pLine);


void __RPC_STUB IMatrix_Rotate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_InitToScaleMatByThreeDir_Proxy( 
    IMatrix * This,
    IXYZ *i_pPt,
    IXYZ *i_pSxyz);


void __RPC_STUB IMatrix_InitToScaleMatByThreeDir_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_InitToTriPtsMat_Proxy( 
    IMatrix * This,
    /* [in] */ IXYZ *i_pP0,
    /* [in] */ IXYZ *i_pP1,
    /* [in] */ IXYZ *i_pP2);


void __RPC_STUB IMatrix_InitToTriPtsMat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_IsSame_Proxy( 
    IMatrix * This,
    /* [in] */ IMatrix *i_pMat,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IMatrix_IsSame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_Inverse_Proxy( 
    IMatrix * This);


void __RPC_STUB IMatrix_Inverse_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_Transpose_Proxy( 
    IMatrix * This);


void __RPC_STUB IMatrix_Transpose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_GetGlMat_Proxy( 
    IMatrix * This,
    /* [out] */ double *md_pVals);


void __RPC_STUB IMatrix_GetGlMat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_Unit_Proxy( 
    IMatrix * This);


void __RPC_STUB IMatrix_Unit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_GetScaleMat_Proxy( 
    IMatrix * This,
    /* [in] */ IXYZ *i_Sxyz);


void __RPC_STUB IMatrix_GetScaleMat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_GetRotMat_Proxy( 
    IMatrix * This,
    /* [in] */ IXYZ *i_pPt,
    /* [in] */ double i_dRX,
    /* [in] */ double i_dRY,
    /* [in] */ double i_dRZ);


void __RPC_STUB IMatrix_GetRotMat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_Move_Proxy( 
    IMatrix * This,
    /* [in] */ IXYZ *i_DeltaPt);


void __RPC_STUB IMatrix_Move_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_GetValue_Proxy( 
    IMatrix * This,
    /* [retval][out] */ double *o_pdVal);


void __RPC_STUB IMatrix_GetValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_RotRndX_Proxy( 
    IMatrix * This,
    /* [in] */ double i_dAng);


void __RPC_STUB IMatrix_RotRndX_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_RotRndY_Proxy( 
    IMatrix * This,
    /* [in] */ double i_dAng);


void __RPC_STUB IMatrix_RotRndY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_RotRndZ_Proxy( 
    IMatrix * This,
    /* [in] */ double i_dAng);


void __RPC_STUB IMatrix_RotRndZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_PutByOriPt_Proxy( 
    IMatrix * This,
    /* [in] */ IXYZ *i_pOriPt);


void __RPC_STUB IMatrix_PutByOriPt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_PutByPtNormVec_Proxy( 
    IMatrix * This,
    /* [in] */ IXYZ *i_pOriPt,
    /* [in] */ IVector *i_pNormVec,
    /* [in] */ LONG i_PlnFlag);


void __RPC_STUB IMatrix_PutByPtNormVec_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_PutByPtVecXVecZ_Proxy( 
    IMatrix * This,
    /* [in] */ IXYZ *i_pOriPt,
    /* [in] */ IVector *i_pVecX,
    /* [in] */ IVector *i_pVecZ);


void __RPC_STUB IMatrix_PutByPtVecXVecZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_Save_Proxy( 
    IMatrix * This,
    /* [in] */ ICxFiler *i_ipFiler);


void __RPC_STUB IMatrix_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_Load_Proxy( 
    IMatrix * This,
    /* [in] */ ICxFiler *i_ipFiler);


void __RPC_STUB IMatrix_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_SetScaleByPt_Proxy( 
    IMatrix * This,
    /* [in] */ IXYZ *i_pPt,
    /* [in] */ IXYZ *i_pSxyz);


void __RPC_STUB IMatrix_SetScaleByPt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_PutBy16_Proxy( 
    IMatrix * This,
    /* [in] */ DOUBLE i_Mat[ 16 ]);


void __RPC_STUB IMatrix_PutBy16_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_GetRotZAng_Proxy( 
    IMatrix * This,
    /* [out] */ DOUBLE *o_dAng);


void __RPC_STUB IMatrix_GetRotZAng_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_GetMirrorFlag_Proxy( 
    IMatrix * This,
    /* [out] */ VARIANT_BOOL *o_bMirrorFlag);


void __RPC_STUB IMatrix_GetMirrorFlag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_GetMirrorAngle_Proxy( 
    IMatrix * This,
    /* [out] */ DOUBLE *o_dMirrorAngle);


void __RPC_STUB IMatrix_GetMirrorAngle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_PutGiMat_Proxy( 
    IMatrix * This,
    /* [in] */ DOUBLE i_dDisPlayMat[ 16 ]);


void __RPC_STUB IMatrix_PutGiMat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_GetGiMat_Proxy( 
    IMatrix * This,
    /* [out] */ DOUBLE o_dDisPlayMat[ 16 ]);


void __RPC_STUB IMatrix_GetGiMat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMatrix_IsUnit_Proxy( 
    IMatrix * This);


void __RPC_STUB IMatrix_IsUnit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMatrix_INTERFACE_DEFINED__ */


#ifndef __IBox_INTERFACE_DEFINED__
#define __IBox_INTERFACE_DEFINED__

/* interface IBox */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IBox;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("89BCEE5B-F490-4B8E-A165-47966D583ACD")
    IBox : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCBox( 
            /* [retval][out] */ LONG_PTR *o_pplCBoxAddress) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMaxPos( 
            /* [in] */ IXYZ *i_pMaxPosPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMinPos( 
            /* [in] */ IXYZ *i_pMinPosPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMaxPos( 
            /* [out] */ IXYZ **o_ppMaxPosPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMinPos( 
            /* [out] */ IXYZ **o_ppMinPosPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Init( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Scale( 
            /* [in] */ DOUBLE i_dScale,
            /* [in] */ IXYZ *i_pDtmPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Mirror( 
            /* [in] */ IPlane *i_pMirrorPln,
            /* [retval][out] */ IBox **o_ppBox) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsSame( 
            /* [in] */ IBox *i_pBox,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsIn( 
            /* [in] */ IBox *i_pBox,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IfIntWith( 
            /* [in] */ IBox *i_pBox,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IfIntWithFor3( 
            /* [in] */ IBox *i_pBox0,
            /* [in] */ IBox *i_pBox1,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IfPtIn( 
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMinDistByDir( 
            /* [in] */ IBox *i_pBox,
            /* [in] */ IVector *i_pDirVec,
            /* [retval][out] */ DOUBLE *o_dDist) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnionByXYZ( 
            /* [in] */ IXYZ *i_pPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnionByBox( 
            /* [in] */ IBox *i_pBox) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Trans( 
            /* [in] */ IMatrix *i_pMat) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsLegal( 
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnionByXYZs( 
            /* [in] */ IXYZArray *i_pPts,
            /* [in] */ int i_iNum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutIBox( 
            /* [in] */ IBox *i_pBox) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ ICxFiler *i_ipFiler) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ ICxFiler *i_ipFiler) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMinPosCoord( 
            /* [out] */ double *pdx,
            /* [out] */ double *pdy,
            /* [out] */ double *pdz) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMaxPosCoord( 
            /* [out] */ double *pdx,
            /* [out] */ double *pdy,
            /* [out] */ double *pdz) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMinPosCoord( 
            /* [in] */ double dx,
            /* [in] */ double dy,
            /* [in] */ double dz) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMaxPosCoord( 
            /* [in] */ double dx,
            /* [in] */ double dy,
            /* [in] */ double dz) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TransAsRect( 
            /* [in] */ IMatrix *i_pMat) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnionByXYZCoord( 
            /* [in] */ double dx,
            /* [in] */ double dy,
            /* [in] */ double dz) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsOutBox( 
            IBox *i_ipBox,
            VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnionByBoxCoord( 
            /* [in] */ double dMinX,
            /* [in] */ double dMinY,
            /* [in] */ double dMaxX,
            /* [in] */ double dMaxY) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsOutBoxByCoord( 
            /* [in] */ double i_dMinX,
            /* [in] */ double i_dMinY,
            /* [in] */ double i_dMaxX,
            /* [in] */ double i_dMaxY,
            /* [out] */ VARIANT_BOOL *o_pbVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBoxVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBox * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBox * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBox * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IBox * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IBox * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IBox * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IBox * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCBox )( 
            IBox * This,
            /* [retval][out] */ LONG_PTR *o_pplCBoxAddress);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetMaxPos )( 
            IBox * This,
            /* [in] */ IXYZ *i_pMaxPosPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetMinPos )( 
            IBox * This,
            /* [in] */ IXYZ *i_pMinPosPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMaxPos )( 
            IBox * This,
            /* [out] */ IXYZ **o_ppMaxPosPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMinPos )( 
            IBox * This,
            /* [out] */ IXYZ **o_ppMinPosPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Init )( 
            IBox * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Scale )( 
            IBox * This,
            /* [in] */ DOUBLE i_dScale,
            /* [in] */ IXYZ *i_pDtmPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror )( 
            IBox * This,
            /* [in] */ IPlane *i_pMirrorPln,
            /* [retval][out] */ IBox **o_ppBox);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsSame )( 
            IBox * This,
            /* [in] */ IBox *i_pBox,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsIn )( 
            IBox * This,
            /* [in] */ IBox *i_pBox,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IfIntWith )( 
            IBox * This,
            /* [in] */ IBox *i_pBox,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IfIntWithFor3 )( 
            IBox * This,
            /* [in] */ IBox *i_pBox0,
            /* [in] */ IBox *i_pBox1,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IfPtIn )( 
            IBox * This,
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMinDistByDir )( 
            IBox * This,
            /* [in] */ IBox *i_pBox,
            /* [in] */ IVector *i_pDirVec,
            /* [retval][out] */ DOUBLE *o_dDist);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnionByXYZ )( 
            IBox * This,
            /* [in] */ IXYZ *i_pPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnionByBox )( 
            IBox * This,
            /* [in] */ IBox *i_pBox);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Trans )( 
            IBox * This,
            /* [in] */ IMatrix *i_pMat);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsLegal )( 
            IBox * This,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnionByXYZs )( 
            IBox * This,
            /* [in] */ IXYZArray *i_pPts,
            /* [in] */ int i_iNum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutIBox )( 
            IBox * This,
            /* [in] */ IBox *i_pBox);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IBox * This,
            /* [in] */ ICxFiler *i_ipFiler);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IBox * This,
            /* [in] */ ICxFiler *i_ipFiler);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMinPosCoord )( 
            IBox * This,
            /* [out] */ double *pdx,
            /* [out] */ double *pdy,
            /* [out] */ double *pdz);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMaxPosCoord )( 
            IBox * This,
            /* [out] */ double *pdx,
            /* [out] */ double *pdy,
            /* [out] */ double *pdz);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetMinPosCoord )( 
            IBox * This,
            /* [in] */ double dx,
            /* [in] */ double dy,
            /* [in] */ double dz);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetMaxPosCoord )( 
            IBox * This,
            /* [in] */ double dx,
            /* [in] */ double dy,
            /* [in] */ double dz);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransAsRect )( 
            IBox * This,
            /* [in] */ IMatrix *i_pMat);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnionByXYZCoord )( 
            IBox * This,
            /* [in] */ double dx,
            /* [in] */ double dy,
            /* [in] */ double dz);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsOutBox )( 
            IBox * This,
            IBox *i_ipBox,
            VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnionByBoxCoord )( 
            IBox * This,
            /* [in] */ double dMinX,
            /* [in] */ double dMinY,
            /* [in] */ double dMaxX,
            /* [in] */ double dMaxY);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsOutBoxByCoord )( 
            IBox * This,
            /* [in] */ double i_dMinX,
            /* [in] */ double i_dMinY,
            /* [in] */ double i_dMaxX,
            /* [in] */ double i_dMaxY,
            /* [out] */ VARIANT_BOOL *o_pbVal);
        
        END_INTERFACE
    } IBoxVtbl;

    interface IBox
    {
        CONST_VTBL struct IBoxVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBox_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBox_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBox_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBox_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IBox_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IBox_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IBox_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IBox_GetCBox(This,o_pplCBoxAddress)	\
    (This)->lpVtbl -> GetCBox(This,o_pplCBoxAddress)

#define IBox_SetMaxPos(This,i_pMaxPosPt)	\
    (This)->lpVtbl -> SetMaxPos(This,i_pMaxPosPt)

#define IBox_SetMinPos(This,i_pMinPosPt)	\
    (This)->lpVtbl -> SetMinPos(This,i_pMinPosPt)

#define IBox_GetMaxPos(This,o_ppMaxPosPt)	\
    (This)->lpVtbl -> GetMaxPos(This,o_ppMaxPosPt)

#define IBox_GetMinPos(This,o_ppMinPosPt)	\
    (This)->lpVtbl -> GetMinPos(This,o_ppMinPosPt)

#define IBox_Init(This)	\
    (This)->lpVtbl -> Init(This)

#define IBox_Scale(This,i_dScale,i_pDtmPt)	\
    (This)->lpVtbl -> Scale(This,i_dScale,i_pDtmPt)

#define IBox_Mirror(This,i_pMirrorPln,o_ppBox)	\
    (This)->lpVtbl -> Mirror(This,i_pMirrorPln,o_ppBox)

#define IBox_IsSame(This,i_pBox,o_pbVal)	\
    (This)->lpVtbl -> IsSame(This,i_pBox,o_pbVal)

#define IBox_IsIn(This,i_pBox,o_pbVal)	\
    (This)->lpVtbl -> IsIn(This,i_pBox,o_pbVal)

#define IBox_IfIntWith(This,i_pBox,o_pbVal)	\
    (This)->lpVtbl -> IfIntWith(This,i_pBox,o_pbVal)

#define IBox_IfIntWithFor3(This,i_pBox0,i_pBox1,o_pbVal)	\
    (This)->lpVtbl -> IfIntWithFor3(This,i_pBox0,i_pBox1,o_pbVal)

#define IBox_IfPtIn(This,i_pPt,o_pbVal)	\
    (This)->lpVtbl -> IfPtIn(This,i_pPt,o_pbVal)

#define IBox_GetMinDistByDir(This,i_pBox,i_pDirVec,o_dDist)	\
    (This)->lpVtbl -> GetMinDistByDir(This,i_pBox,i_pDirVec,o_dDist)

#define IBox_UnionByXYZ(This,i_pPt)	\
    (This)->lpVtbl -> UnionByXYZ(This,i_pPt)

#define IBox_UnionByBox(This,i_pBox)	\
    (This)->lpVtbl -> UnionByBox(This,i_pBox)

#define IBox_Trans(This,i_pMat)	\
    (This)->lpVtbl -> Trans(This,i_pMat)

#define IBox_IsLegal(This,o_pbVal)	\
    (This)->lpVtbl -> IsLegal(This,o_pbVal)

#define IBox_UnionByXYZs(This,i_pPts,i_iNum)	\
    (This)->lpVtbl -> UnionByXYZs(This,i_pPts,i_iNum)

#define IBox_PutIBox(This,i_pBox)	\
    (This)->lpVtbl -> PutIBox(This,i_pBox)

#define IBox_Save(This,i_ipFiler)	\
    (This)->lpVtbl -> Save(This,i_ipFiler)

#define IBox_Load(This,i_ipFiler)	\
    (This)->lpVtbl -> Load(This,i_ipFiler)

#define IBox_GetMinPosCoord(This,pdx,pdy,pdz)	\
    (This)->lpVtbl -> GetMinPosCoord(This,pdx,pdy,pdz)

#define IBox_GetMaxPosCoord(This,pdx,pdy,pdz)	\
    (This)->lpVtbl -> GetMaxPosCoord(This,pdx,pdy,pdz)

#define IBox_SetMinPosCoord(This,dx,dy,dz)	\
    (This)->lpVtbl -> SetMinPosCoord(This,dx,dy,dz)

#define IBox_SetMaxPosCoord(This,dx,dy,dz)	\
    (This)->lpVtbl -> SetMaxPosCoord(This,dx,dy,dz)

#define IBox_TransAsRect(This,i_pMat)	\
    (This)->lpVtbl -> TransAsRect(This,i_pMat)

#define IBox_UnionByXYZCoord(This,dx,dy,dz)	\
    (This)->lpVtbl -> UnionByXYZCoord(This,dx,dy,dz)

#define IBox_IsOutBox(This,i_ipBox,o_pbVal)	\
    (This)->lpVtbl -> IsOutBox(This,i_ipBox,o_pbVal)

#define IBox_UnionByBoxCoord(This,dMinX,dMinY,dMaxX,dMaxY)	\
    (This)->lpVtbl -> UnionByBoxCoord(This,dMinX,dMinY,dMaxX,dMaxY)

#define IBox_IsOutBoxByCoord(This,i_dMinX,i_dMinY,i_dMaxX,i_dMaxY,o_pbVal)	\
    (This)->lpVtbl -> IsOutBoxByCoord(This,i_dMinX,i_dMinY,i_dMaxX,i_dMaxY,o_pbVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_GetCBox_Proxy( 
    IBox * This,
    /* [retval][out] */ LONG_PTR *o_pplCBoxAddress);


void __RPC_STUB IBox_GetCBox_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_SetMaxPos_Proxy( 
    IBox * This,
    /* [in] */ IXYZ *i_pMaxPosPt);


void __RPC_STUB IBox_SetMaxPos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_SetMinPos_Proxy( 
    IBox * This,
    /* [in] */ IXYZ *i_pMinPosPt);


void __RPC_STUB IBox_SetMinPos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_GetMaxPos_Proxy( 
    IBox * This,
    /* [out] */ IXYZ **o_ppMaxPosPt);


void __RPC_STUB IBox_GetMaxPos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_GetMinPos_Proxy( 
    IBox * This,
    /* [out] */ IXYZ **o_ppMinPosPt);


void __RPC_STUB IBox_GetMinPos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_Init_Proxy( 
    IBox * This);


void __RPC_STUB IBox_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_Scale_Proxy( 
    IBox * This,
    /* [in] */ DOUBLE i_dScale,
    /* [in] */ IXYZ *i_pDtmPt);


void __RPC_STUB IBox_Scale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_Mirror_Proxy( 
    IBox * This,
    /* [in] */ IPlane *i_pMirrorPln,
    /* [retval][out] */ IBox **o_ppBox);


void __RPC_STUB IBox_Mirror_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_IsSame_Proxy( 
    IBox * This,
    /* [in] */ IBox *i_pBox,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IBox_IsSame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_IsIn_Proxy( 
    IBox * This,
    /* [in] */ IBox *i_pBox,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IBox_IsIn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_IfIntWith_Proxy( 
    IBox * This,
    /* [in] */ IBox *i_pBox,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IBox_IfIntWith_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_IfIntWithFor3_Proxy( 
    IBox * This,
    /* [in] */ IBox *i_pBox0,
    /* [in] */ IBox *i_pBox1,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IBox_IfIntWithFor3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_IfPtIn_Proxy( 
    IBox * This,
    /* [in] */ IXYZ *i_pPt,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IBox_IfPtIn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_GetMinDistByDir_Proxy( 
    IBox * This,
    /* [in] */ IBox *i_pBox,
    /* [in] */ IVector *i_pDirVec,
    /* [retval][out] */ DOUBLE *o_dDist);


void __RPC_STUB IBox_GetMinDistByDir_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_UnionByXYZ_Proxy( 
    IBox * This,
    /* [in] */ IXYZ *i_pPt);


void __RPC_STUB IBox_UnionByXYZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_UnionByBox_Proxy( 
    IBox * This,
    /* [in] */ IBox *i_pBox);


void __RPC_STUB IBox_UnionByBox_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_Trans_Proxy( 
    IBox * This,
    /* [in] */ IMatrix *i_pMat);


void __RPC_STUB IBox_Trans_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_IsLegal_Proxy( 
    IBox * This,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IBox_IsLegal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_UnionByXYZs_Proxy( 
    IBox * This,
    /* [in] */ IXYZArray *i_pPts,
    /* [in] */ int i_iNum);


void __RPC_STUB IBox_UnionByXYZs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_PutIBox_Proxy( 
    IBox * This,
    /* [in] */ IBox *i_pBox);


void __RPC_STUB IBox_PutIBox_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_Save_Proxy( 
    IBox * This,
    /* [in] */ ICxFiler *i_ipFiler);


void __RPC_STUB IBox_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_Load_Proxy( 
    IBox * This,
    /* [in] */ ICxFiler *i_ipFiler);


void __RPC_STUB IBox_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_GetMinPosCoord_Proxy( 
    IBox * This,
    /* [out] */ double *pdx,
    /* [out] */ double *pdy,
    /* [out] */ double *pdz);


void __RPC_STUB IBox_GetMinPosCoord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_GetMaxPosCoord_Proxy( 
    IBox * This,
    /* [out] */ double *pdx,
    /* [out] */ double *pdy,
    /* [out] */ double *pdz);


void __RPC_STUB IBox_GetMaxPosCoord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_SetMinPosCoord_Proxy( 
    IBox * This,
    /* [in] */ double dx,
    /* [in] */ double dy,
    /* [in] */ double dz);


void __RPC_STUB IBox_SetMinPosCoord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_SetMaxPosCoord_Proxy( 
    IBox * This,
    /* [in] */ double dx,
    /* [in] */ double dy,
    /* [in] */ double dz);


void __RPC_STUB IBox_SetMaxPosCoord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_TransAsRect_Proxy( 
    IBox * This,
    /* [in] */ IMatrix *i_pMat);


void __RPC_STUB IBox_TransAsRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_UnionByXYZCoord_Proxy( 
    IBox * This,
    /* [in] */ double dx,
    /* [in] */ double dy,
    /* [in] */ double dz);


void __RPC_STUB IBox_UnionByXYZCoord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_IsOutBox_Proxy( 
    IBox * This,
    IBox *i_ipBox,
    VARIANT_BOOL *o_pbVal);


void __RPC_STUB IBox_IsOutBox_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_UnionByBoxCoord_Proxy( 
    IBox * This,
    /* [in] */ double dMinX,
    /* [in] */ double dMinY,
    /* [in] */ double dMaxX,
    /* [in] */ double dMaxY);


void __RPC_STUB IBox_UnionByBoxCoord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBox_IsOutBoxByCoord_Proxy( 
    IBox * This,
    /* [in] */ double i_dMinX,
    /* [in] */ double i_dMinY,
    /* [in] */ double i_dMaxX,
    /* [in] */ double i_dMaxY,
    /* [out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IBox_IsOutBoxByCoord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBox_INTERFACE_DEFINED__ */


#ifndef __IXYZW_INTERFACE_DEFINED__
#define __IXYZW_INTERFACE_DEFINED__

/* interface IXYZW */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IXYZW;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D568534C-9257-4342-B56A-F0CB702ACD0F")
    IXYZW : public IXYZ
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCXYZW( 
            /* [retval][out] */ LONG_PTR *o_pplCXYZWAddress) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsSame( 
            /* [in] */ IXYZW *i_pXYZW,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TransToHomogen( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TransFromHomogenTo3D( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ ICxFiler *i_ipFiler) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ ICxFiler *i_ipFiler) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutW( 
            /* [in] */ DOUBLE i_dW) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetW( 
            /* [out] */ DOUBLE *o_dW) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IXYZWVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXYZW * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXYZW * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXYZW * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IXYZW * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IXYZW * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IXYZW * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IXYZW * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCXYZ )( 
            IXYZW * This,
            /* [retval][out] */ LONG_PTR *o_pplCXYZAddress);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutIVect )( 
            IXYZW * This,
            /* [in] */ IVector *i_pVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutIXYZ )( 
            IXYZW * This,
            /* [in] */ IXYZ *i_pPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXYZ )( 
            IXYZW * This,
            /* [out] */ DOUBLE *o_pdX,
            /* [out] */ DOUBLE *o_pdY,
            /* [out] */ DOUBLE *o_pdZ);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutXYZ )( 
            IXYZW * This,
            /* [in] */ DOUBLE i_dX,
            /* [in] */ DOUBLE i_dY,
            /* [in] */ DOUBLE i_dZ);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsLegal )( 
            IXYZW * This,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Init )( 
            IXYZW * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Trans )( 
            IXYZW * This,
            /* [in] */ IMatrix *i_pMat);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            IXYZW * This,
            /* [in] */ DOUBLE i_dRotAng,
            /* [in] */ IVector *i_pVec,
            /* [in] */ IXYZ *i_pDtmPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Scale )( 
            IXYZW * This,
            /* [in] */ DOUBLE i_dScale,
            /* [in] */ IXYZ *i_pDtmPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDistToPt )( 
            IXYZW * This,
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ DOUBLE *o_pdDist);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDistToPts )( 
            IXYZW * This,
            /* [in] */ IXYZArray *i_pPts,
            /* [in] */ LONG i_iNum,
            /* [out] */ DOUBLE *o_pdDist,
            /* [out] */ int *o_iIdx);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetProjPt )( 
            IXYZW * This,
            /* [in] */ IPlane *i_pProjPln,
            /* [out] */ IXYZ **o_ppPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IfTriPtsColn )( 
            IXYZW * This,
            /* [in] */ IXYZ *i_pP0,
            /* [in] */ IXYZ *i_pP1,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetIVec )( 
            IXYZW * This,
            /* [out] */ IVector **o_ppVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsSame )( 
            IXYZW * This,
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMirrorPt )( 
            IXYZW * This,
            /* [in] */ IPlane *i_pMirrorPln,
            /* [retval][out] */ IXYZ **o_ppPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransToMatPln )( 
            IXYZW * This,
            /* [in] */ IMatrix *i_pPlnMat,
            /* [retval][out] */ IXYZ **o_ppPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransToWcPln )( 
            IXYZW * This,
            /* [in] */ IMatrix *i_pPlnMat,
            /* [retval][out] */ IXYZ **o_ppPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransToMatPlnXYZ )( 
            IXYZW * This,
            /* [in] */ IMatrix *i_pPlnMat,
            /* [out] */ double *o_dx,
            /* [out] */ double *o_dy,
            /* [out] */ double *o_dz);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IXYZW * This,
            /* [in] */ ICxFiler *i_ipFiler);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IXYZW * This,
            /* [in] */ ICxFiler *i_ipFiler);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCXYZW )( 
            IXYZW * This,
            /* [retval][out] */ LONG_PTR *o_pplCXYZWAddress);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsSame )( 
            IXYZW * This,
            /* [in] */ IXYZW *i_pXYZW,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransToHomogen )( 
            IXYZW * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TransFromHomogenTo3D )( 
            IXYZW * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IXYZW * This,
            /* [in] */ ICxFiler *i_ipFiler);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IXYZW * This,
            /* [in] */ ICxFiler *i_ipFiler);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutW )( 
            IXYZW * This,
            /* [in] */ DOUBLE i_dW);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetW )( 
            IXYZW * This,
            /* [out] */ DOUBLE *o_dW);
        
        END_INTERFACE
    } IXYZWVtbl;

    interface IXYZW
    {
        CONST_VTBL struct IXYZWVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXYZW_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IXYZW_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IXYZW_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IXYZW_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IXYZW_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IXYZW_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IXYZW_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IXYZW_GetCXYZ(This,o_pplCXYZAddress)	\
    (This)->lpVtbl -> GetCXYZ(This,o_pplCXYZAddress)

#define IXYZW_PutIVect(This,i_pVec)	\
    (This)->lpVtbl -> PutIVect(This,i_pVec)

#define IXYZW_PutIXYZ(This,i_pPt)	\
    (This)->lpVtbl -> PutIXYZ(This,i_pPt)

#define IXYZW_GetXYZ(This,o_pdX,o_pdY,o_pdZ)	\
    (This)->lpVtbl -> GetXYZ(This,o_pdX,o_pdY,o_pdZ)

#define IXYZW_PutXYZ(This,i_dX,i_dY,i_dZ)	\
    (This)->lpVtbl -> PutXYZ(This,i_dX,i_dY,i_dZ)

#define IXYZW_IsLegal(This,o_pbVal)	\
    (This)->lpVtbl -> IsLegal(This,o_pbVal)

#define IXYZW_Init(This)	\
    (This)->lpVtbl -> Init(This)

#define IXYZW_Trans(This,i_pMat)	\
    (This)->lpVtbl -> Trans(This,i_pMat)

#define IXYZW_Rotate(This,i_dRotAng,i_pVec,i_pDtmPt)	\
    (This)->lpVtbl -> Rotate(This,i_dRotAng,i_pVec,i_pDtmPt)

#define IXYZW_Scale(This,i_dScale,i_pDtmPt)	\
    (This)->lpVtbl -> Scale(This,i_dScale,i_pDtmPt)

#define IXYZW_GetDistToPt(This,i_pPt,o_pdDist)	\
    (This)->lpVtbl -> GetDistToPt(This,i_pPt,o_pdDist)

#define IXYZW_GetDistToPts(This,i_pPts,i_iNum,o_pdDist,o_iIdx)	\
    (This)->lpVtbl -> GetDistToPts(This,i_pPts,i_iNum,o_pdDist,o_iIdx)

#define IXYZW_GetProjPt(This,i_pProjPln,o_ppPt)	\
    (This)->lpVtbl -> GetProjPt(This,i_pProjPln,o_ppPt)

#define IXYZW_IfTriPtsColn(This,i_pP0,i_pP1,o_pbVal)	\
    (This)->lpVtbl -> IfTriPtsColn(This,i_pP0,i_pP1,o_pbVal)

#define IXYZW_GetIVec(This,o_ppVec)	\
    (This)->lpVtbl -> GetIVec(This,o_ppVec)

#define IXYZW_IsSame(This,i_pPt,o_pbVal)	\
    (This)->lpVtbl -> IsSame(This,i_pPt,o_pbVal)

#define IXYZW_GetMirrorPt(This,i_pMirrorPln,o_ppPt)	\
    (This)->lpVtbl -> GetMirrorPt(This,i_pMirrorPln,o_ppPt)

#define IXYZW_TransToMatPln(This,i_pPlnMat,o_ppPt)	\
    (This)->lpVtbl -> TransToMatPln(This,i_pPlnMat,o_ppPt)

#define IXYZW_TransToWcPln(This,i_pPlnMat,o_ppPt)	\
    (This)->lpVtbl -> TransToWcPln(This,i_pPlnMat,o_ppPt)

#define IXYZW_TransToMatPlnXYZ(This,i_pPlnMat,o_dx,o_dy,o_dz)	\
    (This)->lpVtbl -> TransToMatPlnXYZ(This,i_pPlnMat,o_dx,o_dy,o_dz)

#define IXYZW_Save(This,i_ipFiler)	\
    (This)->lpVtbl -> Save(This,i_ipFiler)

#define IXYZW_Load(This,i_ipFiler)	\
    (This)->lpVtbl -> Load(This,i_ipFiler)


#define IXYZW_GetCXYZW(This,o_pplCXYZWAddress)	\
    (This)->lpVtbl -> GetCXYZW(This,o_pplCXYZWAddress)

#define IXYZW_IsSame(This,i_pXYZW,o_pbVal)	\
    (This)->lpVtbl -> IsSame(This,i_pXYZW,o_pbVal)

#define IXYZW_TransToHomogen(This)	\
    (This)->lpVtbl -> TransToHomogen(This)

#define IXYZW_TransFromHomogenTo3D(This)	\
    (This)->lpVtbl -> TransFromHomogenTo3D(This)

#define IXYZW_Save(This,i_ipFiler)	\
    (This)->lpVtbl -> Save(This,i_ipFiler)

#define IXYZW_Load(This,i_ipFiler)	\
    (This)->lpVtbl -> Load(This,i_ipFiler)

#define IXYZW_PutW(This,i_dW)	\
    (This)->lpVtbl -> PutW(This,i_dW)

#define IXYZW_GetW(This,o_dW)	\
    (This)->lpVtbl -> GetW(This,o_dW)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZW_GetCXYZW_Proxy( 
    IXYZW * This,
    /* [retval][out] */ LONG_PTR *o_pplCXYZWAddress);


void __RPC_STUB IXYZW_GetCXYZW_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZW_IsSame_Proxy( 
    IXYZW * This,
    /* [in] */ IXYZW *i_pXYZW,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IXYZW_IsSame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZW_TransToHomogen_Proxy( 
    IXYZW * This);


void __RPC_STUB IXYZW_TransToHomogen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZW_TransFromHomogenTo3D_Proxy( 
    IXYZW * This);


void __RPC_STUB IXYZW_TransFromHomogenTo3D_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZW_Save_Proxy( 
    IXYZW * This,
    /* [in] */ ICxFiler *i_ipFiler);


void __RPC_STUB IXYZW_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZW_Load_Proxy( 
    IXYZW * This,
    /* [in] */ ICxFiler *i_ipFiler);


void __RPC_STUB IXYZW_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZW_PutW_Proxy( 
    IXYZW * This,
    /* [in] */ DOUBLE i_dW);


void __RPC_STUB IXYZW_PutW_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZW_GetW_Proxy( 
    IXYZW * This,
    /* [out] */ DOUBLE *o_dW);


void __RPC_STUB IXYZW_GetW_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IXYZW_INTERFACE_DEFINED__ */


#ifndef __ICoord_INTERFACE_DEFINED__
#define __ICoord_INTERFACE_DEFINED__

/* interface ICoord */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICoord;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("82FCF6FD-C3CD-407A-B183-8A34B066B7B5")
    ICoord : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMatrix( 
            /* [in] */ IMatrix *i_pMat) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Init( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetOrigin( 
            /* [in] */ IXYZ *i_pPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeXAxTo( 
            /* [in] */ IVector *i_pVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeYAxTo( 
            /* [in] */ IVector *i_pVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChangeZAxTo( 
            /* [in] */ IVector *i_pVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPAxis( 
            /* [in] */ IVector *i_pVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsSame( 
            /* [in] */ ICoord *i_pCod,
            VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UCSToWCS( 
            /* [in] */ IXYZ *i_pPt,
            /* [out] */ IXYZ **o_ppPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WCSToUCS( 
            /* [in] */ IXYZ *i_pPt,
            /* [out] */ IXYZ **o_ppPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Move( 
            /* [in] */ IXYZ *i_pDeltaPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Trans( 
            /* [in] */ IMatrix *i_pMat) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Rotate( 
            /* [in] */ DOUBLE i_dRotAng,
            /* [in] */ IVector *i_pVec,
            /* [in] */ IXYZ *i_pDtmPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RotRndX( 
            /* [in] */ DOUBLE i_dRotAng) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RotRndY( 
            /* [in] */ DOUBLE i_dRotAng) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RotRndZ( 
            /* [in] */ DOUBLE i_dRotAng) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCCxCoord( 
            /* [retval][out] */ LONG_PTR *o_pplCCxCoordAddress) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UCSToWCSByVec( 
            /* [in] */ IVector *i_pVec,
            /* [out] */ IVector **o_ppVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WCSToUCSByVec( 
            /* [in] */ IVector *i_pVec,
            /* [out] */ IVector **o_ppVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsLegal( 
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPtAftTrans( 
            /* [in] */ IXYZ *i_pPt,
            /* [in] */ IMatrix *i_pMat,
            /* [retval][out] */ IXYZ **o_ppPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPlnStatus( 
            /* [in] */ LONG i_PlnStatus,
            /* [retval][out] */ LONG *o_OldPlnStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Mirror( 
            /* [in] */ IPlane *i_pMirrorPln,
            /* [retval][out] */ ICoord **o_ppCod) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetXAxis( 
            /* [retval][out] */ IVector **o_ppVecX) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetYAxis( 
            /* [retval][out] */ IVector **o_ppVecY) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetZAxis( 
            /* [retval][out] */ IVector **o_ppVecZ) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPAxis( 
            /* [retval][out] */ IVector **o_ppVecZ) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetXYPlnMat( 
            /* [retval][out] */ IMatrix **o_ppXYMat) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetYZPlnMat( 
            /* [retval][out] */ IMatrix **o_ppYZMat) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetZXPlnMat( 
            /* [retval][out] */ IMatrix **o_ppZXMat) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPlnStatus( 
            /* [retval][out] */ LONG *o_plPlnState) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPosMat( 
            /* [retval][out] */ IMatrix **o_ppMat) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetOrigin( 
            /* [retval][out] */ IXYZ **o_ppPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetInvrsMat( 
            /* [retval][out] */ IMatrix **o_ppMat) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCurCoordPlnNorm( 
            /* [out] */ IVector **o_ppNorm) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutByIMatrix( 
            /* [in] */ IMatrix *i_pMat,
            /* [in] */ LONG i_PlnStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutByICoord( 
            /* [in] */ ICoord *i_pCoord) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PutByPtVecXVecZ( 
            /* [in] */ IXYZ *i_pOriPt,
            /* [in] */ IVector *i_pVecX,
            /* [in] */ IVector *i_pVecZ,
            /* [in] */ LONG i_PlnStatus) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *o_pbsName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR i_bsName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ ICxFiler *i_ipFiler) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ ICxFiler *i_ipFiler) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICoordVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoord * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoord * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoord * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICoord * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICoord * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICoord * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoord * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetMatrix )( 
            ICoord * This,
            /* [in] */ IMatrix *i_pMat);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Init )( 
            ICoord * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetOrigin )( 
            ICoord * This,
            /* [in] */ IXYZ *i_pPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeXAxTo )( 
            ICoord * This,
            /* [in] */ IVector *i_pVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeYAxTo )( 
            ICoord * This,
            /* [in] */ IVector *i_pVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChangeZAxTo )( 
            ICoord * This,
            /* [in] */ IVector *i_pVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPAxis )( 
            ICoord * This,
            /* [in] */ IVector *i_pVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsSame )( 
            ICoord * This,
            /* [in] */ ICoord *i_pCod,
            VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UCSToWCS )( 
            ICoord * This,
            /* [in] */ IXYZ *i_pPt,
            /* [out] */ IXYZ **o_ppPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WCSToUCS )( 
            ICoord * This,
            /* [in] */ IXYZ *i_pPt,
            /* [out] */ IXYZ **o_ppPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Move )( 
            ICoord * This,
            /* [in] */ IXYZ *i_pDeltaPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Trans )( 
            ICoord * This,
            /* [in] */ IMatrix *i_pMat);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Rotate )( 
            ICoord * This,
            /* [in] */ DOUBLE i_dRotAng,
            /* [in] */ IVector *i_pVec,
            /* [in] */ IXYZ *i_pDtmPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RotRndX )( 
            ICoord * This,
            /* [in] */ DOUBLE i_dRotAng);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RotRndY )( 
            ICoord * This,
            /* [in] */ DOUBLE i_dRotAng);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RotRndZ )( 
            ICoord * This,
            /* [in] */ DOUBLE i_dRotAng);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCCxCoord )( 
            ICoord * This,
            /* [retval][out] */ LONG_PTR *o_pplCCxCoordAddress);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UCSToWCSByVec )( 
            ICoord * This,
            /* [in] */ IVector *i_pVec,
            /* [out] */ IVector **o_ppVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WCSToUCSByVec )( 
            ICoord * This,
            /* [in] */ IVector *i_pVec,
            /* [out] */ IVector **o_ppVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsLegal )( 
            ICoord * This,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPtAftTrans )( 
            ICoord * This,
            /* [in] */ IXYZ *i_pPt,
            /* [in] */ IMatrix *i_pMat,
            /* [retval][out] */ IXYZ **o_ppPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPlnStatus )( 
            ICoord * This,
            /* [in] */ LONG i_PlnStatus,
            /* [retval][out] */ LONG *o_OldPlnStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Mirror )( 
            ICoord * This,
            /* [in] */ IPlane *i_pMirrorPln,
            /* [retval][out] */ ICoord **o_ppCod);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXAxis )( 
            ICoord * This,
            /* [retval][out] */ IVector **o_ppVecX);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetYAxis )( 
            ICoord * This,
            /* [retval][out] */ IVector **o_ppVecY);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetZAxis )( 
            ICoord * This,
            /* [retval][out] */ IVector **o_ppVecZ);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPAxis )( 
            ICoord * This,
            /* [retval][out] */ IVector **o_ppVecZ);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXYPlnMat )( 
            ICoord * This,
            /* [retval][out] */ IMatrix **o_ppXYMat);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetYZPlnMat )( 
            ICoord * This,
            /* [retval][out] */ IMatrix **o_ppYZMat);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetZXPlnMat )( 
            ICoord * This,
            /* [retval][out] */ IMatrix **o_ppZXMat);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPlnStatus )( 
            ICoord * This,
            /* [retval][out] */ LONG *o_plPlnState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPosMat )( 
            ICoord * This,
            /* [retval][out] */ IMatrix **o_ppMat);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetOrigin )( 
            ICoord * This,
            /* [retval][out] */ IXYZ **o_ppPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetInvrsMat )( 
            ICoord * This,
            /* [retval][out] */ IMatrix **o_ppMat);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCurCoordPlnNorm )( 
            ICoord * This,
            /* [out] */ IVector **o_ppNorm);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutByIMatrix )( 
            ICoord * This,
            /* [in] */ IMatrix *i_pMat,
            /* [in] */ LONG i_PlnStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutByICoord )( 
            ICoord * This,
            /* [in] */ ICoord *i_pCoord);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PutByPtVecXVecZ )( 
            ICoord * This,
            /* [in] */ IXYZ *i_pOriPt,
            /* [in] */ IVector *i_pVecX,
            /* [in] */ IVector *i_pVecZ,
            /* [in] */ LONG i_PlnStatus);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            ICoord * This,
            /* [retval][out] */ BSTR *o_pbsName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            ICoord * This,
            /* [in] */ BSTR i_bsName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            ICoord * This,
            /* [in] */ ICxFiler *i_ipFiler);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            ICoord * This,
            /* [in] */ ICxFiler *i_ipFiler);
        
        END_INTERFACE
    } ICoordVtbl;

    interface ICoord
    {
        CONST_VTBL struct ICoordVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoord_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICoord_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICoord_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICoord_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICoord_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICoord_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICoord_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICoord_SetMatrix(This,i_pMat)	\
    (This)->lpVtbl -> SetMatrix(This,i_pMat)

#define ICoord_Init(This)	\
    (This)->lpVtbl -> Init(This)

#define ICoord_SetOrigin(This,i_pPt)	\
    (This)->lpVtbl -> SetOrigin(This,i_pPt)

#define ICoord_ChangeXAxTo(This,i_pVec)	\
    (This)->lpVtbl -> ChangeXAxTo(This,i_pVec)

#define ICoord_ChangeYAxTo(This,i_pVec)	\
    (This)->lpVtbl -> ChangeYAxTo(This,i_pVec)

#define ICoord_ChangeZAxTo(This,i_pVec)	\
    (This)->lpVtbl -> ChangeZAxTo(This,i_pVec)

#define ICoord_SetPAxis(This,i_pVec)	\
    (This)->lpVtbl -> SetPAxis(This,i_pVec)

#define ICoord_IsSame(This,i_pCod,o_pbVal)	\
    (This)->lpVtbl -> IsSame(This,i_pCod,o_pbVal)

#define ICoord_UCSToWCS(This,i_pPt,o_ppPt)	\
    (This)->lpVtbl -> UCSToWCS(This,i_pPt,o_ppPt)

#define ICoord_WCSToUCS(This,i_pPt,o_ppPt)	\
    (This)->lpVtbl -> WCSToUCS(This,i_pPt,o_ppPt)

#define ICoord_Move(This,i_pDeltaPt)	\
    (This)->lpVtbl -> Move(This,i_pDeltaPt)

#define ICoord_Trans(This,i_pMat)	\
    (This)->lpVtbl -> Trans(This,i_pMat)

#define ICoord_Rotate(This,i_dRotAng,i_pVec,i_pDtmPt)	\
    (This)->lpVtbl -> Rotate(This,i_dRotAng,i_pVec,i_pDtmPt)

#define ICoord_RotRndX(This,i_dRotAng)	\
    (This)->lpVtbl -> RotRndX(This,i_dRotAng)

#define ICoord_RotRndY(This,i_dRotAng)	\
    (This)->lpVtbl -> RotRndY(This,i_dRotAng)

#define ICoord_RotRndZ(This,i_dRotAng)	\
    (This)->lpVtbl -> RotRndZ(This,i_dRotAng)

#define ICoord_GetCCxCoord(This,o_pplCCxCoordAddress)	\
    (This)->lpVtbl -> GetCCxCoord(This,o_pplCCxCoordAddress)

#define ICoord_UCSToWCSByVec(This,i_pVec,o_ppVec)	\
    (This)->lpVtbl -> UCSToWCSByVec(This,i_pVec,o_ppVec)

#define ICoord_WCSToUCSByVec(This,i_pVec,o_ppVec)	\
    (This)->lpVtbl -> WCSToUCSByVec(This,i_pVec,o_ppVec)

#define ICoord_IsLegal(This,o_pbVal)	\
    (This)->lpVtbl -> IsLegal(This,o_pbVal)

#define ICoord_GetPtAftTrans(This,i_pPt,i_pMat,o_ppPt)	\
    (This)->lpVtbl -> GetPtAftTrans(This,i_pPt,i_pMat,o_ppPt)

#define ICoord_SetPlnStatus(This,i_PlnStatus,o_OldPlnStatus)	\
    (This)->lpVtbl -> SetPlnStatus(This,i_PlnStatus,o_OldPlnStatus)

#define ICoord_Mirror(This,i_pMirrorPln,o_ppCod)	\
    (This)->lpVtbl -> Mirror(This,i_pMirrorPln,o_ppCod)

#define ICoord_GetXAxis(This,o_ppVecX)	\
    (This)->lpVtbl -> GetXAxis(This,o_ppVecX)

#define ICoord_GetYAxis(This,o_ppVecY)	\
    (This)->lpVtbl -> GetYAxis(This,o_ppVecY)

#define ICoord_GetZAxis(This,o_ppVecZ)	\
    (This)->lpVtbl -> GetZAxis(This,o_ppVecZ)

#define ICoord_GetPAxis(This,o_ppVecZ)	\
    (This)->lpVtbl -> GetPAxis(This,o_ppVecZ)

#define ICoord_GetXYPlnMat(This,o_ppXYMat)	\
    (This)->lpVtbl -> GetXYPlnMat(This,o_ppXYMat)

#define ICoord_GetYZPlnMat(This,o_ppYZMat)	\
    (This)->lpVtbl -> GetYZPlnMat(This,o_ppYZMat)

#define ICoord_GetZXPlnMat(This,o_ppZXMat)	\
    (This)->lpVtbl -> GetZXPlnMat(This,o_ppZXMat)

#define ICoord_GetPlnStatus(This,o_plPlnState)	\
    (This)->lpVtbl -> GetPlnStatus(This,o_plPlnState)

#define ICoord_GetPosMat(This,o_ppMat)	\
    (This)->lpVtbl -> GetPosMat(This,o_ppMat)

#define ICoord_GetOrigin(This,o_ppPt)	\
    (This)->lpVtbl -> GetOrigin(This,o_ppPt)

#define ICoord_GetInvrsMat(This,o_ppMat)	\
    (This)->lpVtbl -> GetInvrsMat(This,o_ppMat)

#define ICoord_GetCurCoordPlnNorm(This,o_ppNorm)	\
    (This)->lpVtbl -> GetCurCoordPlnNorm(This,o_ppNorm)

#define ICoord_PutByIMatrix(This,i_pMat,i_PlnStatus)	\
    (This)->lpVtbl -> PutByIMatrix(This,i_pMat,i_PlnStatus)

#define ICoord_PutByICoord(This,i_pCoord)	\
    (This)->lpVtbl -> PutByICoord(This,i_pCoord)

#define ICoord_PutByPtVecXVecZ(This,i_pOriPt,i_pVecX,i_pVecZ,i_PlnStatus)	\
    (This)->lpVtbl -> PutByPtVecXVecZ(This,i_pOriPt,i_pVecX,i_pVecZ,i_PlnStatus)

#define ICoord_get_Name(This,o_pbsName)	\
    (This)->lpVtbl -> get_Name(This,o_pbsName)

#define ICoord_put_Name(This,i_bsName)	\
    (This)->lpVtbl -> put_Name(This,i_bsName)

#define ICoord_Save(This,i_ipFiler)	\
    (This)->lpVtbl -> Save(This,i_ipFiler)

#define ICoord_Load(This,i_ipFiler)	\
    (This)->lpVtbl -> Load(This,i_ipFiler)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_SetMatrix_Proxy( 
    ICoord * This,
    /* [in] */ IMatrix *i_pMat);


void __RPC_STUB ICoord_SetMatrix_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_Init_Proxy( 
    ICoord * This);


void __RPC_STUB ICoord_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_SetOrigin_Proxy( 
    ICoord * This,
    /* [in] */ IXYZ *i_pPt);


void __RPC_STUB ICoord_SetOrigin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_ChangeXAxTo_Proxy( 
    ICoord * This,
    /* [in] */ IVector *i_pVec);


void __RPC_STUB ICoord_ChangeXAxTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_ChangeYAxTo_Proxy( 
    ICoord * This,
    /* [in] */ IVector *i_pVec);


void __RPC_STUB ICoord_ChangeYAxTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_ChangeZAxTo_Proxy( 
    ICoord * This,
    /* [in] */ IVector *i_pVec);


void __RPC_STUB ICoord_ChangeZAxTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_SetPAxis_Proxy( 
    ICoord * This,
    /* [in] */ IVector *i_pVec);


void __RPC_STUB ICoord_SetPAxis_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_IsSame_Proxy( 
    ICoord * This,
    /* [in] */ ICoord *i_pCod,
    VARIANT_BOOL *o_pbVal);


void __RPC_STUB ICoord_IsSame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_UCSToWCS_Proxy( 
    ICoord * This,
    /* [in] */ IXYZ *i_pPt,
    /* [out] */ IXYZ **o_ppPt);


void __RPC_STUB ICoord_UCSToWCS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_WCSToUCS_Proxy( 
    ICoord * This,
    /* [in] */ IXYZ *i_pPt,
    /* [out] */ IXYZ **o_ppPt);


void __RPC_STUB ICoord_WCSToUCS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_Move_Proxy( 
    ICoord * This,
    /* [in] */ IXYZ *i_pDeltaPt);


void __RPC_STUB ICoord_Move_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_Trans_Proxy( 
    ICoord * This,
    /* [in] */ IMatrix *i_pMat);


void __RPC_STUB ICoord_Trans_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_Rotate_Proxy( 
    ICoord * This,
    /* [in] */ DOUBLE i_dRotAng,
    /* [in] */ IVector *i_pVec,
    /* [in] */ IXYZ *i_pDtmPt);


void __RPC_STUB ICoord_Rotate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_RotRndX_Proxy( 
    ICoord * This,
    /* [in] */ DOUBLE i_dRotAng);


void __RPC_STUB ICoord_RotRndX_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_RotRndY_Proxy( 
    ICoord * This,
    /* [in] */ DOUBLE i_dRotAng);


void __RPC_STUB ICoord_RotRndY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_RotRndZ_Proxy( 
    ICoord * This,
    /* [in] */ DOUBLE i_dRotAng);


void __RPC_STUB ICoord_RotRndZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_GetCCxCoord_Proxy( 
    ICoord * This,
    /* [retval][out] */ LONG_PTR *o_pplCCxCoordAddress);


void __RPC_STUB ICoord_GetCCxCoord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_UCSToWCSByVec_Proxy( 
    ICoord * This,
    /* [in] */ IVector *i_pVec,
    /* [out] */ IVector **o_ppVec);


void __RPC_STUB ICoord_UCSToWCSByVec_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_WCSToUCSByVec_Proxy( 
    ICoord * This,
    /* [in] */ IVector *i_pVec,
    /* [out] */ IVector **o_ppVec);


void __RPC_STUB ICoord_WCSToUCSByVec_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_IsLegal_Proxy( 
    ICoord * This,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB ICoord_IsLegal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_GetPtAftTrans_Proxy( 
    ICoord * This,
    /* [in] */ IXYZ *i_pPt,
    /* [in] */ IMatrix *i_pMat,
    /* [retval][out] */ IXYZ **o_ppPt);


void __RPC_STUB ICoord_GetPtAftTrans_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_SetPlnStatus_Proxy( 
    ICoord * This,
    /* [in] */ LONG i_PlnStatus,
    /* [retval][out] */ LONG *o_OldPlnStatus);


void __RPC_STUB ICoord_SetPlnStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_Mirror_Proxy( 
    ICoord * This,
    /* [in] */ IPlane *i_pMirrorPln,
    /* [retval][out] */ ICoord **o_ppCod);


void __RPC_STUB ICoord_Mirror_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_GetXAxis_Proxy( 
    ICoord * This,
    /* [retval][out] */ IVector **o_ppVecX);


void __RPC_STUB ICoord_GetXAxis_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_GetYAxis_Proxy( 
    ICoord * This,
    /* [retval][out] */ IVector **o_ppVecY);


void __RPC_STUB ICoord_GetYAxis_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_GetZAxis_Proxy( 
    ICoord * This,
    /* [retval][out] */ IVector **o_ppVecZ);


void __RPC_STUB ICoord_GetZAxis_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_GetPAxis_Proxy( 
    ICoord * This,
    /* [retval][out] */ IVector **o_ppVecZ);


void __RPC_STUB ICoord_GetPAxis_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_GetXYPlnMat_Proxy( 
    ICoord * This,
    /* [retval][out] */ IMatrix **o_ppXYMat);


void __RPC_STUB ICoord_GetXYPlnMat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_GetYZPlnMat_Proxy( 
    ICoord * This,
    /* [retval][out] */ IMatrix **o_ppYZMat);


void __RPC_STUB ICoord_GetYZPlnMat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_GetZXPlnMat_Proxy( 
    ICoord * This,
    /* [retval][out] */ IMatrix **o_ppZXMat);


void __RPC_STUB ICoord_GetZXPlnMat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_GetPlnStatus_Proxy( 
    ICoord * This,
    /* [retval][out] */ LONG *o_plPlnState);


void __RPC_STUB ICoord_GetPlnStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_GetPosMat_Proxy( 
    ICoord * This,
    /* [retval][out] */ IMatrix **o_ppMat);


void __RPC_STUB ICoord_GetPosMat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_GetOrigin_Proxy( 
    ICoord * This,
    /* [retval][out] */ IXYZ **o_ppPt);


void __RPC_STUB ICoord_GetOrigin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_GetInvrsMat_Proxy( 
    ICoord * This,
    /* [retval][out] */ IMatrix **o_ppMat);


void __RPC_STUB ICoord_GetInvrsMat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_GetCurCoordPlnNorm_Proxy( 
    ICoord * This,
    /* [out] */ IVector **o_ppNorm);


void __RPC_STUB ICoord_GetCurCoordPlnNorm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_PutByIMatrix_Proxy( 
    ICoord * This,
    /* [in] */ IMatrix *i_pMat,
    /* [in] */ LONG i_PlnStatus);


void __RPC_STUB ICoord_PutByIMatrix_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_PutByICoord_Proxy( 
    ICoord * This,
    /* [in] */ ICoord *i_pCoord);


void __RPC_STUB ICoord_PutByICoord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_PutByPtVecXVecZ_Proxy( 
    ICoord * This,
    /* [in] */ IXYZ *i_pOriPt,
    /* [in] */ IVector *i_pVecX,
    /* [in] */ IVector *i_pVecZ,
    /* [in] */ LONG i_PlnStatus);


void __RPC_STUB ICoord_PutByPtVecXVecZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICoord_get_Name_Proxy( 
    ICoord * This,
    /* [retval][out] */ BSTR *o_pbsName);


void __RPC_STUB ICoord_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ICoord_put_Name_Proxy( 
    ICoord * This,
    /* [in] */ BSTR i_bsName);


void __RPC_STUB ICoord_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_Save_Proxy( 
    ICoord * This,
    /* [in] */ ICxFiler *i_ipFiler);


void __RPC_STUB ICoord_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoord_Load_Proxy( 
    ICoord * This,
    /* [in] */ ICxFiler *i_ipFiler);


void __RPC_STUB ICoord_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICoord_INTERFACE_DEFINED__ */


#ifndef __ICoordColl_INTERFACE_DEFINED__
#define __ICoordColl_INTERFACE_DEFINED__

/* interface ICoordColl */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICoordColl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9B3AE1A9-1AD6-4116-A293-2D04B7788371")
    ICoordColl : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCount( 
            /* [retval][out] */ SIZE_T *o_plCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsEmpty( 
            /* [retval][out] */ VARIANT_BOOL *o_pbEmpty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetHead( 
            /* [retval][out] */ ICoord **o_ppItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTail( 
            /* [retval][out] */ ICoord **o_ppItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveHead( 
            /* [retval][out] */ ICoord **o_ppItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveTail( 
            /* [retval][out] */ ICoord **o_ppItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveHeadNoReturn( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveTailNoReturn( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveItem( 
            /* [in] */ ICoord *i_pItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveAll( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddHead( 
            /* [in] */ ICoord *i_pItem,
            /* [defaultvalue][out][in] */ LONG_PTR *o_lpPosition = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddHeadColl( 
            /* [in] */ ICoordColl *i_pColl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddTail( 
            /* [in] */ ICoord *i_pItem,
            /* [defaultvalue][out][in] */ LONG_PTR *o_lpPosition = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddTailColl( 
            /* [in] */ ICoordColl *i_pColl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetHeadPosition( 
            /* [retval][out] */ LONG_PTR *o_pPos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTailPosition( 
            /* [retval][out] */ LONG_PTR *o_pPos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNext( 
            /* [out][in] */ LONG_PTR *io_pPos,
            /* [retval][out] */ ICoord **o_ppItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPrev( 
            /* [out][in] */ LONG_PTR *io_pPos,
            /* [retval][out] */ ICoord **o_ppItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAt( 
            /* [in] */ LONG_PTR i_pos,
            /* [retval][out] */ ICoord **o_ppItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAt( 
            /* [in] */ LONG_PTR i_pos,
            /* [in] */ ICoord *i_pItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveAt( 
            /* [in] */ LONG_PTR i_pos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InsertAfter( 
            /* [in] */ ICoord *i_pItem,
            /* [out][in] */ LONG_PTR *io_lpPosition) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InsertBefore( 
            /* [in] */ ICoord *i_pItem,
            /* [out][in] */ LONG_PTR *io_lpPosition) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Find( 
            /* [in] */ ICoord *i_pItem,
            /* [in] */ LONG_PTR i_posStart,
            /* [out][in] */ LONG_PTR *o_pPos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindIndex( 
            /* [in] */ SIZE_T i_lIndex,
            /* [retval][out] */ LONG_PTR *o_lpPosition) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveToHead( 
            /* [in] */ LONG_PTR i_pos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveToTail( 
            /* [in] */ LONG_PTR i_pos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SwapElements( 
            /* [in] */ LONG_PTR i_pos1,
            /* [in] */ LONG_PTR i_pos2) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetIndex( 
            /* [in] */ ICoord *i_pItem,
            /* [retval][out] */ LONG *o_iIdx) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICoordCollVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICoordColl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICoordColl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICoordColl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICoordColl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICoordColl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICoordColl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICoordColl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            ICoordColl * This,
            /* [retval][out] */ SIZE_T *o_plCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEmpty )( 
            ICoordColl * This,
            /* [retval][out] */ VARIANT_BOOL *o_pbEmpty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetHead )( 
            ICoordColl * This,
            /* [retval][out] */ ICoord **o_ppItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTail )( 
            ICoordColl * This,
            /* [retval][out] */ ICoord **o_ppItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveHead )( 
            ICoordColl * This,
            /* [retval][out] */ ICoord **o_ppItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveTail )( 
            ICoordColl * This,
            /* [retval][out] */ ICoord **o_ppItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveHeadNoReturn )( 
            ICoordColl * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveTailNoReturn )( 
            ICoordColl * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveItem )( 
            ICoordColl * This,
            /* [in] */ ICoord *i_pItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveAll )( 
            ICoordColl * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddHead )( 
            ICoordColl * This,
            /* [in] */ ICoord *i_pItem,
            /* [defaultvalue][out][in] */ LONG_PTR *o_lpPosition);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddHeadColl )( 
            ICoordColl * This,
            /* [in] */ ICoordColl *i_pColl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddTail )( 
            ICoordColl * This,
            /* [in] */ ICoord *i_pItem,
            /* [defaultvalue][out][in] */ LONG_PTR *o_lpPosition);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddTailColl )( 
            ICoordColl * This,
            /* [in] */ ICoordColl *i_pColl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetHeadPosition )( 
            ICoordColl * This,
            /* [retval][out] */ LONG_PTR *o_pPos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTailPosition )( 
            ICoordColl * This,
            /* [retval][out] */ LONG_PTR *o_pPos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNext )( 
            ICoordColl * This,
            /* [out][in] */ LONG_PTR *io_pPos,
            /* [retval][out] */ ICoord **o_ppItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPrev )( 
            ICoordColl * This,
            /* [out][in] */ LONG_PTR *io_pPos,
            /* [retval][out] */ ICoord **o_ppItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAt )( 
            ICoordColl * This,
            /* [in] */ LONG_PTR i_pos,
            /* [retval][out] */ ICoord **o_ppItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetAt )( 
            ICoordColl * This,
            /* [in] */ LONG_PTR i_pos,
            /* [in] */ ICoord *i_pItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveAt )( 
            ICoordColl * This,
            /* [in] */ LONG_PTR i_pos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InsertAfter )( 
            ICoordColl * This,
            /* [in] */ ICoord *i_pItem,
            /* [out][in] */ LONG_PTR *io_lpPosition);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InsertBefore )( 
            ICoordColl * This,
            /* [in] */ ICoord *i_pItem,
            /* [out][in] */ LONG_PTR *io_lpPosition);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Find )( 
            ICoordColl * This,
            /* [in] */ ICoord *i_pItem,
            /* [in] */ LONG_PTR i_posStart,
            /* [out][in] */ LONG_PTR *o_pPos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindIndex )( 
            ICoordColl * This,
            /* [in] */ SIZE_T i_lIndex,
            /* [retval][out] */ LONG_PTR *o_lpPosition);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveToHead )( 
            ICoordColl * This,
            /* [in] */ LONG_PTR i_pos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveToTail )( 
            ICoordColl * This,
            /* [in] */ LONG_PTR i_pos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SwapElements )( 
            ICoordColl * This,
            /* [in] */ LONG_PTR i_pos1,
            /* [in] */ LONG_PTR i_pos2);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetIndex )( 
            ICoordColl * This,
            /* [in] */ ICoord *i_pItem,
            /* [retval][out] */ LONG *o_iIdx);
        
        END_INTERFACE
    } ICoordCollVtbl;

    interface ICoordColl
    {
        CONST_VTBL struct ICoordCollVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICoordColl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICoordColl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICoordColl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICoordColl_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICoordColl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICoordColl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICoordColl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICoordColl_GetCount(This,o_plCount)	\
    (This)->lpVtbl -> GetCount(This,o_plCount)

#define ICoordColl_IsEmpty(This,o_pbEmpty)	\
    (This)->lpVtbl -> IsEmpty(This,o_pbEmpty)

#define ICoordColl_GetHead(This,o_ppItem)	\
    (This)->lpVtbl -> GetHead(This,o_ppItem)

#define ICoordColl_GetTail(This,o_ppItem)	\
    (This)->lpVtbl -> GetTail(This,o_ppItem)

#define ICoordColl_RemoveHead(This,o_ppItem)	\
    (This)->lpVtbl -> RemoveHead(This,o_ppItem)

#define ICoordColl_RemoveTail(This,o_ppItem)	\
    (This)->lpVtbl -> RemoveTail(This,o_ppItem)

#define ICoordColl_RemoveHeadNoReturn(This)	\
    (This)->lpVtbl -> RemoveHeadNoReturn(This)

#define ICoordColl_RemoveTailNoReturn(This)	\
    (This)->lpVtbl -> RemoveTailNoReturn(This)

#define ICoordColl_RemoveItem(This,i_pItem)	\
    (This)->lpVtbl -> RemoveItem(This,i_pItem)

#define ICoordColl_RemoveAll(This)	\
    (This)->lpVtbl -> RemoveAll(This)

#define ICoordColl_AddHead(This,i_pItem,o_lpPosition)	\
    (This)->lpVtbl -> AddHead(This,i_pItem,o_lpPosition)

#define ICoordColl_AddHeadColl(This,i_pColl)	\
    (This)->lpVtbl -> AddHeadColl(This,i_pColl)

#define ICoordColl_AddTail(This,i_pItem,o_lpPosition)	\
    (This)->lpVtbl -> AddTail(This,i_pItem,o_lpPosition)

#define ICoordColl_AddTailColl(This,i_pColl)	\
    (This)->lpVtbl -> AddTailColl(This,i_pColl)

#define ICoordColl_GetHeadPosition(This,o_pPos)	\
    (This)->lpVtbl -> GetHeadPosition(This,o_pPos)

#define ICoordColl_GetTailPosition(This,o_pPos)	\
    (This)->lpVtbl -> GetTailPosition(This,o_pPos)

#define ICoordColl_GetNext(This,io_pPos,o_ppItem)	\
    (This)->lpVtbl -> GetNext(This,io_pPos,o_ppItem)

#define ICoordColl_GetPrev(This,io_pPos,o_ppItem)	\
    (This)->lpVtbl -> GetPrev(This,io_pPos,o_ppItem)

#define ICoordColl_GetAt(This,i_pos,o_ppItem)	\
    (This)->lpVtbl -> GetAt(This,i_pos,o_ppItem)

#define ICoordColl_SetAt(This,i_pos,i_pItem)	\
    (This)->lpVtbl -> SetAt(This,i_pos,i_pItem)

#define ICoordColl_RemoveAt(This,i_pos)	\
    (This)->lpVtbl -> RemoveAt(This,i_pos)

#define ICoordColl_InsertAfter(This,i_pItem,io_lpPosition)	\
    (This)->lpVtbl -> InsertAfter(This,i_pItem,io_lpPosition)

#define ICoordColl_InsertBefore(This,i_pItem,io_lpPosition)	\
    (This)->lpVtbl -> InsertBefore(This,i_pItem,io_lpPosition)

#define ICoordColl_Find(This,i_pItem,i_posStart,o_pPos)	\
    (This)->lpVtbl -> Find(This,i_pItem,i_posStart,o_pPos)

#define ICoordColl_FindIndex(This,i_lIndex,o_lpPosition)	\
    (This)->lpVtbl -> FindIndex(This,i_lIndex,o_lpPosition)

#define ICoordColl_MoveToHead(This,i_pos)	\
    (This)->lpVtbl -> MoveToHead(This,i_pos)

#define ICoordColl_MoveToTail(This,i_pos)	\
    (This)->lpVtbl -> MoveToTail(This,i_pos)

#define ICoordColl_SwapElements(This,i_pos1,i_pos2)	\
    (This)->lpVtbl -> SwapElements(This,i_pos1,i_pos2)

#define ICoordColl_GetIndex(This,i_pItem,o_iIdx)	\
    (This)->lpVtbl -> GetIndex(This,i_pItem,o_iIdx)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_GetCount_Proxy( 
    ICoordColl * This,
    /* [retval][out] */ SIZE_T *o_plCount);


void __RPC_STUB ICoordColl_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_IsEmpty_Proxy( 
    ICoordColl * This,
    /* [retval][out] */ VARIANT_BOOL *o_pbEmpty);


void __RPC_STUB ICoordColl_IsEmpty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_GetHead_Proxy( 
    ICoordColl * This,
    /* [retval][out] */ ICoord **o_ppItem);


void __RPC_STUB ICoordColl_GetHead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_GetTail_Proxy( 
    ICoordColl * This,
    /* [retval][out] */ ICoord **o_ppItem);


void __RPC_STUB ICoordColl_GetTail_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_RemoveHead_Proxy( 
    ICoordColl * This,
    /* [retval][out] */ ICoord **o_ppItem);


void __RPC_STUB ICoordColl_RemoveHead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_RemoveTail_Proxy( 
    ICoordColl * This,
    /* [retval][out] */ ICoord **o_ppItem);


void __RPC_STUB ICoordColl_RemoveTail_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_RemoveHeadNoReturn_Proxy( 
    ICoordColl * This);


void __RPC_STUB ICoordColl_RemoveHeadNoReturn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_RemoveTailNoReturn_Proxy( 
    ICoordColl * This);


void __RPC_STUB ICoordColl_RemoveTailNoReturn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_RemoveItem_Proxy( 
    ICoordColl * This,
    /* [in] */ ICoord *i_pItem);


void __RPC_STUB ICoordColl_RemoveItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_RemoveAll_Proxy( 
    ICoordColl * This);


void __RPC_STUB ICoordColl_RemoveAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_AddHead_Proxy( 
    ICoordColl * This,
    /* [in] */ ICoord *i_pItem,
    /* [defaultvalue][out][in] */ LONG_PTR *o_lpPosition);


void __RPC_STUB ICoordColl_AddHead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_AddHeadColl_Proxy( 
    ICoordColl * This,
    /* [in] */ ICoordColl *i_pColl);


void __RPC_STUB ICoordColl_AddHeadColl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_AddTail_Proxy( 
    ICoordColl * This,
    /* [in] */ ICoord *i_pItem,
    /* [defaultvalue][out][in] */ LONG_PTR *o_lpPosition);


void __RPC_STUB ICoordColl_AddTail_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_AddTailColl_Proxy( 
    ICoordColl * This,
    /* [in] */ ICoordColl *i_pColl);


void __RPC_STUB ICoordColl_AddTailColl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_GetHeadPosition_Proxy( 
    ICoordColl * This,
    /* [retval][out] */ LONG_PTR *o_pPos);


void __RPC_STUB ICoordColl_GetHeadPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_GetTailPosition_Proxy( 
    ICoordColl * This,
    /* [retval][out] */ LONG_PTR *o_pPos);


void __RPC_STUB ICoordColl_GetTailPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_GetNext_Proxy( 
    ICoordColl * This,
    /* [out][in] */ LONG_PTR *io_pPos,
    /* [retval][out] */ ICoord **o_ppItem);


void __RPC_STUB ICoordColl_GetNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_GetPrev_Proxy( 
    ICoordColl * This,
    /* [out][in] */ LONG_PTR *io_pPos,
    /* [retval][out] */ ICoord **o_ppItem);


void __RPC_STUB ICoordColl_GetPrev_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_GetAt_Proxy( 
    ICoordColl * This,
    /* [in] */ LONG_PTR i_pos,
    /* [retval][out] */ ICoord **o_ppItem);


void __RPC_STUB ICoordColl_GetAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_SetAt_Proxy( 
    ICoordColl * This,
    /* [in] */ LONG_PTR i_pos,
    /* [in] */ ICoord *i_pItem);


void __RPC_STUB ICoordColl_SetAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_RemoveAt_Proxy( 
    ICoordColl * This,
    /* [in] */ LONG_PTR i_pos);


void __RPC_STUB ICoordColl_RemoveAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_InsertAfter_Proxy( 
    ICoordColl * This,
    /* [in] */ ICoord *i_pItem,
    /* [out][in] */ LONG_PTR *io_lpPosition);


void __RPC_STUB ICoordColl_InsertAfter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_InsertBefore_Proxy( 
    ICoordColl * This,
    /* [in] */ ICoord *i_pItem,
    /* [out][in] */ LONG_PTR *io_lpPosition);


void __RPC_STUB ICoordColl_InsertBefore_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_Find_Proxy( 
    ICoordColl * This,
    /* [in] */ ICoord *i_pItem,
    /* [in] */ LONG_PTR i_posStart,
    /* [out][in] */ LONG_PTR *o_pPos);


void __RPC_STUB ICoordColl_Find_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_FindIndex_Proxy( 
    ICoordColl * This,
    /* [in] */ SIZE_T i_lIndex,
    /* [retval][out] */ LONG_PTR *o_lpPosition);


void __RPC_STUB ICoordColl_FindIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_MoveToHead_Proxy( 
    ICoordColl * This,
    /* [in] */ LONG_PTR i_pos);


void __RPC_STUB ICoordColl_MoveToHead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_MoveToTail_Proxy( 
    ICoordColl * This,
    /* [in] */ LONG_PTR i_pos);


void __RPC_STUB ICoordColl_MoveToTail_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_SwapElements_Proxy( 
    ICoordColl * This,
    /* [in] */ LONG_PTR i_pos1,
    /* [in] */ LONG_PTR i_pos2);


void __RPC_STUB ICoordColl_SwapElements_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICoordColl_GetIndex_Proxy( 
    ICoordColl * This,
    /* [in] */ ICoord *i_pItem,
    /* [retval][out] */ LONG *o_iIdx);


void __RPC_STUB ICoordColl_GetIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICoordColl_INTERFACE_DEFINED__ */


#ifndef __IExpressions_INTERFACE_DEFINED__
#define __IExpressions_INTERFACE_DEFINED__

/* interface IExpressions */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IExpressions;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("808CFD8B-79DA-4CDD-80B7-68DDC72F8917")
    IExpressions : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE exprCalExpByRadian( 
            /* [in] */ BSTR i_exp,
            /* [retval][out] */ DOUBLE *o_dresult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE exprCalExpByDegree( 
            /* [in] */ BSTR i_exp,
            /* [retval][out] */ DOUBLE *o_dresult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CalExp( 
            /* [in] */ BSTR i_exp,
            /* [retval][out] */ DOUBLE *i_dresult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IniFuncTable( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddValueTable( 
            /* [in] */ unsigned char i_flag,
            /* [in] */ BSTR i_pName,
            /* [in] */ BSTR i_pSlave,
            /* [in] */ DOUBLE i_dValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddFunc( 
            /* [in] */ LONG_PTR i_lFuncAddress,
            /* [in] */ BSTR i_FuncStr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetValIndex( 
            /* [in] */ LONG i_Indx,
            /* [out] */ unsigned char *o_flag,
            /* [out] */ BSTR *o_Name,
            /* [out] */ BSTR *o_Slave,
            /* [out] */ DOUBLE *o_dValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFuncIndex( 
            /* [in] */ LONG i_Indx,
            /* [out] */ LONG_PTR *o_lFuncAddress,
            /* [out] */ BSTR *o_FuncStr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsInStr( 
            /* [in] */ unsigned char i_ch,
            /* [in] */ BSTR i_s,
            /* [out] */ VARIANT_BOOL *o_IsIn) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UpdateSlaveVar( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsBoolTrue( 
            /* [in] */ BSTR i_bsDefine,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVarCount( 
            /* [out] */ INT *o_iCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetValIndex( 
            /* [in] */ LONG i_Indx,
            /* [in] */ unsigned char i_cflag,
            /* [in] */ BSTR i_bsName,
            /* [in] */ BSTR i_bsSlave,
            /* [in] */ DOUBLE i_dValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Init( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetErrorHandler( 
            /* [in] */ LONG *pFuncAddress) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsParaUsed( 
            /* [out] */ VARIANT_BOOL *o_vbParaUsed) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExpressionsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IExpressions * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IExpressions * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IExpressions * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IExpressions * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IExpressions * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IExpressions * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IExpressions * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *exprCalExpByRadian )( 
            IExpressions * This,
            /* [in] */ BSTR i_exp,
            /* [retval][out] */ DOUBLE *o_dresult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *exprCalExpByDegree )( 
            IExpressions * This,
            /* [in] */ BSTR i_exp,
            /* [retval][out] */ DOUBLE *o_dresult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CalExp )( 
            IExpressions * This,
            /* [in] */ BSTR i_exp,
            /* [retval][out] */ DOUBLE *i_dresult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IniFuncTable )( 
            IExpressions * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddValueTable )( 
            IExpressions * This,
            /* [in] */ unsigned char i_flag,
            /* [in] */ BSTR i_pName,
            /* [in] */ BSTR i_pSlave,
            /* [in] */ DOUBLE i_dValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddFunc )( 
            IExpressions * This,
            /* [in] */ LONG_PTR i_lFuncAddress,
            /* [in] */ BSTR i_FuncStr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetValIndex )( 
            IExpressions * This,
            /* [in] */ LONG i_Indx,
            /* [out] */ unsigned char *o_flag,
            /* [out] */ BSTR *o_Name,
            /* [out] */ BSTR *o_Slave,
            /* [out] */ DOUBLE *o_dValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFuncIndex )( 
            IExpressions * This,
            /* [in] */ LONG i_Indx,
            /* [out] */ LONG_PTR *o_lFuncAddress,
            /* [out] */ BSTR *o_FuncStr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsInStr )( 
            IExpressions * This,
            /* [in] */ unsigned char i_ch,
            /* [in] */ BSTR i_s,
            /* [out] */ VARIANT_BOOL *o_IsIn);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateSlaveVar )( 
            IExpressions * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsBoolTrue )( 
            IExpressions * This,
            /* [in] */ BSTR i_bsDefine,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetVarCount )( 
            IExpressions * This,
            /* [out] */ INT *o_iCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetValIndex )( 
            IExpressions * This,
            /* [in] */ LONG i_Indx,
            /* [in] */ unsigned char i_cflag,
            /* [in] */ BSTR i_bsName,
            /* [in] */ BSTR i_bsSlave,
            /* [in] */ DOUBLE i_dValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Init )( 
            IExpressions * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetErrorHandler )( 
            IExpressions * This,
            /* [in] */ LONG *pFuncAddress);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsParaUsed )( 
            IExpressions * This,
            /* [out] */ VARIANT_BOOL *o_vbParaUsed);
        
        END_INTERFACE
    } IExpressionsVtbl;

    interface IExpressions
    {
        CONST_VTBL struct IExpressionsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExpressions_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExpressions_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExpressions_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExpressions_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IExpressions_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IExpressions_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IExpressions_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IExpressions_exprCalExpByRadian(This,i_exp,o_dresult)	\
    (This)->lpVtbl -> exprCalExpByRadian(This,i_exp,o_dresult)

#define IExpressions_exprCalExpByDegree(This,i_exp,o_dresult)	\
    (This)->lpVtbl -> exprCalExpByDegree(This,i_exp,o_dresult)

#define IExpressions_CalExp(This,i_exp,i_dresult)	\
    (This)->lpVtbl -> CalExp(This,i_exp,i_dresult)

#define IExpressions_IniFuncTable(This)	\
    (This)->lpVtbl -> IniFuncTable(This)

#define IExpressions_AddValueTable(This,i_flag,i_pName,i_pSlave,i_dValue)	\
    (This)->lpVtbl -> AddValueTable(This,i_flag,i_pName,i_pSlave,i_dValue)

#define IExpressions_AddFunc(This,i_lFuncAddress,i_FuncStr)	\
    (This)->lpVtbl -> AddFunc(This,i_lFuncAddress,i_FuncStr)

#define IExpressions_GetValIndex(This,i_Indx,o_flag,o_Name,o_Slave,o_dValue)	\
    (This)->lpVtbl -> GetValIndex(This,i_Indx,o_flag,o_Name,o_Slave,o_dValue)

#define IExpressions_GetFuncIndex(This,i_Indx,o_lFuncAddress,o_FuncStr)	\
    (This)->lpVtbl -> GetFuncIndex(This,i_Indx,o_lFuncAddress,o_FuncStr)

#define IExpressions_IsInStr(This,i_ch,i_s,o_IsIn)	\
    (This)->lpVtbl -> IsInStr(This,i_ch,i_s,o_IsIn)

#define IExpressions_UpdateSlaveVar(This)	\
    (This)->lpVtbl -> UpdateSlaveVar(This)

#define IExpressions_IsBoolTrue(This,i_bsDefine,o_pbVal)	\
    (This)->lpVtbl -> IsBoolTrue(This,i_bsDefine,o_pbVal)

#define IExpressions_GetVarCount(This,o_iCount)	\
    (This)->lpVtbl -> GetVarCount(This,o_iCount)

#define IExpressions_SetValIndex(This,i_Indx,i_cflag,i_bsName,i_bsSlave,i_dValue)	\
    (This)->lpVtbl -> SetValIndex(This,i_Indx,i_cflag,i_bsName,i_bsSlave,i_dValue)

#define IExpressions_Init(This)	\
    (This)->lpVtbl -> Init(This)

#define IExpressions_SetErrorHandler(This,pFuncAddress)	\
    (This)->lpVtbl -> SetErrorHandler(This,pFuncAddress)

#define IExpressions_IsParaUsed(This,o_vbParaUsed)	\
    (This)->lpVtbl -> IsParaUsed(This,o_vbParaUsed)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IExpressions_exprCalExpByRadian_Proxy( 
    IExpressions * This,
    /* [in] */ BSTR i_exp,
    /* [retval][out] */ DOUBLE *o_dresult);


void __RPC_STUB IExpressions_exprCalExpByRadian_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IExpressions_exprCalExpByDegree_Proxy( 
    IExpressions * This,
    /* [in] */ BSTR i_exp,
    /* [retval][out] */ DOUBLE *o_dresult);


void __RPC_STUB IExpressions_exprCalExpByDegree_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IExpressions_CalExp_Proxy( 
    IExpressions * This,
    /* [in] */ BSTR i_exp,
    /* [retval][out] */ DOUBLE *i_dresult);


void __RPC_STUB IExpressions_CalExp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IExpressions_IniFuncTable_Proxy( 
    IExpressions * This);


void __RPC_STUB IExpressions_IniFuncTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IExpressions_AddValueTable_Proxy( 
    IExpressions * This,
    /* [in] */ unsigned char i_flag,
    /* [in] */ BSTR i_pName,
    /* [in] */ BSTR i_pSlave,
    /* [in] */ DOUBLE i_dValue);


void __RPC_STUB IExpressions_AddValueTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IExpressions_AddFunc_Proxy( 
    IExpressions * This,
    /* [in] */ LONG_PTR i_lFuncAddress,
    /* [in] */ BSTR i_FuncStr);


void __RPC_STUB IExpressions_AddFunc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IExpressions_GetValIndex_Proxy( 
    IExpressions * This,
    /* [in] */ LONG i_Indx,
    /* [out] */ unsigned char *o_flag,
    /* [out] */ BSTR *o_Name,
    /* [out] */ BSTR *o_Slave,
    /* [out] */ DOUBLE *o_dValue);


void __RPC_STUB IExpressions_GetValIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IExpressions_GetFuncIndex_Proxy( 
    IExpressions * This,
    /* [in] */ LONG i_Indx,
    /* [out] */ LONG_PTR *o_lFuncAddress,
    /* [out] */ BSTR *o_FuncStr);


void __RPC_STUB IExpressions_GetFuncIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IExpressions_IsInStr_Proxy( 
    IExpressions * This,
    /* [in] */ unsigned char i_ch,
    /* [in] */ BSTR i_s,
    /* [out] */ VARIANT_BOOL *o_IsIn);


void __RPC_STUB IExpressions_IsInStr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IExpressions_UpdateSlaveVar_Proxy( 
    IExpressions * This);


void __RPC_STUB IExpressions_UpdateSlaveVar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IExpressions_IsBoolTrue_Proxy( 
    IExpressions * This,
    /* [in] */ BSTR i_bsDefine,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IExpressions_IsBoolTrue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IExpressions_GetVarCount_Proxy( 
    IExpressions * This,
    /* [out] */ INT *o_iCount);


void __RPC_STUB IExpressions_GetVarCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IExpressions_SetValIndex_Proxy( 
    IExpressions * This,
    /* [in] */ LONG i_Indx,
    /* [in] */ unsigned char i_cflag,
    /* [in] */ BSTR i_bsName,
    /* [in] */ BSTR i_bsSlave,
    /* [in] */ DOUBLE i_dValue);


void __RPC_STUB IExpressions_SetValIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IExpressions_Init_Proxy( 
    IExpressions * This);


void __RPC_STUB IExpressions_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IExpressions_SetErrorHandler_Proxy( 
    IExpressions * This,
    /* [in] */ LONG *pFuncAddress);


void __RPC_STUB IExpressions_SetErrorHandler_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IExpressions_IsParaUsed_Proxy( 
    IExpressions * This,
    /* [out] */ VARIANT_BOOL *o_vbParaUsed);


void __RPC_STUB IExpressions_IsParaUsed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IExpressions_INTERFACE_DEFINED__ */


#ifndef __IXYZTs_INTERFACE_DEFINED__
#define __IXYZTs_INTERFACE_DEFINED__

/* interface IXYZTs */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IXYZTs;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8F988ACE-D1BA-4DB9-9725-FD275DDA044C")
    IXYZTs : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCXYZTs( 
            /* [out] */ LONG_PTR *o_pplCXYZTsAddress) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Init( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetParaType( 
            /* [out] */ LONG *o_pParaType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetParaType( 
            /* [in] */ LONG i_ParaType) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetUV( 
            /* [out] */ DOUBLE *o_pu0,
            /* [out] */ DOUBLE *o_pu1,
            /* [out] */ DOUBLE *o_pv0,
            /* [out] */ DOUBLE *o_pv1) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetUV( 
            /* [in] */ DOUBLE i_u0,
            /* [in] */ DOUBLE i_u1,
            /* [in] */ DOUBLE i_v0,
            /* [in] */ DOUBLE i_v1) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsLegal( 
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsSame( 
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CopyFrom( 
            /* [in] */ IXYZTs *i_pPtTs) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetIXYZ( 
            /* [in] */ IXYZ *i_pPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetIXYZ( 
            /* [retval][out] */ IXYZ **o_ppPt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetXYZ( 
            /* [out] */ double *o_dx,
            /* [out] */ double *o_dy,
            /* [out] */ double *o_dz) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetXYZ( 
            /* [in] */ double i_dx,
            /* [in] */ double i_dy,
            /* [in] */ double i_dz) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ ICxFiler *i_ipFiler) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ ICxFiler *i_ipFiler) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IXYZTsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXYZTs * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXYZTs * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXYZTs * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IXYZTs * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IXYZTs * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IXYZTs * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IXYZTs * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCXYZTs )( 
            IXYZTs * This,
            /* [out] */ LONG_PTR *o_pplCXYZTsAddress);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Init )( 
            IXYZTs * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetParaType )( 
            IXYZTs * This,
            /* [out] */ LONG *o_pParaType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetParaType )( 
            IXYZTs * This,
            /* [in] */ LONG i_ParaType);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetUV )( 
            IXYZTs * This,
            /* [out] */ DOUBLE *o_pu0,
            /* [out] */ DOUBLE *o_pu1,
            /* [out] */ DOUBLE *o_pv0,
            /* [out] */ DOUBLE *o_pv1);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetUV )( 
            IXYZTs * This,
            /* [in] */ DOUBLE i_u0,
            /* [in] */ DOUBLE i_u1,
            /* [in] */ DOUBLE i_v0,
            /* [in] */ DOUBLE i_v1);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsLegal )( 
            IXYZTs * This,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsSame )( 
            IXYZTs * This,
            /* [in] */ IXYZ *i_pPt,
            /* [retval][out] */ VARIANT_BOOL *o_pbVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CopyFrom )( 
            IXYZTs * This,
            /* [in] */ IXYZTs *i_pPtTs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetIXYZ )( 
            IXYZTs * This,
            /* [in] */ IXYZ *i_pPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetIXYZ )( 
            IXYZTs * This,
            /* [retval][out] */ IXYZ **o_ppPt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXYZ )( 
            IXYZTs * This,
            /* [out] */ double *o_dx,
            /* [out] */ double *o_dy,
            /* [out] */ double *o_dz);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXYZ )( 
            IXYZTs * This,
            /* [in] */ double i_dx,
            /* [in] */ double i_dy,
            /* [in] */ double i_dz);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IXYZTs * This,
            /* [in] */ ICxFiler *i_ipFiler);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IXYZTs * This,
            /* [in] */ ICxFiler *i_ipFiler);
        
        END_INTERFACE
    } IXYZTsVtbl;

    interface IXYZTs
    {
        CONST_VTBL struct IXYZTsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXYZTs_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IXYZTs_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IXYZTs_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IXYZTs_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IXYZTs_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IXYZTs_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IXYZTs_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IXYZTs_GetCXYZTs(This,o_pplCXYZTsAddress)	\
    (This)->lpVtbl -> GetCXYZTs(This,o_pplCXYZTsAddress)

#define IXYZTs_Init(This)	\
    (This)->lpVtbl -> Init(This)

#define IXYZTs_GetParaType(This,o_pParaType)	\
    (This)->lpVtbl -> GetParaType(This,o_pParaType)

#define IXYZTs_SetParaType(This,i_ParaType)	\
    (This)->lpVtbl -> SetParaType(This,i_ParaType)

#define IXYZTs_GetUV(This,o_pu0,o_pu1,o_pv0,o_pv1)	\
    (This)->lpVtbl -> GetUV(This,o_pu0,o_pu1,o_pv0,o_pv1)

#define IXYZTs_SetUV(This,i_u0,i_u1,i_v0,i_v1)	\
    (This)->lpVtbl -> SetUV(This,i_u0,i_u1,i_v0,i_v1)

#define IXYZTs_IsLegal(This,o_pbVal)	\
    (This)->lpVtbl -> IsLegal(This,o_pbVal)

#define IXYZTs_IsSame(This,i_pPt,o_pbVal)	\
    (This)->lpVtbl -> IsSame(This,i_pPt,o_pbVal)

#define IXYZTs_CopyFrom(This,i_pPtTs)	\
    (This)->lpVtbl -> CopyFrom(This,i_pPtTs)

#define IXYZTs_SetIXYZ(This,i_pPt)	\
    (This)->lpVtbl -> SetIXYZ(This,i_pPt)

#define IXYZTs_GetIXYZ(This,o_ppPt)	\
    (This)->lpVtbl -> GetIXYZ(This,o_ppPt)

#define IXYZTs_GetXYZ(This,o_dx,o_dy,o_dz)	\
    (This)->lpVtbl -> GetXYZ(This,o_dx,o_dy,o_dz)

#define IXYZTs_SetXYZ(This,i_dx,i_dy,i_dz)	\
    (This)->lpVtbl -> SetXYZ(This,i_dx,i_dy,i_dz)

#define IXYZTs_Save(This,i_ipFiler)	\
    (This)->lpVtbl -> Save(This,i_ipFiler)

#define IXYZTs_Load(This,i_ipFiler)	\
    (This)->lpVtbl -> Load(This,i_ipFiler)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZTs_GetCXYZTs_Proxy( 
    IXYZTs * This,
    /* [out] */ LONG_PTR *o_pplCXYZTsAddress);


void __RPC_STUB IXYZTs_GetCXYZTs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZTs_Init_Proxy( 
    IXYZTs * This);


void __RPC_STUB IXYZTs_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZTs_GetParaType_Proxy( 
    IXYZTs * This,
    /* [out] */ LONG *o_pParaType);


void __RPC_STUB IXYZTs_GetParaType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZTs_SetParaType_Proxy( 
    IXYZTs * This,
    /* [in] */ LONG i_ParaType);


void __RPC_STUB IXYZTs_SetParaType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZTs_GetUV_Proxy( 
    IXYZTs * This,
    /* [out] */ DOUBLE *o_pu0,
    /* [out] */ DOUBLE *o_pu1,
    /* [out] */ DOUBLE *o_pv0,
    /* [out] */ DOUBLE *o_pv1);


void __RPC_STUB IXYZTs_GetUV_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZTs_SetUV_Proxy( 
    IXYZTs * This,
    /* [in] */ DOUBLE i_u0,
    /* [in] */ DOUBLE i_u1,
    /* [in] */ DOUBLE i_v0,
    /* [in] */ DOUBLE i_v1);


void __RPC_STUB IXYZTs_SetUV_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZTs_IsLegal_Proxy( 
    IXYZTs * This,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IXYZTs_IsLegal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZTs_IsSame_Proxy( 
    IXYZTs * This,
    /* [in] */ IXYZ *i_pPt,
    /* [retval][out] */ VARIANT_BOOL *o_pbVal);


void __RPC_STUB IXYZTs_IsSame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZTs_CopyFrom_Proxy( 
    IXYZTs * This,
    /* [in] */ IXYZTs *i_pPtTs);


void __RPC_STUB IXYZTs_CopyFrom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZTs_SetIXYZ_Proxy( 
    IXYZTs * This,
    /* [in] */ IXYZ *i_pPt);


void __RPC_STUB IXYZTs_SetIXYZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZTs_GetIXYZ_Proxy( 
    IXYZTs * This,
    /* [retval][out] */ IXYZ **o_ppPt);


void __RPC_STUB IXYZTs_GetIXYZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZTs_GetXYZ_Proxy( 
    IXYZTs * This,
    /* [out] */ double *o_dx,
    /* [out] */ double *o_dy,
    /* [out] */ double *o_dz);


void __RPC_STUB IXYZTs_GetXYZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZTs_SetXYZ_Proxy( 
    IXYZTs * This,
    /* [in] */ double i_dx,
    /* [in] */ double i_dy,
    /* [in] */ double i_dz);


void __RPC_STUB IXYZTs_SetXYZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZTs_Save_Proxy( 
    IXYZTs * This,
    /* [in] */ ICxFiler *i_ipFiler);


void __RPC_STUB IXYZTs_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZTs_Load_Proxy( 
    IXYZTs * This,
    /* [in] */ ICxFiler *i_ipFiler);


void __RPC_STUB IXYZTs_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IXYZTs_INTERFACE_DEFINED__ */


#ifndef __IXYZTsArray_INTERFACE_DEFINED__
#define __IXYZTsArray_INTERFACE_DEFINED__

/* interface IXYZTsArray */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IXYZTsArray;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("86E71A50-11C5-4B77-99ED-5DAA533466EC")
    IXYZTsArray : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCXYZTsArray( 
            /* [out] */ LONG_PTR *o_plCXYZTsArrayAddress) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NewXYZTsArray( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetXYZTsArraySize( 
            /* [in] */ LONG i_Size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetXYZTsArraySize( 
            /* [retval][out] */ LONG *o_pSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetIXYZTs( 
            /* [in] */ int i_Index,
            /* [retval][out] */ IXYZTs **o_ppXYZTs) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetIXYZTs( 
            int i_Index,
            /* [in] */ IXYZTs *i_pXYZTs) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCXYZTsArray( 
            /* [in] */ LONG_PTR i_lXYZTsArrayAddress) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetXYZ( 
            /* [in] */ int i_Index,
            /* [out] */ double *o_dx,
            /* [out] */ double *o_dy,
            /* [out] */ double *o_dz) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetXYZ( 
            /* [in] */ int i_Index,
            /* [in] */ double i_dx,
            /* [in] */ double i_dy,
            /* [in] */ double i_dz) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IXYZTsArrayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXYZTsArray * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXYZTsArray * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXYZTsArray * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IXYZTsArray * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IXYZTsArray * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IXYZTsArray * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IXYZTsArray * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCXYZTsArray )( 
            IXYZTsArray * This,
            /* [out] */ LONG_PTR *o_plCXYZTsArrayAddress);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NewXYZTsArray )( 
            IXYZTsArray * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXYZTsArraySize )( 
            IXYZTsArray * This,
            /* [in] */ LONG i_Size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXYZTsArraySize )( 
            IXYZTsArray * This,
            /* [retval][out] */ LONG *o_pSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetIXYZTs )( 
            IXYZTsArray * This,
            /* [in] */ int i_Index,
            /* [retval][out] */ IXYZTs **o_ppXYZTs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetIXYZTs )( 
            IXYZTsArray * This,
            int i_Index,
            /* [in] */ IXYZTs *i_pXYZTs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCXYZTsArray )( 
            IXYZTsArray * This,
            /* [in] */ LONG_PTR i_lXYZTsArrayAddress);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXYZ )( 
            IXYZTsArray * This,
            /* [in] */ int i_Index,
            /* [out] */ double *o_dx,
            /* [out] */ double *o_dy,
            /* [out] */ double *o_dz);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXYZ )( 
            IXYZTsArray * This,
            /* [in] */ int i_Index,
            /* [in] */ double i_dx,
            /* [in] */ double i_dy,
            /* [in] */ double i_dz);
        
        END_INTERFACE
    } IXYZTsArrayVtbl;

    interface IXYZTsArray
    {
        CONST_VTBL struct IXYZTsArrayVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXYZTsArray_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IXYZTsArray_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IXYZTsArray_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IXYZTsArray_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IXYZTsArray_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IXYZTsArray_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IXYZTsArray_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IXYZTsArray_GetCXYZTsArray(This,o_plCXYZTsArrayAddress)	\
    (This)->lpVtbl -> GetCXYZTsArray(This,o_plCXYZTsArrayAddress)

#define IXYZTsArray_NewXYZTsArray(This)	\
    (This)->lpVtbl -> NewXYZTsArray(This)

#define IXYZTsArray_SetXYZTsArraySize(This,i_Size)	\
    (This)->lpVtbl -> SetXYZTsArraySize(This,i_Size)

#define IXYZTsArray_GetXYZTsArraySize(This,o_pSize)	\
    (This)->lpVtbl -> GetXYZTsArraySize(This,o_pSize)

#define IXYZTsArray_GetIXYZTs(This,i_Index,o_ppXYZTs)	\
    (This)->lpVtbl -> GetIXYZTs(This,i_Index,o_ppXYZTs)

#define IXYZTsArray_SetIXYZTs(This,i_Index,i_pXYZTs)	\
    (This)->lpVtbl -> SetIXYZTs(This,i_Index,i_pXYZTs)

#define IXYZTsArray_SetCXYZTsArray(This,i_lXYZTsArrayAddress)	\
    (This)->lpVtbl -> SetCXYZTsArray(This,i_lXYZTsArrayAddress)

#define IXYZTsArray_GetXYZ(This,i_Index,o_dx,o_dy,o_dz)	\
    (This)->lpVtbl -> GetXYZ(This,i_Index,o_dx,o_dy,o_dz)

#define IXYZTsArray_SetXYZ(This,i_Index,i_dx,i_dy,i_dz)	\
    (This)->lpVtbl -> SetXYZ(This,i_Index,i_dx,i_dy,i_dz)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZTsArray_GetCXYZTsArray_Proxy( 
    IXYZTsArray * This,
    /* [out] */ LONG_PTR *o_plCXYZTsArrayAddress);


void __RPC_STUB IXYZTsArray_GetCXYZTsArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZTsArray_NewXYZTsArray_Proxy( 
    IXYZTsArray * This);


void __RPC_STUB IXYZTsArray_NewXYZTsArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZTsArray_SetXYZTsArraySize_Proxy( 
    IXYZTsArray * This,
    /* [in] */ LONG i_Size);


void __RPC_STUB IXYZTsArray_SetXYZTsArraySize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZTsArray_GetXYZTsArraySize_Proxy( 
    IXYZTsArray * This,
    /* [retval][out] */ LONG *o_pSize);


void __RPC_STUB IXYZTsArray_GetXYZTsArraySize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZTsArray_GetIXYZTs_Proxy( 
    IXYZTsArray * This,
    /* [in] */ int i_Index,
    /* [retval][out] */ IXYZTs **o_ppXYZTs);


void __RPC_STUB IXYZTsArray_GetIXYZTs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZTsArray_SetIXYZTs_Proxy( 
    IXYZTsArray * This,
    int i_Index,
    /* [in] */ IXYZTs *i_pXYZTs);


void __RPC_STUB IXYZTsArray_SetIXYZTs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZTsArray_SetCXYZTsArray_Proxy( 
    IXYZTsArray * This,
    /* [in] */ LONG_PTR i_lXYZTsArrayAddress);


void __RPC_STUB IXYZTsArray_SetCXYZTsArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZTsArray_GetXYZ_Proxy( 
    IXYZTsArray * This,
    /* [in] */ int i_Index,
    /* [out] */ double *o_dx,
    /* [out] */ double *o_dy,
    /* [out] */ double *o_dz);


void __RPC_STUB IXYZTsArray_GetXYZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZTsArray_SetXYZ_Proxy( 
    IXYZTsArray * This,
    /* [in] */ int i_Index,
    /* [in] */ double i_dx,
    /* [in] */ double i_dy,
    /* [in] */ double i_dz);


void __RPC_STUB IXYZTsArray_SetXYZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IXYZTsArray_INTERFACE_DEFINED__ */


#ifndef __IXYZArray_INTERFACE_DEFINED__
#define __IXYZArray_INTERFACE_DEFINED__

/* interface IXYZArray */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IXYZArray;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("527AC569-0E21-4CE4-9985-EEF4AB3AE90D")
    IXYZArray : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCXYZArray( 
            /* [out] */ LONG_PTR *o_plCXYZArrayAddress) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCXYZArray( 
            /* [in] */ LONG_PTR i_lXYZArrayAddress) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NewXYZArray( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetXYZArraySize( 
            /* [in] */ LONG i_Size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetXYZArraySize( 
            /* [retval][out] */ LONG *o_pSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetIXYZ( 
            /* [in] */ int i_Index,
            /* [retval][out] */ IXYZ **o_ppXYZ) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetIXYZ( 
            /* [in] */ int i_Index,
            /* [in] */ IXYZ *i_pXYZ) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetXYZ( 
            /* [in] */ int i_Index,
            /* [out] */ double *o_dx,
            /* [out] */ double *o_dy,
            /* [out] */ double *o_dz) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetXYZ( 
            /* [in] */ int i_Index,
            /* [in] */ double i_dx,
            /* [in] */ double i_dy,
            /* [in] */ double i_dz) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IXYZArrayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXYZArray * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXYZArray * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXYZArray * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IXYZArray * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IXYZArray * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IXYZArray * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IXYZArray * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCXYZArray )( 
            IXYZArray * This,
            /* [out] */ LONG_PTR *o_plCXYZArrayAddress);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCXYZArray )( 
            IXYZArray * This,
            /* [in] */ LONG_PTR i_lXYZArrayAddress);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NewXYZArray )( 
            IXYZArray * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXYZArraySize )( 
            IXYZArray * This,
            /* [in] */ LONG i_Size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXYZArraySize )( 
            IXYZArray * This,
            /* [retval][out] */ LONG *o_pSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetIXYZ )( 
            IXYZArray * This,
            /* [in] */ int i_Index,
            /* [retval][out] */ IXYZ **o_ppXYZ);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetIXYZ )( 
            IXYZArray * This,
            /* [in] */ int i_Index,
            /* [in] */ IXYZ *i_pXYZ);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXYZ )( 
            IXYZArray * This,
            /* [in] */ int i_Index,
            /* [out] */ double *o_dx,
            /* [out] */ double *o_dy,
            /* [out] */ double *o_dz);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXYZ )( 
            IXYZArray * This,
            /* [in] */ int i_Index,
            /* [in] */ double i_dx,
            /* [in] */ double i_dy,
            /* [in] */ double i_dz);
        
        END_INTERFACE
    } IXYZArrayVtbl;

    interface IXYZArray
    {
        CONST_VTBL struct IXYZArrayVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXYZArray_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IXYZArray_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IXYZArray_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IXYZArray_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IXYZArray_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IXYZArray_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IXYZArray_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IXYZArray_GetCXYZArray(This,o_plCXYZArrayAddress)	\
    (This)->lpVtbl -> GetCXYZArray(This,o_plCXYZArrayAddress)

#define IXYZArray_SetCXYZArray(This,i_lXYZArrayAddress)	\
    (This)->lpVtbl -> SetCXYZArray(This,i_lXYZArrayAddress)

#define IXYZArray_NewXYZArray(This)	\
    (This)->lpVtbl -> NewXYZArray(This)

#define IXYZArray_SetXYZArraySize(This,i_Size)	\
    (This)->lpVtbl -> SetXYZArraySize(This,i_Size)

#define IXYZArray_GetXYZArraySize(This,o_pSize)	\
    (This)->lpVtbl -> GetXYZArraySize(This,o_pSize)

#define IXYZArray_GetIXYZ(This,i_Index,o_ppXYZ)	\
    (This)->lpVtbl -> GetIXYZ(This,i_Index,o_ppXYZ)

#define IXYZArray_SetIXYZ(This,i_Index,i_pXYZ)	\
    (This)->lpVtbl -> SetIXYZ(This,i_Index,i_pXYZ)

#define IXYZArray_GetXYZ(This,i_Index,o_dx,o_dy,o_dz)	\
    (This)->lpVtbl -> GetXYZ(This,i_Index,o_dx,o_dy,o_dz)

#define IXYZArray_SetXYZ(This,i_Index,i_dx,i_dy,i_dz)	\
    (This)->lpVtbl -> SetXYZ(This,i_Index,i_dx,i_dy,i_dz)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZArray_GetCXYZArray_Proxy( 
    IXYZArray * This,
    /* [out] */ LONG_PTR *o_plCXYZArrayAddress);


void __RPC_STUB IXYZArray_GetCXYZArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZArray_SetCXYZArray_Proxy( 
    IXYZArray * This,
    /* [in] */ LONG_PTR i_lXYZArrayAddress);


void __RPC_STUB IXYZArray_SetCXYZArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZArray_NewXYZArray_Proxy( 
    IXYZArray * This);


void __RPC_STUB IXYZArray_NewXYZArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZArray_SetXYZArraySize_Proxy( 
    IXYZArray * This,
    /* [in] */ LONG i_Size);


void __RPC_STUB IXYZArray_SetXYZArraySize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZArray_GetXYZArraySize_Proxy( 
    IXYZArray * This,
    /* [retval][out] */ LONG *o_pSize);


void __RPC_STUB IXYZArray_GetXYZArraySize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZArray_GetIXYZ_Proxy( 
    IXYZArray * This,
    /* [in] */ int i_Index,
    /* [retval][out] */ IXYZ **o_ppXYZ);


void __RPC_STUB IXYZArray_GetIXYZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZArray_SetIXYZ_Proxy( 
    IXYZArray * This,
    /* [in] */ int i_Index,
    /* [in] */ IXYZ *i_pXYZ);


void __RPC_STUB IXYZArray_SetIXYZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZArray_GetXYZ_Proxy( 
    IXYZArray * This,
    /* [in] */ int i_Index,
    /* [out] */ double *o_dx,
    /* [out] */ double *o_dy,
    /* [out] */ double *o_dz);


void __RPC_STUB IXYZArray_GetXYZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZArray_SetXYZ_Proxy( 
    IXYZArray * This,
    /* [in] */ int i_Index,
    /* [in] */ double i_dx,
    /* [in] */ double i_dy,
    /* [in] */ double i_dz);


void __RPC_STUB IXYZArray_SetXYZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IXYZArray_INTERFACE_DEFINED__ */


#ifndef __IXYZWArray_INTERFACE_DEFINED__
#define __IXYZWArray_INTERFACE_DEFINED__

/* interface IXYZWArray */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IXYZWArray;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CB4A6F4A-DD2C-4958-B733-6514C6331D9A")
    IXYZWArray : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCXYZWArray( 
            /* [out] */ LONG_PTR *o_plCXYZWArrayAddress) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCXYZWArray( 
            /* [in] */ LONG_PTR i_lXYZWArrayAddress) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NewXYZWArray( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetXYZWArraySize( 
            /* [in] */ LONG i_Size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetXYZWArraySize( 
            /* [retval][out] */ LONG *o_pSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetIXYZW( 
            /* [in] */ int i_Index,
            /* [retval][out] */ IXYZW **o_ppXYZW) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetIXYZW( 
            /* [in] */ int i_Index,
            /* [in] */ IXYZW *i_pXYZW) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetXYZW( 
            /* [in] */ int i_Index,
            /* [out] */ double *o_dx,
            /* [out] */ double *o_dy,
            /* [out] */ double *o_dz,
            /* [out] */ double *o_dw) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetXYZW( 
            /* [in] */ int i_Index,
            /* [in] */ double i_dx,
            /* [in] */ double i_dy,
            /* [in] */ double i_dz,
            /* [in] */ double i_dw) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IXYZWArrayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IXYZWArray * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IXYZWArray * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IXYZWArray * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IXYZWArray * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IXYZWArray * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IXYZWArray * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IXYZWArray * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCXYZWArray )( 
            IXYZWArray * This,
            /* [out] */ LONG_PTR *o_plCXYZWArrayAddress);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCXYZWArray )( 
            IXYZWArray * This,
            /* [in] */ LONG_PTR i_lXYZWArrayAddress);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NewXYZWArray )( 
            IXYZWArray * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXYZWArraySize )( 
            IXYZWArray * This,
            /* [in] */ LONG i_Size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXYZWArraySize )( 
            IXYZWArray * This,
            /* [retval][out] */ LONG *o_pSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetIXYZW )( 
            IXYZWArray * This,
            /* [in] */ int i_Index,
            /* [retval][out] */ IXYZW **o_ppXYZW);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetIXYZW )( 
            IXYZWArray * This,
            /* [in] */ int i_Index,
            /* [in] */ IXYZW *i_pXYZW);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXYZW )( 
            IXYZWArray * This,
            /* [in] */ int i_Index,
            /* [out] */ double *o_dx,
            /* [out] */ double *o_dy,
            /* [out] */ double *o_dz,
            /* [out] */ double *o_dw);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXYZW )( 
            IXYZWArray * This,
            /* [in] */ int i_Index,
            /* [in] */ double i_dx,
            /* [in] */ double i_dy,
            /* [in] */ double i_dz,
            /* [in] */ double i_dw);
        
        END_INTERFACE
    } IXYZWArrayVtbl;

    interface IXYZWArray
    {
        CONST_VTBL struct IXYZWArrayVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXYZWArray_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IXYZWArray_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IXYZWArray_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IXYZWArray_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IXYZWArray_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IXYZWArray_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IXYZWArray_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IXYZWArray_GetCXYZWArray(This,o_plCXYZWArrayAddress)	\
    (This)->lpVtbl -> GetCXYZWArray(This,o_plCXYZWArrayAddress)

#define IXYZWArray_SetCXYZWArray(This,i_lXYZWArrayAddress)	\
    (This)->lpVtbl -> SetCXYZWArray(This,i_lXYZWArrayAddress)

#define IXYZWArray_NewXYZWArray(This)	\
    (This)->lpVtbl -> NewXYZWArray(This)

#define IXYZWArray_SetXYZWArraySize(This,i_Size)	\
    (This)->lpVtbl -> SetXYZWArraySize(This,i_Size)

#define IXYZWArray_GetXYZWArraySize(This,o_pSize)	\
    (This)->lpVtbl -> GetXYZWArraySize(This,o_pSize)

#define IXYZWArray_GetIXYZW(This,i_Index,o_ppXYZW)	\
    (This)->lpVtbl -> GetIXYZW(This,i_Index,o_ppXYZW)

#define IXYZWArray_SetIXYZW(This,i_Index,i_pXYZW)	\
    (This)->lpVtbl -> SetIXYZW(This,i_Index,i_pXYZW)

#define IXYZWArray_GetXYZW(This,i_Index,o_dx,o_dy,o_dz,o_dw)	\
    (This)->lpVtbl -> GetXYZW(This,i_Index,o_dx,o_dy,o_dz,o_dw)

#define IXYZWArray_SetXYZW(This,i_Index,i_dx,i_dy,i_dz,i_dw)	\
    (This)->lpVtbl -> SetXYZW(This,i_Index,i_dx,i_dy,i_dz,i_dw)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZWArray_GetCXYZWArray_Proxy( 
    IXYZWArray * This,
    /* [out] */ LONG_PTR *o_plCXYZWArrayAddress);


void __RPC_STUB IXYZWArray_GetCXYZWArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZWArray_SetCXYZWArray_Proxy( 
    IXYZWArray * This,
    /* [in] */ LONG_PTR i_lXYZWArrayAddress);


void __RPC_STUB IXYZWArray_SetCXYZWArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZWArray_NewXYZWArray_Proxy( 
    IXYZWArray * This);


void __RPC_STUB IXYZWArray_NewXYZWArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZWArray_SetXYZWArraySize_Proxy( 
    IXYZWArray * This,
    /* [in] */ LONG i_Size);


void __RPC_STUB IXYZWArray_SetXYZWArraySize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZWArray_GetXYZWArraySize_Proxy( 
    IXYZWArray * This,
    /* [retval][out] */ LONG *o_pSize);


void __RPC_STUB IXYZWArray_GetXYZWArraySize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZWArray_GetIXYZW_Proxy( 
    IXYZWArray * This,
    /* [in] */ int i_Index,
    /* [retval][out] */ IXYZW **o_ppXYZW);


void __RPC_STUB IXYZWArray_GetIXYZW_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZWArray_SetIXYZW_Proxy( 
    IXYZWArray * This,
    /* [in] */ int i_Index,
    /* [in] */ IXYZW *i_pXYZW);


void __RPC_STUB IXYZWArray_SetIXYZW_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZWArray_GetXYZW_Proxy( 
    IXYZWArray * This,
    /* [in] */ int i_Index,
    /* [out] */ double *o_dx,
    /* [out] */ double *o_dy,
    /* [out] */ double *o_dz,
    /* [out] */ double *o_dw);


void __RPC_STUB IXYZWArray_GetXYZW_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IXYZWArray_SetXYZW_Proxy( 
    IXYZWArray * This,
    /* [in] */ int i_Index,
    /* [in] */ double i_dx,
    /* [in] */ double i_dy,
    /* [in] */ double i_dz,
    /* [in] */ double i_dw);


void __RPC_STUB IXYZWArray_SetXYZW_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IXYZWArray_INTERFACE_DEFINED__ */


#ifndef __IVectorArray_INTERFACE_DEFINED__
#define __IVectorArray_INTERFACE_DEFINED__

/* interface IVectorArray */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IVectorArray;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("567B7ABE-39F7-477B-A696-44597B6FE885")
    IVectorArray : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCVectorArray( 
            /* [out] */ LONG_PTR *o_plCVectorArrayAddress) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCVectorArray( 
            /* [in] */ LONG_PTR i_lVectorArrayAddress) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NewVectorArray( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetVectorArraySize( 
            /* [in] */ LONG i_Size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVectorArraySize( 
            /* [retval][out] */ LONG *o_pSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetIVector( 
            /* [in] */ int i_Index,
            /* [retval][out] */ IVector **o_ppVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetIVector( 
            /* [in] */ int i_Index,
            /* [in] */ IVector *i_pVec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetXYZ( 
            /* [in] */ int i_Index,
            /* [out] */ double *o_dx,
            /* [out] */ double *o_dy,
            /* [out] */ double *o_dz) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetXYZ( 
            /* [in] */ int i_Index,
            /* [in] */ double i_dx,
            /* [in] */ double i_dy,
            /* [in] */ double i_dz) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVectorArrayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVectorArray * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVectorArray * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVectorArray * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IVectorArray * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IVectorArray * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IVectorArray * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IVectorArray * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCVectorArray )( 
            IVectorArray * This,
            /* [out] */ LONG_PTR *o_plCVectorArrayAddress);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCVectorArray )( 
            IVectorArray * This,
            /* [in] */ LONG_PTR i_lVectorArrayAddress);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NewVectorArray )( 
            IVectorArray * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetVectorArraySize )( 
            IVectorArray * This,
            /* [in] */ LONG i_Size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetVectorArraySize )( 
            IVectorArray * This,
            /* [retval][out] */ LONG *o_pSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetIVector )( 
            IVectorArray * This,
            /* [in] */ int i_Index,
            /* [retval][out] */ IVector **o_ppVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetIVector )( 
            IVectorArray * This,
            /* [in] */ int i_Index,
            /* [in] */ IVector *i_pVec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetXYZ )( 
            IVectorArray * This,
            /* [in] */ int i_Index,
            /* [out] */ double *o_dx,
            /* [out] */ double *o_dy,
            /* [out] */ double *o_dz);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetXYZ )( 
            IVectorArray * This,
            /* [in] */ int i_Index,
            /* [in] */ double i_dx,
            /* [in] */ double i_dy,
            /* [in] */ double i_dz);
        
        END_INTERFACE
    } IVectorArrayVtbl;

    interface IVectorArray
    {
        CONST_VTBL struct IVectorArrayVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVectorArray_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVectorArray_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVectorArray_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVectorArray_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IVectorArray_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IVectorArray_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IVectorArray_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IVectorArray_GetCVectorArray(This,o_plCVectorArrayAddress)	\
    (This)->lpVtbl -> GetCVectorArray(This,o_plCVectorArrayAddress)

#define IVectorArray_SetCVectorArray(This,i_lVectorArrayAddress)	\
    (This)->lpVtbl -> SetCVectorArray(This,i_lVectorArrayAddress)

#define IVectorArray_NewVectorArray(This)	\
    (This)->lpVtbl -> NewVectorArray(This)

#define IVectorArray_SetVectorArraySize(This,i_Size)	\
    (This)->lpVtbl -> SetVectorArraySize(This,i_Size)

#define IVectorArray_GetVectorArraySize(This,o_pSize)	\
    (This)->lpVtbl -> GetVectorArraySize(This,o_pSize)

#define IVectorArray_GetIVector(This,i_Index,o_ppVec)	\
    (This)->lpVtbl -> GetIVector(This,i_Index,o_ppVec)

#define IVectorArray_SetIVector(This,i_Index,i_pVec)	\
    (This)->lpVtbl -> SetIVector(This,i_Index,i_pVec)

#define IVectorArray_GetXYZ(This,i_Index,o_dx,o_dy,o_dz)	\
    (This)->lpVtbl -> GetXYZ(This,i_Index,o_dx,o_dy,o_dz)

#define IVectorArray_SetXYZ(This,i_Index,i_dx,i_dy,i_dz)	\
    (This)->lpVtbl -> SetXYZ(This,i_Index,i_dx,i_dy,i_dz)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVectorArray_GetCVectorArray_Proxy( 
    IVectorArray * This,
    /* [out] */ LONG_PTR *o_plCVectorArrayAddress);


void __RPC_STUB IVectorArray_GetCVectorArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVectorArray_SetCVectorArray_Proxy( 
    IVectorArray * This,
    /* [in] */ LONG_PTR i_lVectorArrayAddress);


void __RPC_STUB IVectorArray_SetCVectorArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVectorArray_NewVectorArray_Proxy( 
    IVectorArray * This);


void __RPC_STUB IVectorArray_NewVectorArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVectorArray_SetVectorArraySize_Proxy( 
    IVectorArray * This,
    /* [in] */ LONG i_Size);


void __RPC_STUB IVectorArray_SetVectorArraySize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVectorArray_GetVectorArraySize_Proxy( 
    IVectorArray * This,
    /* [retval][out] */ LONG *o_pSize);


void __RPC_STUB IVectorArray_GetVectorArraySize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVectorArray_GetIVector_Proxy( 
    IVectorArray * This,
    /* [in] */ int i_Index,
    /* [retval][out] */ IVector **o_ppVec);


void __RPC_STUB IVectorArray_GetIVector_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVectorArray_SetIVector_Proxy( 
    IVectorArray * This,
    /* [in] */ int i_Index,
    /* [in] */ IVector *i_pVec);


void __RPC_STUB IVectorArray_SetIVector_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVectorArray_GetXYZ_Proxy( 
    IVectorArray * This,
    /* [in] */ int i_Index,
    /* [out] */ double *o_dx,
    /* [out] */ double *o_dy,
    /* [out] */ double *o_dz);


void __RPC_STUB IVectorArray_GetXYZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IVectorArray_SetXYZ_Proxy( 
    IVectorArray * This,
    /* [in] */ int i_Index,
    /* [in] */ double i_dx,
    /* [in] */ double i_dy,
    /* [in] */ double i_dz);


void __RPC_STUB IVectorArray_SetXYZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVectorArray_INTERFACE_DEFINED__ */


#ifndef __IMathTool_INTERFACE_DEFINED__
#define __IMathTool_INTERFACE_DEFINED__

/* interface IMathTool */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMathTool;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B7482EB0-B007-461B-B920-F9D8CA0422DC")
    IMathTool : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPI( 
            /* [retval][out] */ double *o_pdPI) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetInfinite( 
            /* [retval][out] */ double *o_pdInf) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMaxInt( 
            /* [retval][out] */ int *o_piMaxInt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMaxLen( 
            /* [retval][out] */ double *o_pdMaxLen) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMaxInt( 
            /* [in] */ int i_iMaxInt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMaxLen( 
            /* [in] */ double i_dMaxLen) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetArcCos( 
            /* [in] */ double i_dVal,
            /* [retval][out] */ double *o_pdArcCos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDeterm( 
            /* [in] */ double i_dA1,
            /* [in] */ double i_dA2,
            /* [in] */ double i_dA3,
            /* [in] */ double i_dB1,
            /* [in] */ double i_dB2,
            /* [in] */ double i_dB3,
            /* [in] */ double i_dC1,
            /* [in] */ double i_dC2,
            /* [in] */ double i_dC3,
            /* [retval][out] */ double *o_pdDeterm) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTol( 
            /* [retval][out] */ ITolerance **o_ppTol) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetTol( 
            /* [in] */ ITolerance *i_pTol) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMathToolVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMathTool * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMathTool * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMathTool * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMathTool * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMathTool * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMathTool * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMathTool * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPI )( 
            IMathTool * This,
            /* [retval][out] */ double *o_pdPI);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetInfinite )( 
            IMathTool * This,
            /* [retval][out] */ double *o_pdInf);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMaxInt )( 
            IMathTool * This,
            /* [retval][out] */ int *o_piMaxInt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMaxLen )( 
            IMathTool * This,
            /* [retval][out] */ double *o_pdMaxLen);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetMaxInt )( 
            IMathTool * This,
            /* [in] */ int i_iMaxInt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetMaxLen )( 
            IMathTool * This,
            /* [in] */ double i_dMaxLen);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetArcCos )( 
            IMathTool * This,
            /* [in] */ double i_dVal,
            /* [retval][out] */ double *o_pdArcCos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDeterm )( 
            IMathTool * This,
            /* [in] */ double i_dA1,
            /* [in] */ double i_dA2,
            /* [in] */ double i_dA3,
            /* [in] */ double i_dB1,
            /* [in] */ double i_dB2,
            /* [in] */ double i_dB3,
            /* [in] */ double i_dC1,
            /* [in] */ double i_dC2,
            /* [in] */ double i_dC3,
            /* [retval][out] */ double *o_pdDeterm);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTol )( 
            IMathTool * This,
            /* [retval][out] */ ITolerance **o_ppTol);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetTol )( 
            IMathTool * This,
            /* [in] */ ITolerance *i_pTol);
        
        END_INTERFACE
    } IMathToolVtbl;

    interface IMathTool
    {
        CONST_VTBL struct IMathToolVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMathTool_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMathTool_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMathTool_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMathTool_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IMathTool_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IMathTool_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IMathTool_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IMathTool_GetPI(This,o_pdPI)	\
    (This)->lpVtbl -> GetPI(This,o_pdPI)

#define IMathTool_GetInfinite(This,o_pdInf)	\
    (This)->lpVtbl -> GetInfinite(This,o_pdInf)

#define IMathTool_GetMaxInt(This,o_piMaxInt)	\
    (This)->lpVtbl -> GetMaxInt(This,o_piMaxInt)

#define IMathTool_GetMaxLen(This,o_pdMaxLen)	\
    (This)->lpVtbl -> GetMaxLen(This,o_pdMaxLen)

#define IMathTool_SetMaxInt(This,i_iMaxInt)	\
    (This)->lpVtbl -> SetMaxInt(This,i_iMaxInt)

#define IMathTool_SetMaxLen(This,i_dMaxLen)	\
    (This)->lpVtbl -> SetMaxLen(This,i_dMaxLen)

#define IMathTool_GetArcCos(This,i_dVal,o_pdArcCos)	\
    (This)->lpVtbl -> GetArcCos(This,i_dVal,o_pdArcCos)

#define IMathTool_GetDeterm(This,i_dA1,i_dA2,i_dA3,i_dB1,i_dB2,i_dB3,i_dC1,i_dC2,i_dC3,o_pdDeterm)	\
    (This)->lpVtbl -> GetDeterm(This,i_dA1,i_dA2,i_dA3,i_dB1,i_dB2,i_dB3,i_dC1,i_dC2,i_dC3,o_pdDeterm)

#define IMathTool_GetTol(This,o_ppTol)	\
    (This)->lpVtbl -> GetTol(This,o_ppTol)

#define IMathTool_SetTol(This,i_pTol)	\
    (This)->lpVtbl -> SetTol(This,i_pTol)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMathTool_GetPI_Proxy( 
    IMathTool * This,
    /* [retval][out] */ double *o_pdPI);


void __RPC_STUB IMathTool_GetPI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMathTool_GetInfinite_Proxy( 
    IMathTool * This,
    /* [retval][out] */ double *o_pdInf);


void __RPC_STUB IMathTool_GetInfinite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMathTool_GetMaxInt_Proxy( 
    IMathTool * This,
    /* [retval][out] */ int *o_piMaxInt);


void __RPC_STUB IMathTool_GetMaxInt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMathTool_GetMaxLen_Proxy( 
    IMathTool * This,
    /* [retval][out] */ double *o_pdMaxLen);


void __RPC_STUB IMathTool_GetMaxLen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMathTool_SetMaxInt_Proxy( 
    IMathTool * This,
    /* [in] */ int i_iMaxInt);


void __RPC_STUB IMathTool_SetMaxInt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMathTool_SetMaxLen_Proxy( 
    IMathTool * This,
    /* [in] */ double i_dMaxLen);


void __RPC_STUB IMathTool_SetMaxLen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMathTool_GetArcCos_Proxy( 
    IMathTool * This,
    /* [in] */ double i_dVal,
    /* [retval][out] */ double *o_pdArcCos);


void __RPC_STUB IMathTool_GetArcCos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMathTool_GetDeterm_Proxy( 
    IMathTool * This,
    /* [in] */ double i_dA1,
    /* [in] */ double i_dA2,
    /* [in] */ double i_dA3,
    /* [in] */ double i_dB1,
    /* [in] */ double i_dB2,
    /* [in] */ double i_dB3,
    /* [in] */ double i_dC1,
    /* [in] */ double i_dC2,
    /* [in] */ double i_dC3,
    /* [retval][out] */ double *o_pdDeterm);


void __RPC_STUB IMathTool_GetDeterm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMathTool_GetTol_Proxy( 
    IMathTool * This,
    /* [retval][out] */ ITolerance **o_ppTol);


void __RPC_STUB IMathTool_GetTol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IMathTool_SetTol_Proxy( 
    IMathTool * This,
    /* [in] */ ITolerance *i_pTol);


void __RPC_STUB IMathTool_SetTol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMathTool_INTERFACE_DEFINED__ */


#ifndef __ITolerance_INTERFACE_DEFINED__
#define __ITolerance_INTERFACE_DEFINED__

/* interface ITolerance */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITolerance;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C1E6CEC4-9F14-4E62-A686-4554FA69AAB1")
    ITolerance : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDist( 
            /* [in] */ double i_dVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CopyFrom( 
            /* [in] */ ITolerance *i_pTol) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMath( 
            /* [retval][out] */ double *o_dMath) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPara( 
            /* [retval][out] */ double *o_dPara) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDist( 
            /* [retval][out] */ double *o_dDist) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAngDeg( 
            /* [retval][out] */ double *o_dAngDeg) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAngRad( 
            /* [retval][out] */ double *o_dAngRad) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetArea( 
            /* [retval][out] */ double *o_dArea) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLink( 
            /* [retval][out] */ double *o_dLink) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMaxLen( 
            /* [in] */ double i_dMaxLen) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCTol( 
            /* [out] */ LONG_PTR *o_pAddress) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IToleranceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITolerance * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITolerance * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITolerance * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITolerance * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITolerance * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITolerance * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITolerance * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDist )( 
            ITolerance * This,
            /* [in] */ double i_dVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CopyFrom )( 
            ITolerance * This,
            /* [in] */ ITolerance *i_pTol);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMath )( 
            ITolerance * This,
            /* [retval][out] */ double *o_dMath);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPara )( 
            ITolerance * This,
            /* [retval][out] */ double *o_dPara);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDist )( 
            ITolerance * This,
            /* [retval][out] */ double *o_dDist);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAngDeg )( 
            ITolerance * This,
            /* [retval][out] */ double *o_dAngDeg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAngRad )( 
            ITolerance * This,
            /* [retval][out] */ double *o_dAngRad);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetArea )( 
            ITolerance * This,
            /* [retval][out] */ double *o_dArea);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLink )( 
            ITolerance * This,
            /* [retval][out] */ double *o_dLink);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetMaxLen )( 
            ITolerance * This,
            /* [in] */ double i_dMaxLen);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCTol )( 
            ITolerance * This,
            /* [out] */ LONG_PTR *o_pAddress);
        
        END_INTERFACE
    } IToleranceVtbl;

    interface ITolerance
    {
        CONST_VTBL struct IToleranceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITolerance_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITolerance_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITolerance_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITolerance_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ITolerance_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ITolerance_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ITolerance_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ITolerance_SetDist(This,i_dVal)	\
    (This)->lpVtbl -> SetDist(This,i_dVal)

#define ITolerance_CopyFrom(This,i_pTol)	\
    (This)->lpVtbl -> CopyFrom(This,i_pTol)

#define ITolerance_GetMath(This,o_dMath)	\
    (This)->lpVtbl -> GetMath(This,o_dMath)

#define ITolerance_GetPara(This,o_dPara)	\
    (This)->lpVtbl -> GetPara(This,o_dPara)

#define ITolerance_GetDist(This,o_dDist)	\
    (This)->lpVtbl -> GetDist(This,o_dDist)

#define ITolerance_GetAngDeg(This,o_dAngDeg)	\
    (This)->lpVtbl -> GetAngDeg(This,o_dAngDeg)

#define ITolerance_GetAngRad(This,o_dAngRad)	\
    (This)->lpVtbl -> GetAngRad(This,o_dAngRad)

#define ITolerance_GetArea(This,o_dArea)	\
    (This)->lpVtbl -> GetArea(This,o_dArea)

#define ITolerance_GetLink(This,o_dLink)	\
    (This)->lpVtbl -> GetLink(This,o_dLink)

#define ITolerance_SetMaxLen(This,i_dMaxLen)	\
    (This)->lpVtbl -> SetMaxLen(This,i_dMaxLen)

#define ITolerance_GetCTol(This,o_pAddress)	\
    (This)->lpVtbl -> GetCTol(This,o_pAddress)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITolerance_SetDist_Proxy( 
    ITolerance * This,
    /* [in] */ double i_dVal);


void __RPC_STUB ITolerance_SetDist_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITolerance_CopyFrom_Proxy( 
    ITolerance * This,
    /* [in] */ ITolerance *i_pTol);


void __RPC_STUB ITolerance_CopyFrom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITolerance_GetMath_Proxy( 
    ITolerance * This,
    /* [retval][out] */ double *o_dMath);


void __RPC_STUB ITolerance_GetMath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITolerance_GetPara_Proxy( 
    ITolerance * This,
    /* [retval][out] */ double *o_dPara);


void __RPC_STUB ITolerance_GetPara_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITolerance_GetDist_Proxy( 
    ITolerance * This,
    /* [retval][out] */ double *o_dDist);


void __RPC_STUB ITolerance_GetDist_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITolerance_GetAngDeg_Proxy( 
    ITolerance * This,
    /* [retval][out] */ double *o_dAngDeg);


void __RPC_STUB ITolerance_GetAngDeg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITolerance_GetAngRad_Proxy( 
    ITolerance * This,
    /* [retval][out] */ double *o_dAngRad);


void __RPC_STUB ITolerance_GetAngRad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITolerance_GetArea_Proxy( 
    ITolerance * This,
    /* [retval][out] */ double *o_dArea);


void __RPC_STUB ITolerance_GetArea_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITolerance_GetLink_Proxy( 
    ITolerance * This,
    /* [retval][out] */ double *o_dLink);


void __RPC_STUB ITolerance_GetLink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITolerance_SetMaxLen_Proxy( 
    ITolerance * This,
    /* [in] */ double i_dMaxLen);


void __RPC_STUB ITolerance_SetMaxLen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ITolerance_GetCTol_Proxy( 
    ITolerance * This,
    /* [out] */ LONG_PTR *o_pAddress);


void __RPC_STUB ITolerance_GetCTol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITolerance_INTERFACE_DEFINED__ */


#ifndef __ICxIXYZColl_INTERFACE_DEFINED__
#define __ICxIXYZColl_INTERFACE_DEFINED__

/* interface ICxIXYZColl */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICxIXYZColl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C750BDBE-1906-4ed8-8AF3-B6689C0944E1")
    ICxIXYZColl : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCount( 
            /* [retval][out] */ SIZE_T *o_plCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsEmpty( 
            /* [retval][out] */ VARIANT_BOOL *o_pbEmpty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetHead( 
            /* [retval][out] */ IXYZ **o_ppItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTail( 
            /* [retval][out] */ IXYZ **o_ppItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveHead( 
            /* [retval][out] */ IXYZ **o_ppItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveTail( 
            /* [retval][out] */ IXYZ **o_ppItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveHeadNoReturn( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveTailNoReturn( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveItem( 
            /* [in] */ IXYZ *i_pItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveAll( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddHead( 
            /* [in] */ IXYZ *i_pItem,
            /* [defaultvalue][out][in] */ LONG_PTR *o_lpPosition = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddHeadColl( 
            /* [in] */ ICxIXYZColl *i_pColl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddTail( 
            /* [in] */ IXYZ *i_pItem,
            /* [defaultvalue][out][in] */ LONG_PTR *o_lpPosition = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddTailColl( 
            /* [in] */ ICxIXYZColl *i_pColl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetHeadPosition( 
            /* [retval][out] */ LONG_PTR *o_pPos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTailPosition( 
            /* [retval][out] */ LONG_PTR *o_pPos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNext( 
            /* [out][in] */ LONG_PTR *io_pPos,
            /* [retval][out] */ IXYZ **o_ppItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPrev( 
            /* [out][in] */ LONG_PTR *io_pPos,
            /* [retval][out] */ IXYZ **o_ppItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAt( 
            /* [in] */ LONG_PTR i_pos,
            /* [retval][out] */ IXYZ **o_ppItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAt( 
            /* [in] */ LONG_PTR i_pos,
            /* [in] */ IXYZ *i_pItem) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveAt( 
            /* [in] */ LONG_PTR i_pos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InsertAfter( 
            /* [in] */ IXYZ *i_pItem,
            /* [out][in] */ LONG_PTR *io_lpPosition) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InsertBefore( 
            /* [in] */ IXYZ *i_pItem,
            /* [out][in] */ LONG_PTR *io_lpPosition) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Find( 
            /* [in] */ IXYZ *i_pItem,
            /* [in] */ LONG_PTR i_posStart,
            /* [out][in] */ LONG_PTR *o_pPos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindIndex( 
            /* [in] */ SIZE_T i_lIndex,
            /* [retval][out] */ LONG_PTR *o_lpPosition) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveToHead( 
            /* [in] */ LONG_PTR i_pos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveToTail( 
            /* [in] */ LONG_PTR i_pos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SwapElements( 
            /* [in] */ LONG_PTR i_pos1,
            /* [in] */ LONG_PTR i_pos2) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ ICxIXYZColl **o_ppXYZColl) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICxIXYZCollVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICxIXYZColl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICxIXYZColl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICxIXYZColl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICxIXYZColl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICxIXYZColl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICxIXYZColl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICxIXYZColl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            ICxIXYZColl * This,
            /* [retval][out] */ SIZE_T *o_plCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsEmpty )( 
            ICxIXYZColl * This,
            /* [retval][out] */ VARIANT_BOOL *o_pbEmpty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetHead )( 
            ICxIXYZColl * This,
            /* [retval][out] */ IXYZ **o_ppItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTail )( 
            ICxIXYZColl * This,
            /* [retval][out] */ IXYZ **o_ppItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveHead )( 
            ICxIXYZColl * This,
            /* [retval][out] */ IXYZ **o_ppItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveTail )( 
            ICxIXYZColl * This,
            /* [retval][out] */ IXYZ **o_ppItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveHeadNoReturn )( 
            ICxIXYZColl * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveTailNoReturn )( 
            ICxIXYZColl * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveItem )( 
            ICxIXYZColl * This,
            /* [in] */ IXYZ *i_pItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveAll )( 
            ICxIXYZColl * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddHead )( 
            ICxIXYZColl * This,
            /* [in] */ IXYZ *i_pItem,
            /* [defaultvalue][out][in] */ LONG_PTR *o_lpPosition);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddHeadColl )( 
            ICxIXYZColl * This,
            /* [in] */ ICxIXYZColl *i_pColl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddTail )( 
            ICxIXYZColl * This,
            /* [in] */ IXYZ *i_pItem,
            /* [defaultvalue][out][in] */ LONG_PTR *o_lpPosition);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddTailColl )( 
            ICxIXYZColl * This,
            /* [in] */ ICxIXYZColl *i_pColl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetHeadPosition )( 
            ICxIXYZColl * This,
            /* [retval][out] */ LONG_PTR *o_pPos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTailPosition )( 
            ICxIXYZColl * This,
            /* [retval][out] */ LONG_PTR *o_pPos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNext )( 
            ICxIXYZColl * This,
            /* [out][in] */ LONG_PTR *io_pPos,
            /* [retval][out] */ IXYZ **o_ppItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPrev )( 
            ICxIXYZColl * This,
            /* [out][in] */ LONG_PTR *io_pPos,
            /* [retval][out] */ IXYZ **o_ppItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAt )( 
            ICxIXYZColl * This,
            /* [in] */ LONG_PTR i_pos,
            /* [retval][out] */ IXYZ **o_ppItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetAt )( 
            ICxIXYZColl * This,
            /* [in] */ LONG_PTR i_pos,
            /* [in] */ IXYZ *i_pItem);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveAt )( 
            ICxIXYZColl * This,
            /* [in] */ LONG_PTR i_pos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InsertAfter )( 
            ICxIXYZColl * This,
            /* [in] */ IXYZ *i_pItem,
            /* [out][in] */ LONG_PTR *io_lpPosition);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InsertBefore )( 
            ICxIXYZColl * This,
            /* [in] */ IXYZ *i_pItem,
            /* [out][in] */ LONG_PTR *io_lpPosition);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Find )( 
            ICxIXYZColl * This,
            /* [in] */ IXYZ *i_pItem,
            /* [in] */ LONG_PTR i_posStart,
            /* [out][in] */ LONG_PTR *o_pPos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindIndex )( 
            ICxIXYZColl * This,
            /* [in] */ SIZE_T i_lIndex,
            /* [retval][out] */ LONG_PTR *o_lpPosition);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveToHead )( 
            ICxIXYZColl * This,
            /* [in] */ LONG_PTR i_pos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveToTail )( 
            ICxIXYZColl * This,
            /* [in] */ LONG_PTR i_pos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SwapElements )( 
            ICxIXYZColl * This,
            /* [in] */ LONG_PTR i_pos1,
            /* [in] */ LONG_PTR i_pos2);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clone )( 
            ICxIXYZColl * This,
            /* [out] */ ICxIXYZColl **o_ppXYZColl);
        
        END_INTERFACE
    } ICxIXYZCollVtbl;

    interface ICxIXYZColl
    {
        CONST_VTBL struct ICxIXYZCollVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICxIXYZColl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICxIXYZColl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICxIXYZColl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICxIXYZColl_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICxIXYZColl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICxIXYZColl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICxIXYZColl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICxIXYZColl_GetCount(This,o_plCount)	\
    (This)->lpVtbl -> GetCount(This,o_plCount)

#define ICxIXYZColl_IsEmpty(This,o_pbEmpty)	\
    (This)->lpVtbl -> IsEmpty(This,o_pbEmpty)

#define ICxIXYZColl_GetHead(This,o_ppItem)	\
    (This)->lpVtbl -> GetHead(This,o_ppItem)

#define ICxIXYZColl_GetTail(This,o_ppItem)	\
    (This)->lpVtbl -> GetTail(This,o_ppItem)

#define ICxIXYZColl_RemoveHead(This,o_ppItem)	\
    (This)->lpVtbl -> RemoveHead(This,o_ppItem)

#define ICxIXYZColl_RemoveTail(This,o_ppItem)	\
    (This)->lpVtbl -> RemoveTail(This,o_ppItem)

#define ICxIXYZColl_RemoveHeadNoReturn(This)	\
    (This)->lpVtbl -> RemoveHeadNoReturn(This)

#define ICxIXYZColl_RemoveTailNoReturn(This)	\
    (This)->lpVtbl -> RemoveTailNoReturn(This)

#define ICxIXYZColl_RemoveItem(This,i_pItem)	\
    (This)->lpVtbl -> RemoveItem(This,i_pItem)

#define ICxIXYZColl_RemoveAll(This)	\
    (This)->lpVtbl -> RemoveAll(This)

#define ICxIXYZColl_AddHead(This,i_pItem,o_lpPosition)	\
    (This)->lpVtbl -> AddHead(This,i_pItem,o_lpPosition)

#define ICxIXYZColl_AddHeadColl(This,i_pColl)	\
    (This)->lpVtbl -> AddHeadColl(This,i_pColl)

#define ICxIXYZColl_AddTail(This,i_pItem,o_lpPosition)	\
    (This)->lpVtbl -> AddTail(This,i_pItem,o_lpPosition)

#define ICxIXYZColl_AddTailColl(This,i_pColl)	\
    (This)->lpVtbl -> AddTailColl(This,i_pColl)

#define ICxIXYZColl_GetHeadPosition(This,o_pPos)	\
    (This)->lpVtbl -> GetHeadPosition(This,o_pPos)

#define ICxIXYZColl_GetTailPosition(This,o_pPos)	\
    (This)->lpVtbl -> GetTailPosition(This,o_pPos)

#define ICxIXYZColl_GetNext(This,io_pPos,o_ppItem)	\
    (This)->lpVtbl -> GetNext(This,io_pPos,o_ppItem)

#define ICxIXYZColl_GetPrev(This,io_pPos,o_ppItem)	\
    (This)->lpVtbl -> GetPrev(This,io_pPos,o_ppItem)

#define ICxIXYZColl_GetAt(This,i_pos,o_ppItem)	\
    (This)->lpVtbl -> GetAt(This,i_pos,o_ppItem)

#define ICxIXYZColl_SetAt(This,i_pos,i_pItem)	\
    (This)->lpVtbl -> SetAt(This,i_pos,i_pItem)

#define ICxIXYZColl_RemoveAt(This,i_pos)	\
    (This)->lpVtbl -> RemoveAt(This,i_pos)

#define ICxIXYZColl_InsertAfter(This,i_pItem,io_lpPosition)	\
    (This)->lpVtbl -> InsertAfter(This,i_pItem,io_lpPosition)

#define ICxIXYZColl_InsertBefore(This,i_pItem,io_lpPosition)	\
    (This)->lpVtbl -> InsertBefore(This,i_pItem,io_lpPosition)

#define ICxIXYZColl_Find(This,i_pItem,i_posStart,o_pPos)	\
    (This)->lpVtbl -> Find(This,i_pItem,i_posStart,o_pPos)

#define ICxIXYZColl_FindIndex(This,i_lIndex,o_lpPosition)	\
    (This)->lpVtbl -> FindIndex(This,i_lIndex,o_lpPosition)

#define ICxIXYZColl_MoveToHead(This,i_pos)	\
    (This)->lpVtbl -> MoveToHead(This,i_pos)

#define ICxIXYZColl_MoveToTail(This,i_pos)	\
    (This)->lpVtbl -> MoveToTail(This,i_pos)

#define ICxIXYZColl_SwapElements(This,i_pos1,i_pos2)	\
    (This)->lpVtbl -> SwapElements(This,i_pos1,i_pos2)

#define ICxIXYZColl_Clone(This,o_ppXYZColl)	\
    (This)->lpVtbl -> Clone(This,o_ppXYZColl)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_GetCount_Proxy( 
    ICxIXYZColl * This,
    /* [retval][out] */ SIZE_T *o_plCount);


void __RPC_STUB ICxIXYZColl_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_IsEmpty_Proxy( 
    ICxIXYZColl * This,
    /* [retval][out] */ VARIANT_BOOL *o_pbEmpty);


void __RPC_STUB ICxIXYZColl_IsEmpty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_GetHead_Proxy( 
    ICxIXYZColl * This,
    /* [retval][out] */ IXYZ **o_ppItem);


void __RPC_STUB ICxIXYZColl_GetHead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_GetTail_Proxy( 
    ICxIXYZColl * This,
    /* [retval][out] */ IXYZ **o_ppItem);


void __RPC_STUB ICxIXYZColl_GetTail_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_RemoveHead_Proxy( 
    ICxIXYZColl * This,
    /* [retval][out] */ IXYZ **o_ppItem);


void __RPC_STUB ICxIXYZColl_RemoveHead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_RemoveTail_Proxy( 
    ICxIXYZColl * This,
    /* [retval][out] */ IXYZ **o_ppItem);


void __RPC_STUB ICxIXYZColl_RemoveTail_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_RemoveHeadNoReturn_Proxy( 
    ICxIXYZColl * This);


void __RPC_STUB ICxIXYZColl_RemoveHeadNoReturn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_RemoveTailNoReturn_Proxy( 
    ICxIXYZColl * This);


void __RPC_STUB ICxIXYZColl_RemoveTailNoReturn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_RemoveItem_Proxy( 
    ICxIXYZColl * This,
    /* [in] */ IXYZ *i_pItem);


void __RPC_STUB ICxIXYZColl_RemoveItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_RemoveAll_Proxy( 
    ICxIXYZColl * This);


void __RPC_STUB ICxIXYZColl_RemoveAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_AddHead_Proxy( 
    ICxIXYZColl * This,
    /* [in] */ IXYZ *i_pItem,
    /* [defaultvalue][out][in] */ LONG_PTR *o_lpPosition);


void __RPC_STUB ICxIXYZColl_AddHead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_AddHeadColl_Proxy( 
    ICxIXYZColl * This,
    /* [in] */ ICxIXYZColl *i_pColl);


void __RPC_STUB ICxIXYZColl_AddHeadColl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_AddTail_Proxy( 
    ICxIXYZColl * This,
    /* [in] */ IXYZ *i_pItem,
    /* [defaultvalue][out][in] */ LONG_PTR *o_lpPosition);


void __RPC_STUB ICxIXYZColl_AddTail_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_AddTailColl_Proxy( 
    ICxIXYZColl * This,
    /* [in] */ ICxIXYZColl *i_pColl);


void __RPC_STUB ICxIXYZColl_AddTailColl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_GetHeadPosition_Proxy( 
    ICxIXYZColl * This,
    /* [retval][out] */ LONG_PTR *o_pPos);


void __RPC_STUB ICxIXYZColl_GetHeadPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_GetTailPosition_Proxy( 
    ICxIXYZColl * This,
    /* [retval][out] */ LONG_PTR *o_pPos);


void __RPC_STUB ICxIXYZColl_GetTailPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_GetNext_Proxy( 
    ICxIXYZColl * This,
    /* [out][in] */ LONG_PTR *io_pPos,
    /* [retval][out] */ IXYZ **o_ppItem);


void __RPC_STUB ICxIXYZColl_GetNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_GetPrev_Proxy( 
    ICxIXYZColl * This,
    /* [out][in] */ LONG_PTR *io_pPos,
    /* [retval][out] */ IXYZ **o_ppItem);


void __RPC_STUB ICxIXYZColl_GetPrev_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_GetAt_Proxy( 
    ICxIXYZColl * This,
    /* [in] */ LONG_PTR i_pos,
    /* [retval][out] */ IXYZ **o_ppItem);


void __RPC_STUB ICxIXYZColl_GetAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_SetAt_Proxy( 
    ICxIXYZColl * This,
    /* [in] */ LONG_PTR i_pos,
    /* [in] */ IXYZ *i_pItem);


void __RPC_STUB ICxIXYZColl_SetAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_RemoveAt_Proxy( 
    ICxIXYZColl * This,
    /* [in] */ LONG_PTR i_pos);


void __RPC_STUB ICxIXYZColl_RemoveAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_InsertAfter_Proxy( 
    ICxIXYZColl * This,
    /* [in] */ IXYZ *i_pItem,
    /* [out][in] */ LONG_PTR *io_lpPosition);


void __RPC_STUB ICxIXYZColl_InsertAfter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_InsertBefore_Proxy( 
    ICxIXYZColl * This,
    /* [in] */ IXYZ *i_pItem,
    /* [out][in] */ LONG_PTR *io_lpPosition);


void __RPC_STUB ICxIXYZColl_InsertBefore_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_Find_Proxy( 
    ICxIXYZColl * This,
    /* [in] */ IXYZ *i_pItem,
    /* [in] */ LONG_PTR i_posStart,
    /* [out][in] */ LONG_PTR *o_pPos);


void __RPC_STUB ICxIXYZColl_Find_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_FindIndex_Proxy( 
    ICxIXYZColl * This,
    /* [in] */ SIZE_T i_lIndex,
    /* [retval][out] */ LONG_PTR *o_lpPosition);


void __RPC_STUB ICxIXYZColl_FindIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_MoveToHead_Proxy( 
    ICxIXYZColl * This,
    /* [in] */ LONG_PTR i_pos);


void __RPC_STUB ICxIXYZColl_MoveToHead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_MoveToTail_Proxy( 
    ICxIXYZColl * This,
    /* [in] */ LONG_PTR i_pos);


void __RPC_STUB ICxIXYZColl_MoveToTail_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_SwapElements_Proxy( 
    ICxIXYZColl * This,
    /* [in] */ LONG_PTR i_pos1,
    /* [in] */ LONG_PTR i_pos2);


void __RPC_STUB ICxIXYZColl_SwapElements_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICxIXYZColl_Clone_Proxy( 
    ICxIXYZColl * This,
    /* [out] */ ICxIXYZColl **o_ppXYZColl);


void __RPC_STUB ICxIXYZColl_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICxIXYZColl_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


