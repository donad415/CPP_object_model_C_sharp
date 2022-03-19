//
// Created by andre on 15.03.2022.
//

#ifndef TASK2_CLASS_H
#define TASK2_CLASS_H


#include <string>
#include <list>
#include <map>
#include "Property.h"
#include "Function.h"

class Class: public GenerableObject {
private:
    std::map<std::string, Property*> properties;
    std::map<std::string, Function*> functions;
    bool abstract;
    Class* parent;

public:
    Class(std::string name, bool abstract);

    ~Class();

    void setParent(Class *parent);

    bool isAbstract();

    void addProperty(Property* property);

    void addFunction(Function* function);

    bool isCorrect();

    std::string generateCode();

    void deleteFunction(std::string name);

    void deleteProperty(std::string name);

    std::map<std::string, Property*> getProperties();

    std::map<std::string, Function*> getFunctions();
};

#endif //TASK2_CLASS_H
