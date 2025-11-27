#ifndef TREE_H
#define TREE_H

/**
 * @file     tree.h
 * @brief    Binary Search Tree (BST) implementation in C
 *
 * Detailed description:
 * This header file implements a Binary Search Tree (BST) using dynamic
 * memory allocation. It provides the fundamental operations for
 * initializing a tree, inserting elements, deleting nodes, clearing
 * the entire tree, and performing the three standard tree traversals
 * (in-order, pre-order, and post-order).
 *
 * Functions implemented:
 *  - initTree      : Initializes the tree to NULL
 *  - insertElem    : Inserts an integer into the BST
 *  - deleteElem    : Removes an integer from the BST using successor replacement
 *  - makeNull      : Recursively clears the entire BST and frees memory
 *  - inOrder       : Displays elements in L–Root–R order
 *  - preOrder      : Displays elements in Root–L–R order
 *  - postOrder     : Displays elements in L–R–Root order
 *
 * This implementation uses pointers-to-pointers extensively to allow direct
 * modification of tree links during insertion and deletion.
 *
 * @author   Voltaire Ratilla
 * @date     Created:   18/11/2025
 * @date     Completed: 19/11/2025
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
    Node* insert = tree;

    while (*insert != NULL && data != (*insert)->data)
    {
        insert = (data < (*insert)->data) ? &(*insert)->left : &(*insert)->right;
    }
    
    if (*insert == NULL)
    {
        *insert = (Node) malloc(sizeof(NodeSize));

        (*insert)->data = data;
        (*insert)->left = NULL;
        (*insert)->right = NULL;
    }

}

void deleteElem(Node* tree, int data) {
    Node* deleteNode = tree;

    while (*deleteNode != NULL && (*deleteNode)->data != data)
    {
        deleteNode = (data < (*deleteNode)->data) ? &(*deleteNode)->left : &(*deleteNode)->right;
    }

    if (*deleteNode == NULL)
    {
        printf("Elem not found!\n");
        return;
    }
    

    Node temp = *deleteNode;
    
    if (temp->left == NULL)
    {
        *deleteNode = temp->right;
        free(temp);
    }
    else if (temp->right == NULL)
    {
        *deleteNode = temp->left;
        free(temp);
    }
    else
    {
        // Successor
        Node* successor = &temp->right;

        while ((*successor)->left != NULL)
        {
            successor = &(*successor)->left;
        }
        
        temp->data = (*successor)->data;

        Node hold = *successor;
        *successor = (*successor)->right;
        free(hold);

        // Predessor
        // Node* predessor = &temp->left;

        // while ((*predessor)->right != NULL)
        // {
        //     predessor = &(*predessor)->right;
        // }
        
        // temp->data = (*predessor)->data;

        // Node hold = *predessor;
        // *predessor = (*predessor)->left;
        // free(hold);
    }
    

}

void makeNull(Node* tree) {
    while (*tree != NULL)
    {
        deleteElem(tree, (*tree)->data);
    }
    
}

void inOrder(Node tree) {
    if (tree)
    {
        inOrder(tree->left);
        printf("%d ", tree->data);
        inOrder(tree->right);
    }
    
}

void preOrder(Node tree) {
    if (tree)
    {
        printf("%d ", tree->data);
        preOrder(tree->left);
        preOrder(tree->right);
    }
    
}

void postOrder(Node tree) {
    if (tree)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        printf("%d ", tree->data);
    }
    
}

#endif