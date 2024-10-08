//
// Created by Akira Mujawar on 03/07/24.
//

#ifndef PHYSICAT_TRANSFORM3D_COMPONENT_HPP
#define PHYSICAT_TRANSFORM3D_COMPONENT_HPP

//#include <glm/vec3.hpp>
//#include <glm/vec4.hpp>
//#include <glm/mat4x4.hpp>
//#include "glm_wrapper.hpp"

#include "transform_component_base.hpp"
#include "math_wrapper.hpp"

namespace physicat::entity {
    class Transform3DComponent : public physicat::entity::TransformComponentBase {
    public:
        Transform3DComponent();
        Transform3DComponent(glm::vec3 position, glm::vec3 scale, glm::vec4 rotation);
        Transform3DComponent(glm::vec3 position, glm::vec3 scale, glm::vec3 rotationAxis, float rotationDegrees);

        void Update(const float& deltaTime, const glm::mat4& projectionViewMatrix) override;
        void RotateBy(const float& degrees);

//        physicat::math::Vector3 PositionTest;
        physicat::math::Vector3 Position;
        glm::vec3 Scale;

        // find proper way to handle rotations
        glm::vec3 RotationAxis;
        float RotationDegrees;
        glm::vec4 Rotation;

        glm::mat4 IdentityMatrix;
        glm::mat4 TransformMatrix;
    };
}


#endif //PHYSICAT_TRANSFORM3D_COMPONENT_HPP
