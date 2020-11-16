//
// Created by Nikita on 16.11.2020.
//

#ifndef GAME_SAFEDICTIONARY_H
#define GAME_SAFEDICTIONARY_H

#include <map>

namespace Framework {
    namespace Helper {
        template<typename K, typename T>
        class SafeDictionary {
        private:
            std::map<K, T, std::less<K>, std::allocator<std::pair<const K, T>>> m_elements;
            std::mutex m_lock;
        public:
            T& operator[](K key) {
                m_lock.lock();
                T &val = m_elements[key];
                m_lock.unlock();
                return val;
            }

            void Add(K key, T element) {
                m_lock.lock();
                m_elements.insert(std::make_pair(key, element));
                m_lock.unlock();
            }
        };
    }
}

#endif //GAME_SAFEDICTIONARY_H
