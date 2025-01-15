#pragma once
#include <vector>
#define MAX_PATH_LENGTH 512
void getDocumentFolder(TCHAR* waFolderPath);
void getWorkFolder(CString& workFolderPath);
void getIcDraftUtilsInstallPath(CString& installPath);
LPWSTR ConvertToUnicode(CString cString);
void getIcDraftAutoClickerFilePath(CString& prgPath);
void getSystemTimeString(CString& st_datetime);

class FileClass {
	public:	
		static void FileClass::GetFileName(const CString& path, CString& fileName);
		static void GetFileNameWithoutExtension(const CString& path, CString& fileName);
		static void FileClass::GetDirectoryPath(const CString& path, CString& dirPath);
		static void FileClass::GetExtension(const CString& path, CString& ext);
		static bool FileClass::GetDirectoryFiles(CString folderPath, std::vector<CString>& file_names);
};

