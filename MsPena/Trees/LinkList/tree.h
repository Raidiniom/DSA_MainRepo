#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} *Node;

void initTree(Node* node) {
    *node = NULL;
}

bool duplicateData(Node node, int data) {
    if (node == NULL) return false;
    
    return (data == node->data) || (duplicateData(node->left, data)) || (duplicateData(node->right, data));
}

void insertNode(Node* node, int data) {
    if (*node == NULL)
    {
        Node newNode = (Node) malloc(sizeof(struct node));

        if (newNode != NULL)
        {
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;

            *node = newNode;
        }
        
    }
    else
    {
        if (data < (*node)->data)
        {
            insertNode(&(*node)->left, data);
        }
        else
        {
            insertNode(&(*node)->right, data);
        }
        
    }
    
}

void postOrder(Node node) {
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        
        printf("%d ", node->data);
    }
    
}

void preOrder(Node node) {
    if (node != NULL)
    {
        printf("%d ", node->data);

        preOrder(node->left);
        preOrder(node->right);
    }
    
}

void inOrder(Node node) {
    if (node != NULL)
    {
        inOrder(node->left);
        printf("%d ", node->data);
        inOrder(node->right);
    }
    
}

#endif