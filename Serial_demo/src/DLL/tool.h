#pragma once
#include "windows.h"
#include <string.h>
using namespace std;
#define __MIKU_TOOL_DLL__
#ifdef __MIKU_TOOL_DLL__
#define _TOOL_DLL_API __declspec(dllexport)
#else
#define _TOOL_DLL_API __declspec(dllimport)
#endif

#define _NAME "MIKU TOOLS"
#define _VERSION "V0.1"
using namespace std;

extern "C" _TOOL_DLL_API void Readme();

extern "C" _TOOL_DLL_API int add_Int(int, int);
extern "C" _TOOL_DLL_API float add_Float(float, float);
extern "C" _TOOL_DLL_API int sub_Int(int, int);
extern "C" _TOOL_DLL_API float sub_Float(float, float);

//DHT11 ½á¹¹Ìå
struct _TOOL_DLL_API TempHum
{
	float temp = 0;
	float hum = 0;
};

bool _TOOL_DLL_API getTempHum(char* cstr, TempHum* dht);

class _TOOL_DLL_API Serial_Miku {
private:
	HANDLE hCom;
	string last_err;
public:
	bool openSpy(string name, unsigned char baud_rate, unsigned char parity, unsigned char byte_size, unsigned char stop_bits);
	bool openSpy(string name);

	DWORD writeData(char* buffer, int length);
	DWORD readData(char* buffer, int length);
	void closeCom();
	bool isOpened();
	bool flushBuff();
};
