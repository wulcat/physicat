//
// Created by Akira Mujawar on 21/06/24.
//

#ifndef PHYSICAT_MAIN_SCENE_HPP
#define PHYSICAT_MAIN_SCENE_HPP

#include "internal_ptr.hpp"
#include "scene.hpp"
#include "window_size.hpp"

namespace physicat {
    struct MainScene : public physicat::Scene {
        MainScene(const physicat::WindowSize& frameSize);

        void OnWindowResized(const physicat::WindowSize& size) override;

        void Create(physicat::AssetManager& assetManager) override;
        void Input(const float &deltaTime, const physicat::input::InputManager& inputManager) override;
        void Update(const float& deltaTime) override;
        void Render(physicat::Renderer& renderer) override;

//        const std::vector<core::LifeObject*> GetLifeObjects() override;
        entt::registry* GetEntities() override;

    private:
        struct Internal;
        physicat::internal_ptr<Internal> InternalPointer;
    };
}


#endif //PHYSICAT_MAIN_SCENE_HPP
