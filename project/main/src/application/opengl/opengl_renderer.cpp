//
// Created by Akira Mujawar on 21/06/24.
//

#include "opengl_renderer.hpp"


#include "opengl_mesh_pipeline.hpp"
#include "opengl_line_pipeline.hpp"


using physicat::OpenGLRenderer;

using namespace physicat::pipeline;
using namespace physicat::core::component;
using physicat::assets::ShaderPipelineType;

struct OpenGLRenderer::Internal {
    const std::shared_ptr<physicat::OpenGLAssetManager> AssetManager;

    Internal(std::shared_ptr<physicat::OpenGLAssetManager> assetManager)
    : AssetManager(assetManager){}

    void Render(physicat::core::component::RenderComponentBase* renderComponent) {

//        AssetManager->GetShaderPipeline(shaderPipelineType).Render(
//                *AssetManager,
//                staticMeshInstances,
//                lineDraw
//        );

        switch (renderComponent->GetShaderPipelineType()) {
            case ShaderPipelineType::Default:
                AssetManager->GetShaderPipeline<OpenGLMeshPipeline>(ShaderPipelineType::Default)->Render(
                    *AssetManager,
                    dynamic_cast<MeshRenderComponent*>(renderComponent)
                );
                break;
            case ShaderPipelineType::Line:
                AssetManager->GetShaderPipeline<OpenGLLinePipeline>(ShaderPipelineType::Line)->Render(
                        *AssetManager,
                        dynamic_cast<LineRenderComponent*>(renderComponent)
                );
                break;
        }
    }
};

OpenGLRenderer::OpenGLRenderer(const std::shared_ptr<physicat::OpenGLAssetManager>& assetManager)
    : InternalPointer(physicat::make_internal_ptr<Internal>(assetManager)) {}

void OpenGLRenderer::Render(physicat::core::component::RenderComponentBase* renderComponent) {
    InternalPointer->Render(renderComponent);
}
