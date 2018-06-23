//
// Created by Du Carl on 2018/6/18.
//

#ifndef OPENGL_SHADERSTORE_H
#define OPENGL_SHADERSTORE_H


#include <string>
#include <glad/glad.h>
class ShaderStore
{
public:
    static const GLchar *GetSimpleVertexShaderSource();

    static const GLchar *GetSimpleFragmentShaderSource();
};


#endif //OPENGL_SHADERSTORE_H
