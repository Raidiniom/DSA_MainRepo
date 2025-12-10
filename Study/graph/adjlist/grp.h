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
    
    visited[src - 'A'] = 1;
    enqueue(&q, src);
    
    printf("BFS starting from %c:\n", src);
    
    int step = 0;
    while (q.front != NULL && step < 20) {  // Limit steps for debugging
        printf("Step %d: Queue: ", ++step);
        debugQueue(q);
        
        char currV = q.front->vertex;
        printf(" | Processing: %c | Adjacent: ", currV);
        
        // Show adjacent vertices
        AdjList trav;
        for (trav = G.head[currV - 'A']; trav != NULL; trav = trav->link) {
            printf("%c ", trav->info.tail);
        }
        
        dequeue(&q);
        
        // Enqueue unvisited neighbors
        for (trav = G.head[currV - 'A']; trav != NULL; trav = trav->link) {
            char adjVertex = trav->info.tail;
            int idx = adjVertex - 'A';
            
            if (idx >= 0 && idx < maxsize && !visited[idx]) {
                visited[idx] = 1;
                enqueue(&q, adjVertex);
                printf("(enqueued %c) ", adjVertex);
            }
        }
        printf("\n");
    }
    
    if (step >= 20) {
        printf("Stopped after 20 steps to prevent infinite loop\n");
    }
}

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