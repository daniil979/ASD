#include "dsu.h"
#include <stdexcept>

DSU::DSU(int _size) : size(_size) {
    parent.resize(size);
    rank.resize(size, 0);
    for (int i = 0; i < size; i++) {
        parent[i] = i;
    }
}

DSU::~DSU() {
}

int DSU::find(int x) {
    if (x < 0 || x >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void DSU::unite(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB) {
        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        } else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
    }
}

bool DSU::sameSet(int a, int b) {
    return find(a) == find(b);
}

int DSU::getSize() const {
    return size;
}
