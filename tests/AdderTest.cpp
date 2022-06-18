#include "gtest/gtest.h"

#include "../include/Adder.h"

TEST(AdderTest, sampleTest){
    Adder adder;
    EXPECT_TRUE(adder.fullAdder(true, false));
}
