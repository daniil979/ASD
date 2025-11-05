#ifndef DSU_H
#define DSU_H

#include <vector>

class DSU {
private:
    std::vector<int> parent;
    std::vector<int> rank;
    int size;

public:
    DSU(int size);
    ~DSU();
    void unite(int a, int b);
    int find(int x);
    bool sameSet(int a, int b);
    int getSize() const;
};

#endif
