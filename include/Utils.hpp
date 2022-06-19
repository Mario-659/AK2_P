#ifndef AK2_P_UTILS_HPP
#define AK2_P_UTILS_HPP

#include <bitset>
#include <string>

#include <boost/dynamic_bitset.hpp>

namespace utils {

    template <size_t bitsetSize>
    unsigned long bitArrayToULong(const bool arr[]){
        // Converts bit array to unsigned long //
        std::bitset<bitsetSize> set(0);
        for (int i=0; i<bitsetSize; i++) {
            set.set(i, arr[i]);
        }

        return set.to_ulong();
    }

    template <size_t bitsetSize>
    bool* intToBitArray(unsigned long num){
        // Converts unsigned long to bit array with given length //
        std::bitset<bitsetSize> set(num);
        bool* arr = new bool[bitsetSize];

        for (int i=0; i<bitsetSize; i++) {
            arr[i] = set[i];
        }

        return arr;
    }

    void appendToBitset(boost::dynamic_bitset<>& x, boost::dynamic_bitset<>& y) {

        for (size_t i = 0; i < y.size(); i++) {
            x.push_back(y[i]);
        }
        
    }

}

#endif //AK2_P_UTILS_H
