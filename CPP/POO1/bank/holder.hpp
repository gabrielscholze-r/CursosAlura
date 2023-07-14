#pragma once
#include <string>

class Holder
{
    std::string name;
    std::string doc;
    void nameLength();

    public:
        Holder(std::string name, std::string doc);
        std::string getName();
        std::string getDoc();
        
};