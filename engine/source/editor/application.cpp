//
// Created by Akira Mujawar on 06/07/22.
//

#include "sdl_wrapper.hpp"
#include "application.hpp"

#include "imgui_wrapper.hpp"
#include "log.hpp"

using physicat::Application;

namespace {
    #ifdef EMSCRIPTEN
        // Free Function in an anonymous namespace private to this file
        void EmscriptenLoop(physicat::Application* engine) {
            engine->LoopApplication();
        }
    #endif
} // namespace

struct Application::Internal {
    const float FramePerSecond; // PerformanceFrequency
    uint64_t CurrentFrameTime;
    uint64_t PreviousFrameTime;

    Internal()
        : FramePerSecond(static_cast<float>(SDL_GetPerformanceFrequency()))
        , CurrentFrameTime(SDL_GetPerformanceCounter())
        , PreviousFrameTime(CurrentFrameTime) {}

    float TimeStep() {
        PT_PROFILE_SCOPE;
        PreviousFrameTime = CurrentFrameTime;
        CurrentFrameTime = SDL_GetPerformanceCounter();

        float elapsedTime {
            (CurrentFrameTime - PreviousFrameTime) * 1000.0f
        };

        return (elapsedTime / FramePerSecond) * 0.001f;
    }
};

void physicat::Application::StartApplication() {
    PT_PROFILE_SCOPE;
    physicat::Log("physicat::Application::StartApplication", "Starting Application");

    #ifdef __EMSCRIPTEN__
        //  emscripten_set_main_loop(emscriptenLoop, 60, 1);
        emscripten_set_main_loop_arg((em_arg_callback_func) ::EmscriptenLoop, this, 60, 1);
    #else
        while (LoopApplication())
        {
            // Just waiting for the main loop to end.
        }
    #endif
}

bool physicat::Application::LoopApplication() {
    PT_PROFILE_SCOPE_N("Engine Update");

    float deltaTime = InternalPointer->TimeStep();

    // If Input() returns false - close the application
    if(!Input(deltaTime)) {
        return false;
    }

    Update(deltaTime);

    // Perform our rendering for this frame, normally you would also perform
    // any updates to your world as well here.
    Render();

    // Returning true means we want to keep looping.
    return true;
}

Application::Application()
    : InternalPointer(physicat::make_internal_ptr<Internal>()){}
