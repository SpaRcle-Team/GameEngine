//
// Created by Nikita on 16.11.2020.
//

#include "ResourceManager/ResourceManager.h"

bool Framework::Helper::ResourceManager::Init(std::string resource_folder) {
    g_resource_folder = resource_folder;
    g_isInit = true;
    return false;
}

bool Framework::Helper::ResourceManager::RegisterType(Framework::Helper::IResource *resource,
                                                      std::function<void(IResource *)> destructor) {
    return false;
}

void Framework::Helper::ResourceManager::Stop() {

}
