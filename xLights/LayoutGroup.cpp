
#include <wx/wx.h>
#include <wx/xml/xml.h>

#include "LayoutGroup.h"
#include "xLightsMain.h"

LayoutGroup::LayoutGroup(const std::string & name)
: mName(name)
{
}

LayoutGroup::~LayoutGroup()
{
}

void LayoutGroup::SetBackgroundImage(const wxString &filename)
{
    if (mBackgroundImage != filename) {
        mBackgroundImage = filename;
        LayoutGroupXml->DeleteAttribute("backgroundImage");
        LayoutGroupXml->AddAttribute("backgroundImage", mBackgroundImage);
    }
}

void LayoutGroup::SetFromXml(wxXmlNode* LayoutGroupNode)
{
    LayoutGroupXml = LayoutGroupNode;
    mName=LayoutGroupNode->GetAttribute("name").ToStdString();
    mBackgroundImage=LayoutGroupNode->GetAttribute("backgroundImage").ToStdString();
}
