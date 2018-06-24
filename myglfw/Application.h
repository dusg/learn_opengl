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

        virtual ~Application();

        virtual int Main(int argc = 0, char **argv = NULL);

        virtual void OnInit(){};

        virtual void OnLoop();
        virtual void OnSize(size_t width, size_t height) {};
        virtual void OnExit(){};

        GLFWwindow* getMainWindow() const {
            return MainWindow;
        }


    protected:
        void InitGlfw() const;
        void InitGlade();
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
