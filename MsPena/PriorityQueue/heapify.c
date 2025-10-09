#include <stdio.h>

#define MAX  10
typedef struct {
  int elem[MAX];
  int lastNdx;   //index of last element
} minHeap;

void heapifySubtree(minHeap *h, int root) {
    int smallest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    // Check left child
    if (left <= h->lastNdx && h->elem[left] < h->elem[smallest]) {
        smallest = left;
    }

    // Check right child
    if (right <= h->lastNdx && h->elem[right] < h->elem[smallest]) {
        smallest = right;
    }

    // If the smallest is not the root, swap and recurse
    if (smallest != root) {
        int temp = h->elem[root];
        h->elem[root] = h->elem[smallest];
        h->elem[smallest] = temp;

        // Recursively heapify the affected subtree
        heapifySubtree(h, smallest);
    }
}

void main() {
    minHeap h = {{5, 9, 3, 10, 12, 7}, 5};  // lastNdx = 5

    printf("Before heapify:\n");
    for (int i = 0; i <= h.lastNdx; i++) printf("%d ", h.elem[i]);
    printf("\n");

    heapifySubtree(&h, 0); // heapify subtree rooted at index 0

    printf("After heapify:\n");
    for (int i = 0; i <= h.lastNdx; i++) printf("%d ", h.elem[i]);
    printf("\n");
}