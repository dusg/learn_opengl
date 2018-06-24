//
// Created by Du Carl on 2018/6/23.
//

#include <learn_opengl/rectangle/Rectangle.h>
#include "OpenGLApp.h"

void OpenGLApp::OnInit() {

}

void OpenGLApp::OnLoop() {
    glfw::Application::OnLoop();

    Rectangle::Get().Render(1);
}

void OpenGLApp::OnSize(size_t width, size_t height) {
    Rectangle::Get().Reshape(width, height);
}

void OpenGLApp::OnExit() {

}

OpenGLApp::~OpenGLApp() {

}

OpenGLApp::OpenGLApp() {}
