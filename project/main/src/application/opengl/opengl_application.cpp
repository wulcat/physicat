//
// Created by Akira Lynn on 06/07/22.
//

#include "opengl_application.h"

#include "../../core/graphics_wrapper.hpp"
#include "../../core/log.hpp"
#include "../../core/sdl_wrapper.hpp"

#include <string>

using physicat::OpenGLApplication;

namespace {
    SDL_GLContext CreateContext(SDL_Window* window) {
        static const std::string logTag("physicat::OpenGLApplication::CreateContext");

        SDL_GLContext context {SDL_GL_CreateContext(window)};

        #ifdef WIN32
            glewInit();
        #endif

        int viewportWidth;
        int viewportHeight;
        SDL_GL_GetDrawableSize(window, &viewportWidth, &viewportHeight);

        physicat::log(logTag, "Created OpenGL Context with viewport size: " + std::to_string(viewportWidth) + " , " + std::to_string(viewportHeight) );

        glClearDepthf(1.0f);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);
        glEnable(GL_CULL_FACE);
        glViewport(0, 0, viewportWidth, viewportHeight);

        return context;
    }
} // namespace

struct OpenGLApplication::Internal {
    SDL_Window* window;
    SDL_GLContext context;

    Internal() :
        window(physicat::sdl::CreateWindow(SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL | SDL_WINDOW_ALLOW_HIGHDPI)),
        context(CreateContext(window))
    {}

    ~Internal() {
        SDL_GL_DeleteContext(context);
        SDL_DestroyWindow(window);
    }

    void Render() const {
        SDL_GL_MakeCurrent(window, context);

        glClearColor(0.3f, 0.7f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        SDL_GL_SwapWindow(window);
    }
};

OpenGLApplication::OpenGLApplication() :
    internal(physicat::make_internal_ptr<Internal>())
{}

void OpenGLApplication::Render() {
    internal->Render();
}





















