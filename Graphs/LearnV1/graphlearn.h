#ifndef GRAPHLEARN_H
#define GRAPHLEARN_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef int Graph[MAX][MAX];

void initialize_graph(Graph *graph) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            (*graph)[i][j] = 0;
        }
    }
}

void display_graph(Graph graph) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

#endif