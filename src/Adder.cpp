#include "../include/Adder.h"

bit Adder::fullAdder(bit a, bit b, bit carryIn) {
    bit sum = carryIn ^ (a ^ b);
    carry = (a & b) || (b & carryIn) || (a & carryIn);
    return sum;
}

bit Adder::fullAdder(bit a, bit b) {
    return fullAdder(a, b, carry);
}
