//
// Created by Du Carl on 2018/6/17.
//

#ifndef OPENGL_OPENGL_H
#define OPENGL_OPENGL_H

#include "gl_shader.h"
#include "gl_shader_program.h"
#include <string>
namespace opengl
{
    class Factory
    {
    public:
        static std::shared_ptr<Shader> CreateVertexShader(std::string source = "");
        static std::shared_ptr<Shader> CreateFragmentShader(std::string source = "");
    };

    void UseProgram(ShaderProgram& program){
        glUseProgram(program);
    }

    void DrawTrigle();

}



#endif //OPENGL_OPENGL_H
