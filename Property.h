//
// Created by andre on 15.03.2022.
//

#ifndef TASK2_PROPERTY_H
#define TASK2_PROPERTY_H

#include <string>
#include "GenerableObject.h"

class Property: public GenerableObject {
private:
    std::string modifier;
    std::string type;
    bool getable;
    bool setable;
public:
    Property(std::string modifier, std::string type, std::string name, bool getable, bool setable);

    ~Property();

    std::string getModifier();

    std::string getType();

    bool getGetable();

    bool getSetable();

    std::string generateCode();
};

#endif //TASK2_PROPERTY_H
