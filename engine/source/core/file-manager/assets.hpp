//
// Created by Akira Lynn on 11/09/22.
//

#ifndef PHYSICAT_ASSETS_HPP
#define PHYSICAT_ASSETS_HPP

#include "mesh.hpp"
#include <string>
#include "bitmap.hpp"

namespace physicat::assets {
    std::string LoadTextFile(const std::string& path);
    physicat::Mesh LoadObjFile(const std::string& path);
    physicat::Bitmap LoadBitmap(const std::string& path);
} // namespace physicat::assets;

#endif //PHYSICAT_ASSETS_HPP
