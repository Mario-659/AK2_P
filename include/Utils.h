#ifndef AK2_P_UTILS_H
#define AK2_P_UTILS_H

#include <bitset>
#include <string>

namespace utils{

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
}

#endif //AK2_P_UTILS_H
