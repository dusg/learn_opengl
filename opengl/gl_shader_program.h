//
// Created by Du Carl on 2018/6/18.
//

#ifndef OPENGL_GL_SHADER_PROGRAM_H
#define OPENGL_GL_SHADER_PROGRAM_H

#include <glad/glad.h>
#include "gl_shader.h"
#include <boost/core/noncopyable.hpp>
#include <vector>

namespace opengl
{
class ShaderProgram: public boost::noncopyable, public Object
    {
    public:
        ShaderProgram(std::vector<std::shared_ptr<Shader>>& shaders)
        {
            m_shaders = shaders;
            if (shaders.empty()) {
                return;
            }
            m_id = glCreateProgram();
            for (auto iter = shaders.begin(); iter != shaders.end(); ++iter) {
                glAttachShader(m_id,**iter);
            }
            glLinkProgram(m_id);
            if (!IsOk()) {
                GetInfoLog();
            }
        }

        ShaderProgram() {
            m_id = glCreateProgram();
        }

        ShaderProgram& AttachShader(Shader& shader) {
            glAttachShader(getid(), shader);

            return *this;
        }

        ShaderProgram& Link(){
            glLinkProgram(getid());
            if (!IsOk()) {
                std::__throw_runtime_error(GetInfoLog().c_str());
            }

            return *this;
        }

        ShaderProgram& Use(){
            glUseProgram(getid());

            return *this;
        }

        bool IsOk() {
            GLint success;
            glGetProgramiv(m_id, GL_LINK_STATUS, &success);
            return success != 0;
        }

        std::string GetInfoLog() {
            GLchar infoLog[512];
            std::ostringstream out;

            glGetProgramInfoLog(m_id, sizeof(infoLog), nullptr, infoLog);
            out << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;

            return out.str();
        }

        operator GLuint (){
            return m_id;
        }
    private:
        std::vector<std::shared_ptr<Shader>> m_shaders;
    };
};
#endif //OPENGL_GL_SHADER_PROGRAM_H
