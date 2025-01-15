#ifndef CRX_DBHANDLE_H
#define CRX_DBHANDLE_H 1

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

//
// DESCRIPTION:
//
// This file contains the interface of the CRxDbHandle class.
// Instances of this class encapsulate an 8-byte CaxaDraft database
// handle value.

#include "cdraft.h"
#include "CrxCx.h"

#pragma pack (push, 8)

class CRxDbDatabase;
struct CRxClass;

class CRxDbStub;

class CRXDB_API CRxDbHandle
{
public:
	CRxDbHandle();                // this ctor does not initialize the handle
	CRxDbHandle(const CxCHAR*);
	CRxDbHandle(const CAXA::UInt64 &);

public:
	CRxDbHandle& operator=(const CRxDbHandle&);

	CAXA::Int32  low() const;
	CAXA::Int32  high() const;
	void          setLow(CAXA::Int32 low);
	void          setHigh(CAXA::Int32 high);

	bool operator == (const CRxDbHandle&) const;
	bool operator != (const CRxDbHandle&) const;

	bool isNull() const;
	void setNull();

	// This gets the hex digits into a string buffer.
	void getIntoAsciiBuffer(CxCHAR* pBuf) const;

// Implementation Class Members: Not for 3rd Party Consumption ///////
	int compare(const CRxDbHandle&) const;

	void bytes(CAXA::UInt8 * bytes) const;

private:
	CAXA::UInt32 mLow;
	CAXA::UInt32 mHigh;
};

//class CRxDbHandle
//{
//public:
//
//    CRxDbHandle();                // this ctor does not initialize the handle
//    CRxDbHandle(int lo, int hi);  // this one does - useful for creating null handles
//    CRxDbHandle(const CxCHAR*);
//    CRxDbHandle(const CAXA::UInt64 &);
//
//    CRxDbHandle& operator=(const CRxDbHandle&);
//
//    CRxDbHandle& operator=(const CxCHAR*);
//
//    // This gets the hex digits into a string buffer.
//    void getIntoAsciiBuffer(CxCHAR* pBuf) const;
//
//    bool operator == (const CRxDbHandle&) const;
//    bool operator != (const CRxDbHandle&) const;
//
//    bool           isNull() const;
//    void           setNull();
//
//    CAXA::UInt32  low() const;
//    CAXA::UInt32  high() const;
//    void           setLow(CAXA::UInt32 low);
//    void           setHigh(CAXA::UInt32 high);
//
//    bool           isOne(void) const;
//
//    /////// Implementation Class Members: Not for 3rd Party Consumption ///////
//    //
//    CRxDbHandle& operator++();
//    CRxDbHandle operator++(int);
//    void increment(void);
//    void decrement(void);
//    CRxDbHandle operator + (const CRxDbHandle&) const;
//    CRxDbHandle slowOperatorPlus(const CRxDbHandle&) const;
//    CRxDbHandle& operator += (const CRxDbHandle&);
//    CRxDbHandle operator - (const CRxDbHandle&) const;
//    CRxDbHandle& operator -= (const CRxDbHandle&);
//    bool operator > (const CRxDbHandle&) const;
//    bool operator >= (const CRxDbHandle&) const;
//    bool operator < (const CRxDbHandle&) const;
//    bool operator <= (const CRxDbHandle&) const;
//    int compare(const CRxDbHandle&) const;
//    void copyToOldType(CAXA::UInt8 hand[8]) const;
//    void copyFromOldType(const CAXA::UInt8 hand[8]);
//    void getValueBytes(CAXA::UInt8*, CAXA::UInt8*) const;
//    void setValueBytes(CAXA::UInt8, const CAXA::UInt8*);
//    CRxDbHandle& operator=(CAXA::UInt32);
//    operator CAXA::UInt32() const;
//    CRxDbHandle operator + (CAXA::ULongPtr) const;
//    void print() const;
//    enum { kMaxValueBytes = 8 };
//    int byte(CAXA::UInt32 i) const;
//    int restZeros(int i) const;
//private:
//    CAXA::UInt64 & get64BitVal()
//          { return *reinterpret_cast<CAXA::UInt64 *>(&mLow); }
//    const CAXA::UInt64 & get64BitVal() const
//          { return *reinterpret_cast<const CAXA::UInt64 *>(&mLow); }
//
//    CAXA::UInt32 mLow;
//    CAXA::UInt32 mHigh;
//    friend class AcDbHandleTable;
//    friend class HandleDataBase;
//};
//
//// This value is used to indicate cases where a conversion from
//// an CRxDbHandle to an CAXA::UInt32 has gone bad because the
//// handle value was too great.
////
//const CAXA::UInt32 kBadUInt32Handle = 0xFFFFFFFF;
//
//inline CRxDbHandle::CRxDbHandle()
//{
//}
//
//inline CRxDbHandle::CRxDbHandle(int lo, int hi) : mLow(lo), mHigh(hi)
//{
//}
//
//inline
//CRxDbHandle::CRxDbHandle(const CAXA::UInt64 &val)
//{
//    this->get64BitVal() = val;
//}
//
//inline CRxDbHandle&
//CRxDbHandle::operator=(const CRxDbHandle& handle)
//{
//    this->get64BitVal() = handle.get64BitVal();
//
//    return *this;
//}
//
//inline CRxDbHandle&
//CRxDbHandle::operator=(CAXA::UInt32 val)
//{ mHigh = 0; mLow = val; return *this; }
//
//inline CRxDbHandle
//CRxDbHandle::operator+(const CRxDbHandle& handle) const
//{
//    CRxDbHandle tHandle(*this);
//    tHandle.get64BitVal() += handle.get64BitVal();
//    return tHandle;
//}
//
//inline CRxDbHandle
//CRxDbHandle::operator+(CAXA::ULongPtr val) const
//{
//    CRxDbHandle tHandle(*this);
//    tHandle.get64BitVal() += val;
//    return tHandle;
//}
//
//
//inline bool
//CRxDbHandle::operator > (const CRxDbHandle& handle) const
//{
//    return this->get64BitVal() > handle.get64BitVal();
//}
//
//inline int
//CRxDbHandle::compare(const CRxDbHandle& handle) const
//{
//    if (this->get64BitVal() > handle.get64BitVal())
//        return -1;
//    else if (this->get64BitVal() == handle.get64BitVal())
//        return 0;
//    else
//        return 1;
//}
//
//inline bool
//CRxDbHandle::operator==(const CRxDbHandle &handle) const
//{
//    return this->get64BitVal() == handle.get64BitVal();
//}
//
//inline bool
//CRxDbHandle::operator!=(const CRxDbHandle &handle) const
//{
//    return this->get64BitVal() != handle.get64BitVal();
//}
//
//inline bool
//CRxDbHandle::isNull(void) const
//{
//    return this->get64BitVal() == 0;
//}
//
//inline void CRxDbHandle::setNull(void)
//{
//    mHigh = mLow = 0;
//}
//
//inline bool
//CRxDbHandle::isOne(void) const
//{
//    return this->get64BitVal() == 1;
//}
//
//inline CRxDbHandle&
//CRxDbHandle::operator++(void)          // ++CRxDbHandle
//{
//    this->get64BitVal()++;
//
//    return *this;
//}
//
//inline void
//CRxDbHandle::increment(void)          // CRxDbHandle = CRxDbHandle + 1;
//{
//    this->get64BitVal()++;
//}
//
//inline void
//CRxDbHandle::decrement(void)          // CRxDbHandle = CRxDbHandle - 1;
//{
//    this->get64BitVal()--;
//}
//
//inline CRxDbHandle
//CRxDbHandle::operator++(int)           // CRxDbHandle++
//{
//    CRxDbHandle tempHandle = *this;
//    ++(*this);
//    return tempHandle;
//}
//
//inline CRxDbHandle::operator CAXA::UInt32() const
//{
//    if (mHigh != 0)
//        return kBadUInt32Handle;
//    return mLow;
//}
//
//inline bool
//CRxDbHandle::operator < (const CRxDbHandle& handle) const
//{
//    return this->get64BitVal() < handle.get64BitVal();
//}
//
//inline int CRxDbHandle::byte(CAXA::UInt32 i) const
//{
//    // Unicode: leave as unsigned char *
//    return *((unsigned char *)&mLow + i);
//}
//
//inline int CRxDbHandle::restZeros(int i) const
//{
//    CAXA::UInt32 mask;
//    if (i < 4) {
//        mask = ~0 << (i << 3);
//        return !(mHigh | (mLow & mask));
//    } else {
//        mask = ~0 << ((i - 4) << 3);
//        return !(mHigh & mask);
//    }
//}
//
//inline CAXA::UInt32  CRxDbHandle::low() const
//{
//    return mLow;
//}
//inline CAXA::UInt32  CRxDbHandle::high() const
//{
//    return mHigh;
//}
// 
//inline void CRxDbHandle::setLow(CAXA::UInt32 low)
//{
//    mLow = low;
//    return;
//}
//inline void CRxDbHandle::setHigh(CAXA::UInt32 high)
//{
//    mHigh = high;
//    return;
//}

#pragma pack (pop)

#endif
