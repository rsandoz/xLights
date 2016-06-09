#ifndef PREVIEWPANE_H
#define PREVIEWPANE_H

//(*Headers(PreviewPane)
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/dialog.h>
//*)

class ModelPreview;

class PreviewPane: public wxDialog
{
	public:

		PreviewPane(wxWindow* parent, wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~PreviewPane();

		wxPanel* GetPreviewPanel() {return PreviewPanel;}
		wxFlexGridSizer* GetPreviewPanelSizer() {return PreviewPanelSizer;}

		//(*Declarations(PreviewPane)
		wxFlexGridSizer* PreviewPanelSizer;
		wxPanel* PreviewPanel;
		//*)

	protected:

		//(*Identifiers(PreviewPane)
		static const long ID_PANEL_PREVIEW;
		//*)

	private:

		//(*Handlers(PreviewPane)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
