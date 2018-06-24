//
// Created by Du Carl on 2018/6/24.
//

#ifndef OPENGL_GL_CONTEX_H
#define OPENGL_GL_CONTEX_H

#include <glad/glad.h>
#include "gl_clearner.h"
#include "gl_enum.h"

namespace opengl
{
    class Context {
    public:
        void Viewport(GLuint width, GLuint height) {
            glViewport(0, 0, width, height);
        }

        Clearner& GetClearner () { return m_clearner;}
        void DrawElements(DrawType mode, size_t count, DataType type, const void *indices = 0) {
            glDrawElements(mode, count, type, indices);
        }
    protected:
        Clearner m_clearner;
    };
}
#endif //OPENGL_GL_CONTEX_H
