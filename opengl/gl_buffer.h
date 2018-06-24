//
// Created by Du Carl on 2018/6/17.
//

#ifndef OPENGL_GL_BUFFER_H
#define OPENGL_GL_BUFFER_H

#include <glad/glad.h>
namespace opengl
{
    class ArrayBuffer : public Object
    {
    public:
        ArrayBuffer(int m_buffer_type) : m_buffer_type(m_buffer_type) {
            glGenBuffers(1, &m_id);
        }


        ArrayBuffer& Bind() {
            glBindBuffer(m_buffer_type, getid());
            return *this;
        }
        template <typename DataType>
        void SetData(DataType& data, GLenum usage = GL_STATIC_DRAW){
            glBufferData(m_buffer_type, sizeof(data), (void *)(&data), usage);
        }

    private:
        int m_buffer_type;
    };
}
#endif //OPENGL_GL_BUFFER_H
