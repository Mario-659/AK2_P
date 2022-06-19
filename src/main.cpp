#include <iostream>
#include <vector>
#include <cstdint>
#include <memory>

#include "../include/Adder.h"

struct Bit {

    uint8_t value: 1;

    Bit() {

        this->value = 0;
    }

    Bit(uint8_t value) {

        this->value = value;
    }
};


typedef std::vector<Bit> Bits;
typedef std::unique_ptr<Bits> BitsPtr;


BitsPtr* multiply(std::vector<Bits>& aNumbers, std::vector<Bits>& bNumbers) {

    if (aNumbers.size() > 1)
        throw new std::invalid_argument("A subnumbers count should be 1");
    
    if (aNumbers[0].size() > bNumbers[0].size())
        throw new std::invalid_argument("A subnumber bit width should be <= than B subnumber bit width");

    
    return nullptr;
}


int main() {




    // Adder adder;
    // std::cout << adder.fullAdder(false, true) << std::endl;
    return 0;
}
