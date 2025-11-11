#include "gtest/gtest.h"
#include "../lib_linked_list/linked_list.h"

TEST (LinkedListTest, IteratorReadValues) {
    LinkedList<int> list;
        list.push_back(10);
        list.push_back(20);
        list.push_back(30);
    LinkedList<int>::Iterator it = list.begin();
        EXPECT_EQ(*it, 10);
        
        ++it;
        EXPECT_EQ(*it, 20);
        
        ++it;
        EXPECT_EQ(*it, 30);
        
        
        ++it;
        EXPECT_TRUE(it == list.end());
    }
TEST(LinkedListTest, IteratorWriteValues) {
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    
    LinkedList<int>::Iterator it = list.begin();
    *it = 100;
    
    ++it;
    *it = 200;
    
    ++it;
    *it = 300;
    it = list.begin();
    EXPECT_EQ(*it, 100);
    
    ++it;
    EXPECT_EQ(*it, 200);
    
    ++it;
    EXPECT_EQ(*it, 300);
}
TEST(LinkedListTest, EmptyListWithIterator) {
    LinkedList<std::string> list;
    
    EXPECT_TRUE(list.empty());
    EXPECT_TRUE(list.begin() == list.end());
    
    list.push_back(" ");
    EXPECT_FALSE(list.begin() == list.end());
    EXPECT_EQ(*list.begin(), " ");
}
