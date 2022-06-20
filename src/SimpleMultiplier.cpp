#include "../include/SimpleMultiplier.hpp"

using namespace boost;

dynamic_bitset<>* SimpleMultiplier::multiply(dynamic_bitset<>& a, dynamic_bitset<>& b) {

    std::vector<dynamic_bitset<>> products;

    for (int i=0; i<b.size(); i++) {
        if (b[i] == 0) continue;

        dynamic_bitset<> x(a);
        for (int j=0; j<i; j++) x.push_back(0);
        x = x<<i;
        products.push_back(x);
    }

    Adder adder;
    dynamic_bitset<>* sum = new dynamic_bitset<>(a.size());

    for (auto p : products) {
        (*sum) = adder.add(p, *sum);
    }
    
    return sum;
}
