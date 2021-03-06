/***************************************************************
 * Name:      xScheduleApp.h
 * Purpose:   Defines Application Class
 * Author:    xLights ()
 * Created:   2016-12-30
 * Copyright: xLights (http://xlights.org)
 * License:
 **************************************************************/

#ifndef XSCHEDULEAPP_H
#define XSCHEDULEAPP_H

#include <wx/app.h>

#ifdef _MSC_VER_
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

class wxSingleInstanceChecker;

class xScheduleApp : public wxApp
{
    wxSingleInstanceChecker* _checker;

    public:
        virtual bool OnInit();
        virtual void OnFatalException();
        void WipeSettings();
        virtual int OnExit();
};

DECLARE_APP(xScheduleApp)

#endif // XSCHEDULEAPP_H
