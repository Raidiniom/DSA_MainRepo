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
    char label;
    Node adjlst;
} Vertex;


typedef struct {
    int numVertices;
    Vertex vertices[MAX];
} Graph;

Node createNode(char label, int weight) {
    Node initNode = (Node) malloc(sizeof(struct node));

    initNode->label = label;
    initNode->weight = weight;
    initNode->link = NULL;

    return initNode;
}

Graph createGraph() {
    Graph initGraph;

    initGraph.numVertices = 0;
    for (int i = 0; i < MAX; i++)
    {
        initGraph.vertices[i].label = '\0';
        initGraph.vertices[i].adjlst = NULL;
    }
    

    return initGraph;
}

// 

#endif