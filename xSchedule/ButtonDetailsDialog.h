#ifndef BUTTONDETAILSDIALOG_H
#define BUTTONDETAILSDIALOG_H

//(*Headers(ButtonDetailsDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class ButtonDetailsDialog: public wxDialog
{
	public:

		ButtonDetailsDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ButtonDetailsDialog();

		//(*Declarations(ButtonDetailsDialog)
		wxChoice* Choice_Command;
		wxButton* Button_Ok;
		wxStaticText* StaticText2;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxTextCtrl* TextCtrl_Parameters;
		wxButton* Button_Cancel;
		wxTextCtrl* TextCtrl_Label;
		//*)

	protected:

		//(*Identifiers(ButtonDetailsDialog)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_CHOICE1;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(ButtonDetailsDialog)
		void OnButton_OkClick(wxCommandEvent& event);
		void OnButton_CancelClick(wxCommandEvent& event);
		void OnTextCtrl_ParametersText(wxCommandEvent& event);
		void OnTextCtrl_LabelText(wxCommandEvent& event);
		void OnChoice_CommandSelect(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif