//
// Created by Nikita on 16.11.2020.
//

#include "ResourceManager/ResourceManager.h"
#include <Windows.h>
#include <ConsoleApi.h>
#include <Debug/Debug.h>
#include <FileSystem/FileSystem.h>

using namespace Framework::Helper;

int main() {
    Debug::Init(FileSystem::GetPathToExe(), true);

    ResourceManager::Init("folder");

    ResourceManager::Stop();

    return Debug::Stop();
}