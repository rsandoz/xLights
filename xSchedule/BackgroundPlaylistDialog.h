#ifndef BACKGROUNDPLAYLISTDIALOG_H
#define BACKGROUNDPLAYLISTDIALOG_H

//(*Headers(BackgroundPlaylistDialog)
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

#include <list>

class PlayList;

class BackgroundPlaylistDialog: public wxDialog
{
    int& _plid;
    void ValidateWindow();

	public:

		BackgroundPlaylistDialog(wxWindow* parent, int& plid, std::list<PlayList*> playlists, wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~BackgroundPlaylistDialog();

		//(*Declarations(BackgroundPlaylistDialog)
		wxButton* Button_Ok;
		wxButton* Button_Cancel;
		wxListView* ListView_Playlists;
		//*)

	protected:

		//(*Identifiers(BackgroundPlaylistDialog)
		static const long ID_LISTVIEW1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(BackgroundPlaylistDialog)
		void OnButton_CancelClick(wxCommandEvent& event);
		void OnButton_OkClick(wxCommandEvent& event);
		void OnListView_PlaylistsItemSelect(wxListEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
