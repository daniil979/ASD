#include "gtest/gtest.h"
#include "../lib_algorithms/algorithms.h"

TEST(AlgorithmsTest, CheckBracketsValid) {
    EXPECT_TRUE(check_brackets("()"));
    EXPECT_TRUE(check_brackets("([])"));
    EXPECT_TRUE(check_brackets("({[]})"));
    EXPECT_TRUE(check_brackets("()[]{}"));
    EXPECT_TRUE(check_brackets(""));
}

TEST(AlgorithmsTest, CheckBracketsInvalid) {
    EXPECT_FALSE(check_brackets("("));
    EXPECT_FALSE(check_brackets(")"));
    EXPECT_FALSE(check_brackets("([)]"));
    EXPECT_FALSE(check_brackets("({[}])"));
    EXPECT_FALSE(check_brackets("())"));
}
