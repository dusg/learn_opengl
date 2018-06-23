//
// Created by Du Carl on 2018/6/20.
//

#include "main.h"
#include "../opengl/gl_fatory.h"
#include "../opengl/gl_buffer.h"
#include "example.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

void InitShaders();

unsigned int GetVAO();

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

std::shared_ptr<opengl::ShaderProgram> shaderProgram;
std::unique_ptr<oglplus::Example> triangle;

int main(int argc, char** argv){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    auto version = glGetString(GL_VERSION);

    InitShaders();
    // render loop
    // -----------
    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };
//    unsigned int VAO;
//    glGenVertexArrays(1, &VAO);
//     1. 绑定VAO
//    glBindVertexArray(VAO);
//    opengl::ArrayBuffer buffer;
//    buffer.SetData(sizeof(vertices), vertices, GL_STATIC_DRAW);
//    unsigned int VBO;
//    glGenBuffers(1, &VBO);
    // 2. 把顶点数组复制到缓冲中供OpenGL使用
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
// 3. 设置顶点属性指针
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
    triangle = oglplus::makeExample(oglplus::ExampleParams(argc, argv));

    while (!glfwWindowShouldClose(window))
    {
        usleep(1000*100);
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        triangle->Render(1);
//        opengl::UseProgram(*shaderProgram);
//        glUseProgram(*shaderProgram);
//        glBindVertexArray(VAO);
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//        DrawTrigle();
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

void InitShaders() {
//    std::vector<std::shared_ptr<opengl::Shader>> shaders;
//    shaders.push_back(opengl::Factory::CreateVertexShader());
    //auto str = opengl::Factory::CreateFragmentShader()->IsOK();
    //opengl::Factory::CreateFragmentShader()->GetInfoLog();
    //auto str2 = opengl::Factory::CreateVertexShader()->IsOK();
    //opengl::Factory::CreateVertexShader()->GetInfoLog();
//    shaders.push_back(opengl::Factory::CreateFragmentShader());
//    shaderProgram.reset(new opengl::ShaderProgram(shaders));
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    triangle->Reshape(width, height);
//    triangle->Render(0);
//    glViewport(0, 0, width, height);
}

void DrawTrigle() {
    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };

//    unsigned int VAO = GetVAO();
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    opengl::UseProgram(*shaderProgram);

//    opengl::ArrayBuffer buffer;
//    buffer.SetData(sizeof(vertices), vertices, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
//    glEnableVertexAttribArray(0);

    glDrawArrays(GL_TRIANGLES, 0, 3);

}

unsigned int GetVAO() {
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    return 0;
}
