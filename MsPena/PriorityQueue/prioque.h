#ifndef PRIOQUE_H
#define PRIOQUE_H

// Code description

#include <stdio.h>

// Data Structure
#define MAX 20

typedef struct {
    int elem[MAX];
    int lastNdx;
} Heap, List;

// Debug Display
void debugDisplay(Heap hp, char* label) {
    printf("[DEBUG] %-20s\nlastNdx: %d\n", label, hp.lastNdx);
    for (int i = 0; i <= hp.lastNdx; i++)
    {
        printf("%d", hp.elem[i]);

        if (i < hp.lastNdx)
        {
            printf(", ");
        }
        
    }
    printf("\n");
}

// Operations
void initHeap(Heap* hp) {
    hp->lastNdx = -1;
}

void insert(Heap* hp, int elem) {
    if (hp->lastNdx != MAX)
    {
        hp->elem[++hp->lastNdx] = elem;
    }
    else
    {
        printf("Queue is Full\n");
    }
    
}

int deleteMin(Heap* hp) {
    if (hp->lastNdx < 0) {
        printf("Heap is empty.\n");
        return -1;
    }

    int small = hp->elem[0];
    hp->elem[0] = hp->elem[hp->lastNdx--]; // Move last element to root

    int parent = 0;
    while (1) {
        int left = 2 * parent + 1;
        int right = 2 * parent + 2;
        int smallest = parent;

        // Find smaller child
        if (left <= hp->lastNdx && hp->elem[left] < hp->elem[smallest])
            smallest = left;
        if (right <= hp->lastNdx && hp->elem[right] < hp->elem[smallest])
            smallest = right;

        if (smallest == parent)
            break;

        // Swap
        int temp = hp->elem[parent];
        hp->elem[parent] = hp->elem[smallest];
        hp->elem[smallest] = temp;

        parent = smallest;
    }

    return small;
}


void heapSort(Heap* hp) {
    Heap temp;
    initHeap(&temp);

    // Step 1: Build heap from current list
    for (int i = 0; i <= hp->lastNdx; i++) {
        insert(&temp, hp->elem[i]);
    }

    // Step 2: Extract elements in ascending order
    for (int i = 0; i <= hp->lastNdx; i++) {
        hp->elem[i] = deleteMin(&temp);
    }

    // Step 3: Reverse for descending order
    for (int i = 0, j = hp->lastNdx; i < j; i++, j--) {
        int tmp = hp->elem[i];
        hp->elem[i] = hp->elem[j];
        hp->elem[j] = tmp;
    }
}

#endif