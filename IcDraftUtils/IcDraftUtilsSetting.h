#pragma once
#include "tinyxml2.h"
#include <atlstr.h>

typedef struct PdfParam_t
{
	bool isCreate;
	bool multiPageOneFile;
	int width;
	int height;
	int dpi;
	bool rgbColor;
}PdfParam_t;

typedef struct TifParam_t
{
	bool isCreate;
	bool multiPageOneFile;
	int width;
	int height;
	int dpi;
	bool rgbColor;
}TifParam_t;

typedef struct JpgParam_t
{
	bool isCreate;
	int width;
	int height;
	int dpi;
	bool rgbColor;
}JpgParam_t;

typedef struct ConvertConfig_t
{
	PdfParam_t pdf;
	TifParam_t tif;
	JpgParam_t jpg;
}ConvertConfig_t;

typedef struct AutoConvertConfig_t
{
	bool AutoStartAutoConvertWhenAppStart;
	int CheckIntervalMs;
	CString CheckDirectory;
	bool CheckRequestFile;
	ConvertConfig_t ConvertConfig;
}AutoConvertConfig_t;

class IcDraftUtilsSetting {
public:
	static bool GetCommonConfigFilePath(TCHAR* szPath);
private:
	static bool getBoolValue(char* pChar);
	static int getIntValue(char* pChar);
	static bool getElementAutoStartAutoConvertWhenAppStart(tinyxml2::XMLElement* elem);
	static int getElementCheckIntervalMs(tinyxml2::XMLElement* elem);
	static void getElementCheckDirectory(tinyxml2::XMLElement* elem, CString& value);
	static bool getElementCheckRequestFile(tinyxml2::XMLElement* elem);
	static bool getElementIsCreate(tinyxml2::XMLElement* elem);
	static int getElementWidth(tinyxml2::XMLElement* elem);
	static int getElementHeight(tinyxml2::XMLElement* elem);
	static int getElementDpi(tinyxml2::XMLElement* elem);
	static bool getElementRgbColor(tinyxml2::XMLElement* elem);
	static bool getElementMultiPageOneFile(tinyxml2::XMLElement* elem);
};

#pragma once
