#ifndef AK2_P_ADDER_HPP
#define AK2_P_ADDER_HPP

#include <boost/dynamic_bitset.hpp>
#include <bitset>

/* Carry look-ahead adder*/
struct Adder {
    /*
     *  1-bit full adder, sets carry
     */
    bool fullAdder(bool a, bool b, bool carryIn);

    /*
     *  1-bit full adder, uses and sets carry
     */
    bool fullAdder(bool a, bool b);

    /*
     * Carry look ahead adder
     */
    bool* add(bool a[], bool b[], int numOfBits);

    /*
     * Carry look ahead adder
     */
    boost::dynamic_bitset<> add(boost::dynamic_bitset<>& a, boost::dynamic_bitset<>& b);

    /* Represents carry flag */
    bool carry = false;

    Adder() = default;

    ~Adder() = default;
};

#endif //AK2_P_ADDER_H
