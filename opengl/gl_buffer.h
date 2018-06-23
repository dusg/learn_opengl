//
// Created by Du Carl on 2018/6/17.
//

#ifndef OPENGL_GL_BUFFER_H
#define OPENGL_GL_BUFFER_H

#include <glad/glad.h>
namespace opengl
{
    class ArrayBuffer
    {
    public:
        ArrayBuffer(int m_buffer_type = GL_ARRAY_BUFFER) : m_buffer_type(m_buffer_type) {
            glGenBuffers(1, &m_id);
            glBindBuffer(GL_ARRAY_BUFFER, m_id);
        }

        void SetData(size_t size, void* data, GLenum usage = GL_STATIC_DRAW){
            glBufferData(m_buffer_type, size, data, usage);
        }
    private:
        int m_buffer_type;
        GLuint m_id;
    };
}
#endif //OPENGL_GL_BUFFER_H
