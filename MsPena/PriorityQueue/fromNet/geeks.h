#ifndef GEEKS_H
#define GEEKS_H

#define MAXSIZE 50

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int items[MAXSIZE];
    int size;
} PriorityQueue;

// Operations
void initPQ(PriorityQueue* pq) {
    pq->size = 0;
}

void swap(int* a, int* b) {
    int hold = *a;
    *a = *b;
    *b = hold;
}

void heapifyUp(PriorityQueue* pq, int index) {
    if (index && pq->items[(index - 1) / 2] > pq->items[index])
    {
        swap(&pq->items[(index - 1) / 2], &pq->items[index]);

        heapifyUp(pq, (index - 1) / 2);
    }
    
}

void heapifyDown(PriorityQueue* pq, int index) {
    int small = index, left = (2 * index) + 1, right = (2 * index) + 2;

    if (left < pq->size && pq->items[left] < pq->items[small])
    {
        small = left;
    }

    if (right < pq->size && pq->items[right] < pq->items[small])
    {
        small = right;
    }
    
    if (small != index)
    {
        swap(&pq->items[index], &pq->items[small]);

        heapifyDown(pq, small);
    }
    
}

int peek(PriorityQueue pq) {
    if (!pq.size)
    {
        return -1;
    }
    
    return pq.items[0];
}

void enqueue(PriorityQueue* pq, int item) {
    // 
}

void dequeue(PriorityQueue* pq, int item) {
    // 
}

#endif