#include <iostream>
#include "pch.h"

#pragma comment(lib,"my_tool_dll.lib")


int main(int argc, char** argv) {
    Readme();
    TempHum DHT11;
    Serial_Miku com1;
    cout << sub_Float(10.0, 8.2) << endl;
    if (!com1.openSpy("COM3", CBR_115200, NOPARITY, 8, ONESTOPBIT))
    {
        cout << "打开串口" << endl;
    }
    char dat[20];
    while (1) {
        com1.readData(dat,20);
        getTempHum(dat,&DHT11);
        cout<< dat<< endl;
        cout << DHT11.temp << endl;
        cout << DHT11.hum << endl;
        //memset(dat, '\0', sizeof(dat));
        Sleep(100);
    }
    return 0;
}