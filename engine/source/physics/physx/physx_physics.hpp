//
// Created by Akira Mujawar on 12/08/24.
//

#ifndef PHYSICAT_PHYSX_PHYSICS_HPP
#define PHYSICAT_PHYSX_PHYSICS_HPP



#include "physics.hpp"
#include "PxPhysicsAPI.h"


namespace physicat::simulator {
    struct PhysXPhysics : physicat::simulator::Physics {
        PhysXPhysics();
        ~PhysXPhysics();

        void Create() override;
        void Update(float inFixedDeltaTime) override;

        void AddRigidbody(entity::Transform3DComponent& transform, entity::ColliderComponent& collider, entity::RigidbodyComponent& rigidbody) override;

    private:
        // PhysX Foundation
        physx::PxDefaultAllocator gAllocator;
        physx::PxDefaultErrorCallback gErrorCallback;
        physx::PxFoundation* gFoundation = nullptr;
        physx::PxPhysics* gPhysics = nullptr;

        // PhysX Scene Items
        physx::PxScene* gScene;
//        physx::PxTransform testTransform;
//        physx::PxRigidDynamic* body;
    };
}

#endif //PHYSICAT_PHYSX_PHYSICS_HPP
