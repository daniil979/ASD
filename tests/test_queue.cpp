#include "gtest/gtest.h"
#include "../lib_queue/queue.h"

TEST(QueueTest, EnqueueAndDequeue) {
    Queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    
    EXPECT_EQ(queue.dequeue(), 1);
    EXPECT_EQ(queue.dequeue(), 2);
    EXPECT_EQ(queue.dequeue(), 3);
}

TEST(QueueTest, Front) {
    Queue<int> queue;
    queue.enqueue(42);
    
    EXPECT_EQ(queue.front(), 42);
    EXPECT_EQ(queue.size(), 1);
}

TEST(QueueTest, Empty) {
    Queue<int> queue;
    EXPECT_TRUE(queue.empty());
    
    queue.enqueue(1);
    EXPECT_FALSE(queue.empty());
    
    queue.dequeue();
    EXPECT_TRUE(queue.empty());
}

TEST(QueueTest, Size) {
    Queue<int> queue;
    EXPECT_EQ(queue.size(), 0);
    
    queue.enqueue(1);
    queue.enqueue(2);
    EXPECT_EQ(queue.size(), 2);
    
    queue.dequeue();
    EXPECT_EQ(queue.size(), 1);
}

TEST(QueueTest, DequeueEmptyQueue) {
    Queue<int> queue;
    EXPECT_THROW(queue.dequeue(), std::out_of_range);
}

TEST(QueueTest, FrontEmptyQueue) {
    Queue<int> queue;
    EXPECT_THROW(queue.front(), std::out_of_range);
}

TEST(QueueTest, Clear) {
    Queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    
    queue.clear();
    EXPECT_TRUE(queue.empty());
    EXPECT_EQ(queue.size(), 0);
}
