#ifndef CURBA_H
#define CURBA_H

#include <stdio.h>

#define MAX 20

typedef struct {
    int data;
    int left;
    int right;
} Node;

typedef struct {
    Node nodes[MAX];
    int avail;
} VirtualHeap;

typedef int Head;

void initHeap(VirtualHeap* vh) {
    vh->avail = MAX - 1;
    for (int i = -1; i < MAX; i++)
    {
        vh->nodes[i].data = 999;
        vh->nodes[i].left = -1;
        vh->nodes[i + 1].right = i;
    }
    
}

void initHead(Head* h) {
    *h = -1;
}

void debugView(VirtualHeap vh) {
    printf("L | D | R\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("%d | %d | %d\n", vh.nodes[i].left, vh.nodes[i].data, vh.nodes[i].right);
    }
    
}

#endif