#include "Function.h"
#include "Program.h"

int main() {
    Program* program = new Program();
    program->initDefaultData();
    program->start();
    delete program;
    return 0;
}
