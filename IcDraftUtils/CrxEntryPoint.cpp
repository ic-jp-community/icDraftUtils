// HelloWordMenuEntryPoint.cpp : CHelloWordMenuEntryPoint 
#include <iostream>
#include <fstream>
 
#include "stdafx.h"
#include "resource.h"
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
#include "DialogOK.h"
#include "IcDraftUtilsCommon.h"
#include "DraftInfoCommon.h"
#include "IcDraftUtilsMain.h"
#include <stdio.h>
#include <string>
//-----------------------------------------------------------------------------
#define szRDS _RXST("")
#pragma comment(lib,"CrxUi.lib")
#pragma comment(lib,"Crx.lib")
#pragma comment(lib,"CrxDb.lib")
#pragma comment(lib,"CrxEdApi.lib")
#pragma comment(lib,"CrxGe.lib")
#pragma comment(lib,"CrxGi.lib")
#pragma comment(lib,"CrxSpt.lib")
//#define CMDchenliao cmdHello1()

HINSTANCE g_hdllInstance;
void InitCmdIcDraftUtils();

/// <summary>
/// IcDraftUtils
/// </summary>
class CIcDraftUtilsMenuApp :public AcRxArxApp
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	CIcDraftUtilsMenuApp() :AcRxArxApp()
	{

	}

	/// <summary>
	/// 初期ロード処理(コマンドの登録)
	/// </summary>
	/// <param name="pkt"></param>
	/// <returns></returns>
	virtual AcRx::AppRetCode On_kInitAppMsg(void* pkt)
	{
		/* 初期化処理 */
		AcRx::AppRetCode retCode = AcRxArxApp::On_kInitAppMsg(pkt);
		g_hdllInstance = m_hdllInstance;
		// コマンドを追加する
		crxedRegCmds->addCommand(_T("Exbファイルの一括更新"), _T("GExbファイルの一括更新"), _T("Exbファイルの一括更新"), ACRX_CMD_MODAL, &IcDraftUtilsMain);
		crxedRegCmds->addCommand(_T("IcDraftUtilsSetting"), _T("GIcDraftUtilsSetting"), _T("IcDraftUtilsSetting"), ACRX_CMD_MODAL, &IcDraftUtilsSetting);
		InitCmdIcDraftUtils();
		return (retCode);
	}

	/// <summary>
	/// アンロード処理
	/// </summary>
	/// <param name="pkt"></param>
	/// <returns></returns>
	virtual AcRx::AppRetCode On_kUnloadAppMsg(void* pkt)
	{
		// TODO: Add your code here

		// You *must* call On_kUnloadAppMsg here
		AcRx::AppRetCode retCode = AcRxArxApp::On_kUnloadAppMsg(pkt);

		crxedRegCmds->removeGroup(_T("IcDraftUtils"));

		// TODO: Unload dependencies here
		return (retCode);
	}

	virtual void RegisterServerComponents()
	{

	}
};


/// <summary>
/// リボンタブを作成・初期化する
/// </summary>
void InitCmdIcDraftUtils()
{
	CRxUIManager* CrxUI = crxUIManager;
	CRxRibbonTab* pRibbonTab = NULL;
	CRxRibbonPanel* pRibbonPanel = NULL;

	HBITMAP hBitmap1 = (HBITMAP)::LoadImage(g_hdllInstance, MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, LR_COPYFROMRESOURCE | LR_CREATEDIBSECTION);
	HBITMAP hBitmapLarge1 = (HBITMAP)::LoadImage(g_hdllInstance, MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, LR_COPYFROMRESOURCE | LR_CREATEDIBSECTION);
	HBITMAP hBitmap2 = (HBITMAP)::LoadImage(g_hdllInstance, MAKEINTRESOURCE(IDB_BITMAP3), IMAGE_BITMAP, 0, 0, LR_COPYFROMRESOURCE | LR_CREATEDIBSECTION);
	HBITMAP hBitmapLarge2 = (HBITMAP)::LoadImage(g_hdllInstance, MAKEINTRESOURCE(IDB_BITMAP3), IMAGE_BITMAP, 0, 0, LR_COPYFROMRESOURCE | LR_CREATEDIBSECTION);


	/* リボンバーを取得する */
	CRxRibbonBar* pRibbonBar = CrxUI->getCRxRibbonBar();
	if (pRibbonBar != NULL)
	{
		/* リボンタブを作成する */
		pRibbonTab = pRibbonBar->AppendRibbonTab(_T("IcDraftUtils"), _T("IcDraftUtils"), TRUE);

		if (pRibbonTab != NULL)
		{
			/* パネルを作成する */
			pRibbonPanel = pRibbonTab->AppendRibbonPanel(_T("IcDraftUtils"), _T("IcDraftUtils"), (ULONG_PTR)pRibbonBar);
			if (pRibbonPanel != NULL)
			{
				/* ボタンを作成する */
				CRxRibbonButton* pBtn1 = pRibbonPanel->AppendRibbonButton(_T("Exbファイルの 一括更新"), _T("Exbファイルの一括更新"), hBitmap1, hBitmapLarge1, (ULONG_PTR)pRibbonPanel, _T("GExbファイルの一括更新"), _T("指定したフォルダ内のExbファイルをすべて開いて更新します。"));
				CRxRibbonButton* pBtn2 = pRibbonPanel->AppendRibbonButton(_T("設定"), _T("設定"), hBitmap2, hBitmapLarge2, (ULONG_PTR)pRibbonPanel, _T("GIcDraftUtilsSetting"), _T("設定画面を表示します。"));
				//	CRxRibbonButton *pBtn = pRibbonPanel->AppendRibbonButton(_T("IcDraftUtils"), _T("IcDraftUtils"), hBitmap, hBitmapLarge,(ULONG_PTR)pRibbonPanel,_T("GIcDraftUtils"));
			}
		}

	}
}

IMPLEMENT_ARX_ENTRYPOINT(CIcDraftUtilsMenuApp)