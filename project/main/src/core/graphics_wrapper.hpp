//
// Created by Akira Lynn on 06/07/22.
//

#ifndef VULKAN_ENGINE_GRAPHICS_WRAPPER_HPP
#define VULKAN_ENGINE_GRAPHICS_WRAPPER_HPP

#pragma once

#if defined(__EMSCRIPTEN__)
    #include "GLES2/gl2.h"
#elif defined(__APPLE__)
    //Ignore the OpenGL deprecation warnings.
    #define GL_SILENCE_DEPRECATION
    #include "TargetConditionals.h"

    #if TARGET_OS_IPHONE
        #include <OpenGLES/ES2/gl.h>
    #else
        #include <OpenGL/gl3.h>
    #endif
#elif __ANDROID__
    #include "GLES2/gl2.h"
#elif WIN32
    #define GLEW_STATIC
    #include <GL/glew.h>
#endif


class graphics_wrapper {

};


#endif //VULKAN_ENGINE_GRAPHICS_WRAPPER_HPP
