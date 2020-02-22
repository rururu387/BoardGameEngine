// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include <any>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include "../Basic Dependencies/CorrectStreamInput.h"
#include "../Basic Dependencies/Square.h"
#include "../Basic Dependencies/Field.h"
#include "../Basic Dependencies/Piece.h"
#include "../Basic Dependencies/Step.h"
#include "../Basic Dependencies/Position.h"
#include "Draught.h"
#include "DraughtInteract.h"
#include "Draught.h"
#include "DraughtInteract.h"

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

