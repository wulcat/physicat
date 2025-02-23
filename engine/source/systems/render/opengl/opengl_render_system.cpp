//
// Created by Akira Mujawar on 21/06/24.
//

#include "opengl_render_system.hpp"


#include "opengl_mesh_pipeline.hpp"
#include "opengl_line_pipeline.hpp"
#include "opengl_grid_pipeline.hpp"
#include "opengl_sky_box_pipeline.hpp"
#include "opengl_collider_pipeline.hpp"

using MeowEngine::OpenGLRenderSystem;

using namespace MeowEngine::pipeline;
using namespace MeowEngine::entity;

using MeowEngine::assets::ShaderPipelineType;

struct OpenGLRenderSystem::Internal {
    const std::shared_ptr<MeowEngine::OpenGLAssetManager> AssetManager;
    const std::shared_ptr<MeowEngine::graphics::ImGuiUserInterfaceSystem> UI;

    Internal(std::shared_ptr<MeowEngine::OpenGLAssetManager> assetManager,
             std::shared_ptr<MeowEngine::graphics::ImGuiUserInterfaceSystem> inUIRenderer)
    : AssetManager(assetManager)
    , UI(inUIRenderer){}

//    void Render(MeowEngine::PerspectiveCamera* cameraObject, MeowEngine::core::LifeObject* lifeObject) {
//
////        AssetManager->GetShaderPipeline(shaderPipelineType).Render(
////                *AssetManager,
////                staticMeshInstances,
////                lineDraw
////        );
//
//        RenderComponentBase* renderComponent = lifeObject->RenderComponent;
//
//        switch (renderComponent->GetShaderPipelineType()) {
//            case ShaderPipelineType::Default:
////                AssetManager->GetShaderPipeline<OpenGLMeshPipeline>(ShaderPipelineType::Default)->Render(
////                    *AssetManager,
////                    dynamic_cast<MeshRenderComponent*>(renderComponent),
////                    dynamic_cast<MeowEngine::entity::Transform3dComponent*>(lifeObject->TransformComponent)
////                );
//                break;
//            case ShaderPipelineType::Line:
//                AssetManager->GetShaderPipeline<OpenGLLinePipeline>(ShaderPipelineType::Line)->Render(
//                    *AssetManager,
//                    dynamic_cast<LineRenderComponent*>(renderComponent),
//                    dynamic_cast<MeowEngine::core::component::Transform3DComponent*>(lifeObject->TransformComponent),
//                    cameraObject
//                );
//                break;
//            case ShaderPipelineType::Grid:
//                AssetManager->GetShaderPipeline<OpenGLGridPipeline>(ShaderPipelineType::Grid)->Render(
//                        *AssetManager,
//                        renderComponent,
//                        dynamic_cast<MeowEngine::core::component::Transform3DComponent*>(lifeObject->TransformComponent),
//                        cameraObject
//                );
//                break;
//        }
//    }

    void RenderGameView(MeowEngine::PerspectiveCamera* cameraObject, entt::registry& registry)
    {
//        auto view = registry.view<MeowEngine::core::component::Transform3DComponent>();
//        for(auto entity: view)
//        {
//            auto transform = view.get<MeowEngine::core::component::Transform3DComponent>(entity);
//
//        }

//        auto view = registry.view<entity::Transform3dComponent>();
//        registry.view<MeowEngine::entity::Transform3dComponent>().each([](auto entity, auto &MeowEngine::entity::Transform3dComponent) {
//            // ...
//        });
//
//        for(auto &&[entt::entity, MeowEngine::entity::Transform3dComponent]: registry.view<entity::Transform3dComponent>().each()) {
//            // ...
//        }
        for(auto &&[entity,renderComponent, transform]: registry.view<entity::MeshRenderComponent, entity::Transform3DComponent>().each())
        {
            AssetManager->GetShaderPipeline<OpenGLMeshPipeline>(ShaderPipelineType::Default)->Render(
                    *AssetManager,
                    &renderComponent,
                    &transform
            );
        }

        for(auto &&[entity,renderComponent, transform]: registry.view<entity::RenderComponentBase, entity::Transform3DComponent>().each())
        {

                AssetManager->GetShaderPipeline<OpenGLGridPipeline>(ShaderPipelineType::Grid)->Render(
                        *AssetManager,
                        &renderComponent,
                        &transform,
                        cameraObject
                );

        }

        for(auto &&[entity,renderComponent, transform]: registry.view<entity::SkyBoxComponent, entity::Transform3DComponent>().each())
        {

                AssetManager->GetShaderPipeline<OpenGLSkyBoxPipeline>(ShaderPipelineType::Sky)->Render(
                        *AssetManager,
                        &renderComponent,
                        &transform,
                        cameraObject
                );


        }
    }

    void RenderUserInterface(entt::registry& registry, std::queue<std::shared_ptr<MeowEngine::ReflectionPropertyChange>>& inUIInputQueue, unsigned int frameBufferId, const double fps) {
        UI.get()->Render(registry, inUIInputQueue, frameBufferId, fps);
    }

    void RenderPhysics(MeowEngine::PerspectiveCamera* cameraObject, entt::registry& registry) {
        AssetManager->GetShaderPipeline<OpenGLCollidePipeline>(ShaderPipelineType::PHYSICS_COLLIDER)->Render(cameraObject, registry);
    }
};

OpenGLRenderSystem::OpenGLRenderSystem(const std::shared_ptr<MeowEngine::OpenGLAssetManager>& assetManager,
                                       const std::shared_ptr<MeowEngine::graphics::ImGuiUserInterfaceSystem>& uiRenderer)
    : InternalPointer(MeowEngine::make_internal_ptr<Internal>(assetManager, uiRenderer)) {}


void OpenGLRenderSystem::RenderGameView(MeowEngine::PerspectiveCamera* cameraObject, entt::registry& registry) {
    InternalPointer->RenderGameView(cameraObject, registry);
}

void OpenGLRenderSystem::RenderUserInterface(entt::registry& registry, std::queue<std::shared_ptr<MeowEngine::ReflectionPropertyChange>>& inUIInputQueue, unsigned int frameBufferId, const double fps) {
    InternalPointer->RenderUserInterface(registry, inUIInputQueue, frameBufferId, fps);
}

void OpenGLRenderSystem::RenderPhysics(MeowEngine::PerspectiveCamera* cameraObject, entt::registry& registry) {
    InternalPointer->RenderPhysics(cameraObject, registry);
}