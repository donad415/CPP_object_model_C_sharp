//
// Created by andre on 15.03.2022.
//

#include "Class.h"

#include <utility>

Class::Class(std::string name, bool abstract) {
    this->setName(std::move(name));
    this->abstract = abstract;
    this->functions = {};
    this->properties = {};
    this->parent = nullptr;
}

bool Class::isAbstract() {
    return abstract;
}

void Class::setParent(Class *parent) {
    this->parent = parent;
}

bool Class::isCorrect() {
    if (parent != nullptr && parent->abstract) {
        for (auto f: parent->functions) {
            if (f.second->isAbstract()) {
                if (functions[f.second->getName()] == NULL || !functions[f.second->getName()]->isOverride()) {
                    return false;
                }
            }
        }
    } else if (parent == nullptr) {
        for (auto f: functions) {
            if (f.second!= nullptr && f.second->isOverride()) {
                return false;
            }
        }
    }

    return true;
}

void Class::addFunction(Function *function) {
    functions[function->getName()] = function;
}

void Class::addProperty(Property *property) {
    properties[property->getName()] = property;
}

std::string Class::generateCode() {
    std::string code = "    ";
    if (abstract)
        code += "abstract ";
    code += "class " + getName();
    if (parent != nullptr)
        code += " : " + parent->getName();
    code += "\n    {\n";
    for (auto p: properties) {
        if(p.second!= nullptr){
            code += p.second->generateCode();
            code += "\n\n";
        }
    }
    for (auto f: functions) {
        if(f.second!= nullptr){
            code += f.second->generateCode();
            code += "\n\n";
        }
    }
    code += "    }";
    return code;
}

Class::~Class() {}

std::map<std::string, Property *> Class::getProperties() {
    return properties;
}

std::map<std::string, Function *> Class::getFunctions() {
    return functions;
}

void Class::deleteFunction(std::string name) {
    functions[name] = nullptr;
}

void Class::deleteProperty(std::string name) {
    properties[name] = nullptr;
}
