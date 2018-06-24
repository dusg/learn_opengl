//
// Created by Du Carl on 2018/6/23.
//


#include "Rectangle.h"
//using namespace oglplus;
using namespace opengl;
Rectangle::Rectangle() {
    vertexShader.Source((" \
			#version 330\n \
			layout (location = 0) in vec3 aPos; \
			void main(void) \
			{ \
				gl_Position = vec4(aPos, 1.0); \
			} \
		")).Compile();

    // set the fragment shader source and compile it
    fragmentShader.Source((" \
			#version 330\n \
            out vec4 FragColor;\
			void main(void) \
			{ \
				FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f); \
			} \
		")).Compile();

    program.AttachShader(vertexShader).AttachShader(fragmentShader);
    program.Link().Use();

    float vertices[] = {
            0.5f, 0.5f, 0.0f,   // 右上角
            0.5f, -0.5f, 0.0f,  // 右下角
            -0.5f, -0.5f, 0.0f, // 左下角
            -0.5f, 0.5f, 0.0f   // 左上角
    };

    unsigned int indices[] = { // 注意索引从0开始!
            0, 1, 3, // 第一个三角形
            1, 2, 3  // 第二个三角形
    };

    vao.Bind();

    vbo.Bind();

    vbo.SetData(vertices);
//    Buffer::Data(Buffer::Target::Array, vertices);

    ebo.Bind();
    ebo.SetData(indices);
    //Buffer::Data(Buffer::Target::ElementArray, indices);

    vao.SetAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    vao.Enable(0);
//    (program | "aPos").Setup<Vec3f>().Enable();
}

void Rectangle::Reshape(GLuint width, GLuint height) {
    gl.Viewport(width, height);
    Render(0);
}

void Rectangle::Render(double) {
    //gl.GetClearner().ClearColorBuffer();
    gl.DrawElements(DrawType ::Triangles, 6, DataType::UnsignedInt);
}
