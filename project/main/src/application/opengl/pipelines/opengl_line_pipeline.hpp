//
// Created by Akira Mujawar on 22/06/24.
//

#ifndef PHYSICAT_OPENGL_LINE_PIPELINE_HPP
#define PHYSICAT_OPENGL_LINE_PIPELINE_HPP

#include "glm_wrapper.hpp"
#include "graphics_wrapper.hpp"

#include "opengl_pipeline_base.hpp"
#include "line_render_component.hpp"

using namespace std;
using namespace glm;

namespace physicat::pipeline {
    struct OpenGLLinePipeline : public physicat::pipeline::OpenGLPipelineBase {
        OpenGLLinePipeline(const GLuint& shaderProgramID);
        ~OpenGLLinePipeline() override;

    public:
        void Render(
            const physicat::OpenGLAssetManager& assetManager,
            const physicat::core::component::LineRenderComponent* lineRenderComponent
        ) const;

    private:
        const GLuint ShaderProgramID;
        unsigned int VertexBufferID, VertexArrayID;
    };
}

#endif //PHYSICAT_OPENGL_LINE_PIPELINE_HPP
