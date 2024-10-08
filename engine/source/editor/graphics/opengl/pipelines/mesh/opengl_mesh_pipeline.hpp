//
// Created by Akira Mujawar on 23/06/24.
//

#ifndef PHYSICAT_OPENGL_MESH_PIPELINE_HPP
#define PHYSICAT_OPENGL_MESH_PIPELINE_HPP

#include "glm_wrapper.hpp"
#include "graphics_wrapper.hpp"

#include "opengl_pipeline_base.hpp"
#include "mesh_render_component.hpp"
#include "transform3d_component.hpp"

namespace physicat::pipeline {
    struct OpenGLMeshPipeline : public physicat::pipeline::OpenGLPipelineBase {
        OpenGLMeshPipeline(const GLuint& shaderProgramID);
        ~OpenGLMeshPipeline() override;

    public:
        void Render(
            const physicat::OpenGLAssetManager& assetManager,
            const physicat::entity::MeshRenderComponent* meshRenderComponent,
            const physicat::entity::Transform3DComponent* transform3DComponent
        ) const;
//        void Render(
//                const physicat::OpenGLAssetManager& assetManager,
//                const physicat::entity::StaticMeshRenderComponent* meshRenderComponent,
//                const physicat::entity::Transform3dComponent* transform3DComponent
//        ) const;

    private:
        const GLuint ShaderProgramID;
        const GLuint UniformLocationMVP;
        const GLuint AttributeLocationVertexPosition;
        const GLuint AttributeLocationTextureCoord;
        const GLsizei Stride;
        const GLsizei OffsetPosition;
        const GLsizei OffsetTextureCoord;
    };
}


#endif //PHYSICAT_OPENGL_MESH_PIPELINE_HPP
