#ifndef GRP_H
#define GRP_H

#include <stdio.h>
#include <stdlib.h>

#define maxsize 5

typedef struct {
    char tail;
    int weight;
} edgeType;

typedef struct node { 
    edgeType info;
    struct node* link;
} *AdjList;

typedef struct {
    AdjList head[maxsize];
    int edgeCount;
} DirectedAdjList;

// For BFS
typedef struct qnode {
    char vertex;
    struct qnode* next;
} *Node;

typedef struct {
    Node front;
    Node rear;
} Queue;

// For kruskal
typedef struct {
    int u, v;
    int weight;
} Edge;

// Queue
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(Queue* q, char vertex) {
    Node newNode = malloc(sizeof(struct qnode));

    if (newNode != NULL)
    {
        newNode->vertex = vertex;
        newNode->next = NULL;

        if (q->front == NULL)
        {
            newNode->next = q->front;
            q->front = newNode;
            q->rear = newNode;
        }
        else
        {
            q->rear->next = newNode;
            q->rear = newNode;
        }
        
    }
    
}

void dequeue(Queue* q) {
    if (q->front != NULL)
    {
        Node deleteThis = q->front;
        q->front = deleteThis->next;
        
        if (q->front == NULL)
        {
            q->rear = NULL;
        }
        
        free(deleteThis);
    }
    
}

void debugQueue(Queue q) {
    for (Node trav = q.front; trav != NULL; trav = trav->next)
    {
        printf("%c ", trav->vertex);
    }
    
}

// Graph
edgeType createEdgeType(char tail, int weight) {
    edgeType start;

    start.tail = tail;
    start.weight = weight;

    return start;
}

void initDAL(DirectedAdjList* dal) {
    dal->edgeCount = 0;

    for (int i = 0; i < maxsize; i++)
    {
        dal->head[i] = NULL;
    }
    
}

void addEdge(DirectedAdjList* dal, char head, edgeType tail) {
    int index = head - 'A';

    if (index >= 0 && index < maxsize) 
    {
        AdjList newNode = malloc(sizeof(struct node));
    
        if (newNode != NULL)
        {
            newNode->info = tail;
            newNode->link = dal->head[index];
            dal->head[index] = newNode;
        
            dal->edgeCount++;
        }
    }
}

void removeEdge(DirectedAdjList* dal, char head, char tail) {
    int index = head - 'A';

    if (index >= 0 && index < maxsize)
    {
        AdjList* find = &dal->head[index];

        for (; *find != NULL && (*find)->info.tail != tail; find = &(*find)->link){}
        
        if (*find != NULL)
        {
            AdjList removeThis = *find;
            *find = removeThis->link;

            free(removeThis);
            dal->edgeCount--;
        }
        
    }
    
}

void DFS(DirectedAdjList G, char src, int visited[]) {
    visited[src - 'A'] = 1;
    printf("%c ", src);

    AdjList trav;
    for (trav = G.head[src - 'A']; trav != NULL; trav = trav->link) {
        char next = trav->info.tail;
        if (!visited[next - 'A']) {
            DFS(G, next, visited);
        }
    }
}

void BFS(DirectedAdjList G, char src) {
    int visited[maxsize] = {0};
    Queue q;
    
    initQueue(&q);
    
    // Mark source as visited and enqueue
    visited[src - 'A'] = 1;
    enqueue(&q, src);
    
    printf("BFS starting from %c: ", src);
    
    while (q.front != NULL) {
        // Get front vertex
        char currV = q.front->vertex;
        printf("%c ", currV);
        
        // Dequeue
        dequeue(&q);
        
        // Visit all adjacent vertices
        AdjList trav;
        for (trav = G.head[currV - 'A']; trav != NULL; trav = trav->link) {
            char adjVertex = trav->info.tail;
            int idx = adjVertex - 'A';
            
            if (idx >= 0 && idx < maxsize && !visited[idx]) {
                visited[idx] = 1;
                enqueue(&q, adjVertex);
            }
        }
    }
    printf("\n");
}

// Algos
void toMatrix(DirectedAdjList G, int matrix[maxsize][maxsize]) {
    for (int i = 0; i < maxsize; i++) {
        for (int j = 0; j < maxsize; j++) {
            matrix[i][j] = 0; 
        }
    }

    for (int i = 0; i < maxsize; i++) {
        AdjList trav = G.head[i];
        while (trav != NULL) {
            int col = trav->info.tail - 'A';
            matrix[i][col] = trav->info.weight;
            trav = trav->link;
        }
    }
}

int find(int parent[], int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent, parent[x]);
}

void unite(int parent[], int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    parent[b] = a;
}

void dijkstra(DirectedAdjList G, char src) {
    int matrix[maxsize][maxsize];
    toMatrix(G, matrix);

    int dist[maxsize];
    int visited[maxsize] = {0};

    for (int i = 0; i < maxsize; i++)
        dist[i] = 9999;

    int s = src - 'A';
    dist[s] = 0;

    for (int step = 0; step < maxsize; step++) {
        // Step 1: get minimum distance unvisited
        int minDist = 9999, u = -1;
        for (int i = 0; i < maxsize; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break; 
        visited[u] = 1;

        // Step 2: relax neighbors
        for (int v = 0; v < maxsize; v++) {
            if (matrix[u][v] > 0 && !visited[v]) {
                int newDist = dist[u] + matrix[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                }
            }
        }
    }

    printf("\nDijkstra from %c:\n", src);
    for (int i = 0; i < maxsize; i++)
        printf("%c : %d\n", 'A' + i, dist[i]);
}

void prim(DirectedAdjList G) {
    int matrix[maxsize][maxsize];
    toMatrix(G, matrix);

    int inMST[maxsize] = {0};
    int edgeCount = 0;

    inMST[0] = 1;  // Start at A

    printf("\nPrim's MST Edges:\n");

    while (edgeCount < maxsize - 1) {
        int min = 9999;
        int u = -1, v = -1;

        for (int i = 0; i < maxsize; i++) {
            if (inMST[i]) {
                for (int j = 0; j < maxsize; j++) {
                    if (!inMST[j] && matrix[i][j] > 0 && matrix[i][j] < min) {
                        min = matrix[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1) break;

        printf("%c - %c (%d)\n", 'A'+u, 'A'+v, min);
        inMST[v] = 1;
        edgeCount++;
    }
}

void kruskal(DirectedAdjList G) {
    int matrix[maxsize][maxsize];
    toMatrix(G, matrix);

    Edge edges[50];
    int ecount = 0;

    for (int i = 0; i < maxsize; i++)
        for (int j = i + 1; j < maxsize; j++)
            if (matrix[i][j] > 0) {
                edges[ecount++] = (Edge){i, j, matrix[i][j]};
            }

    // sort edges
    for (int i = 0; i < ecount; i++)
        for (int j = i + 1; j < ecount; j++)
            if (edges[j].weight < edges[i].weight) {
                Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }

    int parent[maxsize];
    for (int i = 0; i < maxsize; i++) parent[i] = i;

    printf("\nKruskal's MST Edges:\n");

    for (int i = 0; i < ecount; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(parent, u) != find(parent, v)) {
            unite(parent, u, v);
            printf("%c - %c (%d)\n", 'A'+u, 'A'+v, edges[i].weight);
        }
    }
}

void warshall(DirectedAdjList G) {
    int reach[maxsize][maxsize];
    toMatrix(G, reach);

    // convert weights to boolean reachability
    for (int i = 0; i < maxsize; i++)
        for (int j = 0; j < maxsize; j++)
            reach[i][j] = reach[i][j] > 0 ? 1 : 0;

    for (int k = 0; k < maxsize; k++)
        for (int i = 0; i < maxsize; i++)
            for (int j = 0; j < maxsize; j++)
                reach[i][j] |= (reach[i][k] && reach[k][j]);

    printf("\nWarshall Reachability Matrix:\n");
    for (int i = 0; i < maxsize; i++) {
        for (int j = 0; j < maxsize; j++)
            printf("%d ", reach[i][j]);
        printf("\n");
    }
}

// Display
void displayDAL(DirectedAdjList dal, char* label) {
    printf("%-16s\n", label);
    for (int i = 0; i < maxsize; i++)
    {
        printf("%c :: ", 'A' + i);

        if (dal.head[i] != NULL)
        {
            AdjList trav = dal.head[i];

            for (; trav != NULL; trav = trav->link)
            {
                printf("%c {%d}\t", trav->info.tail, trav->info.weight);
            }
            
        }
        else
        {
            printf("NULL");
        }
        printf("\n");
        
    }
    
}

#endif