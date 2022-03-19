//
// Created by andre on 15.03.2022.
//

#include "Namespace.h"

#include <utility>

Namespace::Namespace(std::string name) {
    this->setName(std::move(name));
    this->classes = {};
}

Class& Namespace::addClass(Class* newClass) {
    classes[newClass->getName()] = newClass;
    return *newClass;
}

std::string Namespace::generateCode() {
    std::string code = "namespace "+getName()+"\n{\n";
    for (auto c: classes) {
        if(c.second!= nullptr){
            code+=c.second->generateCode();
            code+="\n\n";
        }
    }
    code+="}";
    return code;
}

Namespace::~Namespace() {}

std::map<std::string, Class*> Namespace::getClasses() {
    return classes;
}

void Namespace::deleteClass(std::string deleteName) {
    classes[deleteName] = nullptr;
}
