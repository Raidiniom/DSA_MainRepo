#ifndef GRAPHD_H
#define GRAPHD_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    char label;
    struct node* next;
} *Node;

typedef struct {
    char label;
    Node* edge;
} Graph;


#endif