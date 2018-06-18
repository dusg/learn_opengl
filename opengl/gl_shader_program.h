//
// Created by Du Carl on 2018/6/18.
//

#ifndef OPENGL_GL_SHADER_PROGRAM_H
#define OPENGL_GL_SHADER_PROGRAM_H

#include "wx/glcanvas.h"
#include "gl_shader.h"
#include <boost/core/noncopyable.hpp>
#include <vector>

namespace opengl
{
class ShaderProgram: public boost::noncopyable
    {
    public:
        ShaderProgram(std::vector<Shader>& shaders)
        {
            if (shaders.empty()) {
                return;
            }
            m_id = glCreateProgram();
            for (auto iter = shaders.begin(); iter != shaders.end(); ++iter) {
                glAttachShader(m_id,*iter);
            }
            glLinkProgram(m_id);
        }

        bool IsOk() {
            GLint success;
            glGetProgramiv(m_id, GL_LINK_STATUS, &success);
            return success != 0;
        }

        std::string GetInfoLog() {
            std::string info;
            GLchar infoLog[512];
            std::ostringstream out(info);

            glGetProgramInfoLog(m_id, sizeof(infoLog), nullptr, infoLog);
            out << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
            out.flush();

            return info;
        }

        operator GLuint (){
            return m_id;
        }
    private:
        GLuint m_id;
    };
};
#endif //OPENGL_GL_SHADER_PROGRAM_H
