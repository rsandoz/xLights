#ifndef LAYOUTGROUP_H
#define LAYOUTGROUP_H

#include <string>

class LayoutGroup
{
    public:
        LayoutGroup(const std::string & name);
        virtual ~LayoutGroup();

        const std::string &GetName() const {return mName;}
        void SetName(const std::string & name) {mName = name;}

    protected:

    private:
        std::string mName;
};

#endif // LAYOUTGROUP_H
