//
// Created by Du Carl on 2018/6/17.
//

#include <wx/wx.h>
#include "MyGLCanvas.h"
#include "the_app.h"

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

    {
        float vertices[] = {
                -0.5f, -0.5f, 0.0f,
                0.5f, -0.5f, 0.0f,
                0.0f,  0.5f, 0.0f
        };
    }

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    SwapBuffers();
}

MyGLCanvas::MyGLCanvas(wxWindow *parent, wxWindowID id, const int *attribList, const wxPoint &pos, const wxSize &size,
                       long style, const wxString &name, const wxPalette &palette) : wxGLCanvas(parent, id, attribList,
                                                                                                pos, size, style, name,
                                                                                                palette) {}
