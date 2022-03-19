//
// Created by andre on 15.03.2022.
//

#ifndef TASK2_PROGRAM_H
#define TASK2_PROGRAM_H


#include <map>
#include <string>
#include "Namespace.h"

class Program {
public:
    std::map<std::string, Namespace*> namespaces;

    void initDefaultData();

    void start();

    Program();

    ~Program();

    void showMainMenu();

    void showNamespacesMenu();

    void showClassesMenu(std::string name);

    void showClassViewMenu(std::string namespaceName, Class* thisClass);

    void showFunctionViewMenu(std::string namespaceName, Class* thisClass, Function* function);

};


#endif //TASK2_PROGRAM_H
