#ifndef TREEF_H
#define TREEF_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100

typedef struct {
    int size;
    int arr[MAX_SIZE];
} Heap;

// Define the structure of a node in the binary search tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the tree
Node* insert_data(Node* root, int data) {

    // initial insert to the tree
    if (root == NULL) {
        return createNode(data);
    }

    // continue insertion to the tree
    if (data < root->data) {
        root->left = insert_data(root->left, data);
    } else if (data > root->data) {
        root->right = insert_data(root->right, data);
    }
    return root;
}

// Function to find the minimum value node in the tree
Node* findMin_data(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a value from the tree
Node* delete_data(Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = delete_data(root->left, data);
    } else if (data > root->data) {
        root->right = delete_data(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: get the inorder successor (smallest in the right subtree)
        Node* temp = findMin_data(root->right);
        root->data = temp->data;
        root->right = delete_data(root->right, temp->data);
    }
    return root;
}

// Function to search for a value in the tree
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }   
    return search(root->right, data);
}

// Inorder traversal of the tree
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal of the tree
void preorder(Node* root) {
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
    
}

// Postorder traversal of the tree
void postorder(Node* root) {
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
    
}

// Function to get the parent index
int parent(int i) {
    return (i - 1) / 2;
}

// Function to get the left child index
int leftChild(int i) {
    return 2 * i + 1;
}

// Function to get the right child index
int rightChild(int i) {
    return 2 * i + 2;
}

// Function to initialize the heap
void initHeap(Heap *heap) {
    heap->size = 0;
}

// Function to insert a value into the min heap
void insert_min(Heap *heap, int value) {
    if (heap->size == MAX_SIZE) {
        printf("Heap overflow\n");
        return;
    }

    // Insert the new value at the end
    heap->arr[heap->size] = value;
    int i = heap->size;
    heap->size++;

    // Heapify up
    while (i != 0 && heap->arr[parent(i)] > heap->arr[i]) {
        int temp = heap->arr[i];
        heap->arr[i] = heap->arr[parent(i)];
        heap->arr[parent(i)] = temp;
        i = parent(i);
    }
}

// Function to extract the minimum value (root)
int extractMin(Heap *heap) {
    if (heap->size <= 0) {
        printf("Heap underflow\n");
        return INT_MAX;
    }
    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    // Store the root value
    int root = heap->arr[0];
    // Replace the root with the last element
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    // Heapify down
    int i = 0;
    while (1) {
        int left = leftChild(i);
        int right = rightChild(i);
        int smallest = i;

        if (left < heap->size && heap->arr[left] < heap->arr[smallest]) {
            smallest = left;
        }
        if (right < heap->size && heap->arr[right] < heap->arr[smallest]) {
            smallest = right;
        }
        if (smallest == i) {
            break;
        }

        int temp = heap->arr[i];
        heap->arr[i] = heap->arr[smallest];
        heap->arr[smallest] = temp;

        i = smallest;
    }

    return root;
}

// Max Heap
void insert_max(Heap *heap, int value) {
    if (heap->size == MAX_SIZE) {
        printf("Heap overflow\n");
        return;
    }

    heap->arr[heap->size] = value;
    int i = heap->size;
    heap->size++;

    // Heapify up
    while (i != 0 && heap->arr[parent(i)] < heap->arr[i]) {
        int temp = heap->arr[i];
        heap->arr[i] = heap->arr[parent(i)];
        heap->arr[parent(i)] = temp;
        i = parent(i);
    }
}

int extractMax(Heap *heap) {
    if (heap->size <= 0) {
        printf("Heap underflow\n");
        return INT_MIN;
    }
    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    int i = 0;
    while (1) {
        int left = leftChild(i);
        int right = rightChild(i);
        int largest = i;

        if (left < heap->size && heap->arr[left] > heap->arr[largest]) {
            largest = left;
        }
        if (right < heap->size && heap->arr[right] > heap->arr[largest]) {
            largest = right;
        }
        if (largest == i) {
            break;
        }

        int temp = heap->arr[i];
        heap->arr[i] = heap->arr[largest];
        heap->arr[largest] = temp;

        i = largest;
    }

    return root;
}

// Function to display the heap
void displayHeap(Heap *heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

#endif