//
// Created by Nikita on 16.11.2020.
//

#ifndef GAME_MEMORY_H
#define GAME_MEMORY_H

#include <iostream>
#include <string>
#include <Windows.h>
#include <thread>
#include <random>
#include <ostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <Psapi.h>

#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows


class Memory{
private:
    Memory() {};
    ~Memory() {};
public:
    static const long long GetUsedMemoryLoad() noexcept {
        PROCESS_MEMORY_COUNTERS pmc;
        BOOL result = GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
        if (result)
            return (long long)pmc.PeakWorkingSetSize;
        else
            return -1;
    }
};

#endif //GAME_MEMORY_H
