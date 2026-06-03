#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.h"
#include "DataStructures.h"
#include <algorithm>

class MSTOptimizer {
public:
    // Grafı alır, en iyi yolları hesaplar ve arayüzün çizmesi için geri fırlatır
    static std::vector<Edge> solveKruskal(PCBGraph& graph, double& outTotalCost) {
        std::vector<Edge> mst;
        outTotalCost = 0.0;
        
        if (graph.nodes.empty()) return mst;

        // Bütün olası yolları maliyete göre küçükten büyüğe sırala
        std::vector<Edge> sortedEdges = graph.edges;
        std::sort(sortedEdges.begin(), sortedEdges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });

        UnionFind uf(graph.nodes.size());

        // Sırayla en ucuz yolları al ve döngü yapmıyorsa ana karta ekle
        for (const auto& edge : sortedEdges) {
            if (uf.unite(edge.src, edge.dest)) {
                mst.push_back(edge);
                outTotalCost += edge.weight;
            }
        }
        return mst;
    }
};

#endif
