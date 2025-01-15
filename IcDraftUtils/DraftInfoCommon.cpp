#include "stdafx.h"
#include "crxutcds.h"
#include "CrxCusUI.h"
#include "crxutcds.h"
#include "crxgs.h"
#include "dbmain.h"
#include "crxdocman.h"
#include "dbsymtb.h"
#include "dbapserv.h"
#include "cdscodes.h"
#include "crxedcds.h"
#include "dbbomsymtb.h"
//-----------------------------------------------------------------------------
#pragma comment(lib,"CrxUi.lib")
#pragma comment(lib,"Crx.lib")
#pragma comment(lib,"CrxDb.lib")
#pragma comment(lib,"CrxEdApi.lib")
#pragma comment(lib,"CrxGe.lib")
#pragma comment(lib,"CrxGi.lib")
#pragma comment(lib,"CrxSpt.lib")


enum CaxaDraftPaperSizeDescription {
	ePaperSizeA0 = 6000, /* A0 */
	ePaperSizeA1 = 6010, /* A1 */
	ePaperSizeA2 = 6020, /* A2 */
	ePaperSizeA3 = 6030, /* A3 */
	ePaperSizeA4 = 6040, /* A4 */
	ePaperSizeCustom = 6050 /* Custom */
};

enum CaxaDraftPaperDirection {
	ePaperDirHor = 6100, /* 横 */
	ePaperDirVer = 6110 /* 縦 */
};

/// <summary>
/// 現在(アクティブ)なファイルのパスを取得する
/// </summary>
/// <returns></returns>
CString getCurrDraftFilePath()
{
	CRxApDocument* pActiveDoc = crxDocManager->mdiActiveDocument();
	CString strFilePath = pActiveDoc->fileName();
	return strFilePath;
}


/// <summary>
/// 印刷サイズ情報を取得する
/// </summary>
/// <param name="paperType"></param>
/// <param name="isYoko"></param>
/// <param name="width"></param>
/// <param name="height"></param>
/// <returns></returns>
void GetPrintInformation(CString& paperType, bool& isYoko, double& width, double& height)
{
	CRxDbDatabase* pDb = crxdbHostApplicationServices()->workingDatabase();

	/* モデルの用紙情報を取得 */
	CRxDbPaperTable* pTable;
	pDb->getPaperTable(pTable, CRxDb::kForRead);
	CRxDbPaperTableRecord* pRecord;
	pTable->getAt(_T("Model"), pRecord, CRxDb::kForRead);

	/* 用紙サイズを取得 */
	pRecord->getPaperSize(width, height);

	/* 用紙種別を取得 */
	CDraft::PaperSizeDescription desc;
	pRecord->getPaperSizeDescription(desc);
	switch (desc)
	{
		case CaxaDraftPaperSizeDescription::ePaperSizeA0:
			paperType = _T("A0");
			break;
		case CaxaDraftPaperSizeDescription::ePaperSizeA1:
			paperType = _T("A1");
			break;
		case CaxaDraftPaperSizeDescription::ePaperSizeA2:
			paperType = _T("A2");
			break;
		case CaxaDraftPaperSizeDescription::ePaperSizeA3:
			paperType = _T("A3");
			break;
		case CaxaDraftPaperSizeDescription::ePaperSizeA4:
			paperType = _T("A4");
			break;
		case CaxaDraftPaperSizeDescription::ePaperSizeCustom:
			paperType = _T("Custom");
			break;
		default:
			break;
	}

	/* 用紙の向きを取得 */
	CDraft::Paper_Direction direction;
	pRecord->getPaperDirection(direction);
	if (direction == CaxaDraftPaperDirection::ePaperDirHor)
	{
		isYoko = true;
	}
	else
	{
		isYoko = false;
	}
	return;
}
