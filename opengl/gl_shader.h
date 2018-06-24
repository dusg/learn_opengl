//
// Created by Du Carl on 2018/6/18.
//

#ifndef OPENGL_GL_SHADER_H
#define OPENGL_GL_SHADER_H

#include <glad/glad.h>
#include <string>
#include <sstream>
#include "ShaderStore.h"
#include "gl_object.h"
#include <boost/core/noncopyable.hpp>
namespace opengl
{

class Shader : public Object ,public boost::noncopyable
    {
    public:
        Shader(GLenum type, std::string source):m_type(type) {
            assert(!source.empty());

            m_id = glCreateShader(type);

            const GLchar * src = source.c_str();

            glShaderSource(m_id, 1, &src, NULL);
            glCompileShader(m_id);
            if (!IsOK()) {
                GetInfoLog();
            }
        }

        Shader(GLenum type):m_type(type) {
            m_id = glCreateShader(type);
        }

        virtual ~Shader() {
            glDeleteShader(m_id);
        }

        Shader& Source(std::string source) {
            const GLchar * src = source.c_str();
            glShaderSource(getid(), 1, &src, NULL);

            return *this;
        }

        Shader& Compile() {
            glCompileShader(m_id);
            if (!IsOK()) {
                std::__throw_runtime_error(GetInfoLog().c_str());
            }

            return *this;
        }


        bool IsOK(){
            GLint success;
            glGetShaderiv(m_id, GL_COMPILE_STATUS, &success);
            return success != 0;
        }

        std::string GetInfoLog() {
            GLchar infoLog[512];
            std::ostringstream out;

            glGetShaderInfoLog(m_id, sizeof(infoLog), nullptr, infoLog);
            out << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;

            return out.str();
        }

        operator GLuint () {
            return m_id;
        }
    private:
        GLenum m_type;
    };

    class VertexShader : public Shader {
    public:
        VertexShader() : Shader(GL_VERTEX_SHADER) {}
    };

    class FragmentShader : public Shader {
    public:
        FragmentShader() : Shader(GL_FRAGMENT_SHADER) {}
    };
};
#endif //OPENGL_GL_SHADER_H
