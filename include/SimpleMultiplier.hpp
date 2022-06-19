#ifndef AK2_P_MULTIPLIER_HPP
#define AK2_P_MULTIPLIER_HPP

#include "../include/Adder.hpp"

#include <boost/dynamic_bitset.hpp>

struct SimpleMultiplier {
    boost::dynamic_bitset<>* multiply(boost::dynamic_bitset<>& a, boost::dynamic_bitset<>& b);
};

#endif //AK2_P_MULTIPLIER_H
