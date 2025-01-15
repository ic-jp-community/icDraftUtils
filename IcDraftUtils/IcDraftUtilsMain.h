#pragma once
#include <vector>
#define SET_DEFAULT_DPI_VALUE  400
#define DEF_EXT  _T("*.dwg")
#define FILTER   _T("DWGファイル(*.dwg)|*.dwg|すべてのファイル(*.*)|*.*")
void IcDraftUtilsSetting();
void IcAutoUpdateClicker();
void getIcVersion(CString& version);
void IcDraftUtilsMain();
bool getSelectFiles(CString setFilesPath, vector<CString>& files);
void waitInfiniteProcessExit(PROCESS_INFORMATION& tProcessInfomation, DWORD& processRetCode);
void waitProcessExit(PROCESS_INFORMATION& tProcessInfomation, DWORD timeout, DWORD& processRetCode);
void CloseProcess(PROCESS_INFORMATION& tProcessInfomation, DWORD& processRetCode);
bool FolderSelectDialog(CString& saveFilePath);
LPWSTR ConvertToUnicode(CString cString);
