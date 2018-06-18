//
// Created by Du Carl on 2018/6/17.
//

#ifndef OPENGL_THE_APP_H
#define OPENGL_THE_APP_H

#include <wx/app.h>

// Define the MainApp
class MainApp : public wxApp
{
public:
    MainApp() {}
    virtual ~MainApp() {}

    virtual bool OnInit();

    wxGLContext &GetGLContext(wxGLCanvas *canvas);
};
DECLARE_APP(MainApp)
#endif //OPENGL_THE_APP_H
