//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//
#pragma once

class CRxHeapOperators {
    private:
        static void * __stdcall allocRawMem(size_t size);
        // Unicode: leaving pFName as char for now
        static void * __stdcall allocRawMem(size_t size, const char *pFName,
                                             int nLine);
        static void   __stdcall freeRawMem(void *p);
        static void   __stdcall freeRawMem(void *p, const char *pFName,
                                            int nLine);
    public:

#undef new
#undef delete
        static void* operator new(size_t size) {
            void *p = allocRawMem(size);
            __assume(p != NULL);
            return p;
        }

        static void* operator new[](size_t size) {
            void *p = allocRawMem(size);
            __assume(p != NULL);
            return p;
        }

        // Unicode: leaving pFName as char for now
        static void* operator new(size_t size, const char *pFName,
                                  int nLine)
        {
            void * p = allocRawMem(size, pFName, nLine);
            __assume(p != NULL);
            return p;
        }

        static void* operator new[](size_t size,
                                    const char *pFName, int nLine)
        {
            void *p = allocRawMem(size, pFName, nLine);
            __assume(p != NULL);
            return p;
        }

        static void operator delete(void *p) {   
            if(p != NULL)
                freeRawMem(p);
        }

        static void operator delete[](void *p) {   
            if(p != NULL)
                freeRawMem(p);
        }

        // Unicode: leaving pFName as char for now
        static void operator delete(void *p, const char *pFName,
                                    int nLine)
        {
            if (p != NULL)
                freeRawMem(p, pFName, nLine);
        }

        static void operator delete[](void *p,
                                      const char *pFName, int nLine)
        {
            if (p != NULL)
                freeRawMem(p, pFName, nLine);
        }

};  // CRxHeapOperators

#ifdef MEM_DEBUG
// CDraft-specific re-definition of new and delete operators, used to
// insert filename and line number info into memory blocks
//
#define new DEBUG_NEW
#define delete DEBUG_DELETE
#endif

