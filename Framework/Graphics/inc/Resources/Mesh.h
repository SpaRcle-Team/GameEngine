//
// Created by Nikita on 16.11.2020.
//

#ifndef GAME_MESH_H
#define GAME_MESH_H

#include <string>
#include "Vertex.h"
#include <vector>

namespace Framework {
    namespace Graphics {
        class Mesh {
        private:
            Mesh() {}
            ~Mesh() {}
        private:
            std::vector<Vertex> m_vertices = std::vector<Vertex>();
        public:
            static Mesh *Load(std::string name);
        };
    }
}

#endif //GAME_MESH_H
