#include <iostream>
#include <fstream>
#include <vector>
#include <tchar.h>
#include <shlwapi.h>
#pragma comment(lib,"shlwapi.lib")
#include "shlobj.h"
#include "IcDraftUtilsSetting.h"
#include "IcDraftUtilsCommon.h"
using namespace std;


/// <summary>
/// 共通のコンフィグファイルのパスを取得する
/// </summary>
/// <returns></returns>
bool IcDraftUtilsSetting::GetCommonConfigFilePath(TCHAR* szPath)
{
	/* ProgramDataのパスを取得 */
	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, 0, szPath)) != true)
	{
		return false;
	}
	PathAppend(szPath, _T("IRONCAD JP Community\IcDraftUtils\\IcDraftUtilsCommon.config"));

	return true;
}


/// <summary>
/// 文字列からbool値を取得する
/// </summary>
/// <param name="pChar"></param>
/// <returns></returns>
bool IcDraftUtilsSetting::getBoolValue(char* pChar)
{
	char* p = &pChar[0];
	while (*p) {
		*p = tolower(*p);
		p++;
	}
	if (strcmp(pChar, "true") == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/// <summary>
/// 
/// </summary>
/// <param name="pChar"></param>
/// <returns></returns>
int IcDraftUtilsSetting::getIntValue(char* pChar)
{
	int value = atoi(pChar);
	return value;
}

/// <summary>
/// 
/// </summary>
/// <param name="elem"></param>
/// <returns></returns>
bool IcDraftUtilsSetting::getElementAutoStartAutoConvertWhenAppStart(tinyxml2::XMLElement* elem)
{
	tinyxml2::XMLElement* element = elem->FirstChildElement("AutoStartAutoConvertWhenAppStart");
	if (element == NULL)
	{
		return false;
	}
	else
	{
		return getBoolValue((char*)element->GetText());
	}
}


/// <summary>
/// 
/// </summary>
/// <param name="elem"></param>
/// <returns></returns>
int IcDraftUtilsSetting::getElementCheckIntervalMs(tinyxml2::XMLElement* elem)
{
	tinyxml2::XMLElement* element = elem->FirstChildElement("CheckIntervalMs");
	if (element == NULL)
	{
		return 0;
	}
	else
	{
		return getIntValue((char*)element->GetText());
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="elem"></param>
/// <returns></returns>
void IcDraftUtilsSetting::getElementCheckDirectory(tinyxml2::XMLElement* elem, CString& value)
{
	tinyxml2::XMLElement* element = elem->FirstChildElement("CheckDirectory");
	if (element == NULL)
	{
		value.Empty();
		return;
	}
	value.Format(_T("%s"),(char*)element->GetText());
	return;
}

/// <summary>
/// 
/// </summary>
/// <param name="elem"></param>
/// <returns></returns>
bool IcDraftUtilsSetting::getElementCheckRequestFile(tinyxml2::XMLElement* elem)
{
	tinyxml2::XMLElement* element = elem->FirstChildElement("CheckRequestFile");
	if (element == NULL)
	{
		return false;
	}
	else
	{
		return getBoolValue((char*)element->GetText());
	}

}
/// <summary>
/// 
/// </summary>
/// <param name="elem"></param>
/// <returns></returns>
bool IcDraftUtilsSetting::getElementIsCreate(tinyxml2::XMLElement* elem)
{
	tinyxml2::XMLElement* element_isCreate = elem->FirstChildElement("isCreate");
	if (element_isCreate == NULL)
	{
		return false;
	}
	else
	{
		return getBoolValue((char*)element_isCreate->GetText());
	}
}


/// <summary>
/// 
/// </summary>
/// <param name="elem"></param>
/// <returns></returns>
int IcDraftUtilsSetting::getElementWidth(tinyxml2::XMLElement* elem)
{
	tinyxml2::XMLElement* element_Width = elem->FirstChildElement("width");
	if (element_Width == NULL)
	{
		return 0;
	}
	else
	{
		return getIntValue((char*)element_Width->GetText());
	}
}


/// <summary>
/// 
/// </summary>
/// <param name="elem"></param>
/// <returns></returns>
int IcDraftUtilsSetting::getElementHeight(tinyxml2::XMLElement* elem)
{
	tinyxml2::XMLElement* element_Height = elem->FirstChildElement("height");
	if (element_Height == NULL)
	{
		return 0;
	}
	else
	{
		return getIntValue((char*)element_Height->GetText());
	}
}


/// <summary>
/// 
/// </summary>
/// <param name="elem"></param>
/// <returns></returns>
int IcDraftUtilsSetting::getElementDpi(tinyxml2::XMLElement* elem)
{
	tinyxml2::XMLElement* element_Dpi = elem->FirstChildElement("dpi");
	if (element_Dpi == NULL)
	{
		return 0;
	}
	else
	{
		return getIntValue((char*)element_Dpi->GetText());
	}
}


/// <summary>
/// 
/// </summary>
/// <param name="elem"></param>
/// <returns></returns>
bool IcDraftUtilsSetting::getElementRgbColor(tinyxml2::XMLElement* elem)
{
	tinyxml2::XMLElement* element_RgbColor = elem->FirstChildElement("rgbColor");
	if (element_RgbColor == NULL)
	{
		return false;
	}
	else
	{
		return getBoolValue((char*)element_RgbColor->GetText());
	}
}


/// <summary>
/// 
/// </summary>
/// <param name="elem"></param>
/// <returns></returns>
bool IcDraftUtilsSetting::getElementMultiPageOneFile(tinyxml2::XMLElement* elem)
{
	tinyxml2::XMLElement* element_MultiPageOneFile = elem->FirstChildElement("multiPageOneFile");
	if (element_MultiPageOneFile == NULL)
	{
		return true;
	}
	else
	{
		return getBoolValue((char*)element_MultiPageOneFile->GetText());
	}
}

