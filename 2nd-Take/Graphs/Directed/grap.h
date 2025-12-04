#ifndef GRAP_H
#define GRAP_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 6

typedef char vertexType;

// This is for the matrix
typedef int labelType;

typedef struct {
    vertexType tail;
    vertexType head;
    int weight;
} edgeType;

// This is for list
typedef struct {
    vertexType adjVertex;
    int weight;
} adjType;

typedef struct node {
    adjType info;
    struct node* link;
} *AdjList;

typedef struct {
    AdjList heads[MAX];
    int edgeCount;
} directedAdjList;

typedef struct {
    labelType matrix[MAX][MAX];
    int edgeCount;
} labeledAdjList;

adjType createAdjType(vertexType v, int weight) {
    adjType initADJ;

    initADJ.adjVertex = v;
    initADJ.weight = weight;

    return initADJ;
}

void initDirectedAdjList(directedAdjList* l) {
    l->edgeCount = 0;
    for (int i = 0; i < MAX; i++)
    {
        l->heads[i] = NULL;
    }
    
}

void addEdge(directedAdjList* l, vertexType tail, adjType edge) {
    int tailNdx = tail - 'A';
    int adj = edge.adjVertex - 'A';

    if (tailNdx < 0 || tailNdx >= MAX || adj < 0 || adj >= MAX) return;
    
    AdjList newNode = malloc(sizeof(AdjList));

    if (newNode != NULL)
    {
        newNode->info = edge;
        newNode->link = l->heads[tailNdx];
        l->heads[tailNdx] = newNode;
        l->edgeCount++;
    }
    
}

void displayAdjList(directedAdjList l) {
    for (int i = 0; i < l.edgeCount; i++)
    {
        printf("%c :: ", 'A' + i);
        if (l.heads[i] != NULL)
        {
            AdjList trav = l.heads[i];

            for (; trav != NULL; trav = trav->link)
            {
                printf("%c {%d}\t", trav->info.adjVertex, trav->info.weight);
            }
            
        }
        else
        {
            printf("NULL");
        }
        printf("\n");
    }
    printf("\nEdge Counted: %d\n", l.edgeCount);
}

#endif