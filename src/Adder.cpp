#include "../include/Adder.h"

bool Adder::fullAdder(bool a, bool b, bool carryIn) {
    bool sum = carryIn ^ (a ^ b);
    carry = (a & b) || (b & carryIn) || (a & carryIn);
    return sum;
}

bool Adder::fullAdder(bool a, bool b) {
    return fullAdder(a, b, carry);
}

bool *Adder::add(bool *a, bool *b, int numOfBits) {
    carry = false;
    bool* sum = new bool[numOfBits+1];

    for (int i=0; i<numOfBits; i++)
        sum[i] = fullAdder(a[i], b[i]);

    sum[numOfBits] = carry;
    return sum;
}
