//
// Created by Akira Lynn on 06/07/22.
//

#ifndef PHYSICAT_OPENGL_APPLICATION_HPP
#define PHYSICAT_OPENGL_APPLICATION_HPP

#include "../../core/internal_ptr.hpp"
#include "../application.hpp"

namespace physicat {
    struct OpenGLApplication : public physicat::Application {
        OpenGLApplication();
        void Render() override;

    private:
        struct Internal;
        physicat::internal_ptr<Internal> InternalPointer; // checkout pimpl pattern
    };
} // namespace physicat

#endif //PHYSICAT_OPENGL_APPLICATION_HPP
