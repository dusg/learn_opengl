//
// Created by Du Carl on 2018/6/23.
//

#include <iostream>
#include "Application.h"
#define SCR_WIDTH 800
#define SCR_HEIGHT 600

int glfw::Application::Main() {
    try {
        InitGlfw();

        InitWindow();

        glfwSetFramebufferSizeCallback(getMainWindow(), framebuffer_size_callback);

        this->OnInit();

        RunLoop();

    } catch (std::exception & exception) {
        std::cout << exception.what() << std::endl;
        return -1;
    }
    return 0;
}

void glfw::Application::InitGlfw() const {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

void glfw::Application::InitWindow() {
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        std::__throw_runtime_error("Failed to create GLFW window");
    }
    glfwMakeContextCurrent(window);
    MainWindow = window;
}

void glfw::Application::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    TheApp()->OnSize();
}

glfw::Application::Application() {
    Application::__app = this;
}

void glfw::Application::RunLoop() {
    while (!glfwWindowShouldClose(getMainWindow()))
    {
        // input
        // -----
        processInput(getMainWindow());

        this->OnLoop();

        glfwSwapBuffers(getMainWindow());
        glfwPollEvents();
    }
}

void glfw::Application::processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
        this->OnExit();
    }
}
