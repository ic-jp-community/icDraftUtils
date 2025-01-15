#ifndef CRX_GEGBLABB_H
#define CRX_GEGBLABB_H
//

//（C）Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.

//  End-users must also comply with the terms and conditions 

//  in CAXA END-USER LICENSE AGREEMENT  while using this software.

//

//  版权所有（C）北京数码大方科技股份有限公司

//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》

//

#include "gegbl.h"

const int eGood = CRxGe::eGood;
const int eBad = CRxGe::eBad;

typedef CRxGe::EntityId EntityId;

const CRxGe::EntityId kEntity2d = CRxGe::kEntity2d;
const CRxGe::EntityId kEntity3d = CRxGe::kEntity3d;
const CRxGe::EntityId kPointEnt2d = CRxGe::kPointEnt2d;
const CRxGe::EntityId kPointEnt3d = CRxGe::kPointEnt3d;
const CRxGe::EntityId kPosition2d = CRxGe::kPosition2d;
const CRxGe::EntityId kPosition3d = CRxGe::kPosition3d;
const CRxGe::EntityId kPointOnCurve2d = CRxGe::kPointOnCurve2d;
const CRxGe::EntityId kPointOnCurve3d = CRxGe::kPointOnCurve3d;
const CRxGe::EntityId kBoundedPlane = CRxGe::kBoundedPlane;
const CRxGe::EntityId kCircArc2d = CRxGe::kCircArc2d;
const CRxGe::EntityId kCircArc3d = CRxGe::kCircArc3d;
const CRxGe::EntityId kConic2d = CRxGe::kConic2d;
const CRxGe::EntityId kConic3d = CRxGe::kConic3d;
const CRxGe::EntityId kCurve2d = CRxGe::kCurve2d;
const CRxGe::EntityId kCurve3d = CRxGe::kCurve3d;
const CRxGe::EntityId kEllipArc2d = CRxGe::kEllipArc2d;
const CRxGe::EntityId kEllipArc3d = CRxGe::kEllipArc3d;
const CRxGe::EntityId kHelix = CRxGe::kHelix;
const CRxGe::EntityId kLine2d = CRxGe::kLine2d;
const CRxGe::EntityId kLine3d = CRxGe::kLine3d;
const CRxGe::EntityId kLinearEnt2d = CRxGe::kLinearEnt2d;
const CRxGe::EntityId kLinearEnt3d = CRxGe::kLinearEnt3d;
const CRxGe::EntityId kLineSeg2d = CRxGe::kLineSeg2d;
const CRxGe::EntityId kLineSeg3d = CRxGe::kLineSeg3d;
const CRxGe::EntityId kPlanarEnt = CRxGe::kPlanarEnt;
const CRxGe::EntityId kExternalCurve3d = CRxGe::kExternalCurve3d;
const CRxGe::EntityId kExternalCurve2d = CRxGe::kExternalCurve2d;
const CRxGe::EntityId kPlane = CRxGe::kPlane;
const CRxGe::EntityId kRay2d = CRxGe::kRay2d;
const CRxGe::EntityId kRay3d = CRxGe::kRay3d;
const CRxGe::EntityId kSurface = CRxGe::kSurface;
const CRxGe::EntityId kSphere = CRxGe::kSphere;
const CRxGe::EntityId kCone = CRxGe::kCone;
const CRxGe::EntityId kTorus = CRxGe::kTorus;
const CRxGe::EntityId kCylinder = CRxGe::kCylinder;
const CRxGe::EntityId kSplineEnt2d = CRxGe::kSplineEnt2d;
const CRxGe::EntityId kSurfaceCurve2dTo3d = CRxGe::kSurfaceCurve2dTo3d;
const CRxGe::EntityId kSurfaceCurve3dTo2d = CRxGe::kSurfaceCurve3dTo2d;

const CRxGe::EntityId kPolyline2d = CRxGe::kPolyline2d;
const CRxGe::EntityId kAugPolyline2d = CRxGe::kAugPolyline2d;
const CRxGe::EntityId kNurbCurve2d = CRxGe::kNurbCurve2d;
const CRxGe::EntityId kDSpline2d = CRxGe::kDSpline2d;
const CRxGe::EntityId kCubicSplineCurve2d = CRxGe::kCubicSplineCurve2d;
const CRxGe::EntityId kSplineEnt3d = CRxGe::kSplineEnt3d;
const CRxGe::EntityId kPolyline3d = CRxGe::kPolyline3d;
const CRxGe::EntityId kAugPolyline3d = CRxGe::kAugPolyline3d;
const CRxGe::EntityId kNurbCurve3d = CRxGe::kNurbCurve3d;
const CRxGe::EntityId kDSpline3d = CRxGe::kDSpline3d;
const CRxGe::EntityId kCubicSplineCurve3d = CRxGe::kCubicSplineCurve3d;
const CRxGe::EntityId kTrimmedCrv2d = CRxGe::kTrimmedCrv2d;
const CRxGe::EntityId kCompositeCrv2d = CRxGe::kCompositeCrv2d;
const CRxGe::EntityId kCompositeCrv3d = CRxGe::kCompositeCrv3d;
const CRxGe::EntityId kEnvelope2d = CRxGe::kEnvelope2d;

const CRxGe::EntityId kExternalSurface = CRxGe::kExternalSurface;
const CRxGe::EntityId kNurbSurface = CRxGe::kNurbSurface;
const CRxGe::EntityId kOffsetSurface = CRxGe::kOffsetSurface;
const CRxGe::EntityId kTrimmedSurface = CRxGe::kTrimmedSurface;
const CRxGe::EntityId kCurveBoundedSurface = CRxGe::kCurveBoundedSurface;
const CRxGe::EntityId kPointOnSurface = CRxGe::kPointOnSurface;
const CRxGe::EntityId kExternalBoundedSurface = CRxGe::kExternalBoundedSurface;
const CRxGe::EntityId kCurveCurveInt2d = CRxGe::kCurveCurveInt2d;
const CRxGe::EntityId kCurveCurveInt3d = CRxGe::kCurveCurveInt3d;
const CRxGe::EntityId kBoundBlock2d = CRxGe::kBoundBlock2d;
const CRxGe::EntityId kBoundBlock3d = CRxGe::kBoundBlock3d;
const CRxGe::EntityId kOffsetCurve2d = CRxGe::kOffsetCurve2d;
const CRxGe::EntityId kOffsetCurve3d = CRxGe::kOffsetCurve3d;
const CRxGe::EntityId kPolynomCurve3d = CRxGe::kPolynomCurve3d;
const CRxGe::EntityId kBezierCurve3d = CRxGe::kBezierCurve3d;
const CRxGe::EntityId kObject = CRxGe::kObject;
const CRxGe::EntityId kFitData3d = CRxGe::kFitData3d;
const CRxGe::EntityId kHatch = CRxGe::kHatch;
const CRxGe::EntityId kTrimmedCurve2d = CRxGe::kTrimmedCurve2d;
const CRxGe::EntityId kTrimmedCurve3d = CRxGe::kTrimmedCurve3d;
const CRxGe::EntityId kCurveSampleData = CRxGe::kCurveSampleData;

const CRxGe::EntityId kEllipCone = CRxGe::kEllipCone;
const CRxGe::EntityId kEllipCylinder = CRxGe::kEllipCylinder;
const CRxGe::EntityId kIntervalBoundBlock = CRxGe::kIntervalBoundBlock;
const CRxGe::EntityId kClipBoundary2d = CRxGe::kClipBoundary2d;
const CRxGe::EntityId kExternalObject = CRxGe::kExternalObject;
const CRxGe::EntityId kCurveSurfaceInt = CRxGe::kCurveSurfaceInt;
const CRxGe::EntityId kSurfaceSurfaceInt = CRxGe::kSurfaceSurfaceInt;


typedef CRxGe::ExternalEntityKind ExternalEntityKind;

const CRxGe::ExternalEntityKind kAcisEntity = CRxGe::kAcisEntity;
const CRxGe::ExternalEntityKind kExternalEntityUndefined
                                = CRxGe::kExternalEntityUndefined;

typedef CRxGe::NurbSurfaceProperties NurbSurfaceProperties;

const CRxGe::NurbSurfaceProperties kOpen = CRxGe::kOpen;
const CRxGe::NurbSurfaceProperties kClosed = CRxGe::kClosed;
const CRxGe::NurbSurfaceProperties kPeriodic = CRxGe::kPeriodic;
const CRxGe::NurbSurfaceProperties kRational = CRxGe::kRational;
const CRxGe::NurbSurfaceProperties kNoPoles= CRxGe::kNoPoles;
const CRxGe::NurbSurfaceProperties kPoleAtMin = CRxGe::kPoleAtMin;
const CRxGe::NurbSurfaceProperties kPoleAtMax = CRxGe::kPoleAtMax;
const CRxGe::NurbSurfaceProperties kPoleAtBoth = CRxGe::kPoleAtBoth;

typedef CRxGe::PointContainment PointContainment;

const CRxGe::PointContainment kInside = CRxGe::kInside;
const CRxGe::PointContainment kOutside = CRxGe::kOutside;
const CRxGe::PointContainment kOnBoundary = CRxGe::kOnBoundary;

typedef CRxGe::CRxGeXConfig CRxGeXConfig;

const CRxGe::CRxGeXConfig kNotDefined = CRxGe::kNotDefined;
const CRxGe::CRxGeXConfig kUnknown = CRxGe::kUnknown;
const CRxGe::CRxGeXConfig kLeftRight = CRxGe::kLeftRight;
const CRxGe::CRxGeXConfig kRightLeft = CRxGe::kRightLeft;
const CRxGe::CRxGeXConfig kLeftLeft = CRxGe::kLeftLeft;
const CRxGe::CRxGeXConfig kRightRight = CRxGe::kRightRight;
const CRxGe::CRxGeXConfig kPointLeft = CRxGe::kPointLeft;
const CRxGe::CRxGeXConfig kPointRight = CRxGe::kPointRight;
const CRxGe::CRxGeXConfig kLeftOverlap = CRxGe::kLeftOverlap;
const CRxGe::CRxGeXConfig kOverlapLeft = CRxGe::kOverlapLeft;
const CRxGe::CRxGeXConfig kRightOverlap = CRxGe::kRightOverlap;
const CRxGe::CRxGeXConfig kOverlapRight = CRxGe::kOverlapRight;
const CRxGe::CRxGeXConfig kOverlapStart = CRxGe::kOverlapStart;
const CRxGe::CRxGeXConfig kOverlapEnd = CRxGe::kOverlapEnd;
const CRxGe::CRxGeXConfig kOverlapOverlap = CRxGe::kOverlapOverlap;

typedef CRxGe::ErrorCondition  CRxGeError;
 
const CRxGe::ErrorCondition	kOk = CRxGe::kOk;
const CRxGe::ErrorCondition	k0This = CRxGe::k0This;
const CRxGe::ErrorCondition	k0Arg1 = CRxGe::k0Arg1;
const CRxGe::ErrorCondition	k0Arg2 = CRxGe::k0Arg2;
const CRxGe::ErrorCondition	kPerpendicularArg1Arg2 = CRxGe::kPerpendicularArg1Arg2;     
const CRxGe::ErrorCondition	kEqualArg1Arg2 = CRxGe::kEqualArg1Arg2;
const CRxGe::ErrorCondition	kEqualArg1Arg3 = CRxGe::kEqualArg1Arg3;
const CRxGe::ErrorCondition	kEqualArg2Arg3 = CRxGe::kEqualArg2Arg3;
const CRxGe::ErrorCondition	kLinearlyDependentArg1Arg2Arg3 = CRxGe::kLinearlyDependentArg1Arg2Arg3;
const CRxGe::ErrorCondition	kArg1TooBig = CRxGe::kArg1TooBig;
const CRxGe::ErrorCondition	kArg1OnThis = CRxGe::kArg1OnThis;
const CRxGe::ErrorCondition	kArg1InsideThis = CRxGe::kArg1InsideThis;

typedef CRxGe::CRxGeIntersectError CRxGeIntersectError;

const CRxGe::CRxGeIntersectError kXXOk = CRxGe::kXXOk;
const CRxGe::CRxGeIntersectError kXXIndexOutOfRange = CRxGe::kXXIndexOutOfRange;
const CRxGe::CRxGeIntersectError kXXWrongDimensionAtIndex = CRxGe::kXXWrongDimensionAtIndex;
const CRxGe::CRxGeIntersectError kXXUnknown = CRxGe::kXXUnknown;
#endif
