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
// DESCRIPTION: Exported class for underlay definitions in dwg file - CRxDbUnderlayDefintion
#pragma once
#ifndef CRXDB_DBUNDERLAYDEF_H
#define CRXDB_DBUNDERLAYDEF_H
#include "dbmain.h"
#include "crxString.h"

#pragma pack (push, 8)

class CRxDbUnderlayItem;
class CRxDbUnderlayHost;
class IAcReadStream;

/// <summary>
/// Abstract class that handles the linkage to the external underlay content. Underlays are similar to raster images
/// but their content is snappable. An CRxDbUnderlayDefinition is referenced by 0 or more CRxDbUnderlayReferences.
/// The CRxDbUnderlayRefernece is responsible for the placement of the content within the drawing while CRxDbUnderlayDefinition
/// handles the linkage to the underlay content. 
/// Instances of CRxDbUnderlayReference derived concrete classes are inserted in a block table record.
/// Instances of CRxDbUnderlayDefinition derived concrete classes are inserted into a dictionay off of the named object dictionary.
/// </summary>
CRX_DEFINE_CLSID(ED3B2FDB-613B-4404-B5E3-AB298B80023A, CRxDbUnderlayDefinition)
class CRXDB_API CRxDbUnderlayDefinition : public CRxObject
{
public:
	CRxDbUnderlayDefinition(ICxCrxObject* i_pCrxObject = NULL);

	CRX_DECLARE_DYNCREATE(CRxDbUnderlayDefinition);
	///<summary>Default constructor.</summary>
	//CRxDbUnderlayDefinition();
	///<summary>Destructor.</summary>
	//virtual ~CRxDbUnderlayDefinition() = 0;
	/// <summary>
	/// Sets the name of the file that this underlay references. This name can be the following form:
	/// 1. relative path (relative to the host drawing) 
	/// 2. file name only (will be searched on the support search path)
	/// 3. full path
	/// </summary>
	/// <param name="file">Name of the file</param>
	/// <returns>Returns CDraft::eOk if successful.</returns>
	CDraft::ErrorStatus setSourceFileName(const CxCHAR* file);
	/// <summary>
	/// Gets the name of the file that this underlay references. This name is in the form (relative or full path) that the user specified.
	/// </summary>
	/// <returns>Returns a pointer to the internal datamember that holds the source file path.
	/// The string should not be modified or freed and it may get invalidated if modifications are made to underlay definition.</returns>
	const CxCHAR* getSourceFileName() const;
	/// <summary>
	/// This function returns a pointer to an IAcReadStream for the file that
	/// this underlay references, or NULL if there is no file available.
	/// </summary>
	//IAcReadStream* getReadStream() const;
	/// <summary>
	/// Gets the name of the file that this underlay references. This name is always a full path.
	/// </summary>
	/// <param name="file">Variable that is set to point to the internal datamember that holds the active file path upon successful return.
	/// The string should not be modified or freed and it may get invalidated if modifications are made to underlay definition.</param>
	/// <returns>Returns CDraft::eOk if successful.</returns>
	CDraft::ErrorStatus getActiveFileName(const CxCHAR*& file) const;
	/// <summary>
	/// Gets the name of the file that this underlay references. This name is always a full path.
	/// </summary>
	/// <param name="file">Variable that is set to hold the source file path upon successful return.</param>
	/// <returns>Returns CDraft::eOk if successful.</returns>
	//CDraft::ErrorStatus getActiveFileName(CRxString& file) const;
	/// <summary>
	/// Sets the name of the underlay item that this underlay should reference.
	/// </summary>
	/// <param name="item">Name of the item</param>
	/// <returns>Returns CDraft::eOk if successful.</returns>
	CDraft::ErrorStatus setItemName(const CxCHAR* item);
	/// <summary>
	/// Gets the name of the underlay item that this underlay currently references.
	/// </summary>
	/// <returns>Returns a pointer to the internal datamember that holds the item name.
	/// The string should not be modified or freed and it may get invalidated if modifications are made to underlay definition.</returns>
	const CxCHAR* getItemName() const;
	/// <summary>
	/// Sets the source path and underlay item that this underlay should reference. Calls unload() to unload any previous underlay item.
	/// </summary>
	/// <param name="sourceFileName">Source file path.</param>
	/// <param name="activeFileName">Current or active file path. This points to the file where it is currently found.</param>
	/// <param name="pItem">The item to be referenced. The underlay definition takes ownership of the item and it should *not* be deleted by the client.</param>
	/// <returns>Returns CDraft::eOk if successful.</returns>
	CDraft::ErrorStatus setUnderlayItem(const CxCHAR* sourceFileName, const CxCHAR* activeFileName, CRxDbUnderlayItem* pItem);
	/// <summary>
	/// Gets the underlay item that this underlay currently references.
	/// </summary>
	/// <returns>Returns a pointer to the internal datamember that holds the item.
	/// The object should not be modified or freed and it may get invalidated if modifications are made to underlay definition.</returns>
	//const CRxDbUnderlayItem* getUnderlayItem() const;
	/// <summary>
	/// Attempts to load the file returned by getActiveFileName().
	/// </summary>
	/// <param name="password">Optional password. I password is NULL but is necessary to open file this function will prompt the user.</param>
	/// <returns>Returns CDraft::eOk if successful.</returns>
	CDraft::ErrorStatus load(const wchar_t* password);
	/// <summary>
	/// Unloads the underlay file. References will behave as the file was never loaded.
	/// </summary>
	void unload();
	/// <summary>
	/// Gets a boolean indicating whether the underlay is currently loaded.
	/// </summary>
	/// <returns>Returns true, if the underlay is loaded.</returns>
	bool isLoaded() const;
	/// <summary>
	/// Gets the name of the dictionary that holds the CRxDbUnderlayDefinition objects in the named objects dictionary.
	/// </summary>
	/// <param name="underlayDefinitionType">The class descriptor of the underlay type for which to retrive the dictionary name for.</param>
	/// <returns>Returns the name of the dictionary that holds the CRxDbUnderlayDefinition objects in the named objects dictionary.</returns>
	//static CRxString dictionaryKey(const CRxClass* underlayDefinitionType);
private:
	/// <summary>
	/// When overridden in derived classes it gets the underlay host to be used by this underlay definition.
	/// </summary>
	/// <returns>Returns the underlay host to be used by this underlay definition.</returns>
	//virtual const CRxDbUnderlayHost* getUnderlayHost() const = 0;
};

CRX_DEFINE_CLSID(ED3B2FDB-613B-4404-B5E3-AB298B80023A, CRxDbPdfDefinition)
class CRXDB_API CRxDbPdfDefinition : public CRxDbUnderlayDefinition
{
public:
	///<summary>Default constructor.</summary>
	/*CRXDB_API */CRxDbPdfDefinition(ICxCrxObject* i_pCrxObject = NULL);

	CRX_DECLARE_DYNCREATE(CRxDbPdfDefinition);
	///<summary>Destructor.</summary>
	//CRXDB_API virtual ~CRxDbPdfDefinition();
private:
	//virtual  const CRxDbUnderlayHost* getUnderlayHost() const;
};
#pragma pack (pop)

#endif
