//
// Created by Nikita on 16.11.2020.
//

#ifndef GAME_IRESOURCE_H
#define GAME_IRESOURCE_H

namespace Framework {
    namespace Helper {
        class IResource {
        protected:
            IResource(){}
            ~IResource(){}
        protected:
            bool            m_isDestroy     = false;
            unsigned long   m_countUses     = 0;
        public:
            void AddUsePoint();
            void RemoveUsePoint();
        public:
            bool virtual Destroy() = 0;
            bool IsDestroy() const noexcept;
        };
    }
}

#endif //GAME_IRESOURCE_H
