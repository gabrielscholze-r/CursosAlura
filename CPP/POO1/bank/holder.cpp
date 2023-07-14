#include "holder.hpp"
#include <iostream>

Holder::Holder(std::string name, std::string doc) : name(name), doc(doc) {nameLength();}

void Holder::nameLength()
{
    if (name.size() < 5)
    {
        std::cout << "Insert a bigger name" << std::endl;
        exit(1);
    }
}

std::string Holder::getName(){
    return name;
}
std::string Holder::getDoc(){
    return doc;
}