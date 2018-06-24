//
// Created by Du Carl on 2018/6/23.
//

#include <glad/glad.h>
#include <iostream>
#include <zconf.h>
#include "Application.h"
#define SCR_WIDTH 800
#define SCR_HEIGHT 600

int glfw::Application::__argc = 0;
char** glfw::Application::__argv = NULL;
glfw::Application* glfw::Application::__app = nullptr;

int glfw::Application::Main(int argc, char **argv) {
    this->__argc = argc;
    this->__argv = argv;

    try {
        InitGlfw();

        InitWindow();

        glfwSetFramebufferSizeCallback(getMainWindow(), framebuffer_size_callback);

        InitGlade();

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
    TheApp()->OnSize(width, height);
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

        usleep(1000 * 100);
    }
}

void glfw::Application::processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
        this->OnExit();
    }
}

glfw::Application::~Application() {

}

void glfw::Application::OnLoop() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void glfw::Application::InitGlade() {
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::__throw_runtime_error("Failed to initialize GLAD");
    }
}
