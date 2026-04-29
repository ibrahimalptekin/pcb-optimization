#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

// Geçici Kenar (Yol) Yapısı
struct Edge {
    int src, dest;
    double weight;
};

// Geçici Graf Sınıfı
class PCBGraph {
public:
    int V; 
    std::vector<Edge> edges; 

    PCBGraph(int vertices) : V(vertices) {}

    void addConnection(int u, int v, double weight) {
        edges.push_back({u, v, weight});
    }
};

#endif