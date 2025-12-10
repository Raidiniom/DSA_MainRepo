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

    printf("\n--- DFS Traversal ---\n");
    int visited[maxsize] = {0};
    DFS(G, 'A', visited);

    printf("\n\n--- BFS Traversal ---\n");
    BFS(G, 'A');

    // =============================
    // DIJKSTRA
    // =============================
    printf("\n\n--- DIJKSTRA (from A) ---\n");
    dijkstra(G, 'A');

    // =============================
    // WARSHALL (TRANSITIVE CLOSURE)
    // =============================
    printf("\n\n--- WARSHALL ---\n");
    warshall(G);



    // =============================
    // UNDIRECTED GRAPH FOR MST
    // =============================
    DirectedAdjList H;
    initDAL(&H);

    addEdge(&H, 'A', createEdgeType('B', 4));
    addEdge(&H, 'B', createEdgeType('A', 4));

    addEdge(&H, 'A', createEdgeType('C', 2));
    addEdge(&H, 'C', createEdgeType('A', 2));

    addEdge(&H, 'B', createEdgeType('C', 5));
    addEdge(&H, 'C', createEdgeType('B', 5));

    addEdge(&H, 'B', createEdgeType('D', 10));
    addEdge(&H, 'D', createEdgeType('B', 10));

    addEdge(&H, 'C', createEdgeType('E', 3));
    addEdge(&H, 'E', createEdgeType('C', 3));

    addEdge(&H, 'D', createEdgeType('E', 4));
    addEdge(&H, 'E', createEdgeType('D', 4));

    addEdge(&H, 'E', createEdgeType('A', 7));
    addEdge(&H, 'A', createEdgeType('E', 7));

    printf("\n\n--- UNDIRECTED GRAPH FOR MST ---\n");
    displayDAL(H, "UNDIRECTED GRAPH");

    // =============================
    // PRIM
    // =============================
    printf("\n\n--- PRIM'S MST ---\n");
    prim(H);

    // =============================
    // KRUSKAL
    // =============================
    printf("\n\n--- KRUSKAL'S MST ---\n");
    kruskal(H);
}