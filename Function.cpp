//
// Created by andre on 15.03.2022.
//

#include "Function.h"

#include <utility>

Function::Function(std::string modifier, std::string returnType, std::string name, bool isStatic, bool abstract) {
    this->modifier = std::move(modifier);
    this->returnType = std::move(returnType);
    this->setName(std::move(name));
    this->isStatic = isStatic;
    this->params = {};
    this->abstract = abstract;
    this->override = false;
}

bool Function::isFStatic() {
    return isStatic;
}

bool Function::isAbstract() {
    return abstract;
}

bool Function::isOverride() {
    return override;
}

void Function::addParam(std::string type, std::string name) {
    params[name] = std::move(type);
}

std::string Function::getModifier() {
    return modifier;
}

void Function::setAbstract(bool abstract) {
    this->abstract = abstract;
}

void Function::setOverride(bool override) {
    this->override = override;
}

std::map<std::string, std::string> Function::getParams() {
    return params;
}

std::string Function::getReturnType() {
    return returnType;
}

std::string Function::generateCode() {
    std::string code = "        "+modifier+" ";
    if(abstract)
        code+="abstract ";
    if(override){
        code+="override ";
    }else if (isStatic){
        code+="static ";
    }

    code+=returnType+" ";
    code+=getName()+" (";

    int i = 0;
    for (auto p: params) {
        code+=p.second+" ";
        code+=p.first;
        ++i;
        if(i<params.size()){
            code+=", ";
        }
    }

    code+=")\n        {\n\n        }";
    return code;
}

void Function::deleteParam(std::string name) {
    params[name] = "";
}
