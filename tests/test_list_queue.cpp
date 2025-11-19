#include "gtest/gtest.h"
#include "../lib_list_based/list_queue.h"
#include <stdexcept>

TEST(ListQueueTest, EnqueueAndDequeue) {
    ListQueue<int> queue;
    
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    
    EXPECT_EQ(queue.dequeue(), 10);
    EXPECT_EQ(queue.dequeue(), 20);
    EXPECT_EQ(queue.dequeue(), 30);
}

TEST(ListQueueTest, Front) {
    ListQueue<std::string> queue;
    
    queue.enqueue("hello");
    queue.enqueue("world");
    
    EXPECT_EQ(queue.front(), "hello");
    EXPECT_EQ(queue.size(), 2); 
}

TEST(ListQueueTest, Empty) {
    ListQueue<int> queue;
    
    EXPECT_TRUE(queue.empty());
    EXPECT_EQ(queue.size(), 0);
    
    queue.enqueue(42);
    EXPECT_FALSE(queue.empty());
    
    queue.dequeue();
    EXPECT_TRUE(queue.empty());
}

TEST(ListQueueTest, Size) {
    ListQueue<int> queue;
    
    EXPECT_EQ(queue.size(), 0);
    
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    EXPECT_EQ(queue.size(), 3);
    
    queue.dequeue();
    EXPECT_EQ(queue.size(), 2);
}

TEST(ListQueueTest, DequeueEmptyQueue) {
    ListQueue<int> queue;
    EXPECT_THROW(queue.dequeue(), std::out_of_range);
}

TEST(ListQueueTest, FrontEmptyQueue) {
    ListQueue<int> queue;
    EXPECT_THROW(queue.front(), std::out_of_range);
}

TEST(ListQueueTest, Clear) {
    ListQueue<int> queue;
    
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    
    queue.clear();
    EXPECT_TRUE(queue.empty());
    EXPECT_EQ(queue.size(), 0);
}
