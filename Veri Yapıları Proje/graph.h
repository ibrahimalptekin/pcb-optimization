#ifndef GRAPH_H
#define GRAPH_H

// forward declaration (çok önemli)
typedef struct Node Node;
typedef struct Graph Graph;

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

/* Graph ve Node tanımları */
struct Node {
    int dest;
    int weight;
    struct Node* next;
};

struct Graph {
    int V;
    Node** adjList;
};

/* Fonksiyonlar */
Graph* createGraph(int V);
void addEdge(Graph* graph, int src, int dest, int weight);

void BFS(Graph* graph, int start);
void DFS(Graph* graph, int start);

void addNode(Graph* graph);
void printGraph(Graph* graph);

/* Kruskal için */
Edge* getAllEdges(Graph* graph, int* E);

#endif