#include <stdio.h>
#include <stdlib.h>
#include "kruskal.h"
#include "unionfind.h"
#include "graph.h"

int compare(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;

    return e1->weight - e2->weight;
}

void KruskalMST(Graph* graph) {
    int V = graph->V;

    int E;
    Edge* edges = getAllEdges(graph, &E);

    qsort(edges, E, sizeof(Edge), compare);

    int* parent = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
        parent[i] = i;

    Edge* result = (Edge*)malloc((V - 1) * sizeof(Edge));

    int e = 0;
    int i = 0;

    while (e < V - 1 && i < E) {
        Edge next = edges[i++];

        int x = find(parent, next.src);
        int y = find(parent, next.dest);

        if (x != y) {
            result[e++] = next;
            Union(parent, x, y);
        }
    }

    printf("\nMST:\n");

    int total = 0;
    for (i = 0; i < e; i++) {
        printf("%d - %d : %d\n",
               result[i].src,
               result[i].dest,
               result[i].weight);

        total += result[i].weight;
    }

    printf("Total cost: %d\n", total);

    free(edges);
    free(parent);
    free(result);
}