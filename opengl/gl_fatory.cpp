//
// Created by Du Carl on 2018/6/17.
//

#include "gl_fatory.h"
#include "gl_buffer.h"


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

void opengl::DrawTrigle() {
    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };
    std::vector<std::shared_ptr<opengl::Shader>> shaders;
    shaders.push_back(opengl::Factory::CreateVertexShader());
    //auto str = opengl::Factory::CreateFragmentShader()->IsOK();
    //opengl::Factory::CreateFragmentShader()->GetInfoLog();
    //auto str2 = opengl::Factory::CreateVertexShader()->IsOK();
    //opengl::Factory::CreateVertexShader()->GetInfoLog();
    shaders.push_back(opengl::Factory::CreateFragmentShader());
    opengl::ShaderProgram shaderProgram(shaders);
    opengl::UseProgram(shaderProgram);

    opengl::ArrayBuffer buffer;
    buffer.SetData(sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

    glDrawArrays(GL_TRIANGLES, 0, 3);

}
