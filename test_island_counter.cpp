#include "gtest/gtest.h"
#include "island_counter.h"

TEST(IslandCounterTest, EmptyMatrix) {
    std::vector<std::vector<int>> empty;
    EXPECT_EQ(IslandCounter::countIslands(empty), 0);
}

TEST(IslandCounterTest, SingleIsland) {
    std::vector<std::vector<int>> matrix = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 0}
    };
    EXPECT_EQ(IslandCounter::countIslands(matrix), 1);
}

TEST(IslandCounterTest, MultipleIslands) {
    std::vector<std::vector<int>> matrix = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}
    };
    EXPECT_EQ(IslandCounter::countIslands(matrix), 3);
}

TEST(IslandCounterTest, NoIslands) {
    std::vector<std::vector<int>> matrix = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    EXPECT_EQ(IslandCounter::countIslands(matrix), 0);
}

TEST(IslandCounterTest, AllOnes) {
    std::vector<std::vector<int>> matrix = {
        {1, 1},
        {1, 1}
    };
    EXPECT_EQ(IslandCounter::countIslands(matrix), 1);
}

TEST(IslandCounterTest, DiagonalIslands) {
    std::vector<std::vector<int>> matrix = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    EXPECT_EQ(IslandCounter::countIslands(matrix), 3);
}
