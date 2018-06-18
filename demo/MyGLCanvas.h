//
// Created by Du Carl on 2018/6/17.
//

#ifndef OPENGL_MYGLCANVAS_H
#define OPENGL_MYGLCANVAS_H


#include <wx/glcanvas.h>

class MyGLCanvas : public wxGLCanvas
{
public:
    MyGLCanvas(wxWindow* parent);

    MyGLCanvas(wxWindow *parent, wxWindowID id = wxID_ANY, const int *attribList = nullptr, const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize,
               long style = wxFULL_REPAINT_ON_RESIZE, const wxString &name = wxT("MyGLCanvas"), const wxPalette &palette = wxNullPalette);

private:
    void OnPaint(wxPaintEvent &event);


wxDECLARE_EVENT_TABLE();
};


#endif //OPENGL_MYGLCANVAS_H
