//
// Created by Akira Lynn on 08/09/22.
//

#ifndef PHYSICAT_VERTEX_HPP
#define PHYSICAT_VERTEX_HPP

#include "glm_wrapper.hpp"

namespace physicat {
    struct Vertex {
        glm::vec3 Position;
        glm::vec2 TextureCoord;

        bool operator==(const physicat::Vertex& other) const;
    };
} // namespace physicat

namespace std {
    // takes hash of position and texture coordinate
    // performs XOR while shifting bits of the texture coordinate left
    // what the heck is this lol... ufff
    // this gives a unique hash for our Vertex
    template <>
    struct hash<physicat::Vertex> {
        size_t operator()(const physicat::Vertex& vertex) const {
            return (
                    (hash<glm::vec3>()(vertex.Position) ^
                     (hash<glm::vec2>()(vertex.TextureCoord) << 1))
                            >> 1
            );
        }
    };
}

#endif //PHYSICAT_VERTEX_HPP
