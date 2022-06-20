#include "gtest/gtest.h"

#include "../include/SimpleMultiplier.hpp"

TEST(MultiplierTest, shouldMultiply6With5) {
    constexpr int NUM_SIZE = 8;
    boost::dynamic_bitset<> num1(8, 6);
    boost::dynamic_bitset<> num2(8, 5);
    boost::dynamic_bitset<> expected(8, 30);
    SimpleMultiplier mul;

    auto result = mul.multiply(num1, num2);
    
    EXPECT_EQ(expected.to_ulong(), result->to_ulong());
}

TEST(MultiplierTest, shouldMultiply5With10) {
    constexpr int NUM_SIZE = 8;
    boost::dynamic_bitset<> num1(8, 5);
    boost::dynamic_bitset<> num2(8, 10);
    boost::dynamic_bitset<> expected(8, 50);
    SimpleMultiplier mul;

    auto result = mul.multiply(num1, num2);
    
    EXPECT_EQ(expected.to_ulong(), result->to_ulong());
}

TEST(MultiplierTest, shouldMultiply429With210) {
    constexpr int NUM_SIZE = 8;

    // num1 = 429
    boost::dynamic_bitset<> num1(8, 0b11010010);
    // num2 = 210
    boost::dynamic_bitset<> num2(9, 0b110101101);

    boost::dynamic_bitset<> expected(8, 90090);
    SimpleMultiplier mul;

    auto result = mul.multiply(num2, num1);
    
    EXPECT_EQ(90090, result->to_ulong());
}
