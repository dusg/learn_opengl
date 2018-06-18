//
// Created by Du Carl on 2018/6/17.
//

#include "gl_fatory.h"


std::shared_ptr<opengl::Shader> opengl::Factory::CreateVertexShader(std::string source) {
    if (source.empty()) {
        source = ShaderStore::GetSimpleVertexShaderSource();
    }
    return std::shared_ptr<opengl::Shader>(new opengl::Shader(GL_VERTEX_SHADER, source));
}

std::shared_ptr<opengl::Shader> opengl::Factory::CreateFragmentShader(std::string source) {
    if (source.empty()) {
        source = ShaderStore::GetSimpleFragmentShaderSource();
    }

    return std::shared_ptr<opengl::Shader>(new opengl::Shader(GL_FRAGMENT_SHADER, source));
}
