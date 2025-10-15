#include "gtest/gtest.h"
#include "../stack.h"

TEST(StackTest, PushAndPop) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    
    EXPECT_EQ(stack.pop(), 2);
    EXPECT_EQ(stack.pop(), 1);
}

TEST(StackTest, Top) {
    Stack<int> stack;
    stack.push(42);
    
    EXPECT_EQ(stack.top(), 42);
    EXPECT_EQ(stack.size(), 1);
}

TEST(StackTest, Empty) {
    Stack<int> stack;
    EXPECT_TRUE(stack.empty());
    
    stack.push(1);
    EXPECT_FALSE(stack.empty());
    
    stack.pop();
    EXPECT_TRUE(stack.empty());
}

TEST(StackTest, Size) {
    Stack<int> stack;
    EXPECT_EQ(stack.size(), 0);
    
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(stack.size(), 2);
    
    stack.pop();
    EXPECT_EQ(stack.size(), 1);
}

TEST(StackTest, PopEmptyStack) {
    Stack<int> stack;
    EXPECT_THROW(stack.pop(), std::out_of_range);
}

TEST(StackTest, TopEmptyStack) {
    Stack<int> stack;
    EXPECT_THROW(stack.top(), std::out_of_range);
}
