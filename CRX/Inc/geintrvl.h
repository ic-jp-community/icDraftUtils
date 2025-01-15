#ifndef CRX_GEINTRVL_H
#define CRX_GEINTRVL_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

//
#include "gegbl.h"
#include "cdraft.h"
#include "gedll.h"
#pragma pack (push, 8)

class
GE_DLLEXPIMPORT
CRxGeInterval
{
public:
    CRxGeInterval(double tol = 1.e-12);
    CRxGeInterval(const CRxGeInterval& src);
    CRxGeInterval(double lower, double upper, double tol = 1.e-12);
    CRxGeInterval(CAXA::Boolean boundedBelow, double bound,
                 double tol = 1.e-12);
    ~CRxGeInterval();

    // Assignment operator.
    //
    CRxGeInterval&  operator =       (const CRxGeInterval& otherInterval);

    // Get/set methods.
    //
    double         lowerBound       () const;
    double         upperBound       () const;
    double         element          () const;
    void           getBounds        (double& lower, double& upper) const;
    double         length           () const;
    double         tolerance        () const;

    CRxGeInterval&  set              (double lower, double upper);
    CRxGeInterval&  set              (CAXA::Boolean boundedBelow, double bound);
    CRxGeInterval&  set              ();
    CRxGeInterval&  setUpper         (double upper);
    CRxGeInterval&  setLower         (double lower);
    CRxGeInterval&  setTolerance     (double tol);

    // Interval editing.
    //
    void           getMerge         (const CRxGeInterval& otherInterval, CRxGeInterval& result) const;
    int            subtract         (const CRxGeInterval& otherInterval,
                                     CRxGeInterval& lInterval,
                                     CRxGeInterval& rInterval) const;
    CAXA::Boolean intersectWith    (const CRxGeInterval& otherInterval, CRxGeInterval& result) const;

    // Interval characterization.
    //
    CAXA::Boolean isBounded        () const;
    CAXA::Boolean isBoundedAbove   () const;
    CAXA::Boolean isBoundedBelow   () const;
    CAXA::Boolean isUnBounded      () const;
    CAXA::Boolean isSingleton      () const;

    // Relation to other intervals.
    //
    CAXA::Boolean isDisjoint       (const CRxGeInterval& otherInterval) const;
    CAXA::Boolean contains         (const CRxGeInterval& otherInterval) const;
    CAXA::Boolean contains         (double val) const;

    // Continuity
    //
    CAXA::Boolean isContinuousAtUpper (const CRxGeInterval& otherInterval) const;
    CAXA::Boolean isOverlapAtUpper    (const CRxGeInterval& otherInterval,
                                        CRxGeInterval& overlap) const;
    // Equality
    //
    CAXA::Boolean operator ==      (const CRxGeInterval& otherInterval) const;
    CAXA::Boolean operator !=      (const CRxGeInterval& otherInterval) const;
    CAXA::Boolean isEqualAtUpper   (const CRxGeInterval& otherInterval) const;
    CAXA::Boolean isEqualAtUpper   (double value) const;
    CAXA::Boolean isEqualAtLower   (const CRxGeInterval& otherInterval) const;
    CAXA::Boolean isEqualAtLower   (double value) const;

    // To be used with periodic curves
    //
    CAXA::Boolean isPeriodicallyOn (double period, double& val);

    // Comparisons.
    //
    friend
    GE_DLLEXPIMPORT
    CAXA::Boolean operator >       (double val, const CRxGeInterval& intrvl);
    CAXA::Boolean operator >       (double val) const;
    CAXA::Boolean operator >       (const CRxGeInterval& otherInterval) const;
    friend
    GE_DLLEXPIMPORT
    CAXA::Boolean operator >=      (double val, const CRxGeInterval& intrvl);
    CAXA::Boolean operator >=      (double val) const;
    CAXA::Boolean operator >=      (const CRxGeInterval& otherInterval) const;
    friend
    GE_DLLEXPIMPORT
    CAXA::Boolean operator <       (double val, const CRxGeInterval& intrvl);
    CAXA::Boolean operator <       (double val) const;
    CAXA::Boolean operator <       (const CRxGeInterval& otherInterval) const;
    friend
    GE_DLLEXPIMPORT
    CAXA::Boolean operator <=      (double val, const CRxGeInterval& intrvl);
    CAXA::Boolean operator <=      (double val) const;
    CAXA::Boolean operator <=      (const CRxGeInterval& otherInterval) const;

/*
protected:
    friend class CRxGeImpInterval;

    CRxGeImpInterval  *mpImpInt;

    // Construct object from its corresponding implementation object.
    CRxGeInterval (CRxGeImpInterval&, int);

private:
    int              mDelInt;
*/
};

#pragma pack (pop)
#endif
