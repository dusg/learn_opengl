//
// Created by Du Carl on 2018/6/24.
//

#ifndef OPENGL_GL_ENUM_H
#define OPENGL_GL_ENUM_H

#include <glad/glad.h>

namespace opengl
{
    enum DrawType {
        Triangles = GL_TRIANGLES
    };

    enum DataType
    {
        Byte = GL_BYTE,
        Short = GL_SHORT,
        Int = GL_INT,
        Fixed = GL_FIXED_ONLY,
        Float = GL_FLOAT,
        HalfFloat = GL_HALF_FLOAT,
        Double = GL_DOUBLE,
        UnsignedByte = GL_UNSIGNED_BYTE,
        UnsignedShort = GL_UNSIGNED_SHORT,
        UnsignedInt = GL_UNSIGNED_INT
    };
}
#endif //OPENGL_GL_ENUM_H
