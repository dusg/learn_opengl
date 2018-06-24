//
// Created by Du Carl on 2018/6/24.
//

#ifndef OPENGL_GL_CLEARNER_H
#define OPENGL_GL_CLEARNER_H

#include <glad/glad.h>

namespace opengl
{
    class Clearner
    {
    public:
        Clearner& SetClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
            glClearColor(red, green, blue, alpha);
            return *this;
        }

        Clearner& ClearColorBuffer() {
            glClear(GL_COLOR_BUFFER_BIT);
            return *this;
        }

    };
}
#endif //OPENGL_GL_CLEARNER_H
