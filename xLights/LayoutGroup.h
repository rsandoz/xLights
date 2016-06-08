#ifndef LAYOUTGROUP_H
#define LAYOUTGROUP_H

#include <string>

class xLightsFrame;
class Model;

class LayoutGroup
{
    public:
        LayoutGroup(const std::string & name);
        virtual ~LayoutGroup();

        const std::string &GetName() const {return mName;}
        void SetName(const std::string & name) {mName = name;}

        void SetBackgroundImage(const wxString &filename);
        const wxString &GetBackgroundImage() const { return mBackgroundImage;}

        void SetFromXml(wxXmlNode* LayoutGroupNode);

        void SetModels(std::vector<Model*> &models);
        std::vector<Model*> &GetModels() {
            return previewModels;
        }

    protected:
        wxXmlNode* LayoutGroupXml;

    private:
        std::string mName;
        wxString mBackgroundImage;
        std::vector<Model*> previewModels;
};

#endif // LAYOUTGROUP_H
