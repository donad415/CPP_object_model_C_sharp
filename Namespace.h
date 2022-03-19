//
// Created by andre on 15.03.2022.
//

#ifndef TASK2_NAMESPACE_H
#define TASK2_NAMESPACE_H

#include <map>
#include "GenerableObject.h"
#include "Class.h"

class Namespace: public GenerableObject{
private:
    std::map<std::string, Class*> classes;
public:
    Namespace(std::string name);

    ~Namespace();

    Class& addClass(Class* newClass);

    void deleteClass(std::string deleteName);

    std::map<std::string, Class*> getClasses();

    std::string generateCode();
};

#endif //TASK2_NAMESPACE_H
