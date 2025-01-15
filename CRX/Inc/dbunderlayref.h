//
//////////////////////////////////////////////////////////////////////////////
//
//（C）Copyright 2021 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  版权所有（C）北京数码大方科技股份有限公司
//  最终用户使用本软件必须遵守《CAXA最终用户许可使用协议》
//
//////////////////////////////////////////////////////////////////////////////
//
// DESCRIPTION: Exported class for underlay references in dwg file - CRxDbUnderlayReference
#pragma once
#ifndef CRXDB_DBUNDERLAYREF_H
#define CRXDB_DBUNDERLAYREF_H

#include "dbmain.h"
#include "crxString.h"
#include "gemat3d.h"

#pragma pack (push, 8)

class CRxUnderlayLayer;
/// <summary>
/// Abstract class that represents underlays in the drawing. Underlays are similar to raster images
/// but their content is snappable. An CRxDbUnderlayReference must reference compatible an CRxDbUnderlayDefinition.
/// The CRxDbUnderlayRefernece is responsible for the placement of the content within the drawing while CRxDbUnderlayDefinition
/// handles the linkage to the underlay content. 
/// Instances of CRxDbUnderlayReference derived concrete classes are inserted in a block table record.
/// Instances of CRxDbUnderlayDefinition derived concrete classes are inserted into a dictionay off of the named object dictionary.
/// </summary>
CRX_DEFINE_CLSID(BB250309-8C4B-4D98-B93B-D958AC675152, CRxDbUnderlayReference)
class CRXDB_API CRxDbUnderlayReference : public CRxDbEntity
{
public:
	CRxDbUnderlayReference(ICxCrxObject* i_pCrxObject = NULL);

	CRX_DECLARE_DYNCREATE(CRxDbUnderlayReference);
	//CRxDbUnderlayReference(ICxCrxObject* i_pCrxObject = NULL, int iObjType = 0);
	/// <summary>
	/// Destroys the reference.
	/// </summary>
	//virtual ~CRxDbUnderlayReference() = 0;
	/// <summary>
	/// Gets the position of underlay in WCS (or block space coordinates if the reference is part of a block).
	/// </summary>
	/// <returns>Returns the position of underlay in WCS (or block space coordinates if the reference is part of a block).</returns>
	CRxGePoint3d       position() const;
	/// <summary>
	/// Gets the rotation value around the axis defined by the point returned by position() and the vector returned by normal().
	/// </summary>
	/// <returns>Returns the rotation value of the underlay.</returns>
	double            rotation() const;
	/// <summary>
	/// Sets the rotation value around the axis defined by the point returned by position() and the vector returned by normal().
	/// </summary>
	/// <param name="rotation">New rotation value.</param>
	/// <returns>Returns CDraft::eOk if successful.</returns>
	//CDraft::ErrorStatus setRotation(double rotation);
	/// <summary>
	/// Gets the normal of the underlay.
	/// </summary>
	/// <returns>Returns the normal of the underlay.</returns>
	CRxGeVector3d      normal() const;
	/// <summary>
	/// Sets the normal of the underlay.
	/// </summary>
	/// <param name="normal">New normal value.</param>
	/// <returns>Returns CDraft::eOk if successful.</returns>
	CDraft::ErrorStatus setNormal(const CRxGeVector3d& normal);
	/// <summary>
	/// Gets the transformation matrix from underlay coordinate system to world coordinate system (or block space coordinates if the underlay is part of a block).
	/// the transformation is defined by position(), normal() and rotatation().
	/// </summary>
	/// <returns>Returns the model to WCS transformation of the underlay.</returns>
	//CRxGeMatrix3d transform() const;
	/// <summary>
	/// Sets the trnsformation matrix of the underlay. 
	/// The translation component of <paramref name="transform"/> will be used to set the position property.
	/// The rotation component of <paramref name="transform"/> will be used to set the rotation property.
	/// The scale component of <paramref name="transform"/> will be used to set the scale property.
	/// </summary>
	/// <param name="transform">New transformation matrix.</param>
	/// <returns>Returns CDraft::eOk if successful.</returns>
	//CDraft::ErrorStatus setTransform(const CRxGeMatrix3d& transform);
	/// <summary>
	/// Gets the object id of the CRxDbUnderlayDefinition that this underlay references.
	/// </summary>
	/// <returns>Returns the object id of the CRxDbUnderlayDefinition that this underlay references.</returns>
	CRxDbObjectId      definitionId() const;
	/// <summary>
	/// Sets the model to world transformation matrix of the underlay. 
	/// The translation component of <paramref name="transform"/> will be used to set the position property.
	/// The rotation component of <paramref name="transform"/> will be used to set the rotation property.
	/// The scale component of <paramref name="transform"/> will be used to set the scale property.
	/// </summary>
	/// <param name="id">New transformation matrix.</param>
	/// <returns>Returns CDraft::eOk if successful.</returns>
	CDraft::ErrorStatus setDefinitionId(CRxDbObjectId id);

	CDraft::ErrorStatus  setWidth(double width);

	CDraft::ErrorStatus  width(double& width) const;

	CDraft::ErrorStatus  setHeight(double height);

	CDraft::ErrorStatus  height(double& height) const;
	/// <summary>
	/// Gets a boolean indicating whether the clip boundary should be used.
	/// </summary>
	/// <returns>Returns a boolean indicating whether the clip boundary should be used.</returns>
	bool                     isClipped() const;
	/// <summary>
	/// Sets a boolean indicating whether the clip boundary should be used.
	/// </summary>
	/// <param name="value">New value.</param>
	/// <returns>Returns CDraft::eOk if successful.</returns>
	CDraft::ErrorStatus        setIsClipped(bool value);
	/// <summary>
	/// Gets the contrast value for the underlay ([0-100]).
	/// </summary>
	/// <returns>Returns the contrast value for the underlay ([0-100]).</returns>
	CAXA::UInt8      contrast() const;
	/// <summary>
	/// Sets the contrast value for the underlay ([0-100]).
	/// </summary>
	/// <param name="value">New value.</param>
	/// <returns>Returns CDraft::eOk if successful.</returns>
	CDraft::ErrorStatus setContrast(CAXA::UInt8 value);
	/// <summary>
	/// Gets the fade value for the underlay ([0-100]).
	/// </summary>
	/// <returns>Returns the fade value for the underlay ([0-100]).</returns>
	CAXA::UInt8      fade() const;
	/// <summary>
	/// Sets the fade value for the underlay ([0-100]).
	/// </summary>
	/// <param name="value">New value.</param>
	/// <returns>Returns CDraft::eOk if successful.</returns>
	CDraft::ErrorStatus setFade(CAXA::UInt8 value);
	/// <summary>
	/// Gets a value indicating whether the underlay content is shown. This variable governs the visibilty of the underlay content not its frame or clipping boundary.
	/// </summary>
	/// <returns>Returns a value indicating whether the underlay content is shown.</returns>
	bool              isOn() const;
	/// <summary>
	/// Sets a value indicating whether the underlay content is shown. This variable governs the visibilty of the underlay content not its frame or clipping boundary.
	/// </summary>
	/// <param name="value">New value.</param>
	/// <returns>Returns CDraft::eOk if successful.</returns>
	CDraft::ErrorStatus setIsOn(bool value);
	/// <summary>
	/// Gets a value indicating whether the underlay content is shown monochrome. 
	/// </summary>
	/// <returns>Returns a value indicating whether the underlay content is shown monochrome.</returns>
	bool              isMonochrome() const;
	/// <summary>
	/// Sets a value indicating whether the underlay content is shown monochrome. 
	/// </summary>
	/// <param name="value">New value.</param>
	/// <returns>Returns CDraft::eOk if successful.</returns>
	CDraft::ErrorStatus setIsMonochrome(bool value);
	/// <summary>
	/// Gets a value indicating whether the dwf content is adjusted for the current background color. Not all underlay types observe
	/// this setting.
	/// </summary>
	/// <returns>Returns a value indicating whether the underlay content is adjusted for the current background color.</returns>
	bool              isAdjustedForBackground() const;
	/// <summary>
	/// Sets a value indicating whether the underlay content is adjusted for the current background color. Not all underlay types observe
	/// this setting.
	/// </summary>
	/// <param name="value">New value.</param>
	/// <returns>Returns CDraft::eOk if successful.</returns>
	CDraft::ErrorStatus setIsAdjustedForBackground(bool value);
	/// <summary>
	/// Gets a value indicating whether frame of the underlay is visible on screen.
	/// </summary>
	/// <returns>returns true if the frame is visible</returns>
	//virtual bool isFrameVisible() const;
	/// <summary>
	/// Gets a value indicating whether frame of the underlay is visible in a plot.
	/// </summary>
	/// <returns>returns true if the frame is visible</returns>
	//virtual bool isFramePlottable() const;
	/// <summary>
	/// Gets number of layers for this underlay
	/// </summary>
	/// <returns>returns 0 if underlay has no layer information.</returns>
	//CAXA::UInt32 underlayLayerCount() const;
	/// <summary>
	/// Gets lower limit of the legal contrast values.
	/// </summary>
	/// <returns>returns lower limit of the legal contrast values.</returns>
	//static CAXA::UInt8 contrastLowerLimit();
	/// <summary>
	/// Gets upper limit of the legal contrast values.
	/// </summary>
	/// <returns>returns upper limit of the legal contrast values.</returns>
	//static CAXA::UInt8 contrastUpperLimit();
	/// <summary>
	/// Gets default contrast value.
	/// </summary>
	/// <returns>Returnss default contrast value.</returns>
	//static CAXA::UInt8 contrastDefault();
	/// <summary>
	/// Gets lower limit of the legal fade values.
	/// </summary>
	/// <returns>returns lower limit of the legal fade values.</returns>
	//static CAXA::UInt8 fadeLowerLimit();
	/// <summary>
	/// Gets upper limit of the legal fade values.
	/// </summary>
	/// <returns>returns upper limit of the legal fade values.</returns>
	//static CAXA::UInt8 fadeUpperLimit();
	/// <summary>
	/// Gets default fade value.
	/// </summary>
	/// <returns>Returnss default fade value.</returns>
	//static CAXA::UInt8 fadeDefault();
	/// <summary>
	/// Check if clip is inverted.
	/// </summary>
	/// <returns>Returns true if inverted.</returns>
	bool isClipInverted() const;
	/// <summary>
	/// Set if clip is inverted.
	/// </summary>
	/// <param name="value">New value.</param>
	/// <returns>Returns CDraft::eOk if successful.</returns>
	CDraft::ErrorStatus setClipInverted(bool value);
	/// <summary>
	/// Generate the clip boundary from a polyline.
	/// </summary>
	/// <param name="polyId">Polyline ID</param>
	/// <returns>Returns CDraft::eOk if successful.</returns>
	//CDraft::ErrorStatus generateClipBoundaryFromPline(CRxDbObjectId polyId);
};

CRX_DEFINE_CLSID(BB250309-8C4B-4D98-B93B-D958AC675152, CRxDbPdfReference)
class CRXDB_API CRxDbPdfReference : public CRxDbUnderlayReference
{
public:
	/// <summary>
	/// Default constructor.
	/// </summary>
	/*CRXDB_API */CRxDbPdfReference(ICxCrxObject* i_pCrxObject = NULL);

	CRX_DECLARE_DYNCREATE(CRxDbPdfReference);
	/// <summary>
	/// Destroys the reference.
	/// </summary>
	//CRXDB_API virtual ~CRxDbPdfReference();
protected:
	/// <summary>
	/// Overridden from CRxDbEntity
	/// </summary>
	/// <param name="pClsid">See CRxDbEntity::getClassID()</param>
	/// <returns>See CRxDbEntity::getClassID()</returns>
	//virtual CDraft::ErrorStatus   subGetClassID(CLSID* pClsid) const;
public:
	/// <summary>
	/// Gets default contrast value.
	/// </summary>
	/// <returns>Returnss default contrast value.</returns>
	//static CAXA::UInt8 contrastDefault();
	/// <summary>
	/// Gets default fade value.
	/// </summary>
	/// <returns>Returnss default fade value.</returns>
	//static CAXA::UInt8 fadeDefault();
};

#pragma pack (pop)

#endif
