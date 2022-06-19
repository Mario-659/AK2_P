#include "gtest/gtest.h"

#include "../include/Adder.hpp"
#include "../include/Utils.hpp"

TEST(AdderTest, testOneBitFullAdder){
    // truth table
    bool A[] = {0, 0, 0, 0, 1, 1, 1, 1};
    bool B[] = {0, 0, 1, 1, 0, 0, 1, 1};
    bool C[] = {0, 1,0, 1, 0, 1, 0, 1,};
    bool S[] = {0, 1,1, 0, 1, 0, 0, 1,};
    bool carryOut[] = {0, 0, 0, 1, 0, 1, 1, 1};

    Adder adder;
    for (int i=0; i<8; i++) {
        ASSERT_EQ(S[i], adder.fullAdder(A[i], B[i], C[i]));
        ASSERT_EQ(carryOut[i], adder.carry);
    }
}

TEST(AdderTest, shouldAdd6With5) {
    constexpr int NUM_SIZE = 8;
    bool* num1 = utils::intToBitArray<NUM_SIZE>(6);
    bool* num2 = utils::intToBitArray<NUM_SIZE>(5);
    Adder adder;

    bool* result = adder.add(num1, num2, 8);
    unsigned long resultNum = utils::bitArrayToULong<NUM_SIZE>(result);

    EXPECT_EQ(11, resultNum);
}

TEST(AdderTest, shouldAddTwoZeroes) {
    bool num1[] = {0, 0, 0, 0};
    bool num2[] = {0, 0, 0, 0};
    Adder adder;

    bool* result = adder.add(num1, num2, 4);

    for (int i=0; i<=4; i++) {
        ASSERT_FALSE(result[i]);
    }
}

TEST(AdderTest, shouldAdd6With5_BOOST) {
    constexpr int NUM_SIZE = 8;
    boost::dynamic_bitset<> num1(8, 6);
    boost::dynamic_bitset<> num2(8, 5);
    Adder adder;

    auto result = adder.add(num1, num2);

    EXPECT_EQ(11, result.to_ulong());
}

