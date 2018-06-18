#include <wx/event.h>
#include "MainFrame.h"
#include "the_app.h"
#include <wx/image.h>

// Define the MainApp


bool MainApp::OnInit() {
    // Add the common image handlers
    wxImage::AddHandler(new wxPNGHandler);
    wxImage::AddHandler(new wxJPEGHandler);

    MainFrame *mainFrame = new MainFrame(NULL);
    SetTopWindow(mainFrame);
    return GetTopWindow()->Show();
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
