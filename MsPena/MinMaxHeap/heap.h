#ifndef HEAP_H
#define HEAP_H

/**
 * @file    
 * @brief  
 *
 * Detailed description:
 *
 * Functions to be implemented:
 *  - function   : Description
 *
 * @author   Voltaire Ratilla
 * @date     Created: 13/10/2025
 * @date     Completed: DD/MM/YR
*/

#include <stdio.h>

#define MAXSIZE 10

typedef struct {
    int elem[MAXSIZE];
    int count;
} minHeap, maxHeap;

void initminHeap(minHeap* mh) {
    mh->count = -1;
}

// Version #1
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxSubheapify(maxHeap* mh, int root) {
    //  
}

void maxHeapifyTree(maxHeap* mh) {
    // 
}

void heapSort(maxHeap* mh) {
    // 
}

// Version #2
void insertminHeap(minHeap* mh, int element) {
    // 
}

void insertAllminHeap(minHeap* mh) {
    // 
}

int deleteMin(minHeap* mh) {
    // 

    return -1;
}

void heapSort(minHeap* mh) {
    // 
}

#endif