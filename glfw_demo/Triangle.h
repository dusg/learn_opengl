//
// Created by Du Carl on 2018/6/23.
//

#ifndef OPENGL_TRIANGLE_H
#define OPENGL_TRIANGLE_H

/**
 *  @example oglplus/001_triangle_glsl120.cpp
 *  @brief Shows the basic usage of OGLplus by drawing a blue triangle (using GLSL 120).
 *
 *  @oglplus_screenshot{001_triangle_glsl120}
 *
 *  Copyright 2008-2015 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 *
 *  @oglplus_example_uses_gl{GL_VERSION_3_0}
 */
#include <glad/glad.h>
#include <oglplus/gl.hpp>
#include <oglplus/all.hpp>

#include "example.hpp"

namespace oglplus {

    class TriangleExample : public Example
    {
    private:
        // wrapper around the current OpenGL context
        Context gl;

        // Vertex shader
        VertexShader vs;

        // Fragment shader
        FragmentShader fs;

        // Program
        Program prog;

        // A vertex array object for the rendered triangle
        VertexArray triangle;
        // VBO for the triangle's vertices
        Buffer verts;
    public:
        TriangleExample(void)
        {
            // Set the vertex shader source and compile it
            vs.Source(StrCRef(" \
			#version 330\n \
			layout (location = 0) in vec3 aPos; \
			void main(void) \
			{ \
				gl_Position = vec4(aPos, 1.0); \
			} \
		")).Compile();

            // set the fragment shader source and compile it
            fs.Source(StrCRef(" \
			#version 330\n \
            out vec4 FragColor;\
			void main(void) \
			{ \
				FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f); \
			} \
		")).Compile();

            // attach the shaders to the program
            prog.AttachShader(vs).AttachShader(fs);
            // link and use it
            prog.Link().Use();

            // bind the VAO for the triangle
            triangle.Bind();

            float vertices[] = {
                    -0.5f, -0.5f, 0.0f,
                    0.5f, -0.5f, 0.0f,
                    0.0f,  0.5f, 0.0f
            };
            // bind the VBO for the triangle vertices
            verts.Bind(Buffer::Target::Array);
            // upload the data
            // since triangle_vertices is a static array
            // it is not necessary to specify its element count
            Buffer::Data(Buffer::Target::Array, vertices);
            // setup the vertex attribs array for the vertices
            (prog|"aPos").Setup<Vec3f>().Enable();

            gl.ClearColor(0.5f, 0.5f, 0.5f, 0.0f);
            gl.Disable(Capability::DepthTest);
        }

        void Reshape(GLuint width, GLuint height)
        {
            gl.Viewport(width, height);
        }

        void Render(double)
        {
            gl.Clear().ColorBuffer();

            gl.DrawArrays(PrimitiveType::Triangles, 0, 3);
        }
    };

    void setupExample(ExampleParams& /*params*/){ }

    std::unique_ptr<ExampleThread> makeExampleThread(
            Example& /*example*/,
            unsigned /*thread_id*/,
            const ExampleParams& /*params*/
    ){ return std::unique_ptr<ExampleThread>(); }

    std::unique_ptr<Example> makeExample(const ExampleParams& /*params*/)
    {
        return std::unique_ptr<Example>(new TriangleExample);
    }

} // namespace oglplus


#endif //OPENGL_TRIANGLE_H
