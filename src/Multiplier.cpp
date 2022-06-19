#include "../include/Multiplier.h"

using namespace boost;

dynamic_bitset<> Multiplier::multiply(dynamic_bitset<> a, dynamic_bitset<> b) {
    std::vector<dynamic_bitset<>> products;

    for (int i=0; i<b.size(); i++) {
        if (b[i] == 0) continue;

        dynamic_bitset<> x(a);
        x<<=i;
        products.push_back(x);
    }

    Adder adder;
    dynamic_bitset<> sum(a.size());

    for (auto p : products) {
        sum = adder.add(p, sum);
    }
    return sum;
}
