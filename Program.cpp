//
// Created by andre on 15.03.2022.
//

#include <iostream>
#include "Program.h"

Program::Program() {
    namespaces = {};
}

void Program::start() {
    showMainMenu();
}

void Program::initDefaultData() {
    Function* f1 = new Function("public", "void", "f1", false, false);
    f1->addParam("int", "param1");
    f1->addParam("string", "param2");

    Function* f2 = new Function("public", "void", "f1", false, false);
    f2->setOverride(true);
    f2->addParam("int", "param1");
    f2->addParam("string", "param2");

    Property* p1 = new Property("public", "int", "X", true, true);
    Property* p2 = new Property("public", "int", "Y", true, false);

    Class* class1 = new Class("Class1", true);
    class1->addFunction(f1);
    class1->addProperty(p1);
    class1->addProperty(p2);

    Class* class2 = new Class("Class2", false);
    class2->addFunction(f2);
    class2->setParent(class1);

    Namespace* namespace1 = new Namespace("MyClasses");
    namespace1->addClass(class1);
    namespace1->addClass(class2);

    namespaces[namespace1->getName()] = namespace1;
}

void Program::showMainMenu() {
    int input = 0;
    std::cout << "Main menu" << std::endl;
    std::cout << "0 - Exit" << std::endl
         << "1 - Show Namespaces" << std::endl
         << "2 - Add Namespace" << std::endl;

    std::cin >> input;
    switch (input) {
        case 0:{
            return;
        }
            break;
        case 1: {
            std::cout << std::endl;
            showNamespacesMenu();
        }
            break;
        case 2: {
            std::string name;
            std::cout << "Enter new namespace name" << std::endl;
            std::cin >> name;
            if (namespaces[name] != nullptr) {
                std::cout << "Name is busy" << std::endl;
            }else{
                namespaces[name] = new Namespace(name);
                std::cout << "Namespace was added" << std::endl;
            }

            showMainMenu();
        }
            break;
    }
}

void Program::showNamespacesMenu() {
    int input = 0;
    std::cout << "Namespaces menu" << std::endl;
    for(auto n: namespaces){
        if(n.second!= nullptr)
            std::cout << " - " << n.first << std::endl;
    }
    std::cout << "0 - Back" << std::endl
              << "1 - View namespace" << std::endl;

    std::cin >> input;
    switch (input) {
        case 0:{
            showMainMenu();
        }
        case 1: {
            std::string name;
            std::cout << "Enter namespace name" << std::endl;
            std::cin >> name;
            if (namespaces[name]==nullptr) {
                std::cout << "This namespace isn`t exists. Try again.\n" << std::endl;
                showNamespacesMenu();
            }else{
                showClassesMenu(name);
            }
        }
            break;
    }
}

void Program::showClassesMenu(std::string name) {
    int input = 0;
    std::cout << "Classes menu" << std::endl;
    std::cout << " - " << name << std::endl;
    for(auto c: namespaces[name]->getClasses()){
        if(c.second!= nullptr)
            std::cout << "     - " << c.first << std::endl;
    }
    std::cout << "0 - Back" << std::endl
              << "1 - View class" << std::endl
              << "2 - Add class" << std::endl
              << "3 - View namespace code" << std::endl
              << "4 - Delete class" << std::endl;

    std::cin >> input;
    switch (input) {
        case 0:{
            showNamespacesMenu();
        }
        case 1: {
            std::string viewClassName;
            std::cout << "Enter class name" << std::endl;
            std::cin >> viewClassName;
            if (namespaces[name]->getClasses()[viewClassName]==nullptr) {
                std::cout << "This class isn`t exists. Try again.\n" << std::endl;
                showClassesMenu(name);
            }else{
                showClassViewMenu(name, namespaces[name]->getClasses()[viewClassName]);
            }
        }
            break;
        case 2: {
            std::string className;
            int isAbstract;
            std::string parent;

            std::cout << "Enter new class name" << std::endl;
            std::cin >> className;

            if (namespaces[name]->getClasses()[className]!=nullptr) {
                std::cout << "Name is busy" << std::endl;
            }else{
                std::cout << "0 - not abstract" << std::endl
                          << "else - abstract" << std::endl;
                std::cin >> isAbstract;
                std::cout << "Enter parent name if need" << std::endl;
                std::cin >> parent;
                Class* newClass = new Class(className, isAbstract);
                if(namespaces[name]->getClasses()[parent]!= nullptr){
                    newClass->setParent(namespaces[name]->getClasses()[parent]);
                }
                namespaces[name]->addClass(newClass);

                std::cout << "Class was added" << std::endl;
            }

            showClassesMenu(name);
        }
            break;
        case 3: {
            std::cout << namespaces[name]->generateCode() << std::endl;
            showClassesMenu(name);
        }
            break;
        case 4: {
            std::string deleteName;
            std::cout << "Enter class name" << std::endl;
            std::cin >> deleteName;
            if(namespaces[name]->getClasses()[deleteName]!= nullptr){
                namespaces[name]->deleteClass(deleteName);
                std::cout << "Class " << deleteName << " deleted" << std::endl;
            }else{
                std::cout << "Class not found" << std::endl;
            }
            showClassesMenu(name);
        }
            break;
    }
}

void Program::showClassViewMenu(std::string namespaceName, Class* thisClass) {
    int input = 0;
    std::cout << "Class menu" << std::endl;
    std::cout << " - " << namespaceName << std::endl;
    std::cout << "     - " << thisClass->getName() << std::endl;
    std::cout << "         " << "properties:" << std::endl;
    for(auto c: thisClass->getProperties()){
        if(c.second!= nullptr)
            std::cout << "         - " << c.first << std::endl;
    }
    std::cout << "         " << "methods:" << std::endl;
    for(auto c: thisClass->getFunctions()){
        if(c.second!= nullptr)
            std::cout << "         - " << c.first << std::endl;
    }
    std::cout << "0 - Back" << std::endl
              << "1 - View method" << std::endl
              << "2 - Add method" << std::endl
              << "3 - Add property" << std::endl
              << "4 - View class code" << std::endl
              << "5 - Delete method" << std::endl
              << "6 - Delete property" << std::endl
              << "7 - Is class correct" << std::endl;

    std::cin >> input;
    switch (input) {
        case 0:{
            showClassesMenu(namespaceName);
        }
        case 1: {
            std::string viewMethodName;
            std::cout << "Enter method name" << std::endl;
            std::cin >> viewMethodName;
            if (thisClass->getFunctions()[viewMethodName]==nullptr) {
                std::cout << "This method isn`t exists. Try again.\n" << std::endl;
                showClassViewMenu(namespaceName, thisClass);
            }else{
                showFunctionViewMenu(namespaceName, thisClass, thisClass->getFunctions()[viewMethodName]);
            }
        }
            break;
        case 2: {
            std::string methodName;
            int isAbstract;
            int isStatic;
            std::string modifier;
            std::string returnType;

            std::cout << "Enter new method name" << std::endl;
            std::cin >> methodName;

            if (thisClass->getFunctions()[methodName]!=nullptr) {
                std::cout << "Name is busy" << std::endl;
            }else{
                std::cout << "0 - not abstract" << std::endl
                          << "else - abstract" << std::endl;
                std::cin >> isAbstract;
                std::cout << "0 - not static" << std::endl
                          << "else - static" << std::endl;
                std::cin >> isStatic;
                std::cout << "Enter modifier" << std::endl;
                std::cin >> modifier;
                std::cout << "Enter returnType" << std::endl;
                std::cin >> returnType;
                Function* newFunc = new Function(modifier,returnType,methodName,isStatic,isAbstract);

                thisClass->addFunction(newFunc);

                std::cout << "Function was added" << std::endl;
            }

            showClassViewMenu(namespaceName, thisClass);
        }
        case 3: {
            std::string propName;
            int gettable;
            int settable;
            std::string modifier;
            std::string type;

            std::cout << "Enter new property name" << std::endl;
            std::cin >> propName;

            if (thisClass->getProperties()[propName]!=nullptr) {
                std::cout << "Name is busy" << std::endl;
            }else{
                std::cout << "0 - not getter" << std::endl
                          << "else - getter" << std::endl;
                std::cin >> gettable;
                std::cout << "0 - not setter" << std::endl
                          << "else - setter" << std::endl;
                std::cin >> settable;
                std::cout << "Enter modifier" << std::endl;
                std::cin >> modifier;
                std::cout << "Enter type" << std::endl;
                std::cin >> type;
                Property* newProp = new Property(modifier, type,propName,gettable,settable);

                thisClass->addProperty(newProp);

                std::cout << "Property was added" << std::endl;
            }

            showClassViewMenu(namespaceName, thisClass);
        }
            break;
        case 4: {
            std::cout << thisClass->generateCode() << std::endl;
            showClassViewMenu(namespaceName, thisClass);
        }
            break;
        case 5: {
            std::string deleteName;
            std::cout << "Enter method name" << std::endl;
            std::cin >> deleteName;
            if(thisClass->getFunctions()[deleteName]!= nullptr){
                thisClass->deleteFunction(deleteName);
                std::cout << "Method " << deleteName << " deleted" << std::endl;
            }else{
                std::cout << "Method not found" << std::endl;
            }
            showClassViewMenu(namespaceName, thisClass);
        }
            break;
        case 6: {
            std::string deleteName;
            std::cout << "Enter property name" << std::endl;
            std::cin >> deleteName;
            if(thisClass->getProperties()[deleteName]!= nullptr){
                thisClass->deleteProperty(deleteName);
                std::cout << "Property " << deleteName << " deleted" << std::endl;
            }else{
                std::cout << "Property not found" << std::endl;
            }
            showClassViewMenu(namespaceName, thisClass);
        }
            break;
        case 7: {
            bool isCorrect = thisClass->isCorrect();
            if(isCorrect)
                std::cout << "True" << std::endl;
            else
                std::cout << "False" << std::endl;
            showClassViewMenu(namespaceName, thisClass);
        }
            break;
    }
}

void Program::showFunctionViewMenu(std::string namespaceName, Class* thisClass, Function *function) {
    int input = 0;
    std::cout << "Method menu" << std::endl;
    std::cout << " - " << namespaceName << std::endl;
    std::cout << "     - " << thisClass->getName() << std::endl;
    std::cout << "         - " << function->getName() << std::endl;

    for(auto c: function->getParams()){
        if(c.first!="")
            std::cout << "             - " << c.second+" "+c.first << std::endl;
    }

    std::cout << "0 - Back" << std::endl
              << "1 - Add parameter" << std::endl
              << "2 - View method code" << std::endl
              << "3 - Delete parameter" << std::endl;

    std::cin >> input;
    switch (input) {
        case 0:{
            showClassViewMenu(namespaceName, thisClass);
        }
        case 1: {
            std::string paramName;
            std::string type;

            std::cout << "Enter new parameter name" << std::endl;
            std::cin >> paramName;

            if (!function->getParams()[paramName].empty()) {
                std::cout << "Name is busy" << std::endl;
            }else{
                std::cout << "Enter type" << std::endl;
                std::cin >> type;

                function->addParam(type, paramName);

                std::cout << "Parameter was added" << std::endl;
            }

            showFunctionViewMenu(namespaceName, thisClass, function);
        }
        case 2: {
            std::cout << function->generateCode() << std::endl;
            showFunctionViewMenu(namespaceName, thisClass, function);
        }
            break;
        case 3: {
            std::string deleteName;
            std::cout << "Enter parameter name" << std::endl;
            std::cin >> deleteName;
            if(!function->getParams()[deleteName].empty()){
                function->deleteParam(deleteName);
                std::cout << "Parameter " << deleteName << " deleted" << std::endl;
            }else{
                std::cout << "Parameter not found" << std::endl;
            }
            showFunctionViewMenu(namespaceName, thisClass, function);
        }
            break;
    }
}

Program::~Program() {
    for (auto i: namespaces) {
        delete &i;
    }
    namespaces.clear();
}