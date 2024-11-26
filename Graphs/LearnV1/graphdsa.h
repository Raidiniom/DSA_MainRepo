#ifndef GRAPHDSA_H
#define GRAPHDSA_H

// ADJACENCY LIST


#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char val;
    struct node *next;
} Node, *NodePtr;

typedef struct {
    int num_vertices;
    NodePtr *adj_Node;
} Graph;

NodePtr create_node(char val) {
    NodePtr new_node =(NodePtr) malloc(sizeof(Node));

    new_node->val = val;
    new_node->next = NULL;

    return new_node;
}

Graph *create_graph(int num_vertices) {
    Graph *new_graph = malloc(sizeof(Graph));

    new_graph->num_vertices = num_vertices;

    new_graph->adj_Node = malloc(num_vertices * sizeof(Node));

    return new_graph;
}



#endif