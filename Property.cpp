//
// Created by andre on 15.03.2022.
//

#include "Property.h"

#include <utility>

Property::Property(std::string modifier, std::string type, std::string name, bool getable, bool setable) {
    this->modifier = std::move(modifier);
    this->type = std::move(type);
    this->setName(std::move(name));
    this->getable = getable;
    this->setable = setable;
}

std::string Property::getType() {
    return type;
}

std::string Property::getModifier() {
    return modifier;
}

bool Property::getGetable() {
    return getable;
}

bool Property::getSetable() {
    return setable;
}

std::string Property::generateCode() {
    std::string code = "        "+modifier+" ";
    code+=type+" ";
    code+=getName()+" { ";

    if(getable)
        code+="get; ";
    if(setable)
        code+="set; ";
    code+="}";
    return code;
}

Property::~Property() {}