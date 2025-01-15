//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//

//  DESCRIPTION:
//

#ifndef _CRx_String_h_
#define _CRx_String_h_

#include "CRxHeapOpers.h"
#include "crxChar.h"
#pragma pack (push, 1)

class CRxDbHandle;

// Notes:
// 1. All "char" arguments are assumed to be codes in the current
//    code page, unless otherwise specified.
//
// 2. In places where a single char value is passed, the value
//    cannot be a leading byte of a double-byte char, except
//    where noted.
//
// 3. All wchar_t arguments are assumed to be Unicode values.
//
class CRxString : public CRxHeapOperators
{
  public:
    //
    // Constructors and destructor 
    //
    // Default ctor, initializes to empty string.
    CRxString();

    // Initialize with a single character.
    // ch : input character
    CRxString(char ch);

    // Initialize with a single Unicode character
    // wch : input character
    CRxString(wchar_t wch);

    // Initialize from an ansi string.
    // psz : input pointer to source string.
    CRxString(const char *psz);

    // Initialize from a Unicode string
    // wpsz : input pointer to source string
    CRxString(const wchar_t *pwsz);

    // Copy constructor
    // acs : input reference to an existing CRxString object
    CRxString(const CRxString & acs);

    // Values for the nCtorFlags arg of the following constructor
    enum {
        kAppRes = 0x0001,   // use app's default resource dll
        kSigned = 0x0002,   // format the arg as signed int
        kUnSigned = 0x0003, // format the arg as unsigned int
        kHex      = 0x0004  // format the arg as hex
    };

    // Multi-purpose constructor, takes an unsigned argument and
    // uses it either to load a resource string or to create a
    // numerical string (base 10 or hex).
    //
    // nCtorFlags : input flags, indicating type of construction
    // nArg : input argument value, interpreted according to flags
    CRxString(int nCtorFlags, unsigned nArg);

    // Formats an CRxDbHandle value in hex, as in: "a2f".
    // h : input reference to an acdb handle value
    CRxString(const CRxDbHandle &h);

#ifdef _WINBASE_
    // Loads a resource string from the specified dll handle.
    // hDll : input windows handle to a loaded resource dll
    // nId : input int id of the resource string to load
    CRxString(HINSTANCE hDll, unsigned nId);
#endif
    
    // Destructor: frees up memory.
    ~CRxString();

    //
    // Querying methods
    //

    // Get a pointer to the current string (code page based).  This
    // pointer is only valid until the CRxString object is next modified!
    const    char * kszPtr() const;

    // Get a pointer to the current string (in Unicode).  This pointer
    // is only valid until this CRxString object is next modified!
    const wchar_t * kwszPtr() const;

    // Get a pointer to the current string as a TCHAR pointer.  In
    // Unicode builds, this will be Unicode, and in multibyte builds
    // it will be code page dependent.  Pointer is only valid until
    // this CRxString is next modified.
#ifdef UNICODE
    const wchar_t *  constPtr() const;
    const wchar_t * kTCharPtr() const;
#else
    const  char   *  constPtr() const;
    const  char   * kTCharPtr() const;
#endif

    // Get a pointer to the current string in CxCHARs.
    const CxCHAR * kCxCHARPtr() const;

    // Get a pointer to the current string (code page based).  Pointer
    // is valid only until this CRxString is next modified.
    operator const char * () const;

    // Get a pointer to the current string (in Unicode).  Pointer
    // is valid only until this CRxString is next modified.
    operator const wchar_t * () const;

    // Test whether the current string value is empty.  I.e.,
    // logical length is zero.
    bool isEmpty() const;

    // Return logical length of (i.e. number of chars in) the string.
    // WARNING!!!  Double-byte chars count as a single character.
    // This method does *not* return the *byte* length of the string.
    // If the string contains doublebyte chars, then this method will
    // return a smaller length than the byte length.
    // To get the byte length, please call tcharLength() or lengthA().
    //
    unsigned length() const;

    // Return length of the current string, in TCHAR units.
    // In ansi build, call lengthA(), returning number of bytes.
    // In Unicode build, call lengthW(), returning number of widechars.
    unsigned tcharLength() const;

    // Returns true if all chars are in the ascii range: 0x20..0x7f
    bool isAscii() const;


    //
    // Parsing methods.
    //
    enum {
        // Enum value allowing caller to specify how to handle errors
        // (invalid chars or overflow) during string parsing.
        kParseZero = 0,       // return zero on errors
        kParseMinus1 = 0x01,  // return -1 or ffff
        kParseAssert = 0x02,  // pop an assert in debug build
        kParseExcept = 0x04,  // throw an int exception
        kParseNoEmpty = 0x08, // treat empty string as error
        kParseDefault = (kParseAssert | kParseZero)
    };

    // Parse the current string as decimal, return a signed int
    // nFlags : input bits specifying how to do the parsing
    int asDeci(int nFlags = kParseDefault) const;

    // Parse the current string as hexadecimal, return a signed int
    // nFlags : input bits specifying how to do the parsing
    int asHex (int nFlags = kParseDefault) const;

    // Parse the current string as decimal, return an unsigned int
    // nFlags : input bits specifying how to do the parsing
    unsigned int asUDeci(int nFlags = kParseDefault) const;

    // Parse the current string as hexadecimal, return an unsigned int
    // nFlags : input bits specifying how to do the parsing
    unsigned int asUHex (int nFlags = kParseDefault) const;

    // Parse the current string as decimal, return a signed int64
    // nFlags : input bits specifying how to do the parsing
    __int64 asDeci64(int nFlags = kParseDefault) const;

    // Parse the current string as hexadecimal, return a signed int64
    // nFlags : input bits specifying how to do the parsing
    __int64 asHex64 (int nFlags = kParseDefault) const;

    // Parse the current string as decimal, return an unsigned int64
    // nFlags : input bits specifying how to do the parsing
    unsigned __int64 asUDeci64(int nFlags = kParseDefault) const;

    // Parse the current string as hexadecimal, return an unsigned int64
    // nFlags : input bits specifying how to do the parsing
    unsigned __int64 asUHex64 (int nFlags = kParseDefault) const;

    // Parse the current string as hexadecimal.  Return the handle.
    // nFlags : input bits specifying how to do the parsing
    CRxDbHandle asAcDbHandle(int nFlags = kParseDefault) const;

    //
    // Find char/string/one of a string of chars, from front or back
    // Return the position (index) at which the character or substring
    // was found.
    //
    // The find methods which start at the end of the string return
    // an index relative to the front of the string.

    // Find a single char in the string.
    // ch : input char to search for
    int find(CxCHAR ch) const;

    // Find a substring in the string
    // psz : input string to search for
    int find(const CxCHAR *psz) const;

    // Find an CRxString in the string.
    // acs : input string object to search for
    int find(const CRxString & acs) const;

    // Find any of a group of chars in the string.
    // psz : input pointer to string of chars to search for
    int findOneOf(const CxCHAR *psz) const;

    // Find last occurrence of a char in the string
    // ch : input char to search for
    int findRev(CxCHAR ch) const;

    // Find last occurrence of any of a group of chars in the string
    // psz : input pointer to string of chars to search for
    int findRev(const CxCHAR *psz) const;

    // Find last occurrence of a group of chars in the string
    // psz : input ptr to the string of chars to search for
    int findOneOfRev(const CxCHAR *psz) const;

    // Find last occurrence of a string in the string
    // acs : input reference to the string to search for
    int findRev(const CRxString & acs) const;

    //
    // Extraction methods
    // Note: mid() and substr() are the same thing - we define both
    //       for compatibility with CString and std::string
    //
    // The input index arguments are byte indices into the string.

    // Get a substring from the string.  (same as substr() method)
    // nStart : input index (in bytes) from the start of the string
    // nNumChars : input number of chars (not bytes) to retrieve.
    //             if nNumChars is -1, then return the rest of the string
    CRxString mid(int nStart, int nNumChars) const;

    // Get a substring from the start of string.
    // nNumChars : input number of chars (not bytes) to retrieve.
    //             if nNumChars is -1, then return the rest of the string
    CRxString substr(int numChars) const;

    // Get a substring from the string.  (same as mid() method)
    // nStart : input index (in bytes) from the start of the string
    // nNumChars : input number of chars (not bytes) to retrieve.
    //             if nNumChars is -1, then return the rest of the string
    CRxString substr(int nStart, int nNumChars) const;

    // Get a substring from the end of string.
    // nNumChars : input number of chars (not bytes) to retrieve.
    CRxString substrRev(int numChars) const;

    //
    // Assignment operators and methods
    //

    // assign a char to the string
    // ch : input char to assign
    CRxString & assign(char ch);

    // assign a Unicode char to the string
    // wch : input char to assign
    CRxString & assign(wchar_t wch);

    // assign a string of chars to the string
    // psz : input pointer to the string of chars to assign
    CRxString & assign(const char *psz);

    // assign a string of Unicode chars to the string
    // pwsz : input pointer to the string of chars to assign
    CRxString & assign(const wchar_t *pwsz);

    // assign an CRxString object to the string
    // acs : input reference to the CRxString
    CRxString & assign(const CRxString & acs);

    // assign an CRxDbHandle object to the string (format it as hex)
    // h : input reference to the CRxDbHandle object
    CRxString & assign(const CRxDbHandle & h);

    // assign a char to the string
    // ch : input char to assign
    CRxString & operator = (char ch);

    // assign a Unicode char to the string
    // wch : input char to assign
    CRxString & operator = (wchar_t wch);

    // assign a string of chars to the string
    // psz : input pointer to the string of chars to assign
    CRxString & operator = (const char *psz);

    // assign a string of Unicode chars to the string
    // pwsz : input pointer to the string of chars to assign
    CRxString & operator = (const wchar_t *pwsz);

    // assign an CRxString object to the string
    // acs : input reference to the CRxString
    CRxString & operator = (const CRxString & acs);

    // assign an CRxDbHandle object to the string (format it as hex)
    // h : input reference to the CRxDbHandle object
    CRxString & operator = (const CRxDbHandle & h);

    // Set the string to be empty.
    CRxString & setEmpty();

    // Set the string from a resource string
    // nId : input id of the string resource in the current mfc resource dll
    bool loadString(unsigned nId);

#ifdef _WINBASE_
    // Set the string from a resource string
    // hDll : input windows handle to a loaded resource dll
    // nId : input id of the string resource in the specified resource dll
    bool loadString(HINSTANCE hDll, unsigned nId);
#endif

    // Format the string using "printf" rules.
    // pszFmt : input pointer to the printf format string
    void format (const CxCHAR    *pszFmt,  ...);

    // Format the string using "printf" rules
    // pszFmt : input pointer to the printf format string
    // args : input variable args list, containing values to be formatted
    void formatV(const CxCHAR   *pszFmt,  va_list args);

    //
    // Modifying operators and methods
    //

    // append an ansi char to the end of the string
    // ch : input char to append
    CRxString & operator += (char ch);

    // append a Unicode char to the end of the string
    // wch : input char to append
    CRxString & operator += (wchar_t wch);

    // append a char string to the end of the string
    // psz : input pointer to the char string
    CRxString & operator += (const char * psz);

    // append a Unicode string to the end of the string
    // pwsz : input pointer to the Unicode string
    CRxString & operator += (const wchar_t * pwsz);

    // append an CRxString object to the end of the string
    // acs : input reference to the CRxString
    CRxString & operator += (const CRxString & acs);

    // append an ansi char to the end of the string
    // ch : input char to append
    CRxString & append(char ch);

    // append a Unicode char to the end of the string
    // wch : input char to append
    CRxString & append(wchar_t wch);

    // append a char string to the end of the string
    // psz : input pointer to the char string
    CRxString & append(const char *psz);

    // append a Unicode string to the end of the string
    // pwsz : input pointer to the Unicode string
    CRxString & append(const wchar_t *pwsz);

    // append an CRxString object to the end of the string
    // acs : input reference to the CRxString
    CRxString & append(const CRxString & acs);

    // Catenation operators and methods  These are like append,
    // but they do not modify the current string.  They return a
    // new combined string.

    // Copy the string and append a char to it
    // ch : input char to append to the string copy
    CRxString operator + (char ch) const;

    // Copy the string and append a Unicode char to it
    // ch : input char to append to the string copy
    CRxString operator + (wchar_t wch) const;

    // Copy the string and append a string of chars to it
    // psz : input pointer to the string to append
    CRxString operator + (const char * psz) const;

    // Copy the string and append a string of Unicode chars to it
    // pwsz : input pointer to the string to append
    CRxString operator + (const wchar_t * pwsz) const;

    // Copy the string and append an CRxString to it
    // pwsz : input reference to the CRxString to append
    CRxString operator + (const CRxString & acs) const;

    // Copy the string and append a char to it
    // ch : input char to append to the string copy
    CRxString concat(char ch) const;

    // Copy the string and append a Unicode char to it
    // ch : input char to append to the string copy
    CRxString concat(wchar_t wch) const;

    // Copy the string and append a string of chars to it
    // psz : input pointer to the string to append
    CRxString concat(const char * psz) const;

    // Copy the string and append a string of Unicode chars to it
    // pwsz : input pointer to the string to append
    CRxString concat(const wchar_t * pwsz) const;

    // Copy the string and append an CRxString to it
    // pwsz : input reference to the CRxString to append
    CRxString concat(const CRxString & acs) const;

    // These copy the current string and then insert the char or
    // string in front of it.  They're used by the global "+" operators.

    // Copy the string and insert a char in front of it
    // ch : input char to insert
    CRxString precat(CxCHAR ch) const;

    // Copy the string and insert a string of chars in front of it
    // psz : input pointer to the string of chars to insert
    CRxString precat(const char * psz) const;

    // Copy the string and insert a string of chars in front of it
    // psz : input pointer to the string of chars to insert
    CRxString precat(const wchar_t * psz) const;

    //
    // Comparison operators and methods
    // The int return value is -1, 0 or 1, indicating <, == or >
    //

    // Compare the string to a single Unicode char
    // wch : input char to compare to
    int  compare(wchar_t wch) const;

    // Compare the string to a string of chars
    // psz : input pointer to the string of chars to compare to
    int  compare(const char *psz) const;

    // Compare the string to a string of Unicode chars
    // pwsz : input pointer to the string of chars to compare to
    int  compare(const wchar_t *pwsz) const;

    // Compare the string to a string of Unicode chars
    // acs : input reference of the other CRxString to compare to
    int  compare(const CRxString & acs) const;

    // Compare the string case-independently to a Unicode char
    // wch : input char to compare to
    int  compareNoCase(wchar_t wch) const;

    // Compare the string case-independently to a string of chars
    // psz : input pointer to the string of chars to compare to
    int  compareNoCase(const char *psz) const;

    // Compare the string case-independently to a string of Unicode chars
    // pwsz : input pointer to the string of chars to compare to
    int  compareNoCase(const wchar_t *pwsz) const;

    // Compare the string case-independently to another CRxString
    // acs : input reference to the other CRxString
    int  compareNoCase(const CRxString & acs) const;

    // Compare the string for equality with a Unicode char
    // wch : input char to compare to
    bool operator == (wchar_t wch) const;

    // Compare the string for equality with a string of chars
    // psz : input pointer to the string of chars
    bool operator == (const char *psz) const;

    // Compare the string for equality with a string of Unicode chars
    // pwsz : input pointer to the string of chars
    bool operator == (const wchar_t *pwsz) const;

    // Compare the string for equality with another CRxString
    // acs : input reference to the other CRxString
    bool operator == (const CRxString & acs) const;

    // Compare the string for non-equality with a Unicode char
    // wch : input char to compare to
    bool operator != (wchar_t wch) const;

    // Compare the string for non-equality with a string of chars
    // psz : input pointer to the string of chars
    bool operator != (const char *psz) const;

    // Compare the string for non-equality with a string of Unicode chars
    // pwsz : input pointer to the string of chars
    bool operator != (const wchar_t *pwsz) const;

    // Compare the string for non-equality with another CRxString
    // acs : input reference to the other CRxString
    bool operator != (const CRxString & acs) const;

    // Compare the string for greater than a Unicode char
    // wch : input char to compare to
    bool operator >  (wchar_t wch) const;

    // Compare the string for greater than a string of chars
    // psz : input pointer to the string of chars to compare to
    bool operator >  (const char *psz) const;

    // Compare the string for greater than a string of Unicode chars
    // pwsz : input pointer to the string of chars to compare to
    bool operator >  (const wchar_t *pwsz) const;

    // Compare the string for greater than another CRxString
    // acs : input reference to the other CRxString
    bool operator >  (const CRxString & acs) const;

    // Compare the string for greater than or equal to a Unicode char
    // wch : input char to compare to
    bool operator >= (wchar_t wch) const;

    // Compare the string for greater than or equal to a string of chars
    // psz : input pointer to the string of chars
    bool operator >= (const char *psz) const;

    // Compare the string for greater than/equal to a string of Unicode chars
    // pwsz : input pointer to the string of chars
    bool operator >= (const wchar_t *pwsz) const;

    // Compare the string for greater than or equal to another CRxString
    // acs : input reference to the other CRxString
    bool operator >= (const CRxString & acs) const;

    // Compare the string for less than a Unicode char
    // wch : input char to compare to
    bool operator <  (wchar_t wch) const;

    // Compare the string for less than a string of chars
    // psz : input pointer to the string of chars to compare to
    bool operator <  (const char *psz) const;

    // Compare the string for less than a string of Unicode chars
    // pwsz : input pointer to the string of chars to compare to
    bool operator <  (const wchar_t *pwsz) const;

    // Compare the string for less than another CRxString
    // acs : input reference to the other CRxString
    bool operator <  (const CRxString & acs) const;

    // Compare the string for less than or equal to a char
    // ch : input char to compare to
    bool operator <= (const char ch) const;

    // Compare the string for less than or equal to a Unicode char
    // wch : input char to compare to
    bool operator <= (const wchar_t wch) const;

    // Compare the string for less than or equal to a string of chars
    // psz : input pointer to the string of chars
    bool operator <= (const char *psz) const;

    // Compare the string for less than/equal to a string of Unicode chars
    // pwsz : input pointer to the string of chars
    bool operator <= (const wchar_t *pwsz) const;

    // Compare the string for less or equal to than another CRxString
    // acs : input reference to the other CRxString
    bool operator <= (const CRxString & acs) const;

    // The match() methods return how many chars (not bytes) match
    // between two strings.  Not fully implemented yet (non-ascii
    // chars not supported yet).

    // Return the number of chars that match a string of chars
    // psz : input pointer to the string of chars
    int  match(const char *psz) const;

    // Return the number of chars matching a string of Unicode chars
    // pwsz : input pointer to the string of chars
    int  match(const wchar_t *pwsz) const;

    // Return the number of chars matching another CRxString
    // acs : input reference to the other CRxString
    int  match(const CRxString & acs) const;

    // Return number of chars case-independently matching a string of chars
    // psz : input pointer to the string of chars
    int  matchNoCase(const char *psz) const;

    // Return number of chars case-indep'ly matching a string of Unicode chars
    // pwsz : input pointer to the string of chars
    int  matchNoCase(const wchar_t *pwsz) const;

    // Return number of chars case-indep'ly matching another CRxString
    // acs : input reference to the other CRxString
    int  matchNoCase(const CRxString & acs) const;

#ifdef _AFX
    //
    // MFC CString-using methods.  The CStringA class is the ansi
    // code page based CString, while CStringW is Unicode based.
    // CString maps to one or the other depending on whether the
    // UNICODE preprocessor symbol is defined.
    //

    // Construct an CRxString from a CStringW
    // csw : input reference to the CStringW
    CRxString(const CStringW &csw);

    // Initialize this CRxString from a CStringW
    // csw : input reference to the CStringW
    CRxString & operator = (const CStringW &csw);

    // Append a CStringW to this CRxString
    // csa : input reference to the CStringW
    CRxString & operator += (const CStringW &csw);

    // Compare this string to a CStringW
    // csw : input reference to the CStringW
    int  compare(const CStringW & csw) const;

    // Compare this string case independently to a CStringW
    // csw : input reference to the CStringW
    int  compareNoCase(const CStringW & csw) const;

    // Compare for equality with a CStringW
    // csw : input reference to the CStringW
    bool operator == (const CStringW & ) const;

    // Compare for non-equality with a CStringW
    // csw : input reference to the CStringW
    bool operator != (const CStringW & ) const;

    // Compare for less than a CStringW
    // csw : input reference to the CStringW
    bool operator <  (const CStringW & ) const;

    // Compare for less than or equal to a CStringW
    // csw : input reference to the CStringW
    bool operator <= (const CStringW & ) const;

    // Compare for greater than a CStringW
    // csw : input reference to the CStringW
    bool operator >  (const CStringW & ) const;
    // Compare for greater than or equal to a CStringW
    // csw : input reference to the CStringW
    bool operator >= (const CStringW & ) const;

    // Return number of chars matching a CStringW
    // csw : input reference to the CStringW
    int  match(const CStringW & csw) const;

    // Return number of chars case-independently matching a CStringW
    // csw : input reference to the CStringW
    int  matchNoCase(const CStringW & csw) const;

    // Note: unfortunately there is not now an assignment operator for
    // assigning CRxStrings to CStrings, as in CString cs = CRxString("x");
#endif

  private:
    // size is 8 bytes in 32-bit build, 16 in 64-bit build.
#ifndef _WIN64
    enum {
        kObjSize = 8,
        kMbArrSize = 7,
        kUCArrSize = 3,
        kPadArrSize = 3
    };
#else
    enum {
        kObjSize = 16,
        kMbArrSize = 15,
        kUCArrSize = 7,
        kPadArrSize = 7
    };
#endif
    void clearAll();
    struct PtrAndData;
    unsigned char mnFlags;
    union {
        struct {
            unsigned char mnPad2[kPadArrSize];
            union {
                wchar_t *mpwszData;
                char *mpszData;
                PtrAndData *mpPtrAndData;
            };
        };
        struct {
            unsigned char mnPad1;
            wchar_t mwszStr[kUCArrSize];
        };
        char mszStr[kMbArrSize];
    };
    friend class CRxStringImp;
};

#ifdef CXARRAY_H
typedef 
CRxArray< CRxString, CRxArrayObjectCopyReallocator< CRxString > > CRxStringArray;
#endif

#pragma pack (pop)

//
// Global operators
// 

// Compare an CRxString and a Unicode char for equality
// wch : input char to compare
// acs : input reference to the CRxString
bool operator == (wchar_t wch, const CRxString & acs);

// Compare an CRxString and a string of chars char for equality
// psz : input pointer to the string of chars
// acs : input reference to the CRxString
bool operator == (const char *psz, const CRxString & acs);

// Compare an CRxString and a string of Unicode chars for equality
// pwsz : input char to the string of Unicode chars
// acs : input reference to the CRxString
bool operator == (const wchar_t *pwsz, const CRxString & acs);

// Compare an CRxString and a Unicode char for non-equality
// wch : input char to compare
// acs : input reference to the CRxString
bool operator != (wchar_t wch, const CRxString & acs);

// Compare an CRxString and a string of chars char for non-equality
// psz : input pointer to the string of chars
// acs : input reference to the CRxString
bool operator != (const char *psz, const CRxString & acs);

// Compare an CRxString and a string of Unicode chars for non-equality
// pwsz : input char to the string of Unicode chars
// acs : input reference to the CRxString
bool operator != (const wchar_t *pwsz, const CRxString & acs);

// Return whether a Unicode char is greater than an CRxString
// wch : input char to compare
// acs : input reference to the CRxString
bool operator >  (wchar_t wch, const CRxString & acs);

// Return whether a string of chars is greater than an CRxString
// psz : input pointer to the string of chars
// acs : input reference to the CRxString
bool operator >  (const char *psz, const CRxString & acs);

// Return whether a string of Unicode chars is greater than an CRxString
// pwsz : input pointer to the string of Unicode chars
// acs : input reference to the CRxString
bool operator >  (const wchar_t *pwsz, const CRxString & acs);

// Check for a Unicode char being greater than or equal to an CRxString
// wch : input char to compare
// acs : input reference to the CRxString
bool operator >= (wchar_t wch, const CRxString & acs);

// Check for a string of chars being greater than or equal to an CRxString
// psz : input char to compare
// acs : input reference to the CRxString
bool operator >= (const char *psz, const CRxString & acs);

// Check for a string of Unicode chars being greater than/equal to an CRxString
// pwsz : input char to compare
// acs : input reference to the CRxString
bool operator >= (const wchar_t *pwsz, const CRxString & acs);

// Check for a Unicode char being less than an CRxString
// wch : input char to compare
// acs : input reference to the CRxString
bool operator <  (wchar_t wch, const CRxString & acs);

// Check for a string of chars being less than an CRxString
// psz : input char to compare
// acs : input reference to the CRxString
bool operator <  (const char *psz, const CRxString & acs);

// Check for a string of Unicode chars being less than an CRxString
// pwsz : input char to compare
// acs : input reference to the CRxString
bool operator <  (const wchar_t *pwsz, const CRxString & acs);

// Check for a Unicode char being less than or equal to an CRxString
// wch : input char to compare
// acs : input reference to the CRxString
bool operator <= (wchar_t wch, const CRxString & acs);

// Check for a string of chars being less than or equal to an CRxString
// psz : input char to compare
// acs : input reference to the CRxString
bool operator <= (const char *psz, const CRxString & acs);

// Check for a string of Unicode chars being less than/equal to an CRxString
// pwsz : input char to compare
// acs : input reference to the CRxString
bool operator <= (const wchar_t *pwsz, const CRxString & acs);

// Copy an CRxString and insert a Unicode char in front of it
// wch : input char to insert
CRxString operator + (wchar_t wch, const CRxString & acs);

// Copy an CRxString and insert a string of chars in front of it
// psz : input pointer to the string of chars to insert
CRxString operator + (const char *psz, const CRxString & acs);

// Copy an CRxString and insert a string of Unicode chars in front of it
// pwsz : input pointer to the string of chars to insert
CRxString operator + (const wchar_t *pwsz, const CRxString & acs);

#ifdef _AFX

// Compare a CStringW for equality with an CRxString
// csw : input reference to the CStringW
// acs : input reference to the CRxString
bool operator == (const CStringW & csw, const CRxString & acs);

// Compare a CStringW for in-equality with an CRxString
// csw : input reference to the CStringW
// acs : input reference to the CRxString
bool operator != (const CStringW & csw, const CRxString & acs);

// Compare a CStringW for greater than an CRxString
// csw : input reference to the CStringW
// acs : input reference to the CRxString
bool operator >  (const CStringW & csw, const CRxString & acs);

// Compare a CStringW for greater than or equal to an CRxString
// csw : input reference to the CStringW
// acs : input reference to the CRxString
bool operator >= (const CStringW & csw, const CRxString & acs);

// Compare a CStringW for less than an CRxString
// csw : input reference to the CStringW
// acs : input reference to the CRxString
bool operator <  (const CStringW & csw, const CRxString & acs);

// Compare a CStringW for less than or equal to an CRxString
// csw : input reference to the CStringW
// acs : input reference to the CRxString
bool operator <= (const CStringW & csw, const CRxString & acs);

#define DISABLE_CSTRING_PLUS_CRxString 1
#ifndef DISABLE_CSTRING_PLUS_CRxString
// For now, these are disabled to avoid ambiguities.  If someone
// says CString cs = CString("a") + "b", then the "b" could get
// implicitly converted into an CRxString or a CString, so it
// won't compile.
//
CRxString operator + (const CStringW & csw, const CRxString & acs);
#endif
#endif

// Accessing inlines
//
inline CRxString::operator const char *() const
{
    return this->kszPtr();
}

inline CRxString::operator const wchar_t *() const
{
    return this->kwszPtr();
}

#ifdef UNICODE
inline const wchar_t * CRxString::constPtr() const
{
    return this->kwszPtr();
}

inline const wchar_t * CRxString::kTCharPtr() const
{
    return this->kwszPtr();
}

// This method only supported for apps built in same way as acad.
inline unsigned CRxString::tcharLength() const
{
    return this->length();
}

#elif _UNICODE
#error "Unexpected _UNICODE definition"
#else
inline const char * CRxString::constPtr() const
{
    return this->kszPtr();
}

inline const char * CRxString::kTCharPtr() const
{
    return this->kszPtr();
}

#endif

inline const CxCHAR * CRxString::kCxCHARPtr() const
{
    return this->kwszPtr();
}

inline void CRxString::clearAll()
{
    this->mnFlags = 0;
    this->mnPad1 = 0;
    this->mwszStr[0] = 0;
    this->mpszData = NULL;
}

// Extraction inlines
//
inline CRxString CRxString::mid(int nStart, int nNumChars) const
{
    return this->substr(nStart, nNumChars);
}

// Assignment inlines
//
inline CRxString & CRxString::operator = (char ch)
{
    return this->assign(ch);
}

inline CRxString & CRxString::operator = (wchar_t wch)
{
    return this->assign(wch);
}

inline CRxString & CRxString::operator = (const char *psz)
{
    return this->assign(psz);
}

inline CRxString & CRxString::operator = (const wchar_t *pwsz)
{
    return this->assign(pwsz);
}

inline CRxString & CRxString::operator = (const CRxString & acs)
{
    return this->assign(acs);
}

inline CRxString & CRxString::operator = (const CRxDbHandle & h)
{
    return this->assign(h);
}

// Modifying inlines
//
inline CRxString & CRxString::operator += (char ch)
{
    return this->append(ch);
}

inline CRxString & CRxString::operator += (wchar_t wch)
{
    return this->append(wch);
}

inline CRxString & CRxString::operator += (const char *psz)
{
    return this->append(psz);
}

inline CRxString & CRxString::operator += (const wchar_t *pwsz)
{
    return this->append(pwsz);
}

inline CRxString & CRxString::operator += (const CRxString & acs)
{
    return this->append(acs);
}

// Concatenation inlines
inline CRxString CRxString::operator + (char ch) const
{
    return this->concat(ch);
}

inline CRxString CRxString::operator + (wchar_t wch) const
{
    return this->concat(wch);
}

inline CRxString CRxString::operator + (const char * psz) const
{
    return this->concat(psz);
}

inline CRxString CRxString::operator + (const wchar_t * pwsz) const
{
    return this->concat(pwsz);
}

inline CRxString CRxString::operator + (const CRxString & acs) const
{
    return this->concat(acs);
}

// Comparison inlines
//

inline bool CRxString::operator == (wchar_t wch) const
{
    return this->compare(wch) == 0;
}

inline bool CRxString::operator == (const char *psz) const
{
    return this->compare(psz) == 0;
}

inline bool CRxString::operator == (const wchar_t *pwsz) const
{
    return this->compare(pwsz) == 0;
}

inline bool CRxString::operator == (const CRxString & acs) const
{
    return this->compare(acs) == 0;
}

inline bool CRxString::operator != (wchar_t wch) const
{
    return this->compare(wch) != 0;
}

inline bool CRxString::operator != (const char *psz) const
{
    return this->compare(psz) != 0;
}

inline bool CRxString::operator != (const wchar_t *pwsz) const
{
    return this->compare(pwsz) != 0;
}

inline bool CRxString::operator != (const CRxString & acs) const
{
    return this->compare(acs) != 0;
}

inline bool CRxString::operator > (wchar_t wch) const
{
    return this->compare(wch) > 0;
}

inline bool CRxString::operator > (const char *psz) const
{
    return this->compare(psz) > 0;
}

inline bool CRxString::operator > (const wchar_t *pwsz) const
{
    return this->compare(pwsz) > 0;
}

inline bool CRxString::operator > (const CRxString & acs) const
{
    return this->compare(acs) > 0;
}

inline bool CRxString::operator >= (wchar_t wch) const
{
    return this->compare(wch) >= 0;
}

inline bool CRxString::operator >= (const char *psz) const
{
    return this->compare(psz) >= 0;
}

inline bool CRxString::operator >= (const wchar_t *pwsz) const
{
    return this->compare(pwsz) >= 0;
}

inline bool CRxString::operator >= (const CRxString & acs) const
{
    return this->compare(acs) >= 0;
}

inline bool CRxString::operator < (wchar_t wch) const
{
    return this->compare(wch) < 0;
}

inline bool CRxString::operator < (const char *psz) const
{
    return this->compare(psz) < 0;
}

inline bool CRxString::operator < (const wchar_t *pwsz) const
{
    return this->compare(pwsz) < 0;
}

inline bool CRxString::operator < (const CRxString & acs) const
{
    return this->compare(acs) < 0;
}

inline bool CRxString::operator <= (wchar_t wch) const
{
    return this->compare(wch) <= 0;
}

inline bool CRxString::operator <= (const char *psz) const
{
    return this->compare(psz) <= 0;
}

inline bool CRxString::operator <= (const wchar_t *pwsz) const
{
    return this->compare(pwsz) <= 0;
}

inline bool CRxString::operator <= (const CRxString & acs) const
{
    return this->compare(acs) <= 0;
}


// We can do inline operators that deal with CStrings, without getting
// into binary format dependencies.  Don't make these out-of-line
// functions, because then we'll have a dependency between our
// components and CString-using clients.
//
#ifdef _AFX

inline CRxString::CRxString(const CStringW &csw)
{
    const wchar_t *pwsz = (const wchar_t *)csw;
    this->clearAll();
    *this = pwsz;
}

inline CRxString & CRxString::operator=(const CStringW &csw)
{
    const wchar_t *pwsz = (const wchar_t *)csw;
    return this->assign(pwsz);
}

inline CRxString & CRxString::operator+=(const CStringW &csw)
{
    const wchar_t *pwsz = (const wchar_t *)csw;
    return this->append(pwsz);
}

inline int CRxString::compare(const CStringW & csw) const
{
    const wchar_t *pwsz = (const wchar_t *)csw;
    return this->compare(pwsz);
}

inline int CRxString::compareNoCase(const CStringW & csw) const
{
    const wchar_t *pwsz = (const wchar_t *)csw;
    return this->compareNoCase(pwsz);
}

inline int CRxString::match(const CStringW & csw) const
{
    const wchar_t *pwsz = (const wchar_t *)csw;
    return this->match(pwsz);
}

inline int CRxString::matchNoCase(const CStringW & csw) const
{
    const wchar_t *pwsz = (const wchar_t *)csw;
    return this->matchNoCase(pwsz);
}

inline bool CRxString::operator == (const CStringW & csw) const
{
    return this->compare(csw) == 0;
}

inline bool CRxString::operator != (const CStringW & csw) const
{
    return this->compare(csw) != 0;
}

inline bool CRxString::operator > (const CStringW & csw) const
{
    return this->compare(csw) > 0;
}

inline bool CRxString::operator >= (const CStringW & csw) const
{
    return this->compare(csw) >= 0;
}

inline bool CRxString::operator < (const CStringW & csw) const
{
    return this->compare(csw) < 0;
}

inline bool CRxString::operator <= (const CStringW & csw) const
{
    return this->compare(csw) <= 0;
}

// Global CString-related operators
inline bool operator == (const CStringW & csw, const CRxString & acs)
{
    return acs.compare(csw) == 0;
}

inline bool operator != (const CStringW & csw, const CRxString & acs)
{
    return acs.compare(csw) != 0;
}

inline bool operator >  (const CStringW & csw, const CRxString & acs)
{
    return acs.compare(csw) < 0;
}

inline bool operator >= (const CStringW & csw, const CRxString & acs)
{
    return acs.compare(csw) <= 0;
}

inline bool operator <  (const CStringW & csw, const CRxString & acs)
{
    return acs.compare(csw) > 0;
}

inline bool operator <= (const CStringW & csw, const CRxString & acs)
{
    return acs.compare(csw) >= 0;
}

#ifndef DISABLE_CSTRING_PLUS_CRxString
inline CRxString operator + (const CStringW & csw, const CRxString & acs)
{
    const wchar_t *pwsz = (const wchar_t *)csw;
    return acs.precat(pwsz);
}
#endif


#endif // _AFX

// Inline global operators

inline bool operator == (wchar_t wch, const CRxString & acs)
{
    return acs.compare(wch) == 0;
}

inline bool operator == (const char *psz, const CRxString & acs)
{
    return acs.compare(psz) == 0;
}

inline bool operator == (const wchar_t *pwsz, const CRxString & acs)
{
    return acs.compare(pwsz) == 0;
}

inline bool operator != (wchar_t wch, const CRxString & acs)
{
    return acs.compare(wch) != 0;
}

inline bool operator != (const char *psz, const CRxString & acs)
{
    return acs.compare(psz) != 0;
}

inline bool operator != (const wchar_t *pwsz, const CRxString & acs)
{
    return acs.compare(pwsz) != 0;
}

inline bool operator > (wchar_t wch, const CRxString & acs)
{
    return acs.compare(wch) < 0;
}

inline bool operator > (const char *psz, const CRxString & acs)
{
    return acs.compare(psz) < 0;
}

inline bool operator > (const wchar_t *pwsz, const CRxString & acs)
{
    return acs.compare(pwsz) < 0;
}

inline bool operator >= (wchar_t wch, const CRxString & acs)
{
    return acs.compare(wch) <= 0;
}

inline bool operator >= (const char *psz, const CRxString & acs)
{
    return acs.compare(psz) <= 0;
}

inline bool operator >= (const wchar_t *pwsz, const CRxString & acs)
{
    return acs.compare(pwsz) <= 0;
}

inline bool operator < (wchar_t wch, const CRxString & acs)
{
    return acs.compare(wch) > 0;
}

inline bool operator < (const char *psz, const CRxString & acs)
{
    return acs.compare(psz) > 0;
}

inline bool operator < (const wchar_t *pwsz, const CRxString & acs)
{
    return acs.compare(pwsz) > 0;
}

inline bool operator <= (wchar_t wch, const CRxString & acs)
{
    return acs.compare(wch) >= 0;
}

inline bool operator <= (const char *psz, const CRxString & acs)
{
    return acs.compare(psz) >= 0;
}

inline bool operator <= (const wchar_t *pwsz, const CRxString & acs)
{
    return acs.compare(pwsz) >= 0;
}

// These don't modify the CRxString.  They return a copy.
inline CRxString operator + (CxCHAR ch, const CRxString & acs)
{
    return acs.precat(ch);
}

inline CRxString operator + (const char *psz, const CRxString & acs)
{
    return acs.precat(psz);
}

inline CRxString operator + (const wchar_t *pwsz, const CRxString & acs)
{
    return acs.precat(pwsz);
}

#endif // !_CRx_String_h

