//£®C£©Copyright 2012 CAXA Technology Co., Ltd.. All rights reserved.
//  End-users must also comply with the terms and conditions 
//  in CAXA END-USER LICENSE AGREEMENT  while using this software.
//
//  ∞Ê»®À˘”–£®C£©±±æ© ˝¬ÅEÛ∑Ωø∆ººπ…∑›”–œﬁπ´Àæ
//  ◊˚Ú’”√ªß π”√±æ»˙ÿ˛±ÿ–ÅEÒ ÿ°∂CAXA◊˚Ú’”√ªß–˙€… π”√–≠“È°∑
//

#ifndef __CRXDBOBJECT_H_
#define __CRXDBOBJECT_H_

#include <share.h>
#include "rxobject.h"
#include "rxclass.h"
#include "CRxHeapOpers.h"
#include "DbColor.h"
#include "crxDb.h"
#include "dbid.h"
#include "dbptrar.h"
#include "cdsdef.h"
#include "dbidar.h"
#include "dbsubeid.h"
#include "gept3dar.h"
#include "dbintar.h"
#include "drawable.h"
//#include "dbPaper.h"

#include "dbsecurity.h"
#include "dbidmap.h"

class CRxGiDrawable;
class CRxDbObject;
class CRxDbSymbolTable;
class CRxDbBlockTable;
class CRxDbLayerTable;
class CRxDbLinetypeTable;
class CRxDbTextStyleTable;
class CRxDbDimStyleTable;
class CRxDbRegAppTable;
class CRxDbUCSTable;
class CRxDbPaperTable;
class CRxDbXObject;
class CRxCmColor;
class CRxCmComplexColor;
class CRxGeFastTransform;
class CRxGiWorldDraw;
class CRxDbRoughStyleTable;

class CRxDbDatumStyleTable;
class CRxDbGeoTolStyleTable;
class CRxDbCutsStyleTable;
class CRxDbWeldStyleTable;

class CRxDbPartnoStyleTable;
class CRxDbBomStyleTable;
class CRxDbLeaderStyleTable;

class CRxDbDictionary;

extern CRXDB_CLASS const CRxDbFullSubentPath kNullSubent;

class CRxDbGripData;
typedef CRxArray<CRxDbGripData*> CRxDbGripDataPtrArray;
typedef CRxArray<CRxDbFullSubentPath,
	CRxArrayObjectCopyReallocator<CRxDbFullSubentPath> > CRxDbFullSubentPathArray;


CRX_DEFINE_NULL_CLSID(CRxDbObjectReactor)
class CRXDB_CLASS CRxDbObjectReactor: public CRxObject
{
public:
	CRX_DECLARE_DYNAMIC(CRxDbObjectReactor);

	virtual void cancelled      (const CRxDbObject* dbObj);
	virtual void copied         (const CRxDbObject* dbObj,	const CRxDbObject* newObj);
	virtual void erased         (const CRxDbObject* dbObj,	CAXA::Boolean pErasing = true);
	virtual void goodbye        (const CRxDbObject* dbObj);
	virtual void openedForModify(const CRxDbObject* dbObj);
	virtual void modified       (const CRxDbObject* dbObj);
	virtual void subObjModified (const CRxDbObject* dbObj,	const CRxDbObject* subObj);
	virtual void modifyUndone   (const CRxDbObject* dbObj);
	virtual void modifiedXData  (const CRxDbObject* dbObj);
	virtual void unappended     (const CRxDbObject* dbObj);
	virtual void reappended     (const CRxDbObject* dbObj);
	virtual void objectClosed   (const CRxDbObjectId objId);

protected:
	CRxDbObjectReactor();
};

CRX_DEFINE_NULL_CLSID(CRxDbDatabaseReactor)
class CRXDB_CLASS CRxDbDatabaseReactor: public CRxObject
{
public:
	CRX_DECLARE_DYNAMIC(CRxDbDatabaseReactor);

	virtual void objectAppended       (const CRxDbDatabase* dwg, const CRxDbObject* dbObj);
	virtual void objectUnAppended     (const CRxDbDatabase* dwg, const CRxDbObject* dbObj);
	virtual void objectReAppended     (const CRxDbDatabase* dwg, const CRxDbObject* dbObj);
	virtual void objectOpenedForModify(const CRxDbDatabase* dwg, const CRxDbObject* dbObj);
	virtual void objectModified       (const CRxDbDatabase* dwg, const CRxDbObject* dbObj);
	virtual void objectErased         (const CRxDbDatabase* dwg, const CRxDbObject* dbObj,
		CAXA::Boolean pErased = true);
	virtual void headerSysVarWillChange(const CRxDbDatabase* dwg, const CxCHAR* name);
	virtual void headerSysVarChanged   (const CRxDbDatabase* dwg, const CxCHAR* name,
		CAXA::Boolean bSuccess);
	virtual void proxyResurrectionCompleted(const CRxDbDatabase* dwg,
		const CxCHAR* appname, 
		CRxDbObjectIdArray& objects);
	virtual void goodbye              (const CRxDbDatabase* dwg);
};

class CRXDB_CLASS CRxDbExtents //: public CRxHeapOperators
{
public:
	CRxDbExtents();                                      
	CRxDbExtents(const CRxDbExtents& src);           
	CRxDbExtents(const CRxGePoint3d& min, const CRxGePoint3d& max);  

	CRxGePoint3d       minPoint() const { return mMinPoint; }
	CRxGePoint3d       maxPoint() const { return mMaxPoint; }
	CDraft::ErrorStatus set(const CRxGePoint3d& min, const CRxGePoint3d& max);

	void              addPoint (const CRxGePoint3d& pt);
	void              addExt   (const CRxDbExtents& src);
//	CDraft::ErrorStatus addBlockExt(CRxDbBlockTableRecord* pBTR);

	void expandBy(const CRxGeVector3d& vec);
	void transformBy(const CRxGeMatrix3d& mat);

private:
	CRxGePoint3d    mMinPoint;
	CRxGePoint3d    mMaxPoint;
};

CRX_DEFINE_CLSID(C4744859-3BCA-480c-9584-53E8CCC26457,CRxDbObject)
class CRXDB_CLASS CRxDbObject : public CRxGiDrawable
{
	CRX_DECLARE_DYNAMIC(CRxDbObject)

public:
	// Support Inner COM
	virtual CDraft::ErrorStatus saveData(CRxDbDatabase* i_pDataBase, IStream *i_pStm) { return CDraft::eNotImplementedYet; };
	virtual CDraft::ErrorStatus loadData(CRxDbDatabase* i_pDataBase, IStream *i_pStm) { return CDraft::eNotImplementedYet; };
	virtual CDraft::ErrorStatus updateData();
	virtual CDraft::ErrorStatus updateRelation(CRxDbDatabase* i_pDataBase, ULONG_PTR i_pMapID) { return CDraft::eNotImplementedYet; };

public:

//	// Associated Objects
//	//
	CRxDbObjectId      objectId() const;
	CRxDbObjectId      ownerId() const;
	virtual CDraft::ErrorStatus setOwnerId(CRxDbObjectId objId);
	void              getAcDbHandle(CRxDbHandle& handle) const;
	CRxDbDatabase*     database() const;
//	CDraft::ErrorStatus createExtensionDictionary();
//	CrxDbObjectId      extensionDictionary() const;
//	CDraft::ErrorStatus releaseExtensionDictionary();
//
//	// Open/Close/Cancel/Undo/Erase
//	//
	CDraft::ErrorStatus upgradeOpen();
//	CDraft::ErrorStatus upgradeFromNotify(CAXA::Boolean& wasWritable);
	CDraft::ErrorStatus downgradeOpen();
//	CDraft::ErrorStatus downgradeToNotify(CAXA::Boolean wasWritable);
//	virtual CDraft::ErrorStatus subOpen(CRxDb::OpenMode mode);
//
//	CDraft::ErrorStatus cancel();
//	virtual CDraft::ErrorStatus subCancel();
//
	CDraft::ErrorStatus close();
//	CDraft::ErrorStatus closeAndPage(CAXA::Boolean onlyWhenClean = true);
//	virtual CDraft::ErrorStatus subClose();
//
	CDraft::ErrorStatus erase(CAXA::Boolean erasing = true);
//	virtual CDraft::ErrorStatus subErase(CAXA::Boolean erasing);
//
//	CDraft::ErrorStatus handOverTo(CrxDbObject* newObject,
//		CAXA::Boolean keepXData = true,
//		CAXA::Boolean keepExtDict = true);
//	virtual CDraft::ErrorStatus subHandOverTo(CrxDbObject* newObject);
//
//	CDraft::ErrorStatus swapIdWith(CrxDbObjectId otherId, 
//		CAXA::Boolean swapXdata = false,
//		CAXA::Boolean swapExtDict = false);
//	virtual CDraft::ErrorStatus subSwapIdWith(CrxDbObjectId otherId,
//		CAXA::Boolean swapXdata = false,
//		CAXA::Boolean swapExtDict = false);
//
//	virtual CDraft::ErrorStatus swapReferences (const CRxDbIdMapping& idMap);
//
//	// Audit
//	//
//	virtual CDraft::ErrorStatus audit(CRxDbAuditInfo* pAuditInfo);
//
//	// Filing
//	//
//	CDraft::ErrorStatus         dwgIn       (CRxDbDwgFiler* pFiler);
//	virtual CDraft::ErrorStatus dwgInFields (CRxDbDwgFiler* pFiler);
//	CDraft::ErrorStatus         dwgOut      (CRxDbDwgFiler* pFiler) const;
//	virtual CDraft::ErrorStatus dwgOutFields(CRxDbDwgFiler* pFiler) const;
//
//	CDraft::ErrorStatus         dxfIn       (CRxDbDxfFiler* pFiler);
//	virtual CDraft::ErrorStatus dxfInFields (CRxDbDxfFiler* pFiler);
//	CDraft::ErrorStatus         dxfOut      (CRxDbDxfFiler* pFiler,
//		CAXA::Boolean allXdFlag,
//		CAXA::uchar* regAppTable) const;
//	virtual CDraft::ErrorStatus dxfOutFields(CRxDbDxfFiler* pFiler) const;
//
//	// Merge style for insert-style operations. Defaults to kDrcIgnore.
//	//
//	virtual CRxDb::DuplicateRecordCloning mergeStyle () const;
//
//	// XData
//	//
	virtual resbuf*           xData   (const CxCHAR* regappName = NULL) const;
 	virtual CDraft::ErrorStatus setXData(const resbuf* xdata);
 	CDraft::ErrorStatus xDataTransformBy(const CRxGeMatrix3d& xform);
//
//	// Binary chunks.  Note: the data args should be void *.  We'll
//	// change those in an upcoming release... 
//	//
//	CDraft::ErrorStatus         setBinaryData(const CxCHAR * key,
//		long         size,
//		const char * data);
//	CDraft::ErrorStatus         getBinaryData(const CxCHAR * key,
//		long &       size,
//		char *&      data) const;
//
//	// XObject
//	// Open/Notify/Undo/Modified State Predicates
//	//
//	CAXA::Boolean isEraseStatusToggled() const;
	CAXA::Boolean isErased() const;
	CAXA::Boolean isReadEnabled() const;
	CAXA::Boolean isWriteEnabled() const;
	CAXA::Boolean isNotifyEnabled() const;
	CAXA::Boolean isModified() const;
//	CAXA::Boolean isModifiedXData() const;
//	CAXA::Boolean isModifiedGraphics() const;
//	CAXA::Boolean isNewObject() const;
//	CAXA::Boolean isNotifying() const;
//	CAXA::Boolean isUndoing() const;
//	CAXA::Boolean isCancelling() const;
//	CAXA::Boolean isReallyClosing() const;
//	CAXA::Boolean isTransactionResident() const;
//
//	// Formerly isAZombie()
//	//
	CAXA::Boolean isAProxy() const;
//
//	// Access State Assertions
//	//
	void assertReadEnabled() const;
	void assertWriteEnabled(CAXA::Boolean autoUndo = true,
		CAXA::Boolean recordModified = true);
	void assertNotifyEnabled() const;
//
//	// Undo 
//	//
//	bool                      isUndoRecordingDisabled() const;
//	void                      disableUndoRecording(CAXA::Boolean disable);
//	CRxDbDwgFiler*             undoFiler();
//	virtual CDraft::ErrorStatus applyPartialUndo(CRxDbDwgFiler* undoFiler,
//		CrxRxClass*    classObj);
//
//	// Notification
// 	//
//	void                      addReactor(CrxDbObjectReactor* newObj) const;
//	void                      removeReactor(CrxDbObjectReactor* newObj) const;
//	virtual void              addPersistentReactor(CrxDbObjectId objId);
//	virtual CDraft::ErrorStatus removePersistentReactor(CrxDbObjectId objId);
//	bool                      hasPersistentReactor(CrxDbObjectId objId) const;
//	CRxDbVoidPtrArray*         reactors();
//	const CRxDbVoidPtrArray*   reactors() const;
//
//	virtual void              recvPropagateModify(const CrxDbObject* subObj);
//	virtual void              xmitPropagateModify() const;
//
//	virtual CDraft::ErrorStatus deepClone(CrxDbObject* pOwnerObject,
//		CrxDbObject*& pClonedObject,
//		CRxDbIdMapping& idMap,
//		CAXA::Boolean isPrimary = true) const;
//
// 	virtual CDraft::ErrorStatus wblockClone(CRxObject* pOwnerObject,
// 		CRxDbObject*& pClonedObject,
// 		CRxDbIdMapping& idMap,
// 		CAXA::Boolean isPrimary = true) const;
//
//	void              setAcDbObjectIdsInFlux();
//	CAXA::Boolean    isAcDbObjectIdsInFlux() const;
//
//	// Notification for persistent reactors.
//	//
//	virtual void cancelled       (const CrxDbObject* dbObj);
//	virtual void copied          (const CrxDbObject* dbObj,
//		const CrxDbObject* newObj);
//	virtual void erased          (const CrxDbObject* dbObj,
//		CAXA::Boolean pErasing = true);
//	virtual void goodbye         (const CrxDbObject* dbObj);
//	virtual void openedForModify (const CrxDbObject* dbObj);
//	virtual void modified        (const CrxDbObject* dbObj);
//	virtual void subObjModified  (const CrxDbObject* dbObj,
//		const CrxDbObject* subObj);
//	virtual void modifyUndone    (const CrxDbObject* dbObj);
//	virtual void modifiedXData   (const CrxDbObject* dbObj);
//	virtual void unappended      (const CrxDbObject* dbObj);
//	virtual void reappended      (const CrxDbObject* dbObj);
//	virtual void objectClosed    (const CrxDbObjectId objId);
//	virtual void modifiedGraphics(const CrxDbEntity* dbEnt);
//
//	// CrxRxObject Protocol
//	// Derived classes should not override these member implementations.
//	//
	virtual CRxObject*        clone() const;
	virtual CDraft::ErrorStatus  copyFrom(const CRxObject* pSrc);
//
//	// Save to previous versions.
//	//
//	bool       hasSaveVersionOverride();
//	void       setHasSaveVersionOverride(bool bSetIt);
//
//	virtual CDraft::ErrorStatus getObjectSaveVersion(const CRxDbDwgFiler* pFiler, 
//		CRxDb::CRxDbDwgVersion& ver,
//		CRxDb::MaintenanceReleaseVersion& maintVer);
//	virtual CDraft::ErrorStatus getObjectSaveVersion(const CRxDbDxfFiler* pFiler, 
//		CRxDb::CRxDbDwgVersion& ver,
//		CRxDb::MaintenanceReleaseVersion& maintVer);
//	CDraft::ErrorStatus getObjectBirthVersion(
//		CRxDb::CRxDbDwgVersion& ver,
//		CRxDb::MaintenanceReleaseVersion& maintVer);
//
//	// Saving as previous versions.
//	//
//	virtual CDraft::ErrorStatus   decomposeForSave(
//		CRxDb::CRxDbDwgVersion ver,
//		CrxDbObject*& replaceObj,
//		CrxDbObjectId& replaceId,
//		CAXA::Boolean& exchangeXData);
//
//	virtual CRxGiDrawable*       drawable();
//
//	// CRxGiDrawable interface
//	//
//	virtual CAXA::UInt32       setAttributes(CRxGiDrawableTraits* pTraits);
	virtual CAXA::Boolean      worldDraw(CRxGiWorldDraw* pWd);
//	virtual void                viewportDraw(CRxGiViewportDraw* pVd);
//	virtual CAXA::Boolean      isPersistent() const;
//	virtual CrxDbObjectId        id() const;
//	virtual void                setGsNode(CRxGsNode* pNode);
//	virtual CRxGsNode*           gsNode() const;
//
//
//	bool              hasFields(void) const;
//	CDraft::ErrorStatus getField(const CxCHAR* pszPropName, 
//		CrxDbObjectId& fieldId) const;
//	CDraft::ErrorStatus getField(const CxCHAR* pszPropName, CRxDbField*& pField,
//		CRxDb::OpenMode mode) const;
//
//	virtual CDraft::ErrorStatus setField(const CxCHAR* pszPropName, CRxDbField* pField,
//		CrxDbObjectId& fieldId);
//
//	virtual CDraft::ErrorStatus removeField(CrxDbObjectId fieldId);
//	virtual CDraft::ErrorStatus removeField(const CxCHAR* pszPropName, CrxDbObjectId& returnId);
//	virtual CDraft::ErrorStatus removeField(const CxCHAR* pszPropName);
//	CrxDbObjectId      getFieldDictionary(void) const;
//	CDraft::ErrorStatus getFieldDictionary(CrxDbDictionary*& pFieldDict, 
//		CRxDb::OpenMode mode) const;
//
//protected:
//	CrxDbObject();
private:
	friend class CRxDbSystemInternals;
};

/*------------------------------------------------------------------------------
// CrxDbEntity : ø…œ‘ æÕº‘™ª˘¿ÅE
**----------------------------------------------------------------------------*/
CRX_DEFINE_CLSID(12E466B0-48EB-40D6-B9FE-FF4F1CEC6B09,CRxDbEntity)
class CRXDB_CLASS CRxDbEntity : public CRxDbObject
{
	CRX_DECLARE_DYNAMIC(CRxDbEntity)

public:
	virtual void Draw(IUnknown *i_pGiDevice);

	public:
	
		virtual ~CRxDbEntity();
	
		CRxDbObjectId                blockId() const;
	
		CRxCmColor                   color() const;
		virtual CDraft::ErrorStatus   setColor(const CRxCmColor& color,
			CAXA::Boolean doSubents = true);
		CAXA::UInt16               colorIndex() const;
		virtual CDraft::ErrorStatus   setColorIndex(CAXA::UInt16 color,
			CAXA::Boolean doSubents = true);
		CRxCmEntityColor             entityColor() const;
	
	//	CRxCmTransparency            transparency() const;
	//	virtual CDraft::ErrorStatus   setTransparency(const CRxCmTransparency& trans,
	//		CAXA::Boolean doSubents = true);
	//
	//
	//	CxCHAR*                       plotStyleName() const;
	//	CRxDb::PlotStyleNameType     getPlotStyleNameId(CrxDbObjectId& id) const;
	//	virtual CDraft::ErrorStatus   setPlotStyleName(const CxCHAR* newName,
	//		CAXA::Boolean doSubents = true);
	//	virtual CDraft::ErrorStatus   setPlotStyleName(CRxDb::PlotStyleNameType,
	//		CrxDbObjectId newId = CrxDbObjectId::kNull,
	//		CAXA::Boolean doSubents = true);
	//
		CxCHAR*                       layer() const;
		CRxDbObjectId                layerId() const;
		virtual CDraft::ErrorStatus   setLayer(const CxCHAR* newVal,
			CAXA::Boolean doSubents = true,
			bool allowHiddenLayer = false);
		virtual CDraft::ErrorStatus   setLayer(CRxDbObjectId newVal,
			CAXA::Boolean doSubents = true,
			bool allowHiddenLayer = false);
	
		CxCHAR*                       linetype() const;
		CRxDbObjectId                linetypeId() const;
		virtual CDraft::ErrorStatus   setLinetype(const CxCHAR* newVal,CAXA::Boolean doSubents = true);
		virtual CDraft::ErrorStatus   setLinetype(CRxDbObjectId newVal,CAXA::Boolean doSubents = true);
	
	//	CxCHAR*                      material() const;
	//	CrxDbObjectId                materialId() const;
	//	virtual CDraft::ErrorStatus   setMaterial(const CxCHAR* newVal, CAXA::Boolean doSubents = true);
	//	virtual CDraft::ErrorStatus   setMaterial(CrxDbObjectId newVal, CAXA::Boolean doSubents = true);
	//
	//	virtual CDraft::ErrorStatus getMaterialMapper(CRxGiMapper& mapper) const;
	//	virtual CDraft::ErrorStatus setMaterialMapper(const CRxGiMapper& mapper, CAXA::Boolean doSubents = true);
	//
		double                      linetypeScale() const;
		virtual CDraft::ErrorStatus   setLinetypeScale(double newval,	CAXA::Boolean doSubents = true);

		CRxDb::Visibility            visibility() const;
		virtual CDraft::ErrorStatus   setVisibility(CRxDb::Visibility newVal,CAXA::Boolean doSubents = true);

		CRxDb::LineWeight            lineWeight() const;
		virtual CDraft::ErrorStatus   setLineWeight(CRxDb::LineWeight newVal,CAXA::Boolean doSubents = true);
	//
	//	virtual CRxDb::CollisionType collisionType() const;
	//
	//	virtual bool                castShadows() const;
	//	virtual void                setCastShadows(bool newVal);
	//	virtual bool                receiveShadows() const;
	//	virtual void                setReceiveShadows(bool newVal);
	//
		CDraft::ErrorStatus           setPropertiesFrom(const CRxDbEntity* pEntity,
			CAXA::Boolean doSubents = true);
	//
	//	virtual CAXA::Boolean      isPlanar() const { return false; }
	//	virtual CDraft::ErrorStatus   getPlane(CRxGePlane&, CRxDb::Planarity&) const
	//	{ return CDraft::eNotApplicable; }
	//
	//	virtual void                getEcs(CRxGeMatrix3d& retVal) const;
	//
		virtual CDraft::ErrorStatus   getGeomExtents(CRxDbExtents& extents) const;
	//
	//	// Subentity acquisition and manipulation
	//	//
	//	virtual  CDraft::ErrorStatus addSubentPaths(const CRxDbFullSubentPathArray& newPaths);
	//
	//	virtual  CDraft::ErrorStatus deleteSubentPaths(const CRxDbFullSubentPathArray& paths);
	//
	//	virtual  CDraft::ErrorStatus getSubentClassId(
	//		const CrxDbFullSubentPath& path,
	//		CLSID*                    clsId) const;
	//
	//	virtual  CDraft::ErrorStatus transformSubentPathsBy(
	//		const CRxDbFullSubentPathArray& paths,
	//		const CRxGeMatrix3d&            xform);
	//
	//	virtual  CDraft::ErrorStatus getGripPointsAtSubentPath(
	//		const CrxDbFullSubentPath&      path,
	//		CRxDbGripDataPtrArray&          grips,
	//		const double                   curViewUnitSize,
	//		const int                      gripSize,
	//		const CRxGeVector3d&            curViewDir,
	//		const int                      bitflags) const;
	//
	//	virtual  CDraft::ErrorStatus moveGripPointsAtSubentPaths(
	//		const CRxDbFullSubentPathArray& paths,
	//		const CRxDbVoidPtrArray&        gripAppData,
	//		const CRxGeVector3d&            offset,
	//		const int                      bitflags);
	//
	//	virtual  CDraft::ErrorStatus getSubentPathGeomExtents(
	//		const CrxDbFullSubentPath&      path, 
	//		CRxDbExtents&                   extents) const;   
	//
		virtual  CDraft::ErrorStatus getSubentPathsAtGsMarker(
			CRxDb::SubentType       type,
			CAXA::GsMarker        gsMark, 
			const CRxGePoint3d&     pickPoint,
			const CRxGeMatrix3d&    viewXform, 
			int&                   numPaths,
			CRxDbFullSubentPath*&   subentPaths, 
			int                    numInserts = 0,
			CRxDbObjectId*          entAndInsertStack
			= NULL) const;
	//
	//	virtual  CDraft::ErrorStatus getSubentPathsAtGsMarker(
	//		CRxDb::SubentType       type,
	//		CAXA::GsMarker        gsMark, 
	//		const CRxGePoint3d&     pickPoint,
	//		const CrxGeFastTransform&  viewXform, 
	//		int&                   numPaths,
	//		CrxDbFullSubentPath*&   subentPaths, 
	//		int                    numInserts = 0,
	//		CrxDbObjectId*          entAndInsertStack
	//		= NULL) const;
	//
	//	virtual  CDraft::ErrorStatus getGsMarkersAtSubentPath(
	//		const CrxDbFullSubentPath& subPath, 
	//		CRxArray<CAXA::GsMarker>& gsMarkers) const;
	//
		virtual CDraft::ErrorStatus highlight(const CRxDbFullSubentPath& subId = kNullSubent, const CAXA::Boolean highlightAll = false) const;
		virtual CDraft::ErrorStatus unhighlight(const CRxDbFullSubentPath& subId = kNullSubent, const CAXA::Boolean highlightAll = false) const;

		virtual CRxDbEntity*       subentPtr(const CRxDbFullSubentPath& id) const;
	
		virtual CDraft::ErrorStatus   getOsnapPoints(
			CRxDb::OsnapMode     osnapMode,
			CAXA::GsMarker     gsSelectionMark,
			const CRxGePoint3d&  pickPoint,
			const CRxGePoint3d&  lastPoint,
			const CRxGeMatrix3d& viewXform,
			CRxGePoint3dArray&   snapPoints,
			CRxDbIntArray &   geomIds) const;
	
		virtual CDraft::ErrorStatus   getOsnapPoints(
			CRxDb::OsnapMode     osnapMode,
			CAXA::GsMarker     gsSelectionMark,
			const CRxGePoint3d&  pickPoint,
			const CRxGePoint3d&  lastPoint,
			const CRxGeFastTransform& viewXform,
			CRxGePoint3dArray&   snapPoints,
			CRxDbIntArray &       geomIds) const;
	
		virtual CDraft::ErrorStatus   getOsnapPoints(
			CRxDb::OsnapMode     osnapMode,
			CAXA::GsMarker     gsSelectionMark,
			const CRxGePoint3d&  pickPoint,
			const CRxGePoint3d&  lastPoint,
			const CRxGeMatrix3d& viewXform,
			CRxGePoint3dArray&   snapPoints,
			CRxDbIntArray &   geomIds,
			const CRxGeMatrix3d& insertionMat) const;
	
		//virtual CDraft::ErrorStatus   getOsnapPoints(
		//	CRxDb::OsnapMode     osnapMode,
		//	CAXA::GsMarker     gsSelectionMark,
		//	const CRxGePoint3d&  pickPoint,
		//	const CRxGePoint3d&  lastPoint,
		//	const CrxGeFastTransform& viewXform,
		//	CrxGePoint3dArray&   snapPoints,
		//	CRxDbIntArray &   geomIds,
		//	const CRxGeMatrix3d& insertionMat) const;
	
		virtual CDraft::ErrorStatus   getGripPoints(
			CRxGePoint3dArray&  gripPoints,
			CRxDbIntArray &     osnapModes,
			CRxDbIntArray &  geomIds) const;
	
		virtual  CDraft::ErrorStatus moveGripPointsAt(const CRxDbIntArray & indices,
			const CRxGeVector3d& offset);
	
		virtual CDraft::ErrorStatus   getGripPoints(CRxDbGripDataPtrArray& grips,
			const double curViewUnitSize, const int gripSize, 
			const CRxGeVector3d& curViewDir, const int bitflags) const;
	
		virtual  CDraft::ErrorStatus moveGripPointsAt(const CRxDbVoidPtrArray& gripAppData,
			const CRxGeVector3d& offset, const int bitflags);
	
		virtual CDraft::ErrorStatus getStretchPoints(
			CRxGePoint3dArray& stretchPoints) const;
		virtual CDraft::ErrorStatus moveStretchPointsAt(const CRxDbIntArray & indices,
			const CRxGeVector3d& offset);
	//
		virtual  CDraft::ErrorStatus intersectWith(const CRxDbEntity* pEnt,
			CRxDb::Intersect intType, 
			CRxGePoint3dArray& points,
			CAXA::GsMarker thisGsMarker = 0, 
			CAXA::GsMarker otherGsMarker = 0) const;
	//
	//	virtual  CDraft::ErrorStatus intersectWith(const CrxDbEntity* pEnt,
	//		CRxDb::Intersect intType, 
	//		const CRxGePlane& projPlane,
	//		CrxGePoint3dArray& points, 
	//		CAXA::GsMarker thisGsMarker = 0,
	//		CAXA::GsMarker otherGsMarker = 0) const;
	//
	//	CDraft::ErrorStatus          boundingBoxIntersectWith(
	//		const CrxDbEntity*   pEnt,
	//		CRxDb::Intersect     intType,
	//		CrxGePoint3dArray&   points,
	//		CAXA::GsMarker     thisGsMarker,
	//		CAXA::GsMarker     otherGsMarker) const;
	//
	//	CDraft::ErrorStatus          boundingBoxIntersectWith(
	//		const CrxDbEntity*   pEnt,
	//		CRxDb::Intersect     intType,
	//		const CRxGePlane&    projPlane,
	//		CrxGePoint3dArray&   points,
	//		CAXA::GsMarker     thisGsMarker,
	//		CAXA::GsMarker     otherGsMarker) const;
	//
		virtual void                list() const;
	
		virtual CDraft::ErrorStatus   transformBy(const CRxGeMatrix3d& xform);
		//virtual CDraft::ErrorStatus   transformBy(const CrxGeFastTransform& xform);
		virtual CDraft::ErrorStatus   getTransformedCopy(const CRxGeMatrix3d& xform, CRxDbEntity*& pEnt) const;
		virtual CDraft::ErrorStatus   explode(CRxDbVoidPtrArray& entitySet) const;
	//
	//	void                        recordGraphicsModified(CAXA::Boolean setModified = true);
	//
		CDraft::ErrorStatus           draw();
	//	virtual CAXA::Boolean      worldDraw(CRxGiWorldDraw*        mode);
	//	virtual void                viewportDraw(CRxGiViewportDraw*  mode);
	//	virtual void                saveAs(CRxGiWorldDraw* mode, CRxDb::SaveType st);
	//
	//	virtual CDraft::ErrorStatus   getCompoundObjectTransform(CRxGeMatrix3d & xMat) const;
	//
		void                        setDatabaseDefaults();
		void                        setDatabaseDefaults(CRxDbDatabase* pDb);
	//	virtual void                subSetDatabaseDefaults(CrxDbDatabase* pDb);
	//
	//	virtual CDraft::ErrorStatus   applyPartialUndo(CRxDbDwgFiler* undoFiler, CrxRxClass*    classObj);
	//
	//	virtual CDraft::ErrorStatus   audit(CRxDbAuditInfo* pAuditInfo);
	//
	//	virtual CDraft::ErrorStatus   dwgInFields(CRxDbDwgFiler* pFiler);
	//	virtual CDraft::ErrorStatus   dwgOutFields(CRxDbDwgFiler* pFiler) const;
	//
	//	virtual CDraft::ErrorStatus   dxfInFields(CRxDbDxfFiler* pFiler);
	//	virtual CDraft::ErrorStatus   dxfOutFields(CRxDbDxfFiler* pFiler) const;
	//
	//	virtual CRxGiDrawable*       drawable();
	//
	//	// CRxGiDrawable interface
	//	//
	//	virtual CAXA::UInt32       setAttributes(CRxGiDrawableTraits* pTraits);
	//	virtual void                setGsNode(CRxGsNode* pNode);
	//	virtual CRxGsNode*           gsNode() const;
	//
	//	virtual CAXA::Boolean      cloneMeForDragging();
	//	virtual bool                hideMeForDragging() const;
	//
	//	virtual void                dragStatus(const CRxDb::DragStat status);
	//	virtual void                gripStatus(const CRxDb::GripStat status);
	//	virtual void                subentGripStatus(const CRxDb::GripStat status, const CrxDbFullSubentPath& subentity);
	//
	//	// Get corresponding COM wrapper class ID
	//	//
	//	virtual CDraft::ErrorStatus   getClassID(CLSID* pClsid) const;
	//
	//	virtual CDraft::ErrorStatus getGripEntityUCS(const void* pGripAppData, CRxGeVector3d& normalVec, CRxGePoint3d& origin, CRxGeVector3d& xAxis) const;
	//
	//protected:
	//	// Makes CrxDbEntity an abstract class.
	//	CrxDbEntity();
};

CRX_DEFINE_CLSID(7AF8CE77-95C1-4ADB-9A94-9FEBF81F2459, CRxDbDatabase)
class CRXDB_API CRxDbDatabase: public CRxObject//, public CRxHeapOperators
{
public:
	CRX_DECLARE_DYNCREATE(CRxDbDatabase);

	// constructor & destructor
	CRxDbDatabase(ICxCrxObject *i_pCrxObject = NULL);
	CRxDbDatabase(bool buildDefaultDrawing , bool noDocument = false);
	virtual ~CRxDbDatabase();
//
//	// Add objects (but not entities) to database
//
	CDraft::ErrorStatus addAcDbObject(CRxDbObject*    pObj);
	CDraft::ErrorStatus addAcDbObject(CRxDbObjectId&  objId,
		CRxDbObject*    pObj);
//
//	static CDraft::ErrorStatus markObjectNonPersistent(CrxDbObjectId id, bool value);
//	static bool isObjectNonPersistent(CrxDbObjectId id);
//	// Symbol Tables
//
	CDraft::ErrorStatus getBlockTable     (CRxDbSymbolTable*& pTable,
										 CRxDb::OpenMode    mode);
	CDraft::ErrorStatus getLayerTable     (CRxDbSymbolTable*& pTable,
		CRxDb::OpenMode    mode);
	CDraft::ErrorStatus getTextStyleTable (CRxDbSymbolTable*& pTable,
		CRxDb::OpenMode    mode);
	CDraft::ErrorStatus getLinetypeTable  (CRxDbSymbolTable*& pTable,
		CRxDb::OpenMode    mode);
//	CDraft::ErrorStatus getViewTable      (CrxDbSymbolTable*& pTable,
//		CRxDb::OpenMode    mode);
	CDraft::ErrorStatus getUCSTable       (CRxDbSymbolTable*& pTable,
		CRxDb::OpenMode    mode);
//	CDraft::ErrorStatus getViewportTable  (CrxDbSymbolTable*& pTable,
//		CRxDb::OpenMode    mode);
	CDraft::ErrorStatus getRegAppTable    (CRxDbSymbolTable*& pTable,
		CRxDb::OpenMode    mode);
	CDraft::ErrorStatus getDimStyleTable  (CRxDbSymbolTable*& pTable,
		CRxDb::OpenMode    mode);
//
	CDraft::ErrorStatus getSymbolTable    (CRxDbBlockTable*&     pTable,
		CRxDb::OpenMode       mode);
	CDraft::ErrorStatus getSymbolTable    (CRxDbLayerTable*&     pTable,
		CRxDb::OpenMode       mode);
	CDraft::ErrorStatus getSymbolTable    (CRxDbTextStyleTable*& pTable,
		CRxDb::OpenMode       mode);
	CDraft::ErrorStatus getSymbolTable    (CRxDbLinetypeTable*&  pTable,
		CRxDb::OpenMode       mode);
//	CDraft::ErrorStatus getSymbolTable    (CRxDbViewTable*&      pTable,
//		CRxDb::OpenMode       mode);
	CDraft::ErrorStatus getSymbolTable    (CRxDbUCSTable*&       pTable,
		CRxDb::OpenMode       mode);
//	CDraft::ErrorStatus getSymbolTable    (CRxDbViewportTable*&  pTable,
//		CRxDb::OpenMode       mode);
	CDraft::ErrorStatus getSymbolTable    (CRxDbRegAppTable*&    pTable,
		CRxDb::OpenMode       mode);
	CDraft::ErrorStatus getSymbolTable    (CRxDbDimStyleTable*&  pTable,
		CRxDb::OpenMode       mode);
	CDraft::ErrorStatus getSymbolTable    (CRxDbPaperTable*&     pTable,
		CRxDb::OpenMode       mode);
//
//	CDraft::ErrorStatus getGroupDictionary   (CrxDbDictionary*& pDict,
//		CRxDb::OpenMode mode);
//	CDraft::ErrorStatus getMLStyleDictionary (CrxDbDictionary*& pDict,
//		CRxDb::OpenMode mode);
//	CDraft::ErrorStatus getLayoutDictionary  (CrxDbDictionary*& pDict,
//		CRxDb::OpenMode mode);
//	CDraft::ErrorStatus getPlotStyleNameDictionary(
//		CRxDbDictionaryWithDefault*& pDict,
//		CRxDb::OpenMode mode);
//	CDraft::ErrorStatus getMaterialDictionary(CrxDbDictionary*& pDict,
//		CRxDb::OpenMode mode);
//	CDraft::ErrorStatus getVisualStyleDictionary(CrxDbDictionary*& pDict,
//		CRxDb::OpenMode mode);
//	CDraft::ErrorStatus getColorDictionary   (CrxDbDictionary*& pDict,
//		CRxDb::OpenMode mode);
//	CDraft::ErrorStatus getScaleListDictionary(CrxDbDictionary*& pDict,
//		CRxDb::OpenMode mode);
	CDraft::ErrorStatus getNamedObjectsDictionary(
		CRxDbDictionary*& pDict,
		CRxDb::OpenMode mode);
//
//	// The following getXXXTable(CRxDbXXXTable*& ...) functions exist
//	// for backwards compatibility and may be removed in future
//	// releases.
	CDraft::ErrorStatus getBlockTable     (CRxDbBlockTable*& pTable,
		CRxDb::OpenMode    mode);
	CDraft::ErrorStatus getLayerTable     (CRxDbLayerTable*& pTable,
		CRxDb::OpenMode    mode);
	CDraft::ErrorStatus getTextStyleTable (CRxDbTextStyleTable*& pTable,
		CRxDb::OpenMode    mode);
	CDraft::ErrorStatus getLinetypeTable  (CRxDbLinetypeTable*& pTable,
		CRxDb::OpenMode    mode);
//	CDraft::ErrorStatus getViewTable      (CRxDbViewTable*& pTable,
//		CRxDb::OpenMode    mode);
	CDraft::ErrorStatus getUCSTable       (CRxDbUCSTable*& pTable,
		CRxDb::OpenMode    mode);
//	CDraft::ErrorStatus getViewportTable  (CRxDbViewportTable*& pTable,
//		CRxDb::OpenMode    mode);
	CDraft::ErrorStatus getRegAppTable    (CRxDbRegAppTable*& pTable,
		CRxDb::OpenMode    mode);
	CDraft::ErrorStatus getDimStyleTable  (CRxDbDimStyleTable*& pTable,
		CRxDb::OpenMode    mode);
//	CDraft::ErrorStatus getPlotSettingsDictionary(CrxDbDictionary*& pTable,
//		CRxDb::OpenMode    mode);
//	CrxDbObjectId      getSectionManager (void) const;
//	CDraft::ErrorStatus getSectionManager (CRxDbSectionManager*& pMgr, 
//		CRxDb::OpenMode mode) const;
//	CrxDbObjectId    dataLinkDictionaryId(void) const;
//	CDraft::ErrorStatus getDataLinkDictionary(CrxDbDictionary*& pDict, 
//		CRxDb::OpenMode mode);
//	CRxDbDataLinkManager*getDataLinkManager(void) const;
//	CDraft::ErrorStatus updateDataLink    (CRxDb::UpdateDirection nDir, 
//		CRxDb::UpdateOption nOption);
//
//	// Todo: change all these xxxTableId() and xxxDictionaryId()
//	// methods to const.
//	//
	CRxDbObjectId  blockTableId();
	CRxDbObjectId  layerTableId();
	CRxDbObjectId  textStyleTableId();
	CRxDbObjectId  linetypeTableId();
//	CrxDbObjectId  viewTableId();
	CRxDbObjectId  UCSTableId();
//	CrxDbObjectId  viewportTableId();
	CRxDbObjectId  regAppTableId();
	CRxDbObjectId  dimStyleTableId();
//	CrxDbObjectId  mLStyleDictionaryId();
//	CrxDbObjectId  groupDictionaryId();
//	CrxDbObjectId  layoutDictionaryId();
//	CrxDbObjectId  plotStyleNameDictionaryId();
//	CrxDbObjectId  materialDictionaryId();
//	CrxDbObjectId  visualStyleDictionaryId();
//	CrxDbObjectId  colorDictionaryId();
//	CrxDbObjectId  scaleListDictionaryId();
	CRxDbObjectId  namedObjectsDictionaryId();
//	CrxDbObjectId  plotSettingsDictionaryId();
//
	CRxDbObjectId layerZero() const;
	CRxDbObjectId continuousLinetype() const;
	CRxDbObjectId byLayerLinetype() const;
	CRxDbObjectId byBlockLinetype() const;
//
//	CrxDbObjectId globalMaterial() const;
//	CrxDbObjectId byLayerMaterial() const;
//	CrxDbObjectId byBlockMaterial() const;
//
//	CrxDbObjectId paperSpaceVportId() const;
	CRxDbObjectId currentSpaceId() const;
//
//	CDraft::ErrorStatus reclaimMemoryFromErasedObjects(const CRxDbObjectIdArray& erasedObjects);
//
//	// Traverse the db and remove non-purgeable ids from the array
//	CDraft::ErrorStatus purge(CRxDbObjectIdArray& ids);
//	CDraft::ErrorStatus purge(CRxDbObjectIdGraph& idGraph);
//	CDraft::ErrorStatus countHardReferences(const CRxDbObjectIdArray& ids,
//		CAXA::UInt32* pCount);	
//
	// Exchange (handle, xrefId) or name for CrxDbObjectId 
	//
	CDraft::ErrorStatus getAcDbObjectId(CRxDbObjectId& retId,
		bool createIfNotFound,
		const CRxDbHandle& objHandle,
		CAXA::UInt32 xRefId = 0);
//	// Class Dxf Name for this database.
//	//
//	const CxCHAR* classDxfName(const CrxRxClass* pClass);
//
//	bool hasClass(const CrxRxClass* pClass) const;
//
//	// Filing Operations
//	//
//	enum OpenMode {
//		kForReadAndReadShare =    1,  // open for read and allow read sharing (_SH_DENYWR)
//		kForReadAndWriteNoShare = 2,  // open for read/write and allow no sharing (_SH_DENYRW)
//		kForReadAndAllShare =     3,  // open for read and allow read and write sharing (_SH_DENYNO)
//		kTryForReadShare =        4   // try kForReadAndReadShare, and if that fails,
//		// then try kForReadAndAllShare 
//	};
//	CDraft::ErrorStatus readDwgFile(const CxCHAR* fileName,
//		OpenMode shmode,
//		bool bAllowCPConversion = false,
//		const wchar_t* wszPassword = NULL);
	CDraft::ErrorStatus readExbFile(const CxCHAR* fileName,
		const int shmode = _SH_DENYWR,
		bool bAllowCPConversion = false,
		const wchar_t* wszPassword = NULL);
	CDraft::ErrorStatus readDwgFile(const CxCHAR* fileName,
		const int shmode = _SH_DENYWR,
		bool bAllowCPConversion = false,
		const wchar_t* wszPassword = NULL);
//	CDraft::ErrorStatus readDwgFile(CRxDwgFileHandle *pDwgFile,
//		bool bAllowCPConversion = false,
//		const wchar_t* wszPassword = NULL);
	CDraft::ErrorStatus saveAs(const CxCHAR* fileName,
		const SecurityParams* pSecParams = 0);

	CDraft::ErrorStatus saveAs(const CxCHAR* fileName,
		const bool bBakAndRename,
		const CRxDb::CRxDbExbVersion dwgVer = CRxDb::kEXB_CURRENT,
		const SecurityParams* pSecParams = 0);

	CDraft::ErrorStatus saveAs(const CxCHAR* fileName,
		const bool bBakAndRename,
		const CRxDb::CRxDbDwgVersion dwgVer = CRxDb::kDHL_CURRENT,
		const SecurityParams* pSecParams = 0);
//
//	CDraft::ErrorStatus saveAs(CRxDwgFileHandle * pOutputFiler,
//		const SecurityParams* pSecParams = 0,
//		bool crashing = false);
//	CDraft::ErrorStatus save();
//	CDraft::ErrorStatus dxfIn(const CxCHAR* dxfFilename,
//		const CxCHAR* logFilename=NULL);
//	CDraft::ErrorStatus dxfOut(const CxCHAR* fileName,
//		const int precision = 16,
//		const bool saveThumbnailImage = false);
//
//	CDraft::ErrorStatus closeInput(bool bCloseFile = false);
//
//	int approxNumObjects() const;
//	CAXA::Int32 numberOfSaves() const;
//	const CxCHAR * originalFileName() const;
//	CRxDb::CRxDbDwgVersion lastSavedAsVersion() const;
//	CRxDb::CRxDbDwgVersion originalFileVersion() const;
//	CRxDb::CRxDbDwgVersion originalFileSavedByVersion() const;
//	CRxDb::MaintenanceReleaseVersion lastSavedAsMaintenanceVersion() const;
//	CRxDb::MaintenanceReleaseVersion originalFileMaintenanceVersion() const;
//	CRxDb::MaintenanceReleaseVersion originalFileSavedByMaintenanceVersion() const;
//
//	CRxDwgFileHandle * inputFiler() const;
//
//	CDraft::ErrorStatus wblock(CrxDbDatabase*& pOutputDb,
//		const CRxDbObjectIdArray& outObjIds,
//		const CRxGePoint3d& basePoint);
//
//	CDraft::ErrorStatus wblock(CrxDbDatabase* pOutputDb,  // pre-existing (template) db
//		const CRxDbObjectIdArray& outObjIds,
//		const CRxGePoint3d& basePoint,
//		CRxDb::DuplicateRecordCloning drc);  // kDrcIgnore
//
//	CDraft::ErrorStatus wblock(CrxDbDatabase*& pOutputDb, CrxDbObjectId blockId);
//	CDraft::ErrorStatus wblock(CrxDbDatabase*& pOutputDb);
//
//	// This will force the current WBLOCK* operation to result in
//	// a database copy.  Only use this method if your application
//	// does some special handling during WBLOCK* notifications and
//	// you can only do that correctly if the WBLOCK* results in a
//	// database copy.  Needless to say, a database copy will slow
//	// down WBLOCK* and increase memory requirements.
//	//
//	void              forceWblockDatabaseCopy();
//
//	// If preserveSourceDatabase is true, the contents of pDb will not
//	// be changed.  If it is false, objects from pDb could be physically
//	// moved into the database on which insert() is called.  The latter
//	// is much faster.  But pDb will be left in a state where it depends
//	// on "this" database (the one on which insert() was called) for vital
//	// data.  So pDb should be deleted before "this" database is deleted.
//	//
	CDraft::ErrorStatus insert(CRxDbObjectId& blockId, const CxCHAR* pBlockName,
		CRxDbDatabase* pDb,
		bool preserveSourceDatabase = true);
//
//	CDraft::ErrorStatus insert(const CRxGeMatrix3d& xform, CrxDbDatabase* pDb,
//		bool preserveSourceDatabase = true);
//
	CDraft::ErrorStatus insert(CRxDbObjectId& blockId, 
		const CxCHAR* pSourceBlockName,
		const CxCHAR* pDestinationBlockName,
		CRxDbDatabase* pDb,
		bool preserveSourceDatabase = true);
//
//	CDraft::ErrorStatus deepCloneObjects(CRxDbObjectIdArray& objectIds,
//		CrxDbObjectId& owner, CRxDbIdMapping& idMap,
//		bool deferXlation = false);
//
	CDraft::ErrorStatus wblockCloneObjects(CRxDbObjectIdArray& objectIds,
		CRxDbObjectId& owner, CRxDbIdMapping& idMap,
		CRxDb::DuplicateRecordCloning drc,
		bool deferXlation = false);
//
//	void              abortDeepClone(CRxDbIdMapping& idMap);
//
	void              addReactor(CRxDbDatabaseReactor* pReactor) const;
	void              removeReactor(CRxDbDatabaseReactor* pReactor) const;
//
//	CDraft::ErrorStatus audit(CRxDbAuditInfo* pInfo);
//	CDraft::ErrorStatus auditXData(CRxDbAuditInfo* pInfo);
//
//	CRxDbUndoController* undoController() const;
//	void              disableUndoRecording(bool disable);
//	bool              undoRecording() const ;
//
//	CRxDbTransactionManager* transactionManager() const;
//
//	CRxFileDependencyManager* fileDependencyManager() const;
//
//	CAXA::UInt8      maintenanceReleaseVersion() const;
//
//	CDraft::ErrorStatus restoreOriginalXrefSymbols();
//	CDraft::ErrorStatus restoreForwardingXrefSymbols();
//
//	CrxDbObjectId      xrefBlockId() const;
//
//	// Access to ThumbnailImage (preview)
//	// These functions take a windows BITMAPINFO*
//	//
//	void*             thumbnailBitmap() const;
//	CDraft::ErrorStatus setThumbnailBitmap(void* pBmp);
//	bool              retainOriginalThumbnailBitmap() const;
//	void              setRetainOriginalThumbnailBitmap(bool retain);
//	bool              isEMR() const;
//
//	// methods to set and retrieve security-related information
//	bool                  setSecurityParams(const SecurityParams* pSecParams,
//		bool bSetDbMod = true);
//	const SecurityParams* cloneSecurityParams();
//	static void           disposeSecurityParams(const SecurityParams* pSecParams);
//
//	// Header variables exposed via DXF and/or SETVAR
//	//
//	bool dimaso() const;
//	CDraft::ErrorStatus setDimaso(bool aso);
//
//	bool dimsho() const;
//	CDraft::ErrorStatus setDimsho(bool sho);
//
//	bool plinegen() const;
//	CDraft::ErrorStatus setPlinegen(bool gen);
//
	bool orthomode() const;
	CDraft::ErrorStatus setOrthomode(bool mode);
//
//	bool regenmode() const;
//	CDraft::ErrorStatus setRegenmode(bool mode);
//
//	bool fillmode() const;
//	CDraft::ErrorStatus setFillmode(bool mode);
//
//	bool qtextmode() const;
//	CDraft::ErrorStatus setQtextmode(bool mode);
//
//	bool psltscale() const;
//	CDraft::ErrorStatus setPsltscale(bool scale);
//
//	bool limcheck() const;
//	CDraft::ErrorStatus setLimcheck(bool check);
//
//	bool blipmode() const;
//	CDraft::ErrorStatus setBlipmode(bool mode);
//
//	CAXA::Int16 saveproxygraphics() const;
//	CDraft::ErrorStatus setSaveproxygraphics(CAXA::Int16 saveimg);
//
//	CAXA::Int16 delUsedObj() const;
//	CDraft::ErrorStatus setDelUsedObj(CAXA::Int16 deleteObj);
//
//	bool dispSilh() const;
//	CDraft::ErrorStatus setDispSilh(bool silh);
//
//	bool plineEllipse() const;
//	CDraft::ErrorStatus setPlineEllipse(bool pline);
//
//	bool usrtimer() const;
//	CDraft::ErrorStatus setUsrtimer(bool timer);
//
//	bool skpoly() const;
//	CDraft::ErrorStatus setSkpoly(bool asPoly);
//
//	bool angdir() const;
//	CDraft::ErrorStatus setAngdir(bool dir);
//
//	bool splframe() const;
//	CDraft::ErrorStatus setSplframe(bool disp);
//
//	bool xclipFrame() const;
//	CDraft::ErrorStatus setXclipFrame(bool disp);
//
//	bool attreq() const;
//	CDraft::ErrorStatus setAttreq(bool req);
//
//	bool attdia() const;
//	CDraft::ErrorStatus setAttdia(bool dia);
//
//	bool mirrtext() const;
//	CDraft::ErrorStatus setMirrtext(bool mirror);
//
//	bool worldview() const;
//	CDraft::ErrorStatus setWorldview(bool view);
//
//	bool tilemode() const;
//	CDraft::ErrorStatus setTilemode(bool mode);
//
//	bool plimcheck() const;
//	CDraft::ErrorStatus setPlimcheck(bool check);
//
//	bool visretain() const;
//	CDraft::ErrorStatus setVisretain(bool retain);
//
//	CAXA::Int16 dragmode() const;
//	CDraft::ErrorStatus setDragmode(CAXA::Int16 mode);
//
//	CAXA::Int16 treedepth() const;
//	CDraft::ErrorStatus setTreedepth(CAXA::Int16 depth);
//
//	CAXA::Int16 lunits() const;
//	CDraft::ErrorStatus setLunits(CAXA::Int16 lunits);
//
//	CAXA::Int16 luprec() const;
//	CDraft::ErrorStatus setLuprec(CAXA::Int16 prec);
//
//	CAXA::Int16 aunits() const;
//	CDraft::ErrorStatus setAunits(CAXA::Int16 aunits);
//
//	CAXA::Int16 auprec() const;
//	CDraft::ErrorStatus setAuprec(CAXA::Int16 auprec);
//
//	CAXA::Int16 attmode() const;
//	CDraft::ErrorStatus setAttmode(CAXA::Int16 mode);
//
//	CAXA::Int16 coords() const;
//	CDraft::ErrorStatus setCoords(CAXA::Int16 coords);
//
//	CAXA::Int16 pdmode() const;
//	CDraft::ErrorStatus setPdmode(CAXA::Int16 mode);
//
//	CAXA::Int16 pickstyle() const;
//	CDraft::ErrorStatus setPickstyle(CAXA::Int16 style);
//
//	CAXA::Int16 useri1() const;
//	CDraft::ErrorStatus setUseri1(CAXA::Int16 val);
//
//	CAXA::Int16 useri2() const;
//	CDraft::ErrorStatus setUseri2(CAXA::Int16 val);
//
//	CAXA::Int16 useri3() const;
//	CDraft::ErrorStatus setUseri3(CAXA::Int16 val);
//
//	CAXA::Int16 useri4() const;
//	CDraft::ErrorStatus setUseri4(CAXA::Int16 val);
//
//	CAXA::Int16 useri5() const;
//	CDraft::ErrorStatus setUseri5(CAXA::Int16 val);
//
//	CAXA::Int16 splinesegs() const;
//	CDraft::ErrorStatus setSplinesegs(CAXA::Int16 segs);
//
//	CAXA::Int16 surfu() const;
//	CDraft::ErrorStatus setSurfu(CAXA::Int16 u);
//
//	CAXA::Int16 surfv() const;
//	CDraft::ErrorStatus setSurfv(CAXA::Int16 v);
//
//	CAXA::Int16 surftype() const;
//	CDraft::ErrorStatus setSurftype(CAXA::Int16 type);
//
//	CAXA::Int16 surftab1() const;
//	CDraft::ErrorStatus setSurftab1(CAXA::Int16 tab1);
//
//	CAXA::Int16 surftab2() const;
//	CDraft::ErrorStatus setSurftab2(CAXA::Int16 tab2);
//
//	CAXA::Int16 splinetype() const;
//	CDraft::ErrorStatus setSplinetype(CAXA::Int16 type);
//
//	CAXA::Int16 shadedge() const;
//	CDraft::ErrorStatus setShadedge(CAXA::Int16 mode);
//
//	CAXA::Int16 shadedif() const;
//	CDraft::ErrorStatus setShadedif(CAXA::Int16 dif);
//
//	CRxDb::MeasurementValue measurement() const;
//	CDraft::ErrorStatus setMeasurement(CRxDb::MeasurementValue type);
//
//	CAXA::Int16 unitmode() const;
//	CDraft::ErrorStatus setUnitmode(CAXA::Int16 mode);
//
//	CAXA::Int16 maxactvp() const;
//	CDraft::ErrorStatus setMaxactvp(CAXA::Int16 max);
//
//	CAXA::Int16 isolines() const;
//	CDraft::ErrorStatus setIsolines(CAXA::Int16 isolines);
//
//	CAXA::UInt8 dwfframe() const;
//	CDraft::ErrorStatus setDwfframe(CAXA::UInt8);
//
//	CAXA::UInt8 dgnframe() const;
//	CDraft::ErrorStatus setDgnframe(CAXA::UInt8);
//
//	double ltscale() const;
//	CDraft::ErrorStatus setLtscale(double scale);
//
//	double textsize() const;
//	CDraft::ErrorStatus setTextsize(double size);
//
//	double tracewid() const;
//	CDraft::ErrorStatus setTracewid(double width);
//
//	double sketchinc() const;
//	CDraft::ErrorStatus setSketchinc(double inc);
//
//	double filletrad() const;
//	CDraft::ErrorStatus setFilletrad(double radius);
//
//	double thickness() const;
//	CDraft::ErrorStatus setThickness(double thickness);

	CRxDb::LineWeight  celweight() const;
	CDraft::ErrorStatus setCelweight(CRxDb::LineWeight weight);

//	static bool       isValidLineWeight(int weight);
//	static CRxDb::LineWeight getNearestLineWeight(int weight);
//
//	CRxDb::EndCaps endCaps() const;
//	CDraft::ErrorStatus setEndCaps(CRxDb::EndCaps type);
//
//	CRxDb::JoinStyle joinStyle() const;
//	CDraft::ErrorStatus setJoinStyle(CRxDb::JoinStyle style);
//
//	bool lineWeightDisplay() const;
//	CDraft::ErrorStatus setLineWeightDisplay(bool display);
//
//	bool xrefEditEnabled() const;
//	CDraft::ErrorStatus setXrefEditEnabled(bool enable);
//
//	bool oleStartUp() const;
//	CDraft::ErrorStatus setOleStartUp(bool val);
//
//	double angbase() const;
//	CDraft::ErrorStatus setAngbase(double angle);
//
//	double pdsize() const;
//	CDraft::ErrorStatus setPdsize(double size);
//
//	double plinewid() const;
//	CDraft::ErrorStatus setPlinewid(double width);
//
//	double userr1() const;
//	CDraft::ErrorStatus setUserr1(double val);
//
//	double userr2() const;
//	CDraft::ErrorStatus setUserr2(double val);
//
//	double userr3() const;
//	CDraft::ErrorStatus setUserr3(double val);
//
//	double userr4() const;
//	CDraft::ErrorStatus setUserr4(double val);
//
//	double userr5() const;
//	CDraft::ErrorStatus setUserr5(double val);
//
//	double chamfera() const;
//	CDraft::ErrorStatus setChamfera(double val);
//
//	double chamferb() const;
//	CDraft::ErrorStatus setChamferb(double val);
//
//	double chamferc() const;
//	CDraft::ErrorStatus setChamferc(double val);
//
//	double chamferd() const;
//	CDraft::ErrorStatus setChamferd(double val);
//
//	double facetres() const;
//	CDraft::ErrorStatus setFacetres(double facetres);
//
//	// 3DDWF
//	double get3dDwfPrec() const;
//	CDraft::ErrorStatus set3dDwfPrec(double DwfPrec);
//
//	CDraft::ErrorStatus getMenu(CxCHAR*& pOutput) const;
//
//	bool hpInherit() const;
//	CDraft::ErrorStatus setHpInherit(const bool inherit);
//
//	CRxGePoint2d hpOrigin() const;
//	CDraft::ErrorStatus setHpOrigin(const CRxGePoint2d& origin);
//
//	const CRxDbDate tdcreate() const;     // returns a local time
//	const CRxDbDate tdupdate() const;
//
//	const CRxDbDate tducreate() const;    // returns a universal time
//	const CRxDbDate tduupdate() const;
//
//	const CRxDbDate tdindwg() const;      // returns a time delta
//	const CRxDbDate tdusrtimer() const;

	CRxCmColor cecolor() const;
	CDraft::ErrorStatus setCecolor(const CRxCmColor& color);

//	CRxDbHandle handseed() const;
//	CDraft::ErrorStatus setHandseed(const CRxDbHandle& handle);
//
	CRxDbObjectId clayer() const;
	CDraft::ErrorStatus setClayer(CRxDbObjectId objId);
//
//	CRxDb::PlotStyleNameType getCePlotStyleNameId(CrxDbObjectId& id) const;
//	CDraft::ErrorStatus       setCePlotStyleName(CRxDb::PlotStyleNameType,
//		CrxDbObjectId newId = CrxDbObjectId::kNull);
//
	CRxDbObjectId textstyle() const;
	CDraft::ErrorStatus setTextstyle(CRxDbObjectId objId);
//
	CRxDbObjectId celtype() const;
	CDraft::ErrorStatus setCeltype(CRxDbObjectId objId);
//
//	CrxDbObjectId cmaterial() const;
//	CDraft::ErrorStatus setCmaterial(CrxDbObjectId objId);
//
	CRxDbObjectId dimstyle() const;
	CDraft::ErrorStatus setDimstyle(CRxDbObjectId styleId);
//
//	CDraft::ErrorStatus getDimstyleData(CrxDbDimStyleTableRecord*& pRec) const;
//	CDraft::ErrorStatus getDimstyleChildData(const CrxRxClass *pDimClass,
//		CrxDbDimStyleTableRecord*& pRec,
//		CrxDbObjectId &style) const;
//	CrxDbObjectId getDimstyleChildId(const CrxRxClass *pDimClass,
//		CrxDbObjectId &parentStyle) const;
//
//	CrxDbObjectId getDimstyleParentId(CrxDbObjectId &childStyle) const;
//
//	CDraft::ErrorStatus setDimstyleData(CrxDbDimStyleTableRecord* pRec);
//	CDraft::ErrorStatus setDimstyleData(CrxDbObjectId id);
//
//	CrxDbObjectId cmlstyleID() const;
//	CDraft::ErrorStatus setCmlstyleID(CrxDbObjectId objId);
//
//	CAXA::Int16 cmljust() const;
//	CDraft::ErrorStatus setCmljust(CAXA::Int16 just);
//
//	double cmlscale() const;
//	CDraft::ErrorStatus setCmlscale(double scale);
//
//	double celtscale() const;
//	CDraft::ErrorStatus setCeltscale(double scale);
//
//	// Paper space variable access
//
//	CRxGePoint3d pinsbase() const;
//	CDraft::ErrorStatus setPinsbase(const CRxGePoint3d& base);
//
//	CRxGePoint3d pextmin() const;
//
//	CRxGePoint3d pextmax() const;
//
//	CDraft::ErrorStatus setPextmin(const CRxGePoint3d& min);
//	CDraft::ErrorStatus setPextmax(const CRxGePoint3d& max);
//
//	CRxGePoint2d plimmin() const;
//	CDraft::ErrorStatus setPlimmin(const CRxGePoint2d& min);
//
//	CRxGePoint2d plimmax() const;
//	CDraft::ErrorStatus setPlimmax(const CRxGePoint2d& max);
//
//	double pelevation() const;
//	CDraft::ErrorStatus setPelevation(double elev);
//
//	CRxGePoint3d pucsorg() const;
//
//	CRxGeVector3d pucsxdir() const;
//
//	CRxGeVector3d pucsydir() const;
//
	CRxDbObjectId pucsname() const;
//
//	CrxDbObjectId pucsBase() const;
//	CDraft::ErrorStatus setPucsBase(const CrxDbObjectId &ucsid);
//
//	CRxGePoint3d worldPucsBaseOrigin(CRxDb::OrthographicView orthoView) const;
//	CDraft::ErrorStatus setWorldPucsBaseOrigin(const CRxGePoint3d& origin,
//		CRxDb::OrthographicView orthoView);
//
//	bool isPucsOrthographic(CRxDb::OrthographicView& orthoView) const;
//
//	double cameraHeight() const;
//	CDraft::ErrorStatus setCameraHeight(const double cameraHeight);
//
//	double lensLength() const;
//	CDraft::ErrorStatus setLensLength(const double lensLength);
//
//	bool cameraDisplay() const;
//	CDraft::ErrorStatus setCameraDisplay(const bool cameraDisplay);
//
//	double stepsPerSec() const;
//	CDraft::ErrorStatus setStepsPerSec(double stepsPerSec);
//
//	double stepSize() const;
//	CDraft::ErrorStatus setStepSize(double stepSize);
//
//	bool realWorldScale() const;
//	CDraft::ErrorStatus setRealWorldScale(const bool realWorldScale);
//	// Model space variable access
//
//	CRxGePoint3d insbase() const;
//	CDraft::ErrorStatus setInsbase(const CRxGePoint3d& base);
//
	CRxGePoint3d extmin() const;
	CRxGePoint3d extmax() const;
//
//	CDraft::ErrorStatus updateExt(bool doBestFit = FALSE);
//
//	CDraft::ErrorStatus setExtmin(const CRxGePoint3d& min);
//	CDraft::ErrorStatus setExtmax(const CRxGePoint3d& max);
//
//	CRxGePoint2d limmin() const;
//	CDraft::ErrorStatus setLimmin(const CRxGePoint2d& min);
//
//	CRxGePoint2d limmax() const;
//	CDraft::ErrorStatus setLimmax(const CRxGePoint2d& max);
//
//	double elevation() const;
//	CDraft::ErrorStatus setElevation(double elev);
//
//	CRxGePoint3d ucsorg() const;
//
	CRxGeVector3d ucsxdir() const;
//
	CRxGeVector3d ucsydir() const;
//
//	CrxDbObjectId ucsname() const;
//
//	CrxDbObjectId ucsBase() const;
//	CDraft::ErrorStatus setUcsBase(CrxDbObjectId ucsid);
//
//	CRxGePoint3d worldUcsBaseOrigin(CRxDb::OrthographicView orthoView) const;
//	CDraft::ErrorStatus setWorldUcsBaseOrigin(const CRxGePoint3d& origin,
//		CRxDb::OrthographicView orthoView);
//
//	bool isUcsOrthographic(CRxDb::OrthographicView& orthoView) const;
//
//
//	// Dimension variable api:
//	//
//#undef DBDIMVAR_H                   // force the file to get read again
//#include "dbdimvar.h"
//
//	// DEPRECATED METHODS!
//	// These are supported but will be removed in future releases:
//	//
//	CDraft::ErrorStatus getDimpost(CxCHAR*& pOutput) const;
//	CDraft::ErrorStatus getDimapost(CxCHAR*& pOutput) const;
//	CDraft::ErrorStatus getDimblk(CxCHAR*& pOutput) const;
//	CDraft::ErrorStatus getDimblk1(CxCHAR*& pOutput) const;
//	CDraft::ErrorStatus getDimblk2(CxCHAR*& pOutput) const;
//
//	int dimfit() const;
//	int dimunit() const;
//
//	CDraft::ErrorStatus setDimfit(int fit);
//	CDraft::ErrorStatus setDimunit(int unit);
//	//
//	// end DEPRECATED METHODS!
//
//
//	CDraft::ErrorStatus getDimRecentStyleList(CRxDbObjectIdArray& objIds) const;
//
	CDraft::ErrorStatus loadLineTypeFile(const CxCHAR *ltn, const CxCHAR *filename);
//
//	CDraft::ErrorStatus getProjectName(CxCHAR*& pOutput) const;
//	CDraft::ErrorStatus setProjectName(const CxCHAR*);
//	CDraft::ErrorStatus getHyperlinkBase(CxCHAR*& pOutput) const;
//	CDraft::ErrorStatus setHyperlinkBase(const CxCHAR*);
//	CDraft::ErrorStatus getStyleSheet(CxCHAR*& pOutput) const;
//	CDraft::ErrorStatus setStyleSheet(const CxCHAR*);
	CDraft::ErrorStatus getFilename(const CxCHAR* & pOutput) const;
//
//	bool              isPartiallyOpened() const;
//	CDraft::ErrorStatus applyPartialOpenFilters(
//		const CRxDbSpatialFilter* pSpatialFilter,
//		const CRxDbLayerFilter* pLayerFilter);
//	// This will abort the current partial open operation and
//	// continue in a full open of the database.
//	//
//	void              disablePartialOpen();
//
//	CDraft::ErrorStatus getFingerprintGuid(CxCHAR*& guidString) const;
//	CDraft::ErrorStatus setFingerprintGuid(const CxCHAR *pNewGuid);
//
//	CDraft::ErrorStatus getVersionGuid(CxCHAR*& guidString) const;
//	CDraft::ErrorStatus setVersionGuid(const CxCHAR *pNewGuid);
//
//
//	// New text sysvars
//	//
//	int tstackalign() const;
//	CDraft::ErrorStatus setTStackAlign(int val);
//
//	int tstacksize() const;
//	CDraft::ErrorStatus setTStackSize(int val);
//
//	CRxDb::UnitsValue insunits() const;
//	CDraft::ErrorStatus setInsunits(const CRxDb::UnitsValue units);
//
//	// Graphics cache
//	//
//	void                setGsModel(CRxGsModel*);
//	CRxGsModel*          gsModel() const;
//
//	void                setGsHighlightModel(CRxGsModel*);
//	CRxGsModel*          gsHighlightModel() const;
//
//	// Plot Style Legacy
//	bool           plotStyleMode() const;
//
//	// Default paperspace viewport scale
//	double viewportScaleDefault() const;
//	CDraft::ErrorStatus setViewportScaleDefault(double newDefaultVPScale);
//
//	// dwg watermark
//	bool           dwgFileWasSavedByAutodeskSoftware() const;
//
//	// Layer state manager API
//	CRxDbLayerStateManager *getLayerStateManager() const;
//
//	// Object context manager API
//	CRxDbObjectContextManager* objectContextManager() const;
//
//	// When entity traversals are sorted (CRxDb::kSortEnts*).
//	CAXA::UInt8        sortEnts() const;
//	CDraft::ErrorStatus   setSortEnts(CAXA::UInt8 sortEnts);
//
//	CAXA::UInt8        drawOrderCtl() const;
//	CDraft::ErrorStatus   setDrawOrderCtl(CAXA::UInt8 val);
//
//	CAXA::UInt8        dimAssoc() const;
//	CDraft::ErrorStatus setDimAssoc(CAXA::UInt8 val);
//
//	CAXA::UInt8 hideText() const;
//	CDraft::ErrorStatus setHideText(CAXA::UInt8 val);
//
//	CAXA::UInt8  haloGap() const;
//	CDraft::ErrorStatus setHaloGap(CAXA::UInt8 val);
//
//	CAXA::UInt16 obscuredColor() const;
//	CDraft::ErrorStatus setObscuredColor(CAXA::UInt16 val);
//
//	CAXA::UInt8 obscuredLineType() const;
//	CDraft::ErrorStatus setObscuredLineType(CAXA::UInt8 val);
//
//	CAXA::UInt8  intersectDisplay() const;
//	CDraft::ErrorStatus setIntersectDisplay(CAXA::UInt8 val);
//
//	CAXA::UInt16 intersectColor() const;
//	CDraft::ErrorStatus setIntersectColor(CAXA::UInt16 val);
//
//	// For the CDRAFT_TABLESTYLE dictionary
//	CDraft::ErrorStatus getTableStyleDictionary(CrxDbDictionary*& pDict,
//		CRxDb::OpenMode mode);
//	CrxDbObjectId  tableStyleDictionaryId() const;
//
//	// The following functions are similar to setDimstyle/dimstyle
//	//
//	CrxDbObjectId tablestyle() const;
//	CDraft::ErrorStatus setTablestyle(CrxDbObjectId objId);
//
//	// For the CDRAFT_MLEADERSTYLE dictionary
//	CDraft::ErrorStatus getMLeaderStyleDictionary(CrxDbDictionary*& pDict,
//		CRxDb::OpenMode mode);
//	CrxDbObjectId  mleaderStyleDictionaryId() const;
//
//	// The following functions are similar to setDimstyle/dimstyle
//	//
//	CrxDbObjectId mleaderstyle() const;
//	CDraft::ErrorStatus setMLeaderstyle(CrxDbObjectId objId);
//
//	CDraft::ErrorStatus evaluateFields(int nContext,
//		const CxCHAR* pszPropName= NULL,
//		CrxDbDatabase* pDb      = NULL,
//		int* pNumFound         = NULL,
//		int* pNumEvaluated     = NULL);
//
//	// Get all CRxDbViewports in all CRxDbLayouts in the database
//	CDraft::ErrorStatus getViewportArray(CRxDbObjectIdArray& vportIds,
//		bool bGetPaperspaceVports = true) const;
//
//	// Get names of all visual styles in the database (visual styles for
//	// internal use only are excluded)
//	CDraft::ErrorStatus getVisualStyleList(CRxArray<const CxCHAR*> & vstyleList);
//
//	CAXA::UInt8  solidHist() const;  // 0 or 1(default)
//	CDraft::ErrorStatus setSolidHist(CAXA::UInt8 val);
//
//	CAXA::UInt8  showHist() const;   // 0, 1(default) or 2
//	CDraft::ErrorStatus setShowHist(CAXA::UInt8 val);
//
//	double psolWidth() const;
//	CDraft::ErrorStatus setPsolWidth(double width);
//	double psolHeight() const;
//	CDraft::ErrorStatus setPsolHeight(double height);
//
//	CAXA::UInt16 loftParam() const;
//	CDraft::ErrorStatus setLoftParam(CAXA::UInt16 flags);
//	CAXA::UInt8 loftNormals() const;
//	CDraft::ErrorStatus setLoftNormals(CAXA::UInt8 value);
//	double loftAng1() const;
//	CDraft::ErrorStatus setLoftAng1(double ang1);
//	double loftAng2() const;
//	CDraft::ErrorStatus setLoftAng2(double ang2);
//	double loftMag1() const;
//	CDraft::ErrorStatus setLoftMag1(double mag1);
//	double loftMag2() const;
//	CDraft::ErrorStatus setLoftMag2(double mag2);
//
//	// Lat and long are in decimal degrees, not radians!
//	double latitude() const;
//	CDraft::ErrorStatus setLatitude(double lat);
//	double longitude() const;
//	CDraft::ErrorStatus setLongitude(double lng);
//	double northDirection() const;
//	CDraft::ErrorStatus setNorthDirection(double northdir);
//	CRxDb::TimeZone timeZone() const;
//	CDraft::ErrorStatus setTimeZone(CRxDb::TimeZone tz);
//	// Offsets measured in hours difference from UTC
//	CDraft::ErrorStatus getTimeZoneInfo(CRxDb::TimeZone tz, double& offset, CRxString& desc) const;
//	CDraft::ErrorStatus setTimeZoneAsUtcOffset(double offset);
//	bool geoMarkerVisibility() const;
//	CDraft::ErrorStatus setGeoMarkerVisibility(bool value);
//
//	CAXA::UInt8 lightGlyphDisplay() const;  // 0 or 1(default)
//	CDraft::ErrorStatus setLightGlyphDisplay(CAXA::UInt8 val);
//	CAXA::UInt8 tileModeLightSynch() const;  // 0 or 1(default)
//	CDraft::ErrorStatus setTileModeLightSynch(CAXA::UInt8 val);
//
//	CrxCmColor interfereColor() const;
//	CDraft::ErrorStatus setInterfereColor(const CrxCmColor& color);
//
//	CrxDbObjectId interfereObjVisStyle() const;
//	CDraft::ErrorStatus setInterfereObjVisStyle(CrxDbObjectId id);
//
//	CrxDbObjectId interfereVpVisStyle() const;
//	CDraft::ErrorStatus setInterfereVpVisStyle(CrxDbObjectId id);
//
//	CrxDbObjectId dragVisStyle() const;
//	CDraft::ErrorStatus setDragVisStyle(CrxDbObjectId id);
//
//	CAXA::UInt8 cshadow() const;
//	CDraft::ErrorStatus setCshadow(CAXA::UInt8 val);
//
//	double shadowPlaneLocation() const;
//	CDraft::ErrorStatus setShadowPlaneLocation(double val);
//
//	CRxDbAnnotationScale* cannoscale() const;
//	CDraft::ErrorStatus setCannoscale(CRxDbAnnotationScale*);
//
//	bool annoAllVisible() const;
//	CDraft::ErrorStatus setAnnoAllVisible(bool allvis);
//
//	bool annotativeDwg() const;
//	CDraft::ErrorStatus setAnnotativeDwg(bool anno);
//
//	bool msltscale() const;
//	CDraft::ErrorStatus setMsltscale(bool val);
//
//	CAXA::UInt8 lightingUnits() const;
//	CDraft::ErrorStatus setLightingUnits(CAXA::UInt8 val);
//
//	bool lightsInBlocks() const;
//	CDraft::ErrorStatus setLightsInBlocks(bool val);
//
//	CAXA::Int16 dxeVal() const;
//	CDraft::ErrorStatus setDxeVal(CAXA::Int16 val);
//
//	double mleaderscale() const;
//	CDraft::ErrorStatus setMLeaderscale(double scale);
//
//	CAXA::Int16 cDynDisplayMode() const;
//	CDraft::ErrorStatus setCDynDisplayMode(CAXA::Int16 val);
//
//	CAXA::Int16 previewType() const;
//	CDraft::ErrorStatus setPreviewType(CAXA::Int16 val);
//
//	CAXA::UInt8 indexctl() const;
//	CDraft::ErrorStatus setIndexctl(CAXA::UInt8 val);
//
//	CAXA::UInt8 layerEval() const;
//	CDraft::ErrorStatus setLayerEval(CAXA::UInt8 val);
//
//	CAXA::Int16 layerNotify() const;
//	CDraft::ErrorStatus setLayerNotify(CAXA::Int16 val);
//
//	double msOleScale() const;
//	CDraft::ErrorStatus setMsOleScale(double val);
//
//	CAXA::UInt8 updateThumbnail() const;
//	CDraft::ErrorStatus setUpdateThumbnail(CAXA::UInt8 val);
//
//private:
//	friend class CRxDbSystemInternals;
//	CRxDbImpDatabase* mpImpDb;

	CDraft::ErrorStatus CrxCopy(const CRxDbObjectIdArray& IdArray, CRxDbDatabase*& o_pCrxDb);

	CDraft::ErrorStatus getRoughStyleTable  (CRxDbRoughStyleTable*& pTable,CRxDb::OpenMode    mode);
	CDraft::ErrorStatus getRoughStyleTable  (CRxDbSymbolTable*& pTable,CRxDb::OpenMode    mode);

	CDraft::ErrorStatus getDatumStyleTable  (CRxDbDatumStyleTable*& pTable,CRxDb::OpenMode    mode);
	CDraft::ErrorStatus getDatumStyleTable  (CRxDbSymbolTable*& pTable,CRxDb::OpenMode    mode);

	CDraft::ErrorStatus getGeoTolStyleTable  (CRxDbGeoTolStyleTable*& pTable,CRxDb::OpenMode    mode);
	CDraft::ErrorStatus getGeoTolStyleTable  (CRxDbSymbolTable*& pTable,CRxDb::OpenMode    mode);

	CDraft::ErrorStatus getCutsStyleTable  (CRxDbCutsStyleTable*& pTable,CRxDb::OpenMode    mode);
	CDraft::ErrorStatus getCutsStyleTable  (CRxDbSymbolTable*& pTable,CRxDb::OpenMode    mode);

	CDraft::ErrorStatus getWeldStyleTable  (CRxDbWeldStyleTable*& pTable,CRxDb::OpenMode    mode);
	CDraft::ErrorStatus getWeldStyleTable  (CRxDbSymbolTable*& pTable,CRxDb::OpenMode    mode);

	CDraft::ErrorStatus getPaperTable(CRxDbSymbolTable*& pTable,CRxDb::OpenMode mode);
	CDraft::ErrorStatus getPaperTable(CRxDbPaperTable*& pTable,CRxDb::OpenMode mode);

	CRxDbObjectId getCurrentRoughStyleId()const;
	CRxDbObjectId getCurrentDatumStyleId()const;
	CRxDbObjectId getCurrentGeoTolStyleId()const;
	CRxDbObjectId getCurrentCutsStyleId()const;
	CRxDbObjectId getCurrentWeldStyleId()const;
	CRxDbObjectId getCurrentLayerId()const;  

	// Traverse the db and remove non-purgeable ids from the array
	CDraft::ErrorStatus purge(CRxDbObjectIdArray& ids);
	//CDraft::ErrorStatus purge(CRxDbObjectIdGraph& idGraph);
	CDraft::ErrorStatus getLeaderStyleTable(CRxDbLeaderStyleTable*& pTable,CRxDb::OpenMode mode);
	CDraft::ErrorStatus getLeaderStyleTable(CRxDbSymbolTable*& pTable,CRxDb::OpenMode      mode);
	CDraft::ErrorStatus getPartnoStyleTable(CRxDbPartnoStyleTable*& pTable,CRxDb::OpenMode mode);
	CDraft::ErrorStatus getPartnoStyleTable(CRxDbSymbolTable*& pTable,CRxDb::OpenMode      mode);
	CDraft::ErrorStatus getBomStyleTable(CRxDbBomStyleTable*& pTable,CRxDb::OpenMode mode);
	CDraft::ErrorStatus getBomStyleTable(CRxDbSymbolTable*& pTable,CRxDb::OpenMode   mode);

	CAXA::Boolean isModified() const;	// CAXA 3D 2019

	CDraft::ErrorStatus getEnt3DPath(resbuf** pResbuf);

};

CRX_DEFINE_NULL_CLSID(CRxDbObjectIterator)
class CRXDB_CLASS CRxDbObjectIterator: public CRxObject
{
public:
	CRX_DECLARE_DYNAMIC(CRxDbObjectIterator);
	virtual ~CRxDbObjectIterator();

	bool           done() const;
	void           step(bool backwards = false, bool skipDeleted = true);
	void           setPosition(CRxDbEntity*  pEnt);
	void           setPosition(CRxDbObjectId  pObj);
	void           start(bool atEnd = false);
	CRxDbEntity*    entity();
	CRxDbObjectId   objectId();

public:
	LONG_PTR			m_lpPos;
	void				*mpImp;
	ICxCrxObject		*m_pCurObj;
	bool					m_bIgnoreSkipDeleted;

	//friend class CRxDbSystemInternals;
	CRxDbObjectIterator();
	//CRxDbSpaceIterator* mpImpIterator;
};

CRX_DEFINE_CLSID(E9147C07-548B-4e90-BE71-EBAF18758A72,CRxDbXObject)
class CRXDB_API CRxDbXObject: public CRxObject
	//
	// CrxRxObject which recognizes filer protocol,
	// and has a ACRX_DXF_CLASS_OBJ_BODY
	//
{
public:
	CRX_DECLARE_DYNAMIC(CRxDbXObject)

	//virtual CDraft::ErrorStatus audit(CRxDbAuditInfo* pAuditInfo);

	//CDraft::ErrorStatus dwgIn(CRxDbDwgFiler* pFiler);
	//virtual CDraft::ErrorStatus dwgInFields(CRxDbDwgFiler* pFiler);
	//CDraft::ErrorStatus dwgOut(CRxDbDwgFiler* pFiler) const;
	//virtual CDraft::ErrorStatus dwgOutFields(CRxDbDwgFiler* pFiler) const;

	//CDraft::ErrorStatus dxfIn(CRxDbDxfFiler* pFiler);
	//virtual CDraft::ErrorStatus dxfInFields(CRxDbDxfFiler* pFiler);
	//CDraft::ErrorStatus dxfOut(CRxDbDxfFiler* pFiler) const;
	//virtual CDraft::ErrorStatus dxfOutFields(CRxDbDxfFiler* pFiler) const;

protected:
	CRxDbXObject();
};


class CRxCmComplexColor: public  CRxDbXObject
{
public:
	CRX_DECLARE_DYNAMIC(CRxCmComplexColor); 

	virtual CRxCmComplexColor* incReference();
	virtual void              decReference();

	virtual CDraft::ErrorStatus getDescription(CxCHAR*& desc) const;
	virtual CDraft::ErrorStatus getExplanation(CxCHAR*& expl) const;

	virtual CRxCmEntityColor::ColorMethod  colorMethod() const;
	virtual CDraft::ErrorStatus setColorMethod(
		CRxCmEntityColor::ColorMethod eColorMethod);

	virtual bool              isByColor() const;
	virtual bool              isByLayer() const;
	virtual bool              isByBlock() const;
	virtual bool              isByACI()   const;
	virtual bool              isByPen ()  const;
	virtual bool              isForeground()   const;

	virtual CAXA::UInt32     color() const;
	virtual CDraft::ErrorStatus setColor(CAXA::UInt32 color);

	virtual CDraft::ErrorStatus setRGB  (CAXA::UInt8 red, 
		CAXA::UInt8 green, 
		CAXA::UInt8 blue);
	virtual CDraft::ErrorStatus setRed  (CAXA::UInt8 red);
	virtual CDraft::ErrorStatus setGreen(CAXA::UInt8 green);
	virtual CDraft::ErrorStatus setBlue (CAXA::UInt8 blue);
	virtual CAXA::UInt8      red  () const;
	virtual CAXA::UInt8      green() const;
	virtual CAXA::UInt8      blue () const;

	virtual CAXA::UInt16     colorIndex() const;
	virtual CDraft::ErrorStatus setColorIndex(CAXA::UInt16 colorIndex);
	virtual CAXA::UInt16     penIndex() const;   
	virtual CDraft::ErrorStatus setPenIndex (CAXA::UInt16 penIndex);


	// --- CrxRxObject protocol
	//
	virtual CDraft::ErrorStatus copyFrom(const CRxObject*);

	//virtual CDraft::ErrorStatus dwgInFields(CRxDbDwgFiler* pFiler);
	//virtual CDraft::ErrorStatus dwgOutFields(CRxDbDwgFiler* pFiler) const;
	//virtual CDraft::ErrorStatus dxfInFields(CRxDbDxfFiler* pFiler);
	//virtual CDraft::ErrorStatus dxfOutFields(CRxDbDxfFiler* pFiler) const;
	//virtual CDraft::ErrorStatus audit(CRxDbAuditInfo* pAuditInfo);

private:
	CAXA::UInt16 refCount;
	CRxCmEntityColor mColor;
};


class CRXDB_API CRxCmColor : public CRxCmColorBase
{
public:
	
	CRxCmColor();
	CRxCmColor(const CRxCmColor&);
	CRxCmColor(const CRxCmColorBase&);
	CRxCmColor& operator=(const CRxCmColor& inputColor);
	CRxCmColor& operator=(const CRxCmColorBase& inputColor);
	~CRxCmColor();

	bool operator ==(const CRxCmColor& color) const;
	bool operator !=(const CRxCmColor& color) const;
	bool operator ==(const CRxCmColorBase& color) const;
	bool operator !=(const CRxCmColorBase& color) const;

	CDraft::ErrorStatus getDescription(CxCHAR*& desc) const;
	CDraft::ErrorStatus getExplanation(CxCHAR*& expl) const;

	virtual CRxCmEntityColor::ColorMethod  colorMethod() const;
	virtual CDraft::ErrorStatus setColorMethod(CRxCmEntityColor::ColorMethod eColorMethod);

	virtual bool    isByColor() const;
	virtual bool    isByLayer() const;
	virtual bool    isByBlock() const;
	virtual bool    isByACI()   const;
	virtual bool    isByPen () const;
	virtual bool    isForeground()   const;

	bool            isNone() const;

	virtual CAXA::UInt32     color() const;
	virtual CDraft::ErrorStatus setColor(CAXA::UInt32 color);

	virtual CDraft::ErrorStatus setRGB  (CAXA::UInt8 red, 
		CAXA::UInt8 green, 
		CAXA::UInt8 blue);
	virtual CDraft::ErrorStatus setRed  (CAXA::UInt8 red);
	virtual CDraft::ErrorStatus setGreen(CAXA::UInt8 green);
	virtual CDraft::ErrorStatus setBlue (CAXA::UInt8 blue);
	virtual CAXA::UInt8      red  () const;
	virtual CAXA::UInt8      green() const;
	virtual CAXA::UInt8      blue () const;

	virtual CAXA::UInt16     colorIndex() const;
	virtual CDraft::ErrorStatus setColorIndex(CAXA::UInt16 colorIndex);
//	virtual CAXA::UInt16     penIndex() const;   
//	virtual CDraft::ErrorStatus setPenIndex (CAXA::UInt16 penIndex);

//	virtual CDraft::ErrorStatus setNames(const CxCHAR *colorName,
//		const CxCHAR *bookName = NULL);
	//virtual const CxCHAR *      colorName(void) const;
	//virtual const CxCHAR *      bookName(void) const;
	//virtual const CxCHAR *      colorNameForDisplay(void);
//	virtual bool              hasColorName(void) const;
//	virtual bool              hasBookName(void) const;

	CRxCmEntityColor           entityColor(void) const;
//	int                       dictionaryKeyLength(void) const;

	// Note: this deprecated method will go away in a future release.
	// Please use the new method which takes a size argument.
	//CAXA_DEPRECATED void   getDictionaryKey(CxCHAR *pKey) const;
//	void                    getDictionaryKey(CxCHAR *pKey, size_t nLen) const;
	//CDraft::ErrorStatus       setNamesFromDictionaryKey(const CxCHAR *pKey);

	// --- CrxRxObject protocol
	//
	//CDraft::ErrorStatus dwgIn(CRxDbDwgFiler* pInputFiler);
	//CDraft::ErrorStatus dwgOut(CRxDbDwgFiler *pOutputFiler) const;

	//CDraft::ErrorStatus dxfIn(CRxDbDxfFiler* pFiler, int groupCodeOffset = 0);
	//CDraft::ErrorStatus dxfOut(CRxDbDxfFiler* pFiler, int groupCodeOffset = 0) const;

	//CDraft::ErrorStatus audit(CRxDbAuditInfo* pAuditInfo);

	//CDraft::ErrorStatus serializeOut(void *pBuff, int *pBuflen,
	//	CRxDb::CRxDbDwgVersion ver = CRxDb::kDHL_CURRENT) const;

	//CDraft::ErrorStatus serializeIn(const void *pBuff, int *pBuflen);

	static const CAXA::UInt16 MaxColorIndex; 

	// These are obsolete and will be removed in a future release.
	// complexColor() always returns NULL, and setComplexColor() is
	// a no-op.
	//CRxCmComplexColor* complexColor() const;
	//void setComplexColor(CRxCmComplexColor* pComplex);

	//CDraft::ErrorStatus dwgInAsTrueColor(CRxDbDwgFiler* pInputFiler); // For internal use only
	//CDraft::ErrorStatus dwgOutAsTrueColor(CRxDbDwgFiler *pOutputFiler) const; // For internal use only

private:

	enum NameFlags {    kNoNames            = 0x00,
		kHasColorName       = 0x01,
		kHasBookName        = 0x02
	};


	// These are obsolete and will be removed in a future release.
	// isComplex() always returns false.
	static const CAXA::UInt16 ComplexColorFlag; 
	//bool isComplex() const;


	CRxCmEntityColor::RGBM   mRGBM;
	CxCHAR *                  mColorName;
	CxCHAR *                  mBookName;
	CAXA::UInt8            mNameFlags;

};

// Translate between CRxDbObjectName and crx_name, for use
// with ADS library functions.
//
CDraft::ErrorStatus CRXDB_API crxdbGetAdsName(crx_name&  objName, CRxDbObjectId objId);
CDraft::ErrorStatus CRXDB_API crxdbGetObjectId(CRxDbObjectId& objId, const crx_name objName);

// Object Open Functions:  Exchange an object Id and 
// open mode for a pointer to the corresponding object.
//
CDraft::ErrorStatus CRXDB_API
crxdbOpenCRxDbObject(CRxDbObject*& pObj, CRxDbObjectId id, CRxDb::OpenMode mode,
				   bool openErasedObject = false);

CDraft::ErrorStatus CRXDB_API CAXA_STDCALL 
crxdbOpenCRxDbObject(CRxDbObject*& pObj, CRxDbObjectId id, CRxDb::OpenMode mode,
				   const CRxClass *pClass, bool openErasedObject = false);

CDraft::ErrorStatus CRXDB_API
crxdbOpenCRxDbEntity(CRxDbEntity*& pEnt, CRxDbObjectId id, CRxDb::OpenMode mode,
				   bool openErasedEntity = false);

template<class T_OBJECT> inline  CDraft::ErrorStatus
crxdbOpenObject(
			   T_OBJECT *& pObj, CRxDbObjectId id, CRxDb::OpenMode mode,
			   bool openErased = false)
{
	return ::crxdbOpenCRxDbObject((CRxDbObject * &)pObj, id, mode,
		T_OBJECT::desc(), openErased);
}

//
// Special case the open functions for CrxDbObject and CrxDbEntity,
// since we can open them without calling desc() to get an CrxRxClass
// descriptor.
//
inline CDraft::ErrorStatus CRXDB_API crxdbOpenObject(
										CRxDbObject *& pObj, CRxDbObjectId id, CRxDb::OpenMode mode)
{
	return ::crxdbOpenCRxDbObject(pObj, id, mode, false);
}

inline CDraft::ErrorStatus CRXDB_API crxdbOpenObject(
										CRxDbEntity *& pEnt, CRxDbObjectId id, CRxDb::OpenMode mode)
{
	return ::crxdbOpenCRxDbEntity(pEnt, id, mode, false);
}

inline CDraft::ErrorStatus CRXDB_API crxdbOpenObject(
										CRxDbObject *& pObj, CRxDbObjectId id, CRxDb::OpenMode mode,
										bool openErased)
{
	return ::crxdbOpenCRxDbObject(pObj, id, mode, openErased);
}

inline CDraft::ErrorStatus CRXDB_API crxdbOpenObject(
										CRxDbEntity *& pEnt, CRxDbObjectId id, CRxDb::OpenMode mode,
										bool openErased)
{
	return ::crxdbOpenCRxDbEntity(pEnt, id, mode, openErased);
}
#endif
