//
// Created by andre on 15.03.2022.
//

#ifndef TASK2_GENERABLEOBJECT_H
#define TASK2_GENERABLEOBJECT_H

#include <string>

class GenerableObject {
private:
    std::string name;
public:
    ~GenerableObject();
    std::string getName();
    void setName(std::string name);

    virtual std::string generateCode();
};

#endif //TASK2_GENERABLEOBJECT_H
