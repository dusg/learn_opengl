//
// Created by Du Carl on 2018/6/17.
//

#include <wx/wx.h>
#include <vector>
#include "MyGLCanvas.h"
#include "the_app.h"
#include "../opengl/gl_shader.h"
#include "../opengl/gl_fatory.h"
#include "../opengl/gl_buffer.h"

wxBEGIN_EVENT_TABLE(MyGLCanvas, wxGLCanvas)
    EVT_PAINT(MyGLCanvas::OnPaint)
wxEND_EVENT_TABLE()

MyGLCanvas::MyGLCanvas(wxWindow *parent)
        : wxGLCanvas(parent, wxID_ANY, nullptr, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE,
                     wxT("MyGLCanvas")) {

}

void MyGLCanvas::OnPaint(wxPaintEvent &event) {
    wxPaintDC dc(this);

    wxGLContext& context = wxGetApp().GetGLContext(this);

    auto version = glGetString(GL_VERSION);

    glViewport(0, 0, GetClientSize().x, GetClientSize().y);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    DrawTrigle();


    SwapBuffers();
}

void MyGLCanvas::DrawTrigle() const {
    float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
    };
    std::vector<std::shared_ptr<opengl::Shader>> shaders;
    shaders.push_back(opengl::Factory::CreateVertexShader());
    auto str = opengl::Factory::CreateFragmentShader()->IsOK();
    opengl::Factory::CreateFragmentShader()->GetInfoLog();
    auto str2 = opengl::Factory::CreateVertexShader()->IsOK();
    opengl::Factory::CreateVertexShader()->GetInfoLog();
    shaders.push_back(opengl::Factory::CreateFragmentShader());
    opengl::ShaderProgram shaderProgram(shaders);
    opengl::UseProgram(shaderProgram);

    opengl::ArrayBuffer buffer;
    buffer.SetData(sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

    glDrawArrays(GL_TRIANGLES, 0, 3);

}

MyGLCanvas::MyGLCanvas(wxWindow *parent, wxWindowID id, const int *attribList, const wxPoint &pos, const wxSize &size,
                       long style, const wxString &name, const wxPalette &palette) : wxGLCanvas(parent, id, attribList,
                                                                                                pos, size, style, name,
                                                                                                palette) {}
