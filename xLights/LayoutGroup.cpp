
#include <wx/wx.h>
#include <wx/xml/xml.h>

#include "LayoutGroup.h"
#include "xLightsMain.h"
#include "models/Model.h"

LayoutGroup::LayoutGroup(const std::string & name, xLightsFrame* xl, wxXmlNode *node, wxString bkImage)
: mName(name), mPreviewHidden(true), mPreviewCreated(false), mModelPreview(nullptr), xlights(xl), LayoutGroupXml(node)
{
    if( bkImage != "" ) {
        SetBackgroundImage( bkImage );
    }
    SetFromXml(node);
}

LayoutGroup::~LayoutGroup()
{
    previewModels.clear();
    for (auto it = xlights->PreviewWindows.begin(); it != xlights->PreviewWindows.end(); it++) {
        if( *it == mModelPreview ) {
            xlights->PreviewWindows.erase(it);
            delete mModelPreview;
            mModelPreview = nullptr;
            break;
        }
    }
}

void LayoutGroup::SetBackgroundImage(const wxString &filename)
{
    if (mBackgroundImage != filename) {
        mBackgroundImage = filename;
        LayoutGroupXml->DeleteAttribute("backgroundImage");
        LayoutGroupXml->AddAttribute("backgroundImage", mBackgroundImage);
        if( mModelPreview != nullptr ) {
            mModelPreview->SetbackgroundImage(mBackgroundImage);
            if( !mPreviewHidden ) {
                mModelPreview->Refresh();
                mModelPreview->Update();
            }
        }
    }
}

void LayoutGroup::SetFromXml(wxXmlNode* LayoutGroupNode)
{
    LayoutGroupXml = LayoutGroupNode;
    mName=LayoutGroupNode->GetAttribute("name").ToStdString();
    mBackgroundImage=LayoutGroupNode->GetAttribute("backgroundImage").ToStdString();
}

wxXmlNode* LayoutGroup::GetLayoutGroupXml() const {
    return this->LayoutGroupXml;
}

void LayoutGroup::SetModels(std::vector<Model*> &models)
{
    previewModels.clear();
    for (auto it = models.begin(); it != models.end(); it++) {
        previewModels.push_back(*it);
    }
}

void LayoutGroup::PreviewClosed()
{
    mPreviewHidden = true;
    xlights->UpdateLayoutButton();
}

void LayoutGroup::SetPreviewActive()
{
    mPreviewCreated = true;
    mPreviewHidden = false;
    mModelPreview->SetActive();
}

