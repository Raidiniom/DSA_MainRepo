#include <stdio.h>
#include <stdlib.h>

#include "tree_headers/treef.h"

// Main function to demonstrate the tree operations
int main() {
    // Node* root = NULL;
    // root = insert_data(root, 5);
    // root = insert_data(root, 3);
    // root = insert_data(root, 7);
    // root = insert_data(root, 2);
    // root = insert_data(root, 4);
    // root = insert_data(root, 6);
    // root = insert_data(root, 8);
    // root = insert_data(root, 14);
    // root = insert_data(root, 1);
    // root = insert_data(root, 10);

    // printf("Inorder traversal of the tree:\n");
    // inorder(root);
    // printf("\n\n");

    // printf("Postorder traversal of the tree:\n");
    // postorder(root);
    // printf("\n\n");

    // printf("Preorder traversal of the tree:\n");
    // preorder(root);
    // printf("\n\n");

    // printf("Searching for 4:\n");
    // Node* foundNode = search(root, 4);
    // if (foundNode != NULL) {
    //     printf("Found: %d\n", foundNode->data);
    // } else {
    //     printf("Not Found\n");
    // }

    Heap my_heap;

    initHeap(&my_heap);

    insert_min(&my_heap, 6);
    insert_min(&my_heap, 8);
    insert_min(&my_heap, 4);
    insert_min(&my_heap, 7);
    insert_min(&my_heap, 2);
    insert_min(&my_heap, 3);
    insert_min(&my_heap, 9);
    insert_min(&my_heap, 1);
    insert_min(&my_heap, 5);

    displayHeap(&my_heap);

    return 0;
}
