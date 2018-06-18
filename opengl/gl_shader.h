//
// Created by Du Carl on 2018/6/18.
//

#ifndef OPENGL_GL_SHADER_H
#define OPENGL_GL_SHADER_H

#include <wx/glcanvas.h>
#include <string>
#include <sstream>
#include "ShaderStore.h"
#include <boost/core/noncopyable.hpp>
namespace opengl
{
class Shader : public boost::noncopyable
    {
    public:
        Shader(GLenum type, std::string source = ""):m_type(type) {
            assert(!source.empty());

            m_id = glCreateShader(type);

            const GLchar * src = source.c_str();

            glShaderSource(m_id, 1, &src, NULL);
            glCompileShader(m_id);
        }

        virtual ~Shader() {
            glDeleteShader(m_id);
        }

        bool IsOK(){
            GLint success;
            glGetShaderiv(m_id, GL_COMPILE_STATUS, &success);
            return success != 0;
        }

        std::string GetInfoLog() {
            std::string info;
            GLchar infoLog[512];
            std::ostringstream out(info);

            glGetShaderInfoLog(m_id, sizeof(infoLog), nullptr, infoLog);
            out << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
            out.flush();

            return info;
        }

        operator GLuint () {
            return m_id;
        }
    private:
        GLuint m_id;
        GLenum m_type;
    };
};
#endif //OPENGL_GL_SHADER_H
