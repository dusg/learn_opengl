//
// Created by Du Carl on 2018/6/23.
//

#ifndef OPENGL_RECTANGLE_H
#define OPENGL_RECTANGLE_H

#include <glad/glad.h>
//#include <oglplus/gl.hpp>
//#include <glfw_demo/example.hpp>
//#include <oglplus/all.hpp>

#include <opengl/gl_context.h>
#include <opengl/gl_shader.h>
#include <opengl/gl_shader_program.h>
#include <opengl/gl_vertex_array.h>
#include <opengl/gl_buffer.h>
#include <myglfw/Sigleton.h>

class Rectangle : public Sigleton<Rectangle>
{
public:
    Rectangle();

    void Reshape(GLuint width, GLuint height);

    void Render(double d);

private:
    // wrapper around the current OpenGL context
    opengl::Context gl;

    // Vertex shader
    opengl::VertexShader vertexShader;

    // Fragment shader
    opengl::FragmentShader fragmentShader;

    // Program
    opengl::ShaderProgram program;

    opengl::VertexArray vao;
    // VBO for the triangle's vertices
    opengl::ArrayBuffer vbo = opengl::ArrayBuffer(GL_ARRAY_BUFFER);

    opengl::ArrayBuffer ebo = opengl::ArrayBuffer(GL_ELEMENT_ARRAY_BUFFER);
};


#endif //OPENGL_RECTANGLE_H
