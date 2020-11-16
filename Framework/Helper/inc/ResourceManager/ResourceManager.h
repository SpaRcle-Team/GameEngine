//
// Created by Nikita on 16.11.2020.
//

#ifndef GAME_RESOURCEMANAGER_H
#define GAME_RESOURCEMANAGER_H

#include <string>
#include "IResource.h"
#include "Types/SafeArray.h"
#include <functional>
#include <map>

namespace Framework {
    namespace Helper {
        class ResourceManager {
        private:
            ResourceManager(){}
            ~ResourceManager(){}
        private:
            std::mutex                                                              m_mutex = std::mutex();

            inline static bool                                                      g_isInit = false;
            inline static std::string                                               g_resource_folder = "None";
        private:
            inline static SafeArray<IResource*>                                     g_resources_to_destroy = SafeArray<IResource*>();

            inline static std::map<const char*, std::function<void(IResource*)>>    m_destroy_functions = std::map<const char*, std::function<void(IResource*)>>();
        public:
            static bool Init(std::string resource_folder);
        public:
            bool RegisterType(IResource* resource, std::function<void(IResource*)> destructor);

            IResource *Load(const char *name, const char *type) { return nullptr; }

            static void Stop();
        };
    }
}

#endif //GAME_RESOURCEMANAGER_H
