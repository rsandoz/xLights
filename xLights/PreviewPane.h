#ifndef PREVIEWPANE_H
#define PREVIEWPANE_H

//(*Headers(PreviewPane)
#include <wx/sizer.h>
#include <wx/dialog.h>
//*)

class ModelPreview;

class PreviewPane: public wxDialog
{
	public:

		PreviewPane(wxWindow* parent, ModelPreview* preview, wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~PreviewPane();

		//(*Declarations(PreviewPane)
		//*)

	protected:

		//(*Identifiers(PreviewPane)
		//*)

	private:

		//(*Handlers(PreviewPane)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
