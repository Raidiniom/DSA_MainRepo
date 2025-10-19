#ifndef MMHEAP_H
#define MMHEAP_H

/**
 * @file    
 * @brief   
 *
 * Detailed description:
 *
 * Functions to be implemented:
 *  - initHeap   : Initializes the Heap.
 *
 * @author   Voltaire Ratilla
 * @date     Created: 19/10/2025
 * @date     Completed: ~~/~~/2025
*/

#include <stdio.h>

#define SIZE 50

typedef struct {
    int elem[SIZE];
    int count;
} maxHeap, minHeap;

// ----------------------------
// Common Utility Function
// ----------------------------
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// =====================================================
// VERSION 1: HeapSort using Heapify()  (maxHeap)
// =====================================================

// Ensures subtree rooted at index follows max-heap property
void maxSubheapify(maxHeap *H, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < H->count && H->elem[left] > H->elem[largest])
        largest = left;
    if (right < H->count && H->elem[right] > H->elem[largest])
        largest = right;

    if (largest != index) {
        swap(&H->elem[index], &H->elem[largest]);
        maxSubheapify(H, largest);
    }
}

// Build entire heap from array
void maxHeapifyTree(maxHeap *H) {
    for (int i = H->count / 2 - 1; i >= 0; i--) {
        maxSubheapify(H, i);
    }
}

// HeapSort ascending using maxHeap
void heapSort_maxHeap(maxHeap *H) {
    maxHeapifyTree(H); // Step 1: Build heap

    int originalCount = H->count;
    for (int i = H->count - 1; i > 0; i--) {
        swap(&H->elem[0], &H->elem[i]); // Move largest to end
        H->count--;                     // Reduce heap size
        maxSubheapify(H, 0);            // Re-heapify
    }
    H->count = originalCount; // Restore count
}

// =====================================================
// VERSION 2: HeapSort using InsertAll() (minHeap)
// =====================================================

// Insert x into minHeap (maintain heap order)
void insertMinHeap(minHeap *H, int x) {
    int i = H->count;
    H->elem[i] = x;
    H->count++;

    while (i != 0 && H->elem[(i - 1) / 2] > H->elem[i]) {
        swap(&H->elem[i], &H->elem[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Insert all elements from array into heap
void insertAllMinHeap(minHeap *H, int arr[], int n) {
    for (int i = 0; i < n; i++) {
        insertMinHeap(H, arr[i]);
    }
}

// Delete minimum (root) and fix heap
int deleteMin(minHeap *H) {
    if (H->count == 0)
        return -1;

    int root = H->elem[0];
    H->elem[0] = H->elem[H->count - 1];
    H->count--;

    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < H->count && H->elem[left] < H->elem[smallest])
            smallest = left;
        if (right < H->count && H->elem[right] < H->elem[smallest])
            smallest = right;

        if (smallest == i)
            break;

        swap(&H->elem[i], &H->elem[smallest]);
        i = smallest;
    }

    return root;
}

// HeapSort descending using minHeap
void heapSort_minHeap(int arr[], int n) {
    minHeap H;
    H.count = 0;

    insertAllMinHeap(&H, arr, n);

    for (int i = n - 1; i >= 0; i--) {
        arr[i] = deleteMin(&H);
    }
}

#endif