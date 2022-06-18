#include <iostream>

#include "../include/Adder.h"

int main() {
    Adder adder;
    std::cout << adder.fullAdder(false, true) << std::endl;
    return 0;
}
