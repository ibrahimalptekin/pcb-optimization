#include <stdio.h>
#include "graph.h"
#include "kruskal.h"
#include "queue.h"
#include "stack.h"
#include "unionfind.h"

int main() {
    Graph* graph = createGraph(4);

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 2, 6);
    addEdge(graph, 0, 3, 5);
    addEdge(graph, 1, 3, 15);
    addEdge(graph, 2, 3, 4);

    printf("Initial Graph:\n");
    printGraph(graph);

    printf("\nBFS: ");
    BFS(graph, 0);

    printf("\nDFS: ");
    DFS(graph, 0);

    int choice;

    while (1) {
        printf("\n\n1-Node ekle\n2-MST calistir\n3-Graph yazdir\n4-Cikis\n");
        scanf("%d", &choice);

        if (choice == 1) {
            addNode(graph);
        }
        else if (choice == 2) {
            KruskalMST(graph);
        }
        else if (choice == 3) {
            printGraph(graph);
        }
        else {
            break;
        }
    }

    return 0;
}