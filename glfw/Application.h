//
// Created by Du Carl on 2018/6/23.
//

#ifndef OPENGL_APPLICATION_H
#define OPENGL_APPLICATION_H

#include <vector>
#include <GLFW/glfw3.h>
#include <memory>

namespace glfw
{
    class Application
    {
    public:
        static int __argc;
        static char** __argv;
        static Application* TheApp(){return __app;}
    public:
        Application();

        virtual int Main();

        virtual void OnInit(){};

        virtual void OnLoop(){};
        virtual void OnSize(){};
        virtual void OnExit(){};

        GLFWwindow* getMainWindow() const {
            return MainWindow;
        }


    protected:
        void InitGlfw() const;
        void RunLoop();
        void processInput(GLFWwindow *window);

        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);


    private:
        void InitWindow();
        GLFWwindow* MainWindow;

        static Application* __app;

    };
}


#endif //OPENGL_APPLICATION_H
