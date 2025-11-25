#ifndef GRAPHD_H
#define GRAPHD_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    char label;
    int weight;
    struct node* link;
} *Node;

typedef struct {
    int numVertices;
    Node Vertices[MAX];
} Graph;

Graph createGraph() {
    Graph initGraph;

    initGraph.numVertices = 0;
    for (int i = 0; i < MAX; i++)
    {
        initGraph.Vertices[i] = NULL;
    }
    
    return initGraph;
}

void createArc(Graph* grp, char srcLabel, char destLabel, int weight) {
    Node newNode = malloc(sizeof(struct node));

    if (newNode == NULL) return;

    newNode->label = srcLabel;
    newNode->weight = weight;
    newNode->link = malloc(sizeof(struct node));

    if (newNode->link == NULL) return;

    newNode->link->label = destLabel;
    newNode->link->weight = weight;
    newNode->link->link = NULL;

    grp->Vertices[grp->numVertices++] = newNode;
}

void displayGraph(Graph grp) {
    for (int i = 0; i < grp.numVertices; i++)
    {
        printf("%c [%d] -> ", grp.Vertices[i]->label, grp.Vertices[i]->weight);

        if (grp.Vertices[i]->link != NULL)
        {
            printf("%c", grp.Vertices[i]->link->label);
        }
        else
        {
            printf("NULL");
        }
        
        
        printf("\n");
    }
    
}

void freeGraph(Graph* grp) {
    for (int i = 0; i < grp->numVertices; i++)
    {
        if (grp->Vertices[i]->link != NULL)
        {
            free(grp->Vertices[i]->link);
        }
        free(grp->Vertices[i]);
        grp->Vertices[i] = NULL;
    }
    
    grp->numVertices = 0;
}

#endif