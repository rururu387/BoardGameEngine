// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

// MathLibrary.cpp : Defines the exported functions for the DLL.
#include <iostream>
#include <string>
#include "../Basic Dependencies/Basic.h"
#include "testDll.h"

void helloWorld()
{
    std::cout << "Hello, world!\n";
}

A::A(int _variable, double _value) : Basic(_variable)
{
    value = _value;
}

std::string A::print()
{ 
    return "Value: " + std::to_string(value) + " Variable: " + std::to_string(variable);
};