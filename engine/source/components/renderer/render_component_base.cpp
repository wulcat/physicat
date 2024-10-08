//
// Created by Akira Mujawar on 23/06/24.
//

#include "render_component_base.hpp"

using physicat::entity::RenderComponentBase;

RenderComponentBase::RenderComponentBase()
    : Shader(physicat::assets::ShaderPipelineType::Default) {}

RenderComponentBase::RenderComponentBase(physicat::assets::ShaderPipelineType shaderPipelineType)
    : Shader(shaderPipelineType) {}
