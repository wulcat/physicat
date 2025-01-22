//
// Created by Akira Mujawar on 21/01/25.
//

#ifndef MEOWENGINE_OPENGL_APP_MULTI_THREAD_HPP
#define MEOWENGINE_OPENGL_APP_MULTI_THREAD_HPP

#include "thread"
#include <string>

#include "graphics_wrapper.hpp"
#include "sdl_wrapper.hpp"
#include "log.hpp"

#include "opengl_render_system.hpp"
#include "imgui_renderer.hpp"

#include "opengl_framebuffer.hpp"
#include "opengl_asset_manager.hpp"
#include "input_manager.hpp"
#include "main_scene.hpp"

#include <frame_rate_counter.hpp>
#include "sdl_window.hpp"
#include "SDL_image.h"
#include "thread_barrier.hpp"
#include "queue"
#include "double_buffer.hpp"
#include "entt_reflection_wrapper.hpp"

#include "shared_thread_state.hpp"
#include "physics_multi_thread.hpp"
#include "opengl_render_multi_thread.hpp"


using namespace std;

namespace MeowEngine {
    class OpenGLAppMultiThread {
    public:
        OpenGLAppMultiThread();
//        ~OpenGLAppMultiThread();

        void CreateApplication();

    private:
        void Loop();
        bool Input(const float &deltaTime);

        std::unique_ptr<FrameRateCounter> MainThreadFrameRate;
        std::unique_ptr<MeowEngine::input::InputManager> InputManager; //

        MeowEngine::SharedThreadState SharedState;
        std::shared_ptr<MeowEngine::Scene> Scene;

        std::unique_ptr<MeowEngine::PhysicsMultiThread> PhysicThread;
        std::unique_ptr<MeowEngine::OpenGLRenderMultiThread> RenderThread;




    };
}

#endif //MEOWENGINE_OPENGL_APP_MULTI_THREAD_HPP

// physics system -> Physics
// render system -> Renderer

// PhysicsThread
// RenderThread

// Application
    // SingleThreadApplication -- selects the physics system
        // OpenGLApplicationSingleT
        // VulkanApplicationST
        // physics
            // PhysXPhysicsSingleThread
            // CustomPhysicsSingleT
    // MultiThreadApplication -- selects the physics thread which has physics system
        // opengl
            // OpenGLApplicationMultiT -- selects the correct render thread
            // OpenGLRenderMultiThread
        // vulkan
            // VulkanThreadApplication
            // VulkanRenderThread
        // physics
            // PhysXPhysicsThread
            // CustomPhysicsThread

// RenderSystem
    // OpenGL
    // Vulkan
// PhysicsSystem
    // PhysX
    // Custom