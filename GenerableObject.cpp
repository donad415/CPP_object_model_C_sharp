//
// Created by andre on 15.03.2022.
//
#include "GenerableObject.h"

#include <utility>

std::string GenerableObject::getName() {
    return name;
}

void GenerableObject::setName(std::string name) {
    this->name = std::move(name);
}

std::string GenerableObject::generateCode() {
    return "";
}

GenerableObject::~GenerableObject() {}
