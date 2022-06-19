#include "gtest/gtest.h"

#include "../include/SimpleMultiplier.hpp"

TEST(AdderTest, shouldMultiply6With5) {
    constexpr int NUM_SIZE = 8;
    boost::dynamic_bitset<> num1(8, 6);
    boost::dynamic_bitset<> num2(8, 5);
    boost::dynamic_bitset<> expected(8, 30);
    SimpleMultiplier mul;

    auto result = mul.multiply(num1, num2);
    
    EXPECT_EQ(expected.to_ulong(), result->to_ulong());
}

TEST(AdderTest, shouldMultiply5With10) {
    constexpr int NUM_SIZE = 8;
    boost::dynamic_bitset<> num1(8, 5);
    boost::dynamic_bitset<> num2(8, 10);
    boost::dynamic_bitset<> expected(8, 50);
    SimpleMultiplier mul;

    auto result = mul.multiply(num1, num2);
    
    EXPECT_EQ(expected.to_ulong(), result->to_ulong());
}
