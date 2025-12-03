#ifndef PRQU_H
#define PRQU_H

#include <stdio.h>
#include <limits.h>

#define MAX 20

typedef struct {
    int count;
    int arr[MAX];
} Heap, List;

// Helper funcs
void swap(int* a, int* b) {
    int hold = *a;
    *a = *b;
    *b = hold;
}

// List Operations
void initList(List* li) {
    li->count = 0;
}

void insertList(List* li, int data) {
    li->arr[li->count++] = data;
}
// PR Operations
void Initialize(Heap* hp) {
    hp->count = 0;
}

void Makenull(Heap* hp) {
    hp->count = 0;
}

void insert(Heap* hp, int elem) {
    // 
}

int Deletemin(Heap* hp) {
    return -1;
}

#endif