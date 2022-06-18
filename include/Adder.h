#ifndef AK2_P_ADDER_H
#define AK2_P_ADDER_H

#include <bitset>

typedef bool bit;

/* Look ahead adder*/
struct Adder {
    bit carry = false;

    Adder() = default;

    ~Adder() = default;

    /*
     *  1-bit full adder, sets carry
     */
    bit fullAdder(bit a, bit b, bit carryIn);

    /*
     *  1-bit full adder, uses and sets carry
     */
    bit fullAdder(bit a, bit b);
};

#endif //AK2_P_ADDER_H
