#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"
#include "stack.h"

Node* createNode(int dest, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;

    graph->adjList = (Node**)malloc(V * sizeof(Node*));

    for (int i = 0; i < V; i++)
        graph->adjList[i] = NULL;

    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void BFS(Graph* graph, int start) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    Queue q;

    initQueue(&q);

    visited[start] = 1;
    enqueue(&q, start);

    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        printf("%d ", node);

        Node* temp = graph->adjList[node];

        while (temp) {
            if (!visited[temp->dest]) {
                visited[temp->dest] = 1;
                enqueue(&q, temp->dest);
            }
            temp = temp->next;
        }
    }

    free(visited);
}

void DFS(Graph* graph, int start) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    Stack s;

    initStack(&s);

    push(&s, start);

    while (!isStackEmpty(&s)) {
        int node = pop(&s);

        if (!visited[node]) {
            printf("%d ", node);
            visited[node] = 1;
        }

        Node* temp = graph->adjList[node];

        while (temp) {
            if (!visited[temp->dest]) {
                push(&s, temp->dest);
            }
            temp = temp->next;
        }
    }

    free(visited);
}

Edge* getAllEdges(Graph* graph, int* E) {
    int maxEdges = graph->V * graph->V;

    Edge* edges = (Edge*)malloc(maxEdges * sizeof(Edge));
    *E = 0;

    for (int i = 0; i < graph->V; i++) {
        Node* temp = graph->adjList[i];

        while (temp) {
            if (i < temp->dest) {
                edges[*E].src = i;
                edges[*E].dest = temp->dest;
                edges[*E].weight = temp->weight;
                (*E)++;
            }
            temp = temp->next;
        }
    }

    return edges;
}

Graph* resizeGraph(Graph* graph) {
    graph->V++;

    graph->adjList = (Node**)realloc(graph->adjList, graph->V * sizeof(Node*));
    graph->adjList[graph->V - 1] = NULL;

    return graph;
}

void addNode(Graph* graph) {
    resizeGraph(graph);
    printf("Yeni node eklendi: %d\n", graph->V - 1);
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        Node* temp = graph->adjList[i];

        printf("%d -> ", i);

        while (temp) {
            printf("%d(%d) ", temp->dest, temp->weight);
            temp = temp->next;
        }

        printf("\n");
    }
}