#ifndef ISLAND_COUNTER_H
#define ISLAND_COUNTER_H

#include "dsu.h"
#include <vector>

class IslandCounter {
public:
    // Подсчет островов в бинарной матрице
    static int countIslands(const std::vector<std::vector<int>>& matrix);
    
private:
    // Проверка валидности координат
    static bool isValid(int row, int col, int rows, int cols);
    
    // Конвертация 2D координат в 1D индекс для DSU
    static int toIndex(int row, int col, int cols);
};

#endif
