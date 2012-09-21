// VCDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"

//所需接口声明
int  (WINAPI *g_lpInitClassifier)(const wchar_t* lpTemplates, const wchar_t* lpFilters);
void (WINAPI *g_lpFreeClassifier)();
int  (WINAPI *g_lpClassifyImageFile)(const wchar_t* lpImageName, int templateIndex);
int  (WINAPI *g_lpGetTemplateName)(wchar_t* lpTemplateName, int nTemplateNameLen) ;
//
int main(int argc, char* argv[])
{
	HINSTANCE hInst = ::LoadLibrary("GeneralClassifier.dll");
	if (hInst == NULL)
		return -1;
	//
	(FARPROC &)g_lpInitClassifier    = ::GetProcAddress(hInst, "InitClassifier");
	(FARPROC &)g_lpFreeClassifier    = ::GetProcAddress(hInst, "FreeClassifier");
	(FARPROC &)g_lpClassifyImageFile = ::GetProcAddress(hInst, "ClassifyImageFile");
	(FARPROC &)g_lpGetTemplateName   = ::GetProcAddress(hInst, "GetTemplateName");
	
	if (g_lpInitClassifier == NULL || g_lpFreeClassifier == NULL ||
		g_lpClassifyImageFile == NULL || g_lpGetTemplateName == NULL)
		return -2;

	//Step 1: 初始化识别核心
	if (0 != g_lpInitClassifier(L"c:\\modlist.mod", NULL))
		return -3;
	
	//Step 2: 影像分类
	if (0 != g_lpClassifyImageFile(L"c:\\temp1.jpg", 0))
		return -4;

	wchar_t szModName[MAX_PATH] = {0};
	if (0 != g_lpGetTemplateName(szModName, MAX_PATH))
		return -5;

	//Step 3: 释放内存
	g_lpFreeClassifier();

	::FreeLibrary(hInst);
	return 0;
}

