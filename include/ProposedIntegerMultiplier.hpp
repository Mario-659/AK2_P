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

        //STEP 1 - allign partial products
        //And concatenate them into two word Op0 and Op1
        for (size_t i = 0; i < bSubnumbers->size(); i++) {
            
            dynamic_bitset<>* result = partialMultiplier.multiply(bSubnumbers->at(i), aSubnumbers->at(0));

            if (i % 2 == 0)
                utils::appendToBitset(OP0, *result);
            else
                utils::appendToBitset(OP1, *result);
            
            // TODO some assertion in boost breaks with this
            // delete result;
        }

        //Store OP1 in result register
        utils::appendToBitset(resultRegister, OP1);

        //STEP 2
        //Add aligned words and add them to register
        auto addResult = carryLookAheadAdder.add(OP0, OP1);
        utils::appendToBitset(resultRegister, addResult);
    }
};

#endif //PROPOSED_INT_MUL_HPP