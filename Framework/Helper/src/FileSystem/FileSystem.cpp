//
// Created by Nikita on 16.11.2020.
//

#include "FileSystem/FileSystem.h"

const std::string Framework::Helper::FileSystem::GetPathToExe() {
    TCHAR cwd[100];
    GetCurrentDirectory(100, cwd);
    std::wstring ws(reinterpret_cast<const wchar_t *const>(&cwd[0]));
    return std::string(ws.begin(), ws.end());
}
