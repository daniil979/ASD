#include <gtest/gtest.h>
#include "queue.h"
#include <string>

class QueueTest : public ::testing::Test {
protected:
    void SetUp() override {
        intQueue.enqueue(1);
        intQueue.enqueue(2);
        intQueue.enqueue(3);
    }
    
    void TearDown() override {
        
    }
    
    Queue<int> intQueue;
    Queue<std::string> stringQueue;
    Queue<double> emptyQueue;
};

TEST_F(QueueTest, EnqueueIncreasesSize) {
    EXPECT_EQ(intQueue.size(), 3);
    intQueue.enqueue(4);
    EXPECT_EQ(intQueue.size(), 4);
}

TEST_F(QueueTest, DequeueFIFOOrder) {
    EXPECT_EQ(intQueue.dequeue(), 1);
    EXPECT_EQ(intQueue.dequeue(), 2);
    EXPECT_EQ(intQueue.dequeue(), 3);
}

TEST_F(QueueTest, FrontReturnsFirstElement) {
    EXPECT_EQ(intQueue.front(), 1);
    intQueue.dequeue();
    EXPECT_EQ(intQueue.front(), 2);
}

TEST_F(QueueTest, EmptyQueueBehavior) {
    EXPECT_TRUE(emptyQueue.empty());
    EXPECT_EQ(emptyQueue.size(), 0);
}

TEST_F(QueueTest, EmptyQueueThrowsExceptions) {
    EXPECT_THROW(emptyQueue.dequeue(), std::out_of_range);
    EXPECT_THROW(emptyQueue.front(), std::out_of_range);
}

TEST_F(QueueTest, ClearEmptiesQueue) {
    EXPECT_FALSE(intQueue.empty());
    intQueue.clear();
    EXPECT_TRUE(intQueue.empty());
    EXPECT_EQ(intQueue.size(), 0);
}

TEST_F(QueueTest, StringQueueWorks) {
    stringQueue.enqueue("hello");
    stringQueue.enqueue("world");
    
    EXPECT_EQ(stringQueue.front(), "hello");
    EXPECT_EQ(stringQueue.dequeue(), "hello");
    EXPECT_EQ(stringQueue.front(), "world");
}

TEST_F(QueueTest, MixedOperations) {
    Queue<int> queue;
    
    queue.enqueue(10);
    queue.enqueue(20);
    EXPECT_EQ(queue.dequeue(), 10);
    
    queue.enqueue(30);
    EXPECT_EQ(queue.front(), 20);
    EXPECT_EQ(queue.dequeue(), 20);
    EXPECT_EQ(queue.dequeue(), 30);
    EXPECT_TRUE(queue.empty());
}

TEST_F(QueueTest, SizeAfterOperations) {
    Queue<int> queue;
    
    EXPECT_EQ(queue.size(), 0);
    queue.enqueue(100);
    EXPECT_EQ(queue.size(), 1);
    queue.enqueue(200);
    EXPECT_EQ(queue.size(), 2);
    queue.dequeue();
    EXPECT_EQ(queue.size(), 1);
    queue.clear();
    EXPECT_EQ(queue.size(), 0);
}

