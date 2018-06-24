//
// Created by Du Carl on 2018/6/24.
//

#ifndef OPENGL_GL_VERTEX_ARRAY_H
#define OPENGL_GL_VERTEX_ARRAY_H

#include <glad/glad.h>
#include "gl_object.h"
namespace opengl
{
    class VertexArray : public Object
    {
    public:
        VertexArray() {
            glGenVertexArrays(1, &getid());
        }

        void Bind() {
            glBindVertexArray(getid());
        }

        void SetAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) {
            glVertexAttribPointer(index, size, type, normalized, stride, pointer);
        }
        void Enable(GLuint index_of_location = 0){
            glEnableVertexAttribArray(index_of_location);
        }
    private:

    };
}


#endif //OPENGL_GL_VERTEX_ARRAY_H
