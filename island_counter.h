#ifndef ISLAND_COUNTER_H
#define ISLAND_COUNTER_H

#include "dsu.h"
#include <vector>

class IslandCounter {
public:
    static int countIslands(const std::vector<std::vector<int>>& matrix);
    
private:
    static bool isValid(int row, int col, int rows, int cols);
    
    static int toIndex(int row, int col, int cols);
};

#endif
