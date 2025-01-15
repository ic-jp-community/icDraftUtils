

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for ICxCrxBase.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ICxCrxBase_h__
#define __ICxCrxBase_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICxCrxObject_FWD_DEFINED__
#define __ICxCrxObject_FWD_DEFINED__
typedef interface ICxCrxObject ICxCrxObject;

#endif 	/* __ICxCrxObject_FWD_DEFINED__ */


#ifndef __ICxCrxExtDataObj_FWD_DEFINED__
#define __ICxCrxExtDataObj_FWD_DEFINED__
typedef interface ICxCrxExtDataObj ICxCrxExtDataObj;

#endif 	/* __ICxCrxExtDataObj_FWD_DEFINED__ */


#ifndef __ICxDbXRecord_FWD_DEFINED__
#define __ICxDbXRecord_FWD_DEFINED__
typedef interface ICxDbXRecord ICxDbXRecord;

#endif 	/* __ICxDbXRecord_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "ICxMath.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_ICxCrxBase_0000_0000 */
/* [local] */ 

typedef /* [public][uuid] */  DECLSPEC_UUID("5AC0775F-72E2-40d1-98F6-0A6A88FAAE1A") 
enum __MIDL___MIDL_itf_ICxCrxBase_0000_0000_0001
    {
        CX_CRX_EXTDATAOBJ	= 0,
        CX_CRX_XRECORD	= 1
    } 	CXCRXOBJENUM;




extern RPC_IF_HANDLE __MIDL_itf_ICxCrxBase_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ICxCrxBase_0000_0000_v0_0_s_ifspec;

#ifndef __ICxCrxObject_INTERFACE_DEFINED__
#define __ICxCrxObject_INTERFACE_DEFINED__

/* interface ICxCrxObject */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICxCrxObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("517B82E4-C5D2-4bf1-98E6-E82F0F1BF34F")
    ICxCrxObject : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCrxPtr( 
            /* [in] */ ULONG_PTR i_pCrxObject) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCrxPtr( 
            /* [retval][out] */ ULONG_PTR *o_ppCrxObject) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ ICxCrxObject **o_ppCrxObject) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CopyFrom( 
            /* [in] */ ICxCrxObject *i_pCrxObject) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsCrxPtrNull( 
            /* [retval][out] */ VARIANT_BOOL *o_pvbIsNull) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCallBackFlag( 
            /* [in] */ VARIANT_BOOL i_vbCanCallBack) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCallBackFlag( 
            /* [retval][out] */ VARIANT_BOOL *o_pvbCanCallBack) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetOriginObject( 
            /* [out] */ ICxCrxObject **o_pOriginCrxObject) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetOriginObject( 
            /* [in] */ ICxCrxObject *i_pOriginCrxObject) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCrxObject( 
            /* [in] */ ICxCrxObject *i_pCrxObject) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICxCrxObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICxCrxObject * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICxCrxObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICxCrxObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICxCrxObject * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICxCrxObject * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICxCrxObject * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICxCrxObject * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCrxPtr )( 
            ICxCrxObject * This,
            /* [in] */ ULONG_PTR i_pCrxObject);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCrxPtr )( 
            ICxCrxObject * This,
            /* [retval][out] */ ULONG_PTR *o_ppCrxObject);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clone )( 
            ICxCrxObject * This,
            /* [out] */ ICxCrxObject **o_ppCrxObject);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CopyFrom )( 
            ICxCrxObject * This,
            /* [in] */ ICxCrxObject *i_pCrxObject);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsCrxPtrNull )( 
            ICxCrxObject * This,
            /* [retval][out] */ VARIANT_BOOL *o_pvbIsNull);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCallBackFlag )( 
            ICxCrxObject * This,
            /* [in] */ VARIANT_BOOL i_vbCanCallBack);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCallBackFlag )( 
            ICxCrxObject * This,
            /* [retval][out] */ VARIANT_BOOL *o_pvbCanCallBack);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetOriginObject )( 
            ICxCrxObject * This,
            /* [out] */ ICxCrxObject **o_pOriginCrxObject);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetOriginObject )( 
            ICxCrxObject * This,
            /* [in] */ ICxCrxObject *i_pOriginCrxObject);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCrxObject )( 
            ICxCrxObject * This,
            /* [in] */ ICxCrxObject *i_pCrxObject);
        
        END_INTERFACE
    } ICxCrxObjectVtbl;

    interface ICxCrxObject
    {
        CONST_VTBL struct ICxCrxObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICxCrxObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICxCrxObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICxCrxObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICxCrxObject_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICxCrxObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICxCrxObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICxCrxObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICxCrxObject_SetCrxPtr(This,i_pCrxObject)	\
    ( (This)->lpVtbl -> SetCrxPtr(This,i_pCrxObject) ) 

#define ICxCrxObject_GetCrxPtr(This,o_ppCrxObject)	\
    ( (This)->lpVtbl -> GetCrxPtr(This,o_ppCrxObject) ) 

#define ICxCrxObject_Clone(This,o_ppCrxObject)	\
    ( (This)->lpVtbl -> Clone(This,o_ppCrxObject) ) 

#define ICxCrxObject_CopyFrom(This,i_pCrxObject)	\
    ( (This)->lpVtbl -> CopyFrom(This,i_pCrxObject) ) 

#define ICxCrxObject_IsCrxPtrNull(This,o_pvbIsNull)	\
    ( (This)->lpVtbl -> IsCrxPtrNull(This,o_pvbIsNull) ) 

#define ICxCrxObject_SetCallBackFlag(This,i_vbCanCallBack)	\
    ( (This)->lpVtbl -> SetCallBackFlag(This,i_vbCanCallBack) ) 

#define ICxCrxObject_GetCallBackFlag(This,o_pvbCanCallBack)	\
    ( (This)->lpVtbl -> GetCallBackFlag(This,o_pvbCanCallBack) ) 

#define ICxCrxObject_GetOriginObject(This,o_pOriginCrxObject)	\
    ( (This)->lpVtbl -> GetOriginObject(This,o_pOriginCrxObject) ) 

#define ICxCrxObject_SetOriginObject(This,i_pOriginCrxObject)	\
    ( (This)->lpVtbl -> SetOriginObject(This,i_pOriginCrxObject) ) 

#define ICxCrxObject_SetCrxObject(This,i_pCrxObject)	\
    ( (This)->lpVtbl -> SetCrxObject(This,i_pCrxObject) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICxCrxObject_INTERFACE_DEFINED__ */


#ifndef __ICxCrxExtDataObj_INTERFACE_DEFINED__
#define __ICxCrxExtDataObj_INTERFACE_DEFINED__

/* interface ICxCrxExtDataObj */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICxCrxExtDataObj;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B76A27EA-298A-499a-ACC2-1E82C5F7D41D")
    ICxCrxExtDataObj : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE xData( 
            /* [in] */ BSTR i_bsName,
            /* [retval][out] */ ULONG_PTR *o_ppResbuf) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setXData( 
            /* [in] */ ULONG_PTR i_pResbuf) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE xDataTransformBy( 
            /* [in] */ IMatrix *i_pMatrix) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICxCrxExtDataObjVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICxCrxExtDataObj * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICxCrxExtDataObj * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICxCrxExtDataObj * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICxCrxExtDataObj * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICxCrxExtDataObj * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICxCrxExtDataObj * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICxCrxExtDataObj * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *xData )( 
            ICxCrxExtDataObj * This,
            /* [in] */ BSTR i_bsName,
            /* [retval][out] */ ULONG_PTR *o_ppResbuf);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setXData )( 
            ICxCrxExtDataObj * This,
            /* [in] */ ULONG_PTR i_pResbuf);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *xDataTransformBy )( 
            ICxCrxExtDataObj * This,
            /* [in] */ IMatrix *i_pMatrix);
        
        END_INTERFACE
    } ICxCrxExtDataObjVtbl;

    interface ICxCrxExtDataObj
    {
        CONST_VTBL struct ICxCrxExtDataObjVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICxCrxExtDataObj_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICxCrxExtDataObj_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICxCrxExtDataObj_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICxCrxExtDataObj_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICxCrxExtDataObj_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICxCrxExtDataObj_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICxCrxExtDataObj_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICxCrxExtDataObj_xData(This,i_bsName,o_ppResbuf)	\
    ( (This)->lpVtbl -> xData(This,i_bsName,o_ppResbuf) ) 

#define ICxCrxExtDataObj_setXData(This,i_pResbuf)	\
    ( (This)->lpVtbl -> setXData(This,i_pResbuf) ) 

#define ICxCrxExtDataObj_xDataTransformBy(This,i_pMatrix)	\
    ( (This)->lpVtbl -> xDataTransformBy(This,i_pMatrix) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICxCrxExtDataObj_INTERFACE_DEFINED__ */


#ifndef __ICxDbXRecord_INTERFACE_DEFINED__
#define __ICxDbXRecord_INTERFACE_DEFINED__

/* interface ICxDbXRecord */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICxDbXRecord;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("522D7F8F-2BB9-4ea8-B16F-6ADC4FAB4D88")
    ICxDbXRecord : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE rbChain( 
            /* [retval][out] */ ULONG_PTR *o_ppResbuf) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setFromRbChain( 
            /* [in] */ ULONG_PTR i_pResbuf) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICxDbXRecordVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICxDbXRecord * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICxDbXRecord * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICxDbXRecord * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICxDbXRecord * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICxDbXRecord * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICxDbXRecord * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICxDbXRecord * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *rbChain )( 
            ICxDbXRecord * This,
            /* [retval][out] */ ULONG_PTR *o_ppResbuf);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setFromRbChain )( 
            ICxDbXRecord * This,
            /* [in] */ ULONG_PTR i_pResbuf);
        
        END_INTERFACE
    } ICxDbXRecordVtbl;

    interface ICxDbXRecord
    {
        CONST_VTBL struct ICxDbXRecordVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICxDbXRecord_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICxDbXRecord_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICxDbXRecord_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICxDbXRecord_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICxDbXRecord_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICxDbXRecord_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICxDbXRecord_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICxDbXRecord_rbChain(This,o_ppResbuf)	\
    ( (This)->lpVtbl -> rbChain(This,o_ppResbuf) ) 

#define ICxDbXRecord_setFromRbChain(This,i_pResbuf)	\
    ( (This)->lpVtbl -> setFromRbChain(This,i_pResbuf) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICxDbXRecord_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


