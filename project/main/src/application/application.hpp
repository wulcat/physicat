//
// Created by Akira Lynn on 06/07/22.
//

#ifndef VULKAN_ENGINE_ENGINE_HPP
#define VULKAN_ENGINE_ENGINE_HPP

#pragma once

#include <internal_ptr.hpp>
#include "../core/includes.hpp"

namespace physicat {
    struct Application {
        Application();
        virtual ~Application() = default;

        void StartApplication();
        bool LoopApplication();

        virtual void Update(const float& deltaTime) = 0;
        virtual void Render() = 0;

    private:
        struct Internal;
        physicat::internal_ptr<Internal> InternalPointer;
    };
} // namespace physicat


#endif //VULKAN_ENGINE_ENGINE_HPP
