#include "gtest/gtest.h"
#include "../lib_list_based/list_stack.h"
#include <stdexcept>

TEST(ListStackTest, PushAndPop) {
    ListStack<int> stack;
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    EXPECT_EQ(stack.pop(), 30);
    EXPECT_EQ(stack.pop(), 20);
    EXPECT_EQ(stack.pop(), 10);
}

TEST(ListStackTest, Top) {
    ListStack<std::string> stack;
    
    stack.push("hello");
    stack.push("world");
    
    EXPECT_EQ(stack.top(), "world");
    EXPECT_EQ(stack.size(), 2);
}

TEST(ListStackTest, Empty) {
    ListStack<int> stack;
    
    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
    
    stack.push(42);
    EXPECT_FALSE(stack.empty());
    
    stack.pop();
    EXPECT_TRUE(stack.empty());
}

TEST(ListStackTest, Size) {
    ListStack<int> stack;
    
    EXPECT_EQ(stack.size(), 0);
    
    stack.push(1);
    stack.push(2);
    stack.push(3);
    EXPECT_EQ(stack.size(), 3);
    
    stack.pop();
    EXPECT_EQ(stack.size(), 2);
}

TEST(ListStackTest, PopEmptyStack) {
    ListStack<int> stack;
    EXPECT_THROW(stack.pop(), std::out_of_range);
}

TEST(ListStackTest, TopEmptyStack) {
    ListStack<int> stack;
    EXPECT_THROW(stack.top(), std::out_of_range);
}

TEST(ListStackTest, Clear) {
    ListStack<int> stack;
    
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
    stack.clear();
    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
}
