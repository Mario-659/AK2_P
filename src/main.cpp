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

    std::cout << "a0 |" << a0 << "|" << std::endl;

    std::cout << "b0 |" << b0 << "|" << std::endl;

    std::cout << "b1 |" << b1 << "|" << std::endl;

    std::cout << "b2 |" << b2 << "|" << std::endl;

    ProposedIntegerMultiplier multiplier(&aSub, &bSub);
    multiplier.performMultiplication();


    std::cout << "Multiplication result is: " << std::endl;
    std::cout << "|" << multiplier.resultRegister;
    std::cout << "| size: " << multiplier.resultRegister.size() << " bits" << std::endl;

    return 0;
}
