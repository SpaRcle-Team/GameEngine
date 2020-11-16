//
// Created by Nikita on 16.11.2020.
//

#ifndef GAME_RESOURCEMANAGER_H
#define GAME_RESOURCEMANAGER_H

#include <string>
#include "IResource.h"
#include "Types/SafeArray.h"

namespace Framework {
    namespace Helper {
        class ResourceManager {
        private:
            ResourceManager(){}
            ~ResourceManager(){}
        private:
            inline static bool g_isInit = false;
            inline static std::string g_resource_folder = "None";
        private:
            inline static SafeArray<IResource*> g_resources_to_destroy = SafeArray<IResource*>();
        public:
            static bool Init(std::string resource_folder);
        public:
            IResource *Load(const char *name, const char *type){ return nullptr; }
        };
    }
}

#endif //GAME_RESOURCEMANAGER_H
