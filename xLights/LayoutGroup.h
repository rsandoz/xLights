#ifndef LAYOUTGROUP_H
#define LAYOUTGROUP_H

#include <string>
#include <wx/xml/xml.h>

class xLightsFrame;
class Model;
class ModelPreview;

class LayoutGroup
{
    public:
        LayoutGroup(const std::string & name, xLightsFrame* xl, wxXmlNode *node, wxString bkImage = "");
        virtual ~LayoutGroup();

        const std::string &GetName() const {return mName;}
        void SetName(const std::string & name) {mName = name;}

        void SetBackgroundImage(const wxString &filename);
        const wxString &GetBackgroundImage() const { return mBackgroundImage;}

        void SetFromXml(wxXmlNode* LayoutGroupNode);
        wxXmlNode* GetLayoutGroupXml() const;

        void SetModels(std::vector<Model*> &models);
        std::vector<Model*> &GetModels() {
            return previewModels;
        }

        void CheckPreviewClosed();
        void MarkForPreviewDeletion();
        void SetModelPreview(ModelPreview* preview) {mModelPreview = preview;}

        bool GetPreviewActive() {return mPreviewActive;}
        void SetPreviewActive();

    protected:
        wxXmlNode* LayoutGroupXml;

    private:
        std::string mName;
        wxString mBackgroundImage;
        std::vector<Model*> previewModels;
        bool mPreviewClosed;  // this flag is used to indicate preview window should be deleted upon first chance
        bool mPreviewActive;
        ModelPreview* mModelPreview;
        xLightsFrame* xlights;
};

#endif // LAYOUTGROUP_H
