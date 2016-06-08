#include "PreviewPane.h"

//(*InternalHeaders(PreviewPane)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(PreviewPane)
//*)

BEGIN_EVENT_TABLE(PreviewPane,wxDialog)
	//(*EventTable(PreviewPane)
	//*)
END_EVENT_TABLE()

PreviewPane::PreviewPane(wxWindow* parent,ModelPreview* preview,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(PreviewPane)
	wxFlexGridSizer* Panel_Sizer;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	SetMinSize(wxDLG_UNIT(parent,wxSize(100,100)));
	Panel_Sizer = new wxFlexGridSizer(0, 1, 0, 0);
	Panel_Sizer->AddGrowableCol(0);
	Panel_Sizer->AddGrowableRow(0);
	SetSizer(Panel_Sizer);
	Panel_Sizer->Fit(this);
	Panel_Sizer->SetSizeHints(this);
	//*)

	Panel_Sizer->Add((wxWindow*)preview, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Panel_Sizer->Fit(this);
	Panel_Sizer->SetSizeHints(this);
}

PreviewPane::~PreviewPane()
{
	//(*Destroy(PreviewPane)
	//*)
}

