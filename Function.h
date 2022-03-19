//
// Created by andre on 15.03.2022.
//

#ifndef TASK2_FUNCTION_H
#define TASK2_FUNCTION_H

#include <string>
#include <map>
#include "GenerableObject.h"

class Function: public GenerableObject{
private:
    std::string modifier;
    bool isStatic;
    bool abstract;
    bool override;
    std::string returnType;
    std::map<std::string, std::string> params;
public:
    Function(std::string modifier, std::string returnType, std::string name, bool isStatic, bool abstract);

    std::string getModifier();

    bool isAbstract();

    bool isOverride();

    bool isFStatic();

    void deleteParam(std::string name);

    void setAbstract(bool abstract);

    void setOverride(bool override);

    void addParam(std::string type, std::string name);

    std::string getReturnType();

    std::map<std::string, std::string> getParams();

    std::string generateCode();
};


#endif //TASK2_FUNCTION_H
