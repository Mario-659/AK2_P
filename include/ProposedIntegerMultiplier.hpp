#ifndef PROPOSED_INT_MUL_HPP
#define PROPOSED_INT_MUL_HPP

#include "SimpleMultiplier.hpp"
#include "Utils.hpp"

using namespace boost;

typedef std::vector<dynamic_bitset<>> Subnumbers;

struct ProposedIntegerMultiplier {
    
    Subnumbers* aSubnumbers {};
    Subnumbers* bSubnumbers {};
    dynamic_bitset<> resultRegister {};
    dynamic_bitset<> resultRegisterYounger {};
    dynamic_bitset<> resultRegisterOlder {};

    SimpleMultiplier partialMultiplier {};
    Adder carryLookAheadAdder {};

    ProposedIntegerMultiplier(Subnumbers* aSub, Subnumbers* bSub) {

        this->aSubnumbers = aSub;
        this->bSubnumbers = bSub;
    }

    // ~ProposedIntegerMultiplier() {

    //     delete aSubnumbers;
    //     delete bSubnumbers;
    // }

    void performMultiplication() {

        assert(aSubnumbers->size() == 1);
        assert(aSubnumbers->size() <= bSubnumbers->size());

        //Clear any leftovers from previous multiplications
        resultRegister.clear();
        resultRegister.resize(0);

        dynamic_bitset<> OP0;
        dynamic_bitset<> OP1;

        dynamic_bitset<> a0b0;
        dynamic_bitset<> a0b1;
        dynamic_bitset<> a0b2;


        //STEP 1 - allign partial products
        //And concatenate them into two word Op0 and Op1
        for (size_t i = 0; i < bSubnumbers->size(); i++) {

            dynamic_bitset<>* result = partialMultiplier.multiply(aSubnumbers->at(0),bSubnumbers->at(i));
            if (i == 0) a0b0 = *result;
            if (i == 1) a0b1 = *result;
            if (i == 2) a0b2 = *result;
            if (i % 2 == 0)
                utils::appendToBitset(OP0, *result);
            else
                utils::appendToBitset(OP1, *result);
            
            // TODO some assertion in boost breaks with this
            result->reset();
            delete result;
        }

        std::cout <<"OP0:  "<< OP0  << std::endl;
        std::cout <<"a0b0: "<< a0b0  << std::endl;
        std::cout <<"a0b2: "<< a0b2  << std::endl;
        std::cout <<"OP1:  "<< OP1 << std::endl;
        std::cout <<"a0b1: "<< a0b1  << std::endl;

        //Store OP1 in result register
//        utils::appendToBitset(resultRegister, OP1);
//
//        //STEP 2
//        //Add aligned words and add them to register
//        dynamic_bitset<> shift(8);
//        utils::appendToBitset(resultRegister, shift);
//        resultRegister = carryLookAheadAdder.add(resultRegister, OP0);
        resultRegisterYounger = carryLookAheadAdder.add(a0b0,a0b1);
        resultRegisterOlder = a0b2;
        std::cout << "Younger result: " << resultRegisterYounger << std::endl;
        std::cout << "Older result: " << resultRegisterOlder << std::endl;

        utils::appendToBitset(resultRegister, resultRegisterYounger);
        utils::appendToBitset(resultRegister, resultRegisterOlder);

    }
};

#endif //PROPOSED_INT_MUL_HPP