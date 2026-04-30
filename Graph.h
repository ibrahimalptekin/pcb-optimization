#ifndef GRAPH_H
#define GRAPH_H

#include "DataStructures.h"
#include <vector>

struct Node {
    int id;
    float x;
    float y;
};

struct Edge {
    int source;
    int destination;
    float weight;
};

class PCBGraph {
private:
    std::vector<Node> nodes;

    // Komşuluk listesi
    std::vector<std::vector<Edge>> adjacencyList;

    // Kruskal için tüm kenar listesi
    std::vector<Edge> edgeList;

public:
    PCBGraph();

    void addNode(float x, float y);
    void addEdge(int source, int destination, float weight);

    int getNodeCount() const;
    int getEdgeCount() const;

    const std::vector<Node>& getNodes() const;
    const std::vector<Edge>& getEdges() const;
    const std::vector<std::vector<Edge>>& getAdjacencyList() const;

    bool isConnected() const;

    void BFS(int start) const;
    void DFS(int start) const;
};

#endif