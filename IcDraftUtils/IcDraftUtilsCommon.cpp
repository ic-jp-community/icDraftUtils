#include <math.h>
#include "stdafx.h"
#include "IcDraftUtilsCommon.h"
#include <iostream>
#include <vector>

/// <summary>
/// ���[�U�[��Document�t�H���_�̃p�X���擾����
/// </summary>
/// <param name="waFolderPath"></param>
void getDocumentFolder(TCHAR* waFolderPath)
{
	SHGetSpecialFolderPath(NULL, waFolderPath, CSIDL_PERSONAL, 0);
}

/// <summary>
/// ��ƃt�H���_�̃p�X���擾����
/// </summary>
/// <param name="workFolderPath"></param>
void getWorkFolder(CString& workFolderPath)
{
	TCHAR docFolderPath[MAX_PATH_LENGTH];
	getDocumentFolder(docFolderPath);
	workFolderPath.Format(_T("%s\\%s"), docFolderPath, _T("icDraftUtils"));
}


/// <summary>
/// IcDraftUtils�̃C���X�g�[���p�X���擾����
/// </summary>
/// <param name="keyName"></param>
/// <param name="appPathList"></param>
void getIcDraftUtilsInstallPath(CString& installPath)
{
	const CString REG_SW_GROUP_I_WANT = _T("SOFTWARE\\IRONCAD JP Community\\IcDraftUtils");
	const CString REG_KEY_I_WANT = _T("AppPath");

	CRegKey regKey;
	DWORD   dwValue = 0;
	TCHAR szInstallPath[512] = _T("");
	ULONG buffSize = _countof(szInstallPath);

	if (ERROR_SUCCESS != regKey.Open(HKEY_LOCAL_MACHINE, REG_SW_GROUP_I_WANT, KEY_READ))
	{
		regKey.Close();
	}
	else if (ERROR_SUCCESS != regKey.QueryStringValue(REG_KEY_I_WANT, szInstallPath, &buffSize))
	{
		regKey.Close();
	}
	else
	{
	}

	regKey.Close();
	installPath.Format(_T("%s"), szInstallPath);
	return;
}

/// <summary>
/// Unicode�ɕϊ�����
/// </summary>
/// <param name="cString"></param>
/// <returns></returns>
LPWSTR ConvertToUnicode(CString cString)
{
	int nBufSize = cString.GetLength() + 1;
	LPWSTR lpws = new wchar_t[nBufSize];

	if (lpws != NULL)
	{
#if defined(_UNICODE)
		lstrcpy(lpws, cString);
#else
		MultiByteToWideChar(CP_ACP, 0, cString, nBufSize, lpws, nBufSize * 2);
#endif
	}

	return lpws;
}

/// <summary>
/// IcDraftAutoClicker�̎��s�p�X���擾����
/// </summary>
/// <param name="fullPath"></param>
void getIcDraftAutoClickerFilePath(CString& fullPath)
{
	CString InstallPath;
	CString IcDraftAutoClickerFileName;
	getIcDraftUtilsInstallPath(InstallPath);
	IcDraftAutoClickerFileName.Format(_T("%s"), _T("IcDraftAutoClicker.exe"));
	fullPath.Format(_T("%s%s"), InstallPath, IcDraftAutoClickerFileName);
	return;
}

/// <summary>
/// ���t(SYSTEMTIME)�𕶎���(CString)�ɕϊ�
/// </summary>
/// <returns></returns>
void getSystemTimeString(CString& st_datetime)
{
	SYSTEMTIME systime;
	GetLocalTime(&systime);
	CString sysDate;
	CString sysTime;
	sysDate.Format(_T("%04d%02d%02d"), systime.wYear, systime.wMonth, systime.wDay);
	sysTime.Format(_T("%02d%02d%02d"), systime.wHour, systime.wMinute, systime.wSecond);

	st_datetime.Format(_T("%s%s"), sysDate, sysTime);
	return;
}


/// <summary>
/// �t�@�C�������擾����(�p�X�E�g���q����)
/// </summary>
/// <param name="path"></param>
/// <returns></returns>
void FileClass::GetFileName(const CString& path, CString& fileName)
{
	CString filename;
	size_t path_i = path.ReverseFind('\\') + 1;
	size_t ext_i = path.ReverseFind('.');
	if (ext_i != string::npos)
	{
		fileName.Format(_T("%s"), path.Mid(path_i, path.GetLength() - path_i));
	}

	return;
}

/// <summary>
/// �t�@�C�������擾����(�p�X�E�g���q�Ȃ�)
/// </summary>
/// <param name="path"></param>
/// <returns></returns>
void FileClass::GetFileNameWithoutExtension(const CString& path, CString& fileName)
{
	size_t path_i = path.ReverseFind('\\') + 1;
	size_t ext_i = path.ReverseFind('.');
	if (ext_i != string::npos)
	{
		fileName.Format(_T("%s"), path.Mid(path_i, ext_i - path_i));
	}

	return;
}


/// <summary>
/// �f�B���N�g�����擾����(�t�@�C���p�X�Ȃ�)
/// </summary>
/// <param name="path"></param>
/// <returns></returns>
void FileClass::GetDirectoryPath(const CString& path, CString& dirPath)
{
	size_t path_i = path.ReverseFind('\\');
	if (path_i != string::npos)
	{
		dirPath.Format(_T("%s"), path.Mid(0, path_i));
	}

	return;
}


/// <summary>
/// �t�@�C���̊g���q���擾����
/// </summary>
/// <param name="path"></param>
/// <returns></returns>
void FileClass::GetExtension(const CString& path, CString& ext)
{
	size_t pos1 = path.ReverseFind('.');
	if (pos1 != string::npos) {
		ext.Format(_T("%s"), path.Mid(pos1 + 1, path.GetLength() - pos1));
	}

	return;
}

bool FileClass::GetDirectoryFiles(CString folderPath, std::vector<CString>& file_names)
{
	HANDLE hFind;
	WIN32_FIND_DATA win32fd;
	CString search_name;
	search_name.Format(_T("%s\*"),folderPath);

	hFind = FindFirstFile(search_name, &win32fd);

	if (hFind == INVALID_HANDLE_VALUE) {
		throw std::runtime_error("file not found");
		return false;
	}

	/* �w��̃f�B���N�g���ȉ��̃t�@�C�������t�@�C�����Ȃ��Ȃ�܂Ŏ擾���� */
	do {
		if (win32fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			/* �f�B���N�g���̏ꍇ�͉������Ȃ� */
		//	printf("directory\n");
		}
		else {
			CString filePath;
			CString fileName;
			CString extName;
			fileName.Format(_T("%s"), win32fd.cFileName);
			int ext_i = fileName.ReverseFind(_T('.'));//10
			extName.Format(_T("%s"), fileName.Mid(ext_i, fileName.GetLength() - ext_i));
			if (extName.MakeLower() == _T(".exb"))
			{
				/* �t�@�C��������������Vector�z��ɕۑ����� */
				filePath.Format(_T("%s\%s"), folderPath, fileName);
				file_names.push_back(filePath);
			}
		}
	} while (FindNextFile(hFind, &win32fd));

	FindClose(hFind);

	return true;
}
