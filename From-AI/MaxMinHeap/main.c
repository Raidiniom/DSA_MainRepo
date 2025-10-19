#include "mmheap.h"

void main() {
    int data1[] = {30, 10, 50, 20, 60, 40};
    int n = 6;

    printf("Original array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", data1[i]);
    printf("\n\n");

    // ---------------- Version 1: Heapify (Ascending) ----------------
    maxHeap H1;
    for (int i = 0; i < n; i++)
        H1.elem[i] = data1[i];
    H1.count = n;

    heapSort_maxHeap(&H1);

    printf("Sorted (Ascending) using maxHeap Heapify:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", H1.elem[i]);
    printf("\n\n");

    // ---------------- Version 2: InsertAll (Descending) ----------------
    int data2[] = {30, 10, 50, 20, 60, 40};
    heapSort_minHeap(data2, n);

    printf("Sorted (Descending) using minHeap InsertAll:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", data2[i]);
    printf("\n");
}