#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>

//#define _AFXDLL _AFXDLL_H_
//#include<afx.h>

#include "cast_utilities.h"


std::wstring string2Wstring(std::string str)
{
	std::wstring wStr(str.begin(), str.end());
	return wStr;
}


std::string wstring2String(std::wstring wStr)
{
	std::string str(wStr.begin(), wStr.end());
	return str;
}


//std::string CString2String(CString cStr)
//{
//	return (LPCTSTR)cStr;
//}


//CString string2CString(std::string str)
//{
//	return str.c_str();
//}


//CString wstring2CString(std::wstring wStr)
//{
//	return wStr.c_str();
//}


//std::wstring CString2Wstring(CString cStr)
//{
//	//in ANSI build
//	return CStringW(cStr);

//	//in Unicode build
//	return cStr;
//}


const char* charArray2constCharArray(char* cs)
{
	return cs;
}


//char* constCharArray2CharArray(const char* ccs)
//{
//	return _strdup(ccs);	//It's suitable for every enviroment
//	return strdup(ccs);		//Only suitable for Posix enviroment
//}


//wchar_t* charArray2WideCharArray(char* cs)
//{
//	size_t size = strlen(cs)  + 1;
//	wchar_t* wcs = new wchar_t[size]; //Remember to delete wcs in calling function,
//	mbstowcs(wcs, cs, size);		  //Otherwise there will be a memory leak.

//	return wcs;
//}


char* wideCharArray2CharArray(wchar_t* wcs)
{
	size_t size = wcslen(wcs);	//wcslen:get the length of wide character array

	char* cs = new char[size];  //Remember to delete wcs in calling function,
	wcstombs(cs, wcs, size);    //Otherwise there will be a memory leak.

	return cs;
}


std::string charArray2String(char* cs)
{
	return std::string(cs);
}


const char* string2ConstCharArray(std::string str)
{
	return str.c_str();
}


//char* string2CharArray(std::string str)
//{
//    char* cs = new char[str.length() + 1];
//    strcpy(cs, str.c_str());

//    return 0;
//}


std::wstring WideCharArray2WString(wchar_t* wcs)
{
	return std::wstring(wcs);
}


const wchar_t* wstring2ConstWideCharArray(std::wstring wStr)
{
	return wStr.c_str();
}


wchar_t* wstring2WideCharArray(std::wstring wStr)
{
	wchar_t* wcs = new wchar_t[wStr.length() + 1];
	wStr.copy(wcs, wStr.length());

	return wcs;
}


int charArray2Int1(char* cs)
{
	return atoi(cs);
}



int charArray2Int2(char* cs)
{
	int i;
	scanf(cs, "%d", i);

	return i;
}



int charArray2Int3(char* cs)
{
	return strtol(cs, NULL, 0); //Notion: this function cast char aray to long int
}


char* int2CharArray1(int i)
{
	char* cs;
	itoa(i, cs, 0); //the last parameter indicates the beginning position
	return cs;
}

char* int2CharArray2(int i)
{
	char* cs;
	sprintf(cs, "%d", i);
	return cs;
}



float charArray2Float1(char* cs)
{
	return atof(cs);
}



float charArray2Float2(char* cs)
{
	int f;
	scanf(cs, "%f", f);

	return f;
}


float charArray2Float3(char* cs)
{

	return strtod(cs, NULL); //Notion: this function cast char aray to double
}


char* Float2CharArray1(float f)
{
	char* cs;
	sprintf(cs, "%f", f);
	return cs;
}


int string2Int1(std::string str)
{
	std::stringstream ss(str);
	int i;
	ss >> i;

	return i;
}

int string2Int2(std::string str)
{
	std::istringstream iss(str);
	int i;
	iss >> i;

	return i;
}


std::string int2String1(int i)
{
	std::stringstream ss;
	std::string str;

	ss << i;
	ss >> str;

	return str;
}


std::string int2String2(int i)
{
	std::ostringstream os;

	os << i;
	return os.str();
}


//wide

int wstring2Int1(std::wstring wStr)
{
	std::wstringstream wss(wStr);
	int i;
	wss >> i;

	return i;
}

int wstring2Int2(std::wstring wStr)
{
	std::wistringstream wiss(wStr);
	int i;
	wiss >> i;

	return i;
}


std::wstring int2Wstring1(int i)
{
	std::wstringstream wss;
	std::wstring wStr;

	wss << i;
	wss >> wStr;

	return wStr;
}


std::wstring int2Wstring2(int i)
{
	std::wostringstream wos;

	wos << i;
	return wos.str();
}


//float 


float string2Float1(std::string str)
{
	std::stringstream ss(str);
	float f;
	ss >> f;

	return f;
}

float string2Float2(std::string str)
{
	std::istringstream iss(str);
	float f;
	iss >> f;

	return f;
}


std::string float2String1(float f)
{
	std::stringstream ss;
	std::string str;

	ss << f;
	ss >> str;

	return str;
}


std::string float2String2(float f)
{
	std::ostringstream os;

	os << f;
	return os.str();
}


//wide

float wstring2Float1(std::wstring wStr)
{
	std::wstringstream wss(wStr);
	float f;
	wss >> f;

	return f;
}

float wstring2Float2(std::wstring wStr)
{
	std::wistringstream wiss(wStr);
	float f;
	wiss >> f;

	return f;
}


std::wstring float2Wstring1(float f)
{
	std::wstringstream wss;
	std::wstring wStr;

	wss << f;
	wss >> wStr;

	return wStr;
}


std::wstring float2Wstring2(float f)
{
	std::wostringstream wos;

	wos << f;
	return wos.str();
}
