#ifndef AK2_P_MULTIPLIER_H
#define AK2_P_MULTIPLIER_H

#include "../include/Multiplier.h"
#include "../include/Adder.h"

#include <boost/dynamic_bitset.hpp>

struct Multiplier {
    boost::dynamic_bitset<> multiply(boost::dynamic_bitset<> a, boost::dynamic_bitset<> b);
};

#endif //AK2_P_MULTIPLIER_H
