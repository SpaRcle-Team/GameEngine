//
// Created by Nikita on 16.11.2020.
//

#include <ResourceManager/IResource.h>

void Framework::Helper::IResource::AddUsePoint() {
    this->m_countUses++;
}

void Framework::Helper::IResource::RemoveUsePoint() {
    this->m_countUses--;
}

bool Framework::Helper::IResource::IsDestroy() const noexcept {
    return m_isDestroy;
}
