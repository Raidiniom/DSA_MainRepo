#ifndef TREEF_H
#define TREEF_H

#include <stdio.h>
#include <stdlib.h>

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

#endif