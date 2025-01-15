#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <Winsock2.h> 
#include <shobjidl.h> 
#include <stdlib.h>
#include <codecvt>
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
#include "IcDraftUtilsSetting.h"
#include "DraftInfoCommon.h"
#include "IcDraftUtilsMain.h"
#include "IcDraftUtilsRetCode.h"

//-----------------------------------------------------------------------------
#define szRDS _RXST("")
#pragma comment(lib,"CrxUi.lib")
#pragma comment(lib,"Crx.lib")
#pragma comment(lib,"CrxDb.lib")
#pragma comment(lib,"CrxEdApi.lib")
#pragma comment(lib,"CrxGe.lib")
#pragma comment(lib,"CrxGi.lib")
#pragma comment(lib,"CrxSpt.lib")
#define CMDchenliao cmdHello1()


/// <summary>
/// 設定を開く
/// </summary>
void IcDraftUtilsSetting()
{
	bool fileMode = true;
	CString args;
	CString msg;

	STARTUPINFO         tStartupInfo = { 0 };
	PROCESS_INFORMATION tProcessInfomation = { 0 };
	CString prgPath;
	getIcDraftAutoClickerFilePath(prgPath);
	args.Format(_T("\"%s\" %s"), prgPath, _T("/setting"));

	/*	変換プログラムの設定画面を起動する */
	BOOL bResult = CreateProcess(
		prgPath
		, ConvertToUnicode(args)
		, NULL
		, NULL
		, FALSE
		, 0
		, NULL
		, NULL
		, &tStartupInfo
		, &tProcessInfomation
	);
	if (0 == bResult)
	{
		AfxMessageBox(_T("設定の起動に失敗しました。"));
	}
	else
	{
		/* プロセスの終了を待つ */
		DWORD dwResult = ::WaitForSingleObject(tProcessInfomation.hProcess, INFINITE);
		if (WAIT_FAILED == dwResult)
		{
			HRESULT hResult = HRESULT_FROM_WIN32(::GetLastError());
		}
	}

	CloseHandle(tProcessInfomation.hProcess);
	CloseHandle(tProcessInfomation.hThread);
	return;
}

/// <summary>
/// 設定を開く
/// </summary>
int IcAutoUpdateClicker(PROCESS_INFORMATION &tProcessInfomation, CString targetExbFilePath, CString mode, CString paperName = _T(""))
{
	bool fileMode = true;
	CString args;
	CString msg;
	STARTUPINFO         tStartupInfo = { 0 };
	CString prgPath;
	getIcDraftAutoClickerFilePath(prgPath);
	CString icVersion;
	getIcVersion(icVersion);

	if (mode == _T("save"))
	{
		args.Format(_T("\"%s\" /ic:%s %s /target:%s"), prgPath, icVersion, _T("/save"), (LPCTSTR)targetExbFilePath);
	}
	else if (mode == _T("nosave"))
	{
		args.Format(_T("\"%s\" /ic:%s %s /target:%s"), prgPath, icVersion, _T("/nosave"), (LPCTSTR)targetExbFilePath);
	}
	else if (mode == _T("update"))
	{
		args.Format(_T("\"%s\" /ic:%s %s /target:%s"), prgPath, icVersion, _T("/update"), (LPCTSTR)targetExbFilePath);
	}
	else if (mode == _T("updatepaper"))
	{
		args.Format(_T("\"%s\" /ic:%s %s /target:%s"), prgPath, icVersion, _T("/updatepaper"), (LPCTSTR)targetExbFilePath);
	}
	else if (mode == _T("paperclick"))
	{
		args.Format(_T("\"%s\" /ic:%s %s %s /target:%s"), prgPath, icVersion, _T("/paperclick"), paperName, (LPCTSTR)targetExbFilePath);
	}
	else
	{

	}

	LPWSTR argsStr = ConvertToUnicode(args);

	/*	変換プログラムの設定画面を起動する */
	BOOL bResult = CreateProcess(
		prgPath
		, argsStr
		, NULL
		, NULL
		, FALSE
		, 0
		, NULL
		, NULL
		, &tStartupInfo
		, &tProcessInfomation
	);
	if (0 == bResult)
	{
		AfxMessageBox(_T("IcDraftAutoClickerの起動に失敗しました。"));
		return -10;
	}
	return 0;
}

/// <summary>
/// フォルダの選択ダイアログを表示する
/// </summary>
/// <param name="saveFilePath"></param>
/// <returns></returns>
bool FolderSelectDialog(CString& saveFilePath)
{
	bool ret = false;
	IFileOpenDialog* pFileDlg = NULL;

	// Create the FileOpenDialog object.
	HRESULT hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL, IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileDlg));
	if (FAILED(hr))
	{
		pFileDlg->Release();
		return false;
	}

	FILEOPENDIALOGOPTIONS opt;
	pFileDlg->GetOptions(&opt);
	if (pFileDlg->SetOptions(opt | FOS_PICKFOLDERS | FOS_PATHMUSTEXIST) != S_OK)
	{
		pFileDlg->Release();
		return false;
	}

	if (SUCCEEDED(hr))
	{
		// Show the Open dialog box.
		hr = pFileDlg->Show(NULL);

		// Get the file name from the dialog box.
		if (SUCCEEDED(hr))
		{
			IShellItem* pItem;
			hr = pFileDlg->GetResult(&pItem);
			if (SUCCEEDED(hr))
			{
				PWSTR pszFilePath = NULL;
				hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);  // ファイル名を得る
				if (SUCCEEDED(hr))
				{
					saveFilePath = CStringA(pszFilePath);  // wchar_t → CStringA(multibyte)
					CoTaskMemFree(pszFilePath);
					ret = true;
				}
				pItem->Release();
			}
		}
		pFileDlg->Release();
	}
	CoUninitialize();
	return ret;
}


/// <summary>
/// 作業フォルダを作成する
/// </summary>
/// <returns></returns>
bool createWorkFolder()
{
	bool ret = false;
	CString workFolderPath;
	getWorkFolder(workFolderPath);
	if (GetFileAttributes(workFolderPath) == INVALID_FILE_ATTRIBUTES)
	{
		/* ディレクトリがない */
		ret = CreateDirectory(workFolderPath, NULL);
		if (ret != true)
		{
			/* 作業ディレクトリの作成失敗 */
			return false;
		}
	}
	return true;
}

/// <summary>
/// ファイル選択のダイアログ(C#)を表示する
/// </summary>
/// <param name="processRetCode"></param>
/// <param name="selectFilesPath"></param>
void SelectFilesDialog(DWORD& processRetCode, CString& selectFilesPath)
{
	CString args;
	CString workFolderPath;
	CString fileName;
	STARTUPINFO         tStartupInfo = { 0 };
	PROCESS_INFORMATION tProcessInfomation = { 0 };
	CString prgPath;
	CString systenDateTime;

	getIcDraftAutoClickerFilePath(prgPath);
	getWorkFolder(workFolderPath);
	getSystemTimeString(systenDateTime);
	fileName.Format(_T("IcDraftUtils-%s"), systenDateTime);
	selectFilesPath.Format(_T("%s\\%s"), workFolderPath,  fileName);
	args.Format(_T("\"%s\" %s %s"), prgPath, _T("/selectfiles"), selectFilesPath);

	/*	変換プログラムの設定画面を起動する */
	BOOL bResult = CreateProcess(
		prgPath
		, ConvertToUnicode(args)
		, NULL
		, NULL
		, FALSE
		, 0
		, NULL
		, NULL
		, &tStartupInfo
		, &tProcessInfomation
	);
	if (0 == bResult)
	{
		AfxMessageBox(_T("設定の起動に失敗しました。"));
		processRetCode = RETCODE_NG_INNER_ERROR;
		return;
	}
	else
	{
		/* プロセスの終了を待つ */
		DWORD dwResult = ::WaitForSingleObject(tProcessInfomation.hProcess, INFINITE);
		if (WAIT_FAILED == dwResult)
		{
			HRESULT hResult = HRESULT_FROM_WIN32(::GetLastError());
		}
	}

	GetExitCodeProcess(tProcessInfomation.hProcess, &processRetCode);
	CloseHandle(tProcessInfomation.hProcess);
	CloseHandle(tProcessInfomation.hThread);

	return;
}

bool getApDocumentFromFilePath(CString filePath, CRxApDocument** openedDoc)
{
	CRxApDocumentIterator* docIter = crxDocManager->newAcApDocumentIterator();
	bool ret = false;
	while (!docIter->done())
	{
		CRxApDocument* doc = docIter->document();
		if (doc)
		{
			CString strfileName = doc->fileName();
			CString strTile = doc->docTitle();
			if (strfileName == filePath)
			{
				*openedDoc = doc;
				ret = true;
				crxDocManager->setCurDocument(doc);
				crxDocManager->mdiActiveDocument();
				break;
			}
		}
		docIter->step();
	}
	return ret;
}

void getIcVersion(CString& version)
{
	CString	s;
	wchar_t szModulePath[MAX_PATH_LENGTH];

	GetModuleFileNameW(NULL, szModulePath, sizeof(szModulePath) / sizeof(szModulePath[0]));
	s.Format(_T("%s"),  szModulePath);
	s.Replace(_T("\\bin\\IRONCAD.exe"), _T(""));
	int lastEn = s.ReverseFind('\\');
	version.Format(_T("%s"), s.Mid(lastEn + 1, s.GetLength() - (lastEn - 1)));
	return;
}

void showLogFile(CString selectFilePath, CString logFilePath)
{
//	_wsystem(logFilePath);

	bool fileMode = true;
	CString args;
	CString msg;
	STARTUPINFO         tStartupInfo = { 0 };
	PROCESS_INFORMATION tProcessInfomation = { 0 };
	CString prgPath;
	getIcDraftAutoClickerFilePath(prgPath);
	args.Format(_T("\"%s\" /showresult %s %s"), prgPath, (LPCTSTR)selectFilePath, (LPCTSTR)logFilePath);
	LPWSTR argsStr = ConvertToUnicode(args);

	/*	変換プログラムの設定画面を起動する */
	BOOL bResult = CreateProcess(
		prgPath
		, argsStr
		, NULL
		, NULL
		, FALSE
		, 0
		, NULL
		, NULL
		, &tStartupInfo
		, &tProcessInfomation
	);
	if (0 == bResult)
	{
		AfxMessageBox(_T("IcDraftAutoClickerの起動に失敗しました。"));
	}
	CloseHandle(tProcessInfomation.hProcess);
	CloseHandle(tProcessInfomation.hThread);
}
void getPaper(CRxApDocument* apDoc, CString& currPaper, vector<CString>& anotherPaper)
{	
	CRxDbDatabase* pDb = apDoc->database();
	CDraft::ErrorStatus es = CDraft::eOk;
	CRxDbPaperTable* pTable;
	es = pDb->getPaperTable(pTable, CRxDb::kForRead);
	if (es != CDraft::eOk)
	{
		return;
	}
	CRxDbObjectId idCurPaper = pTable->CurrentPaperId();
	int iCount = pTable->getPaperCount();
	for (int i = 0; i < iCount; ++i)
	{
		CxCHAR* strPaperName = NULL;
		CString paperName;
		pTable->getPaperNameByIndex(i, strPaperName);

		CRxDbObjectId idLayout;
		pTable->getAt(strPaperName, idLayout, false);
		if (wcscmp(strPaperName, _T("model")) == 0)
		{
			paperName.Format(_T("モデル"));
		}
		else
		{
			paperName.Format(_T("%s"), strPaperName);
		}

		if (idLayout == idCurPaper)
		{
			currPaper.Format(_T("%s"), paperName);
			continue;
		}
		anotherPaper.push_back(paperName);
	}
	pTable->close();
}

/// <summary>
/// メイン処理
/// </summary>
void IcDraftUtilsMain()
{
	bool ret;
	STARTUPINFO         tStartupInfo = { 0 };
	PROCESS_INFORMATION tProcessInfomation = { 0 };
	CString setFilesPath;
	std::vector<CString> files;
	DWORD processRetCode = RETCODE_NONE;
	CDraft::ErrorStatus closeResult = CDraft::ErrorStatus::eOk;
	bool isMultiPaper = false;
	vector<CString> update3DNotFoundFiles;
	vector<CString> updateDimCheckFiles;
	vector<CString> modelPaperErrorFiles;
	vector<CString> multiPaperFiles;
	vector<CString> updateFiles;
	vector<CString> saveFiles;
	vector<CString> notSaveFiles;
	WCHAR startDateTime[32] = _T("");
	WCHAR endDateTime[32] = _T("");
	time_t t = time(NULL);
	wcsftime(startDateTime, sizeof(startDateTime), _T("%Y/%m/%d %H:%M:%S"), localtime(&t));

	/* 作業フォルダを作成 */
	ret = createWorkFolder();
	if (ret != true)
	{
		AfxMessageBox(_T("作業フォルダの作成に失敗しました。"));
		return;
	}

	/* 更新するExbファイルを選択し、ファイルリストを作成(C#) */
	SelectFilesDialog(processRetCode, setFilesPath);
	if (processRetCode != RETCODE_SETFILE_OK)
	{
		return;
	}

	/* ファイルリストを読み込む */
	ret = getSelectFiles(setFilesPath, files);
	if (ret != true)
	{
		AfxMessageBox(_T("選択したファイルリストを読み込めませんでした。"));
		return;
	}

	/* Exbファイルを開いて更新して保存して閉じる */
	for each (CString filePath in files)
	{
		updateFiles.clear();
		isMultiPaper = false;

		/* AutoClickerを起動する */
		PROCESS_INFORMATION tProcessInfomation = { 0 };
		int retCode = IcAutoUpdateClicker(tProcessInfomation, filePath, _T("update"));
		if (retCode != 0)
		{
			AfxMessageBox(_T("IcAutoUpdateClickerを起動できませんでした"));
			continue;
		}

		/* Exbファイルを開く */
		CDraft::ErrorStatus openResult = crxDocManager->appContextOpenDocument(filePath);
		if (openResult != CDraft::ErrorStatus::eOk)
		{
			TerminateProcess(tProcessInfomation.hProcess, 0);
			continue;
		}

		/* 現在開いているファイルのApDocumentを取得する */
		CRxApDocument* openedDoc;
		bool getResult = getApDocumentFromFilePath(filePath, &openedDoc);
		if (getResult != true)
		{
			TerminateProcess(tProcessInfomation.hProcess, 0);
			continue;
		}

		/* AutoClickerプロセスを終了させる */
		CloseProcess(tProcessInfomation, processRetCode);
		if ((processRetCode & RETCODE_WINDOW_3DNOTFOUND_SET_NO) != 0)
		{
			/* 3DNotFound */
			update3DNotFoundFiles.push_back(filePath);
		}
		if ((processRetCode & RETCODE_WINDOW_DIM_CHECK_SET_CANCEL) != 0)
		{
			/* DimCheck */
			updateDimCheckFiles.push_back(filePath);
		}
		if ((processRetCode & RETCODE_WINDOW_UPDATE_SET_YES) != 0)
		{
			/* 更新するをクリックした */
			updateFiles.push_back(filePath);
		}

		CString currPaper;
		vector<CString> anotherPaper;
		/* 複数シートあるかチェックする */
		getPaper(openedDoc, currPaper, anotherPaper);
		if (anotherPaper.size() > 0)
		{
			isMultiPaper = true;
			multiPaperFiles.push_back(filePath);
		}
		for each (CString paper in anotherPaper)
		{
			/* 複数シートあるので他のシートも処理する */
			/* AutoClickerを起動する */
			PROCESS_INFORMATION tProcessInfomation = { 0 };
			int retCode = IcAutoUpdateClicker(tProcessInfomation, filePath, _T("paperclick"), paper);
			if (retCode != 0)
			{
				AfxMessageBox(_T("IcAutoUpdateClickerを起動できませんでした"));
				continue;
			}

			/* AutoClickerプロセスを終了させる */
			waitInfiniteProcessExit(tProcessInfomation,  processRetCode);
			if (processRetCode != RETCODE_PAPERCLICK_CLICK_OK)
			{
				modelPaperErrorFiles.push_back(filePath + "  ErrorPaper: " + paper);
				AfxMessageBox(_T("指定したmodel/paperを見つけられませんでした"));
				continue;
			}
			/* AutoClickerを起動する */
			tProcessInfomation = { 0 };
			retCode = IcAutoUpdateClicker(tProcessInfomation, filePath, _T("updatepaper"));
			if (retCode != 0)
			{
				AfxMessageBox(_T("IcAutoUpdateClickerを起動できませんでした"));
				continue;
			}

			/* AutoClickerプロセスを終了させる updatepaperはC#側で設定時間でタイムアウトする */
			waitInfiniteProcessExit(tProcessInfomation, processRetCode);
			if ((processRetCode & RETCODE_WINDOW_3DNOTFOUND_SET_NO) != 0)
			{
				/* 3DNotFound */
				update3DNotFoundFiles.push_back(filePath);
			}
			if ((processRetCode & RETCODE_WINDOW_DIM_CHECK_SET_CANCEL) != 0)
			{
				/* DimCheck */
				updateDimCheckFiles.push_back(filePath);
			}
			if ((processRetCode & RETCODE_WINDOW_UPDATE_SET_YES) != 0)
			{
				/* 更新するをクリックした */
				updateFiles.push_back(filePath);
			}
		}
		if (isMultiPaper == true)
		{
			/* 初期の開いていたPaperに戻す */
			/* AutoClickerを起動する */
			PROCESS_INFORMATION tProcessInfomation = { 0 };
			int retCode = IcAutoUpdateClicker(tProcessInfomation, filePath, _T("paperclick"), currPaper);
			if (retCode != 0)
			{
				AfxMessageBox(_T("IcAutoUpdateClickerを起動できませんでした"));
			}

			/* AutoClickerプロセスを終了させる */
			waitInfiniteProcessExit(tProcessInfomation, processRetCode);
			if (processRetCode != RETCODE_PAPERCLICK_CLICK_OK)
			{
				modelPaperErrorFiles.push_back(filePath + "  ErrorPaper: " + currPaper);
				AfxMessageBox(_T("指定したmodel/paperを見つけられませんでした"));
			}
		}

		/* 閉じる */
		closeResult = crxDocManager->closeDocument(openedDoc);

		/* 保存のダイアログを"はい"で終了させる */
		if (isMultiPaper == true)
		{
			int count = std::count_if(std::cbegin(updateFiles), std::cend(updateFiles), [filePath](CString e) { return (e.Find(filePath) != -1); });
			if (count <= 0)
			{
				/* 更新していないので保存しない */
				IcAutoUpdateClicker(tProcessInfomation, filePath, _T("nosave"));
			}
			else
			{
				/* 保存するが表示されたら保存する */
				IcAutoUpdateClicker(tProcessInfomation, filePath, _T("save"));
			}
		}
		else
		{
			/* 保存するが表示されたら保存する */
			IcAutoUpdateClicker(tProcessInfomation, filePath, _T("save"));
		}

		/* プロセスの終了を待つ */
		waitProcessExit(tProcessInfomation, 60000, processRetCode);
		if ((processRetCode & RETCODE_WINDOW_SAVE_SET_YES) != 0)
		{
			saveFiles.push_back(filePath);
		}
		else
		{
			notSaveFiles.push_back(filePath);
		}
	}
	/* ログを出力する */
	if ((saveFiles.size() > 0) || (notSaveFiles.size() > 0))
	{
		t = time(NULL);
		wcsftime(endDateTime, sizeof(endDateTime), _T("%Y/%m/%d %H:%M:%S"), localtime(&t));
		CString logFilePath;
		logFilePath.Format(_T("%s-Log.txt"), setFilesPath);
		FILE* fp = _wfopen(logFilePath, _T("w, ccs=UTF-8"));
		fwprintf(fp, _T("%s%s\n"), _T("■開始時刻:"), startDateTime);
		fwprintf(fp, _T("%s%s\n"), _T("■終了時刻:"), endDateTime);
		fwprintf(fp, _T("---------------------------------------------\n"));
		fwprintf(fp, _T("[更新したファイル]\n"));
		for each (CString fileName in saveFiles)
		{
			CString multiPaper = _T("");
			CString dimCheck = _T("");
			CString Check3DSceneFile = _T("");
			CString CheckMultiPaperFile = _T("");
			
			if (std::count(multiPaperFiles.begin(), multiPaperFiles.end(), fileName) != 0)
			{
				multiPaper.Format(_T("  【複数シート】 "));
			}
			if (std::count(updateDimCheckFiles.begin(), updateDimCheckFiles.end(), fileName) != 0)
			{
				dimCheck.Format(_T("    ◆注意:寸法のチェックが必要です "));
			}
			if (std::count(update3DNotFoundFiles.begin(), update3DNotFoundFiles.end(), fileName) != 0)
			{
				Check3DSceneFile.Format(_T("    ◆注意:3Dシーンファイルが見つかりませんでした"));
			}
			int count = std::count_if(std::cbegin(modelPaperErrorFiles), std::cend(modelPaperErrorFiles), [fileName](CString e) { return (e.Find(fileName) != -1); });
			if (count != 0)
			{
				CheckMultiPaperFile.Format(_T("    ◆注意:複数シートの更新に失敗しました。"));
			}
			
			fwprintf(fp, _T("%s %s %s %s %s\n"), fileName, multiPaper, dimCheck, Check3DSceneFile, CheckMultiPaperFile);
		}
		fwprintf(fp, _T("\n"));
		fwprintf(fp, _T("[更新しなかったファイル]\n"));
		for each (CString fileName in notSaveFiles)
		{
			CString multiPaper = _T("");
			CString dimCheck = _T("");
			CString Check3DSceneFile = _T("");
			CString CheckMultiPaperFile = _T("");
			if (std::count(multiPaperFiles.begin(), multiPaperFiles.end(), fileName) != 0)
			{
				multiPaper.Format(_T("  【複数シート】 "));
			}
			if (std::count(updateDimCheckFiles.begin(), updateDimCheckFiles.end(), fileName) != 0)
			{
				dimCheck.Format(_T("    ◆注意:寸法のチェックが必要です"));
			}
			if (std::count(update3DNotFoundFiles.begin(), update3DNotFoundFiles.end(), fileName) != 0)
			{
				Check3DSceneFile.Format(_T("    ◆注意:3Dシーンファイルが見つかりませんでした"));
			}
			int count = std::count_if(std::cbegin(modelPaperErrorFiles), std::cend(modelPaperErrorFiles), [fileName](CString e) { return (e.Find(fileName) != -1); });
			if (count != 0)
			{
				CheckMultiPaperFile.Format(_T("    ◆注意:複数シートの更新に失敗しました。"));
			}
			fwprintf(fp, _T("%s %s %s %s %s\n"), fileName, multiPaper, dimCheck, Check3DSceneFile, CheckMultiPaperFile);
		}
		fwprintf(fp, _T("---------------------------------------------\n"));
		fwprintf(fp, _T("\n\n"));
		fclose(fp);
		AfxMessageBox(_T("一括更新処理が完了しました。"), MB_ICONINFORMATION);
		showLogFile(setFilesPath, logFilePath);
	}

	return;
}


/// <summary>
/// 選択したファイルリストを読み込む
/// </summary>
/// <param name="setFilesPath"></param>
/// <param name="files"></param>
/// <returns></returns>
bool getSelectFiles(CString setFilesPath, std::vector<CString>& files)
{
	FILE* fp = _tfopen(setFilesPath, _T("r, ccs=UTF-8"));
	if (fp == NULL)
	{
		return false;
	}
	CStdioFile file(fp);
	CString read;
	while (file.ReadString(read) == true)
	{
		// データを読み込めた場合
		files.push_back(read);
	}
	file.Close();
	return true;;
}


/// <summary>
/// 当該プロセスIDのウィンドウハンドルを取得する
/// </summary>
/// <param name="target_id"></param>
/// <returns></returns>
HWND GetWindowHandle(const DWORD target_id)
{
	auto hWnd = GetTopWindow(nullptr);
	do {
		if (GetWindowLong(hWnd, GWLP_HWNDPARENT) != 0 || !IsWindowVisible(hWnd))
			continue;

		DWORD process_id;
		GetWindowThreadProcessId(hWnd, &process_id);
		if (target_id == process_id)
			return hWnd;
	} while ((hWnd = GetNextWindow(hWnd, GW_HWNDNEXT)) != nullptr);

	return nullptr;
}

/// <summary>
/// プロセスの終了を待って閉じる(タイムアウトあり)
/// </summary>
/// <param name="tProcessInfomation"></param>
/// <param name="timeout"></param>
/// <param name="processRetCode"></param>
void waitInfiniteProcessExit(PROCESS_INFORMATION& tProcessInfomation,  DWORD& processRetCode)
{
	DWORD dwResult = ::WaitForSingleObject(tProcessInfomation.hProcess, INFINITE);
	if (WAIT_FAILED == dwResult)
	{
		HRESULT hResult = HRESULT_FROM_WIN32(::GetLastError());
	}

	GetExitCodeProcess(tProcessInfomation.hProcess, &processRetCode);
	CloseHandle(tProcessInfomation.hProcess);
	CloseHandle(tProcessInfomation.hThread);
}

/// <summary>
/// プロセスの終了を待って閉じる(タイムアウトあり)
/// </summary>
/// <param name="tProcessInfomation"></param>
/// <param name="timeout"></param>
/// <param name="processRetCode"></param>
void waitProcessExit(PROCESS_INFORMATION& tProcessInfomation, DWORD timeout, DWORD& processRetCode)
{
	DWORD dwResult = ::WaitForSingleObject(tProcessInfomation.hProcess, timeout);
	if ((WAIT_FAILED == dwResult) || (WAIT_TIMEOUT == dwResult))
	{
		HWND handle = GetWindowHandle(tProcessInfomation.dwProcessId);
		if (handle != NULL)
		{
			::PostMessage(handle, WM_CLOSE, 0, 0);
		}
		dwResult = ::WaitForSingleObject(tProcessInfomation.hProcess, INFINITE);
	}

	GetExitCodeProcess(tProcessInfomation.hProcess, &processRetCode);
	CloseHandle(tProcessInfomation.hProcess);
	CloseHandle(tProcessInfomation.hThread);
}

/// <summary>
/// プロセスを閉じる
/// </summary>
/// <param name="tProcessInfomation"></param>
/// <param name="processRetCode"></param>
void CloseProcess(PROCESS_INFORMATION& tProcessInfomation, DWORD& processRetCode)
{
	HWND handle = GetWindowHandle(tProcessInfomation.dwProcessId);
	if (handle != NULL)
	{
		::PostMessage(handle, WM_CLOSE, 0, 0);
	}
	DWORD dwResult = ::WaitForSingleObject(tProcessInfomation.hProcess, INFINITE);
	if (WAIT_FAILED == dwResult)
	{
		HRESULT hResult = HRESULT_FROM_WIN32(::GetLastError());
	}
	GetExitCodeProcess(tProcessInfomation.hProcess, &processRetCode);
	CloseHandle(tProcessInfomation.hProcess);
	CloseHandle(tProcessInfomation.hThread);
}
