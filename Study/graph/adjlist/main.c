#include "grp.h"

void main() {
    DirectedAdjList G;
    initDAL(&G);

    addEdge(&G, 'A', createEdgeType('B', 4));
    addEdge(&G, 'A', createEdgeType('C', 2));

    addEdge(&G, 'B', createEdgeType('C', 5));
    addEdge(&G, 'B', createEdgeType('D', 10));

    addEdge(&G, 'C', createEdgeType('E', 3));

    addEdge(&G, 'D', createEdgeType('E', 4));

    addEdge(&G, 'E', createEdgeType('A', 7));

    displayDAL(G, "DIRECTED GRAPH");

    // int visited[maxsize] = {0};
    // DFS(G, 'A', visited);
    printf("\n");

    BFS(G, 'A');

    // DirectedAdjList H;
    // initDAL(&H);

    // // A - B
    // addEdge(&H, 'A', createEdgeType('B', 4));
    // addEdge(&H, 'B', createEdgeType('A', 4));

    // // A - C
    // addEdge(&H, 'A', createEdgeType('C', 2));
    // addEdge(&H, 'C', createEdgeType('A', 2));

    // // B - C
    // addEdge(&H, 'B', createEdgeType('C', 5));
    // addEdge(&H, 'C', createEdgeType('B', 5));

    // // B - D
    // addEdge(&H, 'B', createEdgeType('D', 10));
    // addEdge(&H, 'D', createEdgeType('B', 10));

    // // C - E
    // addEdge(&H, 'C', createEdgeType('E', 3));
    // addEdge(&H, 'E', createEdgeType('C', 3));

    // // D - E
    // addEdge(&H, 'D', createEdgeType('E', 4));
    // addEdge(&H, 'E', createEdgeType('D', 4));

    // // E - A
    // addEdge(&H, 'E', createEdgeType('A', 7));
    // addEdge(&H, 'A', createEdgeType('E', 7));

    // displayDAL(H, "UNDIRECTED GRAPH");

}
