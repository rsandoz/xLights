
#include <wx/wx.h>
#include <wx/xml/xml.h>

#include "LayoutGroup.h"
#include "xLightsMain.h"
#include "models/Model.h"

LayoutGroup::LayoutGroup(const std::string & name, xLightsFrame* xl, wxXmlNode *node, wxString bkImage)
: mName(name), mPreviewClosed(false), mPreviewActive(false), mModelPreview(nullptr), xlights(xl), LayoutGroupXml(node)
{
    if( bkImage != "" ) {
        SetBackgroundImage( bkImage );
    }
    SetFromXml(node);
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

void LayoutGroup::SetModels(std::vector<Model*> &models)
{
    previewModels.clear();
    for (auto it = models.begin(); it != models.end(); it++) {
        previewModels.push_back(*it);
    }
}

void LayoutGroup::CheckPreviewClosed()
{
    if( mPreviewClosed ) {
        for (auto it = xlights->PreviewWindows.begin(); it != xlights->PreviewWindows.end(); it++) {
            if( *it == mModelPreview ) {
                delete mModelPreview;
                mModelPreview = nullptr;
                // TODO need to delete from the vector PreviewWindows
                break;
            }
        }
        mPreviewClosed = false;
    }
}

void LayoutGroup::SetPreviewActive()
{
    mPreviewActive = true;
    if( mModelPreview != nullptr ) {
        mPreviewClosed = true;
        CheckPreviewClosed();
    }
}

void LayoutGroup::MarkForPreviewDeletion()
{
    mPreviewClosed = true;
    mPreviewActive = false;
    xlights->UpdateLayoutButton();
}
