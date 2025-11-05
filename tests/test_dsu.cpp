#include "gtest/gtest.h"
#include "../lib_dsu/dsu.h"

TEST(DSUTest, ConstructorAndBasicOperations) {
    DSU dsu(5);
    
    EXPECT_EQ(dsu.find(0), 0);
    EXPECT_EQ(dsu.find(1), 1);
    EXPECT_EQ(dsu.find(2), 2);
    
    dsu.unite(0, 1);
    EXPECT_TRUE(dsu.sameSet(0, 1));
    EXPECT_FALSE(dsu.sameSet(0, 2));
    
    dsu.unite(1, 2);
    EXPECT_TRUE(dsu.sameSet(0, 2));
}

TEST(DSUTest, UnionAndFind) {
    DSU dsu(10);
    
    dsu.unite(0, 1);
    dsu.unite(1, 2);
    dsu.unite(3, 4);
    dsu.unite(5, 6);
    dsu.unite(6, 7);
    
    EXPECT_TRUE(dsu.sameSet(0, 2));
    EXPECT_TRUE(dsu.sameSet(3, 4));
    EXPECT_TRUE(dsu.sameSet(5, 7));
    EXPECT_FALSE(dsu.sameSet(0, 3));
    EXPECT_FALSE(dsu.sameSet(4, 5));
    EXPECT_FALSE(dsu.sameSet(8, 9));
}

TEST(DSUTest, PathCompression) {
    DSU dsu(5);
    
    dsu.unite(0, 1);
    dsu.unite(1, 2);
    dsu.unite(2, 3);
    dsu.unite(3, 4);
    
    int root = dsu.find(4);
    EXPECT_EQ(root, dsu.find(0));
    EXPECT_TRUE(dsu.sameSet(0, 4));
}

TEST(DSUTest, OutOfBounds) {
    DSU dsu(3);
    
    EXPECT_THROW(dsu.find(5), std::out_of_range);
    EXPECT_THROW(dsu.find(-1), std::out_of_range);
}

TEST(DSUTest, GetSize) {
    DSU dsu(7);
    EXPECT_EQ(dsu.getSize(), 7);
}
