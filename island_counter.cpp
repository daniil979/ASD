#include "island_counter.h"
#include <vector>

int IslandCounter::countIslands(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    // Создаем DSU для всех ячеек матрицы
    DSU dsu(rows * cols);
    
    // Направления: вверх, вниз, влево, вправо
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // Первый проход: создаем множества для единиц
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) {
                // Проверяем соседей
                for (auto& dir : directions) {
                    int newRow = i + dir[0];
                    int newCol = j + dir[1];
                    
                    if (isValid(newRow, newCol, rows, cols) &&
                        matrix[newRow][newCol] == 1) {
                        // Объединяем с соседом
                        dsu.unite(toIndex(i, j, cols), toIndex(newRow, newCol, cols));
                    }
                }
            }
        }
    }
    
    // Второй проход: подсчитываем уникальные корни
    std::vector<bool> uniqueRoots(rows * cols, false);
    int islandCount = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) {
                int root = dsu.find(toIndex(i, j, cols));
                if (!uniqueRoots[root]) {
                    uniqueRoots[root] = true;
                    islandCount++;
                }
            }
        }
    }
    
    return islandCount;
}

bool IslandCounter::isValid(int row, int col, int rows, int cols) {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

int IslandCounter::toIndex(int row, int col, int cols) {
    return row * cols + col;
}
