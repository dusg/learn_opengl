#include <glad/glad.h>
#include <wx/event.h>
#include "MainFrame.h"
#include "the_app.h"

#include <wx/image.h>
#include <GLFW/glfw3.h>
// Define the MainApp


bool MainApp::OnInit() {
    // Add the common image handlers
    wxImage::AddHandler(new wxPNGHandler);
    wxImage::AddHandler(new wxJPEGHandler);

    InitOpenGL();

    MainFrame *mainFrame = new MainFrame(NULL);
    SetTopWindow(mainFrame);
    return GetTopWindow()->Show();
}

void MainApp::InitOpenGL() const {
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        wxExit();
    }
}

wxGLContext &MainApp::GetGLContext(wxGLCanvas *canvas) {
    static wxGLContext* s_glContext = nullptr;
    if (!s_glContext) {
        s_glContext = new wxGLContext(canvas);
    }
    s_glContext->SetCurrent(*canvas);
    return *s_glContext;
}


IMPLEMENT_APP(MainApp)
