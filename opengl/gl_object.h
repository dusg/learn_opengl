//
// Created by Du Carl on 2018/6/24.
//

#ifndef OPENGL_GL_OBJECT_H
#define OPENGL_GL_OBJECT_H

#include <glad/glad.h>

namespace opengl
{
    class Object {
    public:
        GLuint& getid() {
            return m_id;
        }


    protected:
        void setid(GLuint id) {
            Object::m_id = id;
        }

    protected:
        GLuint m_id;
    };
}
#endif //OPENGL_GL_OBJECT_H
