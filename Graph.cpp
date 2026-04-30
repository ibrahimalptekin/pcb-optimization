#include "Graph.h"
#include <queue>
#include <stack>
#include <iostream>

PCBGraph::PCBGraph() {}

void PCBGraph::addNode(float x, float y) {
    Node node;
    node.id = nodes.size();
    node.x = x;
    node.y = y;

    nodes.push_back(node);
    adjacencyList.push_back(std::vector<Edge>());
}

void PCBGraph::addEdge(int source, int destination, float weight) {
    if (source < 0 || destination < 0) return;
    if (source >= nodes.size() || destination >= nodes.size()) return;
    if (source == destination) return;

    Edge edge;
    edge.source = source;
    edge.destination = destination;
    edge.weight = weight;

    Edge reverseEdge;
    reverseEdge.source = destination;
    reverseEdge.destination = source;
    reverseEdge.weight = weight;

    adjacencyList[source].push_back(edge);
    adjacencyList[destination].push_back(reverseEdge);

    // Yönsüz graf olduğu için edgeList'e tek kez eklenir.
    edgeList.push_back(edge);
}

int PCBGraph::getNodeCount() const {
    return nodes.size();
}

int PCBGraph::getEdgeCount() const {
    return edgeList.size();
}

const std::vector<Node>& PCBGraph::getNodes() const {
    return nodes;
}

const std::vector<Edge>& PCBGraph::getEdges() const {
    return edgeList;
}

const std::vector<std::vector<Edge>>& PCBGraph::getAdjacencyList() const {
    return adjacencyList;
}

bool PCBGraph::isConnected() const {
    if (nodes.empty()) return true;

    std::vector<bool> visited(nodes.size(), false);
    std::queue<int> q;

    visited[0] = true;
    q.push(0);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (const Edge& edge : adjacencyList[current]) {
            int neighbor = edge.destination;

            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    for (bool status : visited) {
        if (!status) return false;
    }

    return true;
}

void PCBGraph::BFS(int start) const {
    if (start < 0 || start >= nodes.size()) return;

    std::vector<bool> visited(nodes.size(), false);
    std::queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        std::cout << current << " ";

        for (const Edge& edge : adjacencyList[current]) {
            int neighbor = edge.destination;

            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    std::cout << std::endl;
}

void PCBGraph::DFS(int start) const {
    if (start < 0 || start >= nodes.size()) return;

    std::vector<bool> visited(nodes.size(), false);
    std::stack<int> s;

    s.push(start);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (!visited[current]) {
            visited[current] = true;
            std::cout << current << " ";

            for (const Edge& edge : adjacencyList[current]) {
                int neighbor = edge.destination;

                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }

    std::cout << std::endl;
}