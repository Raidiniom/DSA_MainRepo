#ifndef TREE_H
#define TREE_H

/**
 * @file     tree.h
 * @brief    Recursive Binary Search Tree (BST) implementation in C
 *
 * Detailed description:
 * This header file provides a Binary Search Tree (BST) implementation
 * where most major operations use recursion. The BST supports inserting
 * elements, deleting nodes using the in-order successor, clearing the
 * entire tree, and performing the three classical recursive traversals.
 *
 * Functions implemented:
 *  - initTree      : Initializes the tree to NULL
 *  - insertElem    : Inserts an integer into the BST (recursive descent through pointers)
 *  - deleteElem    : Deletes a node using recursive search and successor replacement
 *  - makeNull      : Recursively removes all nodes and frees the entire BST
 *  - inOrder       : Recursive Left–Root–Right traversal
 *  - preOrder      : Recursive Root–Left–Right traversal
 *  - postOrder     : Recursive Left–Right–Root traversal
 *
 * Recursive behavior:
 *  - Tree traversal functions rely entirely on recursion.
 *  - insertElem and deleteElem make recursive progress by updating
 *    pointers-to-pointers until a correct position or match is found.
 *  - makeNull repeatedly calls deleteElem until all nodes are removed.
 *
 * This implementation uses pointer manipulation to maintain proper BST
 * structure while maximizing recursion for clarity and correctness.
 *
 * @author   Voltaire Ratilla
 * @date     Created:   19/11/2025
 * @date     Completed: DD/MM/YR
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} *Node, NodeSize;

void initTree(Node* tree) {
    *tree = NULL;
}

void insertElem(Node* tree, int data) {
    if (*tree == NULL)
    {
        *tree = (Node) malloc(sizeof(NodeSize));

        (*tree)->data = data;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    }
    else if (data < (*tree)->data)
    {
        insertElem(&(*tree)->left, data);
    }
    else if (data > (*tree)->data)
    {
        insertElem(&(*tree)->right, data);
    }
    
    
}

void deleteElem(Node* tree, int data) {
    // 
}

void makeNull(Node* tree) {
    // 
}

void inOrder(Node tree) {
    if (tree != NULL)
    {
        inOrder(tree->left);
        printf("%d ", tree->data);
        inOrder(tree->right);
    }
    
}

void preOrder(Node tree) {
    if (tree != NULL)
    {
        printf("%d ", tree->data);
        preOrder(tree->left);
        preOrder(tree->right);
    }
    
}

void postOrder(Node tree) {
    if (tree != NULL)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        printf("%d ", tree->data);
    }
    
}

#endif