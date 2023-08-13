// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};




class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnGraphs(wxCommandEvent& event);
    void OnDetailsQuery(wxCommandEvent& event);
    void OnImport(wxCommandEvent& event);
    void OnExport(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};

class MyModalDialog : public wxDialog
{
public:
    MyModalDialog(wxWindow* parent, const wxString& title, const wxPoint& pos, const wxSize& size);
};
enum
{
    ID_Hello = 1,
    ID_Graphs = 2,
    ID_DETAILSQUERY = 3,
    ID_Import = 4,
    ID_Export = 5
};
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(ID_Hello, MyFrame::OnHello)
EVT_MENU(wxID_EXIT, MyFrame::OnExit)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
EVT_MENU(ID_Graphs, MyFrame::OnGraphs)
EVT_MENU(ID_DETAILSQUERY, MyFrame::OnDetailsQuery)
EVT_MENU(ID_Import, MyFrame::OnImport)
EVT_MENU(ID_Export, MyFrame::OnExport)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(MyApp);



bool MyApp::OnInit()
{

    int screenWidth, screenHeight;
    screenWidth = wxGetDisplaySize().x;
    screenHeight = wxGetDisplaySize().y;

    int centerX = screenWidth / 2;
    int centerY = screenHeight / 2;
    int windowWidth = 1366;
    int windowHeight = 768;

    MyFrame* frame = new MyFrame("Hello World", wxPoint((centerX - ((windowWidth) / 2)), (centerY - ((windowHeight) / 2))), wxSize(windowWidth, windowHeight));
    frame->Show(true);
    return true;
}
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-b",
        "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(ID_Import, "Import File");
    menuFile->Append(ID_Export, "Export File");
    menuFile->Append(wxID_EXIT);
    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenu* menuOptions = new wxMenu;
    menuOptions->Append(ID_Graphs, "Graphs");
    menuOptions->AppendSeparator();
    menuOptions->Append(wxID_COPY, "Copy\tCtrl+C");
    menuOptions->Append(wxID_CUT, "Cut\tCtrl+X");
    menuOptions->Append(wxID_PASTE, "Paste\tCtrl+V");
    menuOptions->AppendSeparator();
    menuOptions->Append(wxID_UNDO, "Undo\tCtrl+Z");
    menuOptions->Append(wxID_REDO, "Redo\tCtrl+Y");
    menuOptions->AppendSeparator();
    menuOptions->Append(ID_DETAILSQUERY, "Add New Data\tCtrl+D");
    wxMenu* menuView = new wxMenu;
    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuOptions, "&Options");
    menuBar->Append(menuView, "&View");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");
}

MyModalDialog::MyModalDialog(wxWindow* parent, const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxDialog(parent, wxID_ANY, title, pos, size) {

}
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets' Hello world sample",
        "About Hello World", wxOK | wxICON_INFORMATION);
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}
void MyFrame::OnGraphs(wxCommandEvent& event) {
    wxLogMessage("Options to select graphs");
}
void MyFrame::OnDetailsQuery(wxCommandEvent& event) {
    int screenWidth, screenHeight;
    screenWidth = wxGetDisplaySize().x;
    screenHeight = wxGetDisplaySize().y;

    int centerX = screenWidth / 2;
    int centerY = screenHeight / 2;
    int windowWidth = 920;
    int windowHeight = 500;

    MyFrame* frame = new MyFrame("Hello World", wxPoint((centerX - ((windowWidth) / 2)), (centerY - ((windowHeight) / 2))), wxSize(windowWidth, windowHeight));
    frame->Show(true);

}

void MyFrame::OnImport(wxCommandEvent& event) {
    wxFileDialog openFileDialog(this, "Open File", "", "", "All Files (*.*)|*.*", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_OK)
    {
        wxString filePath = openFileDialog.GetPath();
        wxMessageBox("Selected file: " + filePath, "File Selected", wxOK | wxICON_INFORMATION, this);
    }
}


void MyFrame::OnExport(wxCommandEvent& event) {
    /*wxLogMessage("still under constuction");*/
    int screenWidth, screenHeight;
    screenWidth = wxGetDisplaySize().x;
    screenHeight = wxGetDisplaySize().y;

    int centerX = screenWidth / 2;
    int centerY = screenHeight / 2;
    int windowWidth = 920;
    int windowHeight = 500;
    MyModalDialog modalDialog(this, "Modal Dialog Example", wxPoint((centerX - ((windowWidth) / 2)), (centerY - ((windowHeight) / 2))), wxSize(windowWidth, windowHeight));
    modalDialog.ShowModal();  // Show the modal dialog
}
