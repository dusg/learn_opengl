//
// Created by Du Carl on 2018/6/23.
//

#ifndef OPENGL_OPENGLAPP_H
#define OPENGL_OPENGLAPP_H


#include "myglfw/Application.h"

class OpenGLApp : public glfw::Application
{
public:
    OpenGLApp();

    virtual ~OpenGLApp();

    void OnInit() override;

    void OnLoop() override;

    void OnSize(size_t width, size_t height) override;

    void OnExit() override;
};


#endif //OPENGL_OPENGLAPP_H
