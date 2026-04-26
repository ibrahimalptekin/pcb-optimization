#include "unionfind.h"

int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void Union(int parent[], int x, int y) {
    parent[x] = y;
}