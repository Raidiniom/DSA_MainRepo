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

int parentIndex(int childIndex) {
    return (childIndex - 1) / 2;
}

int leftChildIndex(int parentIndex) {
    return (2 * parentIndex) + 1;
}

int rightChildIndex(int parentIndex) {
    return (2 * parentIndex) + 2;
}

// List Operations
void initList(List* li) {
    li->count = 0;
}

void insertList(List* li, int data) {
    if (li->count < MAX) li->arr[li->count++] = data;
}

void displayList(List li, char* label) {
    printf("%-16s | ", label);
    for (int i = 0; i < li.count; i++)
    {
        printf("%d", li.arr[i]);

        if (i + 1 < li.count) printf(", ");
    }
    printf("\n");
}

// PR Operations
void Initialize(Heap* hp) {
    hp->count = 0;
}

void Makenull(Heap* hp) {
    hp->count = 0;
}

void insert(Heap* hp, int elem) {
    if (hp->count < MAX)
    {
        int i = hp->count;
        hp->arr[i] = elem;
        hp->count++;

        for (; i > 0 && hp->arr[parentIndex(i)] > hp->arr[i]; i = parentIndex(i))
        {
            swap(&hp->arr[i], &hp->arr[parentIndex(i)]);
        }
        
    }
    
}

int Deletemin(Heap* hp) {
    return -1;
}

void displayHeap(Heap hp, char* label) {
    printf("%-16s | ", label);
    for (int i = 0; i < hp.count; i++)
    {
        printf("%d", hp.arr[i]);

        if (i + 1 < hp.count) printf(", ");
    }
    printf("\n");
}

#endif