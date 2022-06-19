#include <iostream>
#include "../include/ProposedIntegerMultiplier.hpp"


int main() {

    //* bits
    boost::dynamic_bitset<> a0(8, 0b11010010);
    boost::dynamic_bitset<> b0(9, 0b110101101);
    boost::dynamic_bitset<> b1(9, 0b100010101);
    boost::dynamic_bitset<> b2(9, 0b111010000);
    
    Subnumbers aSub {
        a0
    };

    Subnumbers bSub {
        b0, b1, b2
    };

    std::cout << "a0 |";
    for (size_t i = 0; i <  a0.size(); i++) {
        std::cout << (int) a0[i];
    }
    std::cout << "|" << std::endl;

    std::cout << "b0 |";
    for (size_t i = 0; i <  b0.size(); i++) {
        std::cout << (int) b0[i];
    }
    std::cout << "|" << std::endl;

    std::cout << "b1 |";
    for (size_t i = 0; i <  b1.size(); i++) {
        std::cout << (int) b1[i];
    }
    std::cout << "|" << std::endl;

    std::cout << "b2 |";
    for (size_t i = 0; i <  b2.size(); i++) {
        std::cout << (int) b2[i];
    }
    std::cout << "|" << std::endl;

    ProposedIntegerMultiplier multiplier(&aSub, &bSub);
    multiplier.performMultiplication();


    std::cout << "Multiplication result is: " << std::endl;
    std::cout << "|";
    for (size_t i = 0; i <  multiplier.resultRegister.size(); i++) {
        std::cout << (int) multiplier.resultRegister[i];
    }
    std::cout << "| size: " << multiplier.resultRegister.size() << " bits" << std::endl;

    return 0;
}
