// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#ifndef PCH_H
#define PCH_H

// TODO: add headers that you want to pre-compile here

#include <iostream>
//#include <cstdio>
#include <string>
#include <Windows.h>
#include <tchar.h>

// Including SDKDDKVer.h defines the highest available Windows platform.
// If you wish to build your application for a previous Windows platform, include WinSDKVer.h and
// set the _WIN32_WINNT macro to the platform you wish to support before including SDKDDKVer.h.
#include <SDKDDKVer.h>

#if defined(UNICODE) || defined(_UNICODE)
#define _tcout std::wcout
#define _tcin std::wcin
#else
#define _tcout std::cout
#define _tcout std::cin
#endif

typedef std::basic_string<TCHAR*> _tstring;

#endif PCH_H
